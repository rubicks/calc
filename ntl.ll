/* calc/ntl.ll */

%{
/* ntl.ll code block begin */
#include<cmath>
#include<iostream>
#include<boost/lexical_cast.hpp>
#include"ntctx.hpp"
#include"nty.hh"
#include"where.hpp"
/* ntl.ll code block end */
%}


/* flex options section */
%option reentrant
%option bison-bridge
%option noyywrap
%option header-file="ntl.hh"
%option outfile="ntl.cc"


/* definitions section */
DIGIT  [0-9]
WS     [ \t\n]
OP     [-+*/^]


%%

{DIGIT}+ {
    std::cout
        << std::endl
        << WHERE_STRING()
        << std::endl
        << "INTEGER (code " << INTEGER << ")"
        << " .. yytext == \"" << yytext << "\""
        << " .. atol( yytext ) == " << atol( yytext )
        << std::endl
        ;
    yylval->u.ival = atol( yytext );
    return INTEGER ;
}

{DIGIT}+"."{DIGIT}* {
    std::cout
        << std::endl
        << WHERE_STRING()
        << std::endl
        << "REAL (code " << REAL << ")"
        << " .. yytext == \"" << yytext << "\""
        << " .. atof( yytext ) == " << atof( yytext )
        << std::endl
        ;
    yylval->u.dval = atof( yytext );
    return REAL ;
}

{WS}+ {
    /* eat whitespace */
}

{OP} {
    std::cout
        << std::endl
        << WHERE_STRING()
        << std::endl
        << "OP"
        << " .. *yytext == \'" << *yytext << "\'"
        << " .. unsigned( *yytext ) == "
        << std::dec
        << unsigned( *yytext )
        << " == "
        << std::hex << std::showbase
        << unsigned( *yytext )
        << std::endl
        ;
    return ( yylval->u.ival = * reinterpret_cast< int* >( yytext ) );
}

. {
    fprintf( stderr, "unrecognized character: %s\n", yytext );
}

%%

