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
    unsigned long
    _addy( void*p ){ return reinterpret_cast< unsigned long >( p ); }

    struct parse
    {
        typedef struct result_type
        {
            int stat_ ;
            dumbctx_t ctx_ ;
        } result_type ;

        result_type
        operator()( std::string const&s )
        {
            result_type ret ;

            {
                int stat = yylex_init( &( ret.ctx_.scanner_ ) );
                if( 0 != stat ){
                    std::stringstream ss ;
                    ss
                        << "yylex_init( "
                        << std::hex << std::showbase
                        << _addy( &( ret.ctx_.scanner_ ) )
                        << " ) == "
                        << std::dec
                        << stat
                        ;
                    throw std::runtime_error( ss.str() );
                }
            }

            YY_BUFFER_STATE bs =
                yy_scan_string( s.c_str(), ret.ctx_.scanner_ );

            ret.stat_ = yyparse( &( ret.ctx_ ) );

            {
                int stat = yylex_destroy( ret.ctx_.scanner_ );
                if( 0 != stat ){
                    std::stringstream ss ;
                    ss
                        << "yylex_destroy( "
                        << std::hex << std::showbase
                        << _addy( ret.ctx_.scanner_ )
                        << " ) == "
                        << std::dec
                        << stat
                        ;
                    throw std::runtime_error( ss.str() );
                }
            }

            return ret ;
        }
    } _parse ;

    std::ostream&
    operator<<( std::ostream&os, parse::result_type const&x )
    {
        return
            os << "{ stat_:" << x.stat_
               << ", ctx_:" << x.ctx_
               << " }"
            ;
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

    {
        std::string s = "42" ;
        std::cout
            << "_parse( \"" << s << "\" ) == "
            << _parse( s )
            << std::endl
            ;
    }
    {
        std::string s = "11 + 31 - 17" ;
        std::cout
            << "_parse( \"" << s << "\" ) == "
            << _parse( s )
            << std::endl
            ;
    }
    {
        std::string s = "11 + 15 / 3" ;
        std::cout
            << "_parse( \"" << s << "\" ) == "
            << _parse( s )
            << std::endl
            ;
    }
    {
        std::string s = "2 ^ 3 ^ 2" ;
        std::cout
            << "_parse( \"" << s << "\" ) == "
            << _parse( s )
            << std::endl
            ;
    }

    return 0 ;
}
