modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(ActionPlayZWritePaper);
		actions.Insert(ActionPlayZReadNoteHands);
		actions.Insert(ActionPlayZReadNoteTarget);
	}
}
