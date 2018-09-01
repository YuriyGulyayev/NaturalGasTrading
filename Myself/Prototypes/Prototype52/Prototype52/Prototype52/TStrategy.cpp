#pragma once

#include "StdAfx.h"

// TODO 1 yg? Remove this file.

#if 0

#pragma region Return to this.
#if( /* {private DoInitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::DoInitialize
      ( TStrategyConfiguration && configuration1
      )
   {
      NumberUnmodifiedTowardsMoneyEntryOrders_ = ::std::numeric_limits< int >::max();
      EntryLastFilledOrderDirectionCode_ = ::Finance::Trading::TPositionDirectionCode_None;
      SignedNumberEntryFilledOrders_ = 0;
      ExitOrderSent_ = false;
   }

#endif
#pragma endregion

#if( /* {private Run3}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::Run3()
   {
      // Handling only some exceptions. Others will be handled by our last chance error handler.

      REngineAdapter_->LockREngine();

      try
      {
         // According to the code contract, we may throw a {::Common::ControlFlow::TOperationCancelledException} only while {REngineAdapter_->REngine()} is locked.
         // It's (theoretically) possible that at this point the activity cancellation token is signaled.
         // yg? Non-volatile read.
         ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled();

         DoRun3();
      }

      // According to the code contract, this exception may be thrown only while {REngineAdapter_->REngine()} is locked.
      // yg? We could make the {::Common::ErrorHandling::TErrorHandler} class aware of this exception but we would have to catch it anyway.
      catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )

      {
         {
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            //logger1.log( exception1 );
            logger1.warning( exception1.displayText() );
         }

         //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      REngineAdapter_->UnlockREngine();
      ThreadedActivityCancellationToken_->release();
   }

#endif

   // {::Poco::Runnable} implementation.
#if( /* {private run}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::run()
   {
      // Handling only some exceptions. Others will be handled by our last chance error handler.

      REngineAdapter_->LockREngine();

      try
      {
         // According to the code contract, we may throw a {::Common::ControlFlow::TOperationCancelledException} only while {REngineAdapter_->REngine()} is locked.
         // It's (theoretically) possible that at this point the activity cancellation token is signaled.
         // yg? Non-volatile read.
         ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled();

         DoRun2();
      }

      // According to the code contract, this exception may be thrown only while {REngineAdapter_->REngine()} is locked.
      // yg? We could make the {::Common::ErrorHandling::TErrorHandler} class aware of this exception but we would have to catch it anyway.
      catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )

      {
         {
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            //logger1.warning( exception1.displayText() );
            logger1.log( exception1 );
         }

         //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      REngineAdapter_->UnlockREngine();
      ThreadedActivityCancellationToken_->release();
   }

#endif

#if( /* {private DoRun1}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::DoRun1()
   {



      FixInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask();
      CreatePooledOrder();
      CreateAndSendEntryDeepOutOfMoneyOrders();
      WaitEntryDeepOutOfMoneyOrdersAccepted();
      PrepareActivitiesSchedule();
      StartThread2();
      PrepareReceiveEconomicReport();
      StartThread3();
      TryReceiveEconomicReport();
      OnTriedReceiveEconomicReport();
      SleepUntilTerminationTime();

      // yg? We might need to call these even if a non-critical exception is thrown, such as {::Common::ControlFlow::TOperationCancelledException}.
      // yg? But currently only critical exceptions can be thrown, except by a hack in debug build.
      // yg? An easy fix would be to make these calls in the {Run} method after the {catch} block.
      // yg? But we would have to ensure that the report receiver is in a valid state.
      LogEconomicReportReceptionActivityReportIfPossible();
      TryVerifyCompleted();
   }

#endif


#if( /* {private FixInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::FixInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask()
   {
      // At the beginning this value can be calculated based on not yet populated prices, so at this point this value can be invalid.
      // In warm-up or test mode we increase the chance that related protection will not trigger.
      // In normal mode we require further market data to update this value.
      // TODO 3 yg? Assign {TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllImportant}.
      InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ =
         IsWarmUpOrTestMode_ ?
         ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_All :
         ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_None;
   }

#endif
#if( /* {private CreatePooledOrder}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::CreatePooledOrder()
   {
      // This method is not inline as it's called from multiple places.
      // We create a pooled order even if we are not going to send any orders. The order will be deallocated only along with {* REngineAdapter_}.
      // To keep things simple, we don't make an effort to prevent this order creation if we are not going to use it.
      // And there are cases when we can't know in advance if we are going to need another pooled order.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PooledOrder_ == nullptr );
      PooledOrder_ = ( & REngineAdapter_->CreateSingleInstrumentOrder( REngineAdapter_->Instrument() ) );
      PooledOrder_->TypeCode = ::RApiFacade::TOrderTypeCode_Market;
      PooledOrder_->Quantity = PooledOrder_->Instrument().QuantityIncrementMinLimit;
   }

#endif
#if( /* {private CreateAndSendEntryDeepOutOfMoneyOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::CreateAndSendEntryDeepOutOfMoneyOrders()
   {
      // yg? It doesn't matter in what order we send new order requests as we are going to warm-up-modify the orders.
      // yg? See related comment in {WarmUpRequestModifyEntryOrdersTowardsMoney}.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].empty() );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 1U ].empty() );

      if( ! PositionConfiguration_.EntryOrdersConfiguration.empty() )
      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionConfiguration_.EntryOrdersConfiguration.cbegin() != PositionConfiguration_.EntryOrdersConfiguration.cend() );

         // {entryOrdersConfigurationIterator1} is not used in code below and so should be replaced with a simple counter, but this code is not performance critical.
         // It's inefficient to call {PositionConfiguration_.EntryOrdersConfiguration.cend} multiple times, but this code is not performance critical.
//TODO remove above comment?
         for( ::std::vector< TEntryOrderConfiguration >::const_iterator entryOrdersConfigurationIterator1( PositionConfiguration_.EntryOrdersConfiguration.cbegin() ) ; entryOrdersConfigurationIterator1 != PositionConfiguration_.EntryOrdersConfiguration.cend() ; ++ entryOrdersConfigurationIterator1 )

         {
            {
               ::RApiFacade::TSingleInstrumentOrder & entryOrder1
                  ( REngineAdapter_->CreateSingleInstrumentOrder( REngineAdapter_->Instrument() ) );
               entryOrder1.TypeCode = ::RApiFacade::TOrderTypeCode_StopMarket;

               //#pragma message( "yg---?? Test." )
               //entryOrder1.TypeCode = ::RApiFacade::TOrderTypeCode_Market;

               entryOrder1.DirectionCode = ::Finance::Trading::TPositionDirectionCode_Short;
               entryOrder1.Quantity = entryOrder1.Instrument().QuantityIncrementMinLimit;
         
               // yg? Trigger price will be rejected if it's too far from yesterday's close price.
               // TODO 3 yg? So we should use yesterday's close price while ensuring that trigger price is deep enough out of the money.
               // yg? This formula assumes that the price is positive.
               // yg? Another solution would be to add/subtract {InstrumentDeepOutOfMoneyPriceFactor1_ * entryOrder1.Instrument().QuantityIncrementMinLimit}.
               // yg? For that we might need another positive integer parameter named {InstrumentDeepOutOfMoneyPriceFactor2}.
               // TODO 3 yg? We should support non-positive prices.
               // Asserting, not assuming.
               // Not rounded.
               assert( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price > 0.0 );
               entryOrder1.TriggerPrice = InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price * ( 1.0 - InstrumentDeepOutOfMoneyPriceFactor1_ );
         
               entryOrder1.OnReceivedData += ::Poco::delegate( this, ( & TStrategy::HandleEntryOrderOnReceivedData ) );
               EntryOrders_[ 0U ].push_back( & entryOrder1 );
            }

            {
               ::RApiFacade::TSingleInstrumentOrder & entryOrder1
                  ( REngineAdapter_->CreateSingleInstrumentOrder( REngineAdapter_->Instrument() ) );
               entryOrder1.TypeCode = ::RApiFacade::TOrderTypeCode_StopMarket;
               entryOrder1.DirectionCode = ::Finance::Trading::TPositionDirectionCode_Long;
               entryOrder1.Quantity = entryOrder1.Instrument().QuantityIncrementMinLimit;
         
               // yg? Trigger price will be rejected if it's too far from yesterday's close price.
               // TODO 3 yg? So we should use yesterday's close price while ensuring that trigger price is deep enough out of the money.
               // yg? This formula assumes that the price is positive.
               // yg? Another solution would be to add/subtract {InstrumentDeepOutOfMoneyPriceFactor1_ * entryOrder1.Instrument().QuantityIncrementMinLimit}.
               // yg? For that we might need another positive integer parameter named {InstrumentDeepOutOfMoneyPriceFactor2}.
               // TODO 3 yg? We should support non-positive prices.
               // Asserting, not assuming.
               // Not rounded.
               assert( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price > 0.0 );
               entryOrder1.TriggerPrice = InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price * ( 1.0 + InstrumentDeepOutOfMoneyPriceFactor1_ );
         
               entryOrder1.OnReceivedData += ::Poco::delegate( this, ( & TStrategy::HandleEntryOrderOnReceivedData ) );
               EntryOrders_[ 1U ].push_back( & entryOrder1 );
            }
         }

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].begin() != EntryOrders_[ 0U ].end() );
         REngineAdapter_->SendOrders( EntryOrders_[ 0U ].begin(), EntryOrders_[ 0U ].end() );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 1U ].begin() != EntryOrders_[ 1U ].end() );
         REngineAdapter_->SendOrders( EntryOrders_[ 1U ].begin(), EntryOrders_[ 1U ].end() );
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      // We log this even if we are configured to send no entry orders.
      {
         static char const constantString1AsArray[]( "sent deep out of the money entry orders" );
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      //#pragma message( "yg---?? Test." )
      //do
      //{
      //   REngineAdapter_->SleepMillisecond();
      //}
      //while( ! REngineAdapter_->CanCancelOrder( * EntryOrders_[ 0U ].front() ) );
      //REngineAdapter_->RequestCancelOrderWhenCan( * EntryOrders_[ 0U ].front() );
      //REngineAdapter_->SleepMillisecond();
      //REngineAdapter_->RequestCancelAnyOrders();
      //REngineAdapter_->SleepMillisecond();
      //REngineAdapter_->RequestCancelAnyOrders();
   }

#endif
#if( /* {private WaitEntryDeepOutOfMoneyOrdersAccepted}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::WaitEntryDeepOutOfMoneyOrdersAccepted() const
   {
      // This is guaranteed to be {true} until we leave the locked scope.
      // This will change if an entry order completes, usually due to a rejection.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_None );

   // yg? Hack in debug build.
   #if( ! defined( NDEBUG ) )
      int timeoutCounter( - 3000 );
   #endif

      for( ; ; )
      {
         //// The loop breaking condition is likely {false} at the beginning, so we sleep first.
         //REngineAdapter_->SleepMillisecond();

         // This condition will become {false} if an entry order completes, usually due to a rejection.
         // yg? In that case we will keep cycling forever and I don't want to code any recovery logic.
         // yg? But in debug build we will throw an exception.
         // When this is {true} it's guaranteed that nothing was removed from {EntryOrders_}.
         if( State2Code_ <= TState2Code_None )

         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_None );

            // This is guaranteed unless the R|API thread changed {State2Code_}.
            // Note that {Thread2_} is not running yet.
            // The sizes can be 0U.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == PositionConfiguration_.EntryOrdersConfiguration.size() );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == EntryOrders_[ 1U ].size() );

            // It's more efficient to check long orders first as we send them last.
            // This will work correct even if we are configured to send no entry orders.
            if( ! ::RApiFacade::TSingleInstrumentOrderHelpers::OrdersStateBitMaskEqual
                       ( EntryOrders_[ 1U ].cbegin(),
                         EntryOrders_[ 1U ].cend(),
                         ::RApiFacade::TOrderStateBitMask_NewOrderRequestReceivedByBroker
                       )
              )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // This will work correct even if we are configured to send no entry orders.
               if( ! ::RApiFacade::TSingleInstrumentOrderHelpers::OrdersStateBitMaskEqual
                          ( EntryOrders_[ 0U ].cbegin(),
                            EntryOrders_[ 0U ].cend(),
                            ::RApiFacade::TOrderStateBitMask_NewOrderRequestReceivedByBroker
                          )
                 )

               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
               else
               {
                  // It's pointless to continue if this is not ready.
                  if( REngineAdapter_->Ready() )

                  {
                     break;
                  }
                  else
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                  }
               }
            }
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         }

   // yg? Hack in debug build.
   #if( ! defined( NDEBUG ) )
         // yg? It would be more correct to use a millisecond difference here but keeping it simple.
//TODO flip this condition?
         if( ( ++ timeoutCounter ) >= 0 )

         {
            if( State2Code_ < TState2Code_CancellingEntryOrders )
            {
               // After we request to cancel "any" orders we normally send peer message and request to unsubscribe from market data but that would be unnecessary here.
               REngineAdapter_->RequestCancelAnyOrders();

               // I want to request to cancel "any" orders and only then break in the debugger.
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_CancellingEntryOrders );
            }

            {
               static char const constantString1AsArray[]( "Error; tired waiting for entry orders to get accepted" );
               throw ::Common::ControlFlow::TOperationCancelledException
                            ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                              0
                            );
            }
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
   #endif

         // The loop breaking condition can be {true} at the beginning, so we sleep afterwards.
         // It can be true only if we are configured to send no entry orders.
         REngineAdapter_->SleepMillisecond();
      }
   }

#endif
#if( /* {private PrepareActivitiesSchedule}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::PrepareActivitiesSchedule()
   {
      // {ModeCode_} (use)
      // {Timer1TickIntervalMilliseconds_} (use)
      // {EconomicReportReleaseTimeOfDayMilliseconds_} (use)
      // {EconomicReportReleaseDateTimeWarmUpOffsetMilliseconds_} (use)
      // {EconomicReportReleaseDateTimeTestOffsetMilliseconds_} (use)
      // {EntryOrdersModificationTimeOffsetMilliseconds_} (use)
      // {TradingSystemWarmUpModeCode_} (use)
      // {IsWarmUpOrTestMode_} (use)
      // {DateTimeKeeper_.Get...} (call)
      // {EconomicReportReceiver_->InvocationTimeOffsetMilliseconds} (use)
>>>      // {PeerDataReceiver_.InvocationTimeOffsetMilliseconds} (use)
      //> {EconomicReportReleaseDateTimeMillisecondsSince1970_} (update)
      //> {EconomicReportReleaseTimeMilliseconds_} (update)
>>>      //> {PeerDataReceiverInvocationTimeMilliseconds_} (update)
      //> {EconomicReportReceiverInvocationTimeMilliseconds_} (update)
      //> {EntryOrdersModificationTimeMilliseconds_} (update)
      //> {NumberTimer1TicksUntilEntryOrdersModification_} (update)
      //> {TimeSpanMillisecondsUntilEntryOrdersModification_} (update)
      //> {State1Code_} (update)

      // We used to add the following to this value:
      //    2 ms to start all activities, including to start another thread;
      //    1 ms to absorb any calculation errors, including those caused by {DateTimeKeeper_}.
      // The calculation errors could still be bigger and even more so if the report was to be released in a long time, which wasn't a big deal.
      // I eliminated that unnecessary complication.
      // But let's add 1 to use time after the next multimedia timer tick.
      int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() + 1 );

      ::Poco::Int64 currentDateTimeMillisecondsSince1970( DateTimeKeeper_.GetDateTimeMillisecondsAsInteger< ::Poco::Int64 >( currentTimeMilliseconds ) );

      if( TradingSystemWarmUpModeCode_ != TTradingSystemWarmUpModeCode_None )
      {
         EconomicReportReleaseDateTimeMillisecondsSince1970_ =
            currentDateTimeMillisecondsSince1970 + EconomicReportReleaseDateTimeWarmUpOffsetMilliseconds_;
      }
      else
      {
         if( ModeCode_ == TPeerStrategyBaseModeCode_Test )
         {
            EconomicReportReleaseDateTimeMillisecondsSince1970_ =
               currentDateTimeMillisecondsSince1970 + EconomicReportReleaseDateTimeTestOffsetMilliseconds_;
         }
         else
         {
//TODO move this validation before the {if} and validate all possible values.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ModeCode_ == TPeerStrategyBaseModeCode_Normal );
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
            /*int*/ ::Poco::Int64 const numberMillisecondsPerDay( /*static_cast< int >*/( ::Poco::Timespan::DAYS /*)*/ / /*static_cast< int >(*/ ::Poco::Timespan::MILLISECONDS ) );
            //::Poco::Int64 currentDateMillisecondsSince1970( currentDateTimeMillisecondsSince1970 / numberMillisecondsPerDay * numberMillisecondsPerDay );
            /*int*/ ::Poco::Int64 currentTimeOfDayMilliseconds( /*static_cast< int >*/( currentDateTimeMillisecondsSince1970 % numberMillisecondsPerDay ) );
            ::Poco::Int64 currentDateMillisecondsSince1970( currentDateTimeMillisecondsSince1970 - currentTimeOfDayMilliseconds );
            ::Poco::Int64 economicReportReleaseDateTimeMillisecondsSince19701( currentDateMillisecondsSince1970 + EconomicReportReleaseTimeOfDayMilliseconds_ );

            // This ensures that we will have at least as much time as we would have in warm-up mode but it's not safe to have that little.
            // This can be solved by adding additional parameters to specify how long before the report release the activities must start and/or
            // how many times the date-time keeper must be updated.
            // For now the user must launch the app in advance and kill it if the warm-up procedure takes too long.
            // This loop usually executes 0 or 1 times but can (potentially) execute 2 times.
            while( economicReportReleaseDateTimeMillisecondsSince19701 < currentDateTimeMillisecondsSince1970 + EconomicReportReleaseDateTimeWarmUpOffsetMilliseconds_ )
            {
               economicReportReleaseDateTimeMillisecondsSince19701 += numberMillisecondsPerDay;
            }

            EconomicReportReleaseDateTimeMillisecondsSince1970_ = economicReportReleaseDateTimeMillisecondsSince19701;
         }
      }
      
      UpdateActivitiesSchedule();

      // This value must be positive or at least non-negative and greater than or equal the maximum of the negated {FileSystemCacheFlushing2TimeOffsetTimer1Ticks_},
      // {PeerMessageSendingWarmUp2TimeOffsetTimer1Ticks_}, and {EntryOrdersModificationWarmUp2TimeOffsetTimer1Ticks_} (if we are actually going
      // to warm-up-modify entry orders) and possibly some others but that would not be the case if we are misconfigured.
      // In fact, this value must be much bigger to absorb latencies, not monotonic date-time, and calculation erros,
      // recalculate the moving averages many enough times, and allow the date-time keeper to stabilize.
//TODO Can I just force this to be non-negative? I don't want to deal with fucked up cases.
      NumberTimer1TicksUntilEntryOrdersModification_ =
         /*::std::max*/( EntryOrdersModificationTimeMilliseconds_ - currentTimeMilliseconds/*, 0*/ ) / Timer1TickIntervalMilliseconds_;
      assert( NumberTimer1TicksUntilEntryOrdersModification_ >= 0 );

      TimeSpanMillisecondsUntilEntryOrdersModification_ = NumberTimer1TicksUntilEntryOrdersModification_ * Timer1TickIntervalMilliseconds_;
      assert( TimeSpanMillisecondsUntilEntryOrdersModification_ >= 0 );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ == TState1Code_Starting );

      // We must freeze the activities schedule to prevent multithreaded access to the date-time keeper.
      // But in warm-up or test mode we do so even sooner to prevent incorrect behavior that can be caused by the date-time keeper's date-time being not monotonic.
