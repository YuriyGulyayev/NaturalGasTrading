#pragma once

#include "StdAfx.h"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrumentTradeSubscriptionBase.hpp"

#include "../TInstrumentDataSubscriptionBase.cpp"
#include "./TInstrumentTrade.cpp"

#include "../../Common/SourceCodeModel/SourceFooter.hpp"

namespace Finance
{
namespace MarketData
{
#if( /* {protected} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TDerivedDataType_,
         typename TInstrument_
      >
   inline TInstrumentTradeSubscriptionBase< TDerivedDataType_, TInstrument_ >::TInstrumentTradeSubscriptionBase()
   {
      InstrumentTrade.Reset();
   }

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

#if( /* //{public Unsubscribe>>>Async}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TInstrumentTradeSubscriptionBase::Unsubscribe>>>Async()
   //{
   //   Instrument->BrokerAdapter->Unsubscribe>>>Async( * this );
   //}

#endif
}
}
