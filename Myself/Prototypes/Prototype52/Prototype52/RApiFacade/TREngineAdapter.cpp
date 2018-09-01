#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TREngineAdapter.hpp"

#include "../Common/ControlFlow/TThreadedActivityCancellationToken.cpp"
#include "./TAccountInfoContainer.cpp"
//#include "./TInstrument.cpp"
#include "./TInstrumentBestAggregatedBidAskQuoteSubscription.cpp"
#include "./TInstrumentTradeSubscription.cpp"
//#include "./TSingleInstrumentOrder.cpp"
#include "./TREngineAdapterConfiguration.cpp"
#include "./TRApiHelpers.cpp"
#include "../Common/ErrorHandling/TErrorHandlingHelpers.cpp"
#include "../Common/Math/TMathHelpers.cpp"
#include "../Common/Globalization/TGlobalizationHelpers.cpp"
#include "../Common/DataFormatting/TDataFormattingHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TREngineAdapter::TREngineAdapter
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
      ) :
      ThreadedActivityCancellationToken_( & threadedActivityCancellationToken1 )
   {
   }

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TREngineAdapter::TREngineAdapter
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
        TREngineAdapterConfiguration && configuration1
      ) :
      ThreadedActivityCancellationToken_( & threadedActivityCancellationToken1 ),
      REngineParamsConfiguration_( ::std::move( configuration1.REngineParamsConfiguration ) ),
      LogInParamsConfiguration_( ::std::move( configuration1.LogInParamsConfiguration ) ),
      Instrument_( ::std::move( configuration1.InstrumentConfiguration ) )
   {
      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {public} Instance destructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TREngineAdapter::~TREngineAdapter()
   {
      if( ( ReadinessStateBitMask_ & TReadinessStateBitMask_REngineCreated_ ) != TReadinessStateBitMask_None_ )
      {
         REngine().~REngine();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }
   }

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Initialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::Initialize
      ( TREngineAdapterConfiguration && configuration1
      )
   {
      REngineParamsConfiguration_.Assign( ::std::move( configuration1.REngineParamsConfiguration ) );
      LogInParamsConfiguration_.Assign( ::std::move( configuration1.LogInParamsConfiguration ) );
      Instrument_.Initialize( ::std::move( configuration1.InstrumentConfiguration ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::DoInitialize
      ( TREngineAdapterConfiguration && configuration1
      )
   {
// TODO 2 yg? Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
// TODO 2 yg? Refer to it from consrtructors, destructors, {Initialize}.

      ReadinessStateBitMask_ = TReadinessStateBitMask_None_;
      //InstrumentMarketDataSubscriptionsActive_ = false;
      ShallSubscribeOrdersStateUpdate_ = ::std::move( configuration1.ShallSubscribeOrdersStateUpdate );
   }

#endif
#if( /* {public Prepare}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::Prepare()
   {
      // Visible universe.
      //    {TRApiHelpers::PopulateREngineParams}.
      //       Call.
      //    {ReadinessStateBitMask_}.
      //       Update.
      //    {REngineParamsConfiguration_}.
      //       Use, release resources.
      //    {Instrument_.Prepare}.
      //       Call.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.Prepare}.
      //       Call.
      //    {InstrumentTradeSubscription_.Prepare}.
      //       Call.
      //    {ShallSubscribeOrdersStateUpdate_}.
      //       Use.
      //    {REnginePlace_}.
      //       Update.

      Instrument_.Prepare( * this );
      InstrumentBestAggregatedBidAskQuoteSubscription_.Prepare( Instrument_ );
      InstrumentTradeSubscription_.Prepare( Instrument_ );

      // This is a heavy operation that can fail, therefore I don't want to do this in {DoInitialize}.
      // One other reason to do this after all other preparations is because {REngine()} can potentially call callbacks here.
      {
         ::RApi::REngineParams rEngineParams;
         rEngineParams.pAdmCallbacks = this;
         TRApiHelpers::PopulateREngineParams( rEngineParams, REngineParamsConfiguration_ );
         //REngine_.reset( TRApiHelpers::CreateREngine( rEngineParams ) );
         new( reinterpret_cast< void * >( REnginePlace_ ) ) ::RApi::REngine( & rEngineParams );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ReadinessStateBitMask_ == TReadinessStateBitMask_None_ );
         ReadinessStateBitMask_ = TReadinessStateBitMask_REngineCreated_;
      }

      {
         // Releasing the resources we don't need any more.
         TREngineParamsConfiguration dummy1( ::std::move( REngineParamsConfiguration_ ) );
      }

//TODO move this to Start
//TODO Update visible universe
      if( ShallSubscribeOrdersStateUpdate_ )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter} will not subscribe for order state updates" );
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
#if( /* {public Start}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::Start()
   {
      // This method is inline.
   }

#endif

#if( /* {public AccountInfo}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::RApi::AccountInfo const & TREngineAdapter::AccountInfo() const
   {
      return AccountInfoContainer_.AccountInfo();
   }

#endif
#if( /* {public Instrument}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TInstrument const & TREngineAdapter::Instrument() const
   {
      return Instrument_;
   }

#endif
#if( /* {public REngine}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::RApi::REngine & TREngineAdapter::REngine() //const
   {
      //return ( * REngine_.get() );

      // yg? Consider eliminating this validation to allow the caller
      // yg? to get the address at which an {::RApi::REngine} is to be created in advance.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ( ReadinessStateBitMask_ & TReadinessStateBitMask_REngineCreated_ ) != TReadinessStateBitMask_None_ );

      return ( * reinterpret_cast< ::RApi::REngine * >( REnginePlace_ ) );
   }

#endif

#if( /* {public LockREngine}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::LockREngine()
   {
      TRApiHelpers::LockREngine( REngine() );
   }

#endif
#if( /* {public UnlockREngine}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::UnlockREngine()
   {
      TRApiHelpers::UnlockREngine( REngine() );
   }

#endif

#if( /* {public SleepMillisecond}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::SleepMillisecond()
   {
      UnlockREngine();
      ::Common::Threading::TThreadingHelpers::SleepMillisecond();
      LockREngine();
      
//TODO don't do this?
      // According to the code contract, we may throw a {::Common::ControlFlow::TOperationCancelledException}
      // only while {REngine()} is locked.
      // Non-volatile read.
      ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled();
   }

#endif
#if( /* {public SleepMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::SleepMilliseconds
      ( int timeSpanMilliseconds
      )
   {
      if( timeSpanMilliseconds > 0 )
      {
         DoSleepMilliseconds( timeSpanMilliseconds );
      }
      else
      {
         // yg? Not unlocking {REngine()}, which can freeze some activities.
         // yg? Not validating that we are not cancelled yet.
         // yg? But as mentioned in a comment in {SleepUntilMultimediaTimeMilliseconds} body, the alternative isn't perfect either.
      }
   }

#endif
#if( /* {public DoSleepMilliseconds}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::DoSleepMilliseconds
      ( int timeSpanMilliseconds
      )
   {
      UnlockREngine();
      ::Common::Threading::TThreadingHelpers::DoSleepMilliseconds( timeSpanMilliseconds );
      LockREngine();
      
      // According to the code contract, we may throw a {::Common::ControlFlow::TOperationCancelledException}
      // only while {REngine()} is locked.
      // Non-volatile read.
      ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled();
   }

#endif
#if( /* {public SleepUntilMultimediaTimeMilliseconds}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::SleepUntilMultimediaTimeMilliseconds
      ( int endTimeMilliseconds
      )
   {
      // yg? Unlocking {REngine()} and only then checking if sleeping time span is going to be positive.
      // yg? But as mentioned in a comment in {SleepMilliseconds} body, the alternative isn't perfect either.
      UnlockREngine();
      ::Common::Threading::TThreadingHelpers::SleepUntilMultimediaTimeMilliseconds( endTimeMilliseconds );

      //// Test.
      //{
      //   int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
      //   int int1( currentTimeMilliseconds - endTimeMilliseconds );
      //   if( int1 != 0 )
      //   {
      //      ::std::cout << int1 << ::std::endl;
      //   }
      //}

      LockREngine();
      
      // According to the code contract, we may throw a {::Common::ControlFlow::TOperationCancelledException}
      // only while {REngine()} is locked.
      // Non-volatile read.
      ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled();
   }

#endif

#if( /* {public AsyncEnsureLoggedIn}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::AsyncEnsureLoggedIn()
   {
      // yg? Would it be more reliable to call {AddReadinessStateBit} here?
      // yg? Some marginal cases could be possible if the caller logs in and/or logs out multiple times in a row.
      ReadinessStateBitMask_ =
         static_cast< TReadinessStateBitMask_ >( ReadinessStateBitMask_ | TReadinessStateBitMask_ShallLogIn_ );

      {
         ::RApi::LoginParams logInParams;
         logInParams.pCallbacks = this;
         TRApiHelpers::PopulateLogInParams( logInParams, LogInParamsConfiguration_ );
         TRApiHelpers::AsyncEnsureREngineLoggedIn( REngine(), logInParams );
      }
   }

#endif
#if( /* {public AsyncEnsureLoggedOut}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::AsyncEnsureLoggedOut()
   {
      //InstrumentMarketDataSubscriptionsActive_ = false;
      ReadinessStateBitMask_ =
         static_cast< TReadinessStateBitMask_ >( ReadinessStateBitMask_ & ( ~ TReadinessStateBitMask_ShallLogIn_ ) );
      TRApiHelpers::AsyncEnsureREngineLoggedOut( REngine() );

      // yg? Consider to also do some other things here, such as invalidate market data.
      // yg? Although market data should probably be invalidated when a callback notifying of a connection loss/closing is called.

//TODO review
      // TODO 3 yg? Log an error/warning if at least 1 order has a pending request or is working.
      // TODO 3 yg? This would require to check some order state bits, including {TOrderStateBitMask_NewOrderRequestPending},
      // TODO 3 yg? {TOrderStateBitMask_LastModificationRequestPending}, {TOrderStateBitMask_LastCancellationRequestPending},
      // TODO 3 yg? {TOrderStateBitMask_CancellationRequestPending}, {TOrderStateBitMask_Completed}.
      // TODO 3 yg? If I implement order removal we would need to do this also when removing an order.
   }

#endif
#if( /* {private AddReadinessStateBit}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::AddReadinessStateBit
      ( TReadinessStateBitMask_ readinessStateBit
      )
   {
      // Visible universe.
      //    {ReadinessStateBitMask_}.
      //       Use, update.
      //    {RequestInstrumentPriceIncrementMinLimit}.
      //       Call.

      // I want to believe that it's safe to assume this.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( readinessStateBit != TReadinessStateBitMask_None_ &&
           ( readinessStateBit & ( ~ TReadinessStateBitMask_AllConnectPointsLoggedInTo_ ) ) == TReadinessStateBitMask_None_
         );

      TReadinessStateBitMask_ readinessStateBitMask1( ReadinessStateBitMask_ );
      TReadinessStateBitMask_ readinessStateBitMask2
         ( static_cast< TReadinessStateBitMask_ >( readinessStateBitMask1 | readinessStateBit ) );

      // This condition should always be {true} but it depends on {REngine()} raising correct alerts.
      // It's probably safe to not check it but we would probably need to check it if we were to raise an event.
      if( readinessStateBitMask2 != readinessStateBitMask1 )

      {
         ReadinessStateBitMask_ = readinessStateBitMask2;

         if( ( readinessStateBitMask2 & TReadinessStateBitMask_AllConnectPointsLoggedInTo_ ) !=
             TReadinessStateBitMask_AllConnectPointsLoggedInTo_
           )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            // {REngine()} needs price increment data to send an order.
            // Otherwise it will automatically request the data when sending an order, which would slow things down.
            // In C++ the {RAPI_CACHE_ORDER_RQ} environment variable controls this behavior and in .NET it's not configurable.
            // It's probably safe to request price increment before log-in to all connect points completes
            // or not re-request it under some conditions but keeping it simple.
            // yg? Should we do nothing when the {TReadinessStateBitMask_ShallLogIn_} bit is not set?
            // yg? If this request fails we will not repeat it until a disconnection followed by a reconnection occur.
            // yg? In fact, if an exception is thrown we will die.
            // In .NET we request price increment only when we subscribe for market data
            // but the caller should be able to send orders without a market data subscription.
            RequestInstrumentPriceIncrementMinLimit( Instrument_ );
         }
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }
   }

#endif
#if( /* {public Ready}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TREngineAdapter::Ready() const
   {
      // Non-volatile read. This is documented in the method comment.
      return ( ReadinessStateBitMask_ == TReadinessStateBitMask_All_ );
   }

#endif

#if( /* {private RequestInstrumentPriceIncrementMinLimit}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::RequestInstrumentPriceIncrementMinLimit
      ( TInstrument const & instrument1
      )
   {
      //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & instrument1 ) == ( & Instrument_ ) );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & instrument1 ) == ( & instrument1.BrokerAdapter().Instrument() ) );

      TRApiHelpers::RequestInstrumentPriceIncrementMinLimit( instrument1 );
   }

#endif

#if( /* {private RequestSubscribeInstrumentMarketDataIfNeeded}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::RequestSubscribeInstrumentMarketDataIfNeeded()
   {
      //// yg? If subscription initiation fails we will have no other chance to initiate it.
      //// yg? Consider refactoring the code similarly to {AsyncEnsureLoggedIn}.
      //// yg? But that wouldn't really solve the problem -- we need to have a more robust logic to recover a broken subscription.
      //if( ! InstrumentMarketDataSubscriptionsActive_ )

      {
         //InstrumentMarketDataSubscriptionsActive_ = true;

         TRApiHelpers::RequestSubscribeInstrumentMarketDataIfNeeded
            ( Instrument_,
              ( ::RApi::MD_MARKET_MODE |
                ::RApi::MD_BEST |
                ::RApi::MD_PRINTS
                //::RApi::MD_PRINTS_COND
              )
            );
      }
   }

#endif
#if( /* {public HackRequestUnsubscribeInstrumentMarketDataIfNeeded}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::HackRequestUnsubscribeInstrumentMarketDataIfNeeded
      ( //TInstrument const & instrument1
      )
   {
      TRApiHelpers::RequestUnsubscribeInstrumentMarketDataIfNeeded( Instrument_ );
   }

#endif
#if( /* {public RequestSubscribeInstrumentBestAggregatedBidAskQuoteIfNeeded}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TInstrumentBestAggregatedBidAskQuoteSubscription /*yg? const*/ &
      TREngineAdapter::RequestSubscribeInstrumentBestAggregatedBidAskQuoteIfNeeded
         ( TInstrument const & instrument1
         )
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & instrument1 ) == ( & Instrument_ ) );
      RequestSubscribeInstrumentMarketDataIfNeeded();
      return InstrumentBestAggregatedBidAskQuoteSubscription_;
   }

#endif
#if( /* //{public AsyncUnsubscribe}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // yg? Not implemented.

#endif
#if( /* {public RequestSubscribeInstrumentTradeIfNeeded}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TInstrumentTradeSubscription /*yg? const*/ & TREngineAdapter::RequestSubscribeInstrumentTradeIfNeeded
      ( TInstrument const & instrument1
      )
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & instrument1 ) == ( & Instrument_ ) );
      RequestSubscribeInstrumentMarketDataIfNeeded();
      return InstrumentTradeSubscription_;
   }

#endif
#if( /* //{public AsyncUnsubscribe}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // yg? Not implemented.

#endif
#if( /* //{private ProcessTradeInfo}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TREngineAdapter::ProcessTradeInfo
   //   ( ::RApi::TradeInfo const & tradeInfo1,
   //     bool tradeInfo1IsConditional
   //   )
   //{
   //   // TODO 3 yg? Why is this method inline while it's called from multiple places?
   //   // TODO 3 yg? Check some other {::RApi::TradeInfo} fields, like {sCondition}.
   //
   //   // yg? Assuming this market data is for our only instrument.
   //   // yg? Not logging anything -- assuming an event listener will.
   //   // TODO 3 yg? We need to log all fields here. And we need the date-time keeper here to log the timing.
   //
   //   // yg? Would it be safe to rely on this assumption? I don't feel so.
   //   assert( tradeInfo1IsConditional == ( tradeInfo1.sCondition.iDataLen > 0 ) );
   //
   //#if( ! defined( NDEBUG ) )
   //   // yg? Another test of {tradeInfo1.bPriceFlag} is inefficient and that's OK as this occurs in debug build only.
   //   if( tradeInfo1.bPriceFlag )
   //
   //   {
   //      // yg? Logging this before the data itself.
   //      SafeTryValidateInstrumentPrice( tradeInfo1.dPrice );
   //   }
   //#endif
   //
   //   if( ( tradeInfo1.iType == ::RApi::MD_UPDATE_CB ) && tradeInfo1.bPriceFlag )
   //   {
   //      InstrumentTradeSubscription_.InstrumentTrade.QuantityAndPrice.Price = tradeInfo1.dPrice;
   //
   //      // yg? Can this validation fail? Rithmic docs says that trade size can be 0 but we don't interpret such data as "indicative".
   //      assert( tradeInfo1.iSize > 0 );
   //
   //      InstrumentTradeSubscription_.InstrumentTrade.QuantityAndPrice.Quantity = static_cast< double >( tradeInfo1.iSize );
   //
   //      {
   //         // yg? R|API release notes says that this is "timestamp values as presented by the exchange, if available".
   //         // yg? It's unclear if this is market data generation time or sending time.
   //         // yg? In any case we have only 1 field to assign this date-time-stamp to.
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //         ::Poco::Int64 dateTimeStampMicrosecondsSince1970( tradeInfo1.iSourceSsboe * ::Poco::Timespan::SECONDS + tradeInfo1.iSourceUsecs );
   //
   //         InstrumentTradeSubscription_.InstrumentTrade.GenerationDateTimeStampMillisecondsSince1970 =
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //            static_cast< double >( dateTimeStampMicrosecondsSince1970 ) / static_cast< double >( ::Poco::Timespan::MILLISECONDS );
   //      }
   //
   //      {
   //         // yg? Based on R|API docs, this timestamp indicates the receipt time of this message from the market data provider.
   //         // yg? So this really is not sending date-time.
   //         // yg? Do we need a helper method for this, like in .NET?
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //         ::Poco::Int64 dateTimeStampMicrosecondsSince1970( tradeInfo1.iSsboe * ::Poco::Timespan::SECONDS + tradeInfo1.iUsecs );
   //         InstrumentTradeSubscription_.InstrumentTrade.SendingDateTimeStampMillisecondsSince1970 =
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //            //static_cast< double >( tradeInfo1.iSsboe * ( ::Poco::Timespan::SECONDS / ::Poco::Timespan::MILLISECONDS ) )
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //            //+ ( static_cast< double >( tradeInfo1.iUsecs ) / static_cast< double >( ::Poco::Timespan::MILLISECONDS ) );
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //            static_cast< double >( dateTimeStampMicrosecondsSince1970 ) / static_cast< double >( ::Poco::Timespan::MILLISECONDS );
   //      }
   //
//>>> This should be done at the beginning of the method.
   //      InstrumentTradeSubscription_.InstrumentTrade.IsConditional = tradeInfo1IsConditional;
   //
   //      InstrumentTradeSubscription_.RaiseOnReceivedData();
   //   }
   //   else
   //
   //   // yg? If the data is "indicative" we simply ignore it.
   //   {
   //      static char const constantString1AsArray[]( "received but ignored an indicative {RApi::TradeInfo}" );
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //}

#endif
#if( /* {private SafeTryValidateInstrumentPrice}. */ ( ! defined( NDEBUG ) ) && 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::SafeTryValidateInstrumentPrice
      ( double instrumentPrice1
      )
   {
      // This check is probably unnecessary in most cases but it's OK to do it in debug build.
      // It's actually necessary when validating the last fill price of an order as it can be someone's order.
      //if( Instrument_.PriceIncrementMinLimit <= 0.0 )
      if( ( ReadinessStateBitMask_ & TReadinessStateBitMask_InstrumentPriceIncrementMinLimitReceived_ ) ==
          TReadinessStateBitMask_None_
        )

      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         return;
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      if( // Is it more correct to round both positive and negative price midpoint up?
          // It doesn't matter in this case but it would when rounding average fill price
          // and in that case I might want to round buy price up and sell price down.
          // Although I should not need to round average fill price.
          ( ::Common::Math::TMathHelpers::RoundValueToMultipleOfMidpointUp( instrumentPrice1, Instrument_.PriceIncrementMinLimit ) ==
            instrumentPrice1
          ) //&&
         
          //::std::fmod( instrumentPrice1, Instrument_.PriceIncrementMinLimit ) == 0.0
        )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         {
            static char const constantString1AsArray[]( "instrument price is not rounded" );
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            // I demoted this from "Critical" to "Error" as from the nearby code point of view this error is not critical
            // even though a lot of logic would be broken by a not properly rounded price, primarely in the strategy.
            // Actually it would really be corrupt data, so let's log a "Critical" error.
            logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }
   }

#endif

#if( /* {private RequestSubscribeOrdersStateUpdateIfNeeded}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineAdapter::RequestSubscribeOrdersStateUpdateIfNeeded()
   {
      // yg? If I make this method {public} I might need to redesign this logic.
      // yg? The redesign might include the elimination of the {ShallSubscribeOrdersStateUpdate_} check.

      // yg? The "if needed" originally meant "if we are not subscribed yet" but now we have this additional condition,
      // yg? which is a bit ugly but it's OK, at least for this {private} method.
      if( ShallSubscribeOrdersStateUpdate_ )

      {
         TRApiHelpers::RequestSubscribeOrdersStateUpdateIfNeeded( REngine(), AccountInfoContainer_.AccountInfo() );
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
   }

#endif
#if( /* {private CreateSingleInstrumentOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentOrder_
      >
   inline TSingleInstrumentOrder_ & TREngineAdapter::CreateSingleInstrumentOrder
      ( TInstrument const & instrument1
      )
   {
//TODO maybe don't bother writing exception safe code
//TODO comment: // This code is not necessarily exception safe.

      TSingleInstrumentOrder_ * order1( new TSingleInstrumentOrder_ );

      {
         TSingleInstrumentOrder * order1AsBase( order1 );

         // Unnamed objects -- move semantics.
         ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::value_type
            singleInstrumentsOrdersNewItem
               ( reinterpret_cast< void const * >( order1AsBase ),
                 ::std::unique_ptr< TSingleInstrumentOrder >( order1AsBase )
               );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & instrument1 ) == ( & Instrument_ ) );
         order1->Prepare( instrument1 );

         // TODO 3 yg? We should validate that this insertion succeeded.
         SingleInstrumentsOrders_.insert( ::std::move( singleInstrumentsOrdersNewItem ) );
      }

      return ( * order1 );
   }

#endif
#if( /* {public CreateSingleInstrumentOrder}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TSingleInstrumentOrder & TREngineAdapter::CreateSingleInstrumentOrder
      ( TInstrument const & instrument1
      )
   {
      // This method is not inline.

      return CreateSingleInstrumentOrder< TSingleInstrumentOrder >( instrument1 );
   }

#endif
#if( /* {public SendOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::SendOrder
      ( TSingleInstrumentOrder & order1
      )
   {
      // yg? I could declare this method {static}.

      TRApiHelpers::SendOrder( order1 );
   }

#endif
#if( /* {public SendOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline void TREngineAdapter::SendOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      )
   {
      // yg? I could declare this method {static}.

      TRApiHelpers::SendOrders( orders1BeginIterator, orders1EndIterator );
   }

#endif
#if( /* {public CanModifyOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TREngineAdapter::CanModifyOrder
      ( TSingleInstrumentOrder const & order1
      ) const
   {
      // yg? I could declare this method {static}.

      return TSingleInstrumentOrderHelpers::CanModifyOrder( order1 );
   }

#endif
#if( /* {public CanModifyOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TREngineAdapter::CanModifyOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      ) const
   {
      // yg? I could declare this method {static}.

      return TSingleInstrumentOrderHelpers::CanModifyOrders( orders1BeginIterator, orders1EndIterator );
   }

#endif
#if( /* {public RequestModifyOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::RequestModifyOrder
      ( TSingleInstrumentOrder & order1
      )
   {
      // yg? I could declare this method {static}.

      TRApiHelpers::RequestModifyOrder( order1 );
   }

#endif
#if( /* {public RequestModifyOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline void TREngineAdapter::RequestModifyOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      )
   {
      // yg? I could declare this method {static}.

      TRApiHelpers::RequestModifyOrders( orders1BeginIterator, orders1EndIterator );
   }

#endif
#if( /* {public CanCancelOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TREngineAdapter::CanCancelOrder
      ( TSingleInstrumentOrder const & order1
      ) const
   {
      // yg? I could declare this method {static}.

      return TSingleInstrumentOrderHelpers::CanCancelOrder( order1 );
   }

#endif
#if( /* {public CanCancelOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TREngineAdapter::CanCancelOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      ) const
   {
      // yg? I could declare this method {static}.

      return TSingleInstrumentOrderHelpers::CanCancelOrders( orders1BeginIterator, orders1EndIterator );
   }

#endif
#if( /* {private InternalCanCancelOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TREngineAdapter::InternalCanCancelOrder
      ( TSingleInstrumentOrder const & order1
      ) const
   {
      // yg? I could declare this method {static}.

      return TSingleInstrumentOrderHelpers::InternalCanCancelOrder( order1 );
   }

#endif
#if( /* {private ShallAndInternalCanCancelOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TREngineAdapter::ShallAndInternalCanCancelOrder
      ( TSingleInstrumentOrder const & order1
      ) const
   {
      // yg? I could declare this method {static}.

      return TSingleInstrumentOrderHelpers::ShallAndInternalCanCancelOrder( order1 );
   }

#endif
#if( /* {public RequestCancelOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::RequestCancelOrder
      ( TSingleInstrumentOrder & order1
      )
   {
      // yg? I could declare this method {static}.

      TRApiHelpers::RequestCancelOrder( order1 );
   }

#endif
#if( /* {public RequestCancelOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline void TREngineAdapter::RequestCancelOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      )
   {
      // yg? I could declare this method {static}.

      TRApiHelpers::RequestCancelOrders( orders1BeginIterator, orders1EndIterator );
   }

#endif
#if( /* {public RequestCancelOrderIfCan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TREngineAdapter::RequestCancelOrderIfCan
      ( TSingleInstrumentOrder & order1
      )
   {
      // yg? I could declare this method {static}.

      return TRApiHelpers::RequestCancelOrderIfCan( order1 );
   }

#endif
#if( /* {private RequestCancelOrderIfInternalCan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TREngineAdapter::RequestCancelOrderIfInternalCan
      ( TSingleInstrumentOrder & order1
      )
   {
      // yg? I could declare this method {static}.

      return TRApiHelpers::RequestCancelOrderIfInternalCan( order1 );
   }

#endif
#if( /* {private RequestCancelOrderIfInternalShallAndCan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TREngineAdapter::RequestCancelOrderIfInternalShallAndCan
      ( TSingleInstrumentOrder & order1
      )
   {
      // yg? I could declare this method {static}.

      return TRApiHelpers::RequestCancelOrderIfInternalShallAndCan( order1 );
   }

