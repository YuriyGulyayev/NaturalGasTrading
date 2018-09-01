#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TNewsHubEconomicIndicatorReceiverConfigurationHelpers.hpp"

#include "./TNewsHubEconomicIndicatorReceiverConfiguration.cpp"
#include "./TEconomicReportReceiverViaTcpBaseConfigurationHelpers.cpp"

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

   void TNewsHubEconomicIndicatorReceiverConfigurationHelpers::ExtractConfiguration
      ( TNewsHubEconomicIndicatorReceiverConfiguration & newsHubEconomicIndicatorReceiverConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      TEconomicReportReceiverViaTcpBaseConfigurationHelpers::ExtractConfiguration
         ( newsHubEconomicIndicatorReceiverConfiguration1, abstractConfiguration1 );

      //{
         //static char const parameter1NameAsArray[]( "TradingSignalsMap" );
         //
         //// We have to do a {const_cast} here.
         //::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
         //   ( const_cast< ::Poco::Util::AbstractConfiguration * >
         //        ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
         //   );
         //
         //::Common::Configuration::TConfigurationHelpers::ExtractConfigurations
         //   ( newsHubEconomicIndicatorReceiverConfiguration1.TradingSignalsMap, ( * abstractConfiguration1View1 ) );
      //}

      {
         static char const parameter1NameAsArray[]( "SocketDataBufferInitialCapacity" );
         newsHubEconomicIndicatorReceiverConfiguration1.SocketDataBufferInitialCapacity =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      //{
      //   static char const parameter1NameAsArray[]( "SocketDataBufferCapacityMaxLimit" );
      //   newsHubEconomicIndicatorReceiverConfiguration1.SocketDataBufferCapacityMaxLimit =
      //      abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      //}

      {
         static char const parameter1NameAsArray[]( "EconomicIndicatorIdAsString" );

         // Unnamed objects -- move semantics.
         newsHubEconomicIndicatorReceiverConfiguration1.EconomicIndicatorIdAsString.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "EconomicIndicatorValueMultiplier" );
         newsHubEconomicIndicatorReceiverConfiguration1.EconomicIndicatorValueMultiplier =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
}