//TODO don't bother doing this
      State1Code_ = IsWarmUpOrTestMode_ ? TState1Code_FrozeActivitiesSchedule : TState1Code_PreparedActivitiesSchedule;

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         int const tempString1BufferLength( 128 );
         ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

         {
            static char const constantString1AsArray[]( "current market data date-time; " );
            tempString1.assign( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) );

            // This date-time is actually statistically a half a millisecond after current date-time, so the message we log is a bit incorrect.
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
            ::Poco::Timestamp timeStamp1( currentDateTimeMillisecondsSince1970 * ::Poco::Timespan::MILLISECONDS );

            // yg? Using current thread locale.
            ::Poco::DateTimeFormatter::append( tempString1, timeStamp1, ::Common::DataFormatting::TDataFormattingHelpers::DateTimeMillisecondResolutionFormatString );

            logger1.information( tempString1 );
         }

         {
            static char const constantString1AsArray[]( "economic report release date-time; " );
            tempString1.assign( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) );
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
            ::Poco::Timestamp timeStamp1( EconomicReportReleaseDateTimeMillisecondsSince1970_ * ::Poco::Timespan::MILLISECONDS );

            // yg? Using current thread locale.
            ::Poco::DateTimeFormatter::append( tempString1, timeStamp1, ::Common::DataFormatting::TDataFormattingHelpers::DateTimeMillisecondResolutionFormatString );

            logger1.information( tempString1 );
         }
      }
   }

#endif
#if( /* {private UpdateActivitiesSchedule}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::UpdateActivitiesSchedule()
   {
      // This method is not inline as it's called from multiple places.
   
      EconomicReportReleaseTimeMilliseconds_ =
         DateTimeKeeper_.GetTimerTickCounter( static_cast< double >( EconomicReportReleaseDateTimeMillisecondsSince1970_ ) );

      // This value shall be in the future or at least equal current time but this will not be the case if we are misconfigured.
>>>      PeerDataReceiverInvocationTimeMilliseconds_ =
>>>         EconomicReportReleaseTimeMilliseconds_ + PeerDataReceiver_.InvocationTimeOffsetMilliseconds();

>>>      // This must be later than {PeerDataReceiverInvocationTimeMilliseconds_} but I don't want to assume that.
      EconomicReportReceiverInvocationTimeMilliseconds_ =
         EconomicReportReleaseTimeMilliseconds_ + EconomicReportReceiver_->InvocationTimeOffsetMilliseconds();
>>>      assert( EconomicReportReceiverInvocationTimeMilliseconds_ - PeerDataReceiverInvocationTimeMilliseconds_ > 0 );

      {
         double entryOrdersModificationDateTimeMillisecondsSince1970
            ( static_cast< double >( EconomicReportReleaseDateTimeMillisecondsSince1970_ ) + EntryOrdersModificationTimeOffsetMilliseconds_ );

         // Entry order sending time is calculated precisely.
         // This value must be in the future or at least equal current time but this will not be the case if we are misconfigured.
         EntryOrdersModificationTimeMilliseconds_ = DateTimeKeeper_.GetTimerTickCounter( entryOrdersModificationDateTimeMillisecondsSince1970 );
      }
   }

#endif
#if( /* {private StartThread2}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::StartThread2()
   {
      // yg? We might need an operation cancellation token aware thread but the {::Poco::Thread} class has no virtual methods.
      // yg? Can we have an operation cancellation token aware runnable?
      // TODO 3 yg? An alternative would be to use {::std::thread} or concurrency runtime, provided one is available on Linux.
      //
      // TODO 3 yg? To make it possible to start multiple threads, we need a thread class containing or implementing a {::Poco::RunnableAdapter}.
      // TODO 3 yg? But we better use {::std::thread} or concurrency runtime, provided one is available on Linux.
      //
      // yg? Parts of this code can be moved to helper methods.
//TODO remove prev. comment?

      // At this point, entry orders have been accepted and are pending deep out of the money, as validated by {WaitEntryDeepOutOfMoneyOrdersAccepted}.
      // We didn't exit the locked scope since.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_None );

      State2Code_ = TState2Code_PreparingModifyEntryOrdersTowardsMoney;

      // yg? I've been thinking about moving this increment to the other thread but it's difficult to ensure correct behavior in all marginal cases.
      // yg? For example main thread would be able to recycle all objects before the other thread had a chance to make the increment.
      // yg? If this code was performance critical I'd rather eliminate this increment and use a {bool} flag to non-atomically set before starting the thread.
      // yg? See a related "TODO 3" in the {::Common::ControlFlow::TThreadedActivityCancellationToken} class comment regarding maintaining
      // yg? 2 reference counters: one being atomic and another not atomic.
      ThreadedActivityCancellationToken_->duplicate();

      //try
      //{
         Thread2_.start( * this );
      //}
      //catch( ... )
      //{
         //>>>Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      //   ThreadedActivityCancellationToken_->release();
      //   throw;
      //}
   }

#endif
#if( /* {private PrepareReceiveEconomicReport}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::PrepareReceiveEconomicReport()
   {
      // yg? Consider splitting this code into 2 methods.

      {
         bool economicReportReceiverWarmedUp( false );

         // yg? Some report receiver implementations need at least 1 warm-up step but because this time can (potentially) be
         // yg? significantly later than the time used by {PrepareActivitiesSchedule} it's not guaranteed that a warm-up step will occur.
         // yg? A solution would be to save that timestamp in a member field and use it here.
         int economicReportReceiverWarmUpStepTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );

         for( ; ; )
         {
            int economicReportReceiverWarmUpStepIntervalMilliseconds
               ( ( ! economicReportReceiverWarmedUp ) ?

                 // This may be 0.
                 // In that case to ensure correct behavior {EconomicReportReceiver_->TryMakeWarmUpStep} would have to return {true}.
                 // yg? Consider to guarantee that at least 1 warm-up step will be made when this is 0.
                 // yg? Another solution would be to make the minimum number of warm-up steps configurable.
                 // yg? Another solution would be to add another virtual method to economic report receiver to notify it that there will be no more warm-up steps.
                 // yg? See related comments near {TEconomicReportReceiverBase< TResult_ >::TryMakeWarmUpStep} declaration.
                 EconomicReportReceiver_->WarmUpStepInterval1Milliseconds() :

                 // This is officially required to be positive but the formulas would work even if this is 0. Although the behavior would probably be incorrect.
                 EconomicReportReceiver_->WarmUpStepInterval2Milliseconds()
               );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( economicReportReceiverWarmUpStepIntervalMilliseconds >= 0 );

            // The result of a modulo operation is not uniformly distributed -- no big deal.
            // Assuming this will not overflow.
            economicReportReceiverWarmUpStepIntervalMilliseconds =
               static_cast< int >
                  ( ( static_cast< unsigned int >( economicReportReceiverWarmUpStepIntervalMilliseconds ) + 1U ) / 2U +
                    ( ::Common::Math::TMultiplyWithCarryRandomNumberCommonGeneratorHelpers::MultiplyWithCarryRandomNumberCommonGenerator.GenerateMediumQuality32Bits() %
                      ( static_cast< unsigned int >( economicReportReceiverWarmUpStepIntervalMilliseconds ) + 1U )
                    )
                  );

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( economicReportReceiverWarmUpStepIntervalMilliseconds >= 0 );
            economicReportReceiverWarmUpStepTimeMilliseconds += economicReportReceiverWarmUpStepIntervalMilliseconds;
            
            // Assuming this will not overflow.
//TODO Bug: if {EconomicReportReceiver_->WarmUpStageEndTimeOffsetMilliseconds()} is after the time we are to start peer message receiver
//TODO it can be started later???
//TODO We can end warm-up sooner but this can potentially result in NewsHub heartbeat timeout.
//TODO Log a warning or better error if the timings are configured incorrectly.
//TODO Write coments.
//TODO This bug/feature is actually documented near <InvocationTimeOffsetMilliseconds>-3420</InvocationTimeOffsetMilliseconds>
            if( economicReportReceiverWarmUpStepTimeMilliseconds - EconomicReportReleaseTimeMilliseconds_ < EconomicReportReceiver_->WarmUpStageEndTimeOffsetMilliseconds() )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               if( ! economicReportReceiverWarmedUp )
               {
                  static char const constantString1AsArray[]( "not completely warmed up economic report receiver" );
                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

                  // TODO 2 yg? In warm-up or test mode this should be "Information". Bad idea? Also change the reg-ex in the operation doc.
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }
               else
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
               break;
            }

            // Date-time keeper and activities schedule not monotonicity can (potentially) inflict damage here.
            // A solution would be to sleep multiple times for a half of the remaining time and probably recalculate some numbers after each sleep.
            REngineAdapter_->SleepUntilMultimediaTimeMilliseconds( economicReportReceiverWarmUpStepTimeMilliseconds );

            // yg? If this takes longer than an interval between steps the behavior will be incorrect.
            // And this really must take much less as otherwise it's possible that the date-time keeper will not stabilize sufficiently.
            if( ! TryMakeEconomicReportReceiverWarmUpStep() )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               if( ! economicReportReceiverWarmedUp )
               {
                  economicReportReceiverWarmedUp = true;

                  {
                     static char const constantString1AsArray[]( "warmed up economic report receiver" );
                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                     logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                  }
               }
               else
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
            }
         }
      }

>>>      REngineAdapter_->SleepUntilMultimediaUpdatingTimeMilliseconds( PeerDataReceiverInvocationTimeMilliseconds_ );

//TODO I moved this code to broker adapter. Remove it.
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
   }

#endif
#if( /* {private TryMakeEconomicReportReceiverWarmUpStep}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TStrategy::TryMakeEconomicReportReceiverWarmUpStep()
   {
      TState1Code state1CodeCopy( State1Code_ );

      // Preventing multithreaded access to the date-time keeper.
      // At this point, in warm-up or test mode the activities schedule is already frozen.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( State1Code_ == TState1Code_PreparedActivitiesSchedule ||
           State1Code_ == TState1Code_FrozeActivitiesSchedule
         );
      State1Code_ = TState1Code_FrozeActivitiesSchedule;

      REngineAdapter_->UnlockREngine();

      // The date-time keeer will not be updated until this returns.
      bool returnValue( EconomicReportReceiver_->TryMakeWarmUpStep() );

      REngineAdapter_->LockREngine();

      // According to the code contract, we may throw a {::Common::ControlFlow::TOperationCancelledException} only while {REngineAdapter_->REngine()} is locked.
      // yg? It's currently impossible that at this point the activity cancellation token can be signaled. So consider eliminating this validation.
      // yg? Non-volatile read.
      ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled();

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ == TState1Code_FrozeActivitiesSchedule );
      State1Code_ = state1CodeCopy;
      return returnValue;
   }

#endif
#if( /* {private StartThread3}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::StartThread3()
   {
      // At this point, in warm-up or test mode the activities schedule is already frozen.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( State1Code_ == TState1Code_PreparedActivitiesSchedule ||
           State1Code_ == TState1Code_FrozeActivitiesSchedule
         );
      State1Code_ = TState1Code_ReceivingEconomicReport;

      ThreadedActivityCancellationToken_->duplicate();
      //Thread3_.start( ::Poco::RunnableAdapter< TStrategy >( ( * this ), ( & TStrategy::Run3 ) ) );
      Thread3_.start( RunnableAdapter3_ );
   }

#endif
#if( /* {private TryReceiveEconomicReport}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::TryReceiveEconomicReport()
   {
      //// Test.
      //{
      //   int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
      //   int int1( currentTimeMilliseconds - EconomicReportReceiverInvocationTimeMilliseconds_ );
      //   //if( int1 != 0 )
      //   {
      //      ::std::cout << int1 << ::std::endl;
      //   }
      //}

      // Another option would be to exit the locked scope and call {::Common::Threading::TThreadingHelpers::SleepUntilMultimediaTimeMilliseconds}.
      // But that would be a bad idea if it was possible that another thread signals {* ThreadedActivityCancellationToken_}.
      REngineAdapter_->SleepUntilMultimediaTimeMilliseconds( EconomicReportReceiverInvocationTimeMilliseconds_ );

      //// Test.
      //{
      //   int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
      //   int int1( currentTimeMilliseconds - EconomicReportReceiverInvocationTimeMilliseconds_ );
      //   //if( int1 != 0 )
      //   {
      //      ::std::cout << int1 << ::std::endl;
      //   }
      //}

      //// Test.
      //PositionExpectedDirectionCode_ = ::Finance::Trading::TPositionDirectionCode_Short;

      REngineAdapter_->UnlockREngine();
      EconomicReportReceiver_->TryRun
//TODO remove garbage
         ( //TradingSystemWarmUpModeCode_,
           //ModeCode_,
           EconomicReportReleaseDateTimeMillisecondsSince1970_,
           ModeCode_
         );

      // yg? Non-volatile write. Assuming we will cross a release memory barrier momentarily.
      ShallAbortModifyEntryOrdersTowardsMoney_ = true;

      REngineAdapter_->LockREngine();

      //// Test.
      //PositionExpectedDirectionCode_ = ::Finance::Trading::TPositionDirectionCode_None;

      // According to the code contract, we may throw a {::Common::ControlFlow::TOperationCancelledException} only while {REngineAdapter_->REngine()} is locked.
      // yg? It's currently impossible that at this point the activity cancellation token can be signaled. So consider eliminating this validation.
      // yg? Non-volatile read.
      ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled();
   }

#endif
#if( /* {private OnTriedReceiveEconomicReport}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::OnTriedReceiveEconomicReport()
   {
      // Did we not receive peer message that indicated that economic report was successfully received (no matter if it was ignored)?
      if( State1Code_ < TState1Code_ReceivedButIgnoredEconomicReport )

      {
         // This can't be {TState1Code_FailedReceiveEconomicReport} even if we received that value with peer message.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ == TState1Code_ReceivingEconomicReport );
      }
      else

      // In this case we have nothing left to do, regardless if report reception succeeded or failed and what is in the report.
      // Assuming that the untradable ranges are configured the same for all peers, so all peers interpret the report in the same way.
      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( State1Code_ == TState1Code_ReceivedButIgnoredEconomicReport ||
              State1Code_ == TState1Code_ReceivedEconomicReport
            );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_CancellingEntryOrders );

//TODO Validate {EconomicReportReceiver_->OutcomeCode()}?
         if( EconomicReportReceiver_->OutcomeCode() == TEconomicReportReceiverOutcomeCode_Success )
         {
            // TODO 1 yg? Here and elsewhere, add logging that we sent this. But log nothing
            // TODO 1 yg? if {EconomicReportReceiver_->TryCreateNewsHubMessage} returns {nullptr}.
            TrySendEconomicReportToNewsHubIfPossible();
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         {
            // The "economic report related peer message" can also indicate that economic report was ignored.
            static char const constantString1AsArray[]( "received, successfully or not, economic report but ignored it as we already received economic report related peer message" );

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            // Labeling this "Warning" to indicate that we might have not logged some related errors.
            logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         return;
      }

      UpdatePositionExpectedDirectionCodeIfPossible();

      // At this point this can send only a speculative exit order, not a normal one.
      // yg? Therefore we don't need to execute the normal exit order related logic here.
      // yg? Maybe we need another simplified method to only send a speculative exit order if needed
      // yg? that would also be called by {CreateAndSendExitOrderIfNeeded}.
      // yg? But any performance improvement would be negligible.
      // This will do nothing if we are configured to send no entry orders or ignore the report.
      // yg?? After this we will immediately request to cancel "any" orders, which, depending on the brokerage server logic,
      // yg?? might cancel the order we are now to send, which would result in the position not being completely closed.
      // yg?? Furthermore, other peers are also concurrently sending "any" order cancellation requests.
      // After this we might need to create a pooled order, which we will do after performance critical actions.
      bool exitSpeculativeOrderSent( CreateAndSendExitOrderIfNeeded() );

      // yg? We probably don't need this variable. Insatead we can use {State2Code_} as is and change it after the logging,
      // just like we do in {OnReceivedPeerMessage}.
      TState2Code state2CodeCopy( State2Code_ );

      // We received economic report before we requested to cancel entry orders?
      // This condition will be {true} also if thread 2 did not request to modify entry orders towards the money, or possibly has not even started.
      if( state2CodeCopy < TState2Code_CancellingEntryOrders )

      {
         State2Code_ = TState2Code_CancellingEntryOrders;

         // Note that we don't need to "forget" all entry orders if we request to cancel them before we have a chance to request to modify them towards the money.
         // If I actually wanted to "forget" them it would probably be more correct to do that before calling {CreateAndSendExitOrderIfNeeded}
         // but that would result in a performance penalty with probably no benefit.
         // yg? Not checking if logged in.
         REngineAdapter_->RequestCancelAnyOrders();

         //TrySendPeerMessage( IsWarmUpOrTestMode_, false );
         TrySendPeerMessage( IsWarmUpOrTestMode_, static_cast< TPeerTypesBitMask >( TPeerTypesBitMask_Important | TPeerTypesBitMask_Unimportant ) );

         if( State1Code_ >= TState1Code_ReceivedButIgnoredEconomicReport )
         {
            TrySendEconomicReportToNewsHubIfPossible();
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         // We don't have any time sensitive actions to be done before unsubscribing from market data.
         // yg? Not checking if logged in.
         REngineAdapter_->HackRequestUnsubscribeInstrumentMarketDataIfNeeded();
      }
      else
      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( state2CodeCopy == TState2Code_CancellingEntryOrders );

         // At this point:
         // @ One or more peers, including us, requested to cancel "any" orders and notified the others.
         // @ We neither sent nor received peer message that indicated that economic report was successfully received
         //    (no matter if it was ignored).
         // So now if we successfully received and not ignored economc report we need to send it only to the peer
         // who is configured to send some entry orders.
         // Note that if we are configured to send some entry orders, in our configuration all our peers should be designated as "unimportant".
         {
            if( State1Code_ >= TState1Code_ReceivedEconomicReport )
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ == TState1Code_ReceivedEconomicReport );
               //TrySendPeerMessage( IsWarmUpOrTestMode_, true );
               TrySendPeerMessage( IsWarmUpOrTestMode_, TPeerTypesBitMask_Important );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
         }

         // TODO 1 yg? Above code should be merged with this. Just jump to a label after this condition check.
         if( State1Code_ >= TState1Code_ReceivedButIgnoredEconomicReport )
         {
            TrySendEconomicReportToNewsHubIfPossible();
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
      }

      {
         // yg? Can the logging delay exit order sending? Maybe it's unlikely.
         // yg? Consider leaving the locked scope.
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

         // The order of these {case}s is optimized for performance.
         switch( State1Code_ )
         {
            case TState1Code_ReceivedEconomicReport :
            {
               {
                  static char const constantString1AsArray[]( "received economic report" );
                  logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               break;
            }

            case TState1Code_FailedReceiveEconomicReport :
            {
               {
                  static char const constantString1AsArray[]( "failed to receive economic report" );
                  logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               // Optimization hint.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! exitSpeculativeOrderSent );

               break;
            }
            
            case TState1Code_ReceivedButIgnoredEconomicReport :
            {
               {
                  static char const constantString1AsArray[]( "received but ignored economic report" );
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               // Optimization hint.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! exitSpeculativeOrderSent );

               break;
            }
            
            default :
            {
               YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
               break;
            }
         }

         if( NumberUnmodifiedTowardsMoneyEntryOrders_ > 0 )
         {
            if( NumberUnmodifiedTowardsMoneyEntryOrders_ >= ::std::numeric_limits< int >::max() )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else

            // We can get here only if we are configured to send some entry orders and their modification was real (not warm-up).
            {
               // Logging this after the "received economic report" but it's possible that we abort requesting to modify entry orders towards the money
               // because we received non-economic report related peer message and only later receive economic report. But in that case we already logged this
               // message. So another problem is that this can be logged multiple times. But let's keep it simple.
//TODO Can we log this on another thread? Just exit locked scope. And now we modify all or none, so the message should be different.
               static char const constantString1AsArray[]( "aborted requesting to modify some or all entry orders towards the money" );

               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }
         }
         else
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberUnmodifiedTowardsMoneyEntryOrders_ == 0 );
         }

         if( exitSpeculativeOrderSent )
         {
            // We can get here only after we successfully receive and process the report.
            // Therefore the message we are to log does not need to say "successfully or not".
            // So let's validate that.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ == TState1Code_ReceivedEconomicReport );

            {
               static char const constantString1AsArray[]( "sent a speculative exit order after receiving economic report" );

               // This should be marked "Warning" if some entry orders have already triggered and the report is strongly tradable.
               // But let's keep it free of convoluted judgement.
               logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         // This condition is explained above.
         if( state2CodeCopy < TState2Code_CancellingEntryOrders )

         {
            // We received economic report after we requested to modify entry orders towards the money and before we requested to cancel them?
            if( state2CodeCopy == TState2Code_PreparingCancelEntryOrders )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }

            // We received economic report before thread 2 requested to modify entry orders towards the money?
            // In this case we don't need to "forget" all entry orders.
            else

            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( state2CodeCopy < TState2Code_PreparingCancelEntryOrders );

               {
                  // TODO 3 yg? We need a more descriptive message here.
                  static char const constantString1AsArray[]( "{Prototype52::TStrategy::State2Code_ < Prototype52::TState2Code_PreparingCancelEntryOrders}" );

                  // Marking this message "Error" as this can happen if the report arrives too soon, which in turn can happen if we are misconfigured.
                  logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }
            }

            {
               static char const constantString1AsArray[]( "requested to cancel entry orders after receiving, successfully or not, economic report" );
               logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }
         }
         else
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( state2CodeCopy == TState2Code_CancellingEntryOrders );

            // yg? I decided to comment this out.
            //{
            //   // yg? One might argue that it's unnecessary to log this because we already logged that we requested to cancerl entry orders
            //   // yg? and we logged above that report reception completed.
            //   // yg? Although when we receive peer message we don't log that we requested to cancel entry orders.
            //   // yg? Problem is that this warning is usually logged every time the strategy runs, either after economic report reception completes,
            //   // yg? successfully or not, or when we receive peer message. But keeping it simple.
            //   // yg? Actually we will probably rarely log this more than once as we won't get to this point when {State1Code_ >= TState1Code_ReceivedButIgnoredEconomicReport}.
            //   // TODO 3 yg? We need a more descriptive message here.
            //   static char const constantString1AsArray[]( "{Prototype52::TStrategy::State2Code_ == Prototype52::TState2Code_CancellingEntryOrders}" );
            //
            //   logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            //}
         }
      }

      CreatePooledOrderIfNeeded();
   }

