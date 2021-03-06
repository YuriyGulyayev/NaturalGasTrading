#pragma once

#include "../RApiFacade/TREngineAdapterConfiguration.hpp"
#include "./TStrategyFactoryConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // See the config file for more info.

   class TTradingSystemConfiguration
   {
#if( /* {public REngineAdapterConfiguration}. */ 1 )

      //
      public: ::RApiFacade::TREngineAdapterConfiguration REngineAdapterConfiguration;

#endif
#if( /* {public StrategyFactoryConfiguration}. */ 1 )

      //
      public: TStrategyFactoryConfiguration StrategyFactoryConfiguration;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TTradingSystemConfiguration();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TTradingSystemConfiguration
         ( TTradingSystemConfiguration const & source
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TTradingSystemConfiguration & operator =
         ( TTradingSystemConfiguration const & source
         );

#endif

#if( /* {public Validate}. */ 1 )

      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.

      public: void Validate() const;

#endif
   };
}
