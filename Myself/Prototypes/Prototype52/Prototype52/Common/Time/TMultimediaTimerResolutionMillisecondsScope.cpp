#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TMultimediaTimerResolutionMillisecondsScope.hpp"

#include "./TTimeHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Time
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TMultimediaTimerResolutionMillisecondsScope::TMultimediaTimerResolutionMillisecondsScope
      ( int multimediaTimerResolutionMilliseconds1
      ) :
      // yg? I believe this initialization is unnecessary as if {TTimeHelpers::AtomicSetMultimediaTimerResolutionMilliseconds}
      // yg? throws an exception the destructor won't be called.
      // yg? If I fix this I would also need to make some other changes elsewhere in this code, which I don't want to do as this whole class
      // yg? should be eliminated.
      MultimediaTimerResolutionMilliseconds_( ::std::numeric_limits< int >::lowest() )
   {
      TTimeHelpers::AtomicSetMultimediaTimerResolutionMilliseconds( multimediaTimerResolutionMilliseconds1 );
      MultimediaTimerResolutionMilliseconds_ = multimediaTimerResolutionMilliseconds1;
   }

#endif
#if( /* {public} Instance destructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TMultimediaTimerResolutionMillisecondsScope::~TMultimediaTimerResolutionMillisecondsScope()
   {
      if( MultimediaTimerResolutionMilliseconds_ >= 0 )
      {
         TTimeHelpers::AtomicRestoreMultimediaTimerResolutionMilliseconds( MultimediaTimerResolutionMilliseconds_ );
      }
   }

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
}
}