#endif
#if( /* {private UpdatePositionExpectedDirectionCodeIfPossible}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::UpdatePositionExpectedDirectionCodeIfPossible()
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ == TState1Code_ReceivingEconomicReport );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ == 0 );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
// TODO Maybe validate that this equals specific values.
         ( EconomicReportReceiver_->OutcomeCode() != TEconomicReportReceiverOutcomeCode_Undefined );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( PositionConfiguration_.RelativeDirectionCode == ::Finance::Trading::TPositionDirectionCode_Short ||
           PositionConfiguration_.RelativeDirectionCode == ::Finance::Trading::TPositionDirectionCode_Long
         );

      if( EconomicReportReceiver_->OutcomeCode() == TEconomicReportReceiverOutcomeCode_Success )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ == 0 );
         State1Code_ = TState1Code_FailedReceiveEconomicReport;
         return;
      }

      State1Code_ = TState1Code_ReceivedButIgnoredEconomicReport;

      // yg? This code can be refactored to be a loop traversing a collection of untradable ranges.
      {
         if( UntradableConditionConfiguration_.EconomicReportValueMinLimit1 <= UntradableConditionConfiguration_.EconomicReportValueMaxLimit1 )
         {
            // TODO 3 yg? When warming up the "high" case we should act as if this condition was true.
            if( EconomicReportReceiver_->Result > UntradableConditionConfiguration_.EconomicReportValueMaxLimit1 )

            {
               PositionExpectedDirectionCode_ = PositionConfiguration_.RelativeDirectionCode;
            }
            else
            {
               // TODO 3 yg? When warming up the "low" case we should act as if this condition was true.
               if( EconomicReportReceiver_->Result < UntradableConditionConfiguration_.EconomicReportValueMinLimit1 )

               {
                  PositionExpectedDirectionCode_ = ( - PositionConfiguration_.RelativeDirectionCode );
               }

               // TODO 3 yg? When warming up the "medium" case we should act as if this condition was true.
               else

               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ == 0 );
               }
            }

            State1Code_ = TState1Code_ReceivedEconomicReport;
         }
         else
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ == 0 );
         }

         if( UntradableConditionConfiguration_.EconomicReportValueMinLimit2 <= UntradableConditionConfiguration_.EconomicReportValueMaxLimit2 )
         {
            // TODO 3 yg? When warming up the "high" case we should act as if this condition was true.
            if( EconomicReportReceiver_->Result > UntradableConditionConfiguration_.EconomicReportValueMaxLimit2 )

            {
               PositionExpectedDirectionCode_ = PositionConfiguration_.RelativeDirectionCode * 2;
            }
            else
            {
               // TODO 3 yg? When warming up the "low" case we should act as if this condition was true.
               if( EconomicReportReceiver_->Result < UntradableConditionConfiguration_.EconomicReportValueMinLimit2 )

               {
                  PositionExpectedDirectionCode_ = PositionConfiguration_.RelativeDirectionCode * ( - 2 );
               }

               // TODO 3 yg? When warming up the "medium" case we should act as if this condition was true.
               else

               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
            }

            State1Code_ = TState1Code_ReceivedEconomicReport;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
      }
   }

#endif
#if( /* {private TrySendPeerMessage}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::TrySendPeerMessage
      ( bool isWarmUpOrTestMode1,
        //bool toImportantPeersOnly
        TPeerTypesBitMask peerTypesBitMask
      )
   {
      // This method is not inline as it's called from multiple places.
      // We don't need to execute all this code in some cases but keeping it here allows us to warm it up and simplifies things.

      // We are not supposed to send non-warm-up-or-test peer message while running in warm-up-or-test mode.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! ( IsWarmUpOrTestMode_ && ( ! isWarmUpOrTestMode1 ) ) );

      TPeerData peerData1;
      peerData1.IsWarmUpOrTestMode = isWarmUpOrTestMode1;
      peerData1.StrategyState1Code = State1Code_;
      peerData1.PositionExpectedDirectionCode = PositionExpectedDirectionCode_;
      peerData1.UpdateCheckSum();
      //PeerMessageSender_.TrySendPeerMessage( reinterpret_cast< char const * >( & peerData1 ), static_cast< int >( sizeof( peerData1 ) ), toImportantPeersOnly );
      PeerMessageSender_.TrySendPeerMessage( reinterpret_cast< char const * >( & peerData1 ), static_cast< int >( sizeof( peerData1 ) ), peerTypesBitMask );
   }

#endif
#if( /* {private TrySendEconomicReportToNewsHubIfPossible}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::TrySendEconomicReportToNewsHubIfPossible()
   {
      // This method is not inline as it's called from multiple places.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( EconomicReportReceiver_->OutcomeCode() == TEconomicReportReceiverOutcomeCode_Success );

      if( IsWarmUpOrTestMode_ )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         // We don't check if the user configured any NewsHub recipients.
         // If they didn't the performance penalty would be negligible.
         // If they did we would rather not add a performance penalty.
         // So keeping it simple.
         {
            // I considered calling this even if we are not going to send this message, just to warm it up, but it's unnecessary as
            // this is called anyway on a warm-up step.
            ::std::string const * newsHubMessage( EconomicReportReceiver_->TryCreateNewsHubMessage() );

            if( newsHubMessage != nullptr )
            {
               // Assuming this will not overflow.
               PeerMessageSender_.TrySendPeerMessage
                  ( newsHubMessage->data(), static_cast< int >( newsHubMessage->length() ), TPeerTypesBitMask_NewsHub );
            }
            else
            {
               //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
         }
      }
   }

#endif
#if( /* {private SleepUntilTerminationTime}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::SleepUntilTerminationTime() const
   {
      // This sleep allows {REngineAdapter_} to make multiple attempts to cancel entry orders and hopefully gives us enough time to close the position.
      // We don't pre-calculate this time.
      REngineAdapter_->SleepUntilMultimediaTimeMilliseconds( EconomicReportReleaseTimeMilliseconds_ + TerminationTimeOffsetMilliseconds_ );
   }

#endif
#if( /* {private LogEconomicReportReceptionActivityReportIfPossible}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::LogEconomicReportReceptionActivityReportIfPossible()
   {
      EconomicReportReceiver_->LogActivityReportIfPossible();
   }

#endif
#if( /* {private TryVerifyCompleted}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::TryVerifyCompleted() const
   {
      // Note that under some conditions we simply remove the entry orders that we didn't request to modify towards the money
      // from these collections, so we don't know if they actually completed.
//TODO we don't remove any more?
      if( EntryOrders_[ 0U ].empty() && EntryOrders_[ 1U ].empty() )

      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         static char const constantString1AsArray[]( "{Prototype52::TStrategy} did not complete but is terminating" );
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

         // We used to mark this message "Critical".
         logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif

#if( /* {private DoRun2}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::DoRun2()
   {
      RunTimer1();
      TradeOnThread2IfPossible();
   }

#endif
#if( /* {private RunTimer1}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::RunTimer1()
   {
      // TODO 3 yg? Minimize the time thread 2 holds the lock. Can we keep it unlocked at almost all times? At least calculator logging
      // TODO 3 yg? should be done outside locked scope. Benchmark how long it takes to execute 1 loop below.

      // We don't explicitly freeze the activities schedule {Timer1TickIntervalMilliseconds_} before sending entry orders.
      // We used to do that to ensure that the date-time keeper and the schedule will be monotonic.
      // But it's unnecessary because the schedule anyway gets frozen long before and even otherwise there would be no big damage
      // from a minor non-monotonicity.

      for( ; ; )
      {
         // The 1st of these conditions is usually {true} but even otherwise we will not break the loop prematurely.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( State2Code_ == TState2Code_PreparingModifyEntryOrdersTowardsMoney ||
              State2Code_ == TState2Code_CancellingEntryOrders
            );

         // This validation can fail if we are misconfigured.
         assert( NumberTimer1TicksUntilEntryOrdersModification_ >= 0 );
         assert( TimeSpanMillisecondsUntilEntryOrdersModification_ >= 0 );

         // This validation can also fail if some expressions overflow but assuming the user won't screw up so badly.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( NumberTimer1TicksUntilEntryOrdersModification_ * Timer1TickIntervalMilliseconds_ == TimeSpanMillisecondsUntilEntryOrdersModification_ );

         // This will be in the past if at the very beginning {TimeSpanMillisecondsUntilEntryOrdersModification_ < 0}.
         // This can happen if we are misconfigured.
         // This would not really break our logic but we would request to modify entry orders towards the money later
         // than the user might want.
         int endTimeMilliseconds( EntryOrdersModificationTimeMilliseconds_ - TimeSpanMillisecondsUntilEntryOrdersModification_ );

         REngineAdapter_->SleepUntilMultimediaTimeMilliseconds( endTimeMilliseconds );

         // We must ensure that the calculators contain valid values, even if we are behind the schedule.
         // yg? If this is inefficient it can starve {REngineAdapter_->REngine()} out of CPU time, which can delay market data arrival,
         // yg? especially right before requesting to modify entry orders towards the money when we log a few calculator updates in a row.
         // yg? For performance reasons, we should suppress or defer the logging on the last loop.
         // yg? Consider to split calculator updates and the logging into different methods and log the last update after requesting to modify entry orders
         // yg? towards the money.
         // yg? Actually order modification request sending can take many milliseconds, so the timestamp in the log would be inaccurate.
         // Assuming {endTimeMilliseconds} contains current time but in the reality we could oversleep.
         UpdateCheapMovingAverageCalculators( endTimeMilliseconds );

         if( NumberTimer1TicksUntilEntryOrdersModification_ > 0 )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( EntryOrdersModificationWarmUp1TimeOffsetTimer1Ticks_ < EntryOrdersModificationWarmUp2TimeOffsetTimer1Ticks_ );
         if( EntryOrdersModificationWarmUp2TimeOffsetTimer1Ticks_ + NumberTimer1TicksUntilEntryOrdersModification_ >= 0 )
         {
            // It's possible that this condition will never be {false} or will be false only once if we are misconfigured. No big deal.
            // In fact, the user might want to tweak the configuration so that this was {false} only once in warm-up or test mode.
// TODO 1 yg? The above comment is probably BS. We don't warm-up modify entry orders in warm-up mode, right? Actually the comment probably makes sense but I might need to clarify it with a "Note that ...".
            if( EntryOrdersModificationWarmUp2TimeOffsetTimer1Ticks_ + NumberTimer1TicksUntilEntryOrdersModification_ != 0 &&
                EntryOrdersModificationWarmUp1TimeOffsetTimer1Ticks_ + NumberTimer1TicksUntilEntryOrdersModification_ != 0
              )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // As mentioned in the config file, in warm-up and normal mode we do not warm-up entry order modification.
               // This is the same condition as in {SafeRequestModifyEntryOrdersTowardsMoney}.
//TODO think if this condition needs flipping
//TODO warm-up or test -- reorder, but think if it's efficient. actually this is now bullshit.
               if( TradingSystemWarmUpModeCode_ != TTradingSystemWarmUpModeCode_None && ModeCode_ != TPeerStrategyBaseModeCode_Test )

               {
//TODO this needs to be validated before the {if}; all possible valies need to be validated
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ModeCode_ == TPeerStrategyBaseModeCode_Normal );
               }
               else
               {
                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                  if( State2Code_ <= TState2Code_PreparingModifyEntryOrdersTowardsMoney )
                  {
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_PreparingModifyEntryOrdersTowardsMoney );
                     if( REngineAdapter_->Ready() )
                     {
                        {
                           static char const constantString1AsArray[]( "warming up entry order modification" );
                           logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                        }

                        //#pragma message( "yg---?? Test." )
                        //EntryOrders_[ 0U ].front()->StateBitMask =
                        //   static_cast< ::RApiFacade::TOrderStateBitMask >( EntryOrders_[ 0U ].front()->StateBitMask |
                        //                                                                                  ::RApiFacade::TOrderStateBitMask_ShallBeCancelled
                        //                                                                                );
                        //WarmUpRequestModifyEntryOrdersTowardsMoney();
                        //WarmUpRequestModifyEntryOrdersTowardsMoney();
                        //REngineAdapter_->RequestCancelOrderWhenCan( * EntryOrders_[ 0U ].front() );
                        //REngineAdapter_->RequestCancelOrderWhenCan( * EntryOrders_[ 0U ].front() );
                        //REngineAdapter_->RequestCancelAnyOrders();
                        //REngineAdapter_->RequestCancelAnyOrders();
                        //REngineAdapter_->RequestCancelAnyOrders();
                        //WarmUpRequestModifyEntryOrdersTowardsMoney();
                        //WarmUpRequestModifyEntryOrdersTowardsMoney();

                        // yg? Not checking that we can modify the orders.
                        // yg? Because we warm-up-modify the orders twice it's possible that previous modification hasn't completed yet.
                        // yg? This is currently OK but it can become a problem with another brokerage API.
                        WarmUpRequestModifyEntryOrdersTowardsMoney();

                        {
                           static char const constantString1AsArray[]( "warmed up entry order modification" );
                           logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                        }
                     }
                     else
                     {
                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                        goto label1;
                     }
                  }
                  else
                  {
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_CancellingEntryOrders );

                  label1:
                     {
                        static char const constantString1AsArray[]( "cannot warm-up entry order modification" );
//TODO warning?
                        logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                     }

                     //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                  }
               }
            }
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( PeerMessageSendingWarmUp1TimeOffsetTimer1Ticks_ < PeerMessageSendingWarmUp2TimeOffsetTimer1Ticks_ );
         if( PeerMessageSendingWarmUp2TimeOffsetTimer1Ticks_ + NumberTimer1TicksUntilEntryOrdersModification_ >= 0 )
         {
            if( PeerMessageSendingWarmUp2TimeOffsetTimer1Ticks_ + NumberTimer1TicksUntilEntryOrdersModification_ != 0 &&
                PeerMessageSendingWarmUp1TimeOffsetTimer1Ticks_ + NumberTimer1TicksUntilEntryOrdersModification_ != 0
              )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else

            // No logic will be broken if this block executes 0 or 1 time.
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                  ( ModeCode_ == TPeerStrategyBaseModeCode_Normal || ModeCode_ == TPeerStrategyBaseModeCode_Test );
               if( ModeCode_ == TPeerStrategyBaseModeCode_Test )
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
               else
               {
                  // I want NewsHub to receive this sooner, so sending this before peer message.
                  // We probably don't need separate time offsets for this.
                  // We probably don't need a separate method for this.
// TODO Send this 1 timer tick before.
                  PeerMessageSender_.TrySendPeerMessage( TNewsHubHelpers::NewsFeedAdapterHeartBeatMessageTextAsArray,
                                                                           TNewsHubHelpers::NewsFeedAdapterHeartBeatMessageTextLength,
                                                                           TPeerTypesBitMask_NewsHub
                                                                         );
               }

               // We don't care if we already sent or received non-warm-up peer message. It's unlikely that we did.
               // Even if we did it's unlikely that this sending will delay any time sensitive activities
               // to be performed either by us or another peer.
               // The configuration must ensure that warm-up peer message will be sent and received before time sensitive activities start
               // but even otherwise no logic will be broken.
               //TrySendPeerMessage( true, false );
               TrySendPeerMessage( true, static_cast< TPeerTypesBitMask >( TPeerTypesBitMask_Important | TPeerTypesBitMask_Unimportant ) );
            }
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( FileSystemCacheFlushing1TimeOffsetTimer1Ticks_ < FileSystemCacheFlushing2TimeOffsetTimer1Ticks_ );
         if( FileSystemCacheFlushing2TimeOffsetTimer1Ticks_ + NumberTimer1TicksUntilEntryOrdersModification_ >= 0 )
         {
            // It's possible that this condition will never be {false} or will be false only once if we are misconfigured. No big deal.
            // In fact, the user might want to tweak the configuration so that this was {false} only once in warm-up or test mode.
            if( FileSystemCacheFlushing2TimeOffsetTimer1Ticks_ + NumberTimer1TicksUntilEntryOrdersModification_ != 0 &&
                FileSystemCacheFlushing1TimeOffsetTimer1Ticks_ + NumberTimer1TicksUntilEntryOrdersModification_ != 0
              )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // We don't need and probably should not flush file system cache when this is {false}.
               if( State2Code_ <= TState2Code_PreparingModifyEntryOrdersTowardsMoney )

               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_PreparingModifyEntryOrdersTowardsMoney );
                  FileSystemCacheFlusher_.AsyncRun();
               }
               else
               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_CancellingEntryOrders );
                  //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               }
            }
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         -- NumberTimer1TicksUntilEntryOrdersModification_;
         TimeSpanMillisecondsUntilEntryOrdersModification_ -= Timer1TickIntervalMilliseconds_;
      }
   }

