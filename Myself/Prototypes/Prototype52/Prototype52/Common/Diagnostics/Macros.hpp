#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

// yg? Does this belong to the {CodeOptimization} namespace?
#if( defined( _MSC_VER ) )
   //#define YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( condition ) ( assert( condition ) , __assume( condition ) )
   #define YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( condition ) do { assert( condition ); __assume( condition ); } while( static_cast< void >( false ) , false )
#elif( defined( __GNUC__ ) )
   #error yg?? Revisit this.
   //#define YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( condition ) ( assert( condition ) , ::__builtin_assume( condition ) )
   #define YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( condition ) { assert( condition ); ::__builtin_assume( condition ); } >>>while
#else
   #error ...
#endif
