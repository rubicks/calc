/* calc/yyctx.cpp */

#include "yyctx.hpp"
#include "parser.hh"
#include "lexer.hh"

yyctx::yyctx( void )
{
    yylex_init( &scanner_ );
}

yyctx::~yyctx( void )
{
    yylex_destroy( scanner_ );
}
