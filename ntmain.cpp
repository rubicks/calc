/* calc/ntmain.cpp */

#include<iostream>
#include<string>

#include<boost/utility.hpp>

#include"ntctx.hpp"
#include"nt.yy.hh"
#include"nt.ll.hh"


int
main( int argc, char**argv ){
    std::string s ;
    for( int i = 1 ; i != argc ; ++i ){
        /* std::cout */
        /*     << "argv[" << std::dec << i << "] == \"" */
        /*     << argv[i] << "\"" << std::endl ; */
        s += " " ;
        s += argv[i] ;
    }
    std::cout
        << std::endl
        << "s == \"" << s << "\""
        << std::endl
        ;

    yyscan_t scanner ;

    {
        int stat = yylex_init( &scanner );
        std::cout
            << std::endl
            << "yylex_init( &scanner ) == "
            << stat
            << std::endl
            ;
        if( 0 != stat ) return stat ;
    }

    YY_BUFFER_STATE bs = yy_scan_string( s.c_str(), scanner );

    YYSTYPE val ;
    std::cout
        << std::endl
        << "sizeof( val ) == "
        << std::dec
        << sizeof( val )
        << std::endl
        ;

    {
        int stat ;
        do{
            stat = yylex( &val, scanner );
            std::cout
                << std::endl
                << "yylex( &val, scanner ) == "
                << std::dec << stat
                << std::endl
                ;
        }while( 0 != stat );
    }

    {
        int stat = yylex_destroy( scanner );
        std::cout
            << std::endl
            << "yylex_destroy( scanner ) == "
            << stat
            << std::endl
            ;
        if( 0 != stat ) return stat ;
    }

    return 0 ;
}
