modded class WorldLighting
{
	protected string lighting_PlayZ_default = "PlayZLighting\\DZ\\data\\lighting\\lighting_PlayZ_default.txt";
	protected string lighting_PlayZ_darknight = "PlayZLighting\\DZ\\data\\lighting\\lighting_PlayZ_darknight.txt";
	protected string lighting_DayZ063 = "PlayZLighting\\DZ\\data\\lighting\\lighting_PlayZ_DayZ063.txt";
	protected string lighting_PlayZ_rework = "PlayZLighting\\DZ\\data\\lighting\\lighting_PlayZ_rework.txt";
	protected string lighting_PlayZ_dark_rework = "PlayZLighting\\DZ\\data\\lighting\\lighting_PlayZ_dark_rework.txt";
	
	override void SetGlobalLighting( int lightingID )
	{
		super.SetGlobalLighting( lightingID );

		switch ( lightingID )
		{
			case 60:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_PlayZ_default ); 
				break;

			case 61:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_PlayZ_darknight ); 
				break;
				
			case 62:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_DayZ063 ); 
				break;

			case 63:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_PlayZ_rework ); 
				break;

			case 64:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_PlayZ_dark_rework ); 
				break;
		}
	}
}
