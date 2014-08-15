/* calc.cpp */

#include <iostream>
#include "calc.hpp"
#include "yyctx.hpp"
#include "parser.hh"
#include "lexer.hh"


int
calc::eval( int, char** )
{
    std::cout
        << std::endl
        << __PRETTY_FUNCTION__
        << std::endl
        ;

    yyctx ctx ;
    int stat = yyparse( &ctx );
    
    return 0 ;
}
