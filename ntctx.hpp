/* calc/ntctx.hpp */

#ifndef __NTCTX_HPP__
#define __NTCTX_HPP__

#include<iostream>

struct ntctx
{
    void * scanner_ ;
    union
    {
        double dval ;
        long   ival ;
        char   cval ;
        char*  sval ;
        void*  pval ;
    } u ;
    ntctx( void  );
    ~ntctx( void  );
};

#endif//ndef __NTCTX_HPP__
