/* calc/ntctx.cpp */

#include <boost/utility.hpp>
#include <boost/exception/all.hpp>


#include "ntctx.hpp"
#include "nty.hh"
#include "ntl.hh"
#include "util.hh"

namespace{
    struct _error : virtual std::exception, virtual boost::exception {} ;
}


ntctx*
ntctx_create( void )
{
    ntctx*p = new ntctx ;
    p->scanner_ = calc::util::scanner_create();
    return p ;
}


void
ntctx_destroy( ntctx*p )
{
    calc::util::scanner_destroy( p->scanner_ );
    delete p ;
    p = 0 ;
}


