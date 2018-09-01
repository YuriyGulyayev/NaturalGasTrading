#pragma once

// TODO 1 yg? Remove this file.

#if 0

namespace Prototype52
{
   class TStrategy :
      private ::Poco::Runnable
   {
#pragma region Return to this.
#if( /* {private NumberUnmodifiedTowardsMoneyEntryOrders_}. */ 1 )

      // The number of entry order pairs which we didn't request to modify towards the money.
      // Equals {::std::numeric_limits< int >::max()} if no requests to modify entry orders towards the money were sent yet.
      // Warm-up modifications that only move trigger price by 2 increments don't count.
      // yg? Consider renaming this to {NumberUnmodifiedTowardsMoneyEntryOrdersPair_}.
      // yg? Consider using the word "number entry order pairs not requested to modify towards money" or something like that.
      private: int NumberUnmodifiedTowardsMoneyEntryOrders_;

#endif
#if( /* {private EntryLastFilledOrderDirectionCode_}. */ 1 )

      //
//TODO this should be a broader spike evidense code: int InstrumentPriceSpikePossibleDirectionCode_
      private: ::Finance::Trading::TPositionDirectionCode EntryLastFilledOrderDirectionCode_;

#endif
#if( /* {private SignedNumberEntryFilledOrders_}. */ 1 )

      // This is decremented/incremented away from 0 when an entry order gets filled
      // and incremented/decremented towards 0 when an exit order is sent.
      // In other words this is current open position quantity, positive or negative,
      // expressed in the number of instrument quantity increments.
      // yg? So maybe this should be renamed.
      private: int SignedNumberEntryFilledOrders_;

#endif
#if( /* {private ExitOrderSent_}. */ 1 )

      // {true} if at least 1 exit order was sent, speculative or not.
      private: bool ExitOrderSent_;

#endif
#pragma endregion


#if( /* {private Run3}. */ 1 )

      // Entry point of the {Thread3_} thread.

      private: void Run3();

#endif

   // {::Poco::Runnable} implementation.
#if( /* {private run}. */ 1 )

      // Entry point of the {Thread2_} thread.

      private: virtual void run() override;

#endif

#if( /* {private DoRun1}. */ 1 )

      //

      private: void DoRun1();

#endif
#if( /* {private FixInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask}. */ 1 )

      //

      private: void FixInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask();

#endif
#if( /* {private CreatePooledOrder}. */ 1 )

      //

      private: void CreatePooledOrder();

#endif
#if( /* {private CreateAndSendEntryDeepOutOfMoneyOrders}. */ 1 )

      //

      private: void CreateAndSendEntryDeepOutOfMoneyOrders();

#endif
#if( /* {private WaitEntryDeepOutOfMoneyOrdersAccepted}. */ 1 )

      //

      private: void WaitEntryDeepOutOfMoneyOrdersAccepted() const;

#endif
#if( /* {private PrepareActivitiesSchedule}. */ 1 )

      //

      private: void PrepareActivitiesSchedule();

#endif
#if( /* {private UpdateActivitiesSchedule}. */ 1 )

      //

      private: void UpdateActivitiesSchedule();

#endif
#if( /* {private StartThread2}. */ 1 )

      //

      private: void StartThread2();

#endif
#if( /* {private PrepareReceiveEconomicReport}. */ 1 )

      //

      private: void PrepareReceiveEconomicReport();

#endif
#if( /* {private TryMakeEconomicReportReceiverWarmUpStep}. */ 1 )

      //

      private: bool TryMakeEconomicReportReceiverWarmUpStep();

#endif
#if( /* {private StartThread3}. */ 1 )

      //

      private: void StartThread3();

#endif
#if( /* {private TryReceiveEconomicReport}. */ 1 )

      //

      private: void TryReceiveEconomicReport();

#endif
#if( /* {private OnTriedReceiveEconomicReport}. */ 1 )

      //

//TODO Rename this as this now looks like an event.
      private: void OnTriedReceiveEconomicReport();

#endif
#if( /* {private UpdatePositionExpectedDirectionCodeIfPossible}. */ 1 )

      //

      private: void UpdatePositionExpectedDirectionCodeIfPossible();

#endif
#if( /* {private TrySendPeerMessage}. */ 1 )

      //

      private: void TrySendPeerMessage
         ( bool isWarmUpOrTestMode1,
           //bool toImportantPeersOnly
           TPeerTypesBitMask peerTypesBitMask
         );

#endif
#if( /* {private TrySendEconomicReportToNewsHubIfPossible}. */ 1 )

      //

      private: void TrySendEconomicReportToNewsHubIfPossible();

#endif
#if( /* {private SleepUntilTerminationTime}. */ 1 )

      //

      private: void SleepUntilTerminationTime() const;

#endif
#if( /* {private LogEconomicReportReceptionActivityReportIfPossible}. */ 1 )

      //

      private: void LogEconomicReportReceptionActivityReportIfPossible();

#endif
#if( /* {private TryVerifyCompleted}. */ 1 )

      // yg? I feel the word "validate" should not be used here.
      // yg? Consider not using the word "try".
      // yg? Consider using the word "verify and possibly log" but that would be lame.
      // yg? Another option would be to name this method {logStrategyActivityReport} and log a different message
      // yg? if the strategy actually completed or use the word "if needed" and log nothing if the strategy actually completed.

      private: void TryVerifyCompleted() const;

#endif

#if( /* {private DoRun2}. */ 1 )

      //

      private: void DoRun2();

#endif
#if( /* {private RunTimer1}. */ 1 )

      //

      private: void RunTimer1();

#endif
#if( /* {private UpdateCheapMovingAverageCalculators}. */ 1 )

      //

      private: void UpdateCheapMovingAverageCalculators
         ( int currentTimeMilliseconds
         );

#endif
#if( /* {private WarmUpRequestModifyEntryOrdersTowardsMoney}. */ 1 )

      //

      private: void WarmUpRequestModifyEntryOrdersTowardsMoney();

#endif
#if( /* {private TradeOnThread2IfPossible}. */ 1 )

      // TODO 2 yg? If I refactor threads this will probably not be "thread 2" any more. Also review any "thread".

      private: void TradeOnThread2IfPossible();

#endif
#if( /* {private MayModifyEntryOrdersTowardsMoney}. */ 1 )

      //

      private: bool MayModifyEntryOrdersTowardsMoney() const;

#endif
#if( /* {private SafeRequestModifyEntryOrdersTowardsMoney}. */ 1 )

      // The "safe" means that this method on each loop checks {ShallAbortModifyEntryOrdersTowardsMoney_}.
      // yg? Perhaps it should be renamed to specify what exactly is safe.

      private: void SafeRequestModifyEntryOrdersTowardsMoney();

#endif
#if( /* {private SleepUntilEconomicReportReceptionTimeoutExpires}. */ 1 )

      //

      private: void SleepUntilEconomicReportReceptionTimeoutExpires() const;

#endif

#if( /* {private DoRun3}. */ 1 )

      //

      private: void DoRun3();

#endif
#if( /* {private TryReceivePeerMessage}. */ 1 )

      //

      private: void TryReceivePeerMessage();

#endif
#if( /* {private OnReceivedPeerMessage}. */ 1 )

      //

//TODO Rename this as this now looks like an event.
      private: void OnReceivedPeerMessage();

#endif

#if( /* {(public) HandleInstrumentBestAggregatedBidAskQuoteSubscriptionOnReceivedData}. */ 1 )

      //

      private: void HandleInstrumentBestAggregatedBidAskQuoteSubscriptionOnReceivedData
         ( ::RApiFacade::TInstrumentBestAggregatedBidAskQuoteSubscription * & instrumentBestAggregatedBidAskQuoteSubscription1
         );

#endif
#if( /* {private OnInstrumentBestAggregatedBidAskQuoteSubscriptionReceivedData}. */ 1 )

      //

//TODO this metho needs to be eliminated or renamed to eliminate the "On" at the beginning
      private: void OnInstrumentBestAggregatedBidAskQuoteSubscriptionReceivedData();

#endif
#if( /* {(public) HandleInstrumentTradeSubscriptionOnReceivedData}. */ 1 )

      //

      private: void HandleInstrumentTradeSubscriptionOnReceivedData
         ( ::RApiFacade::TInstrumentTradeSubscription * & instrumentTradeSubscription1
         );

#endif
#if( /* {private OnInstrumentTradeSubscriptionReceivedData}. */ 1 )

      //

//TODO this metho needs to be eliminated or renamed to eliminate the "On" at the beginning
      private: void OnInstrumentTradeSubscriptionReceivedData();

#endif
#if( /* {private UpdateInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask}. */ 1 )

      //

      private: void UpdateInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask();

#endif
#if( /* {private RequestCancelEntryOrdersPrematurelyIfNeeded}. */ 1 )

      // yg? Should we use the word "based on market data" in this method name?
      // yg? If I rename it I would probably need to rephrase the message it logs and search for any other "premature".

      private: void RequestCancelEntryOrdersPrematurelyIfNeeded();

#endif
#if( /* {private LogDateTimeKeeper}. */ 1 )

      //

      private: void LogDateTimeKeeper() const;

#endif

#if( /* {(public) HandleEntryOrderOnReceivedData}. */ 1 )

      //

      private: void HandleEntryOrderOnReceivedData
         ( ::RApiFacade::TSingleInstrumentOrder * & entryOrder1
         );

#endif
#if( /* //{(public) HandleExitOrderOnReceivedData}. */ 1 )

      ////
      //
      //private: void HandleExitOrderOnReceivedData
      //   ( ::RApiFacade::TSingleInstrumentOrder * & exitOrder1
      //   );

#endif
#if( /* {private CreateAndSendExitOrderIfNeeded}. */ 1 )

      // Returns {true} if a speculative exit order was sent.
      // yg? Consider renaming this to use the word "if possible".

      private: bool CreateAndSendExitOrderIfNeeded();

#endif
#if( /* {private CreatePooledOrderIfNeeded}. */ 1 )

      //

      private: void CreatePooledOrderIfNeeded();

#endif
   };
}

#endif
