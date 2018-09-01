#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   //

   enum TEconomicReportReceiverTypeCode : int
   {
      //
      TEconomicReportReceiverTypeCode_None = 0,

      //
      TEconomicReportReceiverTypeCode_TNaturalGasStorageReportDownloader = 1,

      //
      TEconomicReportReceiverTypeCode_TPetroleumStatusReportDownloader = 2,

      //
      TEconomicReportReceiverTypeCode_TNewsHubEconomicIndicatorReceiver = 3,
   };
}
