modded class PsilocybeMushroom
{
    override void OnConsume(float amount, PlayerBase consumer)
    {
        super.OnConsume(amount, consumer);

        if (consumer && consumer.GetTerjeStats())
        {
            consumer.GetTerjeStats().AddMindDegradation(0.5, 200.0);
        }
    }
}