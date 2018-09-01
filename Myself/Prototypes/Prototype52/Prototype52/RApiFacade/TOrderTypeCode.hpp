#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   // These values match the values used for the {OrdType} FIX field.
   // However that field is a {char} while this {enum} underlying type is {int} -- for efficiency.
   // yg? Consider moving this to a more common namespace. But then I would probably want to also move
   // yg? {TSingleInstrumentOrder::TypeCode} to {::Finance::Trading::TSingleInstrumentOrderBase<,>}.

   enum TOrderTypeCode : int
   {
      //
      TOrderTypeCode_None = 0,

      //
      TOrderTypeCode_Market = static_cast< unsigned char >( '1' ),

      //
      TOrderTypeCode_Limit = static_cast< unsigned char >( '2' ),

      //
      TOrderTypeCode_StopMarket = static_cast< unsigned char >( '3' ),

      //
      TOrderTypeCode_StopLimit = static_cast< unsigned char >( '4' ),

      //
      TOrderTypeCode_MarketIfTouched = static_cast< unsigned char >( 'J' ),

      // yg? This code might be non-standard.
      TOrderTypeCode_LimitIfTouched = static_cast< unsigned char >( 'W' ),
   };
}
