class CfgPatches
{
	class DZ_Weapons_Lights_PlayZCore
	{
		units[] = {"UniversalLight_IR","TLRLight_IR"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Lights"};
	};
};

class CfgVehicles
{
	class UniversalLight;
	class TLRLight;

	class UniversalLight_IR: UniversalLight
	{
		scope = 2;
		displayName = "$STR_PlayZ_UniversalLight_IR0";
		descriptionShort = "$STR_PlayZ_UniversalLight_IR1";
	};

	class TLRLight_IR: TLRLight
	{
		scope = 2;
		displayName = "$STR_PlayZ_TLRLight_IR0";
		descriptionShort = "$STR_PlayZ_TLRLight_IR1";
	};
};
