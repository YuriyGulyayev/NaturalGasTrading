#pragma once

#include "../Common/ControlFlow/TThreadedActivityCancellationToken.hpp"
#include "./TAccountInfoContainer.hpp"
//#include "./TInstrument.hpp"
#include "./TInstrumentBestAggregatedBidAskQuoteSubscription.hpp"
#include "./TInstrumentTradeSubscription.hpp"
//#include "./TSingleInstrumentOrder.hpp"
#include "./TREngineAdapterConfiguration.hpp"
#include "./TRApiHelpers.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   // This class is thread unsafe. The caller shall call most methods from within a block protected by the {LockREngine} and
   // {UnlockREngine} methods, even if the object is always accessed on a single thread.
   // yg? Parts of the interface and functionality belong to a base class.

   // Visible universe.
   //    Some R|API classes and constants.
   //    {::Common::ControlFlow::TThreadedActivityCancellationToken}.
   //    {::Common::ErrorHandling::TErrorHandlingHelpers}.
   //    {::Common::Math::TMathHelpers}.
   //    {TRApiHelpers}.
   //    {TAccountInfoContainer}.
   //    {TInstrument}.
   //    {TInstrumentBestAggregatedBidAskQuoteSubscription}.
   //    {TInstrumentTradeSubscription}.
   //    {TSingleInstrumentOrder}.
   //    {TSingleInstrumentOrderHelpers}.
   //    {TLogInParamsConfiguration}.
   //    {TREngineAdapterConfiguration}.
   //    {TREngineParamsConfiguration}.

   class TREngineAdapter :
      // It's probably more efficient to list {::RApi::RCallbacks} first (and before {::RApi::AdmCallbacks}) in the base classes list.
      private ::RApi::RCallbacks,

      private ::RApi::AdmCallbacks
   {
#if( /* {private TReadinessStateBitMask_}. */ 1 )

      // These flags indicate the degree to which we are ready.
      // yg? In .NET we also have the {NotDisposed} flag.
      // See also: {static_assert}s below.

      private: enum TReadinessStateBitMask_ : unsigned int
      {
         //
         TReadinessStateBitMask_None_ = 0U,

         // It's possible that this bit will be cleared when an alert with no connection point arrives. Do not use it.
         TReadinessStateBitMask_Dummy1_ = 1U << static_cast< unsigned int >( TRApiHelpers::ConnectPointIdNone ),

         // Not used.
         //TReadinessStateBitMask_IhCnnctPtLoggedInTo_ = 1U << static_cast< unsigned int >( ::RApi::INTRADAY_HISTORY_CONNECTION_ID ),

         //
         TReadinessStateBitMask_MdCnnctPtLoggedInTo_ = 1U << static_cast< unsigned int >( ::RApi::MARKET_DATA_CONNECTION_ID ),

         // Not used.
         //TReadinessStateBitMask_PnlCnnctPtLoggedInTo_ = 1U << static_cast< unsigned int >( ::RApi::PNL_CONNECTION_ID ),

         //
         TReadinessStateBitMask_TsCnnctPtLoggedInTo_ = 1U << static_cast< unsigned int >( ::RApi::TRADING_SYSTEM_CONNECTION_ID ),

         //
         TReadinessStateBitMask_REngineCreated_ = 1U << 16U,

         //
         TReadinessStateBitMask_ShallLogIn_ = 1U << 18U,

         //
         TReadinessStateBitMask_AccountInfoReceived_ = 1U << 20U,

         // yg? We might also need a flag for whether trading session for this instrument is open.
         // yg? This would have to be redesigned to support multiple and/or dynamically added instruments.
         TReadinessStateBitMask_InstrumentPriceIncrementMinLimitReceived_ = 1U << 22U,

         //
         TReadinessStateBitMask_AllConnectPointsLoggedInTo_ =
            // Not used. TReadinessStateBitMask_IhCnnctPtLoggedInTo_ |
            TReadinessStateBitMask_MdCnnctPtLoggedInTo_ |
            // Not used. TReadinessStateBitMask_PnlCnnctPtLoggedInTo_ |
            TReadinessStateBitMask_TsCnnctPtLoggedInTo_,

         //
         TReadinessStateBitMask_All_ =
            TReadinessStateBitMask_AllConnectPointsLoggedInTo_ |
            TReadinessStateBitMask_REngineCreated_ |
            TReadinessStateBitMask_ShallLogIn_ |
            TReadinessStateBitMask_AccountInfoReceived_ |
            TReadinessStateBitMask_InstrumentPriceIncrementMinLimitReceived_,
      };

      static_assert( TRApiHelpers::ConnectPointIdNone == 0, "" );
      // Not used. static_assert( ( TReadinessStateBitMask_IhCnnctPtLoggedInTo_ >= static_cast< TReadinessStateBitMask_ >( 1U << 1U ) &&
      //                          TReadinessStateBitMask_IhCnnctPtLoggedInTo_ <= static_cast< TReadinessStateBitMask_ >( 1U << 15U )
      //                       ),
      //                       ""
      //                     );
      static_assert( ( TReadinessStateBitMask_MdCnnctPtLoggedInTo_ >= static_cast< TReadinessStateBitMask_ >( 1U << 1U ) &&
                               TReadinessStateBitMask_MdCnnctPtLoggedInTo_ <= static_cast< TReadinessStateBitMask_ >( 1U << 15U )
                            ),
                            ""
                          );
      // Not used. static_assert( ( TReadinessStateBitMask_PnlCnnctPtLoggedInTo_ >= static_cast< TReadinessStateBitMask_ >( 1U << 1U ) &&
      //                          TReadinessStateBitMask_PnlCnnctPtLoggedInTo_ <= static_cast< TReadinessStateBitMask_ >( 1U << 15U )
      //                       ),
      //                       ""
      //                     );
      static_assert( ( TReadinessStateBitMask_TsCnnctPtLoggedInTo_ >= static_cast< TReadinessStateBitMask_ >( 1U << 1U ) &&
                               TReadinessStateBitMask_TsCnnctPtLoggedInTo_ <= static_cast< TReadinessStateBitMask_ >( 1U << 15U )
                            ),
                            ""
                          );

#endif

#if( /* {private ThreadedActivityCancellationToken_}. */ 1 )

      //
      private: ::Common::ControlFlow::TThreadedActivityCancellationToken * const ThreadedActivityCancellationToken_;

#endif
#if( /* {private ReadinessStateBitMask_}. */ 1 )

      //
      private: TReadinessStateBitMask_ ReadinessStateBitMask_;

#endif
#if( /* {private REngineParamsConfiguration_}. */ 1 )

      // Storing the configuration object as is.
      private: TREngineParamsConfiguration REngineParamsConfiguration_;

#endif
#if( /* {private LogInParamsConfiguration_}. */ 1 )

      // Storing the configuration object as is.
      private: TLogInParamsConfiguration LogInParamsConfiguration_;

#endif
#if( /* {private AccountInfoContainer_}. */ 1 )

      // yg? We support only 1 trading account per user account.
      private: TAccountInfoContainer AccountInfoContainer_;

#endif
#if( /* {private Instrument_}. */ 1 )

      // yg? We support only 1 instrument and its market data subscriptions.
      private: TInstrument Instrument_;

#endif
#if( /* {private InstrumentBestAggregatedBidAskQuoteSubscription_}. */ 1 )

      //
      private: TInstrumentBestAggregatedBidAskQuoteSubscription InstrumentBestAggregatedBidAskQuoteSubscription_;

#endif
#if( /* //{private InstrumentBestAggregatedBidAskQuoteSubscriptionActive_}. */ 1 )

      ////
      //private: bool InstrumentBestAggregatedBidAskQuoteSubscriptionActive_;

#endif
#if( /* {private InstrumentTradeSubscription_}. */ 1 )

      //
      private: TInstrumentTradeSubscription InstrumentTradeSubscription_;

#endif
#if( /* //{private InstrumentTradeSubscriptionActive_}. */ 1 )

      ////
      //private: bool InstrumentTradeSubscriptionActive_;

#endif
#if( /* //{private InstrumentMarketDataSubscriptionsActive_}. */ 1 )

      // yg? This solution serves only our immediate needs.
      // yg? Actually this solution is crap!
      // yg? It's actually possible to use this flag to re-subscribe upon a reconnection.
      // yg? We shouldn't cancel any subscriptions even if the caller logs out.
      // TODO 3 yg? This should be done.
      //private: bool InstrumentMarketDataSubscriptionsActive_;

#endif
#if( /* {private ShallSubscribeOrdersStateUpdate_}. */ 1 )

      // We probably don't need to subscribe for order state updates if we are not going to trade, which is what this parameter is for.
      // Another option would be to subscribe only when the caller creates an order,
      // or if it's impossible at that moment then when it becomes possible. But the caller should be free to create a pooled order
      // even if it's not going to trade.
      // Another option would be to subscribe only when the caller sends an order but it would introduce an overhead.
      // Another option would be
      // to require the caller to explicitly call {RequestSubscribeOrdersStateUpdateIfNeeded} after log-in completes.
      private: bool ShallSubscribeOrdersStateUpdate_;

#endif
#if( /* {private SingleInstrumentsOrders_}. */ 1 )

      // yg? We never remove items from here.
      // yg? See a comment in {AsyncEnsureLoggedOut} body regarding order removal.
      // TODO 3 yg? This map should be keyed on an internally generated integer order ID.
      // TODO 3 yg? We need separate collections: newly created and possibly sent but not yet known to broker orders
      // TODO 3 yg? (maybe split it into 2 collections but avoid moving an item from one to another when sending an order);
      // TODO 3 yg? still working orders; no longer working but potentially still restateabale orders.
      // TODO 2 yg? This map should contain order object references. Can we use {::std::reference_wrapper}?
      // TODO 2 yg? Note that this map is passed to some methods as is. Search for:
      // TODO 2 yg? \:\:std\:\:map\< void const \*\, \:\:std\:\:unique_ptr\< TSingleInstrumentOrder \> \>~((\:\:(const_)*iterator)|\:\:value_type)
//TODO 2 maps: keysed on 2 generated chars; keyed on order number
//TODO add order pool
      private: ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > > SingleInstrumentsOrders_;

#endif
#if( /* //{private REngine_}. yg? Must be the last. */ 1 )

      //// yg? This field must be the last as its destructor can potentially call callbacks.
      //// yg? This also implies that we must ensure that its constructor is called before an exception can be thrown. (What??? Bullshit?)
      //// yg? A more reliable solution would be to have callbacks to check if we are not being destructed,
      //// yg? possibly by checking {* ThreadedActivityCancellationToken_}.
      //private: ::std::unique_ptr< ::RApi::REngine > REngine_;

#endif
#if( /* {private REnginePlace_}. */ 1 )

      // Unlike the commented out {REngine_} field above, this one doesn't have to be the last
      // yg? but the same considerations still apply.
      // It's important to ensure that the compiler will not accidentially autogenerate code to copy this array.
      private: char REnginePlace_[ sizeof( ::RApi::REngine ) ];

#endif

#if( /* //{(private)} Instance default constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TREngineAdapter
         ( TREngineAdapter const & source
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TREngineAdapter
         ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TREngineAdapter
         ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
           TREngineAdapterConfiguration && configuration1
         );

#endif
#if( /* {public} Instance destructor. */ 1 )

      // This is actually an {override} but the compiler won't let us to use that keyword.

      public: virtual ~TREngineAdapter();

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TREngineAdapter & operator =
         ( TREngineAdapter const & source
         );

#endif

#if( /* {public Initialize}. */ 1 )

      // When calling this method do not attempt to lock the not yet existing {REngine()}.

      public: void Initialize
         ( TREngineAdapterConfiguration && configuration1
         );

#endif
#if( /* {private DoInitialize}. */ 1 )

      //

      private: void DoInitialize
         ( TREngineAdapterConfiguration && configuration1
         );

#endif
#if( /* {public Prepare}. */ 1 )

      // The {Start} method comment applies here as well.

      public: void Prepare();

#endif
#if( /* {public Start}. */ 1 )

      // This method is thread unsafe and it shall return before any other one may be called.
      // It's undocumented whether {REngine()} is created before this method is called,
      // therefore do not attempt to lock the probably not yet existing {REngine()}.
      // This applies to {Prepare} as well.

      public: void Start();

#endif

#if( /* {public AccountInfo}. */ 1 )

      //

      public: ::RApi::AccountInfo const & AccountInfo() const;

#endif
#if( /* {public Instrument}. */ 1 )

      //

      public: TInstrument const & Instrument() const;

#endif
#if( /* {public REngine}. */ 1 )

      //

      public: ::RApi::REngine & REngine(); //const;

#endif

#if( /* {public LockREngine}. */ 1 )

      // Se also: {TRApiHelpers::LockREngine}.

      public: void LockREngine();

#endif
#if( /* {public UnlockREngine}. */ 1 )

      // Se also: {TRApiHelpers::UnlockREngine}.

      public: void UnlockREngine();

#endif

#if( /* {public SleepMillisecond}. */ 1 )

      // This and the other counterpart methods unlocks {REngine()}, sleeps, locks {REngine()},
      // calls {ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled}.
      // yg? These details are not reflected in its name.

      public: void SleepMillisecond();

#endif
#if( /* {public SleepMilliseconds}. */ 1 )

      // TODO 2 yg? Remember to call {DoSleepMilliseconds} instead of {SleepMilliseconds} when appropriate.

      public: void SleepMilliseconds
         ( int timeSpanMilliseconds
         );

#endif
#if( /* {public DoSleepMilliseconds}. */ 1 )

      // TODO 2 yg? See {SleepMilliseconds} comment.

      public: void DoSleepMilliseconds
         ( int timeSpanMilliseconds
         );

#endif
#if( /* {public SleepUntilMultimediaTimeMilliseconds}. */ 1 )

      //

      public: void SleepUntilMultimediaTimeMilliseconds
         ( int endTimeMilliseconds
         );

#endif
#if( /* {public SleepUntilMultimediaUpdatingTimeMilliseconds}. */ 1 )

      //

//TODO implement
//TODO this needs to call a lower level same named sleep method in threading helpers
//TODO actually no lower level as we need to lock.
//TODO It would actually be safe to not lock but if the variable was 64-bit it would be thread unsafe to read it. Write comments.
      public: void SleepUntilMultimediaUpdatingTimeMilliseconds
         ( int const & endTimeMilliseconds
         );

      //for( ; ; )
      //{
      //   // We could skip this system call if we just made one above but this is not performance critical.
      //   int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
      //
      //   // Non-volatile read. Assuming we are surrounded by memory barriers.
      //   int timeSpanMillisecondsUntilPeerDataReceiverInvocation( PeerDataReceiverInvocationTimeMilliseconds_ - currentTimeMilliseconds );
      //
      //   //::std::cout << timeSpanMillisecondsUntilPeerDataReceiverInvocation << ::std::endl;
      //   if( timeSpanMillisecondsUntilPeerDataReceiverInvocation > 0 )
      //   {
      //      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      //   }
      //   else
      //   {
      //      break;
      //   }
      //
      //   // The loop breaking condition can (potentially) be {true} at the beginning, so we sleep afterwards.
      //   // This can't overflow.
      //   REngineAdapter_->DoSleepMilliseconds( static_cast< int >( ( static_cast< unsigned int >( timeSpanMillisecondsUntilPeerDataReceiverInvocation ) + 1U ) / 2U ) );
      //}

#endif

#if( /* {public AsyncEnsureLoggedIn}. */ 1 )

      // TODO 3 yg? If the operation fails we should retry indefinitely. And maybe use the word "persistent" or "repeatedly".
      // yg? But {::RApi::REngine::login} also makes multiple attempts and restores a broken connection
      // yg? but that logic is not necessarily good or indefinite.
      // yg? See also: {TRApiHelpers::AsyncEnsureREngineLoggedIn}.

      public: void AsyncEnsureLoggedIn();

#endif
#if( /* {public AsyncEnsureLoggedOut}. */ 1 )

      // yg? See also: {TRApiHelpers::AsyncEnsureREngineLoggedOut}.

      public: void AsyncEnsureLoggedOut();

#endif
#if( /* {private AddReadinessStateBit}. */ 1 )

      // This method is called only when a log-in to a connect point completes
      // and is probably not suitable to be called under any other conditions.
      // yg? This method also can send a request, which is not reflected in its name.

      private: void AddReadinessStateBit
         ( TReadinessStateBitMask_ readinessStateBit
         );

#endif
#if( /* {public Ready}. */ 1 )

      // Most methods may be called only when this one would return {true}.
      // This method makes a non-volatile read of a member field and therefore, as most other methods,
      // must be called from within a locked scope to ensure that all internal changes are visible to the calling thread.
      // However in most cases it's OK to call it amid memory barriers without locking.
      // yg? It should be configurable to what connect points we are to be logged in to consider that we are completely logged in.
      // yg? Or we can derive this required connect point bitmask from what connect points have been configured.
      // yg? For efficiency, we might need a separate {bool Ready_} field.
      // yg? Consider renaming this to {IsReady}.

      public: bool Ready() const;

#endif

#if( /* {private RequestInstrumentPriceIncrementMinLimit}. */ 1 )

      // yg? This method is currently {private} and {static}.
      // yg? See {PriceIncrUpdate} comment.
      // yg? See also: {TRApiHelpers::RequestInstrumentPriceIncrementMinLimit}.

      private: static void RequestInstrumentPriceIncrementMinLimit
         ( TInstrument const & instrument1
         );

#endif

#if( /* {private RequestSubscribeInstrumentMarketDataIfNeeded}. */ 1 )

      // yg? This solution serves only our immediate needs.
      // yg? See also: {TRApiHelpers::RequestSubscribeInstrumentMarketDataIfNeeded}.

      private: void RequestSubscribeInstrumentMarketDataIfNeeded();

#endif
#if( /* {public HackRequestUnsubscribeInstrumentMarketDataIfNeeded}. */ 1 )

      // yg? Proper subscription cancellation is currently not implemented.
      // TODO 3 yg? Revisit this.
      // TODO 3 yg? We need separate unsubscription methods for each subscription class.
      // TODO 3 yg? This should invalidate previously received market data or the subscription object pointer.
      // yg? See also: {TRApiHelpers::RequestUnsubscribeInstrumentMarketDataIfNeeded}.

      public: void HackRequestUnsubscribeInstrumentMarketDataIfNeeded
         ( //TInstrument const & instrument1
         );

#endif
#if( /* {public RequestSubscribeInstrumentBestAggregatedBidAskQuoteIfNeeded}. */ 1 )

      // As in most other cases, the caller shall call {LockREngine} before calling this method,
      // which in turn ensures that no market data events can be raised before the caller hooks up its event callback.
      // yg? Assuming that {REngine()} won't raise those events on any thread while locked.
      // yg? Do we need to make it possible for the caller to obtain a market data subscription object pointer
      // yg? without sending a subscription request? Note that this is already possible for order state update subscriptions.

      public: TInstrumentBestAggregatedBidAskQuoteSubscription /*yg? const*/ &
         RequestSubscribeInstrumentBestAggregatedBidAskQuoteIfNeeded
            ( TInstrument const & instrument1
            );

#endif
#if( /* //{public AsyncUnsubscribe}. */ 1 )

      //// After this the pointer will (can?) become invalid.
      //// The caller shall unhook event callbacks before calling this method.
      //// yg? Is it really necessary? Wouldn't the data subscription object unhook event callbacks.
      //// yg? Possibly but only if this event listener is the last and only if the data subscription object is actually destroyed.
      //// yg? Should this be renamed to {RequestUnsubscribeIfNeeded}?
      //
      //public: void AsyncUnsubscribe
      //   ( TInstrumentBestAggregatedBidAskQuoteSubscription & instrumentBestAggregatedBidAskQuoteSubscription1
      //   );

#endif
#if( /* {public RequestSubscribeInstrumentTradeIfNeeded}. */ 1 )

      // Similar to {RequestSubscribeInstrumentBestAggregatedBidAskQuoteIfNeeded}.

      public: TInstrumentTradeSubscription /*yg? const*/ & RequestSubscribeInstrumentTradeIfNeeded
         ( TInstrument const & instrument1
         );

#endif
#if( /* //{public AsyncUnsubscribe}. */ 1 )

      //// Similar to the other overload.
      //
      //public: void AsyncUnsubscribe
      //   ( TInstrumentTradeSubscription & instrumentTradeSubscription1
      //   );

#endif
#if( /* //{private ProcessTradeInfo}. */ 1 )

      ////
      //
      //private: void ProcessTradeInfo
      //   ( ::RApi::TradeInfo const & tradeInfo1,
      //     bool tradeInfo1IsConditional
      //   );

#endif
#if( /* {private SafeTryValidateInstrumentPrice}. */ ( ! defined( NDEBUG ) ) )

      // TODO 2 yg? Remember to call this method on any appropriate occasions when the price is supposed to be rounded.

      private: void SafeTryValidateInstrumentPrice
         ( double instrumentPrice1
         );

#endif

#if( /* {private RequestSubscribeOrdersStateUpdateIfNeeded}. */ 1 )

      // yg? This method is currently {private}.
      // yg? See also: {TRApiHelpers::RequestSubscribeOrdersStateUpdateIfNeeded}.

      private: void RequestSubscribeOrdersStateUpdateIfNeeded();

#endif
#if( /* {public RefillSingleInstrumentOrderPoolIfNeeded}. */ 1 )

      //

//TODO implement
//TODO in UniversalFX this is called {EnsureTradingOrderPoolFull}
      public: void RefillSingleInstrumentOrderPoolIfNeeded
//TODO We need instrument here, right? I don't like it.
//TODO If we had multiple instruments we would probably need a pointer to pool in each instrument.
//TODO Actually we need a way to set instrument afterwards. Problem is that it would be inefficient.
         ( TInstrument const & instrument1,
           int numberPooledItemsMinLimit
         );

#endif
#if( /* {public GetPooledOrCreateSingleInstrumentOrder}. */ 1 )

      //

//TODO implement
//TODO log a "pool miss" error but comment that it's wrong to do this at a performance critical moment
      public: TSingleInstrumentOrder & GetPooledOrCreateSingleInstrumentOrder
         ( TInstrument const & instrument1
         );

#endif
#if( /* {private CreateSingleInstrumentOrder}. */ 1 )

      // Call this method to create a single instrument order class instance.
      // {TSingleInstrumentOrder_} shall be {TSingleInstrumentOrder} or its subclass.
      // The caller shall not {delete} the order object, which is another reason to return a reference rather than a pointer.
      // This method is thread unsafe, as are most others.
      // yg? It's currently impossible to deallocate the object returned.
      // yg? Would it be more correct to declare this method {const} and the {SingleInstrumentsOrders_}
      // yg? and possibly some other fields {mutable}?
      //
      // TODO 3 yg? This is a bad solution as it won't work for unrelated broker adapter implementattions, each of which uses its own
      // TODO 3 yg? {TSingleInstrumentOrder} class. Therefore I declared this method {private}.
      // TODO 3 yg? Instead, the {TREngineAdapter} class should be passed an order base class as a template parameter and derive the
      // TODO 3 yg? {TSingleInstrumentOrder} class from it. That would allow the caller to provide an order base class
      // TODO 3 yg? containigng any data.
      // TODO 3 yg? In C#, it's probably impossible to derive a class from a template parameter, therefore the order class would need
      // TODO 3 yg? another field whose type will be specified by the caller. {public: TCallerData1_ CallerData1}
      // TODO 3 yg? or {public: TCustomData1_ CustomData1}. Maybe use the word "context" instead.

//TODO can I now eliminate this shit?
      private:
         template
            < typename TSingleInstrumentOrder_
            >
         TSingleInstrumentOrder_ & CreateSingleInstrumentOrder
            ( TInstrument const & instrument1
            );

#endif
#if( /* {public CreateSingleInstrumentOrder}. */ 1 )

      // yg? This method calls {CreateSingleInstrumentOrder<>}.

      public: TSingleInstrumentOrder & CreateSingleInstrumentOrder
         ( TInstrument const & instrument1
         );

#endif
#if( /* {public SendOrder}. */ 1 )

      // yg? See also: {TRApiHelpers::SendOrder}.

      public: void SendOrder
         ( TSingleInstrumentOrder & order1
         );

#endif
#if( /* {public SendOrders}. */ 1 )

      // See also: {TRApiHelpers::SendOrders<>}.

      public:
         template
            < typename TSingleInstrumentsOrdersPointerIterator_
            >
         void SendOrders
// TODO 2 yg? These should be reference iterators.
            ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
              TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
            );

