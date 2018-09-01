#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TDateTimeKeeperConfiguration.hpp"

//#include "./.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Time
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDateTimeKeeperConfiguration::TDateTimeKeeperConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TDateTimeKeeperConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
}