#endif
#if( /* {public RequestCancelOrderWhenCan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TREngineAdapter::RequestCancelOrderWhenCan
      ( TSingleInstrumentOrder & order1
      )
   {
      // yg? I could declare this method {static}.

      return TRApiHelpers::RequestCancelOrderWhenCan( order1 );
   }

#endif
#if( /* {public RequestCancelAnyOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TREngineAdapter::RequestCancelAnyOrders()
   {
      // yg? I could declare this method {static}.

      TRApiHelpers::RequestCancelAnyOrders( REngine(), AccountInfoContainer_.AccountInfo(), SingleInstrumentsOrders_ );
   }

#endif

#if( /* Code pattern to be implemented later; also for the {AsyncExecuteOrder}, {AsyncModifyOrder}, {AsyncCancelOrder}, and possibly some other functionalities. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

   // {::RApi::AdmCallbacks} implementation.
#if( /* //{(public) Alert}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //int TREngineAdapter::/*::RApi::AdmCallbacks::*/Alert
   //   ( ::RApi::AlertInfo * alertInfo1,
   //     void * /*context1*/,
   //     int * /*outcomeCode2*/
   //   )
   //{
   //   //::RApi::AdmCallbacks::...
   //
   //   return OK;
   //}

#endif

   // {::RApi::RCallbacks} implementation.
#if( /* {(public) Alert}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::Alert
      ( ::RApi::AlertInfo * alertInfo1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      // TODO 3 yg? In case of a disconnection from the market data connect point we should invalidate market data.
      // TODO 3 yg? We should also process any market data received after that as indicative/invalid.

      // Visible universe.
      //    {::OmneException}.
      //       Catch.
      //    {::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {TRApiHelpers::ConnectPointIdNone}.
      //       Validate.
      //    {TRApiHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {::RApi::RCallbacks::Alert} -- base.
      //       Implement.
      //    {ReadinessStateBitMask_}.
      //       Use, update.
      //    {AddReadinessStateBit}.
      //       Call.
      //    {alertInfo1->iAlertType}.
      //       Use.
      //    {alertInfo1->iConnectionId}.
      //       Use.
      //    {alertInfo1->iRpCode}.
      //       Use.
      //       yg? We only use this in some logic that doesn't affect the behavior.
      //    {alertInfo1->...}
      //       We might log some other fields.

      try
      {
         //::RApi::RCallbacks::...

         // The order of these {case}s is optimized for performance.
         switch( alertInfo1->iAlertType )
         {
            case ::RApi::ALERT_LOGIN_COMPLETE :
            {
               // I want to believe that it's safe to assume that {alertInfo1->iConnectionId} specifies a known connect point.
               // Note that some connect points are not currently known to us.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( alertInfo1->iConnectionId > TRApiHelpers::ConnectPointIdNone );

               TReadinessStateBitMask_ connectPointBitMask1
                  ( static_cast< TReadinessStateBitMask_ >( 1U << static_cast< unsigned int >( alertInfo1->iConnectionId ) ) );

               // This method validates that this bit belongs to {TReadinessStateBitMask_AllConnectPointsLoggedInTo_}.
               AddReadinessStateBit( connectPointBitMask1 );

               break;
            }

            // yg? In .NET we try to reconnect in this case.
            // yg? Actually I commented that code out.
            // yg? Gene Sato wrote about the .NET implementation:
            // yg? <Quote>You shouldn't really need to call reconnect.
            // yg? It is present in the .NET interface primarily to match the c++ interface.</Quote>
            // yg? So it sounds like there are more reasons to call {REngine().reconnect} in C++ than in .NET.
            // yg? But experience shows that the C++ R|API does actually recover on its own.
            // yg? See {::RApi::ALERT_QUIET_HEARTBEAT} comment below.
            case ::RApi::ALERT_CONNECTION_BROKEN :

            // When someone else logs in we will be forcibly logged out and this alert will arrive with the trading system connect point ID.
            // The {::RApi::ALERT_CONNECTION_CLOSED} alert will also arrive for each connected connect point,
            // including the trading system one.
            case ::RApi::ALERT_FORCED_LOGOUT :

            case ::RApi::ALERT_CONNECTION_CLOSED :
            case ::RApi::ALERT_CONNECTION_OPENED :
            case ::RApi::ALERT_LOGIN_FAILED :
            {
               // As mentioned above, I want to believe that this assumption is safe.
               // yg? It would be nice to validate this the way {AddReadinessStateBit} does.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( alertInfo1->iConnectionId > TRApiHelpers::ConnectPointIdNone );

               //break;
            }

            // yg? This alert is probably intended to be raised when we call the {::RApi::REngine} destructor
            // yg? but I haven't seen that happening.
            // yg? We should not handle it.
            // yg? Although current code would probably be OK if executed when we are being destructed.
            // yg? This probably doesn't specify a connect point.
            case ::RApi::ALERT_SHUTDOWN_SIGNAL :

            {
               // As mentioned above, I want to believe that this assumption is safe.
               // At this point, this probably doesn't equal {TRApiHelpers::ConnectPointIdNone},
               // but if it did this logic would not change {ReadinessStateBitMask_} as the respective bit is always 0.
               // See {TReadinessStateBitMask_Dummy1_}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( alertInfo1->iConnectionId >= TRApiHelpers::ConnectPointIdNone );

               TReadinessStateBitMask_ connectPointBitMask1
                  ( static_cast< TReadinessStateBitMask_ >( 1U << static_cast< unsigned int >( alertInfo1->iConnectionId ) ) );

               ReadinessStateBitMask_ = static_cast< TReadinessStateBitMask_ >( ReadinessStateBitMask_ & ( ~ connectPointBitMask1 ) );
               break;
            }

            // yg? Ignoring this. It's probably possible that the connection will be quietly restored without any furter alerts.
            // yg? See {::RApi::ALERT_CONNECTION_BROKEN} comment above.
            // yg? case ::RApi::ALERT_QUIET_HEARTBEAT :

            // This alert arrives after we tried to subscribe for an inavlid instrument. Possibly also in some other cases.
            // yg? case ::RApi::ALERT_SERVICE_ERROR :

            // yg? case ::RApi::ALERT_TRADING_DISABLED :
            // yg? case ::RApi::ALERT_TRADING_ENABLED :
            default :
            {
               break;
            }
         }

         {
            static char const formatConstantString1AsArray[]( "{RApi::AlertInfo}; %.*s; %.*s; %.*s; %u; %u; %i; %.*s" );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 64
                 + alertInfo1->sTicker.iDataLen
                 + alertInfo1->sExchange.iDataLen
                 + alertInfo1->sMessage.iDataLen
                 + alertInfo1->sRpCode.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // We will format these as an unsigned.
            {
               // This is probably positive but we will be OK even if this is 0.
               // I don't want to assume this.
               assert( alertInfo1->iAlertType >= 0 );

               // As mentioned above, I want to believe that this assumption is safe.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( alertInfo1->iConnectionId >= TRApiHelpers::ConnectPointIdNone );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      alertInfo1->sTicker.iDataLen,
                      alertInfo1->sTicker.pData,
                      alertInfo1->sExchange.iDataLen,
                      alertInfo1->sExchange.pData,
                      alertInfo1->sMessage.iDataLen,
                      alertInfo1->sMessage.pData,
                      static_cast< unsigned int >( alertInfo1->iAlertType ),
                      static_cast< unsigned int >( alertInfo1->iConnectionId ),

                      // This is probably not negative but I don't want to format this as an unsigned. We still don't format the '+' sign.
                      alertInfo1->iRpCode,
                      
                      alertInfo1->sRpCode.iDataLen,
                      alertInfo1->sRpCode.pData
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }
            
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            
            if( alertInfo1->iRpCode == API_OK )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // yg? Do we ever get to this point?
               // I don't want to call {::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint}.

               // yg? If the error is not too severe or on the flip side very severe it might be better to mark this a "Warning" or "Critical".
               //goto label1;
               goto label2;
            }

            // The order of these {case}s is optimized for performance.
            switch( alertInfo1->iAlertType )
            {
               case ::RApi::ALERT_LOGIN_COMPLETE :
               case ::RApi::ALERT_CONNECTION_OPENED :
               {
                  // yg? Can this be {false} if the caller logs in and logs out a few times in a row?
                  if( ( ReadinessStateBitMask_ & TReadinessStateBitMask_ShallLogIn_ ) != TReadinessStateBitMask_None_ )

                  {
                     goto label3;
                  }
                  else
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                     goto label2;
                  }
               
                  break;
               }

               case ::RApi::ALERT_CONNECTION_CLOSED :
               {
                  // This will/can be {false} if someone else logs in and the server forcibly logs us out.
                  // See {::RApi::ALERT_FORCED_LOGOUT} comment above.
                  // yg? Can this be {false} if the caller logs in and logs out a few times in a row?
                  if( ( ReadinessStateBitMask_ & TReadinessStateBitMask_ShallLogIn_ ) == TReadinessStateBitMask_None_ )

                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                     goto label2;
                  }

               label3:
                  logger1.information( tempString1 );
                  break;
               }
               
               case ::RApi::ALERT_TRADING_ENABLED :
               case ::RApi::ALERT_CONNECTION_BROKEN :
               case ::RApi::ALERT_QUIET_HEARTBEAT :
               {
                  logger1.warning( tempString1 );
                  break;
               }

               // Should this be marked "Critical"? Because we are not designed to recover from this. Let's keep it this way for now.
               case ::RApi::ALERT_FORCED_LOGOUT :

               // yg? Should this be marked "Critical"? Maybe not or maybe depending on {alertInfo1->iRpCode}.
               case ::RApi::ALERT_SERVICE_ERROR :

               // I don't want to mark this "Critical".
               case ::RApi::ALERT_TRADING_DISABLED :

               case ::RApi::ALERT_LOGIN_FAILED :

               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();

               label2:
                  logger1.error( tempString1 );
                  break;
               }

               // This is not necessarily a critical error but it never happens.
               //case ::RApi::ALERT_SHUTDOWN_SIGNAL :

               default :
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               
               //label1:
                  logger1.critical( tempString1 );
                  break;
               }
            }
         }

         return OK;
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::Poco::Exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::std::exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ... )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
   }