#endif
#if( /* {public CanModifyOrder}. */ 1 )

      // See also: {TSingleInstrumentOrderHelpers::CanModifyOrder}.

      public: bool CanModifyOrder
         ( TSingleInstrumentOrder const & order1
         ) const;

#endif
#if( /* {public CanModifyOrders}. */ 1 )

      // yg? See also: {TSingleInstrumentOrderHelpers::CanModifyOrders<>}.

      public:
         template
            < typename TSingleInstrumentsOrdersPointerIterator_
            >
         bool CanModifyOrders
// TODO 2 yg? These should be reference iterators.
            ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
              TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
            ) const;

#endif
#if( /* {public RequestModifyOrder}. */ 1 )

      // yg? See also: {TRApiHelpers::RequestModifyOrder}.

      public: void RequestModifyOrder
         ( TSingleInstrumentOrder & order1
         );

#endif
#if( /* {public RequestModifyOrders}. */ 1 )

      // See also: {TRApiHelpers::RequestModifyOrders<>}.

      public:
         template
            < typename TSingleInstrumentsOrdersPointerIterator_
            >
         void RequestModifyOrders
// TODO 2 yg? These should be reference iterators.
            ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
              TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
            );

#endif
#if( /* {public CanCancelOrder}. */ 1 )

      // See also: {TSingleInstrumentOrderHelpers::CanCancelOrder}.

      public: bool CanCancelOrder
         ( TSingleInstrumentOrder const & order1
         ) const;

