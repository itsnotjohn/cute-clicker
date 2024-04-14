namespace modules
{
	namespace clicker
	{
		void leftclick_thread( )
		{
			HWND window;

			while ( true )
			{
				window = GetForegroundWindow( );
				GetWindowTextA( window, var::settings::windowname, 128 );

				if ( GetKeyState( var::left_click::keybindleftclick ) & 0x8000 && !var::left_click::pressedlbutton )
				{
					var::left_click::pressedlbutton = true;
				}
				else if ( !( GetKeyState( var::left_click::keybindleftclick ) & 0x8000 ) && var::left_click::pressedlbutton )
				{
					var::left_click::left_click_tab = !var::left_click::left_click_tab;
					var::left_click::pressedlbutton = false;
				}

				if ( var::left_click::LBUTTONDOWN && var::left_click::left_click_tab )
				{
					if ( strstr( var::settings::windowname, var::settings::minecraft_title ) )
					{
						utils::cute::input::left::left_down( );
						std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
						utils::cute::input::left::left_up( );

						if ( var::jitter::jitter_tab )
						{
							GetCursorPos( &var::cursorPos );
							var::jitter::x = var::cursorPos.x;
							var::jitter::y = var::cursorPos.y;

							if ( var::jitter::testa == 0 )
							{
								SetCursorPos( var::jitter::x + rand( ) % var::jitter::densityx, var::jitter::y + rand( ) % var::jitter::densityx );
								var::jitter::testa = 1;
							}
							else
							{
								SetCursorPos( var::jitter::x - rand( ) % var::jitter::densityy, var::jitter::y - rand( ) % var::jitter::densityy );
								var::jitter::testa = 0;
							}
						}

						var::left_click::counter++;
					}
				}

				if ( true )
				{
					Sleep( ( rand( ) % 30 + 400 ) / var::left_click::lmincps - rand( ) % utils::cute::randint( var::left_click::lmincps, var::left_click::lmaxcps ) );
				}
				std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
			}
		}

		void rightclick_thread( )
		{
			HWND window;

			while ( true )
			{
				window = GetForegroundWindow( );
				GetWindowTextA( window, var::settings::windowname, 128 );

				if ( GetKeyState( var::right_click::keybindrightclick ) & 0x8000 && !var::right_click::pressedrbutton )
				{
					var::right_click::pressedrbutton = true;
				}
				else if ( !( GetKeyState( var::right_click::keybindrightclick ) & 0x8000 ) && var::right_click::pressedrbutton )
				{
					var::right_click::right_click_tab = !var::right_click::right_click_tab;
					var::right_click::pressedrbutton = false;
				}

				if ( var::right_click::RBUTTONDOWN && var::right_click::right_click_tab )
				{
					if ( strstr( var::settings::windowname, var::settings::minecraft_title ) )
					{
						utils::cute::input::right::right_down( );
						std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
						utils::cute::input::right::right_up( );
					}
				}

				if ( true )
				{
					Sleep( ( rand( ) % 25 + 600 ) / var::right_click::rmincps - rand( ) % utils::cute::randint( var::right_click::rmincps, var::right_click::rmaxcps ) );
				}
				std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
			}
		}

		void throwpot_thread( BYTE pot, int time, BYTE sword )
		{
			Sleep( var::throwp::delaypot ); //Delay to switch for Pot
			keybd_event( pot, 0, 0, 0 ); //Potion Key
			keybd_event( pot, 0, KEYEVENTF_KEYUP, 0 ); //Potion Key
			Sleep( 30 ); //Delay to Splash Pot
			mouse_event( MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0 ); //Spash Pot
			mouse_event( MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0 ); //Spash Pot 
			Sleep( 30 ); //Delay to switch for Sword
			keybd_event( sword, 0, 0, 0 ); //Sword
			keybd_event( sword, 0, KEYEVENTF_KEYUP, 0 ); //Sword
		}

		void throwpearl_thread( BYTE pot, int time, BYTE sword )
		{
			Sleep( var::throwp::delaypot ); //Delay to switch for Pot
			keybd_event( pot, 0, 0, 0 ); //Potion Key
			keybd_event( pot, 0, KEYEVENTF_KEYUP, 0 ); //Potion Key
			Sleep( 30 ); //Delay to Splash Pot
			mouse_event( MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0 ); //Spash Pot
			mouse_event( MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0 ); //Spash Pot 
			Sleep( 30 ); //Delay to switch for Sword
			keybd_event( sword, 0, 0, 0 ); //Sword
			keybd_event( sword, 0, KEYEVENTF_KEYUP, 0 ); //Sword
		}
	}
}