#endif
#if( /* {(public) AccountList}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::AccountList
      ( ::RApi::AccountListInfo * accountListInfo1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      // yg? We don't currently log this info.

      // Visible universe.
      //    {::OmneException}.
      //       Catch.
      //    {::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {TRApiHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {AccountList} -- base.
      //       Implement.
      //    {ReadinessStateBitMask_}.
      //       Use, update.
      //    {AccountInfoContainer_.Assign}.
      //       Call.
      //    {RequestSubscribeOrdersStateUpdateIfNeeded}.
      //       Call.
      //    {accountListInfo1->asAccountInfoArray}.
      //       Use.
      //    {accountListInfo1->iArrayLen}.
      //       Use.
      //    {accountListInfo1->iRpCode}.
      //       Use.

      try
      {
         //::RApi::RCallbacks::...

         {
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            if( accountListInfo1->iRpCode == API_OK &&

                // yg? We support only 1 trading account per user account.
                accountListInfo1->iArrayLen == 1
              )
            {
               if( ( ReadinessStateBitMask_ & TReadinessStateBitMask_AccountInfoReceived_ ) == TReadinessStateBitMask_None_ )
               {
                  // yg? We assign to {AccountInfoContainer_} only once.
                  // yg? Otherwise if we receive a different info later we would have issues,
                  // yg? such as we would be able to send order modification/cancellation requests to another account.
                  // yg? Another possible issue is that pointers in {AccountInfoContainer_} would have a chance to change.
                  // yg? But if we receive invalid data or valid data changes we will get stuck with what we received first.
                  // yg? One solution is to remember what account we sent each order to and send order modification/cancellation requests
                  // yg? to the same account.
                  // yg? We would have to ensure that any copied pointers would not become invalid.
                  // yg? But on a reconnect we would also have to subscribe for order state updates from all known accounts,
                  // yg? or at least those accounts that are still valid and/or where we believe we have working or restatable orders.
                  // yg? Of course it would be weird if an account is no longer valid but we believe we have working orders in it.
                  // yg? A simpler solution would be to make 1 account configurable
                  // yg? and then validate that one of the arrived {::RApi::AccountInfo}'s matches what's configured.
                  AccountInfoContainer_.Assign( * accountListInfo1->asAccountInfoArray );
               
                  // It would probably be more reliable to set this bit after remaining code succeeds.
                  // Although if an exception is thrown we would die anyway and the caller would have no chance to do any damage
                  // as it would need to acquire the lock first.
                  ReadinessStateBitMask_ =
                     static_cast< TReadinessStateBitMask_ >( ReadinessStateBitMask_ | TReadinessStateBitMask_AccountInfoReceived_ );

                  {
                     //static char const constantString1AsArray[]( "received and saved an {RApi::AccountListInfo}" );
                     static char const constantString1AsArray[]( "received an {RApi::AccountListInfo}" );
                     logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                  }
               }
               else
               {
                  static char const constantString1AsArray[]( "received but ignored an {RApi::AccountListInfo}" );

                  // yg? This used to be labelled "Information", which wasn't really a bad idea
                  // yg? as this probably happens when we log in multiple times.
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               goto label7;
            }
            else
            {
               {
                  static char const constantString1AsArray[]( "received an invalid {RApi::AccountListInfo}" );
                  logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            }
         }

         if( ( ReadinessStateBitMask_ & TReadinessStateBitMask_AccountInfoReceived_ ) == TReadinessStateBitMask_None_ )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         label7:
            // Assuming that an {::RApi::AccountListInfo} is received from
            // and an order state update subscription request is sent to the same connect point, probably the "trading system" one.
            // yg? In .NET we subscribe for order state updates only after we have connected to all connect points
            // yg? and received an {::RApi::AccountListInfo}. (Is it still the case?)
            // yg? We would need to do the same here
            // yg? if we are to send subscription request to the diamond cutter or any other connect point of that sort.
            // yg? Not checking if we are logged in. In fact, we probably are as we received this info.
            RequestSubscribeOrdersStateUpdateIfNeeded();
         }

         return OK;
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::Poco::Exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::std::exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ... )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
   }

#endif
#if( /* {(public) PriceIncrUpdate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::PriceIncrUpdate
      ( ::RApi::PriceIncrInfo * priceIncrInfo1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      // It's OK if we receive this info multiple times, provided the caller uses locking correctly.
      // Any damage would probably be limited if we receive a different info later.
      // yg? If we receive invalid info later we will simply ignore it.
      // TODO 3 yg? Log this info.

      // Visible universe.
      //    {::OmneException}.
      //       Catch.
      //    {::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {TRApiHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {PriceIncrUpdate} -- base.
      //       Implement.
      //    {ReadinessStateBitMask_}.
      //       Update.
      //    {Instrument_.Symbol()}.
      //       Validate.
      //    {Instrument_.ExchangeAbbreviation()}.
      //       Validate.
      //    {Instrument_.PriceIncrementMinLimit}.
      //       Update.
      //    {priceIncrInfo1->sExchange}.
      //       Validate.
      //    {priceIncrInfo1->sTicker}.
      //       Validate.
      //    {priceIncrInfo1->iArrayLen}.
      //       Use.
      //    {priceIncrInfo1->asPriceIncrArray->dPriceIncr}.
      //       Use.
      //    {priceIncrInfo1->iRpCode}.
      //       Use.

      try
      {
         //::RApi::RCallbacks::...

         // I don't want to assume these.
         {
            assert( Instrument_.ExchangeAbbreviation().compare
                           ( 0U,
                             Instrument_.ExchangeAbbreviation().length(),
                             priceIncrInfo1->sExchange.pData,
                             static_cast< unsigned int >( priceIncrInfo1->sExchange.iDataLen )
                           ) ==
                        0
                     );
            assert( Instrument_.Symbol().compare
                           ( 0U,
                             Instrument_.Symbol().length(),
                             priceIncrInfo1->sTicker.pData,
                             static_cast< unsigned int >( priceIncrInfo1->sTicker.iDataLen )
                           ) ==
                        0
                     );
         }

         {
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            if( priceIncrInfo1->iRpCode == API_OK &&

                // yg? We are not designed to handle a different value.
                priceIncrInfo1->iArrayLen == 1
              )
            {
               // I don't want to assume this.
               assert( priceIncrInfo1->asPriceIncrArray->dPriceIncr > 0.0 );

               Instrument_.PriceIncrementMinLimit = priceIncrInfo1->asPriceIncrArray->dPriceIncr;
               ReadinessStateBitMask_ =
                  static_cast< TReadinessStateBitMask_ >
                     ( ReadinessStateBitMask_ | TReadinessStateBitMask_InstrumentPriceIncrementMinLimitReceived_ );

               {
                  static char const constantString1AsArray[]( "received an {RApi::PriceIncrInfo}" );
                  logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }
            }
            else
            {
               {
                  static char const constantString1AsArray[]( "received an invalid {RApi::PriceIncrInfo}" );
                  logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            }
         }

         return OK;
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::Poco::Exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::std::exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ... )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
   }

#endif
#if( /* {(public) MarketMode}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::MarketMode
      ( ::RApi::MarketModeInfo * marketModeInfo1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      // yg? Currently we only log this info.
      // yg? Not validating exchange, symbol, etc.
      // TODO 3 yg? The strategy needs to be made aware of the instrument's market mode.
      // TODO 3 yg? A simple way to implement this would be to add a trading readiness flag to the instrument class
      // TODO 3 yg? and set it to 1 when {marketModeInfo1->sMarketMode == "Open"}.
      // TODO 3 yg? We might need a separate trading readiness flag for each exchange and/or trade route
      // TODO 3 yg? where the instrument can be traded?
      // TODO 3 yg? Note that a trade route can be "UP" or "DOWN".

      try
      {
         //::RApi::RCallbacks::...

         {
            static char const formatConstantString1AsArray[]( "{RApi::MarketModeInfo}; %.*s; %.*s; %.*s; %u; %s" );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 64
                 + marketModeInfo1->sTicker.iDataLen
                 + marketModeInfo1->sExchange.iDataLen
                 + marketModeInfo1->sMarketMode.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( marketModeInfo1->iSsboe >= 0 );

               assert( marketModeInfo1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStampMicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( marketModeInfo1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( marketModeInfo1->iUsecs )
                    )
               );

            // We will format this as an unsigned.
            // This is probably positive but we will be OK even if this is 0.
            // I don't want to assume this.
            assert( marketModeInfo1->iType >= 0 );

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      marketModeInfo1->sTicker.iDataLen,
                      marketModeInfo1->sTicker.pData,
                      marketModeInfo1->sExchange.iDataLen,
                      marketModeInfo1->sExchange.pData,
                      marketModeInfo1->sMarketMode.iDataLen,
                      marketModeInfo1->sMarketMode.pData,
                      static_cast< unsigned int >( marketModeInfo1->iType ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStampMicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::DateTimeMicrosecondResolutionFormatString
                           )
                        .c_str()
                      )
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            // TODO 3 yg? Some log records should be marked a "Warning" or worse, for example when trading is halted.
            logger1.information( tempString1 );
         }

         return OK;
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::Poco::Exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::std::exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ... )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
   }

#endif
#if( /* {(public) LimitOrderBook}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::LimitOrderBook
      ( ::RApi::LimitOrderBookInfo * limitOrderBookInfo1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

      // yg? This method is believed to be called to invalidate previously received market data, probably among other cases.
      // yg? But it's probably not called when we are subscribed for top of book only.
      // yg? Currently we only log this info as a critical error.
      // yg? Not validating exchange, symbol, etc.

      try
      {
         //::RApi::RCallbacks::...

         {
            static char const formatConstantString1AsArray[]( "{RApi::LimitOrderBookInfo}; %.*s; %.*s; %u; %u; %u; %i; %.*s; %s" );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 128
                 + limitOrderBookInfo1->sTicker.iDataLen
                 + limitOrderBookInfo1->sExchange.iDataLen
                 + limitOrderBookInfo1->sRpCode.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( limitOrderBookInfo1->iSsboe >= 0 );

               assert( limitOrderBookInfo1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStampMicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( limitOrderBookInfo1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( limitOrderBookInfo1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( limitOrderBookInfo1->iAskArrayLen >= 0 );
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( limitOrderBookInfo1->iBidArrayLen >= 0 );

               // This is probably positive but we will be OK even if this is 0.
               // I don't want to assume this.
               assert( limitOrderBookInfo1->iType >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      limitOrderBookInfo1->sTicker.iDataLen,
                      limitOrderBookInfo1->sTicker.pData,
                      limitOrderBookInfo1->sExchange.iDataLen,
                      limitOrderBookInfo1->sExchange.pData,
                      static_cast< unsigned int >( limitOrderBookInfo1->iAskArrayLen ),
                      static_cast< unsigned int >( limitOrderBookInfo1->iBidArrayLen ),
                      static_cast< unsigned int >( limitOrderBookInfo1->iType ),

                      // This is probably not negative but I don't want to format this as an unsigned. We still don't format the '+' sign.
                      limitOrderBookInfo1->iRpCode,

                      limitOrderBookInfo1->sRpCode.iDataLen,
                      limitOrderBookInfo1->sRpCode.pData,

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStampMicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      )
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            // yg? Some log records should be marked a "Warning" or worse. For example based on {limitOrderBookInfo1->iRpCode}.
            // yg? This is currently "Critical" because this callback is not supposed to be called.
            logger1.critical( tempString1 );
         }

         return OK;
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::Poco::Exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::std::exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ... )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
   }

#endif
#if( /* {(public) BestBidQuote}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::BestBidQuote
      ( ::RApi::BidInfo * bidInfo1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      // yg? See a logging related comment in {TradePrint} body.
      // See in the R|API help: "F.A.Q. - R | Trade Execution Platform(tm)",
      // "What is the meaning of AskInfo::bPriceFlag, AskInfo::bSizeFlag, BidInfo::bPriceFlag and BidInfo::bSizeFlag?".

      // Visible universe.
      //    {::OmneException}.
      //       Catch.
      //    {::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {TRApiHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {BestBidQuote} -- base.
      //       Implement.
      //    {Instrument_.Symbol()}.
      //       Validate.
      //    {Instrument_.ExchangeAbbreviation()}.
      //       Validate.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.RaiseOnReceivedData}.
      //       Call.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Bid.Quantity}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Bid.Price}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Bid.NumberOrders}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.SendingDateTimeStampMillisecondsSince1970}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask}.
      //       Update.
      //    {SafeTryValidateInstrumentPrice}.
      //       Call.
      //    {bidInfo1->sTicker}.
      //       Validate.
      //    {bidInfo1->sExchange}.
      //       Validate.
      //    {bidInfo1->dPrice}.
      //       Use.
      //    {bidInfo1->bPriceFlag}.
      //       Use.
      //    {bidInfo1->iSize}.
      //       Use.
      //    {bidInfo1->bSizeFlag}.
      //       Validate.
      //    {bidInfo1->iNumOrders}.
      //       Use.
      //    {bidInfo1->iUpdateType}.
      //       Validate.
      //    {bidInfo1->iType}.
      //       Use.
      //    {bidInfo1->iSsboe}.
      //       Use.
      //    {bidInfo1->iUsecs}.
      //       Use.

      try
      {
         //::RApi::RCallbacks::...

         // I don't want to assume these.
         {
            assert( Instrument_.Symbol().compare
                           ( 0U,
                             Instrument_.Symbol().length(),
                             bidInfo1->sTicker.pData,
                             static_cast< unsigned int >( bidInfo1->sTicker.iDataLen )
                           ) ==
                        0
                     );

            // yg? Is it safe to assert this? Can market data come from another exchange?
            assert( Instrument_.ExchangeAbbreviation().compare
                           ( 0U,
                             Instrument_.ExchangeAbbreviation().length(),
                             bidInfo1->sExchange.pData,
                             static_cast< unsigned int >( bidInfo1->sExchange.iDataLen )
                           ) ==
                        0
                     );

            // This matters in {BidQuote} but not in {BestBidQuote}.
            // See in the R|API help: "F.A.Q. - R | Trade Execution Platform(tm)",
            // "How do I maintain an order book? (Or, how do I use update types with AskInfo, BidInfo and EndQuoteInfo?)".
            assert( bidInfo1->iUpdateType == ::RApi::UPDATE_TYPE_UNDEFINED );

            assert( bidInfo1->bPriceFlag == bidInfo1->bSizeFlag );
         }

         if( bidInfo1->bPriceFlag )
         {
   #if( ! defined( NDEBUG ) )
            // yg? Logging this before the data itself.
            SafeTryValidateInstrumentPrice( bidInfo1->dPrice );
   #endif

            // I don't want to assume these.
            // TODO 2 yg? Check this in the log.
            {
               // yg? Although multileg instruments can trade at non-positive prices we don't currently trade those.
               // TODO 2 yg? Maybe remove this validation.
               assert( bidInfo1->dPrice > 0.0 );

               // As we don't check {bidInfo1->bSizeFlag}, this validation can potentially fail
               // but I want to believe that {bidInfo1->iSize >= 0}, even if {! bidInfo1->bSizeFlag}.
               assert( bidInfo1->iSize > 0 );

               // yg? I've seen this being 0.
               assert( bidInfo1->iNumOrders >= 0 );
            }

            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Bid.Price = bidInfo1->dPrice;
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Bid.Quantity =
               static_cast< double >( bidInfo1->iSize );
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Bid.NumberOrders =
               bidInfo1->iNumOrders;
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask =
               ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllBid;

            // I don't want to assume this.
            assert( bidInfo1->iType == ::RApi::MD_UPDATE_CB || bidInfo1->iType == ::RApi::MD_IMAGE_CB );

            if( bidInfo1->iType != ::RApi::MD_UPDATE_CB )
            {
               goto label4;
            }
            else
            {
               InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask =
                  static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
                     ( InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask |
                       ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllBid
                     );
            }
         }
         else
         {
            // TODO 2 yg? Check this in the log.
            {
               static char const constantString1AsArray[]( "{bidInfo1->bPriceFlag == false}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }

            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         label4:
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask =
               static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
                  ( InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask &
                    ( ~ ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllBid )
                  );

// TODO Possible bug: we don't update {....LastUpdatedItemsBitMask} here and as a result is shows its previous value in the log.
         }

         // yg? See related comments in {TradePrint}.
         {
            assert( bidInfo1->iSsboe >= 0 );
            assert( bidInfo1->iUsecs >= 0 );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::UInt64 dateTimeStampMicrosecondsSince1970
               ( static_cast< unsigned int >( bidInfo1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                 static_cast< unsigned int >( bidInfo1->iUsecs )
               );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::MILLISECONDS == 1000 );
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.SendingDateTimeStampMillisecondsSince1970 =
               static_cast< double >( dateTimeStampMicrosecondsSince1970 ) *
               ( 1.0 / static_cast< double >( ::Poco::Timespan::MILLISECONDS ) );
         }

         InstrumentBestAggregatedBidAskQuoteSubscription_.RaiseOnReceivedData();
         return OK;
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::Poco::Exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::std::exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ... )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
   }

#endif
#if( /* {(public) BestAskQuote}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::BestAskQuote
      ( ::RApi::AskInfo * askInfo1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      // yg? See a logging related comment in {TradePrint} body.
      // See in the R|API help: "F.A.Q. - R | Trade Execution Platform(tm)",
      // "What is the meaning of AskInfo::bPriceFlag, AskInfo::bSizeFlag, BidInfo::bPriceFlag and BidInfo::bSizeFlag?".

      // Visible universe.
      //    {::OmneException}.
      //       Catch.
      //    {::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {TRApiHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {BestAskQuote} -- base.
      //       Implement.
      //    {Instrument_.Symbol()}.
      //       Validate.
      //    {Instrument_.ExchangeAbbreviation()}.
      //       Validate.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.RaiseOnReceivedData}.
      //       Call.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Ask.Quantity}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Ask.Price}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Ask.NumberOrders}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.SendingDateTimeStampMillisecondsSince1970}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask}.
      //       Update.
      //    {InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask}.
      //       Update.
      //    {SafeTryValidateInstrumentPrice}.
      //       Call.
      //    {askInfo1->sTicker}.
      //       Validate.
      //    {askInfo1->sExchange}.
      //       Validate.
      //    {askInfo1->dPrice}.
      //       Use.
      //    {askInfo1->bPriceFlag}.
      //       Use.
      //    {askInfo1->iSize}.
      //       Use.
      //    {askInfo1->bSizeFlag}.
      //       Validate.
      //    {askInfo1->iNumOrders}.
      //       Use.
      //    {askInfo1->iUpdateType}.
      //       Validate.
      //    {askInfo1->iType}.
      //       Use.
      //    {askInfo1->iSsboe}.
      //       Use.
      //    {askInfo1->iUsecs}.
      //       Use.

      try
      {
         //::RApi::RCallbacks::...

         // I don't want to assume these.
         {
            assert( Instrument_.Symbol().compare
                           ( 0U,
                             Instrument_.Symbol().length(),
                             askInfo1->sTicker.pData,
                             static_cast< unsigned int >( askInfo1->sTicker.iDataLen )
                           ) ==
                        0
                     );

            // yg? Is it safe to assert this? Can market data come from another exchange?
            assert( Instrument_.ExchangeAbbreviation().compare
                           ( 0U,
                             Instrument_.ExchangeAbbreviation().length(),
                             askInfo1->sExchange.pData,
                             static_cast< unsigned int >( askInfo1->sExchange.iDataLen )
                           ) ==
                        0
                     );

            // This matters in {AskQuote} but not in {BestAskQuote}.
            // See in the R|API help: "F.A.Q. - R | Trade Execution Platform(tm)",
            // "How do I maintain an order book? (Or, how do I use update types with AskInfo, BidInfo and EndQuoteInfo?)".
            assert( askInfo1->iUpdateType == ::RApi::UPDATE_TYPE_UNDEFINED );

            assert( askInfo1->bPriceFlag == askInfo1->bSizeFlag );
         }

         if( askInfo1->bPriceFlag )
         {
   #if( ! defined( NDEBUG ) )
            // yg? Logging this before the data itself.
            SafeTryValidateInstrumentPrice( askInfo1->dPrice );
   #endif

            // I don't want to assume these.
            // TODO 2 yg? Check this in the log.
            {
               // yg? Although multileg instruments can trade at non-positive prices we don't currently trade those.
               // TODO 2 yg? Maybe remove this validation.
               assert( askInfo1->dPrice > 0.0 );

               // As we don't check {askInfo1->bSizeFlag}, this validation can potentially fail
               // but I want to believe that {askInfo1->iSize >= 0}, even if {! askInfo1->bSizeFlag}.
               assert( askInfo1->iSize > 0 );

               // yg? I've seen this being 0.
               assert( askInfo1->iNumOrders >= 0 );
            }

            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Ask.Price = askInfo1->dPrice;
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Ask.Quantity =
               static_cast< double >( askInfo1->iSize );
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Ask.NumberOrders =
               askInfo1->iNumOrders;
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask =
               ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllAsk;

            // I don't want to assume this.
            assert( askInfo1->iType == ::RApi::MD_UPDATE_CB || askInfo1->iType == ::RApi::MD_IMAGE_CB );

            if( askInfo1->iType != ::RApi::MD_UPDATE_CB )
            {
               goto label5;
            }
            else
            {
               InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask =
                  static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
                     ( InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask |
                       ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllAsk
                     );
            }
         }
         else
         {
            // TODO 2 yg? Check this in the log.
            {
               static char const constantString1AsArray[]( "{askInfo1->bPriceFlag == false}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }

            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         label5:
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask =
               static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
                  ( InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask &
                    ( ~ ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllAsk )
                  );

// TODO Possible bug: we don't update {....LastUpdatedItemsBitMask} here and as a result is shows its previous value in the log.
         }

         // yg? See related comments in {TradePrint}.
         {
            assert( askInfo1->iSsboe >= 0 );
            assert( askInfo1->iUsecs >= 0 );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::UInt64 dateTimeStampMicrosecondsSince1970
               ( static_cast< unsigned int >( askInfo1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                 static_cast< unsigned int >( askInfo1->iUsecs )
               );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::MILLISECONDS == 1000 );
            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.SendingDateTimeStampMillisecondsSince1970 =
               static_cast< double >( dateTimeStampMicrosecondsSince1970 ) *
               ( 1.0 / static_cast< double >( ::Poco::Timespan::MILLISECONDS ) );
         }

         InstrumentBestAggregatedBidAskQuoteSubscription_.RaiseOnReceivedData();
         return OK;
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::Poco::Exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::std::exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ... )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
   }


   // Old version.
   //
   //int TREngineAdapter::BestAskQuote
   //   ( ::RApi::AskInfo * askInfo1,
   //     void * /*context1*/,
   //     int * /*outcomeCode2*/
   //   )
   //{
   //   // yg? Not logging anything -- assuming an event listener will.
   //   // TODO 3 yg? We need to log all fields here. And we need the date-time keeper here to log the timing.
   //
   //   try
   //   {
   //      //::RApi::RCallbacks::...
   //
   //#if( ! defined( NDEBUG ) )
   //      // yg? Another test of {askInfo1->bPriceFlag} is inefficient and that's OK as this occurs in debug build only.
   //      if( askInfo1->bPriceFlag )
   //
   //      {
   //         // yg? Logging this before the data itself.
   //         SafeTryValidateInstrumentPrice( askInfo1->dPrice );
   //      }
   //#endif
   //
   //      {
   //         // yg? Can we use an instrinsic to set bits?
   //         ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask instrumentBestAggregatedBidAskQuoteItemsValidityBitMask1( InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask );
   //         instrumentBestAggregatedBidAskQuoteItemsValidityBitMask1 =
   //            static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
   //               ( instrumentBestAggregatedBidAskQuoteItemsValidityBitMask1 &
   //                 ( ~ ( ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskPrice | ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskQuantity ) )
   //               );
   //
   //         if( askInfo1->iType == ::RApi::MD_UPDATE_CB )
   //         {
   //            instrumentBestAggregatedBidAskQuoteItemsValidityBitMask1 =
   //               static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
   //                  ( instrumentBestAggregatedBidAskQuoteItemsValidityBitMask1 |
   //                    ( static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >( askInfo1->bPriceFlag ) * ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskPrice ) |
   //                    ( static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >( askInfo1->bSizeFlag ) * ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskQuantity )
   //                  );
   //         }
   //         else
   //         {
   //            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //         }
   //         InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask = instrumentBestAggregatedBidAskQuoteItemsValidityBitMask1;
   //      }
   //
   //      {
   //         ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask instrumentBestAggregatedBidAskQuoteLastUpdatedItemsBitMask1( ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_None );
   //         if( askInfo1->bPriceFlag )
   //         {
   //            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Ask.Price = askInfo1->dPrice;
   //            instrumentBestAggregatedBidAskQuoteLastUpdatedItemsBitMask1 = /*instrumentBestAggregatedBidAskQuoteLastUpdatedItemsBitMask1 |*/ ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskPrice;
   //         }
   //         else
   //         {
   //            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //         }
   //         if( askInfo1->bSizeFlag )
   //         {
   //            // yg? Can this validation fail?
   //            assert( askInfo1->iType != ::RApi::MD_UPDATE_CB || askInfo1->iSize > 0 );
   //
   //            InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Ask.Quantity = static_cast< double >( askInfo1->iSize );
   //            instrumentBestAggregatedBidAskQuoteLastUpdatedItemsBitMask1 =
   //               static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >( instrumentBestAggregatedBidAskQuoteLastUpdatedItemsBitMask1 | ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskQuantity );
   //         }
   //         else
   //         {
   //            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //         }
   //         InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask = instrumentBestAggregatedBidAskQuoteLastUpdatedItemsBitMask1;
   //      }
   //
   //      // yg? Based on R|API docs, this timestamp indicates the receipt time of this message from the market data provider.
   //      // yg? So this really is not sending date-time.
   //      // yg? Do we need a helper method for this, like in .NET?
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //      ::Poco::Int64 dateTimeStampMicrosecondsSince1970( askInfo1->iSsboe * ::Poco::Timespan::SECONDS + askInfo1->iUsecs );
   //      InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.SendingDateTimeStampMillisecondsSince1970 =
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //         //static_cast< double >( askInfo1->iSsboe * ( ::Poco::Timespan::SECONDS / ::Poco::Timespan::MILLISECONDS ) )
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //         //+ ( static_cast< double >( askInfo1->iUsecs ) / static_cast< double >( ::Poco::Timespan::MILLISECONDS ) );
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
   //         static_cast< double >( dateTimeStampMicrosecondsSince1970 ) / static_cast< double >( ::Poco::Timespan::MILLISECONDS );
   //
   //      InstrumentBestAggregatedBidAskQuoteSubscription_.RaiseOnReceivedData();
   //
   //#if( 0 )
   //      #pragma message( "yg---?? Test." )
   //      {
   //         // yg? Inefficient. Use {wprintf}.
   //         ::std::cout << ( ( askInfo1->iUpdateType == ::RApi::UPDATE_TYPE_UNDEFINED ) ? /*"{askInfo1->iUpdateType} is correct\r\n"*/ "+" : "\r\n{askInfo1->iUpdateType} is incorrect\r\n" );
   //      }
   //#endif
   //
   //#if( 0 )
   //      #pragma message( "yg---?? Test." )
   //      {
   //         if( ( instrumentBestAggregatedBidAskQuoteItemsValidityBitMask1 & ( ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidPrice | ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskPrice ) ) == ( ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidPrice | ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskPrice ) )
   //         {
   //            ::Poco::Timestamp timeStamp1;
   //            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //
   //            // yg? This is inefficient.
   //            // yg? Using current thread locale.
   //            logger1.information( ::Poco::NumberFormatter::format( askInfo1->iSsboe * static_cast< ::Poco::Int64 >( 1000 ) + askInfo1->iUsecs / 1000.0 - timeStamp1.epochMicroseconds() / 1000.0 ) );
   //         }
   //      }
   //#endif
   //
   //      return OK;
   //   }
   //   //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
   //   catch( ::OmneException const & exception1 )
   //   {
   //      TRApiHelpers::AtomicLastChanceHandleException( exception1 );
   //      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   //   }
   //   catch( ::Poco::Exception const & exception1 )
   //   {
   //      ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
   //      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   //   }
   //   catch( ::std::exception const & exception1 )
   //   {
   //      ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
   //      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   //   }
   //   catch( ... )
   //   {
   //      ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
   //      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   //   }
   //}

#endif
#if( /* //{(public) TradeCondition}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //int TREngineAdapter::TradeCondition
   //   ( ::RApi::TradeInfo * tradeInfo1,
   //     void * /*context1*/,
   //     int * /*outcomeCode2*/
   //   )
   //{
   //   try
   //   {
   //      //::RApi::RCallbacks::...
   //
   //      //{
   //      //   static char const constantString1AsArray[]( "received a conditional {RApi::TradeInfo}" );
   //      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      //   logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //      //}
   //
   //      ProcessTradeInfo( ( * tradeInfo1 ), true );
   //
   //      return OK;
   //   }
   //   //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
   //   catch( ::OmneException const & exception1 )
   //   {
   //      TRApiHelpers::AtomicLastChanceHandleException( exception1 );
   //      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   //   }
   //   catch( ::Poco::Exception const & exception1 )
   //   {
   //      ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
   //      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   //   }
   //   catch( ::std::exception const & exception1 )
   //   {
   //      ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
   //      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   //   }
   //   catch( ... )
   //   {
   //      ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
   //      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   //   }
   //}

#endif
#if( /* {(public) TradePrint}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::TradePrint
      ( ::RApi::TradeInfo * tradeInfo1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      // yg? Not logging anything -- assuming an event listener will.
      // TODO 3 yg? We need to log all fields here.
      // TODO 3 yg? And we need the date-time keeper in this class to log the timing.
      // TODO 3 yg? This also applies to some/all other callbacks that come with a date-time-stamp.

      // Visible universe.
      //    {::OmneException}.
      //       Catch.
      //    {::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {TRApiHelpers::AtomicLastChanceHandleException}.
      //       Call.
      //    {TradePrint} -- base.
      //       Implement.
      //    {Instrument_.Symbol()}.
      //       Validate.
      //    {Instrument_.ExchangeAbbreviation()}.
      //       Validate.
      //    {InstrumentTradeSubscription_.RaiseOnReceivedData}.
      //       Call.
      //    {InstrumentTradeSubscription_.InstrumentTrade.QuantityAndPrice.Quantity}.
      //       Update.
      //    {InstrumentTradeSubscription_.InstrumentTrade.QuantityAndPrice.Price}.
      //       Update.
      //    {InstrumentTradeSubscription_.InstrumentTrade.GenerationDateTimeStampMillisecondsSince1970}.
      //       Update.
      //    {InstrumentTradeSubscription_.InstrumentTrade.SendingDateTimeStampMillisecondsSince1970}.
      //       Update.
      //    {InstrumentTradeSubscription_.InstrumentTrade.IsValid}.
      //       Update.
      //    {SafeTryValidateInstrumentPrice}.
      //       Call.
      //    {tradeInfo1->sTicker}.
      //       Validate.
      //    {tradeInfo1->sExchange}.
      //       Validate.
      //    {tradeInfo1->dPrice}.
      //       Use.
      //    {tradeInfo1->bPriceFlag}.
      //       Use.
      //    {tradeInfo1->iSize}.
      //       Use.
      //    //{tradeInfo1->sAggressorSide}.
      //       yg? Ignore. Should we use or log this?
      //    {tradeInfo1->sCondition}.
      //       Validate.
      //    {tradeInfo1->iType}.
      //       Use.
      //    {tradeInfo1->iSourceSsboe}.
      //       Use.
      //    {tradeInfo1->iSourceUsecs}.
      //       Use.
      //    {tradeInfo1->iSsboe}.
      //       Use.
      //    {tradeInfo1->iUsecs}.
      //       Use.

      try
      {
         //::RApi::RCallbacks::...

         //ProcessTradeInfo( ( * tradeInfo1 ), false );

         // I don't want to assume these.
         {
            assert( Instrument_.Symbol().compare
                           ( 0U,
                             Instrument_.Symbol().length(),
                             tradeInfo1->sTicker.pData,
                             static_cast< unsigned int >( tradeInfo1->sTicker.iDataLen )
                           ) ==
                        0
                     );

            // yg? Is it safe to assert this? Can market data come from another exchange?
            assert( Instrument_.ExchangeAbbreviation().compare
                           ( 0U,
                             Instrument_.ExchangeAbbreviation().length(),
                             tradeInfo1->sExchange.pData,
                             static_cast< unsigned int >( tradeInfo1->sExchange.iDataLen )
                           ) ==
                        0
                     );

            assert( tradeInfo1->sCondition.iDataLen == 0 );
         }

         if( tradeInfo1->bPriceFlag )
         {
   #if( ! defined( NDEBUG ) )
            // yg? Logging this before the data itself.
            SafeTryValidateInstrumentPrice( tradeInfo1->dPrice );
   #endif

            // I don't want to assume these.
            // TODO 2 yg? Check this in the log.
            {
               // yg? Although multileg instruments can trade at non-positive prices we don't currently trade those.
               // TODO 2 yg? Maybe remove this validation.
               assert( tradeInfo1->dPrice > 0.0 );

               assert( tradeInfo1->iSize > 0 );
            }

            InstrumentTradeSubscription_.InstrumentTrade.QuantityAndPrice.Price = tradeInfo1->dPrice;
            InstrumentTradeSubscription_.InstrumentTrade.QuantityAndPrice.Quantity = static_cast< double >( tradeInfo1->iSize );

            // I don't want to assume this.
            assert( tradeInfo1->iType == ::RApi::MD_UPDATE_CB || tradeInfo1->iType == ::RApi::MD_IMAGE_CB );

            if( tradeInfo1->iType != ::RApi::MD_UPDATE_CB )
            {
               goto label6;
            }
            else
            {
               InstrumentTradeSubscription_.InstrumentTrade.IsValid = true;
            }
         }
         else
         {
            // yg? We should really never get to this point but I've seen this happening between trading sessions.

            // TODO 2 yg? Check this in the log. (As I said, I've already observed this.)
            {
               static char const constantString1AsArray[]( "{tradeInfo1->bPriceFlag == false}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }

            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         label6:
            InstrumentTradeSubscription_.InstrumentTrade.IsValid = false;
         }

         // yg? Some of the comments some 25 lines below apply here as well.
         {
            // yg? R|API release notes says that this is "timestamp values as presented by the exchange, if available".
            // yg? It's unclear if this is market data generation time or sending time.
            // yg? In any case we have only 1 field to assign this date-time-stamp to.
            assert( tradeInfo1->iSourceSsboe >= 0 );
            assert( tradeInfo1->iSourceUsecs >= 0 );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::UInt64 dateTimeStampMicrosecondsSince1970
               ( static_cast< unsigned int >( tradeInfo1->iSourceSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                 static_cast< unsigned int >( tradeInfo1->iSourceUsecs )
               );

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::MILLISECONDS == 1000 );
            InstrumentTradeSubscription_.InstrumentTrade.GenerationDateTimeStampMillisecondsSince1970 =
               static_cast< double >( dateTimeStampMicrosecondsSince1970 ) *
               ( 1.0 / static_cast< double >( ::Poco::Timespan::MILLISECONDS ) );
         }

         {
            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( tradeInfo1->iSsboe >= 0 );

               assert( tradeInfo1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );

            // yg? Based on R|API help, "this timestamp indicates the receipt time of this message from the market data provider".
            // yg? So this really is not sending date-time.
            // TODO 3 yg? So revisit this.
            // yg? Do we need a helper method for this, like in .NET?
            // This can't overflow, as validated.
            ::Poco::UInt64 dateTimeStampMicrosecondsSince1970
               ( static_cast< unsigned int >( tradeInfo1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                 static_cast< unsigned int >( tradeInfo1->iUsecs )
               );

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::MILLISECONDS == 1000 );
            InstrumentTradeSubscription_.InstrumentTrade.SendingDateTimeStampMillisecondsSince1970 =
               static_cast< double >( dateTimeStampMicrosecondsSince1970 ) *
               ( 1.0 / static_cast< double >( ::Poco::Timespan::MILLISECONDS ) );
         }

         InstrumentTradeSubscription_.RaiseOnReceivedData();
         return OK;
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::Poco::Exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::std::exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ... )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
   }

#endif
#if( /* {(public) LineUpdate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO validate this?:
//            Common.Core.ConditionValidation.ConditionValidationHelpers.ValidateValueEquals
//               ( string.IsNullOrEmpty( lineInfo1.CompletionReason ), ( lineInfo1.Status != com.omnesys.rapi.Constants.LINE_STATUS_COMPLETE ) );

//TODO I commented this out to suppress compile errors.
//   int TREngineAdapter::LineUpdate
//      ( ::RApi::LineInfo * lineInfo1,
//        void * /*context1*/,
//        int * /*outcomeCode2*/
//      )
//   {
//      #pragma region
//
//      // Visible universe.
//      // The following items apply to both {LineUpdate} and all order report callbacks.
//      //    {::OmneException}.
//      //       Catch.
//      //    {::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException}.
//      //       Call.
//      //    {TRApiHelpers::OrderNumberNone}.
//      //       Validate.
//      //    {TRApiHelpers::OrderReportTextAtomicOrderOperationInProgressAsArray}.
//      //       Use in {FailureReport}.
//      //    {TRApiHelpers::OrderReportTextAtomicOrderOperationInProgressLength}.
//      //       Use in {FailureReport}.
//      //    {TRApiHelpers::AtomicLastChanceHandleException}.
//      //       Call.
//      //    {TRApiHelpers::TSNCharcbsEqual}.
//      //       Call in {LineUpdate}, {FailureReport}.
//      //    {TRApiHelpers::TSNCharcbEqual}.
//      //       Call in {FailureReport}.
//      //    {LineUpdate} -- base.
//      //       Implement in {LineUpdate}.
//      //    {SingleInstrumentsOrders_.find}.
//      //       Call.
//      //    {SingleInstrumentsOrders_.find(...).second->RaiseOnReceivedData}.
//      //       Call.
//      //    //{SingleInstrumentsOrders_.find(...).second->TypeCode}.
//      //       Ignore.
//      //       It would be incorrect to use this in any logic as the caller can set this to an arbitrary value
//      //       and send an order modification request, and do it multiple times.
//      //       {lineInfo1->sOrderType} and {::RApi::OrderReport::sOrderType} should be used if needed.
//      //    {SingleInstrumentsOrders_.find(...).second->StateBitMask}.
//      //       Validate in all order report callbacks.
//      //       Use, update.
//      //    {SingleInstrumentsOrders_.find(...).second->BrokerGeneratedId}.
//      //       Validate, update.
//      //    {SingleInstrumentsOrders_.find(...).second->FilledQuantityAndPrice}.
//      //       Validate in all/most order report callbacks.
//      //       Update in {FillReport}, {TradeCorrectReport}, {BustReport}.
//      //    {SingleInstrumentsOrders_.find(...).second->LastModificationRequestId}.
//      //       Use in {FailureReport}, {NotModifiedReport}, {ModifyReport}.
//      //    {SingleInstrumentsOrders_.find(...).second->LastCancellationRequestIdMatches}.
//      //       Call in {FailureReport}.
////TODO now also {LineUpdate}.
//      //    {SingleInstrumentsOrders_.find(...).second->LastCancellationRequestIdMatchesLoosely}.
//      //       Call and validate return value in {FailureReport}.
////TODO now also {LineUpdate}.
//      //       Call in {NotCancelledReport}, {CancelReport}.
////TODO not any more?
//      //    {SafeTryValidateInstrumentPrice}.
//      //       Call in {FillReport}, {TradeCorrectReport}, {BustReport}.
//      //    {InternalCanCancelOrder}.
//      //       Call in {FailureReport}.
//      //    {ShallAndInternalCanCancelOrder}.
//      //       Call in {FailureReport}.
//      //    {RequestCancelOrder}.
//      //       Call in {FailureReport}.
//      //    {RequestCancelOrderIfInternalCan}.
//      //       Call in {NotCancelledReport}.
//      //    {RequestCancelOrderIfInternalShallAndCan}.
//      //       Call in {LineUpdate}, {StatusReport}, {NotModifiedReport},  {ModifyReport}.
//      //    {::RApi::OrderReport::iOrderNum}.
//      //       Validate, use.
//      //    //{::RApi::OrderReport::sExchOrdId}.
//      //       Ignore.
//      //       yg? See {lineInfo1->sExchOrdId} comment.
//      //    //{::RApi::OrderReport::sOrderType}.
//      //       Ignore.
//      //       See {lineInfo1->sOrderType} comment.
//      //    {::RApi::OrderReport::iTotalFilled}.
//      //       Validate in all order report callbacks.
//      //       Use in {FillReport}, {TradeCorrectReport}, {BustReport}.
//      //    {::RApi::OrderReport::iTotalUnfilled}.
//      //       Validate in all order report callbacks.
//      //       Use in {ModifyReport}, {FillReport}.
//      //       Just like {lineInfo1->iUnfilled}, expecting this to be negative.
//      //    {::RApi::OrderReport::dAvgFillPrice}.
//      //       Validate in all/most order report callbacks.
//      //       Use in {FillReport}, {TradeCorrectReport}, {BustReport}.
//      //    {::RApi::OrderReport::bAvgFillPriceFlag}.
//      //       Validate in all order report callbacks.
//      //       Assuming that this is equivalent to {::RApi::OrderReport::iTotalFilled > 0}.
//      //    {::RApi::OrderReport::sText}.
//      //       Use in {FailureReport}.
//      //    {::RApi::OrderReport::sUserMsg}.
//      //       Use in {FailureReport}, {NotModifiedReport}, {ModifyReport}, {NotCancelledReport}, {CancelReport}.
////TODO not any more in {NotCancelledReport}, {CancelReport}.
//      //    {::RApi::OrderReport::pContext}.
//      //       Use.
//      //    //{::RApi::OrderReport::bPossOutOfOrder}.
//      //       yg? Ignore.
//      //       yg? See {lineInfo1->bPossOutOfOrder} comment.
//      //    //{::RApi::OrderReport::iGatewayBufferBytesBehind}.
//      //       Ignore.
//      //    //{::RApi::OrderReport::iGatewaySsboe}.
//      //       Ignore.
//      //    //{::RApi::OrderReport::iGatewayUsecs}.
//      //       Ignore.
//      //    //{::RApi::OrderReport::iSsboe}.
//      //       Ignore.
//      //    //{::RApi::OrderReport::iUsecs}.
//      //       Ignore.
//      //    {::RApi::OrderReport::...}.
//      //       Possibly log some other fields.
//      // The following items apply to {LineUpdate} only.
//      //    {lineInfo1->iOrderNum}.
//      //       Validate, use.
//      //    //{lineInfo1->sExchOrdId}.
//      //       Ignore.
//      //       This is not empty when the order is known to the exchange,
//      //       so it might be possible to use this to set some order state bits and other variables, but such a logic might be unreliable.
//      //       yg? If market data also contained this field we would be able to see which market data items are our own.
//      //    //{lineInfo1->sOrderType}.
//      //       Ignore.
//      //       This is not always confirmed by the exchange.
//      //       This can change over the lifetime of an order, even if the app doesn't request to modify order type.
//      //       This can potentially be {::RApi::sORDER_TYPE_EXTERNAL}.
//      //       When a "stop-market" order trigger condition occurs, it becomes "limit".
//      //       When a "market-if-touched" order trigger condition occurs, it briefly becomes "market",
//      //       and then reverts back to "market-if-touched".
//      //       But this behavior can depend on the exchange.
//      //       See {SingleInstrumentsOrders_.find(...).second->TypeCode} comment.
//      //    //{lineInfo1->sStatus}.
//      //       Ignore.
////TODO now using in {LineUpdate}?
//      //    {lineInfo1->sCompletionReason}.
//      //       Use.
//      //    //{lineInfo1->sUserMsg}.
//      //       Ignore.
//      //    {lineInfo1->pContext}.
//      //       Use.
//      //    //{lineInfo1->iGatewayBufferBytesBehind}.
//      //       Ignore.
//      //    //{lineInfo1->iGatewaySsboe}.
//      //       Ignore.
//      //    //{lineInfo1->iGatewayUsecs}.
//      //       Ignore.
//      //    //{lineInfo1->iSsboe}.
//      //       Ignore.
//      //    //{lineInfo1->iUsecs}.
//      //       Ignore.
//      //    //{lineInfo1->iQuantityToFill}.
//      //       Ignore.
//      //       One not necessarily safe way to check if the order is "probably" completed:
//      //       {iQuantityToFill > 0 && iQuantityToFill <= iFilled}.
//      //    {lineInfo1->iFilled}.
//      //       Validate, use.
//      //    {lineInfo1->iUnfilled}.
//      //       Validate, use.
//      //       If a modification to a smaller quantity succeeds this probably can become 0, or maybe even negative, which we expect.
//      //    {lineInfo1->iCancelled}.
//      //       Validate, use.
//      //       Just like {lineInfo1->iUnfilled}, expecting this to be negative.
//      //    {lineInfo1->iCancelPendingSize}.
//      //       Validate, use.
//      //       Just like {lineInfo1->iUnfilled}, expecting this to be negative.
//      //    //{lineInfo1->dAvgFillPrice}.
//      //       Ignore.
//      //    //{lineInfo1->bAvgFillPriceFlag}.
//      //       Ignore.
//      //    //{lineInfo1->bPossOutOfOrder}.
//      //       yg? Ignore.
//      //       TODO 3 yg? Handle this somehow.
//      //    {lineInfo1->iRpCode}.
//      //       yg? We only use this in some logic that doesn't affect the behavior.
//      //       TODO 3 yg? Handle this somehow.
//      //    {lineInfo1->...}.
//      //       Possibly log some other fields.
//
//      #pragma endregion
//      #pragma region
//
//      try
//      {
//         #pragma region
//
//         //::RApi::RCallbacks::...
//
//         #pragma endregion
//         #pragma region
//
//         // I don't want to assume these.
//         assert( lineInfo1->iOrderNum != TRApiHelpers::OrderNumberNone );
//         assert( lineInfo1->iFilled >= 0 );
//
//         // All this logic assumes that order modification and cancellation applies to the whole unfilled quantity.
//         // Assuming that it's impossible for example that a part of unfilled quantity was cancelled and another one can still be filled.
//         // Note that it's probably possible to modify (really cancel and replace) an order to a smaller quantity
//         // but that is not supposed to make {lineInfo1->iCancelled} a nonzero.
//         // TODO 3 yg? Test this assumption. Remember to test the "if-touched" orders.
//         // See comments related to these fields in the visible universe.
//         // I don't want to assume these.
//         assert( lineInfo1->iUnfilled == 0 || lineInfo1->iCancelled == 0 );
//         assert( lineInfo1->iCancelPendingSize == 0 || lineInfo1->iCancelled == 0 );
//
//         #pragma endregion
//         #pragma region
//
//         {
//            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
//               ( SingleInstrumentsOrders_.find( lineInfo1->pContext ) );
//
//            if( orderPairIterator != SingleInstrumentsOrders_.end() &&
//
//                // yg? Let's make sure we actually sent this order.
//                // yg? This is a really weak protection from someone's order context matching ours, and it adds to the overhead.
//                // yg? However it ensures some little things:
//                // yg? 1. The order {StateBitMask} (and other data) will not get corrupt.
//                // yg?     One implication of this is that the {..._ASSUME} validation
//                // yg?     in the {TSingleInstrumentOrder::PrepareSend} method will succeed.
//                // yg? 2. We will not attempt to re-cancel someone's order before we are fully ready,
//                // yg?     in particular before we populate {AccountInfoContainer_}.
//                // yg? 3. We will not raise events before listeners are ready to handle them.
//                // yg? A more robust solution would probably involve splitting {SingleInstrumentsOrders_} into multiple collections.
//                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
//              )
//            {
//               #pragma region
//
//               // This reassures that we actually sent this order.
//               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
//                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
//                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                                                                                    )
//                                                                                                  ) !=
//                                                                                                  TOrderStateBitMask_None
//                                                                                               );
//
//               // I don't want to assume these.
//               //assert( ( orderPairIterator->second->StateBitMask & ...
//               assert( orderPairIterator->second->BrokerGeneratedId == TRApiHelpers::OrderNumberNone ||
//                           orderPairIterator->second->BrokerGeneratedId == lineInfo1->iOrderNum
//                        );
//               //assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity == ...
//               //assert( orderPairIterator->second->FilledQuantityAndPrice.Price == ...
//
//               #pragma endregion
//               #pragma region
//
//               orderPairIterator->second->BrokerGeneratedId = lineInfo1->iOrderNum;
//
//               #pragma endregion
//               #pragma region
//
//               {
//                  #pragma region
//
//                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
//
//                  #pragma endregion
//                  #pragma region
//
////TODO revisit this convoluted code
////TODO add regions?
//
//                  if( ! TRApiHelpers::TSNCharcbsEqual( lineInfo1->sStatus, ::RApi::sLINE_STATUS_CANCEL_RECEIVED ) )
//                  {
////TODO remove comment
//                     // This condition increases the chance that we will avoid the cost of char-array comparison.
//                     // yg? But it can result in more overhead.
//                     // See a related validation above.
//                     // See a comment about this in the visible universe.
//                     if( lineInfo1->iCancelled == 0 )
//
//                     {
//                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//                     }
//                     else
//                     {
//                        goto label9;
//                     }
//
//                     if( // See a related validation above.
//                         // See a comment about this in the visible universe.
//                         lineInfo1->iCancelPendingSize == 0 //&&
//
//                         //( ! TRApiHelpers::TSNCharcbsEqual( lineInfo1->sStatus, ::RApi::sLINE_STATUS_CANCEL_RECEIVED ) )
//                       )
//                     {
//                        if( lineInfo1->iFilled > 0 ||
//
//                            // See a related validation above.
//                            // See a comment about this in the visible universe.
//                            lineInfo1->iUnfilled != 0 //||
//
//                            //// See a related validation above.
//                            //// See a comment about this in the visible universe.
//                            //lineInfo1->iCancelled != 0
//                          )
//                        {
//                           ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//
//                        label9:
//                           orderStateBitMask =
//                              static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_CancellationRequestPending ) );
//                        }
//
//                        // This is probably a marginal case when all fields are 0.
//                        else
//
//                        {
//                           ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//                        }
//                     }
//                     else
//                     {
//                        goto label11;
//                     }
//                  }
//                  else
//                  {
//                     // It appears to be safe to use the strict cancellation request ID comparison.
//                     // See a related {assert} in the {else} block.
//                     if( orderPairIterator->second->LastCancellationRequestIdMatches( lineInfo1->sUserMsg ) )
//
//                     {
//                        if( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending ) !=
//                            TOrderStateBitMask_None
//                          )
//                        {
//                           YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//                              ( ( orderStateBitMask & TOrderStateBitMask_ShallBeCancelled ) != TOrderStateBitMask_None );
//                           orderStateBitMask =
//                              static_cast< TOrderStateBitMask >
//                                 ( orderStateBitMask & ( ~ TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending ) );
//                        }
//                        else
//                        {
//                           // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                           ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                           static char const constantString1AsArray[]
//                              ( "the brokerage received the last order cancellation request multiple times" );
//
//                           // yg? This is logged before the data itself.
//                           // This creates another temporary string. Although this rarely happens.
////TODO here and elsewhere: warning?
//                           logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                        }
//                     }
//                     else
//                     {
//                        // I don't want to assume this.
//                        assert( ! orderPairIterator->second->LastCancellationRequestIdMatchesLoosely( lineInfo1->sUserMsg ) );
//
//                        {
//                           // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                           ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                           static char const constantString1AsArray[]( "the brokerage received a non-last order cancellation request" );
//
//                           // yg? This is logged before the data itself.
//                           // This creates another temporary string. Although this rarely happens.
//                           logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                        }
//                     }
//
//                  label11:
//                     orderStateBitMask =
//                        static_cast< TOrderStateBitMask >
//                           ( orderStateBitMask |
//                             TOrderStateBitMask_ShallBeCancelled |
//                             TOrderStateBitMask_CancellationRequestPending
//                           );
//                  }
//
//                  #pragma endregion
//                  #pragma region
//
//                  if( lineInfo1->sCompletionReason.iDataLen <= 0 )
//                  {
//                     orderStateBitMask =
//                        static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );
//                  }
//                  else
//                  {
//                     orderStateBitMask =
//                        static_cast< TOrderStateBitMask >
//                           ( orderStateBitMask |
//                             TOrderStateBitMask_NewOrderRequestReceivedByBroker |
//                             TOrderStateBitMask_ProbablyCompleted |
//                             TOrderStateBitMask_Completed
//                           );
//
//                     // This will *not* be used by {RequestCancelOrderIfInternalShallAndCan}.
//                     orderPairIterator->second->StateBitMask = orderStateBitMask;
//
//                     // We don't need to call {RequestCancelOrderIfInternalShallAndCan} here.
//                     goto label10;
//                  }
//
//                  #pragma endregion
//                  #pragma region
//
//                  // This will be used by {RequestCancelOrderIfInternalShallAndCan}.
//                  orderPairIterator->second->StateBitMask = orderStateBitMask;
//
//                  #pragma endregion
//               }
//
//               #pragma endregion
//               #pragma region
//
//               // yg? Not checking if we are logged in. In fact, we probably are as we received this order state update.
//               // This doesn't raise events. Otherwise the behavior would have a chance to be incorrect.
//               if( ! RequestCancelOrderIfInternalShallAndCan( * orderPairIterator->second ) )
//
//               {
//                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//               }
//               else
//               {
//                  // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                  static char const constantString1AsArray[]( "requested to cancel an order after it became possible" );
//
//                  // yg? This is logged before the data itself.
//                  // This creates another temporary string. Although this rarely happens.
//                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//               }
//
//            label10:
//
//               #pragma endregion
//               #pragma region
//
//               orderPairIterator->second->RaiseOnReceivedData();
//
//               #pragma endregion
//            }
//            else
//            {
//               #pragma region
//
//               static char const constantString1AsArray[]( "invalid {lineInfo1->pContext}" );
//
//               // This results in the logger object reference being obtained more than once. Although this rarely happens.
//               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//               // yg? This is logged before the data itself.
//               // This creates another temporary string. Although this rarely happens.
//               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//               #pragma endregion
//            }
//         }
//
//         #pragma endregion
//         #pragma region
//
//         {
//            static char const formatConstantString1AsArray[]
//               ( "{RApi::LineInfo}"
//                 "; %i"
//                 "; %.*s"
//                 "; %.*s"
//                 "; %.*s"
//                 "; %.*s"
//                 "; %.*s"
//                 "; %.*s"
//                 "; %p"
//                 "; %u"
//                 "; %s"
//                 "; %s"
//                 "; %u"
//                 "; %u"
//                 "; %i"
//                 "; %i"
//                 "; %u"
//                 "; %i"
//                 "; %u"
//                 "; %+.*g"
//                 "; %+.*g"
//                 "; %+.*g"
//                 "; %u"
//                 "; %u"
//                 "; %c"
//                 "; %i"
//                 "; %.*s"
//               );
//
//            // Assuming this will not overflow.
//            int const tempString1BufferLength
//               ( 256
//                 + lineInfo1->sOrderType.iDataLen
//                 + lineInfo1->sBuySellType.iDataLen
//                 + lineInfo1->sStatus.iDataLen
//                 + lineInfo1->sCompletionReason.iDataLen
//                 + lineInfo1->sText.iDataLen
//                 + lineInfo1->sUserMsg.iDataLen
//                 + lineInfo1->sRpCode.iDataLen
//               );
//
//            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
//
//            // I don't want to assume these.
//            {
//               // TODO 3 yg? This validation will fail in a few years.
//               assert( lineInfo1->iGatewaySsboe >= 0 );
//
//               assert( lineInfo1->iGatewayUsecs >= 0 );
//            }
//
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
//            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
//               ( static_cast< ::Poco::Int64 >
//                    ( static_cast< unsigned int >( lineInfo1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
//                      static_cast< unsigned int >( lineInfo1->iGatewayUsecs )
//                    )
//               );
//
//            // I don't want to assume these.
//            {
//               // This is probably positive but we will be OK even if this is 0.
//               // TODO 3 yg? This validation will fail in a few years.
//               assert( lineInfo1->iSsboe >= 0 );
//
//               assert( lineInfo1->iUsecs >= 0 );
//            }
//
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
//            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
//               ( static_cast< ::Poco::Int64 >
//                    ( static_cast< unsigned int >( lineInfo1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
//                      static_cast< unsigned int >( lineInfo1->iUsecs )
//                    )
//               );
//
//            // We will format these as an unsigned.
//            // I don't want to assume these.
//            {
//               assert( lineInfo1->iGatewayBufferBytesBehind >= 0 );
//               assert( lineInfo1->iQuantityToFill >= 0 );
//               assert( lineInfo1->iFilled >= 0 );
//               assert( lineInfo1->iReleasePendingSize >= 0 );
//               assert( lineInfo1->iModifyPendingSize >= 0 );
//
//               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
//               assert( lineInfo1->iTriggerPriceId >= 0 );
//               assert( lineInfo1->iTriggerCmpOperator >= 0 );
//            }
//
//            int tempString1Length
//               ( ::_snprintf_l
//                    ( ( & tempString1.front() ),
//                      static_cast< unsigned int >( tempString1BufferLength ),
//                      formatConstantString1AsArray,
//                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
//                      lineInfo1->iOrderNum,
//                      lineInfo1->sOrderType.iDataLen,
//                      lineInfo1->sOrderType.pData,
//                      lineInfo1->sBuySellType.iDataLen,
//                      lineInfo1->sBuySellType.pData,
//                      lineInfo1->sStatus.iDataLen,
//                      lineInfo1->sStatus.pData,
//                      lineInfo1->sCompletionReason.iDataLen,
//                      lineInfo1->sCompletionReason.pData,
//                      lineInfo1->sText.iDataLen,
//                      lineInfo1->sText.pData,
//                      lineInfo1->sUserMsg.iDataLen,
//                      lineInfo1->sUserMsg.pData,
//                      lineInfo1->pContext,
//                      static_cast< unsigned int >( lineInfo1->iGatewayBufferBytesBehind ),
//
//                      // yg? Using current thread locale.
//                      ( ::Poco::DateTimeFormatter::format
//                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
//                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
//                           )
//                        .c_str()
//                      ),
//                      ( ::Poco::DateTimeFormatter::format
//                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
//                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
//                           )
//                        .c_str()
//                      ),
//
//                      static_cast< unsigned int >( lineInfo1->iQuantityToFill ),
//                      static_cast< unsigned int >( lineInfo1->iFilled ),
//
//                      // See a comment about this in the visible universe.
//                      lineInfo1->iUnfilled,
//
//                      // See a comment about this in the visible universe.
//                      lineInfo1->iCancelled,
//
//                      static_cast< unsigned int >( lineInfo1->iReleasePendingSize ),
//
//                      // See a comment about this in the visible universe.
//                      lineInfo1->iCancelPendingSize,
//
//                      static_cast< unsigned int >( lineInfo1->iModifyPendingSize ),
//                      10,
//                      lineInfo1->bPriceToFillFlag ? lineInfo1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
//                      10,
//                      lineInfo1->bAvgFillPriceFlag ? lineInfo1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
//                      10,
//                      lineInfo1->bTriggerPriceFlag ? lineInfo1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
//                      static_cast< unsigned int >( lineInfo1->iTriggerPriceId ),
//                      static_cast< unsigned int >( lineInfo1->iTriggerCmpOperator ),
//                      static_cast< char >( lineInfo1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
//
//                      // This is probably not negative but I don't want to format this as an unsigned. We still don't format the '+' sign.
//                      lineInfo1->iRpCode,
//
//                      lineInfo1->sRpCode.iDataLen,
//                      lineInfo1->sRpCode.pData
//                    )
//               );
//
//            if( tempString1Length >= 0 )
//            {
//               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
//            }
//            else
//            {
//               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
//            }
//
//            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//            // yg? Consider logging a separate message when this condition is {false}.
//            // yg? But as of 10/18/2013 I haven't seen this condition being {false}.
//            if( lineInfo1->iRpCode == API_OK )
//
//            {
//               logger1.information( tempString1 );
//            }
//            else
//            {
//               // yg? If the error is not too severe it might be better to mark this a "Warning".
//               logger1.error( tempString1 );
//
//               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//            }
//         }
//
//         #pragma endregion
//         #pragma region
//
//         return OK;
//
//         #pragma endregion
//      }
//      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
//      catch( ::OmneException const & exception1 )
//      {
//         #pragma region
//
//         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ::Poco::Exception const & exception1 )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ::std::exception const & exception1 )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ... )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//
//      #pragma endregion
//   }

#endif
#if( /* {(public) FailureReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
//   int TREngineAdapter::FailureReport
//      ( ::RApi::OrderFailureReport * orderFailureReport1,
//        void * /*context1*/,
//        int * /*outcomeCode2*/
//      )
//   {
//      #pragma region
//
//      // Visible universe.
//      //    {FailureReport} -- base.
//      //       Implement.
//      //    //{orderFailureReport1->iCancelledSize}.
//      //       Ignore.
//      //       Just like {orderFailureReport1->iTotalUnfilled}, expecting this to be negative.
//      //    {orderFailureReport1->sStatus}.
//      //       Use.
//      //       R|API release notes says:
//      //       <Quote>The OrderFailureReport has a new field sStatus, which can be used to determine if the failed operation was
//      //       a new order, cancellation or modification. The values used in these cases are:
//      //          complete (sLINE_STATUS_COMPLETE)
//      //          Cancellation Failed (sLINE_STATUS_CANCEL_FAILED)
//      //          Modification Failed (sLINE_STATUS_MODIFY_FAILED)
//      //       </Quote>
//      //       R|API help says: "Status string, if available". So it's possible that it's not available.
//      //    {orderFailureReport1->...}.
//      //       Possibly log some other fields.
//      // See visible universe in {LineUpdate}.
//
//      #pragma endregion
//      #pragma region
//
//      try
//      {
//         #pragma region
//
//         //::RApi::RCallbacks::...
//
//         #pragma endregion
//         #pragma region
//
//         // The order of {orderFailureReport1->sStatus} comparisons is optimized for performance.
//         for( ; ; )
//         {
//            #pragma region
//
//            if( TRApiHelpers::TSNCharcbsEqual( orderFailureReport1->sStatus, ::RApi::sLINE_STATUS_CANCEL_FAILED ) )
//            {
//               #pragma region
//
//               // I don't want to assume this.
//               assert( orderFailureReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
//
//               // yg? This is usually/always 0.
//               // I don't want to assume this.
//               assert( orderFailureReport1->iTotalFilled >= 0 );
//
//               // yg? {orderFailureReport1->iTotalUnfilled} is usually/always 0.
//               // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
//               // I don't want to assume this.
//               assert( orderFailureReport1->iTotalFilled + orderFailureReport1->iTotalUnfilled >= 0 );
//
//               // I don't want to assume this.
//               assert( ( orderFailureReport1->iTotalFilled > 0 ) == orderFailureReport1->bAvgFillPriceFlag );
//
//               #pragma endregion
//               #pragma region
//
//               {
//                  ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
//                     ( SingleInstrumentsOrders_.find( orderFailureReport1->pContext ) );
//
//                  if( orderPairIterator != SingleInstrumentsOrders_.end() &&
//
//                      // yg? See related comment in {LineUpdate}.
//                      orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
//                    )
//                  {
//                     #pragma region
//
//                     // See related comment in {LineUpdate}.
//                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
//                                                                                                          ( TOrderStateBitMask_NewOrderRequestPending |
//                                                                                                            TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                                                                                          )
//                                                                                                        ) !=
//                                                                                                        TOrderStateBitMask_None
//                                                                                                     );
//
//                     // I don't want to assume these.
//                     assert( ( orderPairIterator->second->StateBitMask &
//                                   ( //TOrderStateBitMask_NewOrderRequestPending |
//                                     TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                     //TOrderStateBitMask_LastModificationRequestPending |
//                                     //TOrderStateBitMask_LastModificationRequestRejected |
//                                     //TOrderStateBitMask_ShallBeCancelled |
//                                     //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
//                                     ////TOrderStateBitMask_LastCancellationRequestPending |
//                                     ////TOrderStateBitMask_LastCancellationRequestRejected |
//                                     //TOrderStateBitMask_CancellationRequestPending |
//                                     //TOrderStateBitMask_TriggeredByBroker |
//                                     //TOrderStateBitMask_TriggeredByExchange |
//                                     //TOrderStateBitMask_ProbablyCompleted |
//                                     //TOrderStateBitMask_Completed
//                                   )
//                                 ) ==
//                                 TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                              );
//                     assert( orderPairIterator->second->BrokerGeneratedId == orderFailureReport1->iOrderNum );
//
//                     // yg?
//                     //assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
//                     //            static_cast< double >( orderFailureReport1->iTotalFilled )
//                     //         );
//                     //assert( orderPairIterator->second->FilledQuantityAndPrice.Price ==
//                     //            ( ( ! orderFailureReport1->bAvgFillPriceFlag ) ?
//                     //              ::std::numeric_limits< double >::lowest() :
//                     //              orderFailureReport1->dAvgFillPrice
//                     //            )
//                     //         );
//
//                     #pragma endregion
//                     #pragma region
//
//                     // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                     orderPairIterator->second->BrokerGeneratedId = orderFailureReport1->iOrderNum;
//
//                     #pragma endregion
//                     #pragma region
//
//                     {
//                        #pragma region
//
//                        TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
//
//                        #pragma endregion
//                        #pragma region
//
//                        // It appears to be safe to use the strict cancellation request ID comparison.
//                        // See a related {assert} in the {else} block.
//                        if( orderPairIterator->second->LastCancellationRequestIdMatches( orderFailureReport1->sUserMsg ) )
//
//                        {
//                           //if( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestPending ) != TOrderStateBitMask_None )
//                           if( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending ) !=
//                               TOrderStateBitMask_None
//                             )
//                           {
//                              //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//                              //   ( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestRejected ) == TOrderStateBitMask_None );
//                              YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//                                 ( ( orderStateBitMask & TOrderStateBitMask_ShallBeCancelled ) != TOrderStateBitMask_None );
//                              //orderStateBitMask =
//                              //   static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_LastCancellationRequestPending ) );
//                              //orderStateBitMask =
//                              //   static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_LastCancellationRequestRejected );
//                              orderStateBitMask =
//                                 static_cast< TOrderStateBitMask >
//                                    ( orderStateBitMask & ( ~ TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending ) );
//                           }
//                           else
//                           {
//                              // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                              ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
////TODO copy message from LineUpdatel use the word "rejected" instead of "received"
//                              //static char const constantString1AsArray[]( "the last order cancellation request is no longer pending" );
//                              static char const constantString1AsArray[]( "the brokerage already received the last order cancellation request" );
//
//                              // yg? This is logged before the data itself.
//                              // This creates another temporary string. Although this rarely happens.
//                              logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
////TODO remove
//                              // At this point it might make sense to set the {TOrderStateBitMask_LastCancellationRequestRejected} bit
//                              // but let's not complicate things.
//                           }
//                        }
//                        else
//                        {
//                           // I don't want to assume this.
//                           assert( ! orderPairIterator->second->LastCancellationRequestIdMatchesLoosely( orderFailureReport1->sUserMsg ) );
//
//                           {
//                              // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                              ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                              //static char const constantString1AsArray[]( "a non-last order cancellation request was rejected" );
////TODO copy message from LineUpdatel use the word "rejected" instead of "received"
//                              static char const constantString1AsArray[]( "the brokerage rejected a non-last order cancellation request" );
//
//                              // yg? This is logged before the data itself.
//                              // This creates another temporary string. Although this rarely happens.
//                              logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                           }
//                        }
//
//                        #pragma endregion
//                        #pragma region
//
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >
//                              ( orderStateBitMask |
//
//                                // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                                TOrderStateBitMask_NewOrderRequestReceivedByBroker |
//
////TODO remove comment
//                                // We are probably not in rush to set this bit before we actually determine
//                                // that we can't immediatelly re-request to cancel this order
//                                // but it's more efficient to set it here along with the other bits.
//                                // This logic doesn't need to check that the order is not complete yet.
//                                TOrderStateBitMask_ShallBeCancelled
//                              );
//
//                        // Not clearing the {TOrderStateBitMask_CancellationRequestPending} bit
//                        // as we can't assume that the previously seen pending cancellation request, if any, completed.
//
//                        // This will be used by {InternalCanCancelOrder}.
//                        orderPairIterator->second->StateBitMask = orderStateBitMask;
//
//                        #pragma endregion
//                     }
//
//                     #pragma endregion
//                     #pragma region
//
//                     if( InternalCanCancelOrder( * orderPairIterator->second ) )
//                     {
//                        // When this condition is {true} I don't want to immediately send another cancellation request.
//                        // Case sensitive comparison.
//                        // Because of this additional condition it would be inefficient to call {RequestCancelOrderIfInternalCan}.
//                        if( TRApiHelpers::TSNCharcbEqual
//                                ( orderFailureReport1->sText,
//                                  TRApiHelpers::OrderReportTextAtomicOrderOperationInProgressAsArray,
//                                  TRApiHelpers::OrderReportTextAtomicOrderOperationInProgressLength
//                                )
//                          )
//
//                        {
//                           ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//                        }
//                        else
//                        {
//                           // yg? Not checking if we are logged in. In fact, we probably are as we received this order report.
//                           // This doesn't raise events. Otherwise the behavior would have a chance to be incorrect.
//                           RequestCancelOrder( * orderPairIterator->second );
//
//                           {
//                              // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                              ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                              static char const constantString1AsArray[]( "re-requested to cancel an order" );
//
//                              // yg? This is logged before the data itself.
//                              // This creates another temporary string. Although this rarely happens.
//                              logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                           }
//                        }
//                     }
//                     else
//                     {
//                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//                     }
//
//                     #pragma endregion
//                     #pragma region
//
//                     orderPairIterator->second->RaiseOnReceivedData();
//
//                     #pragma endregion
//                  }
//                  else
//                  {
//                     #pragma region
//
//                     static char const constantString1AsArray[]( "invalid {orderFailureReport1->pContext}" );
//
//                     // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                     // yg? This is logged before the data itself.
//                     // This creates another temporary string. Although this rarely happens.
//                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//                     #pragma endregion
//                  }
//               }
//
//               #pragma endregion
//               #pragma region
//
//               break;
//
//               #pragma endregion
//            }
//            else
//            {
//               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//            }
//
//            #pragma endregion
//            #pragma region
//
//            if( TRApiHelpers::TSNCharcbsEqual( orderFailureReport1->sStatus, ::RApi::sLINE_STATUS_MODIFY_FAILED ) )
//            {
//               #pragma region
//
//               // I don't want to assume this.
//               assert( orderFailureReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
//
//               // yg? This is usually/always 0.
//               // I don't want to assume this.
//               assert( orderFailureReport1->iTotalFilled >= 0 );
//
//               // yg? {orderFailureReport1->iTotalUnfilled} is usually/always 0.
//               // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
//               // I don't want to assume this.
//               assert( orderFailureReport1->iTotalFilled + orderFailureReport1->iTotalUnfilled >= 0 );
//
//               // I don't want to assume this.
//               assert( ( orderFailureReport1->iTotalFilled > 0 ) == orderFailureReport1->bAvgFillPriceFlag );
//
//               #pragma endregion
//               #pragma region
//
//               {
//                  ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
//                     ( SingleInstrumentsOrders_.find( orderFailureReport1->pContext ) );
//
//                  if( orderPairIterator != SingleInstrumentsOrders_.end() &&
//
//                      // yg? See related comment in {LineUpdate}.
//                      orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
//                    )
//                  {
//                     #pragma region
//
//                     // See related comment in {LineUpdate}.
//                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
//                                                                                                          ( TOrderStateBitMask_NewOrderRequestPending |
//                                                                                                            TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                                                                                          )
//                                                                                                        ) !=
//                                                                                                        TOrderStateBitMask_None
//                                                                                                     );
//
//                     // I don't want to assume these.
//                     assert( ( orderPairIterator->second->StateBitMask &
//                                   ( //TOrderStateBitMask_NewOrderRequestPending |
//                                     TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                     //TOrderStateBitMask_LastModificationRequestPending |
//                                     //TOrderStateBitMask_LastModificationRequestRejected |
//                                     //TOrderStateBitMask_ShallBeCancelled |
//                                     //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
//                                     ////TOrderStateBitMask_LastCancellationRequestPending |
//                                     ////TOrderStateBitMask_LastCancellationRequestRejected |
//                                     //TOrderStateBitMask_CancellationRequestPending |
//                                     //TOrderStateBitMask_TriggeredByBroker |
//                                     //TOrderStateBitMask_TriggeredByExchange |
//                                     //TOrderStateBitMask_ProbablyCompleted |
//                                     //TOrderStateBitMask_Completed
//                                   )
//                                 ) ==
//                                 TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                              );
//                     assert( orderPairIterator->second->BrokerGeneratedId == orderFailureReport1->iOrderNum );
//
//                     // yg?
//                     //assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
//                     //            static_cast< double >( orderFailureReport1->iTotalFilled )
//                     //         );
//                     //assert( orderPairIterator->second->FilledQuantityAndPrice.Price ==
//                     //            ( ( ! orderFailureReport1->bAvgFillPriceFlag ) ?
//                     //              ::std::numeric_limits< double >::lowest() :
//                     //              orderFailureReport1->dAvgFillPrice
//                     //            )
//                     //         );
//
//                     #pragma endregion
//                     #pragma region
//
//                     // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                     orderPairIterator->second->BrokerGeneratedId = orderFailureReport1->iOrderNum;
//
//                     #pragma endregion
//                     #pragma region
//
//                     {
//                        #pragma region
//
//                        TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
//
//                        #pragma endregion
//                        #pragma region
//
//                        if( orderFailureReport1->sUserMsg.iDataLen == 1 &&
//                            ( * orderFailureReport1->sUserMsg.pData ) == orderPairIterator->second->LastModificationRequestId()
//                          )
//                        {
//                           if( ( orderStateBitMask & TOrderStateBitMask_LastModificationRequestPending ) != TOrderStateBitMask_None )
//                           {
//                              YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//                                 ( ( orderStateBitMask & TOrderStateBitMask_LastModificationRequestRejected ) == TOrderStateBitMask_None );
//                              orderStateBitMask =
//                                 static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_LastModificationRequestPending ) );
//                              orderStateBitMask =
//                                 static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_LastModificationRequestRejected );
//                           }
//                           else
//                           {
//                              // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                              ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
////TODO copy message from LineUpdate
//                              static char const constantString1AsArray[]( "the last order modification request is no longer pending" );
//
//                              // yg? This is logged before the data itself.
//                              // This creates another temporary string. Although this rarely happens.
//                              logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//                              // At this point it might make sense to set the {TOrderStateBitMask_LastModificationRequestRejected} bit
//                              // but let's not complicate things.
//                           }
//                        }
//                        else
//                        {
//                           // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                           ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
////TODO copy message from LineUpdate
//                           static char const constantString1AsArray[]( "a non-last order modification request was rejected" );
//
//                           // yg? This is logged before the data itself.
//                           // This creates another temporary string. Although this rarely happens.
//                           logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                        }
//
//                        #pragma endregion
//                        #pragma region
//
//                        // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );
//
//                        // This will be used by {ShallAndInternalCanCancelOrder}.
//                        orderPairIterator->second->StateBitMask = orderStateBitMask;
//
//                        #pragma endregion
//                     }
//
//                     #pragma endregion
//                     #pragma region
//
//                     if( ! ShallAndInternalCanCancelOrder( * orderPairIterator->second ) )
//                     {
//                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//                     }
//                     else
//                     {
//                        // When this condition is {true} I don't want to immediately send a cancellation request.
//                        // Case sensitive comparison.
//                        // Because of this additional condition it would be inefficient to call {RequestCancelOrderIfInternalShallAndCan}.
//                        if( TRApiHelpers::TSNCharcbEqual
//                                ( orderFailureReport1->sText,
//                                  TRApiHelpers::OrderReportTextAtomicOrderOperationInProgressAsArray,
//                                  TRApiHelpers::OrderReportTextAtomicOrderOperationInProgressLength
//                                )
//                          )
//
//                        {
//                           ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//                        }
//                        else
//                        {
//                           // yg? Not checking if we are logged in. In fact, we probably are as we received this order report.
//                           // This doesn't raise events. Otherwise the behavior would have a chance to be incorrect.
//                           RequestCancelOrder( * orderPairIterator->second );
//
//                           {
//                              // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                              ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                              static char const constantString1AsArray[]( "requested to cancel an order after it became possible" );
//
//                              // yg? This is logged before the data itself.
//                              // This creates another temporary string. Although this rarely happens.
//                              logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                           }
//                        }
//                     }
//
//                     #pragma endregion
//                     #pragma region
//
//                     orderPairIterator->second->RaiseOnReceivedData();
//
//                     #pragma endregion
//                  }
//                  else
//                  {
//                     #pragma region
//
//                     static char const constantString1AsArray[]( "invalid {orderFailureReport1->pContext}" );
//
//                     // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                     // yg? This is logged before the data itself.
//                     // This creates another temporary string. Although this rarely happens.
//                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//                     #pragma endregion
//                  }
//               }
//
//               #pragma endregion
//               #pragma region
//
//               break;
//
//               #pragma endregion
//            }
//            else
//            {
//               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//            }
//
//            #pragma endregion
//            #pragma region
//
//            if( TRApiHelpers::TSNCharcbsEqual( orderFailureReport1->sStatus, ::RApi::sLINE_STATUS_COMPLETE ) )
//            {
//               #pragma region
//
//               // I don't want to assume these.
//               assert( orderFailureReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
//               assert( orderFailureReport1->iTotalFilled == 0 );
//
//               // yg? This is usually/always 0.
//               // I don't want to assume this.
//               assert( orderFailureReport1->iTotalUnfilled >= 0 );
//
//               // I don't want to assume this.
//               assert( ! orderFailureReport1->bAvgFillPriceFlag );
//
//               #pragma endregion
//               #pragma region
//
//               {
//                  ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
//                     ( SingleInstrumentsOrders_.find( orderFailureReport1->pContext ) );
//
//                  if( orderPairIterator != SingleInstrumentsOrders_.end() &&
//
//                      // yg? See related comment in {LineUpdate}.
//                      orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
//                    )
//                  {
//                     #pragma region
//
//                     // See related comment in {LineUpdate}.
//                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
//                                                                                                          ( TOrderStateBitMask_NewOrderRequestPending |
//                                                                                                            TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                                                                                          )
//                                                                                                        ) !=
//                                                                                                        TOrderStateBitMask_None
//                                                                                                     );
//
//                     // I don't want to assume these.
//                     assert( ( orderPairIterator->second->StateBitMask &
//                                   ( TOrderStateBitMask_NewOrderRequestPending |
//                                     TOrderStateBitMask_NewOrderRequestReceivedByBroker |
//                                     //TOrderStateBitMask_LastModificationRequestPending |
//                                     //TOrderStateBitMask_LastModificationRequestRejected |
//                                     //TOrderStateBitMask_ShallBeCancelled |
//                                     //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
//                                     ////TOrderStateBitMask_LastCancellationRequestPending |
//                                     ////TOrderStateBitMask_LastCancellationRequestRejected |
//                                     //TOrderStateBitMask_CancellationRequestPending |
//                                     TOrderStateBitMask_TriggeredByBroker |
//                                     TOrderStateBitMask_TriggeredByExchange |
//                                     TOrderStateBitMask_ProbablyCompleted |
//                                     TOrderStateBitMask_Completed
//                                   )
//                                 ) ==
//                                 ( TOrderStateBitMask_NewOrderRequestPending |
//                                   TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                 )
//                              );
//                     assert( orderPairIterator->second->BrokerGeneratedId == orderFailureReport1->iOrderNum );
//                     assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity == 0.0 );
//                     assert( orderPairIterator->second->FilledQuantityAndPrice.Price == ::std::numeric_limits< double >::lowest() );
//
//                     #pragma endregion
//                     #pragma region
//
//                     // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                     orderPairIterator->second->BrokerGeneratedId = orderFailureReport1->iOrderNum;
//
//                     #pragma endregion
//                     #pragma region
//
//                     {
//                        TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >
//                              ( orderStateBitMask |
//
//                                // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                                TOrderStateBitMask_NewOrderRequestReceivedByBroker |
//
//                                TOrderStateBitMask_ProbablyCompleted |
//                                TOrderStateBitMask_Completed
//                              );
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_NewOrderRequestPending ) );
//                        orderPairIterator->second->StateBitMask = orderStateBitMask;
//                     }
//
//                     #pragma endregion
//                     #pragma region
//
//                     orderPairIterator->second->RaiseOnReceivedData();
//
//                     #pragma endregion
//                  }
//                  else
//                  {
//                     #pragma region
//
//                     static char const constantString1AsArray[]( "invalid {orderFailureReport1->pContext}" );
//
//                     // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                     // yg? This is logged before the data itself.
//                     // This creates another temporary string. Although this rarely happens.
//                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//                     #pragma endregion
//                  }
//               }
//
//               #pragma endregion
//               #pragma region
//
//               break;
//
//               #pragma endregion
//            }
//            else
//            {
//               #pragma region
//
//               {
//                  // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                  static char const constantString1AsArray[]( "invalid {orderFailureReport1->sStatus}" );
//
//                  // yg? This is logged before the data itself.
//                  // This creates another temporary string. Although this rarely happens.
//                  logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//               }
//
//               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//
//               #pragma endregion
//               #pragma region
//
//               // I don't want to assume these.
//               assert( orderFailureReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
//               assert( orderFailureReport1->iTotalFilled >= 0 );
//
//               // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
//               // I don't want to assume this.
//               assert( orderFailureReport1->iTotalFilled + orderFailureReport1->iTotalUnfilled > 0 );
//
//               // I don't want to assume this.
//               assert( ( orderFailureReport1->iTotalFilled > 0 ) == orderFailureReport1->bAvgFillPriceFlag );
//
//               #pragma endregion
//               #pragma region
//
//               {
//                  ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
//                     ( SingleInstrumentsOrders_.find( orderFailureReport1->pContext ) );
//
//                  if( orderPairIterator != SingleInstrumentsOrders_.end() &&
//
//                      // yg? See related comment in {LineUpdate}.
//                      orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
//                    )
//                  {
//                     #pragma region
//
//                     // See related comment in {LineUpdate}.
//                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
//                                                                                                          ( TOrderStateBitMask_NewOrderRequestPending |
//                                                                                                            TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                                                                                          )
//                                                                                                        ) !=
//                                                                                                        TOrderStateBitMask_None
//                                                                                                     );
//
//                     // I don't want to assume these.
//                     assert( ( orderPairIterator->second->StateBitMask &
//                                   ( //TOrderStateBitMask_NewOrderRequestPending |
//                                     TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                     //TOrderStateBitMask_LastModificationRequestPending |
//                                     //TOrderStateBitMask_LastModificationRequestRejected |
//                                     //TOrderStateBitMask_ShallBeCancelled |
//                                     //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
//                                     ////TOrderStateBitMask_LastCancellationRequestPending |
//                                     ////TOrderStateBitMask_LastCancellationRequestRejected |
//                                     //TOrderStateBitMask_CancellationRequestPending |
//                                     //TOrderStateBitMask_TriggeredByBroker |
//                                     //TOrderStateBitMask_TriggeredByExchange |
//                                     //TOrderStateBitMask_ProbablyCompleted |
//                                     //TOrderStateBitMask_Completed
//                                   )
//                                 ) ==
//                                 TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                              );
//                     assert( orderPairIterator->second->BrokerGeneratedId == orderFailureReport1->iOrderNum );
//                     assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
//                                 static_cast< double >( orderFailureReport1->iTotalFilled )
//                              );
//                     assert( orderPairIterator->second->FilledQuantityAndPrice.Price ==
//                                 ( ( ! orderFailureReport1->bAvgFillPriceFlag ) ?
//                                   ::std::numeric_limits< double >::lowest() :
//                                   orderFailureReport1->dAvgFillPrice
//                                 )
//                              );
//
//                     #pragma endregion
//                     #pragma region
//
//                     // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                     orderPairIterator->second->BrokerGeneratedId = orderFailureReport1->iOrderNum;
//
//                     #pragma endregion
//                     #pragma region
//
//                     {
//                        TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
//
//                        // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );
//
//                        orderPairIterator->second->StateBitMask = orderStateBitMask;
//                     }
//
//                     #pragma endregion
//                     #pragma region
//
//                     orderPairIterator->second->RaiseOnReceivedData();
//
//                     #pragma endregion
//                  }
//                  else
//                  {
//                     #pragma region
//
//                     static char const constantString1AsArray[]( "invalid {orderFailureReport1->pContext}" );
//
//                     // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                     // yg? This is logged before the data itself.
//                     // This creates another temporary string. Although this rarely happens.
//                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//                     #pragma endregion
//                  }
//               }
//
//               #pragma endregion
//               #pragma region
//
//               break;
//
//               #pragma endregion
//            }
//
//            #pragma endregion
//         }
//
//         #pragma endregion
//         #pragma region
//
//         {
//            static char const formatConstantString1AsArray[]
//               ( "{RApi::OrderFailureReport}"
//                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
//                 "; %i; %.*s"
//               );
//
//            // Assuming this will not overflow.
//            int const tempString1BufferLength
//               ( 256
//                 + orderFailureReport1->sOrderType.iDataLen
//                 + orderFailureReport1->sBuySellType.iDataLen
//                 + orderFailureReport1->sReportType.iDataLen
//                 + orderFailureReport1->sText.iDataLen
//                 + orderFailureReport1->sUserMsg.iDataLen
//                 + orderFailureReport1->sStatus.iDataLen
//               );
//
//            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
//
//            // I don't want to assume these.
//            {
//               // TODO 3 yg? This validation will fail in a few years.
//               assert( orderFailureReport1->iGatewaySsboe >= 0 );
//
//               assert( orderFailureReport1->iGatewayUsecs >= 0 );
//            }
//
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
//            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
//               ( static_cast< ::Poco::Int64 >
//                    ( static_cast< unsigned int >( orderFailureReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
//                      static_cast< unsigned int >( orderFailureReport1->iGatewayUsecs )
//                    )
//               );
//
//            // I don't want to assume these.
//            {
//               // This is probably positive but we will be OK even if this is 0.
//               // TODO 3 yg? This validation will fail in a few years.
//               assert( orderFailureReport1->iSsboe >= 0 );
//
//               assert( orderFailureReport1->iUsecs >= 0 );
//            }
//
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
//            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
//               ( static_cast< ::Poco::Int64 >
//                    ( static_cast< unsigned int >( orderFailureReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
//                      static_cast< unsigned int >( orderFailureReport1->iUsecs )
//                    )
//               );
//
//            // We will format these as an unsigned.
//            // I don't want to assume these.
//            {
//               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
//               assert( orderFailureReport1->iTriggerCmpOperator >= 0 );
//               assert( orderFailureReport1->iTriggerPriceId >= 0 );
//
//               assert( orderFailureReport1->iTotalFilled >= 0 );
//               assert( orderFailureReport1->iGatewayBufferBytesBehind >= 0 );
//            }
//
//            int tempString1Length
//               ( ::_snprintf_l
//                    ( ( & tempString1.front() ),
//                      static_cast< unsigned int >( tempString1BufferLength ),
//                      formatConstantString1AsArray,
//                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
//                      orderFailureReport1->iOrderNum,
//                      orderFailureReport1->sOrderType.iDataLen,
//                      orderFailureReport1->sOrderType.pData,
//                      orderFailureReport1->sBuySellType.iDataLen,
//                      orderFailureReport1->sBuySellType.pData,
//                      10,
//                      orderFailureReport1->bPriceToFillFlag ? orderFailureReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
//                      10,
//                      orderFailureReport1->bTriggerPriceFlag ? orderFailureReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
//                      static_cast< unsigned int >( orderFailureReport1->iTriggerCmpOperator ),
//                      static_cast< unsigned int >( orderFailureReport1->iTriggerPriceId ),
//                      static_cast< unsigned int >( orderFailureReport1->iTotalFilled ),
//
//                      // See a comment about this in the visible universe in {LineUpdate}.
//                      orderFailureReport1->iTotalUnfilled,
//
//                      10,
//                      orderFailureReport1->bAvgFillPriceFlag ? orderFailureReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
//                      orderFailureReport1->sReportType.iDataLen,
//                      orderFailureReport1->sReportType.pData,
//                      orderFailureReport1->sText.iDataLen,
//                      orderFailureReport1->sText.pData,
//                      orderFailureReport1->sUserMsg.iDataLen,
//                      orderFailureReport1->sUserMsg.pData,
//                      orderFailureReport1->pContext,
//                      static_cast< char >( orderFailureReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
//                      static_cast< unsigned int >( orderFailureReport1->iGatewayBufferBytesBehind ),
//
//                      // yg? Using current thread locale.
//                      ( ::Poco::DateTimeFormatter::format
//                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
//                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
//                           )
//                        .c_str()
//                      ),
//                      ( ::Poco::DateTimeFormatter::format
//                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
//                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
//                           )
//                        .c_str()
//                      ),
//
//                      // See a comment about this in the visible universe.
//                      orderFailureReport1->iCancelledSize,
//
//                      orderFailureReport1->sStatus.iDataLen,
//                      orderFailureReport1->sStatus.pData
//                    )
//               );
//
//            if( tempString1Length >= 0 )
//            {
//               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
//            }
//            else
//            {
//               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
//            }
//
//            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//            logger1.warning( tempString1 );
//         }
//
//         #pragma endregion
//         #pragma region
//
//         return OK;
//
//         #pragma endregion
//      }
//      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
//      catch( ::OmneException const & exception1 )
//      {
//         #pragma region
//
//         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ::Poco::Exception const & exception1 )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ::std::exception const & exception1 )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ... )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//
//      #pragma endregion
//   }

#endif
#if( /* {(public) RejectReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::RejectReport
      ( ::RApi::OrderRejectReport * orderRejectReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      // This callback is called also after an "if-touched" order gets rejected by the exchange.

      // Visible universe.
      //    {RejectReport} -- base.
      //       Implement.
      //    //{orderRejectReport1->iRejectedSize}.
      //       Ignore.
      //    {orderRejectReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderRejectReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderRejectReport1->iTotalFilled == 0 );
         assert( orderRejectReport1->iTotalUnfilled > 0 );
         assert( ! orderRejectReport1->bAvgFillPriceFlag );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderRejectReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region
               
               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |
                               //TOrderStateBitMask_CancellationRequestPending |
                               //TOrderStateBitMask_TriggeredByBroker |
                               TOrderStateBitMask_TriggeredByExchange |
                               TOrderStateBitMask_ProbablyCompleted |
                               TOrderStateBitMask_Completed
                             )
                           ) ==
                           ( TOrderStateBitMask_NewOrderRequestPending |
                             TOrderStateBitMask_NewOrderRequestReceivedByBroker
                           )
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderRejectReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity == 0.0 );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Price == ::std::numeric_limits< double >::lowest() );

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderRejectReport1->iOrderNum;

               #pragma endregion
               #pragma region

               {
                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >
                        ( orderStateBitMask |

                          // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                          TOrderStateBitMask_NewOrderRequestReceivedByBroker |

                          TOrderStateBitMask_ProbablyCompleted |
                          TOrderStateBitMask_Completed
                        );
                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_NewOrderRequestPending ) );
                  orderPairIterator->second->StateBitMask = orderStateBitMask;
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderRejectReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            
               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderRejectReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 "; %u"
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderRejectReport1->sOrderType.iDataLen
                 + orderRejectReport1->sBuySellType.iDataLen
                 + orderRejectReport1->sReportType.iDataLen
                 + orderRejectReport1->sText.iDataLen
                 + orderRejectReport1->sUserMsg.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderRejectReport1->iGatewaySsboe >= 0 );

               assert( orderRejectReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderRejectReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderRejectReport1->iGatewayUsecs )
                    )
               );
            
            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderRejectReport1->iSsboe >= 0 );

               assert( orderRejectReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderRejectReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderRejectReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
               assert( orderRejectReport1->iTriggerCmpOperator >= 0 );
               assert( orderRejectReport1->iTriggerPriceId >= 0 );

               assert( orderRejectReport1->iTotalFilled >= 0 );
               assert( orderRejectReport1->iGatewayBufferBytesBehind >= 0 );

               // This assertion might fail if a buggy app sends an invalid value, and that's not too bad.
               assert( orderRejectReport1->iRejectedSize >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderRejectReport1->iOrderNum,
                      orderRejectReport1->sOrderType.iDataLen,
                      orderRejectReport1->sOrderType.pData,
                      orderRejectReport1->sBuySellType.iDataLen,
                      orderRejectReport1->sBuySellType.pData,
                      10,
                      orderRejectReport1->bPriceToFillFlag ? orderRejectReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderRejectReport1->bTriggerPriceFlag ? orderRejectReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderRejectReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderRejectReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderRejectReport1->iTotalFilled ),

                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderRejectReport1->iTotalUnfilled,

                      10,
                      orderRejectReport1->bAvgFillPriceFlag ? orderRejectReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderRejectReport1->sReportType.iDataLen,
                      orderRejectReport1->sReportType.pData,
                      orderRejectReport1->sText.iDataLen,
                      orderRejectReport1->sText.pData,
                      orderRejectReport1->sUserMsg.iDataLen,
                      orderRejectReport1->sUserMsg.pData,
                      orderRejectReport1->pContext,
                      static_cast< char >( orderRejectReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderRejectReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),

                      static_cast< unsigned int >( orderRejectReport1->iRejectedSize )
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.warning( tempString1 );
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }

      #pragma endregion
   }

