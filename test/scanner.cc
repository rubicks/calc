/* calc/test/scanner.cc */

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "ntctx.hpp"
#include "nty.hh"
#include "ntl.hh"
#include "util.hh"
#include "where.hpp"


namespace
{
    std::vector< int >
    _scan( std::string const&s )
    {
        std::vector< int >ret ;

        ntctx*pval = ntctx_create();

        YY_BUFFER_STATE bs = yy_scan_string( s.c_str(), pval->scanner_ );

        int stat = 0 ;
        while( 0 != ( stat = yylex( pval, pval->scanner_ ) ) ){
            std::cout
                << std::endl
                << "yylex( &val, scanner ) == "
                << std::dec << stat
                << std::endl
                ;
            ret.push_back( stat );
        }
        return ret ;

        ntctx_destroy( pval );
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

    std::vector< int >v = _scan( "42 + 6 / 9" );


    return 0 ;
}
