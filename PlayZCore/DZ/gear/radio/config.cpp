class CfgPatches
{
	class DZ_Radio_PlayZCore
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Radio"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Transmitter_Base;
	class PersonalRadio: Transmitter_Base
	{
		range = 50000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
				};
			};
		};
	};
	class BaseRadio: Transmitter_Base
	{
		range = 50000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=600;
				};
			};
		};
	};
};
