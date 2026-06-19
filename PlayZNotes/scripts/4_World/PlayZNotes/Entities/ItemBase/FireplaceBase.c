modded class FireplaceBase
{
	typename ATTACHMENT_PLAYZNOTE = PlayZNote;

	void FireplaceBase()
	{
		if (m_FireConsumableTypes)
		{
			m_FireConsumableTypes.Insert(ATTACHMENT_PLAYZNOTE, new FireConsumableType(ATTACHMENT_PLAYZNOTE, 10, true, "PlayZNote"));
		}
	}
}