#endif
#if( /* {(public) StatusReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::StatusReport
      ( ::RApi::OrderStatusReport * orderStatusReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      // This callback is called also after an "if-touched" order gets accepted by the brokerage.

      // Visible universe.
      //    {StatusReport} -- base.
      //       Implement.
      //    //{orderStatusReport1->iConfirmedSize}.
      //       Ignore.
      //    {orderStatusReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderStatusReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderStatusReport1->iTotalFilled == 0 );
         assert( orderStatusReport1->iTotalUnfilled > 0 );
         assert( ! orderStatusReport1->bAvgFillPriceFlag );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderStatusReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region

               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |
                               //TOrderStateBitMask_CancellationRequestPending |
                               //TOrderStateBitMask_TriggeredByBroker |
                               TOrderStateBitMask_TriggeredByExchange |
                               TOrderStateBitMask_ProbablyCompleted |
                               TOrderStateBitMask_Completed
                             )
                           ) ==
                           ( TOrderStateBitMask_NewOrderRequestPending |
                             TOrderStateBitMask_NewOrderRequestReceivedByBroker
                           )
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderStatusReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity == 0.0 );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Price == ::std::numeric_limits< double >::lowest() );

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderStatusReport1->iOrderNum;

               #pragma endregion
               #pragma region

               {
                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );

                  // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );

                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_NewOrderRequestPending ) );

                  // This will be used by {RequestCancelOrderIfInternalShallAndCan}.
                  orderPairIterator->second->StateBitMask = orderStateBitMask;
               }

               #pragma endregion
               #pragma region

               // yg? Not checking if we are logged in. In fact, we probably are as we received this order state update.
               // This doesn't raise events. Otherwise the behavior would have a chance to be incorrect.
               if( ! RequestCancelOrderIfInternalShallAndCan( * orderPairIterator->second ) )

               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
               else
               {
                  // This results in the logger object reference being obtained more than once. Although this rarely happens.
                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

                  static char const constantString1AsArray[]( "requested to cancel an order after it became possible" );

                  // yg? This is logged before the data itself.
                  // This creates another temporary string. Although this rarely happens.
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderStatusReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );

               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderStatusReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 "; %u"
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderStatusReport1->sOrderType.iDataLen
                 + orderStatusReport1->sBuySellType.iDataLen
                 + orderStatusReport1->sReportType.iDataLen
                 + orderStatusReport1->sText.iDataLen
                 + orderStatusReport1->sUserMsg.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderStatusReport1->iGatewaySsboe >= 0 );

               assert( orderStatusReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderStatusReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderStatusReport1->iGatewayUsecs )
                    )
               );
            
            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderStatusReport1->iSsboe >= 0 );

               assert( orderStatusReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderStatusReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderStatusReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
               assert( orderStatusReport1->iTriggerCmpOperator >= 0 );
               assert( orderStatusReport1->iTriggerPriceId >= 0 );

               assert( orderStatusReport1->iTotalFilled >= 0 );
               assert( orderStatusReport1->iGatewayBufferBytesBehind >= 0 );
               assert( orderStatusReport1->iConfirmedSize >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderStatusReport1->iOrderNum,
                      orderStatusReport1->sOrderType.iDataLen,
                      orderStatusReport1->sOrderType.pData,
                      orderStatusReport1->sBuySellType.iDataLen,
                      orderStatusReport1->sBuySellType.pData,
                      10,
                      orderStatusReport1->bPriceToFillFlag ? orderStatusReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderStatusReport1->bTriggerPriceFlag ? orderStatusReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderStatusReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderStatusReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderStatusReport1->iTotalFilled ),

                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderStatusReport1->iTotalUnfilled,

                      10,
                      orderStatusReport1->bAvgFillPriceFlag ? orderStatusReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderStatusReport1->sReportType.iDataLen,
                      orderStatusReport1->sReportType.pData,
                      orderStatusReport1->sText.iDataLen,
                      orderStatusReport1->sText.pData,
                      orderStatusReport1->sUserMsg.iDataLen,
                      orderStatusReport1->sUserMsg.pData,
                      orderStatusReport1->pContext,
                      static_cast< char >( orderStatusReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderStatusReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),

                      static_cast< unsigned int >( orderStatusReport1->iConfirmedSize )
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.information( tempString1 );
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }

      #pragma endregion
   }