#endif
#if( /* {private UpdateCheapMovingAverageCalculators}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::UpdateCheapMovingAverageCalculators
      ( int currentTimeMilliseconds
      )
   {
      // If we or another peer cancels "any" orders long before economic report release we will also unsubscribe from market data
      // but will keep using the last known market data. This should not inflict damage as we will anyway not attempt to trade.

      //::Poco::Int64 currentDateTimeMillisecondsSince1970( DateTimeKeeper_.GetCurrentDateTimeMillisecondsAsInteger< ::Poco::Int64 >() );

      InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.Update
         ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote );

      // After the 1st update this calculator will reflect the number of trades over a usually shorter time-span. No big deal.
      // Actually the time-span probably can be longer too as {PrepareActivitiesSchedule} uses current time plus 1.
      NumberInstrumentTradesCheapMovingAverageCalculator_.Update();

      if( // In the unlikely case of {NumberTimer1TicksUntilEntryOrdersModification_} being negative,
          // provided {NumberDataLastLoggingsOnTimer1TickToForce_} is not negative, this condition will be {false}.
          NumberTimer1TicksUntilEntryOrdersModification_ >= NumberDataLastLoggingsOnTimer1TickToForce_ &&

          NumberTimer1TicksUntilEntryOrdersModification_ % DataLoggingIntervalTimer1Ticks_ != 0
        )
      {
         return;
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         int const tempString1BufferLength( 256 );
         ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
         ::Poco::Int64 currentDateTimeMillisecondsSince1970( DateTimeKeeper_.GetDateTimeMillisecondsAsInteger< ::Poco::Int64 >( currentTimeMilliseconds ) );

         // yg? Using current thread locale.
         ::std::string currentDateTimeMillisecondsSince1970AsString
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
            ( ::Poco::DateTimeFormatter::format( ::Poco::Timestamp( currentDateTimeMillisecondsSince1970 * ::Poco::Timespan::MILLISECONDS ), ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMillisecondResolutionFormatString ) );

         {
            static char const formatConstantString1AsArray[]( "instrument best bid and ask price cheap moving averages; %s; %I64u; %+.*g; %+.*g; %+.*g; %+.*g" );

            //int const tempString1BufferLength( ??? );
            //::std::>>>string2010 tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
            //tempString1.resize( static_cast< unsigned int >( tempString1BufferLength ) );

            // We only need this to be non-negative to log it as an unsigned but we know that at this point it's positive, so let's validate that.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.UpdateCounter() > 0 );

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      currentDateTimeMillisecondsSince1970AsString.c_str(),
                      static_cast< ::Poco::UInt64 >( InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.UpdateCounter() ),
                      10,
                      InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.InstrumentBestAggregatedBidQuotePriceCheapMovingAverage(),
                      10,
                      InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price - InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.InstrumentBestAggregatedBidQuotePriceCheapMovingAverage(),
                      10,
                      InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.InstrumentBestAggregatedAskQuotePriceCheapMovingAverage(),
                      10,
                      InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price - InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.InstrumentBestAggregatedAskQuotePriceCheapMovingAverage()
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
            logger1.information( tempString1 );
         }

         {
            static char const formatConstantString1AsArray[]( "number of instrument trades cheap moving average; %s; %I64u; %.*g" );

            //int const tempString1BufferLength( ??? );
            //::std::>>>string2010 tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
            tempString1.resize( static_cast< unsigned int >( tempString1BufferLength ) );

            // We only need this to be non-negative to log it as an unsigned but we know that at this point it's positive, so let's validate that.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberInstrumentTradesCheapMovingAverageCalculator_.UpdateCounter() > 0 );

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                      currentDateTimeMillisecondsSince1970AsString.c_str(),
// TODO dont log this
                      static_cast< ::Poco::UInt64 >( NumberInstrumentTradesCheapMovingAverageCalculator_.UpdateCounter() ),
                      10,
                      NumberInstrumentTradesCheapMovingAverageCalculator_.CheapMovingAverage()
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
            logger1.information( tempString1 );
         }
      }
   }

#endif
#if( /* {private WarmUpRequestModifyEntryOrdersTowardsMoney}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::WarmUpRequestModifyEntryOrdersTowardsMoney()
   {
      // This method is not inline as it's called from multiple places.
      // yg? We warm-up-modify orders in the order opposite to the real modification.
      // yg? This results in "any" orders being cancelled in the order of real modification.
      // yg? This is important in case another instance of the application is going to cancel "any" orders.

      // The sizes can be 0U.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == EntryOrders_[ 1U ].size() );

      ::std::vector< ::RApiFacade::TSingleInstrumentOrder * >::iterator entryOrdersIterators1[ 2U ] = { EntryOrders_[ 0U ].end(), EntryOrders_[ 1U ].end() };
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( RandomNumber1_ <= 1U && ( RandomNumber1_ ^ 1U ) <= 1U );
      ::std::vector< ::RApiFacade::TSingleInstrumentOrder * >::iterator & entryOrdersFirstIterator1( entryOrdersIterators1[ RandomNumber1_ ] );
      ::std::vector< ::RApiFacade::TSingleInstrumentOrder * >::iterator & entryOrdersSecondIterator1( entryOrdersIterators1[ RandomNumber1_ ^ 1U ] );

      // It's inefficient to call {EntryOrders_[ 0U ].begin} multiple times but it's not performance critical.
      while( entryOrdersIterators1[ 0U ] != EntryOrders_[ 0U ].begin() )

      {
         -- entryOrdersIterators1[ 0U ];
         -- entryOrdersIterators1[ 1U ];
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( * entryOrdersIterators1[ 0U ] )->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Short );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( * entryOrdersIterators1[ 1U ] )->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Long );

         // Changing order price by the double of the minimum price increment.
         // This ensures that a rounding of midpoint to even or rounding errors will still produce a different value.
         // We should pre-calculate this but it's not performance critical.
         double priceDifference1( ( * entryOrdersIterators1[ 0U ] )->Instrument().PriceIncrementMinLimit * 2.0 );

         // Assuming that this is still deep out of the money, even if we do this a few times.
         // Not rounded.
         ( * entryOrdersIterators1[ 0U ] )->TriggerPrice += priceDifference1;
         ( * entryOrdersIterators1[ 1U ] )->TriggerPrice -= priceDifference1;

         // I've been thinking if it would be better to swap these modifications to alter the order of cancellations but I don't think so.
         // yg? Not checking if logged in and can modify the orders.
         // yg? Actually in most if not all places where we call {WarmUpRequestModifyEntryOrdersTowardsMoney} we check that we are logged in
         // yg? but that probably doesn't guarantee that this won't blow up.
         REngineAdapter_->RequestModifyOrder( * * entryOrdersSecondIterator1 );
         REngineAdapter_->RequestModifyOrder( * * entryOrdersFirstIterator1 );

         //#pragma message( "yg---?? Test." )
         //::RApiFacade::TSingleInstrumentOrder * orders1[ 2U ] = { ( * entryOrdersSecondIterator1 ), ( * entryOrdersFirstIterator1 ) };
         //REngineAdapter_->RequestModifyOrders( orders1, orders1 + 2U );
      }
   }

#endif
#if( /* {private TradeOnThread2IfPossible}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::TradeOnThread2IfPossible()
   {
      // This condition will be {false} if other threads requested to cancel entry orders before the time came to request to modify them towards the money.
      // This can happen if report reception already completed, successfully or not.
      // In a more marginal case an entry order can be spontaneously cancelled or filled.
      // Another instance of the application can cancel "any" orders but it should not happen before we request to modify entry orders towards the money.
      if( State2Code_ <= TState2Code_PreparingModifyEntryOrdersTowardsMoney )

      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_PreparingModifyEntryOrdersTowardsMoney );
      }
      else
      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_CancellingEntryOrders );

         // TODO 1 yg? Do we really need to log this? The other thread already logged a relevant error.
         {
            // TODO 3 yg? We need a more descriptive message here.
            static char const constantString1AsArray[]( "{Prototype52::TStrategy::State2Code_ > Prototype52::TState2Code_PreparingModifyEntryOrdersTowardsMoney}" );

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         return;
      }

      // The sizes can be 0U.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == PositionConfiguration_.EntryOrdersConfiguration.size() );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == EntryOrders_[ 1U ].size() );

      unsigned int bitMask1;

      do
      {
         // This will work correct even if we are configured to send no entry orders.
         if( ::RApiFacade::TSingleInstrumentOrderHelpers::OrdersStateBitMaskEqual
                  ( EntryOrders_[ 0U ].cbegin(),
                    EntryOrders_[ 0U ].cend(),
                    ::RApiFacade::TOrderStateBitMask_NewOrderRequestReceivedByBroker
                  ) &&
              ::RApiFacade::TSingleInstrumentOrderHelpers::OrdersStateBitMaskEqual
                  ( EntryOrders_[ 1U ].cbegin(),
                    EntryOrders_[ 1U ].cend(),
                    ::RApiFacade::TOrderStateBitMask_NewOrderRequestReceivedByBroker
                  )
           )

         {
            // yg? When this returns {false}, consider still modifying entry orders but setting their quantity to 1 quantity increment.
            // yg? This idea now makes no sense as order quantity is always 1 quantity increment.
            // yg? But another idea would be to modify only 1 pair of orders. But if active trading already started
            // yg? the modification of one of the orders will usually fail and another order will not get filled.
            if( MayModifyEntryOrdersTowardsMoney() )

            {
               // When this executes only warm-up modification logic it leaves {NumberUnmodifiedTowardsMoneyEntryOrders_ == ::std::numeric_limits< int >::max()}.
               // This will work correct even if we are configured to send no entry orders.
               SafeRequestModifyEntryOrdersTowardsMoney();

               if( NumberUnmodifiedTowardsMoneyEntryOrders_ <= 0 ||
                   NumberUnmodifiedTowardsMoneyEntryOrders_ >= static_cast< int >( EntryOrders_[ 0U ].size() )
                 )
               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                     ( NumberUnmodifiedTowardsMoneyEntryOrders_ == 0 ||
                       NumberUnmodifiedTowardsMoneyEntryOrders_ == ::std::numeric_limits< int >::max() ||
                       static_cast< unsigned int >( NumberUnmodifiedTowardsMoneyEntryOrders_ ) == EntryOrders_[ 0U ].size()
                     );

                  if( ! EntryOrders_[ 0U ].empty() )
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     // If we are configured to send no entry orders let's unsubscribe from market data sooner
                     // as we won't run post-entry order sending protection logic.
                     // Where we call this below or elsewhere it will do nothing.
                     // We don't have any time sensitive actions to be done before unsubscribing from market data.
                     // yg? Not checking if logged in.
                     REngineAdapter_->HackRequestUnsubscribeInstrumentMarketDataIfNeeded();
                  }
               }
               else
               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberUnmodifiedTowardsMoneyEntryOrders_ > 0 );
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberUnmodifiedTowardsMoneyEntryOrders_ < ::std::numeric_limits< int >::max() );
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( static_cast< unsigned int >( NumberUnmodifiedTowardsMoneyEntryOrders_ ) < EntryOrders_[ 0U ].size() );

                  // Any unmodified towards the money entry orders will very likely be cancelled without a fill.
                  // So if we aborted modification of some (not all) entry orders let's "forget" them so that the exit order sending logic did not wait
                  // for the unmodified entry orders to be cancelled.
                  // yg? Consider moving this code to a method named {removeUnmodifiedTowardsMoneyEntryOrders} or {forgetUnmodifiedTowardsMoneyEntryOrders}.
                  {
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! EntryOrders_[ 0U ].empty() );
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == PositionConfiguration_.EntryOrdersConfiguration.size() );
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == EntryOrders_[ 1U ].size() );
                     ::std::vector< ::RApiFacade::TSingleInstrumentOrder * >::iterator entryShortOrdersIterator1( EntryOrders_[ 0U ].end() );
                     ::std::vector< ::RApiFacade::TSingleInstrumentOrder * >::iterator entryLongOrdersIterator1( EntryOrders_[ 1U ].end() );
                     int counter1( NumberUnmodifiedTowardsMoneyEntryOrders_ );
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( counter1 > 0 );
                     do
                     {
                        -- entryShortOrdersIterator1;
                        -- entryLongOrdersIterator1;

                        // We will not receive any execution restatements. Although most likely there were no executions.
                        // We are the only event listener, so unhooking in the most efficient way.
                        // yg? There appears to be no way to validate that we are the only event listener.
                        ( * entryShortOrdersIterator1 )->OnReceivedData.clear();
                        ( * entryLongOrdersIterator1 )->OnReceivedData.clear();
                     }
                     while( ( -- counter1 ) > 0 );
                     EntryOrders_[ 0U ].erase( entryShortOrdersIterator1, EntryOrders_[ 0U ].end() );
                     EntryOrders_[ 1U ].erase( entryLongOrdersIterator1, EntryOrders_[ 1U ].end() );

                     // This also validates that we must not unsubscribe from market data sooner.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! EntryOrders_[ 0U ].empty() );

                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == PositionConfiguration_.EntryOrdersConfiguration.size() - static_cast< unsigned int >( NumberUnmodifiedTowardsMoneyEntryOrders_ ) );
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == EntryOrders_[ 1U ].size() );
                  }
               }

               // The following logic will work even if we aborted modification of some or all entry orders.
               // In that case main thread will immediately process the report or thread 3 will immediately process peer message,
               // request to cancel "any" orders, and log a message saying that some entry order modifications have been aborted.
               // It's very likely to happen before {SleepUntilEconomicReportReceptionTimeoutExpires} returns but even otherwise no logic will be broken.
               // yg? But it's possible that pending market data will be processed before that, which will result in a delay.
               // yg? A performance improvement solution might be to call {OnTriedReceiveEconomicReport} here but that would require some refactoring,
               // yg? including making the {OnTriedReceiveEconomicReport} method not inline.
               // yg? And now this solution would also have to accomodate peer message.
               // TODO 3 yg? Another solution would be to check {NumberUnmodifiedTowardsMoneyEntryOrders_} in {RequestCancelEntryOrdersPrematurelyIfNeeded}
               // TODO 3 yg? but the problem is that it won't attempt to send a speculative exit order.
               {
                  SleepUntilEconomicReportReceptionTimeoutExpires();

                  // Did we request to cancel entry orders?
                  // This condition doesn't tell us if report reception completed (successfully or not).
                  if( State2Code_ >= TState2Code_CancellingEntryOrders )

                  {
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_CancellingEntryOrders );

                     // Did report reception complete (successfully or not)?
                     if( State1Code_ > TState1Code_ReceivingEconomicReport )

                     {
                        return;
                     }

                     // Are we still receiving the report?
                     // Note that at this point we know that we requested to cancel entry orders.
                     else

                     {
                        bitMask1 = 1U << 7U;
                        break;
                     }
                  }
                  else
                  {
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_PreparingCancelEntryOrders );

                     // This condition is {true} as we request to cancel entry orders as soon as the report receiver returns
                     // or peer message with (or without) report related info arrives.
                     // So we need to log a message saying that economic report reception timeout expired.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ <= TState1Code_ReceivingEconomicReport );

                     bitMask1 = ( 1U << 7U ) | ( 1U << 9U );
                  }
               }
            }
            else
            {
               bitMask1 = ( 1U << 3U ) | ( 1U << 9U );
            }
         }
         else
         {
            bitMask1 = ( 1U << 1U ) | ( 1U << 9U );
         }

         State2Code_ = TState2Code_CancellingEntryOrders;

         // yg? Not checking if logged in.
         REngineAdapter_->RequestCancelAnyOrders();

         //#pragma message( "yg---?? Test." )
         //REngineAdapter_->RequestCancelOrders( EntryOrders_[ 0U ].cbegin(), EntryOrders_[ 0U ].cend() );
         //REngineAdapter_->RequestCancelOrders( EntryOrders_[ 1U ].cbegin(), EntryOrders_[ 1U ].cend() );

         //TrySendPeerMessage( IsWarmUpOrTestMode_, false );
         TrySendPeerMessage( IsWarmUpOrTestMode_, static_cast< TPeerTypesBitMask >( TPeerTypesBitMask_Important | TPeerTypesBitMask_Unimportant ) );

         // We don't have any time sensitive actions to be done before unsubscribing from market data.
         // yg? Not checking if logged in.
         REngineAdapter_->HackRequestUnsubscribeInstrumentMarketDataIfNeeded();
      }
      while( static_cast< void >( false ) , false );

      {
         // yg? Can the logging delay exit order sending? Maybe it's unlikely.
         // yg? Consider leaving the locked scope.
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

         switch( bitMask1 & ( ~ ( 1U << 9U ) ) )
         {
            case 1U << 1U :
            {
               {
                  static char const constantString1AsArray[]( "entry orders are not ready to be modified towards the money" );
            
                  // yg? Should we mark this message an "Error"?
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               break;
            }
            case 1U << 3U :
            {
               {
                  static char const constantString1AsArray[]( "{Prototype52::TStrategy::MayModifyEntryOrdersTowardsMoney} returned {false}" );
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               break;
            }
            case 1U << 7U :
            {
               {
                  static char const constantString1AsArray[]( "economic report reception timeout expired" );
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               break;
            }
            default :
            {
               YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
               break;
            }
         }

         if( ( bitMask1 & ( 1U << 9U ) ) == 0U )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            static char const constantString1AsArray[]( "requested to cancel entry orders on thread 2" );

            // Marking this message a "Warning" because we normally request to cancel entry orders after economic report reception completes
            // or peer message arrives.
            logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }
      }
   }

#endif
#if( /* {private MayModifyEntryOrdersTowardsMoney}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TStrategy::MayModifyEntryOrdersTowardsMoney() const
   {
      // TODO 3 yg? Log each protection that triggered. Write a comment that the logging does not delay any time sensitive activities.
      // TODO 3 yg? But if we call this method to re-modify entry orders we would rather postpone the logging.
      // TODO 3 yg? An alternative solution is to return a {char const *} with error description on error or {nullptr} on success and then log it
      // TODO 3 yg? but in that case we can log only 1 message. Then maybe return a bitmask.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.UpdateCounter() > 0 );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberInstrumentTradesCheapMovingAverageCalculator_.UpdateCounter() > 0 );

      // I don't want to check any protections if we are configured to send no entry orders.
      // One little problem can arise if the app that actually sends entry orders doesn't receive market data in time, and that's probably OK.
      // yg? We could at least check if {REngineAdapter_} is ready but if it's really not ready we would rather wait until report reception timeout expires
      // yg? before we attempt to make a call to {REngineAdapter_} hoping that the connection will be restored by then.
      // Note that a {YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME} before {RequestCancelEntryOrdersPrematurelyIfNeeded} is called
      // in {OnInstrumentBestAggregatedBidAskQuoteSubscriptionReceivedData} depends on this logic.
      {
         // The sizes can be 0U.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == EntryOrders_[ 1U ].size() );

         if( ! EntryOrders_[ 0U ].empty() )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            return true;
         }
      }

      if( REngineAdapter_->Ready() &&

          // It might be more reliable to verify that market data has been valid for some time. Maybe that would be unnecessary.
          // TODO 3 yg? Check only {TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllImportant} bits.
          InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask == ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_All &&

//TODO insert trade IsValid check somewhere

          // yg? In case this condition is {false}, consider using a speculative logic to assume that the other side of the spread
          // yg? is 1 point or typical distance away from the side that changed the last.
          // Assuming these values are rounded.
          InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price < InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price
        )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         return false;
      }

      {
         // Assuming quote and trade prices are rounded.
         // But their difference is not guaranteed to be such in case the operands are different.
         //double instrumentBestAggregatedBidAskQuotePricesSpread( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.PricesSpread() );
         double instrumentBestAggregatedBidAskQuotePricesSpread
            ( ::std::max( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price, InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price ) -
              ::std::min( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price, InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price )
            );
         
         if( ::Common::Math::TMathHelpers::RoundValueToMultipleOfMidpointUp( instrumentBestAggregatedBidAskQuotePricesSpread - PositionConfiguration_.PreEntryOrdersSendingProtectionConfiguration.InstrumentBestAggregatedBidAskQuotePricesSpreadMaxLimit, REngineAdapter_->Instrument().PriceIncrementMinLimit ) <= 0.0 )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            return false;
         }
      }

      {
         // Verifying that the last trade price is not too far from the bid/ask spread.
         // This is needed to make it safe to place "stop-market" orders beyond the last trade price.
         double instrumentLastTradePriceDeviation
            ( ::std::max
                 ( InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price - InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price,
                   InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price - InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price
                 )
            );

         if( ::Common::Math::TMathHelpers::RoundValueToMultipleOfMidpointUp( instrumentLastTradePriceDeviation - PositionConfiguration_.PreEntryOrdersSendingProtectionConfiguration.InstrumentLastTradePriceDeviationMaxLimit, REngineAdapter_->Instrument().PriceIncrementMinLimit ) <= 0.0 &&

             // It might be more reliable to verify that market data has been valid for some time. Maybe that would be unnecessary.
             // TODO 3 yg? Check only {TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllImportant} bits.
             InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ == ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_All &&

             // We don't need to round this.
//TODO I eliminated this.
             ::std::abs( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price - InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.InstrumentBestAggregatedBidQuotePriceCheapMovingAverage() ) <= PositionConfiguration_.PreEntryOrdersSendingProtectionConfiguration.InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit &&
             ::std::abs( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price - InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculator_.InstrumentBestAggregatedAskQuotePriceCheapMovingAverage() ) <= PositionConfiguration_.PreEntryOrdersSendingProtectionConfiguration.InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit &&

             ( NumberInstrumentTradesCheapMovingAverageCalculator_.CheapMovingAverage() >= PositionConfiguration_.PreEntryOrdersSendingProtectionConfiguration.NumberInstrumentTradesCheapMovingAverageMinLimit ||

               // yg? We really should suppress (almost?) all protections when this is {true}. Maybe suppress more protections in warm-up than in test mode.
               // yg? Although normally no protection should fail and if one does the user would want to see that.
               // yg? A better solution could be to check the protections but anyway request to modify entry orders.
//TODO maybe we should allow to increment the number of trades in the calculator even before we complete startup procedure and then we won't need to disable this protection
//TODO but the value can be too big in test mode but it's unlikely
//TODO write coments
               IsWarmUpOrTestMode_
             ) &&
             NumberInstrumentTradesCheapMovingAverageCalculator_.CheapMovingAverage() <= PositionConfiguration_.PreEntryOrdersSendingProtectionConfiguration.NumberInstrumentTradesCheapMovingAverageMaxLimit
           )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            return false;
         }
      }

      return true;
   }

