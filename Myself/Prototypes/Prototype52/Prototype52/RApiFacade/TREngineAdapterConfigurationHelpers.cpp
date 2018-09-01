#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TREngineAdapterConfigurationHelpers.hpp"

#include "./TREngineAdapterConfiguration.cpp"
#include "./TREngineParamsConfigurationHelpers.cpp"
#include "./TLogInParamsConfigurationHelpers.cpp"
#include "./TInstrumentConfigurationHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
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

   void TREngineAdapterConfigurationHelpers::ExtractConfiguration
      ( TREngineAdapterConfiguration & rEngineAdapterConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "REngineParamsConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         TREngineParamsConfigurationHelpers::ExtractConfiguration
            ( rEngineAdapterConfiguration1.REngineParamsConfiguration, ( * abstractConfiguration1View1 ) );
      }

      {
         static char const parameter1NameAsArray[]( "LogInParamsConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         TLogInParamsConfigurationHelpers::ExtractConfiguration
            ( rEngineAdapterConfiguration1.LogInParamsConfiguration, ( * abstractConfiguration1View1 ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "InstrumentsConfiguration.add" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         TInstrumentConfigurationHelpers::ExtractConfiguration
            ( rEngineAdapterConfiguration1.InstrumentConfiguration, ( * abstractConfiguration1View1 ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "ShallSubscribeOrdersStateUpdate" );
         rEngineAdapterConfiguration1.ShallSubscribeOrdersStateUpdate =
            abstractConfiguration1.getBool( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
}
