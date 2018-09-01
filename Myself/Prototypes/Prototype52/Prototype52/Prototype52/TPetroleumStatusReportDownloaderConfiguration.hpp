#pragma once

#include "./TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // See the config file for more info.

   class TPetroleumStatusReportDownloaderConfiguration :
      public TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration
   {
#if( /* {public CommercialCrudeOilStocksQuantityDifferenceMultiplier}. */ 1 )

      //
      //public: double CommercialCrudeOilStocksQuantityDifferenceMultiplier;
      public: int CommercialCrudeOilStocksQuantityDifferenceMultiplier;

#endif
#if( /* {public MotorGasolineStocksQuantityDifferenceMultiplier}. */ 1 )

      //
      //public: double MotorGasolineStocksQuantityDifferenceMultiplier;
      public: int MotorGasolineStocksQuantityDifferenceMultiplier;

#endif
#if( /* {public DistillateFuelOilStocksQuantityDifferenceMultiplier}. */ 1 )

      //
      //public: double DistillateFuelOilStocksQuantityDifferenceMultiplier;
      public: int DistillateFuelOilStocksQuantityDifferenceMultiplier;

#endif

#if( /* {(public)} Instance default constructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // {virtual}.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif

#if( /* {public Validate}. */ 1 )

      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.
      // TODO 3 yg? If I implement this method I will need to make it {virtual}.

      public: void Validate() const;

#endif
   };
}