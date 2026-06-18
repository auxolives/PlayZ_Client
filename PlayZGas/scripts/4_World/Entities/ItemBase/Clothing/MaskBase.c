modded class MaskBase
{
	static const float PLAYZ_FILTER_CONSUMPTION_SCALE = 0.5;

	override bool ConsumeQuantity(float quantity, PlayerBase consumer_player)
	{
		return super.ConsumeQuantity(quantity * PLAYZ_FILTER_CONSUMPTION_SCALE, consumer_player);
	}
}
