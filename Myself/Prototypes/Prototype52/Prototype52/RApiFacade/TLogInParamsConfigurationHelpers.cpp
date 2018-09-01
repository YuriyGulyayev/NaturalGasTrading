#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TLogInParamsConfigurationHelpers.hpp"

#include "./TLogInParamsConfiguration.cpp"

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

   void TLogInParamsConfigurationHelpers::ExtractConfiguration
      ( TLogInParamsConfiguration & logInParamsConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "sUser" );

         // Unnamed objects -- move semantics.
         logInParamsConfiguration1.sUser.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "sPassword" );

         // Unnamed objects -- move semantics.
         logInParamsConfiguration1.sPassword.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      // Not used.
      //{
      //   static char const parameter1NameAsArray[]( "sIhCnnctPt" );
      //
      //   // Unnamed objects -- move semantics.
      //   logInParamsConfiguration1.sIhCnnctPt.assign
      //      ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      //}

      {
         static char const parameter1NameAsArray[]( "sMdCnnctPt" );

         // Unnamed objects -- move semantics.
         logInParamsConfiguration1.sMdCnnctPt.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      // Not used.
      //{
      //   static char const parameter1NameAsArray[]( "sPnlCnnctPt" );
      //
      //   // Unnamed objects -- move semantics.
      //   logInParamsConfiguration1.sPnlCnnctPt.assign
      //      ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      //}

      {
         static char const parameter1NameAsArray[]( "sTsCnnctPt" );

         // Unnamed objects -- move semantics.
         logInParamsConfiguration1.sTsCnnctPt.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
   }

#endif
}
