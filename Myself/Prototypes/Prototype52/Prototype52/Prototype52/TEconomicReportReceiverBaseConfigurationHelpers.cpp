#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportReceiverBaseConfigurationHelpers.hpp"

#include "./TEconomicReportReceiverBaseConfiguration.cpp"

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

   void TEconomicReportReceiverBaseConfigurationHelpers::ExtractConfiguration
      ( TEconomicReportReceiverBaseConfiguration & economicReportReceiverBaseConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "WarmUpStepInterval1Milliseconds" );
         economicReportReceiverBaseConfiguration1.WarmUpStepInterval1Milliseconds =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "WarmUpStepInterval2Milliseconds" );
         economicReportReceiverBaseConfiguration1.WarmUpStepInterval2Milliseconds =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "WarmUpStageEndTimeOffsetMilliseconds" );
         economicReportReceiverBaseConfiguration1.WarmUpStageEndTimeOffsetMilliseconds =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "InvocationTimeOffsetMilliseconds" );
         economicReportReceiverBaseConfiguration1.InvocationTimeOffsetMilliseconds =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "EconomicReportReceptionTimeoutTimeSpanMilliseconds" );
         economicReportReceiverBaseConfiguration1.EconomicReportReceptionTimeoutTimeSpanMilliseconds =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
}
