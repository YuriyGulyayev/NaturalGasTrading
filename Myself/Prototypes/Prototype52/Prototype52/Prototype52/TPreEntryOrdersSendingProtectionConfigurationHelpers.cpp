#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPreEntryOrdersSendingProtectionConfigurationHelpers.hpp"

#include "./TPreEntryOrdersSendingProtectionConfiguration.cpp"

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

   void TPreEntryOrdersSendingProtectionConfigurationHelpers::ExtractConfiguration
      ( TPreEntryOrdersSendingProtectionConfiguration & preEntryOrdersSendingProtectionConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "InstrumentBestAggregatedBidAskQuotePricesSpreadMaxLimit" );
         preEntryOrdersSendingProtectionConfiguration1.InstrumentBestAggregatedBidAskQuotePricesSpreadMaxLimit =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      //{
      //   static char const parameter1NameAsArray[]( "InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit" );
      //   preEntryOrdersSendingProtectionConfiguration1.InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit =
      //      abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      //}

      {
         static char const parameter1NameAsArray[]( "InstrumentLastTradePriceDeviationMaxLimit" );
         preEntryOrdersSendingProtectionConfiguration1.InstrumentLastTradePriceDeviationMaxLimit =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "NumberInstrumentTradesCheapMovingAverageMinLimit" );
         preEntryOrdersSendingProtectionConfiguration1.NumberInstrumentTradesCheapMovingAverageMinLimit =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "NumberInstrumentTradesCheapMovingAverageMaxLimit" );
         preEntryOrdersSendingProtectionConfiguration1.NumberInstrumentTradesCheapMovingAverageMaxLimit =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
}
