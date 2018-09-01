#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TNaturalGasStorageReportDownloaderConfigurationHelpers.hpp"

#include "./TNaturalGasStorageReportDownloaderConfiguration.cpp"
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

#if( /* {public ExtractConfiguration}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNaturalGasStorageReportDownloaderConfigurationHelpers::ExtractConfiguration
      ( TNaturalGasStorageReportDownloaderConfiguration & naturalGasStorageReportDownloaderConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      // This method is inline.

      TEconomicReportDownloaderWithTcpParallelRequestsBaseConfigurationHelpers::ExtractConfiguration
         ( naturalGasStorageReportDownloaderConfiguration1, abstractConfiguration1 );
   }

#endif
}
