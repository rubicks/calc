/* calc/where.hpp */

#ifndef ___CALC___WHERE_HPP___
#define ___CALC___WHERE_HPP___

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

#endif//ndef ___CALC___WHERE_HPP___
