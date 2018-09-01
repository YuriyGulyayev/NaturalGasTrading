#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPeerConfigurationHelpers.hpp"

#include "./TPeerConfiguration.cpp"
#include "../Common/Diagnostics/Macros.cpp"

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

   void TPeerConfigurationHelpers::ExtractConfiguration
      ( TPeerConfiguration & peerConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "Id" );

         // yg? There is no such thing as {getChar}.
         // TODO 3 yg? This will result in incorrect behavior if the string is empty -- to be fixed.
         // Unnamed objects -- move semantics.
         peerConfiguration1.Id =
            abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) )[ 0U ];
      }

      {
         static char const parameter1NameAsArray[]( "PeerIPHostName" );

         // Unnamed objects -- move semantics.
         peerConfiguration1.PeerIPHostName.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "PeerIPPortNumber" );

         // yg? There is no such thing as {getUInt16}.
         // yg? Assuming this will not overflow. But it would be nice to validate this.
         peerConfiguration1.PeerIPPortNumber =
            static_cast< unsigned short >
               ( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "LocalIPHostName" );

         // Unnamed objects -- move semantics.
         peerConfiguration1.LocalIPHostName.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
   }

#endif
#if( /* {public ExtractConfigurations}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerConfigurationHelpers::ExtractConfigurations
      ( ::std::vector< TPeerConfiguration > & peersConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      ::Poco::Util::AbstractConfiguration::Keys keys;
      abstractConfiguration1.keys( keys );

      // Assuming the collection is initially empty and all keys in the configuration are "add".
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( peersConfiguration1.empty() );
      peersConfiguration1.resize( keys.size() );

      ::std::vector< TPeerConfiguration >::iterator peersConfiguration1Iterator( peersConfiguration1.begin() );
      for( ::Poco::Util::AbstractConfiguration::Keys::const_iterator keysIterator( keys.cbegin() ) ; keysIterator != keys.cend() ; ++ keysIterator )
      {
         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( * keysIterator ) ) );

         ExtractConfiguration( ( * peersConfiguration1Iterator ), ( * abstractConfiguration1View1 ) );
         ++ peersConfiguration1Iterator;
      }
   }

#endif
}
