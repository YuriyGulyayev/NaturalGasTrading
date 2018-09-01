#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportReceiverViaUdpConfigurationHelpers.hpp"

#include "./TEconomicReportReceiverViaUdpConfiguration.cpp"
#include "./TEconomicReportReceiverBaseConfigurationHelpers.cpp"

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

   void TEconomicReportReceiverViaUdpConfigurationHelpers::ExtractConfiguration
      ( TEconomicReportReceiverViaUdpConfiguration & economicReportReceiverViaUdpConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      TEconomicReportReceiverBaseConfigurationHelpers::ExtractConfiguration
         ( economicReportReceiverViaUdpConfiguration1, abstractConfiguration1 );

      {
         static char const parameter1NameAsArray[]( "LocalIPPortNumber" );

         // yg? There is no such thing as {getUInt16}.
         // yg? Assuming this will not overflow. But it would be nice to validate this.
         economicReportReceiverViaUdpConfiguration1.LocalIPPortNumber =
            static_cast< unsigned short >
               ( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
   }

#endif
}
