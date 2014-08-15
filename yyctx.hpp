/* calc/yyctx.hpp */

#ifndef __YYCTX_HPP__
#define __YYCTX_HPP__

struct yyctx
{
    void * scanner_ ;
    union
    {
        double dval ;
        char*  sval ;
    } u ;
    yyctx( void  );
    ~yyctx( void  );
};

void yyerror( yyctx*lvalp, char const*msg );

#endif//ndef __YYCTX_HPP__