#endif
#if( /* {(public) NotModifiedReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
//   int TREngineAdapter::NotModifiedReport
//      ( ::RApi::OrderNotModifiedReport * orderNotModifiedReport1,
//        void * /*context1*/,
//        int * /*outcomeCode2*/
//      )
//   {
//      #pragma region
//
//      // Visible universe.
//      //    {NotModifiedReport} -- base.
//      //       Implement.
//      //    //{orderNotModifiedReport1->iNotModifiedSize}.
//      //       Ignore.
//      //    {orderNotModifiedReport1->...}.
//      //       Possibly log some other fields.
//      // See visible universe in {LineUpdate}.
//
//      #pragma endregion
//      #pragma region
//
//      try
//      {
//         #pragma region
//
//         //::RApi::RCallbacks::...
//
//         #pragma endregion
//         #pragma region
//
//         // I don't want to assume these.
//         assert( orderNotModifiedReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
//         assert( orderNotModifiedReport1->iTotalFilled >= 0 );
//
//         // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
//         // I don't want to assume this.
//         assert( orderNotModifiedReport1->iTotalFilled + orderNotModifiedReport1->iTotalUnfilled > 0 );
//
//         // I don't want to assume this.
//         assert( ( orderNotModifiedReport1->iTotalFilled > 0 ) == orderNotModifiedReport1->bAvgFillPriceFlag );
//
//         #pragma endregion
//         #pragma region
//
//         {
//            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
//               ( SingleInstrumentsOrders_.find( orderNotModifiedReport1->pContext ) );
//
//            if( orderPairIterator != SingleInstrumentsOrders_.end() &&
//
//                // yg? See related comment in {LineUpdate}.
//                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
//              )
//            {
//               #pragma region
//
//               // See related comment in {LineUpdate}.
//               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
//                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
//                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                                                                                    )
//                                                                                                  ) !=
//                                                                                                  TOrderStateBitMask_None
//                                                                                               );
//
//               // I don't want to assume these.
//               assert( ( orderPairIterator->second->StateBitMask &
//                             ( TOrderStateBitMask_NewOrderRequestPending |
//                               TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                               //TOrderStateBitMask_LastModificationRequestPending |
//                               //TOrderStateBitMask_LastModificationRequestRejected |
//                               //TOrderStateBitMask_ShallBeCancelled |
//                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
//                               ////TOrderStateBitMask_LastCancellationRequestPending |
//                               ////TOrderStateBitMask_LastCancellationRequestRejected |
//                               //TOrderStateBitMask_CancellationRequestPending |
//                               //TOrderStateBitMask_TriggeredByBroker |
//                               //TOrderStateBitMask_TriggeredByExchange |
//                               //TOrderStateBitMask_ProbablyCompleted |
//                               //TOrderStateBitMask_Completed
//                             )
//                           ) ==
//                           TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                        );
//               assert( orderPairIterator->second->BrokerGeneratedId == orderNotModifiedReport1->iOrderNum );
//               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
//                           static_cast< double >( orderNotModifiedReport1->iTotalFilled )
//                        );
//               assert( orderPairIterator->second->FilledQuantityAndPrice.Price ==
//                           ( ( ! orderNotModifiedReport1->bAvgFillPriceFlag ) ?
//                             ::std::numeric_limits< double >::lowest() :
//                             orderNotModifiedReport1->dAvgFillPrice
//                           )
//                        );
//
//               #pragma endregion
//               #pragma region
//
//               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//               orderPairIterator->second->BrokerGeneratedId = orderNotModifiedReport1->iOrderNum;
//
//               #pragma endregion
//               #pragma region
//
//               {
//                  #pragma region
//
//                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
//
//                  #pragma endregion
//                  #pragma region
//
//                  if( orderNotModifiedReport1->sUserMsg.iDataLen == 1 &&
//                      ( * orderNotModifiedReport1->sUserMsg.pData ) == orderPairIterator->second->LastModificationRequestId()
//                    )
//                  {
//                     if( ( orderStateBitMask & TOrderStateBitMask_LastModificationRequestPending ) != TOrderStateBitMask_None )
//                     {
//                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//                           ( ( orderStateBitMask & TOrderStateBitMask_LastModificationRequestRejected ) == TOrderStateBitMask_None );
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_LastModificationRequestPending ) );
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_LastModificationRequestRejected );
//                     }
//                     else
//                     {
//                        // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                        ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
////TODO copy message from LineUpdate
//                        static char const constantString1AsArray[]( "the last order modification request is no longer pending" );
//
//                        // yg? This is logged before the data itself.
//                        // This creates another temporary string. Although this rarely happens.
//                        logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//                        // At this point it might make sense to set the {TOrderStateBitMask_LastModificationRequestRejected} bit
//                        // but let's not complicate things.
//                     }
//                  }
//                  else
//                  {
//                     // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
////TODO copy message from LineUpdate
//                     static char const constantString1AsArray[]( "a non-last order modification request was rejected" );
//
//                     // yg? This is logged before the data itself.
//                     // This creates another temporary string. Although this rarely happens.
//                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                  }
//
//                  #pragma endregion
//                  #pragma region
//
//                  // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                  orderStateBitMask =
//                     static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );
//
//                  // This will be used by {RequestCancelOrderIfInternalShallAndCan}.
//                  orderPairIterator->second->StateBitMask = orderStateBitMask;
//
//                  #pragma endregion
//               }
//
//               #pragma endregion
//               #pragma region
//
//               // yg? Not checking if we are logged in. In fact, we probably are as we received this order state update.
//               // This doesn't raise events. Otherwise the behavior would have a chance to be incorrect.
//               if( ! RequestCancelOrderIfInternalShallAndCan( * orderPairIterator->second ) )
//
//               {
//                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//               }
//               else
//               {
//                  // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                  static char const constantString1AsArray[]( "requested to cancel an order after it became possible" );
//
//                  // yg? This is logged before the data itself.
//                  // This creates another temporary string. Although this rarely happens.
//                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//               }
//
//               #pragma endregion
//               #pragma region
//
//               orderPairIterator->second->RaiseOnReceivedData();
//
//               #pragma endregion
//            }
//            else
//            {
//               #pragma region
//
//               static char const constantString1AsArray[]( "invalid {orderNotModifiedReport1->pContext}" );
//
//               // This results in the logger object reference being obtained more than once. Although this rarely happens.
//               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//               // yg? This is logged before the data itself.
//               // This creates another temporary string. Although this rarely happens.
//               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//               #pragma endregion
//            }
//         }
//
//         #pragma endregion
//         #pragma region
//
//         {
//            static char const formatConstantString1AsArray[]
//               ( "{RApi::OrderNotModifiedReport}"
//                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
//                 "; %u"
//               );
//
//            // Assuming this will not overflow.
//            int const tempString1BufferLength
//               ( 256
//                 + orderNotModifiedReport1->sOrderType.iDataLen
//                 + orderNotModifiedReport1->sBuySellType.iDataLen
//                 + orderNotModifiedReport1->sReportType.iDataLen
//                 + orderNotModifiedReport1->sText.iDataLen
//                 + orderNotModifiedReport1->sUserMsg.iDataLen
//               );
//
//            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
//
//            // I don't want to assume these.
//            {
//               // TODO 3 yg? This validation will fail in a few years.
//               assert( orderNotModifiedReport1->iGatewaySsboe >= 0 );
//
//               assert( orderNotModifiedReport1->iGatewayUsecs >= 0 );
//            }
//
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
//            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
//               ( static_cast< ::Poco::Int64 >
//                    ( static_cast< unsigned int >( orderNotModifiedReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
//                      static_cast< unsigned int >( orderNotModifiedReport1->iGatewayUsecs )
//                    )
//               );
//
//            // I don't want to assume these.
//            {
//               // This is probably positive but we will be OK even if this is 0.
//               // TODO 3 yg? This validation will fail in a few years.
//               assert( orderNotModifiedReport1->iSsboe >= 0 );
//
//               assert( orderNotModifiedReport1->iUsecs >= 0 );
//            }
//
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
//            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
//               ( static_cast< ::Poco::Int64 >
//                    ( static_cast< unsigned int >( orderNotModifiedReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
//                      static_cast< unsigned int >( orderNotModifiedReport1->iUsecs )
//                    )
//               );
//
//            // We will format these as an unsigned.
//            // I don't want to assume these.
//            {
//               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
//               assert( orderNotModifiedReport1->iTriggerCmpOperator >= 0 );
//               assert( orderNotModifiedReport1->iTriggerPriceId >= 0 );
//
//               assert( orderNotModifiedReport1->iTotalFilled >= 0 );
//               assert( orderNotModifiedReport1->iGatewayBufferBytesBehind >= 0 );
//
//               // This assertion might fail if a buggy app sends an invalid value, and that's not too bad.
//               assert( orderNotModifiedReport1->iNotModifiedSize >= 0 );
//            }
//
//            int tempString1Length
//               ( ::_snprintf_l
//                    ( ( & tempString1.front() ),
//                      static_cast< unsigned int >( tempString1BufferLength ),
//                      formatConstantString1AsArray,
//                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
//                      orderNotModifiedReport1->iOrderNum,
//                      orderNotModifiedReport1->sOrderType.iDataLen,
//                      orderNotModifiedReport1->sOrderType.pData,
//                      orderNotModifiedReport1->sBuySellType.iDataLen,
//                      orderNotModifiedReport1->sBuySellType.pData,
//                      10,
//                      orderNotModifiedReport1->bPriceToFillFlag ? orderNotModifiedReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
//                      10,
//                      orderNotModifiedReport1->bTriggerPriceFlag ? orderNotModifiedReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
//                      static_cast< unsigned int >( orderNotModifiedReport1->iTriggerCmpOperator ),
//                      static_cast< unsigned int >( orderNotModifiedReport1->iTriggerPriceId ),
//                      static_cast< unsigned int >( orderNotModifiedReport1->iTotalFilled ),
//
//                      // See a comment about this in the visible universe in {LineUpdate}.
//                      orderNotModifiedReport1->iTotalUnfilled,
//
//                      10,
//                      orderNotModifiedReport1->bAvgFillPriceFlag ? orderNotModifiedReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
//                      orderNotModifiedReport1->sReportType.iDataLen,
//                      orderNotModifiedReport1->sReportType.pData,
//                      orderNotModifiedReport1->sText.iDataLen,
//                      orderNotModifiedReport1->sText.pData,
//                      orderNotModifiedReport1->sUserMsg.iDataLen,
//                      orderNotModifiedReport1->sUserMsg.pData,
//                      orderNotModifiedReport1->pContext,
//                      static_cast< char >( orderNotModifiedReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
//                      static_cast< unsigned int >( orderNotModifiedReport1->iGatewayBufferBytesBehind ),
//
//                      // yg? Using current thread locale.
//                      ( ::Poco::DateTimeFormatter::format
//                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
//                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
//                           )
//                        .c_str()
//                      ),
//                      ( ::Poco::DateTimeFormatter::format
//                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
//                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
//                           )
//                        .c_str()
//                      ),
//
//                      static_cast< unsigned int >( orderNotModifiedReport1->iNotModifiedSize )
//                    )
//               );
//
//            if( tempString1Length >= 0 )
//            {
//               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
//            }
//            else
//            {
//               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
//            }
//
//            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//            logger1.warning( tempString1 );
//         }
//
//         #pragma endregion
//         #pragma region
//
//         return OK;
//
//         #pragma endregion
//      }
//      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
//      catch( ::OmneException const & exception1 )
//      {
//         #pragma region
//
//         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ::Poco::Exception const & exception1 )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ::std::exception const & exception1 )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ... )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//
//      #pragma endregion
//   }

