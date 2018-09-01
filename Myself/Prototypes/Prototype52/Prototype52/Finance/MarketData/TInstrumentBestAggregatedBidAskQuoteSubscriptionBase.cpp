#pragma once

#include "StdAfx.h"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrumentBestAggregatedBidAskQuoteSubscriptionBase.hpp"

#include "../TInstrumentDataSubscriptionBase.cpp"
#include "./TInstrumentBestAggregatedBidAskQuote.cpp"

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
   inline TInstrumentBestAggregatedBidAskQuoteSubscriptionBase< TDerivedDataType_, TInstrument_ >::TInstrumentBestAggregatedBidAskQuoteSubscriptionBase()
   {
      InstrumentBestAggregatedBidAskQuote.Reset();
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

   //inline void TInstrumentBestAggregatedBidAskQuoteSubscriptionBase::Unsubscribe>>>Async()
   //{
   //   Instrument->BrokerAdapter->Unsubscribe>>>Async( * this );
   //}

#endif
#if( /* //{public Unsubscribe>>>Async}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TSubscriber_ <<<rename to {TSubscriber1}.
   //   >
   //inline void TInstrumentBestAggregatedBidAskQuoteSubscriptionBase::Unsubscribe>>>Async
   //   ( TSubscriber_ & subscriber1,
   //     void ( TSubscriber_:: * method1 )( /*void const *,*/ /*::Poco::EventArgs &*/ TInstrumentBestAggregatedBidAskQuoteSubscriptionBase * & )
   //   )
   //{
   //   Instrument->BrokerAdapter->Unsubscribe>>>Async( ( * this ), subscriber1, method1 );
   //}

#endif
}
}
