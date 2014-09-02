/* calc/dumbctx.cc */

#include <cmath>
#include <iostream>

#include "dumbctx.hh"

std::ostream&
operator<<( std::ostream&os,
            dumbctx_t const&ctx )
{
    return os << ctx.value_ ;
}

dumbctx_t
operator+( dumbctx_t const&lhs,
           dumbctx_t const&rhs )
{
    dumbctx_t ret = lhs ;
    ret.value_ += rhs.value_ ;
    return ret ;
}

dumbctx_t
operator-( dumbctx_t const&lhs,
           dumbctx_t const&rhs )
{
    dumbctx_t ret = lhs ;
    ret.value_ -= rhs.value_ ;
    return ret ;
}

dumbctx_t
operator*( dumbctx_t const&lhs,
           dumbctx_t const&rhs )
{
    dumbctx_t ret = lhs ;
    ret.value_ *= rhs.value_ ;
    return ret ;
}

dumbctx_t
operator/( dumbctx_t const&lhs,
           dumbctx_t const&rhs )
{
    dumbctx_t ret = lhs ;
    ret.value_ /= rhs.value_ ;
    return ret ;
}

dumbctx_t
operator-( dumbctx_t const&o )
{
    dumbctx_t ret = o ;
    ret.value_ *= -1 ;
    return ret ;
}

dumbctx_t
pow( dumbctx_t const&lhs,
     dumbctx_t const&rhs )
{
    dumbctx_t ret ;
    ret.value_ = std::pow( lhs.value_, rhs.value_ );
    return ret ;
}

