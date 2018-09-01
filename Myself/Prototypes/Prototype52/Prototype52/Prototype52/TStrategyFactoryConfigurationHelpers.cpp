#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TStrategyFactoryConfigurationHelpers.hpp"

#include "./TStrategyFactoryConfiguration.cpp"
#include "../Common/ErrorHandling/TRegularErrorException.cpp"
#include "../Common/Diagnostics/TDiagnosticsHelpers.cpp"
#include "./TWarmUpStrategyConfigurationHelpers.cpp"
#include "./TPrimaryPeerStrategyConfigurationHelpers.cpp"
#include "./TSecondaryPeerStrategyConfigurationHelpers.cpp"

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

   void TStrategyFactoryConfigurationHelpers::ExtractConfiguration
      ( TStrategyFactoryConfiguration & strategyFactoryConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "DataTypeCode" );
         strategyFactoryConfiguration1.DataTypeCode =
            static_cast< TStrategyTypeCode >
               ( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter3NameAsArray[]( "DataTypeConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter3NameAsArray, ( sizeof( parameter3NameAsArray ) / sizeof( parameter3NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         switch( strategyFactoryConfiguration1.DataTypeCode )
         {
            case TStrategyTypeCode_TWarmUpStrategy :
            {
               TWarmUpStrategyConfiguration * warmUpStrategyConfiguration1( new TWarmUpStrategyConfiguration );
               strategyFactoryConfiguration1.DataTypeConfiguration.reset( warmUpStrategyConfiguration1 );
               TWarmUpStrategyConfigurationHelpers::ExtractConfiguration
                  ( ( * warmUpStrategyConfiguration1 ), ( * abstractConfiguration1View1 ) );
               break;
            }

            case TStrategyTypeCode_TPrimaryPeerStrategy :
            {
               TPrimaryPeerStrategyConfiguration * primaryPeerStrategyConfiguration1( new TPrimaryPeerStrategyConfiguration );
               strategyFactoryConfiguration1.DataTypeConfiguration.reset( primaryPeerStrategyConfiguration1 );
               TPrimaryPeerStrategyConfigurationHelpers::ExtractConfiguration
                  ( ( * primaryPeerStrategyConfiguration1 ), ( * abstractConfiguration1View1 ) );
               break;
            }
         
            case TStrategyTypeCode_TSecondaryPeerStrategy :
            {
               TSecondaryPeerStrategyConfiguration * secondaryPeerStrategyConfiguration1( new TSecondaryPeerStrategyConfiguration );
               strategyFactoryConfiguration1.DataTypeConfiguration.reset( secondaryPeerStrategyConfiguration1 );
               TSecondaryPeerStrategyConfigurationHelpers::ExtractConfiguration
                  ( ( * secondaryPeerStrategyConfiguration1 ), ( * abstractConfiguration1View1 ) );
               break;
            }
         
            default :
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

               {
                  static char const constantString1AsArray[]
                     ( "Error; {Prototype52::TStrategyFactoryConfigurationHelpers::ExtractConfiguration} failed" );
                  
                  // yg? Would it make sense to throw a {::Common::ErrorHandling::TCriticalErrorException} here.
                  throw ::Common::ErrorHandling::TRegularErrorException
                               ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                                 0
                               );
               }
            }
         }
      }
   }

#endif
}