#endif
#if( /* {public CanCancelOrders}. */ 1 )

      // yg? See also: {TSingleInstrumentOrderHelpers::CanCancelOrders<>}.

      public:
         template
            < typename TSingleInstrumentsOrdersPointerIterator_
            >
         bool CanCancelOrders
// TODO 2 yg? These should be reference iterators.
            ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
              TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
            ) const;

#endif
#if( /* {private InternalCanCancelOrder}. */ 1 )

      // See also: {TSingleInstrumentOrderHelpers::InternalCanCancelOrder}.

      private: bool InternalCanCancelOrder
         ( TSingleInstrumentOrder const & order1
         ) const;

#endif
#if( /* {private ShallAndInternalCanCancelOrder}. */ 1 )

      // See also: {TSingleInstrumentOrderHelpers::ShallAndInternalCanCancelOrder}.

      private: bool ShallAndInternalCanCancelOrder
         ( TSingleInstrumentOrder const & order1
         ) const;

#endif
#if( /* {public RequestCancelOrder}. */ 1 )

      // See also: {TRApiHelpers::RequestCancelOrder}.

      public: void RequestCancelOrder
         ( TSingleInstrumentOrder & order1
         );

#endif
#if( /* {public RequestCancelOrders}. */ 1 )

      // See also: {TRApiHelpers::RequestCancelOrders<>}.

      public:
         template
            < typename TSingleInstrumentsOrdersPointerIterator_
            >
         void RequestCancelOrders
