#pragma once

#include "../Finance/MarketData/TInstrumentTradeSubscription.hpp"
#include "./TInstrument.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   //
   typedef ::Finance::MarketData::TInstrumentTradeSubscription< TInstrument > TInstrumentTradeSubscription;
}
