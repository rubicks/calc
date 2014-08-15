/* calc/ntctx.cpp */

#include<boost/utility.hpp>
#include<boost/exception/all.hpp>


#include"ntctx.hpp"
#include"nt.yy.hh"
#include"nt.ll.hh"

namespace{
    struct _error : virtual std::exception, virtual boost::exception {} ;
}

ntctx::ntctx( void )
{
    if( 0 != yylex_init( boost::addressof( scanner_ ) ) )
        BOOST_THROW_EXCEPTION
            ( _error()
              << boost::errinfo_api_function( "yylex_init" )
              << boost::errinfo_errno( errno ) );
}

ntctx::~ntctx( void )
{
    if( 0 != yylex_destroy( scanner_ ) )
        BOOST_THROW_EXCEPTION
            ( _error()
              << boost::errinfo_api_function( "yylex_destroy" )
              << boost::errinfo_errno( errno ) );
}
