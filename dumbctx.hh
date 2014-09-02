/* calc/dumbctx.hh */

#ifndef __DUMBCTX_HH__
#define __DUMBCTX_HH__

#include <iostream>

typedef struct{
    void*scanner_ ;
    double value_ ;
} dumbctx_t ;


std::ostream&
operator<<( std::ostream&os,
            dumbctx_t const&ctx );

dumbctx_t
operator+( dumbctx_t const&lhs,
           dumbctx_t const&rhs );

dumbctx_t
operator-( dumbctx_t const&lhs,
           dumbctx_t const&rhs );

dumbctx_t
operator*( dumbctx_t const&lhs,
           dumbctx_t const&rhs );

dumbctx_t
operator/( dumbctx_t const&lhs,
           dumbctx_t const&rhs );

dumbctx_t
operator-( dumbctx_t const&o );

dumbctx_t
pow( dumbctx_t const&lhs,
     dumbctx_t const&rhs );

#endif//ndef __DUMBCTX_HH__
