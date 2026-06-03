modded class PluginRecipesManagerBase
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();

		RegisterRecipe(new PlayZ_CraftLeatherJacket);
		RegisterRecipe(new PlayZ_CraftLeatherPants);
		RegisterRecipe(new PlayZ_CraftLeatherShoes);
		RegisterRecipe(new PlayZ_CraftLeatherGloves);
		RegisterRecipe(new PlayZ_CraftLeatherHat);
		RegisterRecipe(new PlayZ_CraftLeatherHat_Bone);
	}
};
