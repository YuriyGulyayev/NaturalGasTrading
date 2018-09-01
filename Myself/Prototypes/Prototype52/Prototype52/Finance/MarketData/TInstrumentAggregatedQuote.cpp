#pragma once

#include "StdAfx.h"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrumentAggregatedQuote.hpp"

#include "../Math/TQuantityAndPrice.cpp"

#include "../../Common/SourceCodeModel/SourceFooter.hpp"

namespace Finance
{
namespace MarketData
{
#if( /* {(public)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public Reset}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TInstrumentAggregatedQuote::Reset()
   {
      TQuantityAndPrice::Reset();

      NumberOrders = 0;
   }

#endif
#if( /* {public Equals}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TInstrumentAggregatedQuote::Equals
      ( TInstrumentAggregatedQuote const & instance1,
        TInstrumentAggregatedQuote const & instance2
      )
   {
      return ( instance1.NumberOrders == instance2.NumberOrders && TQuantityAndPrice::Equals( instance1, instance2 ) );
   }

#endif
}
}
