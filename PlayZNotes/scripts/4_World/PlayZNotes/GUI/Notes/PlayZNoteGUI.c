class PlayZNoteGUI extends UIScriptedMenu
{
	static const string LAYOUT_FILE = "PlayZ_Client/PlayZNotes/data/gui/layouts/NoteGUI.layout";

	MultilineEditBoxWidget m_TextBox;
	MultilineTextWidget m_TextReadBox;
	TextWidget m_DateText;
	ButtonWidget m_ExitBtn;
	ImageWidget m_DamageLayer;

	ItemBase m_Paper;
	bool m_ReadOnly;
	int m_PenColour;
	static string DATE_TEXT = "";

	override void OnShow()
	{
		super.OnShow();
		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		GetGame().GetMission().GetHud().Show(false);
		GetUApi().GetInputByName("UAPersonView").Lock();
		PPEffects.SetBlurMenu(0.5);
	}

	override void OnHide()
	{
		super.OnHide();
		GetGame().GetMission().PlayerControlEnable(true);
		GetGame().GetMission().GetHud().Show(true);
		GetUApi().GetInputByName("UAPersonView").Unlock();
		PPEffects.SetBlurMenu(0);
	}

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets(LAYOUT_FILE);

		m_TextBox = MultilineEditBoxWidget.Cast(layoutRoot.FindAnyWidget("NoteText0"));
		m_TextReadBox = MultilineTextWidget.Cast(layoutRoot.FindAnyWidget("NoteReadText0"));
		m_DateText = TextWidget.Cast(layoutRoot.FindAnyWidget("DateText0"));
		m_ExitBtn = ButtonWidget.Cast(layoutRoot.FindAnyWidget("CloseBtn"));
		m_DamageLayer = ImageWidget.Cast(layoutRoot.FindAnyWidget("DamageLayer"));

		if (!m_ExitBtn || !m_TextBox || !m_TextReadBox)
		{
			return NULL;
		}

		if (m_DateText)
		{
			m_DateText.SetText(DATE_TEXT);
		}

		return layoutRoot;
	}

	override bool UseKeyboard()
	{
		return true;
	}

	void SetPaper(ItemBase item)
	{
		m_Paper = item;
		if (!m_Paper || !m_DamageLayer)
		{
			return;
		}

		int dmgState = m_Paper.GetHealthLevel("");
		if (dmgState == GameConstants.STATE_PRISTINE)
		{
			return;
		}

		m_DamageLayer.Show(true);
		if (dmgState == GameConstants.STATE_WORN)
		{
			m_DamageLayer.SetAlpha(0.3);
		}
		else if (dmgState == GameConstants.STATE_DAMAGED)
		{
			m_DamageLayer.SetAlpha(0.6);
		}
		else if (dmgState <= GameConstants.STATE_BADLY_DAMAGED)
		{
			m_DamageLayer.SetAlpha(0.9);
		}
	}

	void SetNoteData(PlayZNoteData data)
	{
		if (!data || !m_TextReadBox || !m_DateText)
		{
			OnExitBtnClick();
			return;
		}

		m_TextBox.Show(false);
		m_TextBox.Enable(false);
		m_TextReadBox.Show(true);
		m_TextReadBox.SetText(data.m_NoteText);
		m_DateText.Show(true);
		m_DateText.SetText(data.m_DateText);
		SetPenColour(data.m_ARGBColour);
	}

	void SetDate()
	{
		if (m_DateText)
		{
			m_DateText.SetText(DATE_TEXT);
		}
	}

	void SetPenColour(int colour)
	{
		if (m_TextBox)
		{
			m_TextBox.SetColor(colour);
		}
		if (m_TextReadBox)
		{
			m_TextReadBox.SetColor(colour);
		}
		if (m_DateText)
		{
			m_DateText.SetColor(colour);
		}
		if (m_ExitBtn)
		{
			m_ExitBtn.SetTextColor(colour);
		}
		m_PenColour = colour;
	}

	void SetReadOnly(bool readOnly)
	{
		m_ReadOnly = readOnly;
		if (readOnly)
		{
			m_TextBox.Show(false);
			m_TextBox.Enable(false);
		}
		else
		{
			m_TextReadBox.Show(false);
			m_TextReadBox.Enable(false);
			m_TextBox.Show(true);
			m_TextBox.Enable(true);
		}
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		if (w == m_ExitBtn)
		{
			return OnExitBtnClick();
		}
		return true;
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);
		if (GetUApi())
		{
			GetUApi().GetInputByName("UAPersonView").Supress();
		}
	}

	bool OnExitBtnClick()
	{
		string msgTxt;
		if (m_TextBox)
		{
			m_TextBox.GetText(msgTxt);
		}

		if (m_Paper && !m_ReadOnly && msgTxt != "" && GetGame().GetPlayer())
		{
			PlayZNoteData noteData = new PlayZNoteData();
			noteData.m_FontIndex = 0;
			noteData.m_NoteText = msgTxt;
			noteData.m_DateText = DATE_TEXT;
			noteData.m_ARGBColour = m_PenColour;

			Param1<ref PlayZNoteData> params = new Param1<ref PlayZNoteData>(noteData);
			m_Paper.RPCSingleParam(PlayZNotesRPCs.SEND_WRITTEN_NOTE, params, true, NULL);
		}

		UIManager uiManager = GetGame().GetUIManager();
		if (!uiManager)
		{
			return true;
		}

		UIScriptedMenu menu = uiManager.GetMenu();
		if (menu)
		{
			PlayZNoteGUI noteMenu = PlayZNoteGUI.Cast(menu);
			if (noteMenu)
			{
				uiManager.HideScriptedMenu(noteMenu);
			}
		}

		return true;
	}
}
