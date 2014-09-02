/* calc/util.cc */


#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "ntctx.hpp"
#include "nty.hh"
#include "ntl.hh"
#include "util.hh"
#include "where.hpp"


void*
calc::util::scanner_create( void )
{
    void * scanner ;
    int stat = yylex_init( &scanner );
    if( 0 == stat ){
        return scanner ;
    }
    std::stringstream ss ;
    ss
        << std::endl
        << WHERE_STRING()
        << std::endl
        << "yylex_init( "
        << std::hex << std::showbase << &scanner
        << " ) == " << std::dec << stat
        << std::endl
        ;
    throw std::runtime_error( ss.str() );
}


void
calc::util::scanner_destroy( void*scanner )
{
    int stat = yylex_destroy( scanner );
    if( 0 == stat ){
        scanner = 0 ;
        return ;
    }
    std::stringstream ss ;
    ss
        << std::endl
        << WHERE_STRING()
        << std::endl
        << "yylex_destroy( "
        << std::hex << std::showbase << scanner
        << " ) == " << std::dec << stat
        << std::endl
        ;
    throw std::runtime_error( ss.str() );
}
