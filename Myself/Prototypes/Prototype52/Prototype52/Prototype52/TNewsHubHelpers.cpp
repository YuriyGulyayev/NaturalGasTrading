#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TNewsHubHelpers.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public ClientHeartBeatMessageTextAsArray}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TNewsHubHelpers::ClientHeartBeatMessageTextAsArray[]( "NC|HB|0012|23:59:59 ET|" );

   inline void TNewsHubHelpers::ClientHeartBeatMessageTextStaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ClientHeartBeatMessageTextLength ) == ( sizeof( ClientHeartBeatMessageTextAsArray ) / sizeof( ClientHeartBeatMessageTextAsArray[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {public NewsFeedAdapterHeartBeatMessageTextAsArray}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TNewsHubHelpers::NewsFeedAdapterHeartBeatMessageTextAsArray[]
      ( "DE|HB|0012|23:59:59 ET|"
        "DE|AV|0016|0|WarmUp|-091|7|"
      );

   inline void TNewsHubHelpers::NewsFeedAdapterHeartBeatMessageTextStaticAssertion()
   {
      static_assert( static_cast< unsigned int >( NewsFeedAdapterHeartBeatMessageTextLength ) == ( sizeof( NewsFeedAdapterHeartBeatMessageTextAsArray ) / sizeof( NewsFeedAdapterHeartBeatMessageTextAsArray[ 0U ] ) - 1U ), "" );
   }

#endif

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
}
