#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TSocketNextDynamicPortNumberAdvancerConfigurationHelpers.hpp"

#include "./TSocketNextDynamicPortNumberAdvancerConfiguration.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Networking
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

   void TSocketNextDynamicPortNumberAdvancerConfigurationHelpers::ExtractConfiguration
      ( TSocketNextDynamicPortNumberAdvancerConfiguration & socketNextDynamicPortNumberAdvancerConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "NumberSocketNextDynamicPortNumberIncrements" );
         socketNextDynamicPortNumberAdvancerConfiguration1.NumberSocketNextDynamicPortNumberIncrements =
            abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
}
}
