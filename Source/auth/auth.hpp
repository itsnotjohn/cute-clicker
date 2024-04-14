/*#include <Windows.h>
#include <array>
#include <random>
#include "Source/utils/lib/md5.h"
#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")
namespace auth
{
    std::string replaceAll( std::string subject, const std::string &search, const std::string &replace )
    {
        size_t pos = 0;
        while ( ( pos = subject.find( search, pos ) ) != std::string::npos )
        {
            subject.replace( pos, search.length( ), replace );
            pos += replace.length( );
        };
        return subject;
    };

    bool IsChaveDash( char c )
    {
        switch ( c )
        {
            case  ( 'P' ):
            case  ( 'r' ):
            case  ( 'o' ):
            case  ( 'c' ):
            case  ( 'e' ):
            case  ( 's' ):
            case  ( 'd' ):
            case  ( 'I' ):
            case  ( '-' ):
            case  ( 'U' ):
            case  ( 'H' ):
            case  ( 'Y' ):
            case  ( 'S' ):
            case  ( 'C' ):
            case  ( 'A' ):
            case  ( 'L' ):
            case  ( 'D' ):
            case  ( 'R' ):
            case  ( 'V' ):
            case  ( 'E' ):
            case  ( '0' ):
            case  ( '\\' ):
            case  ( ',' ):
            case ( '.' ):
                return true;
            default:
                return false;
        }
    }

    std::string exec( const char *cmd )
    {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype( &_pclose )> pipe( _popen( ( cmd ), "r" ), _pclose );
        if ( !pipe )
        {
            return "";
        }
        while ( fgets( buffer.data( ), buffer.size( ), pipe.get( ) ) != nullptr )
        {
            ( ( result ) ) += buffer.data( );
        }
        std::string output;
        ( output.reserve( result.length( ) ) );

        std::copy_if( result.begin( ), result.end( ),
                      std::back_inserter( ( ( output ) ) ),
                      [ ]( char c )
        {
            return c != '\r' && c != '\n' && c != ' ';
        } );
        return ( ( output ) );
    }

    std::string DownloadURL( std::string URL )
    {
        HINTERNET interwebs = InternetOpenA( "Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL );
        HINTERNET urlFile;
        std::string rtn;
        if ( interwebs )
        {
            urlFile = InternetOpenUrlA( interwebs, URL.c_str( ), NULL, NULL, NULL, NULL );
            if ( urlFile )
            {
                char buffer[ 2000 ];
                DWORD bytesRead;
                do
                {
                    InternetReadFile( urlFile, buffer, 2000, &bytesRead );
                    rtn.append( buffer, bytesRead );
                    memset( buffer, 0, 2000 );
                } while ( bytesRead );
                InternetCloseHandle( interwebs );
                InternetCloseHandle( urlFile );
                std::string p = replaceAll( rtn, "|n", "\r\n" );
                return p;
            };
        };
        InternetCloseHandle( interwebs );
        std::string p = replaceAll( rtn, "|n", "\r\n" );
        return p;
    };

    void toClipboard( const std::string &s )
    {
        HWND hwnd = GetDesktopWindow( );
        OpenClipboard( hwnd );
        EmptyClipboard( );
        HGLOBAL hg = GlobalAlloc( GMEM_MOVEABLE, s.size( ) + 1 );
        if ( !hg )
        {
            CloseClipboard( );
            return;
        }
        memcpy( GlobalLock( hg ), s.c_str( ), s.size( ) + 1 );
        GlobalUnlock( hg );
        SetClipboardData( CF_TEXT, hg );
        CloseClipboard( );
        GlobalFree( hg );
    }

    std::string a = exec( "wmic csproduct get uuid" );
    std::string b = exec( "wmic cpu get ProcessorId" );
    std::string c = exec( "wmic diskdrive get name,serialnumber|find \"DRIVE0\"" );
    std::string d = md5( c += a );
    std::string e = md5( d += b );

    std::string host = base64::Decrypt( "aHR0cDovL2N1dGUuc3VyZi9mdW5jcy9od2lkL2NoZWNrZXIucGhwP2xpc3Q9" );

    bool auth( std::string hot )
    {
        std::string hostfile = ( host.c_str( ) );
        hot.erase( std::remove_if( hot.begin( ), hot.end( ), &IsChaveDash ), hot.end( ) );
        std::transform( hot.begin( ), hot.end( ), hot.begin( ), ::toupper );
        std::string result = DownloadURL( hostfile += hot );
        if ( result.length( ) == 20 )
        {
            return true;
        }
        {
            return false;
        };
    };
}*/