void timer_function( std::vector<double> value, bool status, DWORD min, DWORD max )
{
	var::timer::speed_pid = utils::cute::get_processid( "javaw.exe" ); int cucklord_reach_chance_temp = utils::cute::cute_random_int( 0, 99 );
	if ( var::timer::speed_phandle = OpenProcess( THREAD_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, false, var::timer::speed_pid ) )
	{
		INT64 cucklord_current_address = min; 
		bool breakscan = var::timer::timer_tab; MEMORY_BASIC_INFORMATION cucklord_memory;
		while ( cucklord_current_address < max )
		{
			if ( breakscan != var::timer::timer_tab )
			{
				break;
			}
			std::vector<double> buffer( MEMBLOCK );
			if ( ReadProcessMemory( var::timer::speed_phandle, ( LPVOID ) cucklord_current_address, &buffer[ 0 ], MEMBLOCK, 0 ) )
			{
				for ( size_t i = 0; i < buffer.size( ); ++i )
				{
					for ( const auto f : value )
					{
						if ( buffer[ i ] == f )
						{
							if ( status )
							{
								if ( var::timer::speed_tpmode )
								{
									WriteProcessMemory( var::timer::speed_phandle, ( LPVOID ) ( cucklord_current_address + ( ( i + 1 ) * sizeof( double ) ) - sizeof( double ) ), &var::timer::speed_new, sizeof( double ), 0 );
									std::this_thread::sleep_for( std::chrono::milliseconds( 20 ) );
									WriteProcessMemory( var::timer::speed_phandle, ( LPVOID ) ( cucklord_current_address + ( ( i + 1 ) * sizeof( double ) ) - sizeof( double ) ), &var::timer::speed_default, sizeof( double ), 0 );
								}
								else
								{
									WriteProcessMemory( var::timer::speed_phandle, ( LPVOID ) ( cucklord_current_address + ( ( i + 1 ) * sizeof( double ) ) - sizeof( double ) ), &var::timer::speed_new, sizeof( double ), 0 );
								}
							}
							if ( !status )
							{
								var::timer::speed_used = false;
								WriteProcessMemory( var::timer::speed_phandle, ( LPVOID ) ( cucklord_current_address + ( ( i + 1 ) * sizeof( double ) ) - sizeof( double ) ), &var::timer::speed_default, sizeof( double ), 0 );
							}
							std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
						}
					}
				}
			}
			cucklord_current_address += MEMBLOCK;
		}
		CloseHandle( var::timer::speed_phandle );
		if ( var::timer::speed_tpmode )
		{
			var::timer::timer_tab = false;
		}
	}
	else
	{
		var::timer::speed_used = false;
	}
}

void thread_speed( )
{
	while ( true )
	{
		while ( var::timer::timer_tab )
		{
			var::timer::speed_used = true;
			if ( var::timer::timer_speed >= -1.05 & var::timer::timer_speed < -0.95 )
				var::timer::speed_new = var::timer::timer_speeds[ 0 ];

			if ( var::timer::timer_speed >= -0.95 & var::timer::timer_speed < -0.85 )
				var::timer::speed_new = var::timer::timer_speeds[ 1 ];

			if ( var::timer::timer_speed >= -0.85 & var::timer::timer_speed < -0.75 )
				var::timer::speed_new = var::timer::timer_speeds[ 2 ];

			if ( var::timer::timer_speed >= -0.75 & var::timer::timer_speed < -0.65 )
				var::timer::speed_new = var::timer::timer_speeds[ 3 ];

			if ( var::timer::timer_speed >= -0.65 & var::timer::timer_speed < -0.55 )
				var::timer::speed_new = var::timer::timer_speeds[ 4 ];

			if ( var::timer::timer_speed >= -0.55 & var::timer::timer_speed < -0.45 )
				var::timer::speed_new = var::timer::timer_speeds[ 5 ];

			if ( var::timer::timer_speed >= -0.45 & var::timer::timer_speed < -0.35 )
				var::timer::speed_new = var::timer::timer_speeds[ 6 ];

			if ( var::timer::timer_speed >= -0.35 & var::timer::timer_speed < -0.25 )
				var::timer::speed_new = var::timer::timer_speeds[ 7 ];

			if ( var::timer::timer_speed >= -0.25 & var::timer::timer_speed < -0.15 )
				var::timer::speed_new = var::timer::timer_speeds[ 8 ];

			if ( var::timer::timer_speed >= -0.15 & var::timer::timer_speed < -0.05 )
				var::timer::speed_new = var::timer::timer_speeds[ 9 ];

			if ( var::timer::timer_speed >= -0.05 & var::timer::timer_speed < 0.05 )
				var::timer::speed_new = var::timer::timer_speeds[ 10 ];

			if ( var::timer::timer_speed >= 0.05 & var::timer::timer_speed < 0.15 )
				var::timer::speed_new = var::timer::timer_speeds[ 11 ];

			if ( var::timer::timer_speed >= 0.15 & var::timer::timer_speed < 0.25 )
				var::timer::speed_new = var::timer::timer_speeds[ 12 ];

			if ( var::timer::timer_speed >= 0.25 & var::timer::timer_speed < 0.35 )
				var::timer::speed_new = var::timer::timer_speeds[ 13 ];

			if ( var::timer::timer_speed >= 0.35 & var::timer::timer_speed < 0.45 )
				var::timer::speed_new = var::timer::timer_speeds[ 14 ];

			if ( var::timer::timer_speed >= 0.45 & var::timer::timer_speed < 0.55 )
				var::timer::speed_new = var::timer::timer_speeds[ 15 ];

			if ( var::timer::timer_speed >= 0.55 & var::timer::timer_speed < 0.65 )
				var::timer::speed_new = var::timer::timer_speeds[ 16 ];

			if ( var::timer::timer_speed >= 0.65 & var::timer::timer_speed < 0.75 )
				var::timer::speed_new = var::timer::timer_speeds[ 17 ];

			if ( var::timer::timer_speed >= 0.75 & var::timer::timer_speed < 0.85 )
				var::timer::speed_new = var::timer::timer_speeds[ 18 ];

			if ( var::timer::timer_speed >= 0.85 & var::timer::timer_speed < 0.95 )
				var::timer::speed_new = var::timer::timer_speeds[ 19 ];

			if ( var::timer::timer_speed >= 0.95 & var::timer::timer_speed < 1.05 )
				var::timer::speed_new = var::timer::timer_speeds[ 20 ];

			timer_function( var::timer::timer_speeds, true, 0x02000000, 0x06FFFFFF );
			for ( int i = 0; i < 2500; ++i )
			{
				std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) ); 
				if ( !var::timer::timer_tab )
				{
					break;
				}
			}
		}
		while ( !var::timer::timer_tab )
		{
			if ( var::timer::speed_used )
			{
				timer_function( var::timer::timer_speeds, false, 0x02000000, 0x06FFFFFF );
				var::timer::speed_used = false;
			}
			for ( int i = 0; i < 2500; ++i )
			{
				std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) ); 
				if ( var::timer::timer_tab )
				{
					break;
				}
			}
		}
		std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
	}
}