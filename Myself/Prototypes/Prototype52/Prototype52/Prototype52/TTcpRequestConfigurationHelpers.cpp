#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TTcpRequestConfigurationHelpers.hpp"

#include "./TTcpRequestConfiguration.cpp"
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

   void TTcpRequestConfigurationHelpers::ExtractConfiguration
      ( TTcpRequestConfiguration & tcpRequestConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "LocalIPHostName" );

         // Unnamed objects -- move semantics.
         tcpRequestConfiguration1.LocalIPHostName.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "ShallAdvanceSocketNextDynamicPortNumber" );
         tcpRequestConfiguration1.ShallAdvanceSocketNextDynamicPortNumber =
            abstractConfiguration1.getBool( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "DestinationUrlAsString" );

         // Unnamed objects -- move semantics.
         tcpRequestConfiguration1.DestinationUrlAsString.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "RequestContent" );

         // yg? It appears, {RequestContent} is read with no corruption from the XML, but keep an eye on it.
         // Unnamed objects -- move semantics.
         tcpRequestConfiguration1.RequestContent.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "NumberRequestsToSend" );
         tcpRequestConfiguration1.NumberRequestsToSend =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "RequestsPreSendingBitMask" );

         // yg? There is no such thing as {getUInt} but this parses a hexadecimal number as an unsigned.
         tcpRequestConfiguration1.RequestsPreSendingBitMask =
            static_cast< unsigned int >
               ( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "FirstRequestSendingTimeOffsetMilliseconds" );
         tcpRequestConfiguration1.FirstRequestSendingTimeOffsetMilliseconds =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "RequestSendingIntervalMilliseconds" );
         tcpRequestConfiguration1.RequestSendingIntervalMilliseconds =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
#if( /* {public ExtractConfigurations}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTcpRequestConfigurationHelpers::ExtractConfigurations
      ( ::std::vector< TTcpRequestConfiguration > & tcpRequestsConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      ::Poco::Util::AbstractConfiguration::Keys keys;
      abstractConfiguration1.keys( keys );

      // Assuming the collection is initially empty and all keys in the configuration are "add".
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsConfiguration1.empty() );
      tcpRequestsConfiguration1.resize( keys.size() );

      ::std::vector< TTcpRequestConfiguration >::iterator tcpRequestsConfiguration1Iterator( tcpRequestsConfiguration1.begin() );
      for( ::Poco::Util::AbstractConfiguration::Keys::const_iterator keysIterator( keys.cbegin() ) ; keysIterator != keys.cend() ; ++ keysIterator )
      {
         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( * keysIterator ) ) );

         ExtractConfiguration( ( * tcpRequestsConfiguration1Iterator ), ( * abstractConfiguration1View1 ) );
         ++ tcpRequestsConfiguration1Iterator;
      }
   }

#endif

#if( /* //{public TryFindTcpRequestConfigurationByRequestContentPointer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TTcpRequestsConfigurationIterator_
   //   >
   //inline TTcpRequestsConfigurationIterator_ TTcpRequestConfigurationHelpers::TryFindTcpRequestConfigurationByRequestContentPointer
   //   ( TTcpRequestsConfigurationIterator_ tcpRequestsConfigurationBeginIterator,
   //     TTcpRequestsConfigurationIterator_ tcpRequestsConfigurationEndIterator,
   //     ::std::string const * requestContent
   //   )
   //{
   //   auto predicate1
   //      ( [ & ]
   //        ( TTcpRequestConfiguration const & tcpRequestConfiguration1
   //        )
   //        -> bool
   //        {
   //            return ( ( & tcpRequestConfiguration1.RequestContent ) == requestContent );
   //        }
   //      );
   //   return ::std::find_if( tcpRequestsConfigurationBeginIterator, tcpRequestsConfigurationEndIterator, predicate1 );
   //}

#endif
}
