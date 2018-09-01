#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TTradingSystemConfigurationHelpers.hpp"

#include "./TTradingSystemConfiguration.cpp"
#include "../RApiFacade/TREngineAdapterConfigurationHelpers.cpp"
#include "./TStrategyFactoryConfigurationHelpers.cpp"

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

   void TTradingSystemConfigurationHelpers::ExtractConfiguration
      ( TTradingSystemConfiguration & tradingSystemConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "REngineAdapterConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         ::RApiFacade::TREngineAdapterConfigurationHelpers::ExtractConfiguration
            ( tradingSystemConfiguration1.REngineAdapterConfiguration, ( * abstractConfiguration1View1 ) );
      }

      {
         static char const parameter1NameAsArray[]( "StrategyFactoryConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         TStrategyFactoryConfigurationHelpers::ExtractConfiguration
            ( tradingSystemConfiguration1.StrategyFactoryConfiguration, ( * abstractConfiguration1View1 ) );
      }
   }

#endif
#if( /* {public ExtractConfigurations}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTradingSystemConfigurationHelpers::ExtractConfigurations
      ( ::std::vector< ::std::unique_ptr< TTradingSystemConfiguration > > & tradingSystemsConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      ::Poco::Util::AbstractConfiguration::Keys keys;
      abstractConfiguration1.keys( keys );

      // Assuming the collection is initially empty and all keys in the configuration are "add".
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tradingSystemsConfiguration1.empty() );
      tradingSystemsConfiguration1.resize( keys.size() );

      ::std::vector< ::std::unique_ptr< TTradingSystemConfiguration > >::iterator tradingSystemsConfiguration1Iterator
         ( tradingSystemsConfiguration1.begin() );
      for( ::Poco::Util::AbstractConfiguration::Keys::const_iterator keysIterator( keys.cbegin() ) ; keysIterator != keys.cend() ; ++ keysIterator )
      {
         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( * keysIterator ) ) );

         TTradingSystemConfiguration * tradingSystemConfiguration1( new TTradingSystemConfiguration );
         tradingSystemsConfiguration1Iterator->reset( tradingSystemConfiguration1 );
         ExtractConfiguration( ( * tradingSystemConfiguration1 ), ( * abstractConfiguration1View1 ) );
         ++ tradingSystemsConfiguration1Iterator;
      }
   }

#endif
}