#endif
#if( /* {(public) ModifyReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
//   int TREngineAdapter::ModifyReport
//      ( ::RApi::OrderModifyReport * orderModifyReport1,
//        void * /*context1*/,
//        int * /*outcomeCode2*/
//      )
//   {
//      #pragma region
//
//      // Visible universe.
//      //    {ModifyReport} -- base.
//      //       Implement.
//      //    //{orderModifyReport1->iNewSize}.
//      //       Ignore.
//      //       This probably equals {orderModifyReport1->iTotalFilled + orderModifyReport1->iTotalUnfilled}.
//      //       Although this might equal {orderModifyReport1->iTotalFilled} while {orderModifyReport1->iTotalUnfilled == 0}
//      //       if the quantity in the order modification request was less than the quantity already filled.
//      //       See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
//      //    {orderModifyReport1->...}.
//      //       Possibly log some other fields.
//      // See visible universe in {LineUpdate}.
//
//      #pragma endregion
//      #pragma region
//
//      try
//      {
//         #pragma region
//
//         //::RApi::RCallbacks::...
//
//         #pragma endregion
//         #pragma region
//
//         // I don't want to assume these.
//         assert( orderModifyReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
//         assert( orderModifyReport1->iTotalFilled >= 0 );
//
//         // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
//         // I don't want to assume this.
//         assert( orderModifyReport1->iTotalFilled + orderModifyReport1->iTotalUnfilled > 0 );
//
//         // I don't want to assume this.
//         assert( ( orderModifyReport1->iTotalFilled > 0 ) == orderModifyReport1->bAvgFillPriceFlag );
//
//         #pragma endregion
//         #pragma region
//
//         {
//            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
//               ( SingleInstrumentsOrders_.find( orderModifyReport1->pContext ) );
//
//            if( orderPairIterator != SingleInstrumentsOrders_.end() &&
//
//                // yg? See related comment in {LineUpdate}.
//                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
//              )
//            {
//               #pragma region
//
//               // See related comment in {LineUpdate}.
//               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
//                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
//                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                                                                                                    )
//                                                                                                  ) !=
//                                                                                                  TOrderStateBitMask_None
//                                                                                               );
//
//               // I don't want to assume these.
//               assert( ( orderPairIterator->second->StateBitMask &
//                             ( TOrderStateBitMask_NewOrderRequestPending |
//                               TOrderStateBitMask_NewOrderRequestReceivedByBroker |
//                               //TOrderStateBitMask_LastModificationRequestPending |
//                               //TOrderStateBitMask_LastModificationRequestRejected |
//                               //TOrderStateBitMask_ShallBeCancelled |
//                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
//                               ////TOrderStateBitMask_LastCancellationRequestPending |
//                               ////TOrderStateBitMask_LastCancellationRequestRejected |
//                               //TOrderStateBitMask_CancellationRequestPending |
//                               //TOrderStateBitMask_TriggeredByBroker |
//                               //TOrderStateBitMask_TriggeredByExchange |
//                               TOrderStateBitMask_ProbablyCompleted |
//                               TOrderStateBitMask_Completed
//                             )
//                           ) ==
//                           TOrderStateBitMask_NewOrderRequestReceivedByBroker
//                        );
//               assert( orderPairIterator->second->BrokerGeneratedId == orderModifyReport1->iOrderNum );
//               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
//                           static_cast< double >( orderModifyReport1->iTotalFilled )
//                        );
//               assert( orderPairIterator->second->FilledQuantityAndPrice.Price ==
//                           ( ( ! orderModifyReport1->bAvgFillPriceFlag ) ?
//                             ::std::numeric_limits< double >::lowest() :
//                             orderModifyReport1->dAvgFillPrice
//                           )
//                        );
//
//               #pragma endregion
//               #pragma region
//
//               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//               orderPairIterator->second->BrokerGeneratedId = orderModifyReport1->iOrderNum;
//
//               #pragma endregion
//               #pragma region
//
//               {
//                  #pragma region
//
//                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
//
//                  #pragma endregion
//                  #pragma region
//
//                  if( orderModifyReport1->sUserMsg.iDataLen == 1 &&
//                      ( * orderModifyReport1->sUserMsg.pData ) == orderPairIterator->second->LastModificationRequestId()
//                    )
//                  {
//                     if( ( orderStateBitMask & TOrderStateBitMask_LastModificationRequestPending ) != TOrderStateBitMask_None )
//                     {
//                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//                           ( ( orderStateBitMask & TOrderStateBitMask_LastModificationRequestRejected ) == TOrderStateBitMask_None );
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_LastModificationRequestPending ) );
//                     }
//                     else
//                     {
//                        // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                        ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
////TODO copy message from LineUpdate
//                        static char const constantString1AsArray[]( "the last order modification request is no longer pending" );
//
//                        // yg? This is logged before the data itself.
//                        // This creates another temporary string. Although this rarely happens.
//                        logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//                        // At this point it might make sense to clear the {TOrderStateBitMask_LastModificationRequestRejected} bit
//                        // but let's not complicate things.
//                     }
//                  }
//                  else
//                  {
//                     // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
////TODO copy message from LineUpdate
//                     static char const constantString1AsArray[]( "a non-last order modification request succeeded" );
//
//                     // yg? This is logged before the data itself.
//                     // This creates another temporary string. Although this rarely happens.
//                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                  }
//
//                  #pragma endregion
//                  #pragma region
//
//                  // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
//                  if( orderModifyReport1->iTotalUnfilled > 0 )
//
//                  {
//                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//                  }
//                  else
//                  {
//                     {
//                        // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                        ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                        // yg? If this is logged often I might want to comment this logging out. It's really normal behavior.
//                        static char const constantString1AsArray[]( "orderModifyReport1->iTotalUnfilled <= 0" );
//
//                        // yg? This is logged before the data itself.
//                        // This creates another temporary string. Although this rarely happens.
//                        logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                     }
//
//                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//
//                     // This logic probably can be unsafe if a buggy brokerage/exchange makes it posible
//                     // to modify an order to the already filled quantity and in a moment modify it again to a bigger quantity.
//                     // yg? I don't want to also set the {TOrderStateBitMask_Completed} bit.
//                     orderStateBitMask = static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_ProbablyCompleted );
//                  }
//
//                  #pragma endregion
//                  #pragma region
//
//                  // As asserted above, this is probably unnecessary but let's reinsure ourselves.
//                  orderStateBitMask =
//                     static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );
//
//                  // This will be used by {RequestCancelOrderIfInternalShallAndCan}.
//                  orderPairIterator->second->StateBitMask = orderStateBitMask;
//
//                  #pragma endregion
//               }
//
//               #pragma endregion
//               #pragma region
//
//               // yg? Not checking if we are logged in. In fact, we probably are as we received this order state update.
//               // This doesn't raise events. Otherwise the behavior would have a chance to be incorrect.
//               if( ! RequestCancelOrderIfInternalShallAndCan( * orderPairIterator->second ) )
//
//               {
//                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//               }
//               else
//               {
//                  // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                  static char const constantString1AsArray[]( "requested to cancel an order after it became possible" );
//
//                  // yg? This is logged before the data itself.
//                  // This creates another temporary string. Although this rarely happens.
//                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//               }
//
//               #pragma endregion
//               #pragma region
//
//               orderPairIterator->second->RaiseOnReceivedData();
//
//               #pragma endregion
//            }
//            else
//            {
//               #pragma region
//
//               static char const constantString1AsArray[]( "invalid {orderModifyReport1->pContext}" );
//
//               // This results in the logger object reference being obtained more than once. Although this rarely happens.
//               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//               // yg? This is logged before the data itself.
//               // This creates another temporary string. Although this rarely happens.
//               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//               #pragma endregion
//            }
//         }
//
//         #pragma endregion
//         #pragma region
//
//         {
//            static char const formatConstantString1AsArray[]
//               ( "{RApi::OrderModifyReport}"
//                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
//                 "; %u"
//               );
//
//            // Assuming this will not overflow.
//            int const tempString1BufferLength
//               ( 256
//                 + orderModifyReport1->sOrderType.iDataLen
//                 + orderModifyReport1->sBuySellType.iDataLen
//                 + orderModifyReport1->sReportType.iDataLen
//                 + orderModifyReport1->sText.iDataLen
//                 + orderModifyReport1->sUserMsg.iDataLen
//               );
//
//            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
//
//            // I don't want to assume these.
//            {
//               // TODO 3 yg? This validation will fail in a few years.
//               assert( orderModifyReport1->iGatewaySsboe >= 0 );
//
//               assert( orderModifyReport1->iGatewayUsecs >= 0 );
//            }
//
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
//            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
//               ( static_cast< ::Poco::Int64 >
//                    ( static_cast< unsigned int >( orderModifyReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
//                      static_cast< unsigned int >( orderModifyReport1->iGatewayUsecs )
//                    )
//               );
//
//            // I don't want to assume these.
//            {
//               // This is probably positive but we will be OK even if this is 0.
//               // TODO 3 yg? This validation will fail in a few years.
//               assert( orderModifyReport1->iSsboe >= 0 );
//
//               assert( orderModifyReport1->iUsecs >= 0 );
//            }
//
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
//            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
//               ( static_cast< ::Poco::Int64 >
//                    ( static_cast< unsigned int >( orderModifyReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
//                      static_cast< unsigned int >( orderModifyReport1->iUsecs )
//                    )
//               );
//
//            // We will format these as an unsigned.
//            // I don't want to assume these.
//            {
//               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
//               assert( orderModifyReport1->iTriggerCmpOperator >= 0 );
//               assert( orderModifyReport1->iTriggerPriceId >= 0 );
//
//               assert( orderModifyReport1->iTotalFilled >= 0 );
//               assert( orderModifyReport1->iGatewayBufferBytesBehind >= 0 );
//               assert( orderModifyReport1->iNewSize >= 0 );
//            }
//
//            int tempString1Length
//               ( ::_snprintf_l
//                    ( ( & tempString1.front() ),
//                      static_cast< unsigned int >( tempString1BufferLength ),
//                      formatConstantString1AsArray,
//                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
//                      orderModifyReport1->iOrderNum,
//                      orderModifyReport1->sOrderType.iDataLen,
//                      orderModifyReport1->sOrderType.pData,
//                      orderModifyReport1->sBuySellType.iDataLen,
//                      orderModifyReport1->sBuySellType.pData,
//                      10,
//                      orderModifyReport1->bPriceToFillFlag ? orderModifyReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
//                      10,
//                      orderModifyReport1->bTriggerPriceFlag ? orderModifyReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
//                      static_cast< unsigned int >( orderModifyReport1->iTriggerCmpOperator ),
//                      static_cast< unsigned int >( orderModifyReport1->iTriggerPriceId ),
//                      static_cast< unsigned int >( orderModifyReport1->iTotalFilled ),
//
//                      // See a comment about this in the visible universe in {LineUpdate}.
//                      orderModifyReport1->iTotalUnfilled,
//
//                      10,
//                      orderModifyReport1->bAvgFillPriceFlag ? orderModifyReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
//                      orderModifyReport1->sReportType.iDataLen,
//                      orderModifyReport1->sReportType.pData,
//                      orderModifyReport1->sText.iDataLen,
//                      orderModifyReport1->sText.pData,
//                      orderModifyReport1->sUserMsg.iDataLen,
//                      orderModifyReport1->sUserMsg.pData,
//                      orderModifyReport1->pContext,
//                      static_cast< char >( orderModifyReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
//                      static_cast< unsigned int >( orderModifyReport1->iGatewayBufferBytesBehind ),
//
//                      // yg? Using current thread locale.
//                      ( ::Poco::DateTimeFormatter::format
//                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
//                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
//                           )
//                        .c_str()
//                      ),
//                      ( ::Poco::DateTimeFormatter::format
//                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
//                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
//                           )
//                        .c_str()
//                      ),
//
//                      static_cast< unsigned int >( orderModifyReport1->iNewSize )
//                    )
//               );
//
//            if( tempString1Length >= 0 )
//            {
//               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
//            }
//            else
//            {
//               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
//            }
//
//            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//            logger1.information( tempString1 );
//         }
//
//         #pragma endregion
//         #pragma region
//
//         return OK;
//
//         #pragma endregion
//      }
//      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
//      catch( ::OmneException const & exception1 )
//      {
//         #pragma region
//
//         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ::Poco::Exception const & exception1 )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ::std::exception const & exception1 )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//      catch( ... )
//      {
//         #pragma region
//
//         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
//         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
//
//         #pragma endregion
//      }
//
//      #pragma endregion
//   }

#endif
#if( /* {(public) NotCancelledReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO Test this somehow.
   int TREngineAdapter::NotCancelledReport
      ( ::RApi::OrderNotCancelledReport * orderNotCancelledReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      // Visible universe.
      //    {NotCancelledReport} -- base.
      //       Implement.
      //    //{orderNotCancelledReport1->iNotCancelledSize}.
      //       Ignore.
      //       Just like {orderNotCancelledReport1->iTotalUnfilled}, expecting this to be negative.
      //    {orderNotCancelledReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderNotCancelledReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderNotCancelledReport1->iTotalFilled >= 0 );

         // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
         // I don't want to assume this.
         assert( orderNotCancelledReport1->iTotalFilled + orderNotCancelledReport1->iTotalUnfilled > 0 );

         // I don't want to assume this.
         assert( ( orderNotCancelledReport1->iTotalFilled > 0 ) == orderNotCancelledReport1->bAvgFillPriceFlag );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderNotCancelledReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region

               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |
                               TOrderStateBitMask_CancellationRequestPending
                               //TOrderStateBitMask_TriggeredByBroker |
                               //TOrderStateBitMask_TriggeredByExchange |
                               //TOrderStateBitMask_ProbablyCompleted |
                               //TOrderStateBitMask_Completed
                             )
                           ) ==
                           ( TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                             TOrderStateBitMask_CancellationRequestPending
                           )
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderNotCancelledReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
                           static_cast< double >( orderNotCancelledReport1->iTotalFilled )
                        );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Price ==
                           ( ( ! orderNotCancelledReport1->bAvgFillPriceFlag ) ?
                             ::std::numeric_limits< double >::lowest() :
                             orderNotCancelledReport1->dAvgFillPrice
                           )
                        );

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderNotCancelledReport1->iOrderNum;

               #pragma endregion
               #pragma region

               {
                  #pragma region

                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );

                  #pragma endregion
                  #pragma region //TODO REMOVE

//TODO remove

