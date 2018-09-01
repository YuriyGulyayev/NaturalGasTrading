#pragma once

#include "StdAfx.h"

// TODO 1 yg? Remove this file.

#if 0

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TStrategyConfigurationHelpers.hpp"

#include "./TStrategyConfiguration.cpp"
#include "../Common/Time/TTimeHelpers.cpp"
#include "../Common/Time/TDateTimeKeeperConfigurationHelpers.cpp"
#include "../Common/DataFormatting/TDataFormattingHelpers.cpp"
#include "../Finance/Math/TInstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculatorConfigurationHelpers.cpp"
#include "./TPositionConfigurationHelpers.cpp"
#include "./TUntradableConditionConfigurationHelpers.cpp"
#include "./TNumberEventsCheapMovingAverageCalculatorConfigurationHelpers.cpp"
#include "./TEconomicReportReceiverFactoryConfigurationHelpers.cpp"
#include "./TPeerMessageSenderConfigurationHelpers.cpp"
>>>#include "./TPeerDataReceiverConfigurationHelpers.cpp"
#include "./TFileSystemCacheFlusherConfigurationHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

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

#if( /* {public ExtractConfiguration}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategyConfigurationHelpers::ExtractConfiguration
      ( TStrategyConfiguration & strategyConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      // yg? Parts of this code can be moved to helper methods.
//TODO remove prev. comment?

      {
         static char const parameter1NameAsArray[]( "ModeCode" );

         // yg? There is no such thing as {getUInt}.
         strategyConfiguration1.ModeCode = static_cast< TPeerStrategyBaseModeCode >( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Timer1TickIntervalMilliseconds" );
         strategyConfiguration1.Timer1TickIntervalMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         ::Poco::DateTime dateTime1( ::Common::Time::TTimeHelpers::MinDateTime );

         {
            static char const parameter1NameAsArray[]( "EconomicReportReleaseTimeOfDayMilliseconds" );

            // Unnamed objects -- move semantics.
            ::std::string economicReportReleaseTimeOfDayMillisecondsAsString( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );

            int timeZoneDifferential1;

            // yg? Second resolution. I don't want to support fractions of a second. If we parsed fractions of a second we would need to factor them below.
            // yg? This method leaves {year = 0} instead of 1970, which is probably by design.
            // yg? Using current thread locale.
//TODO can we support fractional seconds?
            ::Poco::DateTimeParser::parse
               ( ::Common::DataFormatting::TDataFormattingHelpers::TimeOfDaySecondResolutionFormatString,
                 economicReportReleaseTimeOfDayMillisecondsAsString,
                 dateTime1,
                 timeZoneDifferential1
               );
         }
      
         strategyConfiguration1.EconomicReportReleaseTimeOfDayMilliseconds =
            // yg? This will divide without a remainder because the time resolution is a second.
            // yg? This doesn't work because {year == 0}.
////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
            //static_cast< int >( dateTime1.timestamp().epochMicroseconds() / ::Poco::Timespan::MILLISECONDS );

////  Validate this everywhere we use this and other similar constants. Replace division with multiplication.
            //static_cast< int >( dateTime1.utcTime() / ::Poco::Timespan::MILLISECONDS );

            // yg? We don't need to factor milliseconds or microseconds because the time resolution is a second.
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
            dateTime1.hour() * ( static_cast< int >( ::Poco::Timespan::HOURS /*)*/ / /*static_cast< int >(*/ ::Poco::Timespan::MILLISECONDS ) )
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
            + dateTime1.minute() * ( static_cast< int >( ::Poco::Timespan::MINUTES /*)*/ / /*static_cast< int >(*/ ::Poco::Timespan::MILLISECONDS ) )
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
            + dateTime1.second() * ( static_cast< int >( ::Poco::Timespan::SECONDS /*)*/ / /*static_cast< int >(*/ ::Poco::Timespan::MILLISECONDS ) );
      }
      {
         static char const parameter1NameAsArray[]( "EconomicReportReleaseDateTimeWarmUpOffsetMilliseconds" );
         strategyConfiguration1.EconomicReportReleaseDateTimeWarmUpOffsetMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "EconomicReportReleaseDateTimeTestOffsetMilliseconds" );
         strategyConfiguration1.EconomicReportReleaseDateTimeTestOffsetMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "DataLoggingIntervalTimer1Ticks" );
         strategyConfiguration1.DataLoggingIntervalTimer1Ticks = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "NumberDataLastLoggingsOnTimer1TickToForce" );
         strategyConfiguration1.NumberDataLastLoggingsOnTimer1TickToForce = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "FileSystemCacheFlushing1TimeOffsetMilliseconds" );
         strategyConfiguration1.FileSystemCacheFlushing1TimeOffsetMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "FileSystemCacheFlushing2TimeOffsetMilliseconds" );
         strategyConfiguration1.FileSystemCacheFlushing2TimeOffsetMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "PeerMessageSendingWarmUp1TimeOffsetMilliseconds" );
         strategyConfiguration1.PeerMessageSendingWarmUp1TimeOffsetMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "PeerMessageSendingWarmUp2TimeOffsetMilliseconds" );
         strategyConfiguration1.PeerMessageSendingWarmUp2TimeOffsetMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "EntryOrdersModificationWarmUp1TimeOffsetMilliseconds" );
         strategyConfiguration1.EntryOrdersModificationWarmUp1TimeOffsetMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "EntryOrdersModificationWarmUp2TimeOffsetMilliseconds" );
         strategyConfiguration1.EntryOrdersModificationWarmUp2TimeOffsetMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "EntryOrdersModificationTimeOffsetMilliseconds" );
         strategyConfiguration1.EntryOrdersModificationTimeOffsetMilliseconds = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "EconomicReportReceptionTimeoutTimeSpanMilliseconds" );
         strategyConfiguration1.EconomicReportReceptionTimeoutTimeSpanMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "TerminationTimeOffsetMilliseconds" );
         strategyConfiguration1.TerminationTimeOffsetMilliseconds = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "InstrumentDeepOutOfMoneyPriceFactor1" );
         strategyConfiguration1.InstrumentDeepOutOfMoneyPriceFactor1 = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      //{
      //   //static char const parameter1NameAsArray[]( "PositionsConfiguration" );
      //
      //   //// We have to do a {const_cast} here.
      //   //::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );
      //
      //   // yg? Only exactly 2 items are supported.
      //   //static char const * const parameters2NameAsArray[] = { "add", "add[1]" };
      //   static char const * const parameters2NameAsArray[] = { "PositionsConfiguration.add", "PositionsConfiguration.add[1]" };
      //
      //   for( int counter1( 0 ) ; counter1 < 2 ; ++ counter1 )
      //   {
      //      char const * parameter2NameAsArray( parameters2NameAsArray[ static_cast< unsigned int >( counter1 ) ] );
      //
      //      // We have to do a {const_cast} here.
      //      //::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View2( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1View1->createView( ::std::string( parameter2NameAsArray/*, ( sizeof( parameter2NameAsArray ) / sizeof( parameter2NameAsArray[ 0U ] ) - 1U )*/ ) ) ) );
      //      ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View2( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter2NameAsArray/*, ( sizeof( parameter2NameAsArray ) / sizeof( parameter2NameAsArray[ 0U ] ) - 1U )*/ ) ) ) );
      //
      //      TPositionConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.PositionsConfiguration[ static_cast< unsigned int >( counter1 ) ], ( * abstractConfiguration1View2 ) );
      //   }
      //}
      {
         static char const parameter1NameAsArray[]( "PositionsConfiguration.add" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );

         TPositionConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.PositionConfiguration, ( * abstractConfiguration1View1 ) );
      }
      {
         static char const parameter1NameAsArray[]( "UntradableConditionConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );

         TUntradableConditionConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.UntradableConditionConfiguration, ( * abstractConfiguration1View1 ) );
      }
      {
         static char const parameter1NameAsArray[]( "InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculatorConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );

         ::Finance::Math::TInstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculatorConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.InstrumentBestAggregatedBidAskQuotePricesCheapMovingAverageCalculatorConfiguration, ( * abstractConfiguration1View1 ) );
      }
      {
         static char const parameter1NameAsArray[]( "NumberInstrumentTradesCheapMovingAverageCalculatorConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );

         TNumberEventsCheapMovingAverageCalculatorConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.NumberInstrumentTradesCheapMovingAverageCalculatorConfiguration, ( * abstractConfiguration1View1 ) );
      }
      {
         static char const parameter1NameAsArray[]( "EconomicReportReceiverFactoryConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );

         TEconomicReportReceiverFactoryConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.EconomicReportReceiverFactoryConfiguration, ( * abstractConfiguration1View1 ) );
      }
      {
         static char const parameter1NameAsArray[]( "PeerMessageSenderConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );

         TPeerMessageSenderConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.PeerMessageSenderConfiguration, ( * abstractConfiguration1View1 ) );
      }
>>>      {
         static char const parameter1NameAsArray[]( "PeerDataReceiverConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );

         TPeerDataReceiverConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.PeerDataReceiverConfiguration, ( * abstractConfiguration1View1 ) );
      }
      {
         static char const parameter1NameAsArray[]( "FileSystemCacheFlusherConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );

         TFileSystemCacheFlusherConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.FileSystemCacheFlusherConfiguration, ( * abstractConfiguration1View1 ) );
      }
      {
         static char const parameter1NameAsArray[]( "DateTimeKeeperConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) ) );

         ::Common::Time::TDateTimeKeeperConfigurationHelpers::ExtractConfiguration( strategyConfiguration1.DateTimeKeeperConfiguration, ( * abstractConfiguration1View1 ) );
      }
   }

#endif
}

#endif
