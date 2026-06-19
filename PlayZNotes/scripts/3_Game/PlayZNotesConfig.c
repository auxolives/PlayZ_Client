class PlayZNoteDateFormat
{
	int Format;
	ref array<string> DaySuffix;
	ref array<string> MonthName;
}

class PlayZNotesConfig
{
	static const string CONFIG_ROOT = "$profile:PlayZ/";
	static const string CONFIG_PATH = "$profile:PlayZ/Notes.json";

	int PenConsumeQuantity = 3;
	int MaxNoteLength = 2000;
	bool DeleteAllNotes = false;
	ref PlayZNoteDateFormat NoteDateFormat;

	[NonSerialized()]
	private static ref PlayZNotesConfig m_Instance;

	static PlayZNotesConfig Get()
	{
		if (!m_Instance)
		{
			m_Instance = new PlayZNotesConfig();
			if (GetGame() && GetGame().IsServer())
			{
				m_Instance.Load();
			}
		}
		return m_Instance;
	}

	void Load()
	{
		EnsureProfileDir();
		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<PlayZNotesConfig>.JsonLoadFile(CONFIG_PATH, this);
		}
		else
		{
			SetDefaults();
			Save();
		}
		if (!NoteDateFormat)
		{
			SetDefaults();
		}
	}

	void Save()
	{
		EnsureProfileDir();
		JsonFileLoader<PlayZNotesConfig>.JsonSaveFile(CONFIG_PATH, this);
	}

	void SetDefaults()
	{
		PenConsumeQuantity = 3;
		MaxNoteLength = 2000;
		DeleteAllNotes = false;

		NoteDateFormat = new PlayZNoteDateFormat();
		NoteDateFormat.Format = 6;
		NoteDateFormat.DaySuffix = new array<string>();
		NoteDateFormat.DaySuffix.Insert("st");
		NoteDateFormat.DaySuffix.Insert("nd");
		NoteDateFormat.DaySuffix.Insert("rd");
		NoteDateFormat.DaySuffix.Insert("th");
		NoteDateFormat.MonthName = new array<string>();
		NoteDateFormat.MonthName.Insert("January");
		NoteDateFormat.MonthName.Insert("February");
		NoteDateFormat.MonthName.Insert("March");
		NoteDateFormat.MonthName.Insert("April");
		NoteDateFormat.MonthName.Insert("May");
		NoteDateFormat.MonthName.Insert("June");
		NoteDateFormat.MonthName.Insert("July");
		NoteDateFormat.MonthName.Insert("August");
		NoteDateFormat.MonthName.Insert("September");
		NoteDateFormat.MonthName.Insert("October");
		NoteDateFormat.MonthName.Insert("November");
		NoteDateFormat.MonthName.Insert("December");
	}

	static void EnsureProfileDir()
	{
		if (!FileExist(CONFIG_ROOT))
		{
			MakeDirectory(CONFIG_ROOT);
		}
	}

	string GetDate()
	{
		if (!NoteDateFormat || NoteDateFormat.Format == 0)
		{
			return "";
		}

		int year, month, day;
		GetYearMonthDay(year, month, day);

		string date;
		string dayNumber;
		string monthNumber;
		string dayStr;
		string monthStr;

		dayNumber = day.ToStringLen(2);
		if (day <= 9)
		{
			dayNumber = day.ToStringLen(1);
		}

		monthNumber = month.ToStringLen(2);
		if (month <= 9)
		{
			monthNumber = month.ToStringLen(1);
		}

		if (NoteDateFormat.Format == 6)
		{
			dayStr = GetNumberDateSuffix(day);
			monthStr = GetMonth(month);
			date = dayNumber + dayStr + " " + monthStr;
		}
		else
		if (NoteDateFormat.Format == 2)
		{
			date = day.ToStringLen(2) + "/" + month.ToStringLen(2) + "/" + year.ToStringLen(4);
		}
		else
		{
			date = dayNumber + "/" + monthNumber + "/" + year.ToStringLen(4);
		}

		return date;
	}

	string GetNumberDateSuffix(int number)
	{
		switch (number)
		{
			case 1:
			case 21:
			case 31:
				return NoteDateFormat.DaySuffix.Get(0);
			case 2:
			case 22:
				return NoteDateFormat.DaySuffix.Get(1);
			case 3:
			case 23:
				return NoteDateFormat.DaySuffix.Get(2);
			default:
				return NoteDateFormat.DaySuffix.Get(3);
		}

		return "";
	}

	string GetMonth(int month)
	{
		return NoteDateFormat.MonthName.Get(month - 1);
	}

	bool ValidateNoteText(string msg, out string err)
	{
		err = "";
		if (!msg)
		{
			err = "empty";
			return false;
		}

		string check = msg;
		check.Trim();
		if (check == "")
		{
			err = "empty";
			return false;
		}

		if (MaxNoteLength > 0 && msg.Length() > MaxNoteLength)
		{
			err = "too_long";
			return false;
		}

		return true;
	}
}
