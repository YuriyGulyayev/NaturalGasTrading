#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // See the config file for more info.

//TODO make underlying type int
//TODO make this not a bitmask-like
//TODO or leave it as is?
   enum TPeerStrategyBaseModeCode : unsigned int
   {
      //
      TPeerStrategyBaseModeCode_None = 0U,

      //
      TPeerStrategyBaseModeCode_Normal = ( 1U << 0U ),

      //
//TODO we normally compare variables to this value because of the "warm-up or test" paradign but now we should compare to TPeerStrategyBaseModeCode_Normal
//TODO but think about it
      TPeerStrategyBaseModeCode_Test = ( 1U << 1U ),

//TODO we need a special {MarketDataSubscriptionOnly} strategy, to be named better. See {TStrategyTypeCode_TMarketDataSubscriptionOnlyStrategy}.
//TODO It might need to log the whole order book.
//TODO remove
      ////
      //TPeerStrategyBaseModeCode_MarketDataSubscriptionOnly = ( 1U << 2U ),
   };
}