// TODO 2 yg? These should be reference iterators.
            ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
              TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
            );

#endif
#if( /* {public RequestCancelOrderIfCan}. */ 1 )

      // See also: {TRApiHelpers::RequestCancelOrderIfCan}.

      public: bool RequestCancelOrderIfCan
         ( TSingleInstrumentOrder & order1
         );

#endif
#if( /* {private RequestCancelOrderIfInternalCan}. */ 1 )

      // See also: {TRApiHelpers::RequestCancelOrderIfInternalCan}.

      private: bool RequestCancelOrderIfInternalCan
         ( TSingleInstrumentOrder & order1
         );

#endif
#if( /* {private RequestCancelOrderIfInternalShallAndCan}. */ 1 )

      // See also: {TRApiHelpers::RequestCancelOrderIfInternalShallAndCan}.

      private: bool RequestCancelOrderIfInternalShallAndCan
         ( TSingleInstrumentOrder & order1
         );

#endif
#if( /* {public RequestCancelOrderWhenCan}. */ 1 )

      // See also: {TRApiHelpers::RequestCancelOrderWhenCan}.

      public: bool RequestCancelOrderWhenCan
         ( TSingleInstrumentOrder & order1
         );

#endif
#if( /* {public RequestCancelAnyOrders}. */ 1 )

      // yg? See {TRApiHelpers::RequestCancelAnyOrders}, multiple overloads.

      public: void RequestCancelAnyOrders();

