class PlayZUIPaths
{
	static const string PLAYZ_UI_ROOT = "PlayZ_Client/PlayZUI/gui/";

	static const string LAYOUT_LOADING = PLAYZ_UI_ROOT + "layouts/playz_loading.layout";
	static const string LAYOUT_MAIN_MENU = PLAYZ_UI_ROOT + "layouts/playz_main_menu.layout";
	static const string LAYOUT_QUEUE = PLAYZ_UI_ROOT + "layouts/playz_dialog_queue_position.layout";
	static const string LAYOUT_LOGIN_TIME = PLAYZ_UI_ROOT + "layouts/playz_dialog_login_time.layout";
	static const string LAYOUT_INGAME = PLAYZ_UI_ROOT + "layouts/playz_ingamemenu.layout";
	static const string LAYOUT_DEATH_SCREEN = PLAYZ_UI_ROOT + "layouts/playz_death_screen.layout";

	static const string TEX_BACKGROUND = PLAYZ_UI_ROOT + "textures/Background_01.edds";
	static const string TEX_DEATHSCREEN = PLAYZ_UI_ROOT + "textures/Deathscreen_01.edds";
	static const string TEX_LOGO = PLAYZ_UI_ROOT + "textures/PlayZ.edds";

	static const float DEATH_BLACK_HOLD_SEC = 2;
	static const float DEATH_REVEAL_PICTURE_SEC = 10;
	static const float DEATH_REVEAL_BUTTONS_SEC = 2;
	static const float DEATH_REVEAL_BUTTONS_DELAY_SEC = 1;

	static const string SERVER_IP = "127.0.0.1";
	static const int SERVER_GAME_PORT = 2502;
	static const int SERVER_STEAM_QUERY_PORT = 27018;

	static const string URL_WEBSITE = "https://playzthegoat.com/";
	static const string URL_DISCORD = "https://discord.gg/SgNhCNtb5N";
};