#endif
#if( /* {private SafeRequestModifyEntryOrdersTowardsMoney}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::SafeRequestModifyEntryOrdersTowardsMoney()
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_PreparingModifyEntryOrdersTowardsMoney );

      // The sizes can be 0U.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == PositionConfiguration_.EntryOrdersConfiguration.size() );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == EntryOrders_[ 1U ].size() );

      State2Code_ = TState2Code_PreparingCancelEntryOrders;

      // This is the same condition as in {RunTimer1}.
//TODO think if this condition needs flipping
//TODO warm-up or test -- reorder, but think if it's efficient. actually this is now bullshit.
      if( TradingSystemWarmUpModeCode_ != TTradingSystemWarmUpModeCode_None && ModeCode_ != TPeerStrategyBaseModeCode_Test )

      {
//TODO this needs to be validated before the {if}; all possible valies need to be validated
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ModeCode_ == TPeerStrategyBaseModeCode_Normal );

         // This doesn't check on each loop if report reception completed, which is OK.
         WarmUpRequestModifyEntryOrdersTowardsMoney();

         // This stays unchanged.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberUnmodifiedTowardsMoneyEntryOrders_ == ::std::numeric_limits< int >::max() );
      }
      else

      // TODO 3 yg? In warm-up mode this block will not be executed. This issue should be addressed.
      {
         // We must round the price to ensure correct behavior of the {RequestCancelEntryOrdersPrematurelyIfNeeded} method.
         // yg? Do we need a parameter that specifies how far from the last trade price we need to place an order? For now 1 price increment is hardcoded.
         // Note that we verified that the last trade price is not too far from the bid/ask.
         double shortOrderTriggerPriceMaxLimit
            ( ::Common::Math::TMathHelpers::RoundValueToMultipleOfMidpointDown
                  ( InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price - REngineAdapter_->Instrument().PriceIncrementMinLimit,
                    REngineAdapter_->Instrument().PriceIncrementMinLimit
                  )
            );
         double longOrderTriggerPriceMinLimit
            ( ::Common::Math::TMathHelpers::RoundValueToMultipleOfMidpointUp
                  ( InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price + REngineAdapter_->Instrument().PriceIncrementMinLimit,
                    REngineAdapter_->Instrument().PriceIncrementMinLimit
                  )
            );

         ::std::vector< ::RApiFacade::TSingleInstrumentOrder * >::iterator entryOrdersIterators1[ 2U ] = { EntryOrders_[ 0U ].begin(), EntryOrders_[ 1U ].begin() };
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( RandomNumber1_ <= 1U && ( RandomNumber1_ ^ 1U ) <= 1U );
         ::std::vector< ::RApiFacade::TSingleInstrumentOrder * >::iterator & entryOrdersFirstIterator1( entryOrdersIterators1[ RandomNumber1_ ] );
         ::std::vector< ::RApiFacade::TSingleInstrumentOrder * >::iterator & entryOrdersSecondIterator1( entryOrdersIterators1[ RandomNumber1_ ^ 1U ] );
//TODO here and elsewhere, I don't really need to cache vector::cend
         ::std::vector< TEntryOrderConfiguration >::const_iterator entryOrdersConfigurationEndIterator1( PositionConfiguration_.EntryOrdersConfiguration.cend() );

         // This loop will execute 0 times if we are configured to send no entry orders.
         for( ::std::vector< TEntryOrderConfiguration >::const_iterator entryOrdersConfigurationIterator1( PositionConfiguration_.EntryOrdersConfiguration.cbegin() ) ;
                entryOrdersConfigurationIterator1 != entryOrdersConfigurationEndIterator1 ;
                ++ entryOrdersConfigurationIterator1
             )

         {
            //if( // yg? Note that {TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::CompleteRun} makes a not totally correct effort to make this work correct.
            //   // yg? Non-volatile read. Assuming we are surrounded by memory barriers.
            //   EconomicReportReceiver_->OutcomeCode() == TEconomicReportReceiverOutcomeCode_Undefined ||
            //
            //   // It's possible that we will request to modify entry orders before main thread invokes {EconomicReportReceiver_}.
            //   // Even if it's not configured to be that way it can happen due to a race outcome.
            //   // In that case the preceeding condition will likely be false, so we need this additional condition.
            //   // It would be more correct to swap these conditions but let's keep it this way for efficiency.
            //   // yg?? Bug: actually this is thread unsafe as {EconomicReportReceiver_->OutcomeCode()} is reset outside the locked scope.
            //   State1Code_ < TState1Code_ReceivingEconomicReport
            //  )

            // yg? Non-volatile read. Assuming we are surrounded by memory barriers.
            if( ! ShallAbortModifyEntryOrdersTowardsMoney_ )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // Assuming this will not overflow.
               NumberUnmodifiedTowardsMoneyEntryOrders_ = static_cast< int >( entryOrdersConfigurationEndIterator1 - entryOrdersConfigurationIterator1 );
               
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberUnmodifiedTowardsMoneyEntryOrders_ > 0 );
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( static_cast< unsigned int >( NumberUnmodifiedTowardsMoneyEntryOrders_ ) <= EntryOrders_[ 0U ].size() );

               // For performance, not logging anything here. {OnTriedReceiveEconomicReport} and/or {OnReceivedPeerMessage} will log.
               return;
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( * entryOrdersIterators1[ 0U ] )->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Short );

            //// yg? Not rounding this. The R|API will round this.
            //( * entryShortOrdersIterator1 )->TriggerPrice =
            //   ::std::min
            //      ( ::std::min
            //           ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price - entryOrdersConfigurationIterator1->TriggerPriceOffset1,
            //            InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price - entryOrdersConfigurationIterator1->TriggerPriceOffset2
            //           ),
            //        shortOrderTriggerPriceMaxLimit
            //      );

            {
               double orderTriggerPrice
                  ( ::std::min
                        ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price - entryOrdersConfigurationIterator1->TriggerPriceOffset1,
                          InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price - entryOrdersConfigurationIterator1->TriggerPriceOffset2
                        )
                  );

               // {orderTriggerPrice} is not deterministically comparable, which is not a problem.
               if( orderTriggerPrice < shortOrderTriggerPriceMaxLimit )

               {
                  ( * entryOrdersIterators1[ 0U ] )->TriggerPrice =
                      // We must round the price to ensure correct behavior of the {RequestCancelEntryOrdersPrematurelyIfNeeded} method.
                      // Rounding this down to make it further from the money.
                      ::Common::Math::TMathHelpers::RoundValueToMultipleOfMidpointDown
                          ( orderTriggerPrice, ( * entryOrdersIterators1[ 0U ] )->Instrument().PriceIncrementMinLimit );
               }
               else
               {
                  ( * entryOrdersIterators1[ 0U ] )->TriggerPrice = shortOrderTriggerPriceMaxLimit;
               }
            }

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( * entryOrdersIterators1[ 1U ] )->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Long );

            //// yg? Not rounding this. The R|API will round this.
            //( * entryLongOrdersIterator1 )->TriggerPrice =
            //   ::std::max
            //      ( ::std::max
            //           ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price + entryOrdersConfigurationIterator1->TriggerPriceOffset1,
            //            InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price + entryOrdersConfigurationIterator1->TriggerPriceOffset2
            //           ),
            //        longOrderTriggerPriceMinLimit
            //      );

            {
               double orderTriggerPrice
                  ( ::std::max
                        ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price + entryOrdersConfigurationIterator1->TriggerPriceOffset1,
                          InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price + entryOrdersConfigurationIterator1->TriggerPriceOffset2
                        )
                  );
               
               // {orderTriggerPrice} is not deterministically comparable, which is no problem.
               if( orderTriggerPrice > longOrderTriggerPriceMinLimit )

               {
                  ( * entryOrdersIterators1[ 1U ] )->TriggerPrice =
                      // We must round the price to ensure correct behavior of the {RequestCancelEntryOrdersPrematurelyIfNeeded} method.
                      // Rounding this up to make it further from the money.
                      ::Common::Math::TMathHelpers::RoundValueToMultipleOfMidpointUp
                          ( orderTriggerPrice, ( * entryOrdersIterators1[ 1U ] )->Instrument().PriceIncrementMinLimit );
               }
               else
               {
                  ( * entryOrdersIterators1[ 1U ] )->TriggerPrice = longOrderTriggerPriceMinLimit;
               }
            }

            // We validated that we are logged in and can modify entry orders.
            // We haven't left the locked scope after that.
            // yg? But this doesn't guarantee that these calls will not blow up.
            REngineAdapter_->RequestModifyOrder( * * entryOrdersFirstIterator1 );
            REngineAdapter_->RequestModifyOrder( * * entryOrdersSecondIterator1 );

            ++ entryOrdersIterators1[ 0U ];
            ++ entryOrdersIterators1[ 1U ];
         }

         NumberUnmodifiedTowardsMoneyEntryOrders_ = 0;
      }

      // We log this even if we are configured to send no entry orders.
      // We won't log this if we abort modification of some or all entry orders. In that case {OnTriedReceiveEconomicReport} and/or {OnReceivedPeerMessage}
      // will log a message.
      // yg? If economic report or peer message already arrived this logging will cause a delay. A solution would be to exit the locked scope or log this later,
      // yg? like we log that we aborted some order modifications.
      {
         static char const constantString1AsArray[]( "requested to modify entry orders towards the money" );
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      // yg? We should log: "Warning; some entry orders were placed further out of the money than configured". But that would complicate things.
   }

#endif
#if( /* {private SleepUntilEconomicReportReceptionTimeoutExpires}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::SleepUntilEconomicReportReceptionTimeoutExpires() const
   {
      // We don't pre-calculate this time.
      REngineAdapter_->SleepUntilMultimediaTimeMilliseconds( EconomicReportReleaseTimeMilliseconds_ + EconomicReportReceptionTimeoutTimeSpanMilliseconds_ );

      // Test.
      //{
      //   int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
      //   ::std::cout << "timeout 1; " << currentTimeMilliseconds << ::std::endl;
      //}
   }

#endif

#if( /* {private DoRun3}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::DoRun3()
   {
      // TODO 3 yg? To eliminate the race condition of possible start of economic report receiver before peer message receiver
      // TODO 3 yg? this code should run on main thread and economic report receiver should run on thread 3.
      // TODO 3 yg? If I do that, to reduce the chance that an {::Common::ControlFlow::TOperationCancelledException} will be thrown
      // TODO 3 yg? I would probably need to configure {EconomicReportReceptionTimeoutTimeSpanMilliseconds}
      // TODO 3 yg? to be 4997 for economic report receiver and 4999 for peer message receiver. But see a related comment in {Run}.

//TODO common first, method parameters last
//TODO only list what I need to not forget about something important; no method params, {string}, {printf}, {logger}, {DataBuffer} {typedef}s, {GetMultimediaCurrentTimeMilliseconds}.
//TODO possibly remove these from the whole class visible universe.
      // Visible universe for this method and its "sub-methods".
      //    {ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled}.
      //    {ModeCode_}.
>>>      //       Pass it to {PeerDataReceiver_.TryRun}.
      //    {REngineAdapter_->REngine()}.
      //       Lock and unlock it.
//TODO we don't touch the above directly any more, right?
      //    {REngineAdapter_->HackRequestUnsubscribeInstrumentMarketDataIfNeeded}.
      //    {TradingSystemWarmUpModeCode_}.
>>>      //       Pass it to {PeerDataReceiver_.TryRun}.
>>>      //    {PeerDataReceiver_.Result.IsWarmUpOrTestMode}.
      //    {PeerDataReceiver_.Result.StrategyState1Code}.
      //    {PeerDataReceiver_.Result.PositionExpectedDirectionCode}.
      //    {PeerDataReceiver_.TryRun}.
>>>      //    {PeerDataReceiver_.OutcomeCode}.
      //    {PositionExpectedDirectionCode_}.
      //    {ShallAbortModifyEntryOrdersTowardsMoney_}.
      //    {NumberUnmodifiedTowardsMoneyEntryOrders_}.
      //       Log it.
      //    {EconomicReportReleaseDateTimeMillisecondsSince1970_}.
>>>      //       Pass it to {PeerDataReceiver_.TryRun}.
      //    {State1Code_}.
      //    {State2Code_}.
      //    {CreateAndSendExitOrderIfNeeded}.
      //    {CreatePooledOrderIfNeeded}.
      //    {::RApiFacade::TRApiHelpers::LockREngine}.
      //    {::RApiFacade::TRApiHelpers::UnlockREngine}.
//TODO not calling the above any more, right? Now calling {REngineAdapter_->LockREngine}, {REngineAdapter_->UnlockREngine}, right?

      for( ; ; )
      {
         // We updated this right before starting thread 3. It's theoretically possible that the report will arrive before we get to this point for the 1st time.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ >= TState1Code_ReceivingEconomicReport );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ <= TState1Code_ReceivedEconomicReport );

         // We updated this right before starting thread 2. It's theoretically possible that we will cancel "any" orders before we get to this point for the 1st time.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ >= TState2Code_PreparingModifyEntryOrdersTowardsMoney );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ <= TState2Code_CancellingEntryOrders );

         // I don't want to complicate the loop breaking condition because in most cases it would not result in this loop executed fewer times and even
         // otherwise the benefit would be negligible.
         // Some ideas on how it can be complicated.
         // @ Provided we are configured to send no entry orders if it becomes known that we or another peer cancelled "any" orders break the loop.
         // @ If we already sent an exit order break the loop. This is because we currenty can send a speculative exit order only if we didn't send an exit order yet,
         //    and so we will not need to know the report.
         // @ If all entry orders complete break the loop.
         // Assuming that the untradable ranges are configured the same for all peers. So if a peer, including ourselves, received but ignored the report
         // no other peer, including ourselves, is going to take repot data into account.
         // This condition can theoretically be {false} on the 1st loop.
         if( State1Code_ < TState1Code_ReceivedButIgnoredEconomicReport )

         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }

>>>         // yg? We should call {PeerDataReceiver_.LogActivityReportIfPossible} after this but we don't. This is currently by design,
>>>         // yg? including the {TPeerDataReceiver} class design. In fact, we could call it after breaking the loop to close the socket but
>>>         // yg? that would result in some latency and little benefit as the {PeerDataReceiver_} object would anyway be destructed soon.
         TryReceivePeerMessage();

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
// TODO Maybe validate that this equals specific values.
>>>            ( PeerDataReceiver_.OutcomeCode() != TEconomicReportReceiverOutcomeCode_Undefined );
>>>         if( PeerDataReceiver_.OutcomeCode() == TEconomicReportReceiverOutcomeCode_Success )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else

>>>         // {PeerDataReceiver_} logged the error, so we don't need to.
         {
            break;
         }

>>>         if( PeerDataReceiver_.Result.IsWarmUpOrTestMode )
         {
            static char const constantString1AsArray[]( "received warm-up peer message" );
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }
         else
         {
            // Since this method is inline its call will be substituted with its code. But the code will not be executed in warm-up or test mode.
            // Assuming the code, at least the most important part of it at the beginning, and the data it uses will anyway be in RAM.
>>>            // --not any more-- Actually in warm-up or test mode (or at least in some sub-modes of those) {TPeerDataReceiver} on error now fakes success,
            // --not any more-- so this case will be warmed-up.
            // The problem with faking peer message reception success is that the strategy doesn't cancel entry orders.
            OnReceivedPeerMessage();
         }
      }

      {
         static char const constantString1AsArray[]( "broke peer message reception loop" );
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
#if( /* {private TryReceivePeerMessage}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::TryReceivePeerMessage()
   {
      REngineAdapter_->UnlockREngine();

      // Note that we can't call this well in advance as we would have to freeze the activities schedule.
      // In fact, as explained in a comment where we send peer message in {HandleEntryOrderOnReceivedData}, it's better to not call this in advance.
>>>      PeerDataReceiver_.TryRun
//TODO remove garbage
         ( //TradingSystemWarmUpModeCode_,
           //ModeCode_,
           EconomicReportReleaseDateTimeMillisecondsSince1970_,
           ModeCode_
         );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
// TODO Maybe validate that this equals specific values.
>>>         ( PeerDataReceiver_.OutcomeCode() != TEconomicReportReceiverOutcomeCode_Undefined );
>>>      if( PeerDataReceiver_.OutcomeCode() == TEconomicReportReceiverOutcomeCode_Success )
      {
>>>         if( PeerDataReceiver_.Result.IsWarmUpOrTestMode )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            // yg? Non-volatile write. Assuming we will cross a release memory barrier momentarily.
            ShallAbortModifyEntryOrdersTowardsMoney_ = true;
         }
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      REngineAdapter_->LockREngine();

      // According to the code contract, we may throw a {::Common::ControlFlow::TOperationCancelledException} only while {REngineAdapter_->REngine()} is locked.
      // It's possible that at this point the activity cancellation token is signaled.
      // yg? Non-volatile read.
      ThreadedActivityCancellationToken_->NonVolatileValidateNotSignaled();
   }

#endif
#if( /* {private OnReceivedPeerMessage}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::OnReceivedPeerMessage()
   {
//TODO common first, method parameters last
//TODO only list what I need to not forget about something important; no method params, {string}, {printf}, {logger}, {DataBuffer} {typedef}s, {GetMultimediaCurrentTimeMilliseconds}.
//TODO possibly remove these from the whole class visible universe.
      // Visible universe for this method and its "sub-methods".
      // This is a subset of what's listed in {DoRun3}.
      //    {REngineAdapter_->HackRequestUnsubscribeInstrumentMarketDataIfNeeded}.
>>>      //    {PeerDataReceiver_.Result.IsWarmUpOrTestMode}.
      //       Validate it.
>>>      //    {PeerDataReceiver_.Result.StrategyState1Code}.
>>>      //    {PeerDataReceiver_.Result.PositionExpectedDirectionCode}.
>>>      //    {PeerDataReceiver_.OutcomeCode}.
      //       Validate it.
      //    {PositionExpectedDirectionCode_}.
      //    {NumberUnmodifiedTowardsMoneyEntryOrders_}.
      //       Log it.
      //    {State1Code_}.
      //    {State2Code_}.
      //    {CreateAndSendExitOrderIfNeeded}.
      //    {CreatePooledOrderIfNeeded}.

      // If this wasn't guaranteed the {OnReceivedPeerMessage} method would need to be renamed to {OnTried...}.
//TODO the above needs to be renamed to not use "on".
>>>      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PeerDataReceiver_.OutcomeCode() == TEconomicReportReceiverOutcomeCode_Success );

>>>      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! PeerDataReceiver_.Result.IsWarmUpOrTestMode );

      // This can be almost anything.
      // But in case we are configured to send some entry orders this probably will be greather than {TState1Code_Starting}
      // and maybe even greater than or equal {TState1Code_ReceivingEconomicReport} as
      // the peers are supposed to be configured to send no entry orders and they are supposed to be launched sooner,
      // so we are not supposed to have a chance to receive peer message before all peers successfully complete the starting stage.
      // A peer can actually request to cancel "any" orders even before we send deep-out-of-the-money entry orders. Although this should
      // rarely happen, if it can happen at all, given that the peer is configured to send no entry orders.