#endif

#if( /* Code pattern to be implemented later; also for the {AsyncExecuteOrder}, {AsyncModifyOrder}, {AsyncCancelOrder}, and possibly some other functionalities. */ 1 )
#if( /* //{public SendSuspendedOrder}. */ 1 )

      //// yg? Idea: this method should return an order state change subscription object and/or take such an object as a parameter.

      //// yg? We really don't need this method and instead the order object should contain a flag that the order is to be suspended/held until further notice.

      //public: void SendSuspendedOrder
      //   ( TSingleInstrumentOrder & order1
      //   );

#endif
#if( /* //{public CanExecuteSuspendedOrder}. */ 1 )

      //// Checks if the order is known to the brokerage and is still "held", we are logged in, atc.

      //public: bool CanExecuteSuspendedOrder
      //   ( TSingleInstrumentOrder const & order1
      //   ) const;

#endif
#if( /* //{public ValidateCanExecuteSuspendedOrder}. */ 1 )

      //// Calls the {CanExecuteSuspendedOrder} method and if it returns {false} throws a {::Common::ErrorHandling::TRecoverableErrorException} exception.

      //public: bool ValidateCanExecuteSuspendedOrder
      //   ( TSingleInstrumentOrder const & order1
      //   ) const;

#endif
#if( /* //{public AsyncExecuteSuspendedOrder}. */ 1 )

      //// If the {CanExecuteSuspendedOrder} method would return {false} the behavior is officially undefined.
      //// yg? Idea: this method should return an order state change subscription object and/or take such an object as a parameter.

      //public: void AsyncExecuteSuspendedOrder
      //   ( TSingleInstrumentOrder & order1
      //   );

