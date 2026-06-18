class PlayZCarHillAssist
{
	protected static ref map<string, string> s_SurfaceProfileCache;
	protected static ref map<string, float> s_SurfaceFloatCache;

	static void Apply(CarScript car, float assistStrength, float timeSlice)
	{
		if (!car || assistStrength <= 0.0)
		{
			return;
		}

		vector driveForward = GetDriveForward(car);
		vector forward = GetFlatForward(car);
		if (driveForward.LengthSq() < 0.0001 || forward.LengthSq() < 0.0001)
		{
			return;
		}

		vector velocity = car.GetVelocity(car);
		float forwardSpeed = vector.Dot(velocity, forward);
		float rpmRange = car.EngineGetRPMRedline() - car.EngineGetRPMIdle();
		float rpmFactor = 0.0;
		if (rpmRange > 0.0)
		{
			rpmFactor = Math.Clamp((car.EngineGetRPM() - car.EngineGetRPMIdle()) / rpmRange, 0.0, 1.0);
		}

		float frictionDelta = 0.0;
		float dragDelta = 0.0;
		if (!GetWheelSurfaceAssistDeltas(car, frictionDelta, dragDelta))
		{
			return;
		}

		int gear = car.GetGear();
		bool forwardGear = gear != CarGear.NEUTRAL && gear != CarGear.REVERSE;
		if (!forwardGear || !IsDriverAccelerating(car))
		{
			car.PlayZ_SetHillStartAssistUntil(0);
			car.PlayZ_SetHillStuckSince(0);
			return;
		}

		float absForwardSpeed = Math.AbsFloat(forwardSpeed);
		if (absForwardSpeed > PlayZCarsConstants.HILL_ASSIST_MAX_SPEED_MPS)
		{
			car.PlayZ_SetHillStartAssistUntil(0);
			car.PlayZ_SetHillStuckSince(0);
			return;
		}

		string surfaceProfile = GetVehicleSurfaceProfile(car);
		bool offroadClimbSurface = surfaceProfile != "Asphalt" && surfaceProfile != "DirtRoad";

		int currentGear = car.GetCurrentGear();
		int currentTime = GetGame().GetTime();
		float uphillFactor = Math.Clamp(driveForward[1], 0.0, 0.5);
		float inclineFactor = 1.0 + Math.Clamp(uphillFactor * 5.5, 0.0, 2.2);
		float crawlFactor = 1.0;
		float launchFactor = 1.0;
		float hillStartAcceleration = 0.0;
		float hillStartThreshold = 0.08;
		float hillStartArmRpmThreshold = 0.015;
		float compensationAcceleration = 0.0;
		vector hillClimbDirection = forward;
		bool hillStartZone = uphillFactor > hillStartThreshold && forwardSpeed > -3.0 && forwardSpeed < 6.0;
		bool canArmHillStart = hillStartZone && !car.IsHandbrakeActive() && Math.AbsFloat(forwardSpeed) < 2.0;
		bool hillStartStuck = hillStartZone && !car.IsHandbrakeActive() && Math.AbsFloat(forwardSpeed) < 0.08;
		bool hillStartRestartHold = hillStartZone && !car.IsHandbrakeActive() && Math.AbsFloat(forwardSpeed) < 0.35;
		bool hillHoldZone = hillStartZone && !car.IsHandbrakeActive() && Math.AbsFloat(forwardSpeed) < 0.75;
		bool forceFirstGearZone = !car.IsHandbrakeActive() && uphillFactor > 0.14 && forwardSpeed > -0.25 && forwardSpeed < 2.4;
		bool offroadClimbTractionMode = false;
		int hillStartAssistUntil = car.PlayZ_GetHillStartAssistUntil();
		int hillStuckSince = car.PlayZ_GetHillStuckSince();

		if (driveForward[1] > 0.03 && absForwardSpeed < PlayZCarsConstants.HILL_ASSIST_MAX_SPEED_MPS)
		{
			crawlFactor = crawlFactor + (Math.Clamp(PlayZCarsConstants.HILL_ASSIST_MAX_SPEED_MPS - absForwardSpeed, 0.0, PlayZCarsConstants.HILL_ASSIST_MAX_SPEED_MPS) / PlayZCarsConstants.HILL_ASSIST_MAX_SPEED_MPS) * 1.35;
		}

		if (canArmHillStart && rpmFactor > hillStartArmRpmThreshold)
		{
			if (hillStartAssistUntil < currentTime + 1800)
			{
				hillStartAssistUntil = currentTime + 1800;
			}
		}

		if (hillStartRestartHold)
		{
			if (hillStartAssistUntil < currentTime + 1800)
			{
				hillStartAssistUntil = currentTime + 1800;
			}
		}

		if (hillStartStuck)
		{
			if (hillStuckSince == 0)
			{
				hillStuckSince = currentTime;
			}
			else if (currentTime - hillStuckSince > 450)
			{
				if (hillStartAssistUntil < currentTime + 1600)
				{
					hillStartAssistUntil = currentTime + 1600;
				}
			}
		}
		else
		{
			hillStuckSince = 0;
		}

		car.PlayZ_SetHillStartAssistUntil(hillStartAssistUntil);
		car.PlayZ_SetHillStuckSince(hillStuckSince);

		if (hillHoldZone && forwardSpeed < 0.0)
		{
			vector hillHoldVelocity = velocity - (forward * forwardSpeed);
			car.SetVelocity(car, hillHoldVelocity);
			velocity = hillHoldVelocity;
			forwardSpeed = 0.0;
		}

		if (forceFirstGearZone && (gear > CarGear.FIRST || currentGear > CarGear.FIRST))
		{
			car.ShiftTo(CarGear.FIRST);
			gear = CarGear.FIRST;
			currentGear = CarGear.FIRST;
		}

		bool rollbackRecovery = forwardSpeed < -0.05;
		bool hillStartLatched = hillStartZone && currentTime <= hillStartAssistUntil;
		offroadClimbTractionMode = hillStartLatched && offroadClimbSurface && uphillFactor > 0.18 && !car.IsHandbrakeActive();
		if (hillStartLatched)
		{
			float hillDirectionDriveWeight = Math.Clamp(0.82 - (uphillFactor * 0.7), 0.48, 0.82);
			float hillDirectionFlatWeight = 1.0 - hillDirectionDriveWeight;
			hillClimbDirection = (driveForward * hillDirectionDriveWeight) + (forward * hillDirectionFlatWeight);
			if (hillClimbDirection.LengthSq() > 0.0001)
			{
				hillClimbDirection.Normalize();
			}
			else
			{
				hillClimbDirection = driveForward;
			}

			if (rollbackRecovery)
			{
				float rollbackLimitedSpeed = 0.0;
				vector rollbackLimitedVelocity = velocity - (forward * forwardSpeed) + (forward * rollbackLimitedSpeed);
				car.SetVelocity(car, rollbackLimitedVelocity);
				velocity = rollbackLimitedVelocity;
				forwardSpeed = rollbackLimitedSpeed;
			}

			float effectiveRpmFactor = Math.Max(rpmFactor, 0.06);
			float lowSpeedFactor = Math.Clamp((7.5 - Math.Max(forwardSpeed, 0.0)) / 7.5, 0.0, 1.0);
			float wheelspinFactor = Math.Clamp(effectiveRpmFactor - (Math.Max(forwardSpeed, 0.0) / 7.0), 0.0, 1.0);
			float launchZoneFactor = Math.Clamp((4.0 - Math.Max(forwardSpeed, 0.0)) / 4.0, 0.0, 1.0);
			float loadedLaunchFactor = Math.Clamp((effectiveRpmFactor - hillStartArmRpmThreshold) / 0.12, 0.0, 1.0);
			float redlineProtectFactor = 1.0;
			float rollbackFactor = 0.0;
			float startFactor;
			if (rpmFactor > 0.68)
			{
				redlineProtectFactor = Math.Clamp(1.0 - ((rpmFactor - 0.68) / 0.32) * 0.92, 0.08, 1.0);
			}
			if (offroadClimbTractionMode && Math.Max(forwardSpeed, 0.0) < 2.4)
			{
				redlineProtectFactor = Math.Max(redlineProtectFactor, 0.68);
			}
			if (uphillFactor > 0.45 && Math.Max(forwardSpeed, 0.0) < 1.0)
			{
				redlineProtectFactor = Math.Max(redlineProtectFactor, 0.38);
			}
			if (rollbackRecovery)
			{
				rollbackFactor = 1.0;
			}
			startFactor = 1.0 + launchZoneFactor * 2.4 + loadedLaunchFactor * 1.4 + rollbackFactor * 2.2;
			launchFactor = launchFactor + (uphillFactor * 13.0 * lowSpeedFactor) + (wheelspinFactor * 0.25) + (rollbackFactor * 3.2);
			hillStartAcceleration = assistStrength * (5.8 + uphillFactor * 26.0 + frictionDelta * 32.0 + dragDelta * 38.0) * lowSpeedFactor * startFactor * redlineProtectFactor;
		}

		compensationAcceleration = (0.35 + dragDelta * 10.0 + frictionDelta * 6.0) * assistStrength;
		compensationAcceleration = compensationAcceleration * (0.35 + rpmFactor * 0.65) * inclineFactor * crawlFactor * launchFactor;
		if (rpmFactor > 0.68)
		{
			compensationAcceleration = compensationAcceleration * Math.Clamp(1.0 - ((rpmFactor - 0.68) / 0.32) * 0.88, 0.1, 1.0);
		}

		if (hillStartLatched && uphillFactor > hillStartThreshold && rpmFactor > 0.82 && Math.Max(forwardSpeed, 0.0) < 2.0)
		{
			float stuckRedlineBaseSpeed = 0.08;
			float stuckRedlineMinFactor = 0.08;
			if (uphillFactor > 0.45)
			{
				stuckRedlineBaseSpeed = 0.34;
				stuckRedlineMinFactor = 0.52;
			}
			if (offroadClimbTractionMode)
			{
				stuckRedlineBaseSpeed = 0.62;
				stuckRedlineMinFactor = 0.82;
			}
			float stuckRedlineFactor = Math.Clamp((Math.Max(forwardSpeed, 0.0) + stuckRedlineBaseSpeed) / 0.75, stuckRedlineMinFactor, 1.0);
			compensationAcceleration = compensationAcceleration * stuckRedlineFactor;
			hillStartAcceleration = hillStartAcceleration * stuckRedlineFactor;
		}

		if (forwardSpeed < 0.0)
		{
			compensationAcceleration = compensationAcceleration * 0.95;
		}

		vector assistedClimbDirection = hillClimbDirection;
		if (offroadClimbTractionMode)
		{
			assistedClimbDirection = forward;
		}
		else if (hillStartLatched && uphillFactor > 0.45 && Math.Max(forwardSpeed, 0.0) < 1.2)
		{
			assistedClimbDirection = forward;
		}

		if (compensationAcceleration > 0.0)
		{
			vector compensationDirection = driveForward;
			if (hillStartLatched)
			{
				compensationDirection = assistedClimbDirection;
			}

			dBodyApplyForce(car, compensationDirection * (dBodyGetMass(car) * compensationAcceleration));
		}

		if (hillStartAcceleration > 0.0)
		{
			dBodyApplyForce(car, assistedClimbDirection * (dBodyGetMass(car) * hillStartAcceleration));
		}

		if (hillStartLatched && rollbackRecovery)
		{
			float rollbackRecoveryAcceleration = assistStrength * (3.4 + uphillFactor * 13.0 + frictionDelta * 16.0 + dragDelta * 18.0);
			dBodyApplyForce(car, assistedClimbDirection * (dBodyGetMass(car) * rollbackRecoveryAcceleration));
		}

		if (hillStartLatched && uphillFactor > hillStartThreshold && Math.AbsFloat(forwardSpeed) < 3.5)
		{
			float tractionDownforce = dBodyGetMass(car) * assistStrength * (1.6 + uphillFactor * 5.5) * Math.Clamp((3.5 - Math.AbsFloat(forwardSpeed)) / 3.5, 0.0, 1.0);
			if (offroadClimbTractionMode && Math.Max(forwardSpeed, 0.0) < 2.0)
			{
				tractionDownforce = tractionDownforce * 2.9;
			}
			if (uphillFactor > 0.45 && rpmFactor > 0.85 && Math.Max(forwardSpeed, 0.0) < 1.8)
			{
				tractionDownforce = tractionDownforce * 2.25;
			}
			tractionDownforce = tractionDownforce * GetWheelContactFactor(car);
			dBodyApplyForce(car, Vector(0.0, -tractionDownforce, 0.0));
		}

		if (hillStartLatched && uphillFactor > 0.45 && rpmFactor > 0.95 && Math.Max(forwardSpeed, 0.0) < 2.4)
		{
			car.AddHealth("Engine", "Health", 1.2);
			car.SetEngineZoneReceivedHit(false);
		}
	}

	protected static vector GetFlatForward(CarScript car)
	{
		vector forward = car.GetDirection();
		forward[1] = 0.0;

		if (forward.LengthSq() > 0.0001)
		{
			forward.Normalize();
		}

		return forward;
	}

	protected static vector GetDriveForward(CarScript car)
	{
		vector forward = car.GetDirection();

		if (forward.LengthSq() > 0.0001)
		{
			forward.Normalize();
		}

		return forward;
	}

	protected static string GetVehicleSurfaceProfile(CarScript car)
	{
		string surfaceType = car.GetSurfaceType();
		return GetSurfaceProfileFromSurfaceType(surfaceType);
	}

	protected static float GetVehicleSurfaceFloat(string surfaceProfile, string parameterName, float defaultValue)
	{
		if (surfaceProfile == "")
		{
			return defaultValue;
		}

		if (!s_SurfaceFloatCache)
		{
			s_SurfaceFloatCache = new map<string, float>;
		}

		string cacheKey = surfaceProfile + "." + parameterName;
		if (s_SurfaceFloatCache.Contains(cacheKey))
		{
			return s_SurfaceFloatCache.Get(cacheKey);
		}

		float value = defaultValue;
		string configPath = "CfgVehicleSurfaces " + surfaceProfile + " " + parameterName;
		if (GetGame() && GetGame().ConfigIsExisting(configPath))
		{
			value = GetGame().ConfigGetFloat(configPath);
		}

		s_SurfaceFloatCache.Set(cacheKey, value);
		return value;
	}

	protected static string GetSurfaceProfileFromSurfaceType(string surfaceType)
	{
		if (surfaceType == "")
		{
			return "Asphalt";
		}

		if (!s_SurfaceProfileCache)
		{
			s_SurfaceProfileCache = new map<string, string>;
		}

		if (s_SurfaceProfileCache.Contains(surfaceType))
		{
			return s_SurfaceProfileCache.Get(surfaceType);
		}

		string surfaceProfile = Surface.GetParamText(surfaceType, "vpSurface");
		if (surfaceProfile == "")
		{
			surfaceProfile = "Asphalt";
		}

		s_SurfaceProfileCache.Set(surfaceType, surfaceProfile);
		return surfaceProfile;
	}

	protected static bool GetWheelSurfaceAssistDeltas(CarScript car, out float frictionDelta, out float dragDelta)
	{
		float asphaltFriction = GetVehicleSurfaceFloat("Asphalt", "friction", 0.95);
		float asphaltDrag = GetVehicleSurfaceFloat("Asphalt", "drag", 0.0);
		float frictionSum = 0.0;
		float dragSum = 0.0;
		int contactCount = 0;
		int wheelCount = car.WheelCount();

		frictionDelta = 0.0;
		dragDelta = 0.0;

		if (wheelCount <= 0)
		{
			return false;
		}

		for (int i = 0; i < wheelCount; i++)
		{
			if (!car.WheelHasContact(i))
			{
				continue;
			}

			CarWheelWaterState waterState = car.WheelGetWaterState(i);
			if (waterState == CarWheelWaterState.IN_WATER || waterState == CarWheelWaterState.UNDER_WATER)
			{
				return false;
			}

			SurfaceInfo wheelSurface = car.WheelGetSurface(i);
			string wheelSurfaceType = "";
			if (wheelSurface)
			{
				wheelSurfaceType = wheelSurface.GetSurfaceType();
				if (wheelSurfaceType == "")
				{
					wheelSurfaceType = wheelSurface.GetName();
				}
				if (wheelSurfaceType == "")
				{
					wheelSurfaceType = wheelSurface.GetEntryName();
				}
			}

			string wheelSurfaceProfile = GetSurfaceProfileFromSurfaceType(wheelSurfaceType);
			float wheelSurfaceFriction = GetVehicleSurfaceFloat(wheelSurfaceProfile, "friction", asphaltFriction);
			float wheelSurfaceDrag = GetVehicleSurfaceFloat(wheelSurfaceProfile, "drag", asphaltDrag);

			frictionSum = frictionSum + Math.Max(0.0, asphaltFriction - wheelSurfaceFriction);
			dragSum = dragSum + Math.Max(0.0, wheelSurfaceDrag - asphaltDrag);
			contactCount++;
		}

		if (contactCount <= 0)
		{
			return false;
		}

		frictionDelta = frictionSum / contactCount;
		dragDelta = dragSum / contactCount;
		return frictionDelta > 0.001 || dragDelta > 0.001;
	}

	protected static bool IsDriverAccelerating(CarScript car)
	{
		Human driver = car.CrewDriver();
		if (!driver)
		{
			return false;
		}

		PlayerBase player;
		if (!Class.CastTo(player, driver))
		{
			return false;
		}

		UAInterface input = player.GetInputInterface();
		if (!input)
		{
			return false;
		}

		return input.SyncedValue("UACarForward", false) > PlayZCarsConstants.HILL_ASSIST_DRIVER_INPUT_MIN;
	}

	protected static float GetWheelContactFactor(CarScript car)
	{
		int wheelCount = car.WheelCount();
		if (wheelCount <= 0)
		{
			return 0.0;
		}

		int contactCount = 0;
		for (int i = 0; i < wheelCount; i++)
		{
			if (car.WheelHasContact(i))
			{
				contactCount++;
			}
		}

		return contactCount / (wheelCount * 1.0);
	}
}
