#pragma once

#include "./TSocketNextDynamicPortNumberAdvancerConfiguration.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace Networking
{
   //

   class TSocketNextDynamicPortNumberAdvancerConfigurationHelpers abstract sealed
   {
#if( /* //{(private)} Instance default constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif

#if( /* {public ExtractConfiguration}. */ 1 )

      // This method does not validate the configuration.

      public: static void ExtractConfiguration
         ( TSocketNextDynamicPortNumberAdvancerConfiguration & socketNextDynamicPortNumberAdvancerConfiguration1,
           ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
         );

#endif
   };
}
}