#endif
#if( /* //{public TryAsyncExecuteSuspendedOrder}. */ 1 )

      //// Calls {CanExecuteSuspendedOrder} and if it returns {true} calls {AsyncExecuteSuspendedOrder}.
      //// yg? Consider renaming this to {Safe...} or {AsyncExecuteSuspendedOrderIfCan}.

      //public: bool TryAsyncExecuteSuspendedOrder
      //   ( TSingleInstrumentOrder & order1
      //   );

#endif
#endif

   // {::RApi::AdmCallbacks} implementation.
#if( /* //{(public) Alert}. */ 1 )

      // yg? See {::RApi::RCallbacks} implementation.

      //private: virtual int /*::RApi::AdmCallbacks::*/Alert
      //   ( ::RApi::AlertInfo * alertInfo1,
      //     void * context1,
      //     int * outcomeCode2
      //   ) override;

#endif

   // {::RApi::RCallbacks} implementation.
#if( /* {(public) Alert}. */ 1 )

      // yg? This method imlements both {::RApi::RCallbacks::Alert} and {::RApi::AdmCallbacks::Alert}.

      private: virtual int Alert
         ( ::RApi::AlertInfo * alertInfo1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) AccountList}. */ 1 )

      //

      private: virtual int AccountList
         ( ::RApi::AccountListInfo * accountListInfo1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) PriceIncrUpdate}. */ 1 )

      // yg? This callback will be called on the same thread as {::RApi::REngine::getPriceIncrInfo} was called
      // yg? if the data is already available in the cache. But I never tested this.

      private: virtual int PriceIncrUpdate
         ( ::RApi::PriceIncrInfo * priceIncrInfo1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) MarketMode}. */ 1 )

      //

      private: virtual int MarketMode
         ( ::RApi::MarketModeInfo * marketModeInfo1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) LimitOrderBook}. */ 1 )

      //

      private: virtual int LimitOrderBook
         ( ::RApi::LimitOrderBookInfo * limitOrderBookInfo1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) BestBidQuote}. */ 1 )

      //

      private: virtual int BestBidQuote
         ( ::RApi::BidInfo * bidInfo1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) BestAskQuote}. */ 1 )

      //

      private: virtual int BestAskQuote
         ( ::RApi::AskInfo * askInfo1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* //{(public) TradeCondition}. */ 1 )

      ////
      //
      //private: virtual int TradeCondition
      //   ( ::RApi::TradeInfo * tradeInfo1,
      //     void * context1,
      //     int * outcomeCode2
      //   ) override;

#endif
#if( /* {(public) TradePrint}. */ 1 )

      //

      private: virtual int TradePrint
         ( ::RApi::TradeInfo * tradeInfo1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) LineUpdate}. */ 1 )

      //

      private: virtual int LineUpdate
         ( ::RApi::LineInfo * lineInfo1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) FailureReport}. */ 1 )

      //

      private: virtual int FailureReport
         ( ::RApi::OrderFailureReport * orderFailureReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) RejectReport}. */ 1 )

      //

      private: virtual int RejectReport
         ( ::RApi::OrderRejectReport * orderRejectReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) StatusReport}. */ 1 )

      //

      private: virtual int StatusReport
         ( ::RApi::OrderStatusReport * orderStatusReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) NotModifiedReport}. */ 1 )

      //

      private: virtual int NotModifiedReport
         ( ::RApi::OrderNotModifiedReport * orderNotModifiedReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) ModifyReport}. */ 1 )

      //

      private: virtual int ModifyReport
         ( ::RApi::OrderModifyReport * orderModifyReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) NotCancelledReport}. */ 1 )

      //

      private: virtual int NotCancelledReport
         ( ::RApi::OrderNotCancelledReport * orderNotCancelledReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) CancelReport}. */ 1 )

      //

      private: virtual int CancelReport
         ( ::RApi::OrderCancelReport * orderCancelReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) TriggerPulledReport}. */ 1 )

      //

      private: virtual int TriggerPulledReport
         ( ::RApi::OrderTriggerPulledReport * orderTriggerPulledReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) TriggerReport}. */ 1 )

      //

      private: virtual int TriggerReport
         ( ::RApi::OrderTriggerReport * orderTriggerReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) FillReport}. */ 1 )

      //

      private: virtual int FillReport
         ( ::RApi::OrderFillReport * orderFillReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) TradeCorrectReport}. */ 1 )

      //

      private: virtual int TradeCorrectReport
         ( ::RApi::OrderTradeCorrectReport * orderTradeCorrectReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) BustReport}. */ 1 )

      //

      private: virtual int BustReport
         ( ::RApi::OrderBustReport * orderBustReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* {(public) OtherReport}. */ 1 )

      //

      private: virtual int OtherReport
         ( ::RApi::OrderReport * orderReport1,
           void * context1,
           int * outcomeCode2
         ) override;

