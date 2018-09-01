#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportReceiverViaTcpBaseConfigurationHelpers.hpp"

#include "./TEconomicReportReceiverViaTcpBaseConfiguration.cpp"
#include "./TEconomicReportReceiverBaseConfigurationHelpers.cpp"

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

   void TEconomicReportReceiverViaTcpBaseConfigurationHelpers::ExtractConfiguration
      ( TEconomicReportReceiverViaTcpBaseConfiguration & economicReportReceiverViaTcpBaseConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      TEconomicReportReceiverBaseConfigurationHelpers::ExtractConfiguration
         ( economicReportReceiverViaTcpBaseConfiguration1, abstractConfiguration1 );

      {
         static char const parameter1NameAsArray[]( "EconomicReportSenderIPHostName" );

         // Unnamed objects -- move semantics.
         economicReportReceiverViaTcpBaseConfiguration1.EconomicReportSenderIPHostName.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "EconomicReportSenderIPPortNumber" );

         // yg? There is no such thing as {getUInt16}.
         // yg? Assuming this will not overflow. But it would be nice to validate this.
         economicReportReceiverViaTcpBaseConfiguration1.EconomicReportSenderIPPortNumber =
            static_cast< unsigned short >
               ( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "LocalIPHostName" );

         // Unnamed objects -- move semantics.
         economicReportReceiverViaTcpBaseConfiguration1.LocalIPHostName.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      
      //{
      //   static char const parameter1NameAsArray[]( "SocketKeepAliveTimeoutTimeSpanMilliseconds" );
      //   economicReportReceiverViaTcpBaseConfiguration1.SocketKeepAliveTimeoutTimeSpanMilliseconds =
      //      abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      //}

      //{
      //   static char const parameter1NameAsArray[]( "SocketKeepAliveIntervalMilliseconds" );
      //   economicReportReceiverViaTcpBaseConfiguration1.SocketKeepAliveIntervalMilliseconds =
      //      abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      //}
   }

#endif
}
