/* calc/where.hpp */

#ifndef __WHERE_HPP__
#define __WHERE_HPP__

#include<string>
#include<boost/preprocessor/stringize.hpp>

#define WHERE_STRING()                                      \
    ( ::std::string                                         \
      ( ::std::string( __PRETTY_FUNCTION__ ) +              \
        ::std::string( " at " )              +              \
        ::std::string( __FILE__ )            +              \
        ::std::string( ":" )                 +              \
        ::std::string( BOOST_PP_STRINGIZE( __LINE__ ) ) ) ) \
/**/

#endif//ndef __WHERE_HPP__
