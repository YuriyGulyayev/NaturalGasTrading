#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPreEntryOrdersSendingProtectionConfiguration.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPreEntryOrdersSendingProtectionConfiguration::TPreEntryOrdersSendingProtectionConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance move constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPreEntryOrdersSendingProtectionConfiguration::TPreEntryOrdersSendingProtectionConfiguration
      ( TPreEntryOrdersSendingProtectionConfiguration && source
      ) :
      InstrumentBestAggregatedBidAskQuotePricesSpreadMaxLimit
         ( ::std::move( source.InstrumentBestAggregatedBidAskQuotePricesSpreadMaxLimit ) ),
      //InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit
      //   ( ::std::move( source.InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit ) ),
      InstrumentLastTradePriceDeviationMaxLimit( ::std::move( source.InstrumentLastTradePriceDeviationMaxLimit ) ),
      NumberInstrumentTradesCheapMovingAverageMinLimit
         ( ::std::move( source.NumberInstrumentTradesCheapMovingAverageMinLimit ) ),
      NumberInstrumentTradesCheapMovingAverageMaxLimit
         ( ::std::move( source.NumberInstrumentTradesCheapMovingAverageMaxLimit ) )
   {
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPreEntryOrdersSendingProtectionConfiguration & TPreEntryOrdersSendingProtectionConfiguration::operator =
      ( TPreEntryOrdersSendingProtectionConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPreEntryOrdersSendingProtectionConfiguration::Assign
      ( TPreEntryOrdersSendingProtectionConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      InstrumentBestAggregatedBidAskQuotePricesSpreadMaxLimit =
         ::std::move( source.InstrumentBestAggregatedBidAskQuotePricesSpreadMaxLimit );
      //InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit =
      //   ::std::move( source.InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit );
      InstrumentLastTradePriceDeviationMaxLimit = ::std::move( source.InstrumentLastTradePriceDeviationMaxLimit );
      NumberInstrumentTradesCheapMovingAverageMinLimit =
         ::std::move( source.NumberInstrumentTradesCheapMovingAverageMinLimit );
      NumberInstrumentTradesCheapMovingAverageMaxLimit =
         ::std::move( source.NumberInstrumentTradesCheapMovingAverageMaxLimit );
   }

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPreEntryOrdersSendingProtectionConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