>>>      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PeerDataReceiver_.Result.StrategyState1Code >= TState1Code_Starting );
>>>      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PeerDataReceiver_.Result.StrategyState1Code <= TState1Code_ReceivedEconomicReport );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
>>>         ( ! ( PeerDataReceiver_.Result.StrategyState1Code != TState1Code_ReceivedEconomicReport &&
>>>                PeerDataReceiver_.Result.PositionExpectedDirectionCode != 0
             )
         );
>>>      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PeerDataReceiver_.Result.PositionExpectedDirectionCode >= ( - 2 ) );
>>>      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PeerDataReceiver_.Result.PositionExpectedDirectionCode <= 2 );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ >= TState1Code_ReceivingEconomicReport );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ <= TState1Code_ReceivedEconomicReport );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ >= TState2Code_PreparingModifyEntryOrdersTowardsMoney );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ <= TState2Code_CancellingEntryOrders );

      // This condition will be valid if the untradable ranges are configured the same for all peers.
      // Even if the untradable ranges were configured differently for different peers and the logic below didn't immediatelly return
      // in case we already received economic report, regardless if we ignored it or not, the logic below might still work. Only little problem
      // would be that we would "forget" report data, that's {State1Code_} and {PositionExpectedDirectionCode_}, if the peer who sent us this peer message
      // ignored the report and as a result we would not send a speculative exit order unless we already sent one. Or, we would change
      // {PositionExpectedDirectionCode_} and possibly send a speculative exit order unless we already sent one.
>>>      // --not any more-- This expression accounts for the fact that in warm-up or test mode {TPeerDataReceiver} can fake success.
      // Asserting, not assuming.
      assert
         ( ! ( //( ! IsWarmUpOrTestMode_ ) &&
                ( ( State1Code_ == TState1Code_ReceivedEconomicReport &&
>>>                    ( PeerDataReceiver_.Result.StrategyState1Code == TState1Code_ReceivedButIgnoredEconomicReport ||
>>>                      ( PeerDataReceiver_.Result.StrategyState1Code == TState1Code_ReceivedEconomicReport &&
>>>                        PeerDataReceiver_.Result.PositionExpectedDirectionCode != PositionExpectedDirectionCode_
                      )
                    )
                  ) ||
>>>                  ( PeerDataReceiver_.Result.StrategyState1Code == TState1Code_ReceivedEconomicReport &&
                    ( State1Code_ == TState1Code_ReceivedButIgnoredEconomicReport ||
                      ( State1Code_ == TState1Code_ReceivedEconomicReport &&
>>>                        PeerDataReceiver_.Result.PositionExpectedDirectionCode != PositionExpectedDirectionCode_
                      )
                    )
                  )
                )
             )
         );

      // Did we not successfully receive economic report (no matter if we ignored it)?
      if( State1Code_ < TState1Code_ReceivedButIgnoredEconomicReport )

      {
         // This can be {TState1Code_FailedReceiveEconomicReport}.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ <= TState1Code_FailedReceiveEconomicReport );
      }
      else

      // In this case we have nothing left to do, regardless of what we received with peer message.
      {
         // This will break the peer message reception loop.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( State1Code_ == TState1Code_ReceivedButIgnoredEconomicReport ||
              State1Code_ == TState1Code_ReceivedEconomicReport
            );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_CancellingEntryOrders );

         {
            static char const constantString1AsArray[]( "received peer message but ignored it as we already received economic report" );
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            // Labeling this "Warning" to indicate that we might have not logged some related errors.
            logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         return;
      }

      bool exitSpeculativeOrderSent;

>>>      if( PeerDataReceiver_.Result.StrategyState1Code >= TState1Code_ReceivedButIgnoredEconomicReport )
      {
>>>         PositionExpectedDirectionCode_ = PeerDataReceiver_.Result.PositionExpectedDirectionCode;

         // This will break the peer message reception loop.
>>>         State1Code_ = PeerDataReceiver_.Result.StrategyState1Code;

         // yg?? See a comment where this method is called in {OnTriedReceiveEconomicReport}.
         exitSpeculativeOrderSent = CreateAndSendExitOrderIfNeeded();
      }
      else
      {
         exitSpeculativeOrderSent = false;
      }

      // We don't need to call {REngineAdapter_->RequestCancelAnyOrders} here as the peer already did so.
      // We still need to change {State2Code_}, which we will do momentarily.
      // See a comment where {REngineAdapter_->RequestCancelAnyOrders} is called in {OnTriedReceiveEconomicReport}.

      // We don't have any time sensitive actions to be done before unsubscribing from market data.
      // yg? Not checking if logged in.
      REngineAdapter_->HackRequestUnsubscribeInstrumentMarketDataIfNeeded();

      {
         // yg? Can the logging delay exit order sending? Maybe it's unlikely.
         // yg? Consider leaving the locked scope.
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

         // The order of these {case}s is optimized for performance.
>>>         switch( PeerDataReceiver_.Result.StrategyState1Code )
         {
            case TState1Code_ReceivedEconomicReport :
            {
               {
                  // It was incorrect to log this as what we really received is "economic report related peer message".
                  // But it would also be incorrect to say "economic report related peer message" as it can also indicate that economic report was ignored.
                  //static char const constantString1AsArray[]( "received economic report from a peer" );

                  static char const constantString1AsArray[]( "a peer received economic report" );
                  logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               break;
            }
            case TState1Code_FailedReceiveEconomicReport :
            {
               {
                  static char const constantString1AsArray[]( "a peer failed to receive economic report" );
                  logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               // Optimization hint.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! exitSpeculativeOrderSent );

               break;
            }
            case TState1Code_ReceivedButIgnoredEconomicReport :
            {
               {
                  static char const constantString1AsArray[]( "a peer received but ignored economic report" );
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               // Optimization hint.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! exitSpeculativeOrderSent );

               break;
            }
            default :
            {
               // This can be almost anything else, as validated at the beginning of {OnReceivedPeerMessage}.
>>>               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PeerDataReceiver_.Result.StrategyState1Code >= TState1Code_Starting );
>>>               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PeerDataReceiver_.Result.StrategyState1Code < TState1Code_FailedReceiveEconomicReport );

               {
                  //static char const constantString1AsArray[]( "a peer requested to cancel entry orders before receiving, successfully or not, economic report" );
                  static char const constantString1AsArray[]( "a peer requested to cancel entry orders before receiving economic report" );
                  logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               // Optimization hint.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! exitSpeculativeOrderSent );

               break;
            }
         }

         if( NumberUnmodifiedTowardsMoneyEntryOrders_ > 0 )
         {
            if( NumberUnmodifiedTowardsMoneyEntryOrders_ >= ::std::numeric_limits< int >::max() )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else

            // We can get here only if we are configured to send some entry orders and their modification was real (not warm-up).
            {
               // This can be logged multiple times, possibly multiple times at this point. But let's keep it simple.
               // See a comment where we log this in {OnTriedReceiveEconomicReport}.
//TODO See a "TODO" near where we log this above.
               static char const constantString1AsArray[]( "aborted requesting to modify some or all entry orders towards the money" );

               logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }
         }
         else
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberUnmodifiedTowardsMoneyEntryOrders_ == 0 );
         }

         if( exitSpeculativeOrderSent )
         {
            // We probably don't really need to validate this here because the message we are to log would anyway not need to say "successfully or not",
            // but we do so in {OnTriedReceiveEconomicReport}.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ == TState1Code_ReceivedEconomicReport );
>>>            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State1Code_ == PeerDataReceiver_.Result.StrategyState1Code );

            {
               // The "economic report related peer message" can also indicate that economic report was ignored but in that case we would not send a speculative exit order.
               // We validated 3 lines above that economic report wasn't actually ignored.
               static char const constantString1AsArray[]( "sent a speculative exit order after receiving economic report related peer message" );

               // See related comment in {OnTriedReceiveEconomicReport}.
               logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         // We received peer message before we requested to cancel entry orders?
         // This condition will be {true} also if thread 2 did not request to modify entry orders towards the money, or possibly has not even started.
         if( State2Code_ < TState2Code_CancellingEntryOrders )

         {
            // We received peer message after we requested to modify entry orders towards the money and before we requested to cancel them?
            if( State2Code_ == TState2Code_PreparingCancelEntryOrders )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }

            // We received peer message before thread 2 requested to modify entry orders towards the money?
            // In this case we don't need to "forget" all entry orders.
            else

            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ < TState2Code_PreparingCancelEntryOrders );

               {
                  // TODO 3 yg? We need a more descriptive message here.
                  static char const constantString1AsArray[]( "{Prototype52::TStrategy::State2Code_ < Prototype52::TState2Code_PreparingCancelEntryOrders}" );

                  // Marking this message "Error" as this can happen if the report arrives too soon, which in turn can happen if we are misconfigured.
                  // A non-report related peer message is not supposed to arrive too soon either.
                  logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }
            }

            //{
            //   static char const constantString1AsArray[]( "requested to cancel entry orders after receiving peer message" );
            //   logger1.information( ??? );
            //}

            // As we received peer message we know that the other peer requested to cancel "any" orders.
            State2Code_ = TState2Code_CancellingEntryOrders;
         }
         else
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_CancellingEntryOrders );

            // yg? I decided to comment this out.
            //{
            //   // yg? One might argue that it's unnecessary to log this because we already logged that we requested to cancerl entry orders
            //   // yg? and we logged above that we received peer message.
            //   // yg? Although when we receive peer message we don't log that we requested to cancel entry orders.
            //   // yg? Problem is that this warning is usually logged every time the strategy runs, either after economic report reception completes,
            //   // yg? successfully or not, or when we receive peer message. But keeping it simple.
            //   // yg? Actually we will probably rarely log this more than once as we won't get to this point when {State1Code_ >= TState1Code_ReceivedButIgnoredEconomicReport}.
            //   // TODO 3 yg? We need a more descriptive message here.
            //   static char const constantString1AsArray[]( "{Prototype52::TStrategy::State2Code_ == Prototype52::TState2Code_CancellingEntryOrders}" );
            //
            //   logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            //}
         }
      }

      //// As we received peer message we know that the other peer requested to cancel "any" orders.
      //// We don't care if it has been known for some time that we or any other peer (possibly the same one who sent us this peer message)
      //// has already requested to cancel "any" orders, which would be indicated by {State2Code_ == TState2Code_CancellingEntryOrders}.
      //State2Code_ = TState2Code_CancellingEntryOrders;

      CreatePooledOrderIfNeeded();
   }

#endif

#if( /* {(public) HandleInstrumentBestAggregatedBidAskQuoteSubscriptionOnReceivedData}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::HandleInstrumentBestAggregatedBidAskQuoteSubscriptionOnReceivedData
      ( ::RApiFacade::TInstrumentBestAggregatedBidAskQuoteSubscription * & //instrumentBestAggregatedBidAskQuoteSubscription1
      )
   {
      // yg? Assuming that callbacks will not be called after a log out.
      // yg? We should unhook events to make this assumption safer.

//TODO validate that parameter is the same as what we stored in a field
//TODO Eliminate {OnInstrumentBestAggregatedBidAskQuoteSubscriptionReceivedData}
//TODO and use {instrumentBestAggregatedBidAskQuoteSubscription1} rather than the class field.

      OnInstrumentBestAggregatedBidAskQuoteSubscriptionReceivedData();
   }

#endif
#if( /* {private OnInstrumentBestAggregatedBidAskQuoteSubscriptionReceivedData}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::OnInstrumentBestAggregatedBidAskQuoteSubscriptionReceivedData()
   {
      // yg? Consider cancelling entry orders "prematurely" before spending some time to obtain current time.
      // TODO 3 yg? {::RApiFacade::TREngineAdapter} should obtain and store this timestamp.
      int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );

      // We don't need to add bits to {InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_} before calling {RequestCancelEntryOrdersPrematurelyIfNeeded}
      // as if {InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_} is currently invalid we would not have requested to modify entry orders towards the money.
      // And when we remove any bits from {InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_} we request to cancel "any" orders.
      // In case we are configured to send no entry orders, we actually skip the "pre" protections and modify (zero) entry orders towards the money
      // but in that case {RequestCancelEntryOrdersPrematurelyIfNeeded} also ignores {InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_}.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ! ( // It might be more correct to use {PositionConfiguration_.EntryOrdersConfiguration.empty()} instead here but the result would be the same.
                // Note that when {State2Code_ == TState2Code_PreparingCancelEntryOrders} if we aborted the modification of
                // some (not all) entry orders towards the money we removed them from {EntryOrders_}.
                ( ! EntryOrders_[ 0U ].empty() ) &&

                State2Code_ == TState2Code_PreparingCancelEntryOrders &&

                // TODO 3 yg? Check only {TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllImportant} bits.
                InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ != ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_All
             )
         );

      // yg? This can log a message related to this quote before the quote itself is logged.
      RequestCancelEntryOrdersPrematurelyIfNeeded();

      // As mentioned above, it's safe to do this after calling {RequestCancelEntryOrdersPrematurelyIfNeeded}.
      // Counting even indicative quotes.
      // We don't really need to do this after we requested to cancel entry orders but it's OK.
      InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ =
         static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
            ( InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ |
              InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask
            );

      // This condition prevents multithreaded access to date-time keeper and ensures that activities schedule becomes monotonic short before the release.
      if( State1Code_ < TState1Code_FrozeActivitiesSchedule )

      {
         // Is this quote indicative or no data arrived at all?
         if( ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask &
                InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask
             ) ==
             ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_None
           )

         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            bool dateTimeKeeperUpdated
               ( DateTimeKeeper_.ProcessDateTimeTick
                    ( currentTimeMilliseconds,
                      InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.SendingDateTimeStampMillisecondsSince1970
                    )
               );

            // I could move this to the end of the method but I want to complete all calculations before the logging.
            // yg? Although logging is really a higher priority action.
            {
//TODO swap this condition? did i mean flip?
               if( ( ! dateTimeKeeperUpdated ) || ( State1Code_ < TState1Code_PreparedActivitiesSchedule ) )
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
               else
               {
                  UpdateActivitiesSchedule();
               }
            }

            // Assuming the compiler will optimize the code to evaluate this condition only once.
//TODO swap this condition? did i mean flip?
            if( ! dateTimeKeeperUpdated )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // Logging the date-time keeper before the market data which date-time-stamp was used to update the date-time keeper.
               // Otherwise we would log the market data record tagged with date-time obtained from the already updated date-time keeper.
               // yg? This creates another temporary string.
               LogDateTimeKeeper();
            }
         }
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      // TODO 3 yg? {::RApiFacade::TREngineAdapter} should log this. It should also contain the date-time keeper.
      {
         // yg? Should I phrase this better, like "aggregated bid/ask ..."? But it already says if it's bid and/or ask.
         static char const formatConstantString1AsArray[]
            ( "received instrument best quote; %s; %s; "/*"%u; "*/"%s                 ; %s; %u; %u; %+.*g; %.*g; %u; %+.*g; %.*g; %u" );
         //#pragma message( "yg---?? Test." )
         //static char const formatConstantString1AsArray[]
         //   ( "received instrument best quote; %s; %s; %u; %.*f; %s; %s; %u; %+.*g; %.*g; %+.*g; %.*g" );

         int const tempString1BufferLength( 256 );
         ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

         // We will format these as an unsigned.
         // This validation is supposed to succeed even if based on
         // {InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask}
         // these items are invalid.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.NumberOrders >= 0 );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.NumberOrders >= 0 );

         int tempString1Length
            ( ::_snprintf_l
                 ( ( & tempString1.front() ),
                   static_cast< unsigned int >( tempString1BufferLength ),
                   formatConstantString1AsArray,
                   ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,

                   // Note that we also log
                   // {InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask},
                   // so the user can see what exactly items arrived.
                   ( ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask & ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllBid ) != ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_None ) ? "bid" : "   ",
                   ( ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask & ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllAsk ) != ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_None ) ? "ask" : "   ",

                   //static_cast< unsigned int >( currentTimeMilliseconds ),
                   //#pragma message( "yg---?? Test." )
                   //5,
                   //InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.SendingDateTimeStampMillisecondsSince1970,

                   // TODO 3 yg? Pre-populate {DateTimeKeeper_} from current system date-time and use {DateTimeKeeper_}'s date-time unconditionally here.
                   // TODO 3 yg? In warm-up or test mode don't pass market data date-time to date-time keeper. Then date-time keeper will probably not need the "fast" mode.
                   // yg? Using current thread locale.
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
                   ( DateTimeKeeper_.UpdateCounter() <= 0 ) ? "??:??:??.???" : ::Poco::DateTimeFormatter::format( ::Poco::Timestamp( DateTimeKeeper_.GetDateTimeMillisecondsAsInteger< ::Poco::Int64 >( static_cast< double >( currentTimeMilliseconds ) + 0.5 ) * ::Poco::Timespan::MILLISECONDS ), ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMillisecondResolutionFormatString ).c_str(),

                   // Rounding midpoint up.
                   // yg? Consider rounding midpoint down, to keep it consistent with date-time keeper that in turn rounds the date-time it returns up.
                   // yg? But on the other hand rounding midpoint up is probably more correct taking into account that this timestamp probably was truncated rather than rounded.
                   // yg? Using current thread locale.
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
                   ::Poco::DateTimeFormatter::format( ::Poco::Timestamp( ::Common::Math::TMathHelpers::RoundNonNegativeValueToIntegerMidpointUp< double, ::Poco::Int64 >( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.SendingDateTimeStampMillisecondsSince1970 * static_cast< double >( ::Poco::Timespan::MILLISECONDS ) ) ), ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString ).c_str(),

                   InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.LastUpdatedItemsBitMask,
                   InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.ItemsValidityBitMask,
                   10,
                   InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price,
                   10,
                   InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Quantity,
                   static_cast< unsigned int >
                      ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.NumberOrders ),
                   10,
                   InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price,
                   10,
                   InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Quantity,
                   static_cast< unsigned int >
                      ( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.NumberOrders )
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
   }

