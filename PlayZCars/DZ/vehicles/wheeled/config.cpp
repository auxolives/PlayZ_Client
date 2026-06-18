class CfgPatches
{
	class DZ_Vehicles_Wheeled_PlayZCars
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Vehicles_Wheeled"
		};
	};
};

class CfgVehicles
{
	class CarScript;
	class CarWheel;
	class SimulationModule;
	class Axles;
	class Front;
	class Rear;
	class Middle;
	class Suspension;

	class HatchbackWheel: CarWheel
	{
		tyreGrip = 0.94;
	};

	class CivSedanWheel: CarWheel
	{
		tyreGrip = 0.94;
	};

	class Hatchback_02_Wheel: CarWheel
	{
		tyreGrip = 0.94;
	};

	class Sedan_02_Wheel: CarWheel
	{
		tyreGrip = 0.94;
	};

	class Truck_01_Wheel: CarWheel
	{
		tyreGrip = 0.94;
		tyreOffroadResistance = 1.0;
	};

	class Truck_01_WheelDouble: Truck_01_Wheel
	{
		tyreGrip = 0.94;
		tyreOffroadResistance = 1.0;
	};

	class Offroad_02_Wheel: CarWheel
	{
		tyreGrip = 0.95;
	};

	class OffroadHatchback: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Engine
			{
				torqueCurve[] = {
					650,  0,
					750,  50,
					1400, 100,
					3400, 143,
					5400, 119,
					8000, 0
				};
			};

			class Clutch
			{
				maxTorqueTransfer = 300;
			};

			class Axles: Axles
			{
				class Front: Front
				{
					class Suspension: Suspension
					{
						stiffness = 51000;
						compression = 2310;
						damping = 6050;
						travelMaxUp = 0.091;
						travelMaxDown = 0.069;
					};
				};

				class Rear: Rear
				{
					class Suspension: Suspension
					{
						stiffness = 28900;
						compression = 2200;
						damping = 5610;
						travelMaxUp = 0.099;
						travelMaxDown = 0.153;
					};
				};
			};
		};
	};

	class CivilianSedan: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Engine
			{
				torqueCurve[] = {
					400,  0,
					1000, 196,
					1700, 229,
					2500, 234,
					4500, 184,
					6000, 0
				};
			};

			class Clutch
			{
				maxTorqueTransfer = 500;
			};

			class Axles: Axles
			{
				class Front: Front
				{
					class Suspension: Suspension
					{
						stiffness = 51000;
						compression = 2310;
						damping = 6050;
						travelMaxUp = 0.091;
						travelMaxDown = 0.069;
					};
				};

				class Rear: Rear
				{
					class Suspension: Suspension
					{
						stiffness = 28900;
						compression = 2200;
						damping = 5610;
						travelMaxUp = 0.099;
						travelMaxDown = 0.153;
					};
				};
			};
		};
	};

	class Hatchback_02: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Engine
			{
				torqueCurve[] = {
					850,  0,
					1150, 113,
					2000, 163,
					4400, 233,
					5800, 206,
					7500, 0
				};
			};

			class Clutch
			{
				maxTorqueTransfer = 450;
			};

			class Axles: Axles
			{
				class Front: Front
				{
					class Suspension: Suspension
					{
						stiffness = 23000;
						compression = 2200;
						damping = 8250;
						travelMaxUp = 0.184;
						travelMaxDown = 0.184;
					};
				};

				class Rear: Rear
				{
					class Suspension: Suspension
					{
						stiffness = 23400;
						compression = 2310;
						damping = 8800;
						travelMaxUp = 0.184;
						travelMaxDown = 0.184;
					};
				};
			};
		};
	};

	class Sedan_02: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Engine
			{
				torqueCurve[] = {
					600,  0,
					990,  63,
					1800, 94,
					3000, 103,
					5000, 89,
					7000, 0
				};
			};

			class Clutch
			{
				maxTorqueTransfer = 206;
			};

			class Axles: Axles
			{
				class Front: Front
				{
					class Suspension: Suspension
					{
						stiffness = 21250;
						compression = 1760;
						damping = 5720;
						travelMaxUp = 0.081;
						travelMaxDown = 0.092;
					};
				};

				class Rear: Rear
				{
					class Suspension: Suspension
					{
						stiffness = 18300;
						compression = 1980;
						damping = 6160;
						travelMaxUp = 0.115;
						travelMaxDown = 0.115;
					};
				};
			};
		};
	};

	class Truck_01_Base: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Engine
			{
				torqueCurve[] = {
					525,  0,
					1000, 413,
					1400, 425,
					1900, 375,
					2500, 125,
					3000, 0
				};
			};

			class Clutch
			{
				maxTorqueTransfer = 900;

			};

			class Axles: Axles
			{
				class Front: Front
				{
					class Suspension: Suspension
					{
						stiffness = 46000;
						compression = 3600;
						damping = 8500;
						travelMaxUp = 0.20;
						travelMaxDown = 0.20;
					};
				};

				class Middle: Rear
				{
					class Suspension: Suspension
					{
						stiffness = 39000;
						compression = 3500;
						damping = 9500;
						travelMaxUp = 0.18;
						travelMaxDown = 0.20;
					};
				};

				class Rear: Rear
				{
					class Suspension: Suspension
					{
						stiffness = 39000;
						compression = 3500;
						damping = 9500;
						travelMaxUp = 0.18;
						travelMaxDown = 0.20;
					};
				};
			};
		};
	};

	class Offroad_02: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Engine
			{
				torqueCurve[] = {
					525,  0,
					800,  260,
					1100, 380,
					1400, 460,
					1800, 500,
					2500, 520,
					3200, 470,
					3600, 420,
					5120, 0
				};
			};

			class Clutch
			{
				maxTorqueTransfer = 1100;
			};

			class Gearbox
			{
				reverse = 2.35;
				ratios[] = {3.25, 2.05, 1.34, 0.98, 0.76};
			};

			class CentralDifferential
			{
				ratio = 2.45;
			};
		};
	};
};

