#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   //

   enum TEconomicReportReceiverOutcomeCode : int
   {
      //
      TEconomicReportReceiverOutcomeCode_Success,

      // This indicates that report reception is still in progress.
      TEconomicReportReceiverOutcomeCode_Undefined,

      //
      TEconomicReportReceiverOutcomeCode_OtherError,
   };
}