#endif
#if( /* {(public) HandleInstrumentTradeSubscriptionOnReceivedData}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::HandleInstrumentTradeSubscriptionOnReceivedData
      ( ::RApiFacade::TInstrumentTradeSubscription * & //instrumentTradeSubscription1
      )
   {
      // yg? Assuming that callbacks will not be called after a log out.
      // yg? We should unhook events to make this assumption safer.

//TODO validate that parameter is the same as what we stored in a field
//TODO Eliminate {OnInstrumentTradeSubscriptionReceivedData}
//TODO and use {instrumentTradeSubscription1} rather than the class field.

      OnInstrumentTradeSubscriptionReceivedData();
   }

#endif
#if( /* {private OnInstrumentTradeSubscriptionReceivedData}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::OnInstrumentTradeSubscriptionReceivedData()
   {
      // yg? Consider cancelling entry orders "prematurely" before spending some time to obtain current time.
      // TODO 3 yg? {::RApiFacade::TREngineAdapter} should obtain and store this timestamp.
      int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );

      // We must do these before calling {RequestCancelEntryOrdersPrematurelyIfNeeded}.
      {
         // We don't really need to do this after we requested to cancel entry orders but it's OK.
         UpdateInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask();

         // yg? Note that this condition will be {false} if we cancel "any" orders before we start thread 2, usually because a request to place
         // yg? a new entry order gets rejected. Therefore it might be more correct to check for {State1Code_} but it would make no difference.
         // yg? It would be more efficient to eliminate this condition and reset the calculator or only its event counter before starting thread 2.
         if( State2Code_ <= TState2Code_None )

         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_None );
         }
         else
         {
            // It's important to not update this when {State2Code_ == TState2Code_None}.
            // It's important to update this when {State2Code_ == TState2Code_PreparingModifyEntryOrdersTowardsMoney || State2Code_ == TState2Code_PreparingCancelEntryOrders}.
            // Otherwise it doesn't matter.
            // In case we are configured to send no entry orders, we unsubscribe from market data right after requesting to modify (zero) entry orders
            // towards the money. In that case it's no longer necessary to update the calculator because we will skip the "post" protections
            // but market data would probably not arrive anyway.
            NumberInstrumentTradesCheapMovingAverageCalculator_.RegisterEvent();
         }
      }

      // yg? This can log a message related to this trade before the trade itself is logged.
      RequestCancelEntryOrdersPrematurelyIfNeeded();

      // This condition prevents multithreaded access to date-time keeper and ensures that activities schedule becomes monotonic short before the release.
      if( State1Code_ < TState1Code_FrozeActivitiesSchedule )

      {
         if( ! InstrumentTradeSubscription_->InstrumentTrade.IsValid )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            bool dateTimeKeeperUpdated
               ( DateTimeKeeper_.ProcessDateTimeTick
                    ( currentTimeMilliseconds,
                      InstrumentTradeSubscription_->InstrumentTrade.SendingDateTimeStampMillisecondsSince1970
                    )
               );

            // I could move this to the end of the method but I want to complete all calculations before the logging.
            // yg? Although logging is really a higher priority action.
            {
//TODO swap this condition? did i mean flip?
               if( ( ! dateTimeKeeperUpdated ) || ( State1Code_ < TState1Code_PreparedActivitiesSchedule ) )
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
               else
               {
                  UpdateActivitiesSchedule();
               }
            }

            // Assuming the compiler will optimize the code to evaluate this condition only once.
//TODO swap this condition? did i mean flip?
            if( ! dateTimeKeeperUpdated )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // Logging the date-time keeper before the market data which date-time-stamp was used to update the date-time keeper.
               // Otherwise we would log the market data record tagged with date-time obtained from the already updated date-time keeper.
               // yg? This creates another temporary string.
               LogDateTimeKeeper();
            }
         }
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      // TODO 3 yg? {::RApiFacade::TREngineAdapter} should log this. It should also contain the date-time keeper.
      {
         static char const formatConstantString1AsArray[]( "received instrument trade               ; "/*"%u; "*/"%s; %s; %s; %c; %+.*g; %.*g" );
         //#pragma message( "yg---?? Test." )
         //static char const formatConstantString1AsArray[]( "received instrument last trade; %u; %.*f; %s; %s; %u; %+.*g; %.*g" );
         int const tempString1BufferLength( 128 );
         ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

         int tempString1Length
            ( ::_snprintf_l
                 ( ( & tempString1.front() ),
                   static_cast< unsigned int >( tempString1BufferLength ),
                   formatConstantString1AsArray,
                   ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                   //static_cast< unsigned int >( currentTimeMilliseconds ),
                   //#pragma message( "yg---?? Test." )
                   //5,
                   //InstrumentTradeSubscription_->InstrumentTrade.SendingDateTimeStampMillisecondsSince1970,

                   // TODO 3 yg? Pre-populate {DateTimeKeeper_} from current system date-time and use {DateTimeKeeper_}'s date-time unconditionally here.
                   // TODO 3 yg? In warm-up or test mode don't pass market data date-time to date-time keeper. Then date-time keeper will probably not need the "fast" mode.
                   // yg? Using current thread locale.
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
                   ( DateTimeKeeper_.UpdateCounter() <= 0 ) ? "??:??:??.???" : ::Poco::DateTimeFormatter::format( ::Poco::Timestamp( DateTimeKeeper_.GetDateTimeMillisecondsAsInteger< ::Poco::Int64 >( static_cast< double >( currentTimeMilliseconds ) + 0.5 ) * ::Poco::Timespan::MILLISECONDS ), ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMillisecondResolutionFormatString ).c_str(),

                   // Rounding midpoint up.
                   // yg? Consider rounding midpoint down, to keep it consistent with date-time keeper that in turn rounds the date-time it returns up.
                   // yg? But on the other hand rounding midpoint up is probably more correct taking into account that this timestamp probably was truncated rather than rounded.
                   // yg? Using current thread locale.
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
                   ::Poco::DateTimeFormatter::format( ::Poco::Timestamp( ::Common::Math::TMathHelpers::RoundNonNegativeValueToIntegerMidpointUp< double, ::Poco::Int64 >( InstrumentTradeSubscription_->InstrumentTrade.GenerationDateTimeStampMillisecondsSince1970 * static_cast< double >( ::Poco::Timespan::MILLISECONDS ) ) ), ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString ).c_str(),
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
                   ::Poco::DateTimeFormatter::format( ::Poco::Timestamp( ::Common::Math::TMathHelpers::RoundNonNegativeValueToIntegerMidpointUp< double, ::Poco::Int64 >( InstrumentTradeSubscription_->InstrumentTrade.SendingDateTimeStampMillisecondsSince1970 * static_cast< double >( ::Poco::Timespan::MILLISECONDS ) ) ), ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDayMicrosecondResolutionFormatString ).c_str(),

                   //static_cast< unsigned int >( InstrumentTradeSubscription_->InstrumentTrade.IsConditional ),
                   //InstrumentTradeSubscription_->InstrumentTrade.IsConditional ? '1' : '0',
                   //static_cast< char >( InstrumentTradeSubscription_->InstrumentTrade.IsConditional + static_cast< unsigned char >( '0' ) ),
                   static_cast< char >( InstrumentTradeSubscription_->InstrumentTrade.IsValid + static_cast< unsigned char >( '0' ) ),
                   10,
                   InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price,
                   10,
                   InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Quantity
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
   }

#endif
#if( /* {private UpdateInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategy::UpdateInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask()
   {
      // Not validating any data validity bitmasks, if the bid is below the ask, or even if the prices have been populated at all.
      // Those validations will be made separately before sending orders.
      // See also: {FixInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask}.
      // TODO 3 yg? One might argue it's incorrect to update non-price related bits based on price. This might not work correct with any brokerage API.
      // --no longer relevant-- yg? We don't care if the trade is conditional.

      // Assuming these values are safe to compare without rounding.
      if( InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price >= InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price )

      {
         InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ =
            static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
               ( InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ |
                 ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllBid
               );
      }
      else
      {
         InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ =
            static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
               ( InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ &
                 ( ~ ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllBid )
               );
      }

      // Assuming these values are safe to compare without rounding.
      if( InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price <= InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price )

      {
         InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ =
            static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
               ( InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ |
                 ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllAsk
               );
      }
      else
      {
         InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ =
            static_cast< ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask >
               ( InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ &
                 ( ~ ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllAsk )
               );
      }
   }

#endif
#if( /* {private RequestCancelEntryOrdersPrematurelyIfNeeded}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::RequestCancelEntryOrdersPrematurelyIfNeeded()
   {
      // This method is not inline as it's called from multiple places.
      // TODO 3 yg? Split this method into 2 methods: one to be called on best quote and another to be called on trade.

//TODO cancel if !(bid<ask)

      do
      {
         if( State2Code_ != TState2Code_PreparingCancelEntryOrders )
         {
            return;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         // The sizes can be 0U.
         // If we aborted the modification of some (not all) entry orders towards the money we removed them from these collections.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == EntryOrders_[ 1U ].size() );

         // I don't want to check any protections if we are configured to send no entry orders.
         // One little problem can arise if the app that actually sends entry orders doesn't receive market data in time, and that's probably OK.
         // yg? We probably (almost?) never get to this point when we are configured to send no entry orders as we request to cancel market data subscriptions.
         // Note that a {YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME} before {RequestCancelEntryOrdersPrematurelyIfNeeded} is called
         // in {OnInstrumentBestAggregatedBidAskQuoteSubscriptionReceivedData} depends on this logic.
         {
            if( ! EntryOrders_[ 0U ].empty() )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               return;
            }
         }

         // TODO 3 yg? Check only {TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllImportant} bits.
         if( InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ == ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_All )

         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }

//TODO check trade IsValid

//TODO remove
         //if( NumberInstrumentTradesCheapMovingAverageCalculator_.EventSinceLastUpdateCounter() <= PositionConfiguration_.PostEntryOrdersSendingProtectionConfiguration.NumberInstrumentTradesMaxLimit )
         //{
         //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         //}
         //else
         //{
         //   break;
         //}

         // This will work even if we requested to only warm-up-modify entry orders. In that case it's very unlikely that this protection will trigger.
         // Enumerating the orders backwards because closer to the money orders are usually at the end.
         // Running a single loop for both long and short orders to have more assembly instructions executed simultaneously.
         {
            // The sizes can't be 0U as we would have returned above.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! EntryOrders_[ 0U ].empty() );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EntryOrders_[ 0U ].size() == EntryOrders_[ 1U ].size() );

            ::std::vector< ::RApiFacade::TSingleInstrumentOrder * >::const_iterator entryOrdersIterators1[ 2U ] = { EntryOrders_[ 0U ].cend(), EntryOrders_[ 1U ].cend() };
//TODO instead of this loop, store min/max trigger price of orders and just compare those with market data
            do
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( entryOrdersIterators1[ 0U ] != EntryOrders_[ 0U ].cbegin() );
               -- entryOrdersIterators1[ 0U ];
               -- entryOrdersIterators1[ 1U ];
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( * entryOrdersIterators1[ 0U ] )->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Short );
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( * entryOrdersIterators1[ 1U ] )->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Long );

               // Assuming these values are rounded.
               {
                  if( InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price > ( * entryOrdersIterators1[ 0U ] )->TriggerPrice )
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     goto label2;
                  }
                  if( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Ask.Price > ( * entryOrdersIterators1[ 0U ] )->TriggerPrice )
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     goto label2;
                  }
                  if( InstrumentTradeSubscription_->InstrumentTrade.QuantityAndPrice.Price < ( * entryOrdersIterators1[ 1U ] )->TriggerPrice )
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     goto label2;
                  }
                  if( InstrumentBestAggregatedBidAskQuoteSubscription_->InstrumentBestAggregatedBidAskQuote.Bid.Price < ( * entryOrdersIterators1[ 1U ] )->TriggerPrice )
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     goto label2;
                  }
               }
            }
            while( entryOrdersIterators1[ 0U ] != EntryOrders_[ 0U ].cbegin() );
         }

         return;
      }
      while( static_cast< void >( false ) , false );

   label2:
//TODO Here and elsewhere, do this after requesting to cancel orders.
      State2Code_ = TState2Code_CancellingEntryOrders;

      // yg? Not checking if logged in.
      REngineAdapter_->RequestCancelAnyOrders();

      //TrySendPeerMessage( IsWarmUpOrTestMode_, false );
      TrySendPeerMessage( IsWarmUpOrTestMode_, static_cast< TPeerTypesBitMask >( TPeerTypesBitMask_Important | TPeerTypesBitMask_Unimportant ) );

      // We don't have any time sensitive actions to be done before unsubscribing from market data.
      // yg? Not checking if logged in.
      REngineAdapter_->HackRequestUnsubscribeInstrumentMarketDataIfNeeded();

      {
         static char const constantString1AsArray[]( "requested to cancel entry orders prematurely" );
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
#if( /* {private LogDateTimeKeeper}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::LogDateTimeKeeper() const
   {
      // This method is not inline as it's called from multiple places.
      // TODO 3 yg? Log current date-time to give log parsers an idea.

      int const tempString1BufferLength( 128 );
      ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
      static char const formatConstantString1AsArray[]( "date-time keeper; %I64u; %+.*f; %+.*f" );

      // We only need this to be non-negative to log it as an unsigned but we know that at this point it's positive, so let's validate that.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DateTimeKeeper_.UpdateCounter() > 0 );

      int tempString1Length
         ( ::_snprintf_l
              ( ( & tempString1.front() ),
                static_cast< unsigned int >( tempString1BufferLength ),
                formatConstantString1AsArray,
                ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                static_cast< ::Poco::UInt64 >( DateTimeKeeper_.UpdateCounter() ),
                24,
                DateTimeKeeper_.TimerTickIntervalMillisecondsDeviation(),
                24,
                DateTimeKeeper_.TimerTickIntervalMillisecondsSafeDeviation()
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

#endif

#if( /* {(public) HandleEntryOrderOnReceivedData}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::HandleEntryOrderOnReceivedData
      ( ::RApiFacade::TSingleInstrumentOrder * & entryOrder1
      )
   {
      // yg? Assuming that callbacks will not be called after a log out.
      // yg? We should unhook events to make this assumption safer.
      // This method will never be called if we are configured to send no entry orders.
      // It's theoretically possoble that an out of the money order will get filled or complete in any other way long before the release --
      // we will close the position with no problem.
      // TODO 3 yg? Split this code into multiple methods. This is partially done.

   #if( ! defined( NDEBUG ) )
      {
         ::std::vector< ::RApiFacade::TSingleInstrumentOrder * > & entryOrders1( EntryOrders_[ static_cast< unsigned int >( entryOrder1->DirectionCode + 1 ) / 2U ] );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ::std::find( entryOrders1.cbegin(), entryOrders1.cend(), entryOrder1 ) != entryOrders1.cend() );
      }
   #endif

      // 1U indicates that we requested to cancel "any" orders.
      // 2U indicates that we removed/forgot {entryOrder1}.
      unsigned int bitMask1;

      // This condition will become {false} if a deep out-of-the-money entry order gets rejected or filled,
//TODO 0 actually a fill no longer sets the {::RApiFacade::TOrderStateBitMask_TriggeredByExchange} bit but it probably doesn't matter.
      // the user cancels a deep out-of-the-money entry order, a deep out-of-the-money entry order warm-up modification fails,
      // among other more usual cases.
//TODO 0 verify/refactor this code -- done
      if( ( entryOrder1->StateBitMask &
             ( // An order whose modification failed is very likely deep out of the money, so we can safely "forget" it. It will be cancelled along with the other orders.
               ::RApiFacade::TOrderStateBitMask_LastModificationRequestRejected |
      
               ::RApiFacade::TOrderStateBitMask_TriggeredByExchange |
               ::RApiFacade::TOrderStateBitMask_ProbablyCompleted
             )
           ) ==
           ::RApiFacade::TOrderStateBitMask_None
        )

      {
         bitMask1 = 0U;
      }
      else
      {
         if( State2Code_ < TState2Code_CancellingEntryOrders )
         {
            State2Code_ = TState2Code_CancellingEntryOrders;

            // In Prototype5, there was a lame logic described in the following lamely written comment:
            //    If all entry orders were initially accepted and then short before or after we are to request to modify them towards the money
            //    an order spontaneously completes without a fill we will assume that another instance of our application cancelled "any" orders,
            //    so we can improve performance by not sending another "any" order cancel request.
            //    But it's possible that a modification request gets rejected because a cancellation request is in progress.
            //    We are currently not designed to detect such a case and will send a cancel request.
            //    However in that case we will have a chance to notice the {::RApi::sLINE_STATUS_CANCEL_RECEIVED} notification above.
            // The peers are now talking to each other, so the above described issue is probably not too bad.
//TODO We now notice {::RApi::sLINE_STATUS_CANCEL_RECEIVED} -- revisit.
//TODO As we now know when any cancellation request is pending, maybe update state as if we requested to cancel entry/"any" orders but don't actually request to cancel.
//TODO maybe check if one of the following bits is 1: TOrderStateBitMask_ShallBeCancelled, TOrderStateBitMask_CancellationRequestPending, TOrderStateBitMask_LastCancellationRequestPending, maybe even TOrderStateBitMask_LastCancellationRequestRejected but it's redundant

            // yg? It would probably make little sense or offer little benefit to call {CreateAndSendExitOrderIfNeeded}
            // yg? before requesting to cancel "any" orders.
            // yg? If economic report already arrived we already requested to cancel "any" orders, so we won't get to this point.
            // yg? If economic report did not arrive yet we can send only an unspeculative exit order,
            // yg? which won't happen after the 1st entry order gets filled or completes unfilled.
            // As we send at least 2 entry orders, it's guaranteed that at least 1 entry order is believed to be not completed yet,
            // therefore we send a cancellation request without checking that any entry orders not yet completed.
            // After this we need to unsubscribe from market data, which we will do after performance critical actions.
            REngineAdapter_->RequestCancelAnyOrders();

            bitMask1 = 1U | 2U;
         }
         else
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( State2Code_ == TState2Code_CancellingEntryOrders );
            bitMask1 = 2U;
         }

//TODO 0 verify/refactor this code -- done
         if( ( entryOrder1->StateBitMask & ::RApiFacade::TOrderStateBitMask_TriggeredByExchange ) ==
             ::RApiFacade::TOrderStateBitMask_None
           )
         {
//TODO 0 verify/refactor this code -- done
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( ( entryOrder1->StateBitMask &
                   ( ::RApiFacade::TOrderStateBitMask_LastModificationRequestRejected |
                     ::RApiFacade::TOrderStateBitMask_ProbablyCompleted
                   )
                 ) !=
                 ::RApiFacade::TOrderStateBitMask_None
               );

            // Note that, as mentioned a few lines below, we set
            // the {::RApiFacade::TOrderStateBitMask_TriggeredByExchange} bit when a fill occurs.
//TODO 0 not any more but it probably doesn't matter
            // Assuming this is rounded.
//TODO maybe only assert this, also elsewhere
//TODO When I sent entry orders as market to test {...::NotCancelledReport} (which didn't work) this validation failed. This probably should be an {assert} after all.
            //#pragma message( "yg---?? Test." )
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( entryOrder1->FilledQuantityAndPrice.Quantity == 0.0 );
         }
         else
         {
            // yg? Assuming an order that was triggered was filled or will be filled.
            // Note that, as mentioned a few lines above, we set
            // the {::RApiFacade::TOrderStateBitMask_TriggeredByExchange} bit when a fill occurs.
//TODO 0 not any more but it probably doesn't matter
            {
               // Perhaps we should log an error when entry orders in both directions get filled but there is no need to bother.
               // This is used by {CreateAndSendExitOrderIfNeeded}.
               EntryLastFilledOrderDirectionCode_ = entryOrder1->DirectionCode;

               // This is used by {CreateAndSendExitOrderIfNeeded}.
               SignedNumberEntryFilledOrders_ += entryOrder1->DirectionCode;
            }
         }

//TODO move this validation under the block that follows?
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( entryOrder1->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Long ||
              entryOrder1->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Short
            );

         {
            ::std::vector< ::RApiFacade::TSingleInstrumentOrder * > & entryOrders1( EntryOrders_[ static_cast< unsigned int >( entryOrder1->DirectionCode + 1 ) / 2U ] );

            // This removal ensures correct behavior of the {CreateAndSendExitOrderIfNeeded} method,
            // so we must do it before calling that method.
            // We still need to unhook this order, which we will do after performance critical actions.
            // It would be better to do binary search here but the benefit would be negligible.
            // We validated above that this find will succeed.
            entryOrders1.erase( ::std::find( entryOrders1.begin(), entryOrders1.end(), entryOrder1 ) );
         }

         //// Test.
         //PositionExpectedDirectionCode_ =
         //   ( ( ::Common::Math::TMultiplyWithCarryRandomNumberCommonGeneratorHelpers::MultiplyWithCarryRandomNumberCommonGenerator.GenerateLowQuality1BitRaw() & 1U ) == 0U ) ? ( - 1 ) : 1;
      }

      // We must call {CreateAndSendExitOrderIfNeeded} unconditionally rather than only after we remove an entry order
      // because under some conditions it can send a speculative exit order after a successful entry order modification.
      // After this we might need to create a pooled order, which we will do after performance critical actions.
      bool exitSpeculativeOrderSent( CreateAndSendExitOrderIfNeeded() );

      if( ( bitMask1 & 1U ) == 0U )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         // It's possible that we will send this peer message before peers invoke peer message receiver.
         // It's more likely to happen in case we are configured to send some entry orders if a deep out-of-the-money entry order
         // gets rejected. In that case the other peers will be unaware that "any" orders have already been cancelled
         // and will eventually request to cancel "any" orders, which is no big deal.
         // The user will still have the possibility to restart the peer configured to send some entry orders and everything would work.
         // In case we are configured to send no entry orders it's probably impossible that we can send peer message long before
         // economic report release.
         //TrySendPeerMessage( IsWarmUpOrTestMode_, false );
         TrySendPeerMessage( IsWarmUpOrTestMode_, static_cast< TPeerTypesBitMask >( TPeerTypesBitMask_Important | TPeerTypesBitMask_Unimportant ) );

         // We don't have any time sensitive actions to be done before unsubscribing from market data.
         // At the same time, we do this before any less time critical actions, such as logging or pooled order creation.
         // yg? Not checking if logged in.
         REngineAdapter_->HackRequestUnsubscribeInstrumentMarketDataIfNeeded();

         {
            static char const constantString1AsArray[]( "entry order state change event handler requested to cancel entry orders" );
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            // Marking this message "Warning" as any cancellation before economic report arrives is undesirable.
            // This message should be marked "Error" if we didn't request to modify entry orders towards the money yet, but keeping it simple.
            logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }
      }

      if( ! exitSpeculativeOrderSent )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         static char const constantString1AsArray[]( "entry order state change event handler sent a speculative exit order" );
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

         // This should be marked "Warning" if economic report is already known to be tradable but a speculative exit order could not be sent sooner
         // because some entry order modification requests were still pending.
         // At the same time, if the report is only weakly tradable we can send a speculative exit order only after an entry order gets triggered.
         // So let's keep it free of convoluted judgement.
         logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      // Remaining actions are less time critical than the logging.

      if( ( bitMask1 & 2U ) == 0U )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         // We will not receive any execution restatements.
         // We are the only event listener, so unhooking in the most efficient way.
         // yg? There appears to be no way to validate that we are the only event listener.
         entryOrder1->OnReceivedData.clear();
      }

      CreatePooledOrderIfNeeded();
   }

