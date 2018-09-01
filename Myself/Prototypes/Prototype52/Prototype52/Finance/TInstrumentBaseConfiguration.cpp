#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrumentBaseConfiguration.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Finance
{
#if( /* {protected} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TInstrumentBaseConfiguration::TInstrumentBaseConfiguration()
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

   void TInstrumentBaseConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
