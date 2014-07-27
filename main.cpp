/* calc/main.cpp */


#include<iostream>


#ifdef HAVE_CONFIG_H
#  include"config.h"
#else
#  error"config.h"
#endif

#ifdef HAVE_BOOST_THREAD_HPP
#  include<boost/thread.hpp>
#else
#  error"boost/thread.hpp"
#endif


namespace
{

    struct callable
    {
        void
        operator()( void )
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl ;
        }
    };
}

int
main( int argc, char**argv )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;

    callable c;

    boost::thread t( c );
    t.join();
    
    return 0 ;
}
