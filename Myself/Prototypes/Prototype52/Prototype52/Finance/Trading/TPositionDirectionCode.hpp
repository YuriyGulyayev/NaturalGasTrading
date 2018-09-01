#pragma once

//#include "./.hpp"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Finance
{
namespace Trading
{
   //

   enum TPositionDirectionCode : int
   {
      // This value equals 0.
      TPositionDirectionCode_None = 0,

      // This value equals 1 -- to make it possible to use it as a multiplier.
      TPositionDirectionCode_Long = 1,

      // This value equals -1 -- to make it possible to use it as a multiplier.
      TPositionDirectionCode_Short = ( - TPositionDirectionCode_Long )
   };
}
}
