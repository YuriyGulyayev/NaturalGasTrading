#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

#if( defined( _MSC_VER ) )
   // yg? We probably can define this macro as {YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( false )}.
   //#define YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE() ( assert( false ) , __assume( false ) )
   #define YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE() do { assert( false ); __assume( false ); } while( static_cast< void >( false ) , false )
#elif( defined( __GNUC__ ) )
   #error yg?? ToDo
   // yg? If this doesn't work try {::__builtin_trap} or {::__builtin_assume( false )}.
/*
   #if __GNUC__ * 100 + __GNUC_MINOR__ >= 405
      #define UNREACHABLE() __builtin_unreachable()
  +#elif __GNUC__ * 100 + __GNUC_MINOR__ >= 404
  +#define UNREACHABLE() __builtin_trap()
  +#elif _MSC_VER
  +#define UNREACHABLE() __assume(0)
*/
   //#define YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE() ( assert( false ) , ::__builtin_unreachable() )
   #define YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE() { assert( false ); ::__builtin_unreachable(); } >>>do+while
#else
   #error ...
#endif
