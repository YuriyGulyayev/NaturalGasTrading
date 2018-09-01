#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TWarmUpHelpers.hpp"

#include "../Time/TTimeHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace WarmUp
{
#if( /* {private TLifeTimeScope_}. */ 1 )
   #if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TWarmUpHelpers::TLifeTimeScope_::TLifeTimeScope_()
   {
   }

   #endif
   #if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
   #if( /* {public} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TWarmUpHelpers::TLifeTimeScope_::~TLifeTimeScope_()
   {
      // yg? Assuming this code will not be over-optimized.
      // yg? To be tested on Linux.
      if( TWarmUpHelpers::WarmUpState != 1234567890 )
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds();
      }
   }

   #endif
   #if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
#endif

#if( /* {private LifeTimeScope_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TWarmUpHelpers::TLifeTimeScope_ TWarmUpHelpers::LifeTimeScope_;

#endif

#if( /* {public WarmUpState}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TWarmUpHelpers::WarmUpState;

#endif

#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
}
}
