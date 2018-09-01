#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportDownloaderWithTcpParallelRequestsBaseConfigurationHelpers.hpp"

#include "./TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration.cpp"
#include "../Common/Networking/TSocketNextDynamicPortNumberAdvancerConfigurationHelpers.cpp"
#include "./TEconomicReportReceiverBaseConfigurationHelpers.cpp"
#include "./TTcpRequestConfigurationHelpers.cpp"

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

   void TEconomicReportDownloaderWithTcpParallelRequestsBaseConfigurationHelpers::ExtractConfiguration
      ( TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration & economicReportDownloaderWithTcpParallelRequestsBaseConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      TEconomicReportReceiverBaseConfigurationHelpers::ExtractConfiguration
         ( economicReportDownloaderWithTcpParallelRequestsBaseConfiguration1, abstractConfiguration1 );

      {
         static char const parameter1NameAsArray[]( "RequestPreSendingTimeOffsetMilliseconds" );
         economicReportDownloaderWithTcpParallelRequestsBaseConfiguration1.RequestPreSendingTimeOffsetMilliseconds =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "ForcedDelayTimeSpanMillisecondsInTestMode" );
         economicReportDownloaderWithTcpParallelRequestsBaseConfiguration1.ForcedDelayTimeSpanMillisecondsInTestMode =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "SocketNextDynamicPortNumberAdvancerConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         ::Common::Networking::TSocketNextDynamicPortNumberAdvancerConfigurationHelpers::ExtractConfiguration
            ( economicReportDownloaderWithTcpParallelRequestsBaseConfiguration1.SocketNextDynamicPortNumberAdvancerConfiguration, ( * abstractConfiguration1View1 ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "TcpRequestsConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         TTcpRequestConfigurationHelpers::ExtractConfigurations
            ( economicReportDownloaderWithTcpParallelRequestsBaseConfiguration1.TcpRequestsConfiguration, ( * abstractConfiguration1View1 ) );
      }
   }

#endif
}
