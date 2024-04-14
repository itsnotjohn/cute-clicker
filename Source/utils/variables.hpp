#define MEMBLOCK 4096
#define COLOR_FLAGS ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_RGB | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_DisplayHex
#define SELF_REMOVE_STRING TEXT( xorstr ( "cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del \"%s\"") )

namespace var
{
	int keybindchoose;

	HHOOK hookdoMouse;

	POINT cursorPos;

	namespace left_click
	{
		bool left_click_tab = false;

		bool pressedlbutton;

		bool LBUTTONDOWN;

		int keybindleftclick = 0;

		int counter = 0;

		float lmincps = 12;
		float lmaxcps = 15;

		float maxclicks = 20;

		static std::string key_bind_lc_text = "toggle key";
	}

	namespace right_click
	{
		static bool right_click_tab = false;

		bool RBUTTONDOWN;

		bool pressedrbutton;

		int keybindrightclick = 0;

		float rmincps = 6;
		float rmaxcps = 9;

		float maxclicks = 20;

		static std::string key_bind_rc_text = "toggle key";
	}

	namespace jitter
	{
		static bool jitter_tab = false;

		float x;
		float y;

		int testa;

		int densityx = 5;
		int densityy = 7;
	}

	namespace throwp
	{
		inline bool slot[9];
		inline float return_pos;
		inline bool throw_item;

		int keybindthrowpot = 0;

		float delaypot = 30;

		static std::string key_bind_throwpot_text = "toggle key";
		static std::string key_bind_throwpearl_text = "toggle key";
	}

	namespace throwpl 
	{
		float delaypearl = 30;

		int perlslot = 2;
	
		int keybindthrowpearl = 0;
	}

	namespace settings
	{
		char windowname[ 256 ] {};
		char namecheat[ 64 ] {};

		bool inventory = true;
		bool humanized = true;
		bool blatant = false;
		bool coming_soon = false;

		static char minecraft_title[ 256 ] = { "Minecraft 1.7.10" };
	}

	namespace misc
	{
		bool selfdelete = false;

		bool pressedhide;

		bool janelinha;

		bool rainbow;

		int keybindhide = 0;

		float color[ 4 ] = { 1, 0.451, 0.451, 1 /*0.545, 0.00f, 1.00f, 1.0f*/ /*0.984, 0.478, 0.831, 1.00f*/ };

		float rainbow_speed = 8.0f;

		float rainbow_saturation = color[4];

		static std::string key_bind_hide_text = "toggle key";
	}

	namespace reach
	{
		HANDLE handle_reach;

		std::vector<DWORD>locationslimit;
		std::vector<DWORD>locationsreachf;
		std::vector<DWORD>locationsreachd;

		bool reach_used = false;

		bool reach_tab = false;

		float distance = 3.0f;

		static std::string key_reach_hide_text = "toggle key";
	}

	namespace velocity
	{
		HANDLE handle_velocity;

		std::vector<DWORD>locationsv1;

		bool velocity_used = false;

		bool velocity_tab = false;

		float velocity = 100.0f;
	}

	namespace timer
	{
		HANDLE handle_timer;

		bool timer_tab = false;

		float timer_speed = 0.0f;

		DWORD speed_pid;

		HANDLE speed_phandle;

		bool speed_used = false;

		double speed_new;

		double speed_default = 1000;

		bool speed_tpmode = false;

		std::vector<double>timer_speeds = { 2000.00000000123, 1900.00000000123, 1800.00000000123, 1700.00000000123, 1600.00000000123, 1500.00000000123, 1400.00000000123, 1300.00000000123, 1200.00000000123, 1100.00000000123, 1000, 950.00000000123,  900.00000000123,  850.00000000123,  800.00000000123,  750.00000000123,  700.00000000123,  650.00000000123,  600.00000000123,  550.00000000123, 500.00000000123 };
	}

	namespace tabs
	{
		int switchtabs = 1;

		bool combat_tab = true;
		bool memory_tab = false;
		bool misc_tab = false;
	}

	namespace self
	{
		std::vector<const char *> exenamevectordps;
		std::vector<const char *> exenamevector;
		std::vector<const char *> exenamevector2;

		bool dps_string_found = false;
	}

	namespace auth
	{
		bool cute_logged = false;
	}

	namespace local_player
	{
		inline bool moving = false;
		inline bool sprinting = false;
		inline bool jumping = false;
		inline bool inventory_open = false;
		inline int current_slot = 1;

		namespace binds
		{
			inline int slot1 = 0x31;
			inline int slot2 = 0x32;
			inline int slot3 = 0x33;
			inline int slot4 = 0x34;
			inline int slot5 = 0x35;
			inline int slot6 = 0x36;
			inline int slot7 = 0x37;
			inline int slot8 = 0x38;
			inline int slot9 = 0x39;

			inline int w = 'w';
			inline int a = 'a';
			inline int s = 's';
			inline int d = 'd';

			inline int jump = VK_SPACE;
			inline int sprint = VK_LCONTROL;
			inline int drop = 'q';
			inline int inventory = 'e';
		}
	}
}