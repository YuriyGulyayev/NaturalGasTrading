#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPetroleumStatusReportDownloaderConfigurationHelpers.hpp"

#include "./TPetroleumStatusReportDownloaderConfiguration.cpp"
#include "./TEconomicReportDownloaderWithTcpParallelRequestsBaseConfigurationHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public ExtractConfiguration}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPetroleumStatusReportDownloaderConfigurationHelpers::ExtractConfiguration
      ( TPetroleumStatusReportDownloaderConfiguration & petroleumStatusReportDownloaderConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      TEconomicReportDownloaderWithTcpParallelRequestsBaseConfigurationHelpers::ExtractConfiguration
         ( petroleumStatusReportDownloaderConfiguration1, abstractConfiguration1 );

      {
         static char const parameter1NameAsArray[]( "CommercialCrudeOilStocksQuantityDifferenceMultiplier" );
         //petroleumStatusReportDownloaderConfiguration1.CommercialCrudeOilStocksQuantityDifferenceMultiplier = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
         petroleumStatusReportDownloaderConfiguration1.CommercialCrudeOilStocksQuantityDifferenceMultiplier =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "MotorGasolineStocksQuantityDifferenceMultiplier" );
         //petroleumStatusReportDownloaderConfiguration1.MotorGasolineStocksQuantityDifferenceMultiplier = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
         petroleumStatusReportDownloaderConfiguration1.MotorGasolineStocksQuantityDifferenceMultiplier =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "DistillateFuelOilStocksQuantityDifferenceMultiplier" );
         //petroleumStatusReportDownloaderConfiguration1.DistillateFuelOilStocksQuantityDifferenceMultiplier = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
         petroleumStatusReportDownloaderConfiguration1.DistillateFuelOilStocksQuantityDifferenceMultiplier =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
}
