#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPrimaryPeerStrategyPositionConfigurationHelpers.hpp"

#include "./TPrimaryPeerStrategyPositionConfiguration.cpp"
#include "./TPreEntryOrdersSendingProtectionConfigurationHelpers.cpp"
#include "./TSecondaryPeerStrategyPositionConfigurationHelpers.cpp"

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

   void TPrimaryPeerStrategyPositionConfigurationHelpers::ExtractConfiguration
      ( TPrimaryPeerStrategyPositionConfiguration & primaryPeerStrategyPositionConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      TSecondaryPeerStrategyPositionConfigurationHelpers::ExtractConfiguration
         ( primaryPeerStrategyPositionConfiguration1, abstractConfiguration1 );

      {
         static char const parameter1NameAsArray[]( "PreEntryOrdersSendingProtectionConfiguration" );
      
         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );
      
         TPreEntryOrdersSendingProtectionConfigurationHelpers::ExtractConfiguration
            ( primaryPeerStrategyPositionConfiguration1.PreEntryOrdersSendingProtectionConfiguration,
              ( * abstractConfiguration1View1 )
            );
      }
   }

#endif
}
