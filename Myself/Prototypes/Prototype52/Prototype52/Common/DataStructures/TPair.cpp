#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPair.hpp"

//#include "./.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace DataStructures
{
#if( /* {public operator ==}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue1_,
         typename TValue2_
      >
   inline bool operator ==
      ( TPair< TValue1_, TValue2_ > const & instance1,
        TPair< TValue1_, TValue2_ > const & instance2
      )
   {
      return ( instance1.Value1 == instance2.Value1 && instance1.Value2 == instance2.Value2 );
   }

#endif
#if( /* {public operator !=}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue1_,
         typename TValue2_
      >
   inline bool operator !=
      ( TPair< TValue1_, TValue2_ > const & instance1,
        TPair< TValue1_, TValue2_ > const & instance2
      )
   {
      return ( ! ( instance1 == instance2 ) );
   }

#endif
}
}
