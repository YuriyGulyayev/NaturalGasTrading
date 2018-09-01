#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   //

   enum TOrderModificationRequestStateCode : int
   {
      //
      TOrderModificationRequestStateCode_None = 0,

      //
      TOrderModificationRequestStateCode_Sent = 1,

      //
      TOrderModificationRequestStateCode_ReceivedByBroker = 2,

      // It might make sense to use the word "failed" but it's not necessarily a good idea.
      TOrderModificationRequestStateCode_Rejected = 3,

      //
      TOrderModificationRequestStateCode_Succeeded = 4,
   };
}
