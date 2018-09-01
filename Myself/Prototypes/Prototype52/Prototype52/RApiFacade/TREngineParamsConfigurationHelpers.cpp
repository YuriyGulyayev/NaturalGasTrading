#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TREngineParamsConfigurationHelpers.hpp"

#include "./TREngineParamsConfiguration.cpp"
#include "../Common/Diagnostics/Macros.cpp"

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

   void TREngineParamsConfigurationHelpers::ExtractConfiguration
      ( TREngineParamsConfiguration & rEngineParamsConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "sAppName" );

         // Unnamed objects -- move semantics.
         rEngineParamsConfiguration1.sAppName.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "sAppVersion" );

         // Unnamed objects -- move semantics.
         rEngineParamsConfiguration1.sAppVersion.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "sAdmCnnctPt" );

         // Unnamed objects -- move semantics.
         rEngineParamsConfiguration1.sAdmCnnctPt.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "sLogFilePath" );

         // Unnamed objects -- move semantics.
         rEngineParamsConfiguration1.sLogFilePath.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      // TODO 3 yg? This code should be moved to a helper method that extracts environment variables.
      {
         static char const parameter1NameAsArray[]( "EnvironmentVariables" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         ::Poco::Util::AbstractConfiguration::Keys keys;
         abstractConfiguration1View1->keys( keys );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( rEngineParamsConfiguration1.EnvironmentVariables.empty() );
         rEngineParamsConfiguration1.EnvironmentVariables.resize( keys.size() );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( rEngineParamsConfiguration1.envp.empty() );

         // The last item will stay {nullptr}.
         // Assuming this will not overflow.
         rEngineParamsConfiguration1.envp.resize( keys.size() + 1U );

         ::std::vector< ::std::string >::iterator environmentVariablesIterator( rEngineParamsConfiguration1.EnvironmentVariables.begin() );
         ::std::vector< char const * >::iterator envpIterator( rEngineParamsConfiguration1.envp.begin() );

         // This iterator can't be const.
         for( ::Poco::Util::AbstractConfiguration::Keys::iterator keysIterator( keys.begin() ) ; keysIterator != keys.end() ; ++ keysIterator )

         {
            // Using {* keysIterator} before moving it.
            // Unnamed objects -- move semantics.
            ::std::string environmentVariableValue( abstractConfiguration1View1->getString( * keysIterator ) );

            environmentVariablesIterator->assign( ::std::move( * keysIterator ) );

            // Assuming this will not overflow.
            environmentVariablesIterator->reserve( environmentVariablesIterator->length() + 1U + environmentVariableValue.length() );

            environmentVariablesIterator
               // Magic char hardcoded, which is probably not too bad.
               ->append( 1U, '=' )

               .append( environmentVariableValue );
               //.shrink_to_fit();

            ( * envpIterator ) = environmentVariablesIterator->c_str();
            ++ environmentVariablesIterator;
            ++ envpIterator;
         }
      }
   }

#endif
}
