#pragma once

#include "StdAfx.h"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrumentBestAggregatedBidAskQuote.hpp"

#include "./TInstrumentAggregatedQuote.cpp"
#include "./TInstrumentBestAggregatedBidAskQuoteItemsBitMask.cpp"
#include "../../Common/Time/TTimeHelpers.cpp"

#include "../../Common/SourceCodeModel/SourceFooter.hpp"

namespace Finance
{
namespace MarketData
{
#if( /* {(public)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public Reset}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TInstrumentBestAggregatedBidAskQuote::Reset()
   {
      Bid.Reset();
      Ask.Reset();
      //GenerationDateTimeStampMillisecondsSince1970 = ::std::numeric_limits< double >::lowest();

      // This divides without a remainder.
      GenerationDateTimeStampMillisecondsSince1970 =
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
         static_cast< double >( ::Common::Time::TTimeHelpers::MinTimeStamp.epochMicroseconds() / ::Poco::Timespan::MILLISECONDS );

      //SendingDateTimeStampMillisecondsSince1970 = ::std::numeric_limits< double >::lowest();
      SendingDateTimeStampMillisecondsSince1970 = GenerationDateTimeStampMillisecondsSince1970;
      LastUpdatedItemsBitMask = TInstrumentBestAggregatedBidAskQuoteItemsBitMask_None;
      ItemsValidityBitMask = TInstrumentBestAggregatedBidAskQuoteItemsBitMask_None;
   }

#endif
#if( /* {public Equals}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   bool TInstrumentBestAggregatedBidAskQuote::Equals
      ( TInstrumentBestAggregatedBidAskQuote const & instance1,
        TInstrumentBestAggregatedBidAskQuote const & instance2
      )
   {
      return
         ( instance1.GenerationDateTimeStampMillisecondsSince1970 == instance2.GenerationDateTimeStampMillisecondsSince1970 &&
           instance1.SendingDateTimeStampMillisecondsSince1970 == instance2.SendingDateTimeStampMillisecondsSince1970 &&
           instance1.LastUpdatedItemsBitMask == instance2.LastUpdatedItemsBitMask &&
           instance1.ItemsValidityBitMask == instance2.ItemsValidityBitMask &&
           TInstrumentAggregatedQuote::Equals( instance1.Bid, instance2.Bid ) &&
           TInstrumentAggregatedQuote::Equals( instance1.Ask, instance2.Ask )
         );
   }

#endif

#if( /* {public PricesSpread}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline double TInstrumentBestAggregatedBidAskQuote::PricesSpread()
   {
      return Ask.Price - Bid.Price;
   }

#endif
}
}
