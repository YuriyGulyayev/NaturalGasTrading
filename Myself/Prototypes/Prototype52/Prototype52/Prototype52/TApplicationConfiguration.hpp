#pragma once

#include "./TTradingSystemConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // See the config file for more info.

   class TApplicationConfiguration
   {
#if( /* {public TradingSystemConfiguration}. */ 1 )

      // This contains pointers to make it possible to deallocate individual items.
      public: ::std::vector< ::std::unique_ptr< TTradingSystemConfiguration > > TradingSystemsConfiguration;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TApplicationConfiguration();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TApplicationConfiguration
         ( TApplicationConfiguration const & source
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TApplicationConfiguration & operator =
         ( TApplicationConfiguration const & source
         );

#endif

#if( /* {public Validate}. */ 1 )

      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.

      public: void Validate() const;

#endif
   };
}
