#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TTcpRequestConfiguration.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TTcpRequestConfiguration::TTcpRequestConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance move constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TTcpRequestConfiguration::TTcpRequestConfiguration
      ( TTcpRequestConfiguration && source
      ) :
      LocalIPHostName( ::std::move( source.LocalIPHostName ) ),
      ShallAdvanceSocketNextDynamicPortNumber( ::std::move( source.ShallAdvanceSocketNextDynamicPortNumber ) ),
      DestinationUrlAsString( ::std::move( source.DestinationUrlAsString ) ),
      RequestContent( ::std::move( source.RequestContent ) ),
      NumberRequestsToSend( ::std::move( source.NumberRequestsToSend ) ),
      RequestsPreSendingBitMask( ::std::move( source.RequestsPreSendingBitMask ) ),
      FirstRequestSendingTimeOffsetMilliseconds( ::std::move( source.FirstRequestSendingTimeOffsetMilliseconds ) ),
      RequestSendingIntervalMilliseconds( ::std::move( source.RequestSendingIntervalMilliseconds ) )
   {
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TTcpRequestConfiguration & TTcpRequestConfiguration::operator =
      ( TTcpRequestConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTcpRequestConfiguration::Assign
      ( TTcpRequestConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      LocalIPHostName.assign( ::std::move( source.LocalIPHostName ) );
      ShallAdvanceSocketNextDynamicPortNumber = ::std::move( source.ShallAdvanceSocketNextDynamicPortNumber );
      DestinationUrlAsString.assign( ::std::move( source.DestinationUrlAsString ) );
      RequestContent.assign( ::std::move( source.RequestContent ) );
      NumberRequestsToSend = ::std::move( source.NumberRequestsToSend );
      RequestsPreSendingBitMask = ::std::move( source.RequestsPreSendingBitMask );
      FirstRequestSendingTimeOffsetMilliseconds = ::std::move( source.FirstRequestSendingTimeOffsetMilliseconds );
      RequestSendingIntervalMilliseconds = ::std::move( source.RequestSendingIntervalMilliseconds );
   }

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTcpRequestConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
