#pragma once

#include "./TNumberEventsCheapMovingAverageCalculator.hpp"
#include "./TPeerStrategyBase.hpp"
#include "./TPrimaryPeerStrategyConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // yg? We probably can send some exit orders before their counterpart entry orders complete, which requires more margin.

   // Visible universe.
   //    {TPeerStrategyBase}.
   //       Subclass.
   //    {TPrimaryPeerStrategyConfiguration}.
   //    {REngineAdapter_}.
   //       Call its methods.
   //    Instance constructors -- base.
   //       Hide, possibly implicitly. Call, possibly implicitly.
   //    Instance destructor -- base.
   //       Override, possibly implicitly. Call, possibly implicitly.
   //    {Initialize} -- base.
   //       Hide, call.
   //    //{Prepare} -- base.
   //    //   Override, call.
   //    //{Start} -- base.
   //    //   Override, call.
   //    //{Run} -- base.
   //    //   Implement.
   //    {DoRun} -- base.
   //       Implement.

// TODO Compare visible universe with the one in "26_Strategy_Notes.doc". Maybe remove it there.

   class TPrimaryPeerStrategy :
      public TPeerStrategyBase
   {

//TODO // This is a placeholder for some data structure that allows to register filled and unfilled quantity and decide if we need to send an exit order.
//TODO // I can maintain {OpenPositionSignedQuantity} (or {FilledSignedQuantity}) and {UnfilledSignedQuantity}. Update those on each order state update.
//TODO When {OpenPositionQuantity != -UnfilledQuantity} (and/or {abs(OpenPositionQuantity) >= abs(UnfilledQuantity)}?) we can send an exit order.
//TODO // I need to remember previous filled quantity of each order in a separate context object.
//TODO // Primary peer only.
//TODO FilledQuantityRegistry_


#if( /* {private Timer1TickIntervalMilliseconds_}. */ 1 )

      //
      private: int Timer1TickIntervalMilliseconds_;

#endif
#if( /* {private DataLoggingIntervalTimer1Ticks_}. */ 1 )

      //
      private: int DataLoggingIntervalTimer1Ticks_;

#endif
#if( /* {private NumberDataLastLoggingsOnTimer1TickToForce_}. */ 1 )

      //
      private: int NumberDataLastLoggingsOnTimer1TickToForce_;

#endif
#if( /* {private EntryOrdersModificationWarmUpTimeOffsetTimer1Ticks_}. */ 1 )

      // Forced to be { < 0 }.
//TODO now warming up only once.
//TODO swap "Modification" and "WarmUp". actually don't
      private: int EntryOrdersModificationWarmUpTimeOffsetTimer1Ticks_;

#endif
#if( /* {private EconomicReportReceptionTimeoutTimeSpanMilliseconds_}. */ 1 )

      // yg? Consider moving this parameter to a separate protection configuration class shared by all positions.
      private: int EconomicReportReceptionTimeoutTimeSpanMilliseconds_;

#endif
#if( /* {private InstrumentDeepOutOfMoneyPriceFactor1_}. */ 1 )

      // TODO 3 yg? Consider moving this parameter to a separate class and configuring it separately for each instrument.
      private: double InstrumentDeepOutOfMoneyPriceFactor1_;

#endif
#if( /* {private PositionConfiguration_}. */ 1 )

      // Storing the configuration object as is.
      private: TPrimaryPeerStrategyPositionConfiguration PositionConfiguration_;

#endif

#if( /* {private InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_}. */ 1 )

      // See also: {FixInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask}.
//TODO Maybe append {2} to this field name or before the word {BitMask} to distinguish this data validity bitmask from the one in the subscription object. And explain in a comment.
//TODO Append {2} to the method too.
//TODO don't bother fixing this, just init with 0.
//TODO Write a comment here that the logic isn't perfect and refer to more comments in the method that updates this.
//TODO suppress this protection in test mode.
      private: ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_;

#endif
#if( /* {private NumberInstrumentTradesCheapMovingAverageCalculator_}. */ 1 )

      //
      private: TNumberEventsCheapMovingAverageCalculator NumberInstrumentTradesCheapMovingAverageCalculator_;

#endif

#if( /* {private OrdersPeerMessageSender_}. */ 1 )

      //
      private: TPeerMessageSender OrdersPeerMessageSender_;

#endif
#if( /* {private PlannedAction1PeerMessageSender_}. */ 1 )

      //
      private: TPeerMessageSender PlannedAction1PeerMessageSender_;

#endif
#if( /* {private PlannedAction2PeerMessageSender_}. */ 1 )

      //
      private: TPeerMessageSender PlannedAction2PeerMessageSender_;

#endif

#if( /* {private PooledOrder_}. */ 1 )

      // yg? This is used as an exit order only and some fields are pre-populated for that purpose, so maybe this should be renamed to
      // yg? {ExitPooledOrder_}.
      // TODO 3 yg? Pre-create multiple pooled orders.
//TODO actually we need an order pool in broker adapter but we need this too to pre-populate it.
      private: ::RApiFacade::TSingleInstrumentOrder * PooledOrder_;

#endif
#if( /* {private NumberPendingOrdersWarmUpModificationRequest_}. */ 1 )

      //
//TODO init this with 0
//TODO Set this to the number of all orders (entry and quick exit) when sending warm-up modification requests.
//TODO When a warm-up modification request completes unhook it and decrement this counter.
//TODO Otherwise it would not be guaranteed that we won't decrement this more than once.
//TODO Am I happy with the name?
      private: int NumberPendingOrdersWarmUpModificationRequest_;

#endif

#if( /* {private NumberTimer1TicksUntilEntryOrdersModification_}. */ 1 )

      // Counts down to 0.
//TODO I eliminated TimeSpanMillisecondsUntilEntryOrdersModification_
      private: int NumberTimer1TicksUntilEntryOrdersModification_;

#endif

#if( /* //{(private)} Instance default constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TPrimaryPeerStrategy
         ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TPrimaryPeerStrategy
         ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
           TPrimaryPeerStrategyConfiguration && configuration1
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // {virtual}.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif

#if( /* {public Initialize}. */ 1 )

      //

      public: void Initialize
         ( TPrimaryPeerStrategyConfiguration && configuration1
         );

#endif
#if( /* {private DoInitialize}. */ 1 )

      //

      private: void DoInitialize
         ( TPrimaryPeerStrategyConfiguration && configuration1
         );

#endif
#if( /* {public Prepare}. */ 1 )

      //

      public: virtual void Prepare
         ( TTradingSystem & tradingSystem1
         ) override;

#endif
#if( /* {public DoRun}. */ 1 )

      //

      public: virtual void DoRun() override;

#endif
   };
}
