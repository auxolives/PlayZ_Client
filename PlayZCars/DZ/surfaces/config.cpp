class CfgPatches
{
	class DZ_Surfaces_PlayZCars
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Surfaces"
		};
	};
};

class CfgVehicleSurfaces
{
	class Asphalt
	{
		friction = 1.0;
	};
	class Dirt
	{
		friction = 0.90;
		drag = 0.0525;
	};
	class Gravel
	{
		friction = 0.765;
		drag = 0.075;
	};
	class Grass
	{
		friction = 0.848;
		drag = 0.24;
	};
	class Forest
	{
		friction = 0.828;
		drag = 0.2625;
	};
	class Snow
	{
		friction = 0.622;
		drag = 0.3375;
	};
	class Ice
	{
		friction = 0.205;
		drag = 0.2625;
	};
};
