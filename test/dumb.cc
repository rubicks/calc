/* calc/test/dumb.cc */

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "dumbctx.hh"
#include "dumbyy.hh"
#include "dumbll.hh"
#include "where.hpp"


namespace
{
    int
    _parse( std::string const&s )
    {
        dumbctx_t dumbctx ;
        {
            int stat = yylex_init( &(dumbctx.scanner_) );
            if( 0 != stat ) return stat ;
        }

        YY_BUFFER_STATE bs = yy_scan_string( s.c_str(), dumbctx.scanner_ );

        int ret = yyparse( &dumbctx );

        {
            std::cout
                << std::endl
                << "yyparse( \""
                << s
                << "\", "
                << std::hex << std::showbase << ( &dumbctx )
                << " ) == "
                << std::dec << ret
                << std::endl
                ;
        }

        if( 0 == ret ){
            std::cout
                << std::endl
                << "dumbctx.value_ == "
                << std::dec
                << dumbctx.value_
                << std::endl
                ;
        }

        {
            int stat = yylex_destroy( (dumbctx.scanner_) );
            if( 0 != stat ) return stat ;
        }

        return ret ;
    }
}


int
main( int, char** )
{
    std::cout
        << std::endl
        << WHERE_STRING()
        << std::endl
        ;

    std::cout
        << std::endl
        << "_parse( \"42\" ) == "
        << std::dec << _parse( "42" )
        << std::endl
        ;

    return 0 ;
}
