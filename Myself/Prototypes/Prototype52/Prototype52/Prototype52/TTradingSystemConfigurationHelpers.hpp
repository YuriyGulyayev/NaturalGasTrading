#pragma once

#include "./TTradingSystemConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   //

   class TTradingSystemConfigurationHelpers abstract sealed
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
         ( TTradingSystemConfiguration & tradingSystemConfiguration1,
           ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
         );

#endif
#if( /* {public ExtractConfigurations}. */ 1 )

      // This method does not validate the configuration.
      // yg? This method can be implemented more generically.

      public: static void ExtractConfigurations
         ( ::std::vector< ::std::unique_ptr< TTradingSystemConfiguration > > & tradingSystemsConfiguration1,
           ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
         );

#endif
   };
}
