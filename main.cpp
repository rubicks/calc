/* calc/main.cpp */


#include<iostream>


#ifdef HAVE_CONFIG_H
#  include"config.h"
#else
#  error"config.h"
#endif

#include "calc.hpp"


/* #ifdef HAVE_BOOST_THREAD_HPP */
/* #  include<boost/thread.hpp> */
/* #else */
/* #  error"boost/thread.hpp" */
/* #endif */


namespace
{
    void
    foo( void )
    {
        std::cout << std::endl << __PRETTY_FUNCTION__ << std::endl ;
    }
}

int
main( int argc, char**argv )
{
    std::cout
        << std::endl
        << __PRETTY_FUNCTION__
        << std::endl
        ;

    return calc::eval( argc, argv );
}