#endif
#if( /* Misc. */ 1 )

      //private: virtual int AccountList(::RApi::AccountListInfo * pInfo,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int Alert(::RApi::AlertInfo * pInfo,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int AskQuote(::RApi::AskInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int BestAskQuote(::RApi::AskInfo * pInfo,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int BestBidQuote(::RApi::BidInfo * pInfo,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int BidQuote(::RApi::BidInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int BinaryContractList(::RApi::BinaryContractListInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int BustReport(::RApi::OrderBustReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int CancelReport(::RApi::OrderCancelReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int ClosePrice(::RApi::ClosePriceInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int ClosingIndicator(::RApi::ClosingIndicatorInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int EndQuote(::RApi::EndQuoteInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int EquityOptionStrategyList(::RApi::EquityOptionStrategyListInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int ExchangeList(::RApi::ExchangeListInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int ExecutionReplay(::RApi::ExecutionReplayInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int FailureReport(::RApi::OrderFailureReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int FillReport(::RApi::OrderFillReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int HighPrice(::RApi::HighPriceInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int InstrumentByUnderlying(::RApi::InstrumentByUnderlyingInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int LimitOrderBook(::RApi::LimitOrderBookInfo * pInfo,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int LineUpdate(::RApi::LineInfo * pInfo,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int LowPrice(::RApi::LowPriceInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int MarketMode(::RApi::MarketModeInfo * pInfo,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int ModifyReport(::RApi::OrderModifyReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int NotCancelledReport(::RApi::OrderNotCancelledReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int NotModifiedReport(::RApi::OrderNotModifiedReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int OpenInterest(::RApi::OpenInterestInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int OpenOrderReplay(::RApi::OrderReplayInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int OpenPrice(::RApi::OpenPriceInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int OpeningIndicator(::RApi::OpeningIndicatorInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int OptionList(::RApi::OptionListInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int OrderReplay(::RApi::OrderReplayInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int OtherReport(::RApi::OrderReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int PasswordChange(::RApi::PasswordChangeInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int PnlReplay(::RApi::PnlReplayInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int PnlUpdate(::RApi::PnlInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int PriceIncrUpdate(::RApi::PriceIncrInfo * pInfo,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int ProductRmsList(::RApi::ProductRmsListInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int RefData(::RApi::RefDataInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int RejectReport(::RApi::OrderRejectReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int SettlementPrice(::RApi::SettlementPriceInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int SodUpdate(::RApi::SodReport * pReport,
         void * pContext,
         int * aiCode) override;

      //private: virtual int StatusReport(::RApi::OrderStatusReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int Strategy(::RApi::StrategyInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int StrategyList(::RApi::StrategyListInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int TimeBar(::RApi::TimeBarInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int TimeBarReplay(::RApi::TimeBarReplayInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      private: virtual int TradeReplay(::RApi::TradeReplayInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int TriggerPulledReport(::RApi::OrderTriggerPulledReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int TriggerReport(::RApi::OrderTriggerReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int TradeCondition(::RApi::TradeInfo * pInfo,
         void * pContext,
         int * aiCode) override;

      //private: virtual int TradeCorrectReport(::RApi::OrderTradeCorrectReport * pReport,
      //   void * pContext,
      //   int * aiCode) override;

      //private: virtual int TradePrint(::RApi::TradeInfo * pInfo,
      //   void * pContext,
      //   int * aiCode) override;

      private: virtual int TradeRoute( ::RApi::TradeRouteInfo * pInfo,
			void * pContext,
			int * aiCode) override;

      private: virtual int TradeRouteList(::RApi::TradeRouteListInfo * pInfo,
			void * pContext,
			int * aiCode) override;

      private: virtual int TradeVolume(::RApi::TradeVolumeInfo * pInfo,
         void * pContext,
         int * aiCode) override;

#endif
   };
}
