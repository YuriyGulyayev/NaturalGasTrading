#pragma once

// TODO 1 yg? Remove this file.

#if 0

#include "./TStrategyConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   //

   class TStrategyConfigurationHelpers abstract sealed
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
         ( TStrategyConfiguration & strategyConfiguration1,
           ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
         );

#endif
   };
}

#endif