#endif
#if( /* //{(public) HandleExitOrderOnReceivedData}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //void TStrategy::HandleExitOrderOnReceivedData
   //   ( ::RApiFacade::TSingleInstrumentOrder * & exitOrder1
   //   )
   //{
   //}

#endif
#if( /* {private CreateAndSendExitOrderIfNeeded}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   bool TStrategy::CreateAndSendExitOrderIfNeeded()
   {
      // This method is not inline as it's called from multiple places.
      // yg? It might be possible to optimize this logic by combining the unspeculative and speculative logic.

      // The following fields are used in the logic that decides if an exit order needs to be sent.
      //    {PositionConfiguration_.EntryOrdersConfiguration.size}.
      //    {PositionExpectedDirectionCode_}.
      //    {EntryOrders_[].size}.
      //    {EntryOrders_[][].StateBitMask}.
      //    {NumberUnmodifiedTowardsMoneyEntryOrders_}.
      //    {EntryLastFilledOrderDirectionCode_}.
      //    {SignedNumberEntryFilledOrders_}.
      //       We also update this.
      //    {ExitOrderSent_}.
      //       We also update this.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PooledOrder_ != nullptr );

      // yg? This doesn't specify if we used the more or less speculative logic.
      bool exitSpeculativeOrderSent;

      // Unspeculative exit order logic.
      {
         // We don't care if we sent requests to modify entry orders towards the money or whether the requests have completed.
         // This will work correct even if we are configured to send no entry orders.
         // yg? If any orders in this direction have already been filled the modification of the rest probably failed.
         // yg? But I probably don't want to base any speculative logic on this.
         // Assuming this will not overflow.
         int exitPressure( static_cast< int >( EntryOrders_[ 0U ].size() ) - SignedNumberEntryFilledOrders_ );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( exitPressure >= ( - 1 ) );
         if( exitPressure >= 0 )
         {
            // yg? Same comment as above applies.
            exitPressure = static_cast< int >( EntryOrders_[ 1U ].size() ) + SignedNumberEntryFilledOrders_;

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( exitPressure >= ( - 1 ) );
            if( exitPressure >= 0 )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SignedNumberEntryFilledOrders_ < 0 );
               exitSpeculativeOrderSent = false;
               goto label12;
            }
         }
         else
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SignedNumberEntryFilledOrders_ > 0 );
            exitSpeculativeOrderSent = false;
            goto label22;
         }
      }

      if( ! ExitOrderSent_ )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         return false;
      }

      // This logic can speculatively send an exit order before it's known that no fill in the opposite direction can occur.
      // It's intended to work correct only if no exit orders were sent yet.
      // TODO 3 yg? Allow to send a speculative exit order even if some non-speculative ones were already sent. This might require little modification but would it really help us to make more money?
      // It (hopefully) doesn't break any {YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME}s.
      // If this order over-closes the position the situation will eventually be corrected by sending an order in the opposite direction.
      // We can send a speculative exit order only after we received and not ignored the report.
      // yg? Entry orders trigger price is forced to be above and below the last trade price. This implies that a trade can't trigger
      // yg? both long and short entry orders. Otherwise some speculative exit order logic would probably need to be revisited.
      {
         switch( EntryLastFilledOrderDirectionCode_ )
         {
            case ::Finance::Trading::TPositionDirectionCode_None :
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SignedNumberEntryFilledOrders_ == 0 );

               // Checking if we did not request to modify at least 1 entry order pair towards the money.
               // This will work correct even if we are configured to send no entry orders.
               if( NumberUnmodifiedTowardsMoneyEntryOrders_ >= static_cast< int >( PositionConfiguration_.EntryOrdersConfiguration.size() ) )

               {
                  // This will work correct even if we are configured to send no entry orders.
                  // Assuming this will not overflow.
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                     ( NumberUnmodifiedTowardsMoneyEntryOrders_ == ::std::numeric_limits< int >::max() ||
                       static_cast< unsigned int >( NumberUnmodifiedTowardsMoneyEntryOrders_ ) == PositionConfiguration_.EntryOrdersConfiguration.size()
                     );

                  return false;
               }
               else

               // We can get to this point only if we are configured to send some entry orders.
               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberUnmodifiedTowardsMoneyEntryOrders_ >= 0 );
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( static_cast< unsigned int >( NumberUnmodifiedTowardsMoneyEntryOrders_ ) < PositionConfiguration_.EntryOrdersConfiguration.size() );

                  // We don't need to check here that {State1Code_ == TState1Code_ReceivedEconomicReport}.
                  if( PositionExpectedDirectionCode_ < ( - 1 ) )

                  {
                     {
                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ == ( - 2 ) );

                        // Is there at least 1 successfully modified entry order in the expected direction?
//TODO Further comments say "successfully modified towards the money"? Should the preceeding one say the same?
                        // Assuming it will get filled.
                        // We don't care about the order state flags that result in the {HandleEntryOrderOnReceivedData} method "forgetting" the order.
                        if( ::RApiFacade::TSingleInstrumentOrderHelpers::OrderStateBitMaskExists
                                 ( EntryOrders_[ 0U ].cbegin(),
                                   EntryOrders_[ 0U ].cend(),
                                   static_cast< ::RApiFacade::TOrderStateBitMask >
                                       ( ~ ( ::RApiFacade::TOrderStateBitMask_LastCancellationRequestPending |
                                               ::RApiFacade::TOrderStateBitMask_LastCancellationRequestRejected |

//TODO 0 I added these 2 bits -- revisit, at least reorder the bits
                                               ::RApiFacade::TOrderStateBitMask_ShallBeCancelled |
                                               ::RApiFacade::TOrderStateBitMask_CancellationRequestPending
                                             )
                                       ),
                                   ::RApiFacade::TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                 )
                          )

                        {
                           goto label11;
                        }
                        else
                        {
                           return false;
                        }
                     }
                  }
                  else
                  {
                     // We don't need to check here that {State1Code_ == TState1Code_ReceivedEconomicReport}.
                     if( PositionExpectedDirectionCode_ > 1 )

                     {
                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ == 2 );

                        // Is there at least 1 successfully modified entry order in the expected direction?
//TODO Further comments say "successfully modified towards the money"? Should the preceeding one say the same?
                        // Assuming it will get filled.
                        // We don't care about the order state flags that result in the {HandleEntryOrderOnReceivedData} method "forgetting" the order.
                        if( ::RApiFacade::TSingleInstrumentOrderHelpers::OrderStateBitMaskExists
                                 ( EntryOrders_[ 1U ].cbegin(),
                                   EntryOrders_[ 1U ].cend(),
                                   static_cast< ::RApiFacade::TOrderStateBitMask >
                                       ( ~ ( ::RApiFacade::TOrderStateBitMask_LastCancellationRequestPending |
                                               ::RApiFacade::TOrderStateBitMask_LastCancellationRequestRejected |

//TODO 0 I added these 2 bits -- revisit, at least reorder the bits
                                               ::RApiFacade::TOrderStateBitMask_ShallBeCancelled |
                                               ::RApiFacade::TOrderStateBitMask_CancellationRequestPending
                                             )
                                       ),
                                   ::RApiFacade::TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                 )
                          )

                        {
                           goto label21;
                        }
                        else
                        {
                           return false;
                        }
                     }
                     else
                     {
                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ >= ( - 1 ) );
                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ <= 1 );
                        return false;
                     }
                  }
               }

               // warning C4702: unreachable code
               //YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();

               break;
            }

            case ::Finance::Trading::TPositionDirectionCode_Short :

            // We can get to this point only if we are configured to send some entry orders.
            // It's not guaranteed that we requested to modify any towards the money.
            {
               // We don't need to check here that {State1Code_ == TState1Code_ReceivedEconomicReport}.
               if( PositionExpectedDirectionCode_ < 0 )

               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ == ( - 1 ) || PositionExpectedDirectionCode_ == ( - 2 ) );
                  if( SignedNumberEntryFilledOrders_ < 0 )
                  {
                     // No need to check {NumberUnmodifiedTowardsMoneyEntryOrders_}.
                     // If at least 1 unmodified towards the money entry order gets filled while the report is already known to be tradable we will use the same logic.
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SignedNumberEntryFilledOrders_ >= 0 );

                     // We will use this expression below.
                     // This acts as an optimization hint for {::RApiFacade::TSingleInstrumentOrderHelpers::OrdersStateBitMaskExist}.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( 1 + SignedNumberEntryFilledOrders_ > 0 );

                     // Ckecking if we requested to modify at least 1 entry order pair towards the money.
                     if( NumberUnmodifiedTowardsMoneyEntryOrders_ < static_cast< int >( PositionConfiguration_.EntryOrdersConfiguration.size() ) )

                     {
                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberUnmodifiedTowardsMoneyEntryOrders_ >= 0 );

                        // Are there at least {1 + SignedNumberEntryFilledOrders_} successfully modified towards the money entry orders in the expected direction?
                        // Assuming they will get filled.
                        // We don't care about the order state flags that result in the {HandleEntryOrderOnReceivedData} method "forgetting" the order.
                        if( ::RApiFacade::TSingleInstrumentOrderHelpers::OrdersStateBitMaskExist
                                 ( EntryOrders_[ 0U ].cbegin(),
                                   EntryOrders_[ 0U ].cend(),
                                   static_cast< ::RApiFacade::TOrderStateBitMask >
                                       ( ~ ( ::RApiFacade::TOrderStateBitMask_LastCancellationRequestPending |
                                               ::RApiFacade::TOrderStateBitMask_LastCancellationRequestRejected |

//TODO 0 I added these 2 bits -- revisit, at least reorder the bits
                                               ::RApiFacade::TOrderStateBitMask_ShallBeCancelled |
                                               ::RApiFacade::TOrderStateBitMask_CancellationRequestPending
                                             )
                                       ),
                                   ::RApiFacade::TOrderStateBitMask_NewOrderRequestReceivedByBroker,
                                   1 + SignedNumberEntryFilledOrders_
                                 )
                          )

                        {
                           ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                        }
                        else
                        {
                           return false;
                        }
                     }
                     else

                     // It's probably realistically impossible to get here.
                     // We can get here if market price quickly whipsaws from one deep-out-of-the-money price to another.
                     {
                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                           ( NumberUnmodifiedTowardsMoneyEntryOrders_ == ::std::numeric_limits< int >::max() ||
                             static_cast< unsigned int >( NumberUnmodifiedTowardsMoneyEntryOrders_ ) == PositionConfiguration_.EntryOrdersConfiguration.size()
                           );
                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                        return false;
                     }
                  }
               }
               else
               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ >= 0 );
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ <= 2 );
                  return false;
               }

            label11:
               exitSpeculativeOrderSent = true;
            label12:
               PooledOrder_->DirectionCode = ::Finance::Trading::TPositionDirectionCode_Long;
               break;
            }

            case ::Finance::Trading::TPositionDirectionCode_Long :

            // We can get to this point only if we are configured to send some entry orders.
            // It's not guaranteed that we requested to modify any towards the money.
            {
               // We don't need to check here that {State1Code_ == TState1Code_ReceivedEconomicReport}.
               if( PositionExpectedDirectionCode_ > 0 )

               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ == 1 || PositionExpectedDirectionCode_ == 2 );
                  if( SignedNumberEntryFilledOrders_ > 0 )
                  {
                     // No need to check {NumberUnmodifiedTowardsMoneyEntryOrders_}.
                     // If at least 1 unmodified towards the money entry order gets filled while the report is already known to be tradable we will use the same logic.
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SignedNumberEntryFilledOrders_ <= 0 );

                     // We will use this expression below.
                     // This acts as an optimization hint for {::RApiFacade::TSingleInstrumentOrderHelpers::OrdersStateBitMaskExist}.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( 1 - SignedNumberEntryFilledOrders_ > 0 );

                     // Ckecking if we requested to modify at least 1 entry order pair towards the money.
                     if( NumberUnmodifiedTowardsMoneyEntryOrders_ < static_cast< int >( PositionConfiguration_.EntryOrdersConfiguration.size() ) )

                     {
                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberUnmodifiedTowardsMoneyEntryOrders_ >= 0 );

                        // Are there at least {1 - SignedNumberEntryFilledOrders_} successfully modified towards the money entry orders in the expected direction?
                        // Assuming they will get filled.
                        // We don't care about the order state flags that result in the {HandleEntryOrderOnReceivedData} method "forgetting" the order.
                        if( ::RApiFacade::TSingleInstrumentOrderHelpers::OrdersStateBitMaskExist
                                 ( EntryOrders_[ 1U ].cbegin(),
                                   EntryOrders_[ 1U ].cend(),
                                   static_cast< ::RApiFacade::TOrderStateBitMask >
                                       ( ~ ( ::RApiFacade::TOrderStateBitMask_LastCancellationRequestPending |
                                               ::RApiFacade::TOrderStateBitMask_LastCancellationRequestRejected |

//TODO 0 I added these 2 bits -- revisit, at least reorder the bits
                                               ::RApiFacade::TOrderStateBitMask_ShallBeCancelled |
                                               ::RApiFacade::TOrderStateBitMask_CancellationRequestPending
                                             )
                                       ),
                                   ::RApiFacade::TOrderStateBitMask_NewOrderRequestReceivedByBroker,
                                   1 - SignedNumberEntryFilledOrders_
                                 )
                          )

                        {
                           ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                        }
                        else
                        {
                           return false;
                        }
                     }
                     else

                     // It's probably realistically impossible to get here.
                     // We can get here if market price quickly whipsaws from one deep-out-of-the-money price to another.
                     {
                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                           ( NumberUnmodifiedTowardsMoneyEntryOrders_ == ::std::numeric_limits< int >::max() ||
                             static_cast< unsigned int >( NumberUnmodifiedTowardsMoneyEntryOrders_ ) == PositionConfiguration_.EntryOrdersConfiguration.size()
                           );
                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                        return false;
                     }
                  }
               }
               else
               {
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ >= ( - 2 ) );
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PositionExpectedDirectionCode_ <= 0 );
                  return false;
               }

            label21:
               exitSpeculativeOrderSent = true;
            label22:
               PooledOrder_->DirectionCode = ::Finance::Trading::TPositionDirectionCode_Short;
               break;
            }

            default :
            {
               YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
               break;
            }
         }
      }

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PooledOrder_->TypeCode == ::RApiFacade::TOrderTypeCode_Market );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( PooledOrder_->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Short ||
           PooledOrder_->DirectionCode == ::Finance::Trading::TPositionDirectionCode_Long
         );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( PooledOrder_->Quantity == PooledOrder_->Instrument().QuantityIncrementMinLimit );
      // {PooledOrder_->TriggerPrice} remains undefined.

      // yg? Not checking if logged in.
      REngineAdapter_->SendOrder( * PooledOrder_ );

      SignedNumberEntryFilledOrders_ += PooledOrder_->DirectionCode;
      PooledOrder_ = nullptr;
      ExitOrderSent_ = true;
      //CreatePooledOrder();
      return exitSpeculativeOrderSent;
   }

#endif
#if( /* {private CreatePooledOrderIfNeeded}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategy::CreatePooledOrderIfNeeded()
   {
      // This method is not inline as it's called from multiple places.

      if( PooledOrder_ == nullptr )
      {
         CreatePooledOrder();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
   }

#endif
}

#endif
