class PlayZUIDialog extends ScriptedWidgetEventHandler
{
	protected static ref PlayZUIDialog s_Instance;

	protected Widget m_Root;
	protected TextWidget m_Caption;
	protected RichTextWidget m_Text;
	protected ButtonWidget m_bYes;
	protected ButtonWidget m_bNo;
	protected ButtonWidget m_bOK;
	protected ButtonWidget m_bCancel;
	protected UIScriptedMenu m_Handler;
	protected int m_Code;
	protected int m_ButtonType;

	static bool IsVisible()
	{
		if (!s_Instance)
		{
			return false;
		}

		return s_Instance.m_Root != null;
	}

	static void Show(string caption, string text, int id, int butts, int def, int type, UIScriptedMenu handler)
	{
		CloseActive();

		s_Instance = new PlayZUIDialog();
		s_Instance.Open(caption, text, id, butts, def, type, handler);
	}

	static void Cancel()
	{
		if (!s_Instance)
		{
			return;
		}

		if (s_Instance.m_ButtonType == DBT_YESNOCANCEL)
		{
			s_Instance.DeliverResult(DBB_CANCEL);
		}
		else if (s_Instance.m_ButtonType == DBT_YESNO)
		{
			s_Instance.DeliverResult(DBB_NO);
		}
		else
		{
			s_Instance.DeliverResult(DBB_OK);
		}
	}

	static void CloseActive()
	{
		if (s_Instance)
		{
			s_Instance.Destroy();
		}
	}

	void Open(string caption, string text, int id, int butts, int def, int type, UIScriptedMenu handler)
	{
		m_Handler = handler;
		m_Code = id;
		m_ButtonType = butts;

		m_Root = g_Game.GetWorkspace().CreateWidgets(PlayZUIPaths.LAYOUT_DIALOG);
		if (!m_Root)
		{
			return;
		}

		m_Root.SetHandler(this);
		m_Root.SetSort(1023, true);

		m_Caption = TextWidget.Cast(m_Root.FindAnyWidget("Caption"));
		m_Text = RichTextWidget.Cast(m_Root.FindAnyWidget("Text"));
		m_bYes = ButtonWidget.Cast(m_Root.FindAnyWidget("bYes"));
		m_bNo = ButtonWidget.Cast(m_Root.FindAnyWidget("bNo"));
		m_bOK = ButtonWidget.Cast(m_Root.FindAnyWidget("bOK"));
		m_bCancel = ButtonWidget.Cast(m_Root.FindAnyWidget("bCancel"));

		if (m_Caption)
		{
			m_Caption.SetText(caption);
		}

		if (m_Text)
		{
			m_Text.SetText(text);
		}

		ConfigureButtons(butts, def);

		g_Game.GetUIManager().ShowUICursor(true);
		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Insert(DialogUpdate);
	}

	void ConfigureButtons(int butts, int def)
	{
		bool showYes = false;
		bool showNo = false;
		bool showOk = false;
		bool showCancel = false;

		if (butts == DBT_OK)
		{
			showOk = true;
		}
		else if (butts == DBT_YESNO)
		{
			showYes = true;
			showNo = true;
		}
		else if (butts == DBT_YESNOCANCEL)
		{
			showYes = true;
			showNo = true;
			showCancel = true;
		}

		if (m_bYes)
		{
			m_bYes.Show(showYes);
		}

		if (m_bNo)
		{
			m_bNo.Show(showNo);
		}

		if (m_bOK)
		{
			m_bOK.Show(showOk);
		}

		if (m_bCancel)
		{
			m_bCancel.Show(showCancel);
		}

		Widget focusWidget = null;
		if (def == DBB_YES && showYes && m_bYes)
		{
			focusWidget = m_bYes;
		}
		else if (def == DBB_NO && showNo && m_bNo)
		{
			focusWidget = m_bNo;
		}
		else if (def == DBB_OK && showOk && m_bOK)
		{
			focusWidget = m_bOK;
		}
		else if (def == DBB_CANCEL && showCancel && m_bCancel)
		{
			focusWidget = m_bCancel;
		}

		if (focusWidget)
		{
			SetFocus(focusWidget);
		}
	}

	void DialogUpdate(float tDelta)
	{
		if (!m_Root)
		{
			return;
		}

		g_Game.GetUIManager().ShowUICursor(true);
	}

	void DeliverResult(int result)
	{
		UIScriptedMenu handler = m_Handler;
		int code = m_Code;
		Destroy();

		if (handler)
		{
			handler.OnModalResult(null, 0, 0, code, result);
		}
	}

	void Destroy()
	{
		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Remove(DialogUpdate);

		if (m_Root)
		{
			m_Root.Unlink();
			m_Root = null;
		}

		g_Game.GetUIManager().ShowUICursor(false);

		if (s_Instance == this)
		{
			s_Instance = null;
		}
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button != MouseState.LEFT)
		{
			return false;
		}

		if (w == m_bYes)
		{
			DeliverResult(DBB_YES);
			return true;
		}

		if (w == m_bNo)
		{
			DeliverResult(DBB_NO);
			return true;
		}

		if (w == m_bOK)
		{
			DeliverResult(DBB_OK);
			return true;
		}

		if (w == m_bCancel)
		{
			DeliverResult(DBB_CANCEL);
			return true;
		}

		return false;
	}
}
