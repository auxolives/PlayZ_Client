// PlayZ market stock curve: power 2 (responsive mid-range) instead of Expansion default 6.
// Source Found: DayZExpansion/Market/Scripts/3_Game/DayZExpansion_Market/Settings/ExpansionMarketItem.c:445-467

modded class ExpansionMarketItem
{
	static const float PLAYZ_MARKET_STOCK_PRICE_POWER = 1.5;

	override int CalculatePrice(int stock, float modifier = 1.0, bool round = false)
	{
		#ifdef EXPANSIONMODMARKET_DEBUG
		EXPrint("ExpansionMarketItem::CalculatePrice - Start - " + ClassName + " - stock " + stock + " modifier " + modifier + " minstock " + MinStockThreshold + " maxstock " + MaxStockThreshold + " maxprice " + MaxPriceThreshold + " minprice " + MinPriceThreshold + " pct " + SellPricePercent);
		#endif

		float price;

		if (!IsStaticStock() && MaxStockThreshold != 0)
			price = ExpansionMath.PowerConversion(MinStockThreshold, MaxStockThreshold, stock, MaxPriceThreshold, MinPriceThreshold, PLAYZ_MARKET_STOCK_PRICE_POWER);
		else
			price = MinPriceThreshold;

		price *= modifier;

		if (round)
			price = Math.Round(price);

		#ifdef EXPANSIONMODMARKET_DEBUG
		EXPrint("ExpansionMarketItem::CalculatePrice - End and return calculated price: " + price);
		#endif

		return (int) price;
	}
}
