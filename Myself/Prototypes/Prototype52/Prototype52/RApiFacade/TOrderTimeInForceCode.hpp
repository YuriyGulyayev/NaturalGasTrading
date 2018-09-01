#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   // These values match the values used for the {TimeInForce} FIX field.
   // However that field is a {char} while this {enum} underlying type is {int} -- for efficiency.
   // yg? Consider moving this to a more common namespace. But then I would probably want to also move
   // yg? {TSingleInstrumentOrder::TimeInForceCode} to {::Finance::Trading::TSingleInstrumentOrderBase<,>}.
   // yg? But it might not be needed for an arbitrary brokerage API facade or its caller.

   enum TOrderTimeInForceCode : int
   {
      //
      TOrderTimeInForceCode_None = 0,

      //
      TOrderTimeInForceCode_Day = static_cast< unsigned char >( '0' ),

      //
      TOrderTimeInForceCode_GoodTillCancelled = static_cast< unsigned char >( '1' ),

      //
      TOrderTimeInForceCode_ImmediateOrCancel = static_cast< unsigned char >( '3' ),
   };
}
