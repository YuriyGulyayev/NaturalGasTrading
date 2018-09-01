#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TSecondaryPeerStrategy.hpp"

#include "./TPeerStrategyBase.cpp"
#include "./TSecondaryPeerStrategyConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TSecondaryPeerStrategy::TSecondaryPeerStrategy
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
      ) :
      TPeerStrategyBase( threadedActivityCancellationToken1 ),

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      OrdersPeerMessageReceiverThreadRunnableAdapter_( ( * this ), ( & TSecondaryPeerStrategy::OrdersPeerMessageReceiverThreadProc ) ),
      #pragma warning( pop )

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      PlannedAction1PeerMessageReceiverThreadRunnableAdapter_( ( * this ), ( & TSecondaryPeerStrategy::PlannedAction1PeerMessageReceiverThreadProc ) ),
      #pragma warning( pop )

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      PlannedAction2PeerMessageReceiverThreadRunnableAdapter_( ( * this ), ( & TSecondaryPeerStrategy::PlannedAction2PeerMessageReceiverThreadProc ) )
      #pragma warning( pop )
   {
      // See visible universe in {DoInitialize}.
   }

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TSecondaryPeerStrategy::TSecondaryPeerStrategy
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
        TSecondaryPeerStrategyConfiguration && configuration1
      ) :
      TPeerStrategyBase( threadedActivityCancellationToken1, ::std::move( configuration1 ) ),
      PositionConfiguration_( ::std::move( configuration1.PositionConfiguration ) ),

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      OrdersPeerMessageReceiverThreadRunnableAdapter_( ( * this ), ( & TSecondaryPeerStrategy::OrdersPeerMessageReceiverThreadProc ) ),
      #pragma warning( pop )

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      PlannedAction1PeerMessageReceiverThreadRunnableAdapter_( ( * this ), ( & TSecondaryPeerStrategy::PlannedAction1PeerMessageReceiverThreadProc ) ),
      #pragma warning( pop )

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      PlannedAction2PeerMessageReceiverThreadRunnableAdapter_( ( * this ), ( & TSecondaryPeerStrategy::PlannedAction2PeerMessageReceiverThreadProc ) )
      #pragma warning( pop )
   {
      // See visible universe in {DoInitialize}.

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

      // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

      // Placeholder.

#endif

#if( /* {public Initialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TSecondaryPeerStrategy::Initialize
      ( TSecondaryPeerStrategyConfiguration && configuration1
      )
   {
      // See visible universe in {DoInitialize}.

      TPeerStrategyBase::Initialize( ::std::move( configuration1 ) );

      PositionConfiguration_.Assign( ::std::move( configuration1.PositionConfiguration ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TSecondaryPeerStrategy::DoInitialize
      ( TSecondaryPeerStrategyConfiguration && //configuration1
      )
   {
//TODO update this
      // Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
      //    Instance constructors -- base.
      //       Hide, possibly implicitly. Call, possibly implicitly.
      //    Instance destructor -- base.
      //       Override, possibly implicitly. Call, possibly implicitly.
      //    {Initialize} -- base.
      //       Hide, call.
      //    {DoInitialize}.
      //       Call.
   }

#endif
#if( /* {public DoRun}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TSecondaryPeerStrategy::DoRun()
   {
      // Visible universe.
      //    {DoRun} -- base.
      //       Implement.
//TODO add more

      //TPeerStrategyBase::DoRun();

//TODO write code
   }

#endif

#if( /* {public PrepareDoRun}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TSecondaryPeerStrategy::PrepareDoRun()
   {
      // Visible universe.
//TODO add more

      WaitREngineAdapterReady();
      RequestSubscribeMarketData();
      WaitDateTimeKeeperReady();
      WaitMarketDataValid();
   }

#endif
#if( /* {private WaitREngineAdapterReady}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TSecondaryPeerStrategy::WaitREngineAdapterReady() const
   {
      for( ; ; )
      {
         // The loop breaking condition is likely {false} at the beginning, so we sleep first.
         REngineAdapter_->SleepMillisecond();

         if( ! REngineAdapter_->Ready() )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }
      }
   }

#endif
#if( /* {private RequestSubscribeMarketData}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TSecondaryPeerStrategy::RequestSubscribeMarketData()
   {
      InstrumentBestAggregatedBidAskQuoteSubscription_ =
         ( & REngineAdapter_->RequestSubscribeInstrumentBestAggregatedBidAskQuoteIfNeeded( REngineAdapter_->Instrument() ) );
      InstrumentTradeSubscription_ =
         ( & REngineAdapter_->RequestSubscribeInstrumentTradeIfNeeded( REngineAdapter_->Instrument() ) );
      //InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.Prepare( & InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote );

      // yg? We never unhook these.
      // yg? Market data can potentially arrive after the {Run} method returns, which we probably can handle.
      InstrumentBestAggregatedBidAskQuoteSubscription_->OnReceivedData += ::Poco::delegate( this, ( & TStrategy::HandleInstrumentBestAggregatedBidAskQuoteSubscriptionOnReceivedData ) );
      InstrumentTradeSubscription_->OnReceivedData += ::Poco::delegate( this, ( & TStrategy::HandleInstrumentTradeSubscriptionOnReceivedData ) );
   }

#endif
#if( /* {private WaitDateTimeKeeperReady}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TSecondaryPeerStrategy::WaitDateTimeKeeperReady() const
   {
      for( ; ; )
      {
         // The loop breaking condition is likely {false} at the beginning, so we sleep first.
         REngineAdapter_->SleepMillisecond();

         if( DateTimeKeeper_.UpdateCounter() <= 0 )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }

         //// The loop breaking condition can be {true} at the beginning, so we sleep afterwards.
         //REngineAdapter_->SleepMillisecond();
      }
   }

#endif
#if( /* {private WaitMarketDataValid}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TSecondaryPeerStrategy::WaitMarketDataValid() const
   {
//TODO don't wait for real time market data.
//TODO rename this to use the word "known" instead of "valid"
//TODO suppress market data being valid protection in test mode

      for( ; ; )
      {
//TODO can it be {true} at the beginngig?
         //// The loop breaking condition is likely {false} at the beginning, so we sleep first.
         //REngineAdapter_->SleepMillisecond();

         // Not checking {InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_} as it's unnecessary and also the logic that calculates it can produce an incorrect result when market data is not yet known.
         // Note that we are about to call {FixInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask}.
         // TODO 3 yg? Wait only for {TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllImportant} bits.
         if( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask != ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_All ||

             //// yg? There is no data validity bitmask for the trade.
             //// yg? It could be more correct to wait until the quantity is positive. But on the other hand we should support non-positive prices.
             //// yg? It could be more efficient to check if the date-time-stamp is still { <= 0.0 }.
             ////InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price <= ::std::numeric_limits< double >::lowest() ||
             //( ! ( InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price > ::std::numeric_limits< double >::lowest() ) ) ||

             ( ! InstrumentTradeSubscription_->InstrumentTrade.IsValid ) ||

             // It's pointless to continue if this is not ready.
             ( ! REngineAdapter_->Ready() )
           )

         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }

         // The loop breaking condition can be {true} at the beginning, so we sleep afterwards.
         REngineAdapter_->SleepMillisecond();
      }
   }

#endif

#if( /* {private OrdersPeerMessageReceiverThreadProc}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TSecondaryPeerStrategy::OrdersPeerMessageReceiverThreadProc()
   {
//TODO
   }

#endif

#if( /* {private PlannedAction1PeerMessageReceiverThreadProc}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TSecondaryPeerStrategy::PlannedAction1PeerMessageReceiverThreadProc()
   {
//TODO
   }

#endif

#if( /* {private PlannedAction2PeerMessageReceiverThreadProc}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TSecondaryPeerStrategy::PlannedAction2PeerMessageReceiverThreadProc()
   {
//TODO
   }

#endif
}
