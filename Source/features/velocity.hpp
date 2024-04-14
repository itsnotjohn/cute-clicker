namespace combat
{
	namespace randomizer
	{
		bool isbetween( double value, double min, double max )
		{
			if ( value < min )
			{
				return false;
			}
			if ( value > max )
			{
				return false;
			}
			return true;
		}
	}

	namespace velocity
	{
		void velocityupdater( )
		{
			double defaultvelocity = 8000;
			double buffer;
			while ( 1 )
			{
				if ( var::velocity::velocity_used )
				{
					double newvelocity = 800000 / var::velocity::velocity;
					if ( HANDLE processhandle = LI_FN( OpenProcess ).cached( )( THREAD_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, false, utils::cute::get_processid( "javaw.exe" ) ) )
					{
						if ( var::velocity::velocity_tab )
						{
							for ( size_t i = 0; i < var::velocity::locationsv1.size( ); ++i )
							{
								if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::velocity::locationsv1[ i ] ), &buffer, sizeof( double ), 0 ) )
								{
									if ( randomizer::isbetween( buffer, -999999999, 999999999 ) && !randomizer::isbetween( buffer, -1, 1 ) )
									{
										LI_FN( WriteProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::velocity::locationsv1[ i ] ), &newvelocity, sizeof( double ), 0 );
									}
									else
									{
										var::velocity::locationsv1.erase( var::velocity::locationsv1.begin( ) + i ); i -= 2;
									}
								}
							}
						}
						else
						{
							for ( size_t i = 0; i < var::velocity::locationsv1.size( ); ++i )
							{
								if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::velocity::locationsv1[ i ] ), &buffer, sizeof( double ), 0 ) )
								{
									if ( randomizer::isbetween( buffer, -999999999, 999999999 ) && !randomizer::isbetween( buffer, -1, 1 ) )
									{
										LI_FN( WriteProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::velocity::locationsv1[ i ] ), &defaultvelocity, sizeof( double ), 0 );
									}
									else
									{
										var::velocity::locationsv1.erase( var::velocity::locationsv1.begin( ) + i ); i -= 2;
									}
								}
							}
							var::velocity::velocity_used = false;
						}
					}
					else
					{
						var::velocity::velocity_used = false;
					}
				}
				std::this_thread::sleep_for( std::chrono::milliseconds( 150 ) );
			}
		}

		void velocityscan( DWORD min, DWORD max )
		{
			if ( HANDLE processhandle = LI_FN( OpenProcess ).cached( )( THREAD_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, false, utils::cute::get_processid( "javaw.exe" ) ) )
			{
				bool breakscan = var::velocity::velocity_tab; size_t address = min;
				while ( address < max )
				{
					if ( breakscan != var::velocity::velocity_tab )
					{
						break;
					}
					std::vector<double> buffer( MEMBLOCK );
					if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) address, &buffer[ 0 ], MEMBLOCK, 0 ) )
					{
						for ( size_t i = 0; i < buffer.size( ); ++i )
						{
							if ( breakscan != var::velocity::velocity_tab )
							{
								break;
							}
							if ( buffer[ i ] == 8000 )
							{
								if ( buffer[ i + 1 ] == 8000 && buffer[ i + 2 ] == 8000 )
								{
									if ( buffer[ i + 3 ] == 8000 )
									{
										breakscan = true; 
										break;
									}
									else
									{
										var::velocity::locationsv1.push_back( address + ( ( i + 1 ) * sizeof( double ) ) - sizeof( double ) );
										var::velocity::locationsv1.erase( unique( var::velocity::locationsv1.begin( ), var::velocity::locationsv1.end( ) ), var::velocity::locationsv1.end( ) );

										var::velocity::locationsv1.push_back( address + ( ( i + 3 ) * sizeof( double ) ) - sizeof( double ) );
										var::velocity::locationsv1.erase( unique( var::velocity::locationsv1.begin( ), var::velocity::locationsv1.end( ) ), var::velocity::locationsv1.end( ) );

										sort( var::velocity::locationsv1.begin( ), var::velocity::locationsv1.end( ) );
										var::velocity::locationsv1.erase( unique( var::velocity::locationsv1.begin( ), var::velocity::locationsv1.end( ) ), var::velocity::locationsv1.end( ) );
									}
								}
							}
						}
					} address += MEMBLOCK;
				} CloseHandle( processhandle );
			}
		}
	}

	namespace thread
	{
		void thread_velocity( )
		{
			CreateThread( nullptr, 0, ( LPTHREAD_START_ROUTINE ) &velocity::velocityupdater, nullptr, 0, 0 );
			while ( 1 )
			{
				while ( var::velocity::velocity_tab )
				{
					if ( !var::velocity::velocity_used )
					{
						var::velocity::velocity_used = true;
					} velocity::velocityscan( 0x02000000, 0x08000000 );
					for ( int i = 0; i < 2500; ++i )
					{
						std::this_thread::sleep_for( std::chrono::milliseconds( 15 ) ); if ( !var::velocity::velocity_tab )
						{
							break;
						}
					}
				}
				std::this_thread::sleep_for( std::chrono::milliseconds( 15 ) );
			}
		}
	}
}