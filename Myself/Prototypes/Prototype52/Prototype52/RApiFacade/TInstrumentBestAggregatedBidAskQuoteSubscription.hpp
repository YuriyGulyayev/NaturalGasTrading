#pragma once

#include "../Finance/MarketData/TInstrumentBestAggregatedBidAskQuoteSubscription.hpp"
#include "./TInstrument.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   //
   typedef ::Finance::MarketData::TInstrumentBestAggregatedBidAskQuoteSubscription< TInstrument >
                   TInstrumentBestAggregatedBidAskQuoteSubscription;
}
