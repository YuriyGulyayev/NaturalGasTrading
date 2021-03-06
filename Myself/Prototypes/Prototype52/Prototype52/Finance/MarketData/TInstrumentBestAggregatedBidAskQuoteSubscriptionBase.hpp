#pragma once

#include "../TInstrumentDataSubscriptionBase.hpp"
#include "./TInstrumentBestAggregatedBidAskQuote.hpp"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Finance
{
namespace MarketData
{
   // There is no need to override the inherited {Prepare} method.

   template
      < typename TDerivedDataType_,
         typename TInstrument_
      >
   class TInstrumentBestAggregatedBidAskQuoteSubscriptionBase abstract :
      public TInstrumentDataSubscriptionBase< TDerivedDataType_, TInstrument_ >
   {
#if( /* {public InstrumentBestAggregatedBidAskQuote}. */ 1 )

      // yg? Consider renaming this to {Data}.
      public: TInstrumentBestAggregatedBidAskQuote InstrumentBestAggregatedBidAskQuote;

#endif

#if( /* {protected} Instance default constructor. */ 1 )

      //

      protected: explicit TInstrumentBestAggregatedBidAskQuoteSubscriptionBase();

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // This probably does not need to be {virtual}.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif

#if( /* //{public Unsubscribe>>>Async}. */ 1 )

      //>>>#pragma message( "yg---?? Consider moving this method to the base class." )
      //// yg? Rename this to {TrySendUnsubscriptionRequest} or {AsyncUnsubscribe}.
      //
      //public: void Unsubscribe>>>Async();

#endif
#if( /* //{public Unsubscribe>>>Async}. */ 1 )

      //// yg? Rename this to {TrySendUnsubscriptionRequest} or {AsyncUnsubscribe}.

      //public:
      //   template
      //      < typename TSubscriber_ <<<rename to {TSubscriber1}.
      //      >
      //   void Unsubscribe>>>Async
      //      ( TSubscriber_ & subscriber1,
      //        void ( TSubscriber_:: * method1 )( /*void const *,*/ /*::Poco::EventArgs &*/ TInstrumentBestAggregatedBidAskQuoteSubscriptionBase * & )
      //      );

#endif
   };
}
}
