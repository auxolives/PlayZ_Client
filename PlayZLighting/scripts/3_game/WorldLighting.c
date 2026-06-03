modded class WorldLighting
{
	protected string lighting_PlayZ_default = "PlayZ_Client\\PlayZLighting\\DZ\\data\\lighting\\lighting_PlayZ_default.txt";
	protected string lighting_PlayZ_darknight = "PlayZ_Client\\PlayZLighting\\DZ\\data\\lighting\\lighting_PlayZ_darknight.txt";
	protected string lighting_DayZ063 = "PlayZ_Client\\PlayZLighting\\DZ\\data\\lighting\\lighting_PlayZ_DayZ063.txt";
	
	override void SetGlobalLighting( int lightingID )
	{
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

			default:
				super.SetGlobalLighting( lightingID );
				break;
		}
	}
}
