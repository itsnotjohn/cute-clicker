namespace combat
{
	namespace reach
	{
		void reachupdater( )
		{
			double dlimitd = 4.5;
			double dreachd = 3;
			float dreachf = 3;

			float bufferf;
			double bufferd;
			while ( true )
			{
				if ( var::reach::reach_used )
				{
					double nlimitd = var::reach::distance + 1.5;
					float nreachf = var::reach::distance;
					double nreachd = var::reach::distance;
					if ( HANDLE processhandle = LI_FN( OpenProcess ).cached( )( THREAD_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, false, utils::cute::get_processid( "javaw.exe" ) ) )
					{

						if ( var::reach::reach_tab )
						{
							std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
							for ( size_t i = 0; i < var::reach::locationsreachf.size( ); ++i )
							{
								if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationsreachf[ i ] ), &bufferf, sizeof( float ), 0 ) )
								{
									if ( bufferf > 2.99 && bufferf < 20.01 )
									{
										LI_FN( WriteProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationsreachf[ i ] ), &nreachf, sizeof( float ), 0 );
									}
									else
									{
										var::reach::locationsreachf.erase( var::reach::locationsreachf.begin( ) + i ); i -= 2;
									}
								}
							}
							for ( size_t i = 0; i < var::reach::locationsreachd.size( ); ++i )
							{
								if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationsreachd[ i ] ), &bufferd, sizeof( double ), 0 ) )
								{
									if ( bufferd > 2.99 && bufferd < 20.01 )
									{
										LI_FN( WriteProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationsreachd[ i ] ), &nreachd, sizeof( double ), 0 );
									}
									else
									{
										var::reach::locationsreachd.erase( var::reach::locationsreachd.begin( ) + i ); i -= 2;
									}
								}
							}
							for ( size_t i = 0; i < var::reach::locationslimit.size( ); ++i )
							{
								if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationslimit[ i ] ), &bufferd, sizeof( double ), 0 ) )
								{
									if ( bufferd > 4.49 && bufferd < 21.51 )
									{
										LI_FN( WriteProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationslimit[ i ] ), &nlimitd, sizeof( double ), 0 );
									}
									else
									{
										var::reach::locationslimit.erase( var::reach::locationslimit.begin( ) + i ); i -= 2;
									}
								}
							}
						}
						else
						{
							std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
							for ( size_t i = 0; i < var::reach::locationsreachf.size( ); ++i )
							{
								if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationsreachf[ i ] ), &bufferf, sizeof( float ), 0 ) )
								{
									if ( bufferf > 2.99 && bufferf < 6.01 )
									{
										LI_FN( WriteProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationsreachf[ i ] ), &dreachf, sizeof( float ), 0 );
									}
									else
									{
										var::reach::locationsreachf.erase( var::reach::locationsreachf.begin( ) + i ); i -= 2;
									}
								}
							}
							for ( size_t i = 0; i < var::reach::locationsreachd.size( ); ++i )
							{
								if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationsreachd[ i ] ), &bufferd, sizeof( double ), 0 ) )
								{
									if ( bufferd > 2.99 && bufferd < 6.01 )
									{
										LI_FN( WriteProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationsreachd[ i ] ), &dreachd, sizeof( double ), 0 );
									}
									else
									{
										var::reach::locationsreachd.erase( var::reach::locationsreachd.begin( ) + i ); i -= 2;
									}
								}
							}
							for ( size_t i = 0; i < var::reach::locationslimit.size( ); ++i )
							{
								if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationslimit[ i ] ), &bufferd, sizeof( double ), 0 ) )
								{
									if ( bufferd > 4.49 && bufferd < 7.51 )
									{
										LI_FN( WriteProcessMemory ).cached( )( processhandle, ( LPVOID ) ( var::reach::locationslimit[ i ] ), &dlimitd, sizeof( double ), 0 );
									}
									else
									{
										var::reach::locationslimit.erase( var::reach::locationslimit.begin( ) + i ); i -= 2;
									}
								}
							}
							var::reach::reach_used = false;
						}
					}
					else
					{
						var::reach::reach_used = false;
					}
				} std::this_thread::sleep_for( std::chrono::milliseconds( 15 ) );
			}
		}

		void reachscan( DWORD min, DWORD max )
		{
			if ( HANDLE processhandle = LI_FN( OpenProcess ).cached( )( THREAD_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, false, utils::cute::get_processid( "javaw.exe" ) ) )
			{
				bool breakscan = var::reach::reach_tab; size_t address = min;
				while ( address < max )
				{
					if ( breakscan != var::reach::reach_tab )
					{
						break;
					}
					std::vector<double> buffer( MEMBLOCK );
					std::vector<float> buffer2( MEMBLOCK );
					if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) address, &buffer[ 0 ], MEMBLOCK, 0 ) )
					{
						for ( size_t i = 0; i < buffer.size( ); ++i )
						{
							if ( breakscan != var::reach::reach_tab )
							{
								break;
							}
							if ( buffer[ i ] == 4.5 )
							{
								for ( size_t o = 0; o < buffer.size( ); ++o )
								{
									if ( buffer[ o ] == 3 )
									{
										var::reach::locationslimit.push_back( address + ( ( i + 1 ) * sizeof( double ) ) - sizeof( double ) ); sort( var::reach::locationslimit.begin( ), var::reach::locationslimit.end( ) );
										var::reach::locationslimit.erase( unique( var::reach::locationslimit.begin( ), var::reach::locationslimit.end( ) ), var::reach::locationslimit.end( ) );

										var::reach::locationsreachd.push_back( address + ( ( o + 1 ) * sizeof( double ) ) - sizeof( double ) ); sort( var::reach::locationsreachd.begin( ), var::reach::locationsreachd.end( ) );
										var::reach::locationsreachd.erase( unique( var::reach::locationsreachd.begin( ), var::reach::locationsreachd.end( ) ), var::reach::locationsreachd.end( ) );
									}
								}
								if ( LI_FN( ReadProcessMemory ).cached( )( processhandle, ( LPVOID ) address, &buffer2[ 0 ], MEMBLOCK, 0 ) )
								{
									for ( size_t o = 0; o < buffer2.size( ); ++o )
									{
										if ( buffer2[ o ] == 3 )
										{
											var::reach::locationslimit.push_back( address + ( ( i + 1 ) * sizeof( double ) ) - sizeof( double ) ); sort( var::reach::locationslimit.begin( ), var::reach::locationslimit.end( ) );
											var::reach::locationslimit.erase( unique( var::reach::locationslimit.begin( ), var::reach::locationslimit.end( ) ), var::reach::locationslimit.end( ) );

											var::reach::locationsreachf.push_back( address + ( ( o + 1 ) * sizeof( float ) ) - sizeof( float ) ); sort( var::reach::locationsreachf.begin( ), var::reach::locationsreachf.end( ) );
											var::reach::locationsreachf.erase( unique( var::reach::locationsreachf.begin( ), var::reach::locationsreachf.end( ) ), var::reach::locationsreachf.end( ) );
										}
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
		void thread_reach( )
		{
			CreateThread( nullptr, 0, ( LPTHREAD_START_ROUTINE ) &reach::reachupdater, nullptr, 0, 0 );
			while ( true )
			{
				while ( var::reach::reach_tab )
				{
					if ( !var::reach::reach_used )
					{
						var::reach::reach_used = true;
					} combat::reach::reachscan( 0x02000000, 0x06000000 );
					for ( int i = 0; i < 2500; ++i )
					{
						std::this_thread::sleep_for( std::chrono::milliseconds( 15 ) ); if ( !var::reach::reach_tab )
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