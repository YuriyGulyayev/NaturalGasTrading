#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   //

   enum TStrategyTypeCode : int
   {
      //
      TStrategyTypeCode_None = 0,

      //
      TStrategyTypeCode_TWarmUpStrategy = 1,

      //
//TODO this is yet to be done
      TStrategyTypeCode_TMarketDataSubscriptionOnlyStrategy = 5,

      //
      TStrategyTypeCode_TPrimaryPeerStrategy = 11,

      //
      TStrategyTypeCode_TSecondaryPeerStrategy = 12,
   };
}