//                  // yg? Using the loose cancellation request ID comparison.
//                  if( orderPairIterator->second->LastCancellationRequestIdMatchesLoosely( orderNotCancelledReport1->sUserMsg ) )
//
//                  {
//                     if( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestPending ) != TOrderStateBitMask_None )
//                     {
//                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//                           ( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestRejected ) == TOrderStateBitMask_None );
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_LastCancellationRequestPending ) );
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_LastCancellationRequestRejected );
//                     }
//                     else
//                     {
//                        // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                        ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
////TODO more descriptive msg, like the next one
//                        static char const constantString1AsArray[]( "the last order cancellation request is no longer pending" );
//
//                        // yg? This is logged before the data itself.
//                        // This creates another temporary string. Although this rarely happens.
//                        logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//                        // At this point it might make sense to set the {TOrderStateBitMask_LastCancellationRequestRejected} bit
//                        // but let's not complicate things.
//                     }
//                  }
//                  else
//                  {
//                     // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                     static char const constantString1AsArray[]( "a non-last order cancellation request was rejected" );
//
//                     // yg? This is logged before the data itself.
//                     // This creates another temporary string. Although this rarely happens.
//                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                  }

                  #pragma endregion
                  #pragma region

                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >
                        ( orderStateBitMask |

                          // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                          TOrderStateBitMask_NewOrderRequestReceivedByBroker |

//TODO remove comment
                          // We are probably not in rush to set this bit before we actually determine
                          // that we can't immediatelly re-request to cancel this order
                          // but it's more efficient to set it here along with the other bits.
                          // This logic doesn't need to check that the order is not complete yet.
                          TOrderStateBitMask_ShallBeCancelled
                        );

//TODO read
                  // yg? Chances are, this order report indicates the completion of the previously seen pending cancellation request, if any,
                  // yg? and the brokerage doesn't hold another cancellation request to be sent to the exchange,
                  // yg? unless the {TOrderStateBitMask_LastCancellationRequestPending} bit is 1 but that logic is separate.
                  // yg? So I want to speculatively clear the {TOrderStateBitMask_CancellationRequestPending} bit
                  // yg? to allow immediate sending of another cancellation request.
                  // yg? This logic probably can be improved by remembering and then comparing the ID of the pending cancellation request
                  // yg? but it can require some trial and error to get it right.
                  // yg? Then it would probably make sense to clear this bit in {CancelReport} and possibly some other callbacks.
                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_CancellationRequestPending ) );

                  // This will be used by {RequestCancelOrderIfInternalCan}.
                  orderPairIterator->second->StateBitMask = orderStateBitMask;

                  #pragma endregion
               }

               #pragma endregion
               #pragma region

               // yg? Not checking if we are logged in. In fact, we probably are as we received this order state update.
               // This doesn't raise events. Otherwise the behavior would have a chance to be incorrect.
               if( RequestCancelOrderIfInternalCan( * orderPairIterator->second ) )

               {
                  // This results in the logger object reference being obtained more than once. Although this rarely happens.
                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

                  static char const constantString1AsArray[]( "re-requested to cancel an order" );

                  // yg? This is logged before the data itself.
                  // This creates another temporary string. Although this rarely happens.
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }
               else
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderNotCancelledReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );

               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderNotCancelledReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 "; %i"
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderNotCancelledReport1->sOrderType.iDataLen
                 + orderNotCancelledReport1->sBuySellType.iDataLen
                 + orderNotCancelledReport1->sReportType.iDataLen
                 + orderNotCancelledReport1->sText.iDataLen
                 + orderNotCancelledReport1->sUserMsg.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderNotCancelledReport1->iGatewaySsboe >= 0 );

               assert( orderNotCancelledReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderNotCancelledReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderNotCancelledReport1->iGatewayUsecs )
                    )
               );
            
            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderNotCancelledReport1->iSsboe >= 0 );

               assert( orderNotCancelledReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderNotCancelledReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderNotCancelledReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
               assert( orderNotCancelledReport1->iTriggerCmpOperator >= 0 );
               assert( orderNotCancelledReport1->iTriggerPriceId >= 0 );

               assert( orderNotCancelledReport1->iTotalFilled >= 0 );
               assert( orderNotCancelledReport1->iGatewayBufferBytesBehind >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderNotCancelledReport1->iOrderNum,
                      orderNotCancelledReport1->sOrderType.iDataLen,
                      orderNotCancelledReport1->sOrderType.pData,
                      orderNotCancelledReport1->sBuySellType.iDataLen,
                      orderNotCancelledReport1->sBuySellType.pData,
                      10,
                      orderNotCancelledReport1->bPriceToFillFlag ? orderNotCancelledReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderNotCancelledReport1->bTriggerPriceFlag ? orderNotCancelledReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderNotCancelledReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderNotCancelledReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderNotCancelledReport1->iTotalFilled ),

                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderNotCancelledReport1->iTotalUnfilled,

                      10,
                      orderNotCancelledReport1->bAvgFillPriceFlag ? orderNotCancelledReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderNotCancelledReport1->sReportType.iDataLen,
                      orderNotCancelledReport1->sReportType.pData,
                      orderNotCancelledReport1->sText.iDataLen,
                      orderNotCancelledReport1->sText.pData,
                      orderNotCancelledReport1->sUserMsg.iDataLen,
                      orderNotCancelledReport1->sUserMsg.pData,
                      orderNotCancelledReport1->pContext,
                      static_cast< char >( orderNotCancelledReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderNotCancelledReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),

                      // See a comment about this in the visible universe.
                      orderNotCancelledReport1->iNotCancelledSize
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.warning( tempString1 );
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
   
      #pragma endregion
   }

#endif
#if( /* {(public) CancelReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::CancelReport
      ( ::RApi::OrderCancelReport * orderCancelReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      // Visible universe.
      //    {CancelReport} -- base.
      //       Implement.
      //    //{orderCancelReport1->iCancelledSize}.
      //       Ignore.
      //       Just like {orderCancelReport1->iTotalUnfilled}, expecting this to be negative.
      //    {orderCancelReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderCancelReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderCancelReport1->iTotalFilled >= 0 );

         // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
         // I don't want to assume this.
         assert( orderCancelReport1->iTotalFilled + orderCancelReport1->iTotalUnfilled > 0 );

         // I don't want to assume this.
         assert( ( orderCancelReport1->iTotalFilled > 0 ) == orderCancelReport1->bAvgFillPriceFlag );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderCancelReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region

               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |

                               // It's possible that this bit is 0
                               // because an order can be cancelled spontaneously without a prior cancellation request.
                               //TOrderStateBitMask_CancellationRequestPending |

                               //TOrderStateBitMask_TriggeredByBroker |
                               //TOrderStateBitMask_TriggeredByExchange |
                               TOrderStateBitMask_ProbablyCompleted |
                               TOrderStateBitMask_Completed
                             )
                           ) ==
                           TOrderStateBitMask_NewOrderRequestReceivedByBroker
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderCancelReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
                           static_cast< double >( orderCancelReport1->iTotalFilled )
                        );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Price ==
                           ( ( ! orderCancelReport1->bAvgFillPriceFlag ) ?
                             ::std::numeric_limits< double >::lowest() :
                             orderCancelReport1->dAvgFillPrice
                           )
                        );

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderCancelReport1->iOrderNum;

               #pragma endregion
               #pragma region

               {
                  #pragma region

                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );

                  #pragma endregion
                  #pragma region //TODO remove

//TODO remove

//   #if( ! defined( NDEBUG ) )
//
//                  // yg? Using the loose cancellation request ID comparison.
//                  if( orderPairIterator->second->LastCancellationRequestIdMatchesLoosely( orderCancelReport1->sUserMsg ) )
//
//                  {
//                     if( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestPending ) != TOrderStateBitMask_None )
//                     {
//                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//                           ( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestRejected ) == TOrderStateBitMask_None );
//                        orderStateBitMask =
//                           static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_LastCancellationRequestPending ) );
//                     }
//                     else
//                     {
//                        // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                        ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
////TODO more descriptive msg, like the next one
//                        static char const constantString1AsArray[]( "the last order cancellation request is no longer pending" );
//
//                        // yg? This is logged before the data itself.
//                        // This creates another temporary string. Although this rarely happens.
//                        logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//
//                        // At this point it might make sense to clear the {TOrderStateBitMask_LastCancellationRequestRejected} bit
//                        // but let's not complicate things.
//                     }
//                  }
//                  else
//                  {
//                     // This results in the logger object reference being obtained more than once. Although this rarely happens.
//                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//
//                     static char const constantString1AsArray[]( "a non-last order cancellation request succeeded" );
//
//                     // yg? This is logged before the data itself.
//                     // This creates another temporary string. Although this rarely happens.
//                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//                  }
//
//   #else
//
//                  // It's better to not log any errors because an order can be cancelled spontaneously without a prior cancellation request.
//                  // This checks the same conditions as above but in a more efficient order.
//                  // At least some comments in the debug code above apply here as well.
//                  {
//                     if( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestPending ) != TOrderStateBitMask_None )
//                     {
//                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//                           ( ( orderStateBitMask & TOrderStateBitMask_LastCancellationRequestRejected ) == TOrderStateBitMask_None );
//
//                        if( orderPairIterator->second->LastCancellationRequestIdMatchesLoosely( orderCancelReport1->sUserMsg ) )
//                        {
//                           orderStateBitMask =
//                              static_cast< TOrderStateBitMask >( orderStateBitMask & ( ~ TOrderStateBitMask_LastCancellationRequestPending ) );
//                        }
//                        else
//                        {
//                           ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//                        }
//                     }
//                     else
//                     {
//                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//                     }
//                  }
//
//   #endif

                  #pragma endregion
                  #pragma region

                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >
                        ( orderStateBitMask |

                          // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                          TOrderStateBitMask_NewOrderRequestReceivedByBroker |

                          TOrderStateBitMask_ProbablyCompleted |
                          TOrderStateBitMask_Completed
                        );
                  orderPairIterator->second->StateBitMask = orderStateBitMask;

                  #pragma endregion
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderCancelReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );

               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderCancelReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 "; %i"
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderCancelReport1->sOrderType.iDataLen
                 + orderCancelReport1->sBuySellType.iDataLen
                 + orderCancelReport1->sReportType.iDataLen
                 + orderCancelReport1->sText.iDataLen
                 + orderCancelReport1->sUserMsg.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderCancelReport1->iGatewaySsboe >= 0 );

               assert( orderCancelReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderCancelReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderCancelReport1->iGatewayUsecs )
                    )
               );
            
            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderCancelReport1->iSsboe >= 0 );

               assert( orderCancelReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderCancelReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderCancelReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
               assert( orderCancelReport1->iTriggerCmpOperator >= 0 );
               assert( orderCancelReport1->iTriggerPriceId >= 0 );

               assert( orderCancelReport1->iTotalFilled >= 0 );
               assert( orderCancelReport1->iGatewayBufferBytesBehind >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderCancelReport1->iOrderNum,
                      orderCancelReport1->sOrderType.iDataLen,
                      orderCancelReport1->sOrderType.pData,
                      orderCancelReport1->sBuySellType.iDataLen,
                      orderCancelReport1->sBuySellType.pData,
                      10,
                      orderCancelReport1->bPriceToFillFlag ? orderCancelReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderCancelReport1->bTriggerPriceFlag ? orderCancelReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderCancelReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderCancelReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderCancelReport1->iTotalFilled ),

                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderCancelReport1->iTotalUnfilled,
                      
                      10,
                      orderCancelReport1->bAvgFillPriceFlag ? orderCancelReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderCancelReport1->sReportType.iDataLen,
                      orderCancelReport1->sReportType.pData,
                      orderCancelReport1->sText.iDataLen,
                      orderCancelReport1->sText.pData,
                      orderCancelReport1->sUserMsg.iDataLen,
                      orderCancelReport1->sUserMsg.pData,
                      orderCancelReport1->pContext,
                      static_cast< char >( orderCancelReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderCancelReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),

                      // See a comment about this in the visible universe.
                      orderCancelReport1->iCancelledSize
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.information( tempString1 );
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }

      #pragma endregion
   }

#endif
#if( /* {(public) TriggerPulledReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::TriggerPulledReport
      ( ::RApi::OrderTriggerPulledReport * orderTriggerPulledReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      // Visible universe.
      //    {TriggerPulledReport} -- base.
      //       Implement.
      //    {orderTriggerPulledReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderTriggerPulledReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderTriggerPulledReport1->iTotalFilled == 0 );
         assert( orderTriggerPulledReport1->iTotalUnfilled > 0 );
         assert( ! orderTriggerPulledReport1->bAvgFillPriceFlag );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderTriggerPulledReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region

               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |
                               //TOrderStateBitMask_CancellationRequestPending |
                               TOrderStateBitMask_TriggeredByBroker |
                               TOrderStateBitMask_TriggeredByExchange |
                               TOrderStateBitMask_ProbablyCompleted |
                               TOrderStateBitMask_Completed
                             )
                           ) ==
                           TOrderStateBitMask_NewOrderRequestReceivedByBroker
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderTriggerPulledReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity == 0.0 );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Price == ::std::numeric_limits< double >::lowest() );

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderTriggerPulledReport1->iOrderNum;

               #pragma endregion
               #pragma region

               {
                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >
                        ( orderStateBitMask |
                          TOrderStateBitMask_NewOrderRequestPending |

                          // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                          TOrderStateBitMask_NewOrderRequestReceivedByBroker |

                          TOrderStateBitMask_TriggeredByBroker
                        );
                  orderPairIterator->second->StateBitMask = orderStateBitMask;
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderTriggerPulledReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );

               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderTriggerPulledReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 ""
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderTriggerPulledReport1->sOrderType.iDataLen
                 + orderTriggerPulledReport1->sBuySellType.iDataLen
                 + orderTriggerPulledReport1->sReportType.iDataLen
                 + orderTriggerPulledReport1->sText.iDataLen
                 + orderTriggerPulledReport1->sUserMsg.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
            
            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderTriggerPulledReport1->iGatewaySsboe >= 0 );

               assert( orderTriggerPulledReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderTriggerPulledReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderTriggerPulledReport1->iGatewayUsecs )
                    )
               );
            
            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderTriggerPulledReport1->iSsboe >= 0 );

               assert( orderTriggerPulledReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderTriggerPulledReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderTriggerPulledReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
               assert( orderTriggerPulledReport1->iTriggerCmpOperator >= 0 );
               assert( orderTriggerPulledReport1->iTriggerPriceId >= 0 );

               assert( orderTriggerPulledReport1->iTotalFilled >= 0 );
               assert( orderTriggerPulledReport1->iGatewayBufferBytesBehind >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderTriggerPulledReport1->iOrderNum,
                      orderTriggerPulledReport1->sOrderType.iDataLen,
                      orderTriggerPulledReport1->sOrderType.pData,
                      orderTriggerPulledReport1->sBuySellType.iDataLen,
                      orderTriggerPulledReport1->sBuySellType.pData,
                      10,
                      orderTriggerPulledReport1->bPriceToFillFlag ? orderTriggerPulledReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderTriggerPulledReport1->bTriggerPriceFlag ? orderTriggerPulledReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderTriggerPulledReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderTriggerPulledReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderTriggerPulledReport1->iTotalFilled ),
                      
                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderTriggerPulledReport1->iTotalUnfilled,

                      10,
                      orderTriggerPulledReport1->bAvgFillPriceFlag ? orderTriggerPulledReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderTriggerPulledReport1->sReportType.iDataLen,
                      orderTriggerPulledReport1->sReportType.pData,
                      orderTriggerPulledReport1->sText.iDataLen,
                      orderTriggerPulledReport1->sText.pData,
                      orderTriggerPulledReport1->sUserMsg.iDataLen,
                      orderTriggerPulledReport1->sUserMsg.pData,
                      orderTriggerPulledReport1->pContext,
                      static_cast< char >( orderTriggerPulledReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderTriggerPulledReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      )
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.information( tempString1 );
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      
         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      
         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      
         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      
         #pragma endregion
      }
   
      #pragma endregion
   }

#endif
#if( /* {(public) TriggerReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::TriggerReport
      ( ::RApi::OrderTriggerReport * orderTriggerReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      // Visible universe.
      //    {TriggerReport} -- base.
      //       Implement.
      //    //{orderTriggerReport1->iConfirmedSize}.
      //       Ignore.
      //    {orderTriggerReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderTriggerReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderTriggerReport1->iTotalFilled == 0 );
         assert( orderTriggerReport1->iTotalUnfilled > 0 );
         assert( ! orderTriggerReport1->bAvgFillPriceFlag );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderTriggerReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region

               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |
                               //TOrderStateBitMask_CancellationRequestPending |
                               TOrderStateBitMask_TriggeredByBroker |
                               TOrderStateBitMask_TriggeredByExchange |
                               TOrderStateBitMask_ProbablyCompleted |
                               TOrderStateBitMask_Completed
                             )
                           ) ==
                           TOrderStateBitMask_NewOrderRequestReceivedByBroker
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderTriggerReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity == 0.0 );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Price == ::std::numeric_limits< double >::lowest() );

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderTriggerReport1->iOrderNum;

               #pragma endregion
               #pragma region

               {
                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );
                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >
                        ( orderStateBitMask |

                          // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                          TOrderStateBitMask_NewOrderRequestReceivedByBroker |

                          TOrderStateBitMask_TriggeredByExchange
                        );
                  orderPairIterator->second->StateBitMask = orderStateBitMask;
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderTriggerReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );

               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderTriggerReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 "; %u"
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderTriggerReport1->sOrderType.iDataLen
                 + orderTriggerReport1->sBuySellType.iDataLen
                 + orderTriggerReport1->sReportType.iDataLen
                 + orderTriggerReport1->sText.iDataLen
                 + orderTriggerReport1->sUserMsg.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderTriggerReport1->iGatewaySsboe >= 0 );

               assert( orderTriggerReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderTriggerReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderTriggerReport1->iGatewayUsecs )
                    )
               );
            
            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderTriggerReport1->iSsboe >= 0 );

               assert( orderTriggerReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderTriggerReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderTriggerReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
               assert( orderTriggerReport1->iTriggerCmpOperator >= 0 );
               assert( orderTriggerReport1->iTriggerPriceId >= 0 );

               assert( orderTriggerReport1->iTotalFilled >= 0 );
               assert( orderTriggerReport1->iGatewayBufferBytesBehind >= 0 );
               assert( orderTriggerReport1->iConfirmedSize >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderTriggerReport1->iOrderNum,
                      orderTriggerReport1->sOrderType.iDataLen,
                      orderTriggerReport1->sOrderType.pData,
                      orderTriggerReport1->sBuySellType.iDataLen,
                      orderTriggerReport1->sBuySellType.pData,
                      10,
                      orderTriggerReport1->bPriceToFillFlag ? orderTriggerReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderTriggerReport1->bTriggerPriceFlag ? orderTriggerReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderTriggerReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderTriggerReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderTriggerReport1->iTotalFilled ),

                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderTriggerReport1->iTotalUnfilled,

                      10,
                      orderTriggerReport1->bAvgFillPriceFlag ? orderTriggerReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderTriggerReport1->sReportType.iDataLen,
                      orderTriggerReport1->sReportType.pData,
                      orderTriggerReport1->sText.iDataLen,
                      orderTriggerReport1->sText.pData,
                      orderTriggerReport1->sUserMsg.iDataLen,
                      orderTriggerReport1->sUserMsg.pData,
                      orderTriggerReport1->pContext,
                      static_cast< char >( orderTriggerReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderTriggerReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),

                      static_cast< unsigned int >( orderTriggerReport1->iConfirmedSize )
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }
        
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.information( tempString1 );
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }

      #pragma endregion
   }

#endif
#if( /* {(public) FillReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::FillReport
      ( ::RApi::OrderFillReport * orderFillReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      // Visible universe.
      //    {FillReport} -- base.
      //       Implement.
      //    {orderFillReport1->dFillPrice}.
      //       Validate.
      //    {orderFillReport1->bFillPriceFlag}.
      //       Validate.
      //    {orderFillReport1->iFillSize}.
      //       Validate.
      //    //{orderFillReport1->sLiquidityIndicator}.
      //       yg? Ignore.
      //       yg? Can we use this in any logic?
      //    {orderFillReport1->iRpCode}.
      //       yg? Validate.
      //       yg? We only use this in some logic that doesn't affect the behavior.
      //       TODO 3 yg? Handle this somehow.
      //    {orderFillReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderFillReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderFillReport1->iTotalFilled > 0 );
         assert( orderFillReport1->iTotalUnfilled >= 0 );
         assert( orderFillReport1->bAvgFillPriceFlag );

   #if( ! defined( NDEBUG ) )
         // As asserted below, it's probably OK to not check {orderFillReport1->bFillPriceFlag}.
         // At worst, this will validate 0.0.
         // yg? Logging this before the data itself.
         SafeTryValidateInstrumentPrice( orderFillReport1->dFillPrice );
   #endif

         // I don't want to assume these.
         assert( orderFillReport1->bFillPriceFlag );
         assert( orderFillReport1->iFillSize > 0 );
         assert( orderFillReport1->iFillSize <= orderFillReport1->iTotalFilled );
         assert( orderFillReport1->iRpCode == API_OK );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderFillReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region

               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |
                               //TOrderStateBitMask_CancellationRequestPending |
                               //TOrderStateBitMask_TriggeredByBroker |
                               //TOrderStateBitMask_TriggeredByExchange |
                               TOrderStateBitMask_ProbablyCompleted |
                               TOrderStateBitMask_Completed
                             )
                           ) ==
                           TOrderStateBitMask_NewOrderRequestReceivedByBroker
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderFillReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
                           static_cast< double >( orderFillReport1->iTotalFilled - orderFillReport1->iFillSize )
                        );
               //assert( orderPairIterator->second->FilledQuantityAndPrice.Price == ...

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderFillReport1->iOrderNum;

               #pragma endregion
               #pragma region

               // yg? As asserted above, it's probably OK to not check that this is positive.
               // It's probably unnecessary to round this.
               orderPairIterator->second->FilledQuantityAndPrice.Quantity =
                  static_cast< double >( orderFillReport1->iTotalFilled );

               // yg? As asserted above, it's probably OK to not check {orderFillReport1->bAvgFillPriceFlag}.
               // yg? At worst, this will assign 0.0, which can in fact inflict damge.
               orderPairIterator->second->FilledQuantityAndPrice.Price = orderFillReport1->dAvgFillPrice;

               #pragma endregion
               #pragma region

               {
                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );

                  if( orderFillReport1->iTotalUnfilled > 0 )
                  {
                     // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                     orderStateBitMask =
                        static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );
                  }
                  else
                  {
                     orderStateBitMask =
                        static_cast< TOrderStateBitMask >
                           ( orderStateBitMask |

                             // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                             TOrderStateBitMask_NewOrderRequestReceivedByBroker |

                             // yg? I don't want to also set the {TOrderStateBitMask_Completed} bit.
                             TOrderStateBitMask_ProbablyCompleted
                           );
                  }

                  orderPairIterator->second->StateBitMask = orderStateBitMask;
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderFillReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );

               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderFillReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 "; %+.*g; %u; %.*s; %.*s; %i; %.*s"
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderFillReport1->sOrderType.iDataLen
                 + orderFillReport1->sBuySellType.iDataLen
                 + orderFillReport1->sReportType.iDataLen
                 + orderFillReport1->sText.iDataLen
                 + orderFillReport1->sUserMsg.iDataLen
                 + orderFillReport1->sFillType.iDataLen
                 + orderFillReport1->sLiquidityIndicator.iDataLen
                 + orderFillReport1->sRpCode.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderFillReport1->iGatewaySsboe >= 0 );

               assert( orderFillReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderFillReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderFillReport1->iGatewayUsecs )
                    )
               );

            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderFillReport1->iSsboe >= 0 );

               assert( orderFillReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderFillReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderFillReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
               assert( orderFillReport1->iTriggerCmpOperator >= 0 );
               assert( orderFillReport1->iTriggerPriceId >= 0 );

               assert( orderFillReport1->iTotalFilled >= 0 );
               assert( orderFillReport1->iGatewayBufferBytesBehind >= 0 );
               assert( orderFillReport1->iFillSize >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderFillReport1->iOrderNum,
                      orderFillReport1->sOrderType.iDataLen,
                      orderFillReport1->sOrderType.pData,
                      orderFillReport1->sBuySellType.iDataLen,
                      orderFillReport1->sBuySellType.pData,
                      10,
                      orderFillReport1->bPriceToFillFlag ? orderFillReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderFillReport1->bTriggerPriceFlag ? orderFillReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderFillReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderFillReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderFillReport1->iTotalFilled ),

                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderFillReport1->iTotalUnfilled,

                      10,
                      orderFillReport1->bAvgFillPriceFlag ? orderFillReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderFillReport1->sReportType.iDataLen,
                      orderFillReport1->sReportType.pData,
                      orderFillReport1->sText.iDataLen,
                      orderFillReport1->sText.pData,
                      orderFillReport1->sUserMsg.iDataLen,
                      orderFillReport1->sUserMsg.pData,
                      orderFillReport1->pContext,
                      static_cast< char >( orderFillReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderFillReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),

                      10,
                      orderFillReport1->bFillPriceFlag ? orderFillReport1->dFillPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderFillReport1->iFillSize ),
                      orderFillReport1->sFillType.iDataLen,
                      orderFillReport1->sFillType.pData,
                      orderFillReport1->sLiquidityIndicator.iDataLen,
                      orderFillReport1->sLiquidityIndicator.pData,

                      // This is probably not negative but I don't want to format this as an unsigned. We still don't format the '+' sign.
                      orderFillReport1->iRpCode,

                      orderFillReport1->sRpCode.iDataLen,
                      orderFillReport1->sRpCode.pData
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            // yg? Consider logging a separate message when this condition is {false}.
            // yg? But as of 10/18/2013 I haven't seen this condition being {false}.
            if( orderFillReport1->iRpCode == API_OK )

            {
               logger1.information( tempString1 );
            }
            else
            {
               // yg? If the error is not too severe it might be better to mark this a "Warning".
               logger1.error( tempString1 );

               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            }
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }

      #pragma endregion
   }

