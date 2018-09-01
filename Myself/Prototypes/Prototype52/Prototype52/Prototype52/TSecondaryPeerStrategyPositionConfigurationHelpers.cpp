#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TSecondaryPeerStrategyPositionConfigurationHelpers.hpp"

#include "./TSecondaryPeerStrategyPositionConfiguration.cpp"
#include "./TEntryOrderConfigurationHelpers.cpp"

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

   void TSecondaryPeerStrategyPositionConfigurationHelpers::ExtractConfiguration
      ( TSecondaryPeerStrategyPositionConfiguration & secondaryPeerStrategyPositionConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "RelativeDirectionCode" );
         secondaryPeerStrategyPositionConfiguration1.RelativeDirectionCode =
            static_cast< ::Finance::Trading::TPositionDirectionCode >
               ( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "EntryOrdersConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         TEntryOrderConfigurationHelpers::ExtractConfigurations
            ( secondaryPeerStrategyPositionConfiguration1.EntryOrdersConfiguration, ( * abstractConfiguration1View1 ) );
      }
   }

#endif
}
