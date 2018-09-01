#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPrimaryPeerStrategy.hpp"

#include "./TNumberEventsCheapMovingAverageCalculator.cpp"
#include "./TPeerStrategyBase.cpp"
#include "./TPrimaryPeerStrategyConfiguration.cpp"

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

   TPrimaryPeerStrategy::TPrimaryPeerStrategy
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
      ) :
      TPeerStrategyBase( threadedActivityCancellationToken1 )
      //PooledOrder_( ??? ),
   {
      // See visible universe in {DoInitialize}.
   }

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPrimaryPeerStrategy::TPrimaryPeerStrategy
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
        TPrimaryPeerStrategyConfiguration && configuration1
      ) :
      TPeerStrategyBase( threadedActivityCancellationToken1, ::std::move( configuration1 ) ),
      PositionConfiguration_( ::std::move( configuration1.PositionConfiguration ) ),
      NumberInstrumentTradesCheapMovingAverageCalculator_
         ( ::std::move( configuration1.NumberInstrumentTradesCheapMovingAverageCalculatorConfiguration ) ),
      //PooledOrder_( ??? ),
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

   void TPrimaryPeerStrategy::Initialize
      ( TPrimaryPeerStrategyConfiguration && configuration1
      )
   {
      // See visible universe in {DoInitialize}.

      TPeerStrategyBase::Initialize( ::std::move( configuration1 ) );

      PositionConfiguration_.Assign( ::std::move( configuration1.PositionConfiguration ) );
      NumberInstrumentTradesCheapMovingAverageCalculator_.Initialize( ::std::move( configuration1.NumberInstrumentTradesCheapMovingAverageCalculatorConfiguration ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPrimaryPeerStrategy::DoInitialize
      ( TPrimaryPeerStrategyConfiguration && //configuration1
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

      Timer1TickIntervalMilliseconds_ = ::std::move( configuration1.Timer1TickIntervalMilliseconds );
      DataLoggingIntervalTimer1Ticks_ = ::std::move( configuration1.DataLoggingIntervalTimer1Ticks );
      NumberDataLastLoggingsOnTimer1TickToForce_ = ::std::move( configuration1.NumberDataLastLoggingsOnTimer1TickToForce );

      // The rounding formula assumes that {configuration1.EntryOrdersModificationWarmUp2TimeOffsetMilliseconds} is negative.
      // It would be nice to log a warning if the resulting value is different from the configured one.
      // Assuming this will not overflow.
//TODO this is now 1 variable.
      EntryOrdersModificationWarmUp2TimeOffsetTimer1Ticks_ =
         ::std::min( ( configuration1.EntryOrdersModificationWarmUp2TimeOffsetMilliseconds - Timer1TickIntervalMilliseconds_ / 2 ) / Timer1TickIntervalMilliseconds_, ( - 1 ) );

      // The rounding formula assumes that {configuration1.EntryOrdersModificationWarmUp1TimeOffsetMilliseconds} is negative.
      // It would be nice to log a warning if the resulting value is different from the configured one.
      // Assuming this will not overflow.
//TODO this is now 1 variable.
      EntryOrdersModificationWarmUp1TimeOffsetTimer1Ticks_ =
         ::std::min( ( configuration1.EntryOrdersModificationWarmUp1TimeOffsetMilliseconds - Timer1TickIntervalMilliseconds_ / 2 ) / Timer1TickIntervalMilliseconds_, EntryOrdersModificationWarmUp2TimeOffsetTimer1Ticks_ - 1 );

      EconomicReportReceptionTimeoutTimeSpanMilliseconds_ = ::std::move( configuration1.EconomicReportReceptionTimeoutTimeSpanMilliseconds );

      InstrumentDeepOutOfMoneyPriceFactor1_ = ::std::move( configuration1.InstrumentDeepOutOfMoneyPriceFactor1 );

      // This is probably unnecessary as {FixInstrumentBestAggregatedBidAskQuoteItemsValidityBitMask} would fix it anyway but it's OK.
      InstrumentBestAggregatedBidAskQuoteItemsValidityBitMask_ = ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteItemsBitMask_None;
   }

#endif
#if( /* {public Prepare}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPrimaryPeerStrategy::Prepare
      ( TTradingSystem & tradingSystem1
      )
   {
      // Visible universe.
//TODO

      TPeerStrategyBase::Prepare( tradingSystem1 );

      // Instead of generating this randomly it would be better to use one direction in one week and another direction in another week.
      // This can be done by dividing expected report release date-time by a week but the week period would need to be configurable.
      // We would need to ensure that the formulas would produce the same result on each day of the given week.
      // If the period is a month the logic would have to be different.
      {
         RandomNumber1_ =
            ::Common::Math::TMultiplyWithCarryRandomNumberCommonGeneratorHelpers::MultiplyWithCarryRandomNumberCommonGenerator.GenerateLowQuality1BitRaw() & 1U;
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( RandomNumber1_ <= 1U && ( RandomNumber1_ ^ 1U ) <= 1U );
      }

      
   }

#endif
#if( /* {public DoRun}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPrimaryPeerStrategy::DoRun()
   {
      // Visible universe.
      //    {DoRun} -- base.
      //       Implement.
//TODO add more

      //TPeerStrategyBase::DoRun();

//TODO write code
   }

#endif
}