#endif
#if( /* {(public) TradeCorrectReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::TradeCorrectReport
      ( ::RApi::OrderTradeCorrectReport * orderTradeCorrectReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

      // <Quote>This method is invoked when the engine receives a report from the infrastructure
      // indicating that a trade correction has occurred.</Quote>
      // <Quote>The OrderTradeCorrectReport represents a trade which is under investigation.</Quote>
      // yg? So is it correction or investigation?
      // Regardless, assuming that cumulative filled quantity and price are valid, so we pretty much treat this report as a fill report.
      
      // Visible universe.
      //    {TradeCorrectReport} -- base.
      //       Implement.
      //    {orderTradeCorrectReport1->dFillPrice}.
      //       Validate.
      //    {orderTradeCorrectReport1->bFillPriceFlag}.
      //       Validate.
      //    {orderTradeCorrectReport1->iFillSize}.
      //       Validate.
      //    {orderTradeCorrectReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderTradeCorrectReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderTradeCorrectReport1->iTotalFilled > 0 );

         // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
         // I don't want to assume this.
         assert( orderTradeCorrectReport1->iTotalFilled + orderTradeCorrectReport1->iTotalUnfilled > 0 );

         // I don't want to assume this.
         assert( orderTradeCorrectReport1->bAvgFillPriceFlag );

   #if( ! defined( NDEBUG ) )
         // As asserted below, it's probably OK to not check {orderTradeCorrectReport1->bFillPriceFlag}.
         // At worst, this will validate 0.0.
         // yg? Logging this before the data itself.
         SafeTryValidateInstrumentPrice( orderTradeCorrectReport1->dFillPrice );
   #endif

         // I don't want to assume these.
         assert( orderTradeCorrectReport1->bFillPriceFlag );
         assert( orderTradeCorrectReport1->iFillSize > 0 );
         assert( orderTradeCorrectReport1->iFillSize <= orderTradeCorrectReport1->iTotalFilled );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderTradeCorrectReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region

               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |
                               //TOrderStateBitMask_CancellationRequestPending |
                               //TOrderStateBitMask_TriggeredByBroker |
                               //TOrderStateBitMask_TriggeredByExchange |
                               //TOrderStateBitMask_ProbablyCompleted |
                               //TOrderStateBitMask_Completed
                             )
                           ) ==
                           TOrderStateBitMask_NewOrderRequestReceivedByBroker
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderTradeCorrectReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
                           static_cast< double >( orderTradeCorrectReport1->iTotalFilled )
                        );
               //assert( orderPairIterator->second->FilledQuantityAndPrice.Price == ...

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderTradeCorrectReport1->iOrderNum;

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               // yg? As asserted above, it's probably OK to not check that this is positive.
               // It's probably unnecessary to round this.
               orderPairIterator->second->FilledQuantityAndPrice.Quantity =
                  static_cast< double >( orderTradeCorrectReport1->iTotalFilled );

               // yg? As asserted above, it's probably OK to not check {orderTradeCorrectReport1->bAvgFillPriceFlag}.
               // yg? At worst, this will assign 0.0, which can in fact inflict damge.
               orderPairIterator->second->FilledQuantityAndPrice.Price = orderTradeCorrectReport1->dAvgFillPrice;

               #pragma endregion
               #pragma region

               {
                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );

                  // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );

                  orderPairIterator->second->StateBitMask = orderStateBitMask;
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderTradeCorrectReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );

               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderTradeCorrectReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 "; %+.*g; %u; %.*s"
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderTradeCorrectReport1->sOrderType.iDataLen
                 + orderTradeCorrectReport1->sBuySellType.iDataLen
                 + orderTradeCorrectReport1->sReportType.iDataLen
                 + orderTradeCorrectReport1->sText.iDataLen
                 + orderTradeCorrectReport1->sUserMsg.iDataLen
                 + orderTradeCorrectReport1->sFillType.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderTradeCorrectReport1->iGatewaySsboe >= 0 );

               assert( orderTradeCorrectReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderTradeCorrectReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderTradeCorrectReport1->iGatewayUsecs )
                    )
               );

            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderTradeCorrectReport1->iSsboe >= 0 );

               assert( orderTradeCorrectReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderTradeCorrectReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderTradeCorrectReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
               assert( orderTradeCorrectReport1->iTriggerCmpOperator >= 0 );
               assert( orderTradeCorrectReport1->iTriggerPriceId >= 0 );

               assert( orderTradeCorrectReport1->iTotalFilled >= 0 );
               assert( orderTradeCorrectReport1->iGatewayBufferBytesBehind >= 0 );
               assert( orderTradeCorrectReport1->iFillSize >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderTradeCorrectReport1->iOrderNum,
                      orderTradeCorrectReport1->sOrderType.iDataLen,
                      orderTradeCorrectReport1->sOrderType.pData,
                      orderTradeCorrectReport1->sBuySellType.iDataLen,
                      orderTradeCorrectReport1->sBuySellType.pData,
                      10,
                      orderTradeCorrectReport1->bPriceToFillFlag ? orderTradeCorrectReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderTradeCorrectReport1->bTriggerPriceFlag ? orderTradeCorrectReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderTradeCorrectReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderTradeCorrectReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderTradeCorrectReport1->iTotalFilled ),

                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderTradeCorrectReport1->iTotalUnfilled,

                      10,
                      orderTradeCorrectReport1->bAvgFillPriceFlag ? orderTradeCorrectReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderTradeCorrectReport1->sReportType.iDataLen,
                      orderTradeCorrectReport1->sReportType.pData,
                      orderTradeCorrectReport1->sText.iDataLen,
                      orderTradeCorrectReport1->sText.pData,
                      orderTradeCorrectReport1->sUserMsg.iDataLen,
                      orderTradeCorrectReport1->sUserMsg.pData,
                      orderTradeCorrectReport1->pContext,
                      static_cast< char >( orderTradeCorrectReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderTradeCorrectReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),

                      10,
                      orderTradeCorrectReport1->bFillPriceFlag ? orderTradeCorrectReport1->dFillPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderTradeCorrectReport1->iFillSize ),
                      orderTradeCorrectReport1->sFillType.iDataLen,
                      orderTradeCorrectReport1->sFillType.pData
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            // One might argue that this should be marked "Warning" because this is a normal business process flow
            // but I want to mark this "Error".
            logger1.error( tempString1 );
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      
         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      
         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      
         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      
         #pragma endregion
      }

      #pragma endregion
   }

#endif
#if( /* {(public) BustReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::BustReport
      ( ::RApi::OrderBustReport * orderBustReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

      // Gene Sato wrote:
      // <Quote>
      // I don't know of a way to induce the exchange to bust a fill in their test environment.
      // Typically the data on bust reports are the same as fill reports,
      // so you can populate your own bust report instance and call the callback routine.
      // </Quote>

      // Visible universe.
      //    {BustReport} -- base.
      //       Implement.
      //    {orderBustReport1->dFillPrice}.
      //       Validate.
      //    {orderBustReport1->bFillPriceFlag}.
      //       Validate.
      //    {orderBustReport1->iFillSize}.
      //       Validate.
      //    {orderBustReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderBustReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderBustReport1->iTotalFilled >= 0 );

         // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
         // I don't want to assume this.
         assert( orderBustReport1->iTotalFilled + orderBustReport1->iTotalUnfilled > 0 );

         // I don't want to assume this.
         assert( ( orderBustReport1->iTotalFilled > 0 ) == orderBustReport1->bAvgFillPriceFlag );

   #if( ! defined( NDEBUG ) )
         // As asserted below, it's probably OK to not check {orderBustReport1->bFillPriceFlag}.
         // At worst, this will validate 0.0.
         // yg? Logging this before the data itself.
         SafeTryValidateInstrumentPrice( orderBustReport1->dFillPrice );
   #endif

         // I don't want to assume these.
         assert( orderBustReport1->bFillPriceFlag );
         assert( orderBustReport1->iFillSize > 0 );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderBustReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region

               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |
                               //TOrderStateBitMask_CancellationRequestPending |
                               //TOrderStateBitMask_TriggeredByBroker |
                               //TOrderStateBitMask_TriggeredByExchange |
                               //TOrderStateBitMask_ProbablyCompleted |
                               //TOrderStateBitMask_Completed
                             )
                           ) ==
                           TOrderStateBitMask_NewOrderRequestReceivedByBroker
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderBustReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
                           static_cast< double >( orderBustReport1->iTotalFilled + orderBustReport1->iFillSize )
                        );
               //assert( orderPairIterator->second->FilledQuantityAndPrice.Price == ...

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderBustReport1->iOrderNum;

               #pragma endregion
               #pragma region

               if( orderBustReport1->iTotalFilled > 0 )
               {
                  // It's probably unnecessary to round this.
                  orderPairIterator->second->FilledQuantityAndPrice.Quantity =
                     static_cast< double >( orderBustReport1->iTotalFilled );

                  // yg? As asserted above, it's probably OK to not check {orderBustReport1->bAvgFillPriceFkag}.
                  // yg? At worst, this will assign 0.0, which can in fact inflict damge.
                  orderPairIterator->second->FilledQuantityAndPrice.Price = orderBustReport1->dAvgFillPrice;
               }
               else
               {
                  orderPairIterator->second->FilledQuantityAndPrice.Reset();
               }

               #pragma endregion
               #pragma region

               {
                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );

                  // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );

                  orderPairIterator->second->StateBitMask = orderStateBitMask;
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderBustReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );

               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderBustReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 "; %+.*g; %u; %.*s"
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderBustReport1->sOrderType.iDataLen
                 + orderBustReport1->sBuySellType.iDataLen
                 + orderBustReport1->sReportType.iDataLen
                 + orderBustReport1->sText.iDataLen
                 + orderBustReport1->sUserMsg.iDataLen
                 + orderBustReport1->sFillType.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderBustReport1->iGatewaySsboe >= 0 );

               assert( orderBustReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderBustReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderBustReport1->iGatewayUsecs )
                    )
               );

            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderBustReport1->iSsboe >= 0 );

               assert( orderBustReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderBustReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderBustReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values, and that's not too bad.
               assert( orderBustReport1->iTriggerCmpOperator >= 0 );
               assert( orderBustReport1->iTriggerPriceId >= 0 );

               assert( orderBustReport1->iTotalFilled >= 0 );
               assert( orderBustReport1->iGatewayBufferBytesBehind >= 0 );
               assert( orderBustReport1->iFillSize >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderBustReport1->iOrderNum,
                      orderBustReport1->sOrderType.iDataLen,
                      orderBustReport1->sOrderType.pData,
                      orderBustReport1->sBuySellType.iDataLen,
                      orderBustReport1->sBuySellType.pData,
                      10,
                      orderBustReport1->bPriceToFillFlag ? orderBustReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderBustReport1->bTriggerPriceFlag ? orderBustReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderBustReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderBustReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderBustReport1->iTotalFilled ),

                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderBustReport1->iTotalUnfilled,

                      10,
                      orderBustReport1->bAvgFillPriceFlag ? orderBustReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderBustReport1->sReportType.iDataLen,
                      orderBustReport1->sReportType.pData,
                      orderBustReport1->sText.iDataLen,
                      orderBustReport1->sText.pData,
                      orderBustReport1->sUserMsg.iDataLen,
                      orderBustReport1->sUserMsg.pData,
                      orderBustReport1->pContext,
                      static_cast< char >( orderBustReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderBustReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),

                      10,
                      orderBustReport1->bFillPriceFlag ? orderBustReport1->dFillPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderBustReport1->iFillSize ),
                      orderBustReport1->sFillType.iDataLen,
                      orderBustReport1->sFillType.pData
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            // One might argue that this should be marked "Warning" because this is a normal business process flow
            // but I want to mark this "Error".
            logger1.error( tempString1 );
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }

      #pragma endregion
   }

#endif
#if( /* {(public) OtherReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TREngineAdapter::OtherReport
      ( ::RApi::OrderReport * orderReport1,
        void * /*context1*/,
        int * /*outcomeCode2*/
      )
   {
      #pragma region

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

      // Gene Sato wrote:
      // <Quote>
      // Regarding the other report, it exists because of an interface hedge. There are cases where new order report types
      // can be introduced in the infrastructure independently of new versions of R | API.
      // The OtherReport callback will be invoked for the order reports that the R | API client does not recognize.
      // This allows end users more flexibility regarding when to migrate to newer versions of R | API
      // while still getting the notification of the new 'event' conveyed by the OtherReport callback.
      // I don't know of any such order reports at the moment.
      // </Quote>
      // I don't want to write lots of code in here.

      // Visible universe.
      //    {OtherReport} -- base.
      //       Implement.
      //    {orderReport1->...}.
      //       Possibly log some other fields.
      // See visible universe in {LineUpdate}.

      #pragma endregion
      #pragma region

      try
      {
         #pragma region

         //::RApi::RCallbacks::...

         #pragma endregion
         #pragma region

         // I don't want to assume these.
         assert( orderReport1->iOrderNum != TRApiHelpers::OrderNumberNone );
         assert( orderReport1->iTotalFilled >= 0 );

         // See {::RApi::OrderReport::iTotalUnfilled} comment in {LineUpdate}.
         // I don't want to assume this.
         assert( orderReport1->iTotalFilled + orderReport1->iTotalUnfilled > 0 );

         // I don't want to assume this.
         assert( ( orderReport1->iTotalFilled > 0 ) == orderReport1->bAvgFillPriceFlag );

         #pragma endregion
         #pragma region

         {
            ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::iterator orderPairIterator
               ( SingleInstrumentsOrders_.find( orderReport1->pContext ) );

            if( orderPairIterator != SingleInstrumentsOrders_.end() &&

                // yg? See related comment in {LineUpdate}.
                orderPairIterator->second->StateBitMask != TOrderStateBitMask_None
              )
            {
               #pragma region

               // See related comment in {LineUpdate}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( orderPairIterator->second->StateBitMask &
                                                                                                    ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                                      TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                                    )
                                                                                                  ) !=
                                                                                                  TOrderStateBitMask_None
                                                                                               );

               // I don't want to assume these.
               assert( ( orderPairIterator->second->StateBitMask &
                             ( //TOrderStateBitMask_NewOrderRequestPending |
                               TOrderStateBitMask_NewOrderRequestReceivedByBroker
                               //TOrderStateBitMask_LastModificationRequestPending |
                               //TOrderStateBitMask_LastModificationRequestRejected |
                               //TOrderStateBitMask_ShallBeCancelled |
                               //TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                               ////TOrderStateBitMask_LastCancellationRequestPending |
                               ////TOrderStateBitMask_LastCancellationRequestRejected |
                               //TOrderStateBitMask_CancellationRequestPending |
                               //TOrderStateBitMask_TriggeredByBroker |
                               //TOrderStateBitMask_TriggeredByExchange |
                               //TOrderStateBitMask_ProbablyCompleted |
                               //TOrderStateBitMask_Completed
                             )
                           ) ==
                           TOrderStateBitMask_NewOrderRequestReceivedByBroker
                        );
               assert( orderPairIterator->second->BrokerGeneratedId == orderReport1->iOrderNum );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Quantity ==
                           static_cast< double >( orderReport1->iTotalFilled )
                        );
               assert( orderPairIterator->second->FilledQuantityAndPrice.Price ==
                           ( ( ! orderReport1->bAvgFillPriceFlag ) ?
                             ::std::numeric_limits< double >::lowest() :
                             orderReport1->dAvgFillPrice
                           )
                        );

               #pragma endregion
               #pragma region

               // As asserted above, this is probably unnecessary but let's reinsure ourselves.
               orderPairIterator->second->BrokerGeneratedId = orderReport1->iOrderNum;

               #pragma endregion
               #pragma region

               {
                  TOrderStateBitMask orderStateBitMask( orderPairIterator->second->StateBitMask );

                  // As asserted above, this is probably unnecessary but let's reinsure ourselves.
                  orderStateBitMask =
                     static_cast< TOrderStateBitMask >( orderStateBitMask | TOrderStateBitMask_NewOrderRequestReceivedByBroker );

                  orderPairIterator->second->StateBitMask = orderStateBitMask;
               }

               #pragma endregion
               #pragma region

               orderPairIterator->second->RaiseOnReceivedData();

               #pragma endregion
            }
            else
            {
               #pragma region

               static char const constantString1AsArray[]( "invalid {orderReport1->pContext}" );

               // This results in the logger object reference being obtained more than once. Although this rarely happens.
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

               // yg? This is logged before the data itself.
               // This creates another temporary string. Although this rarely happens.
               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );

               #pragma endregion
            }
         }

         #pragma endregion
         #pragma region

         {
            static char const formatConstantString1AsArray[]
               ( "{RApi::OrderReport}"
                 "; %i; %.*s; %.*s; %+.*g; %+.*g; %u; %u; %u; %i; %+.*g; %.*s; %.*s; %.*s; %p; %c; %u; %s; %s"
                 ""
               );

            // Assuming this will not overflow.
            int const tempString1BufferLength
               ( 256
                 + orderReport1->sOrderType.iDataLen
                 + orderReport1->sBuySellType.iDataLen
                 + orderReport1->sReportType.iDataLen
                 + orderReport1->sText.iDataLen
                 + orderReport1->sUserMsg.iDataLen
               );

            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            // I don't want to assume these.
            {
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderReport1->iGatewaySsboe >= 0 );

               assert( orderReport1->iGatewayUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp1MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderReport1->iGatewaySsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderReport1->iGatewayUsecs )
                    )
               );

            // I don't want to assume these.
            {
               // This is probably positive but we will be OK even if this is 0.
               // TODO 3 yg? This validation will fail in a few years.
               assert( orderReport1->iSsboe >= 0 );

               assert( orderReport1->iUsecs >= 0 );
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::Poco::Timespan::SECONDS == 1000000 );
            ::Poco::Int64 dateTimeStamp2MicrosecondsSince1970
               ( static_cast< ::Poco::Int64 >
                    ( static_cast< unsigned int >( orderReport1->iSsboe ) * static_cast< ::Poco::UInt64 >( ::Poco::Timespan::SECONDS ) +
                      static_cast< unsigned int >( orderReport1->iUsecs )
                    )
               );

            // We will format these as an unsigned.
            // I don't want to assume these.
            {
               // These assertions might fail if a buggy app sends invalid values.
               assert( orderReport1->iTriggerCmpOperator >= 0 );
               assert( orderReport1->iTriggerPriceId >= 0 );

               assert( orderReport1->iTotalFilled >= 0 );
               assert( orderReport1->iGatewayBufferBytesBehind >= 0 );
            }

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      orderReport1->iOrderNum,
                      orderReport1->sOrderType.iDataLen,
                      orderReport1->sOrderType.pData,
                      orderReport1->sBuySellType.iDataLen,
                      orderReport1->sBuySellType.pData,
                      10,
                      orderReport1->bPriceToFillFlag ? orderReport1->dPriceToFill : ::std::numeric_limits< double >::lowest(),
                      10,
                      orderReport1->bTriggerPriceFlag ? orderReport1->dTriggerPrice : ::std::numeric_limits< double >::lowest(),
                      static_cast< unsigned int >( orderReport1->iTriggerCmpOperator ),
                      static_cast< unsigned int >( orderReport1->iTriggerPriceId ),
                      static_cast< unsigned int >( orderReport1->iTotalFilled ),

                      // See a comment about this in the visible universe in {LineUpdate}.
                      orderReport1->iTotalUnfilled,

                      10,
                      orderReport1->bAvgFillPriceFlag ? orderReport1->dAvgFillPrice : ::std::numeric_limits< double >::lowest(),
                      orderReport1->sReportType.iDataLen,
                      orderReport1->sReportType.pData,
                      orderReport1->sText.iDataLen,
                      orderReport1->sText.pData,
                      orderReport1->sUserMsg.iDataLen,
                      orderReport1->sUserMsg.pData,
                      orderReport1->pContext,
                      static_cast< char >( orderReport1->bPossOutOfOrder + static_cast< unsigned char >( '0' ) ),
                      static_cast< unsigned int >( orderReport1->iGatewayBufferBytesBehind ),

                      // yg? Using current thread locale.
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp1MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      ),
                      ( ::Poco::DateTimeFormatter::format
                           ( ::Poco::Timestamp( dateTimeStamp2MicrosecondsSince1970 ),
                             ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString
                           )
                        .c_str()
                      )
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.warning( tempString1 );
         }

         #pragma endregion
         #pragma region

         return OK;

         #pragma endregion
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         #pragma region

         TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::Poco::Exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ::std::exception const & exception1 )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }
      catch( ... )
      {
         #pragma region

         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

         #pragma endregion
      }

      #pragma endregion
   }

#endif
#if( /* Misc. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //int TREngineAdapter::AccountList(::RApi::AccountListInfo * /*pInfo*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
      //{
      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
      //   static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::AccountList} was called" );
      //   logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      //}
      //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::Alert(::RApi::AlertInfo * /*pInfo*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
      //{
      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
      //   static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::Alert} was called" );
      //   logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      //}
      //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::AskQuote(::RApi::AskInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? See a comment in {BidQuote}.

      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::AskQuote} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

//#pragma message( "yg---?? Test." )
//      BestAskQuote( pInfo, >>>cast>>>nullptr, aiCode );

      return OK;
   }

   //int TREngineAdapter::BestAskQuote(::RApi::AskInfo * /*pInfo*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
      //{
      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
      //   static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::BestAskQuote} was called" );
      //   logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      //}
      //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::BestBidQuote(::RApi::BidInfo * /*pInfo*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
      //{
      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
      //   static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::BestBidQuote} was called" );
      //   logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      //}
      //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::BidQuote(::RApi::BidInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? Rithmic invalidates order book entries by 0 size. And it might be possible that
      // yg? the whole order book can be invalidated by a call to the {LimitOrderBook} callback
      // yg? even if we didn't subscribe for order book.
      // See in the R|API help: "F.A.Q. - R | Trade Execution Platform(tm)",
      // "How do I maintain an order book? (Or, how do I use update types with AskInfo, BidInfo and EndQuoteInfo?)".

      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::BidQuote} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

//#pragma message( "yg---?? Test." )
//      BestBidQuote( pInfo, pContext, aiCode );

      return OK;
   }

   int TREngineAdapter::BinaryContractList(::RApi::BinaryContractListInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::BinaryContractList} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::BustReport(::RApi::OrderBustReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::BustReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::CancelReport(::RApi::OrderCancelReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::CancelReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::ClosePrice(::RApi::ClosePriceInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::ClosePrice} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::ClosingIndicator(::RApi::ClosingIndicatorInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::ClosingIndicator} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::EndQuote(::RApi::EndQuoteInfo * /*pInfo*/,
         void * /*pContext*/,
         int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::EndQuote} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::EquityOptionStrategyList(::RApi::EquityOptionStrategyListInfo * /*pInfo*/,
         void * /*pContext*/,
         int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::EquityOptionStrategyList} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::ExchangeList(::RApi::ExchangeListInfo * /*pInfo*/,
         void * /*pContext*/,
         int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::ExchangeList} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::ExecutionReplay(::RApi::ExecutionReplayInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::ExecutionReplay} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::FailureReport(::RApi::OrderFailureReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::FailureReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::FillReport(::RApi::OrderFillReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::FillReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::HighPrice(::RApi::HighPriceInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::HighPrice} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::InstrumentByUnderlying(::RApi::InstrumentByUnderlyingInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::InstrumentByUnderlying} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::LimitOrderBook(::RApi::LimitOrderBookInfo * /*pInfo*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
      //{
      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
      //   static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::LimitOrderBook} was called" );
      //   logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      //}
      //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::LineUpdate(::RApi::LineInfo * /*pInfo*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
      //{
      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
      //   static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::LineUpdate} was called" );
      //   logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      //}
      //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::LowPrice(::RApi::LowPriceInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::LowPrice} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::MarketMode(::RApi::MarketModeInfo * /*pInfo*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
      //{
      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
      //   static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::MarketMode} was called" );
      //   logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      //}
      //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::ModifyReport(::RApi::OrderModifyReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::ModifyReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::NotCancelledReport(::RApi::OrderNotCancelledReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::NotCancelledReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::NotModifiedReport(::RApi::OrderNotModifiedReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::NotModifiedReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::OpenInterest(::RApi::OpenInterestInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::OpenInterest} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::OpenOrderReplay(::RApi::OrderReplayInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::OpenOrderReplay} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::OpenPrice(::RApi::OpenPriceInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::OpenPrice} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::OpeningIndicator(::RApi::OpeningIndicatorInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::OpeningIndicator} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::OptionList(::RApi::OptionListInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::OptionList} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::OrderReplay(::RApi::OrderReplayInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::OrderReplay} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::OtherReport(::RApi::OrderReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::OtherReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::PasswordChange(::RApi::PasswordChangeInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::PasswordChange} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::PnlReplay(::RApi::PnlReplayInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::PnlReplay} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::PnlUpdate(::RApi::PnlInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::PnlUpdate} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::PriceIncrUpdate(::RApi::PriceIncrInfo * /*pInfo*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
      //{
      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
      //   static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::PriceIncrUpdate} was called" );
      //   logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      //}
      //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::ProductRmsList(::RApi::ProductRmsListInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::ProductRmsList} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::RefData(::RApi::RefDataInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::RefData} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::RejectReport(::RApi::OrderRejectReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::RejectReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::SettlementPrice(::RApi::SettlementPriceInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::SettlementPrice} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::SodUpdate(::RApi::SodReport * /*pReport*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::SodUpdate} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::StatusReport(::RApi::OrderStatusReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::StatusReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::Strategy(::RApi::StrategyInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::Strategy} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::StrategyList(::RApi::StrategyListInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::StrategyList} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::TimeBar(::RApi::TimeBarInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TimeBar} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::TimeBarReplay(::RApi::TimeBarReplayInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TimeBarReplay} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::TradeReplay(::RApi::TradeReplayInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TradeReplay} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::TriggerPulledReport(::RApi::OrderTriggerPulledReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TriggerPulledReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::TriggerReport(::RApi::OrderTriggerReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TriggerReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::TradeCondition(::RApi::TradeInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...
   
      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TradeCondition} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }
      
      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   //int TREngineAdapter::TradeCorrectReport(::RApi::OrderTradeCorrectReport * /*pReport*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
   //   {
   //      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
   //      static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TradeCorrectReport} was called" );
   //      logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
   //   }
   //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   //int TREngineAdapter::TradePrint(::RApi::TradeInfo * /*pInfo*/,
   //   void * /*pContext*/,
   //   int * /*aiCode*/)
   //{
   //   // yg? No exception handling.
   //
   //   //::RApi::RCallbacks::...
   //
      //{
      //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
      //   static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TradePrint} was called" );
      //   logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      //}
      //
   //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   return OK;
   //}

   int TREngineAdapter::TradeRoute(::RApi::TradeRouteInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...
   
      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TradeRoute} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::TradeRouteList(::RApi::TradeRouteListInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...
   
      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TradeRouteList} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

   int TREngineAdapter::TradeVolume(::RApi::TradeVolumeInfo * /*pInfo*/,
      void * /*pContext*/,
      int * /*aiCode*/)
   {
      // yg? No exception handling.

      //::RApi::RCallbacks::...
   
      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         static char const constantString1AsArray[]( "{RApiFacade::TREngineAdapter::TradeVolume} was called" );
         logger1.critical( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      return OK;
   }

#endif
}
