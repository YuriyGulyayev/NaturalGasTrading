#pragma once

#include "./TStrategyBaseConfiguration.hpp"
#include "./TStrategyTypeCode.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // See the config file for more info.

   class TStrategyFactoryConfiguration
   {
#if( /* {public DataTypeCode}. */ 1 )

      //
      public: TStrategyTypeCode DataTypeCode;

#endif
#if( /* {public DataTypeConfiguration}. */ 1 )

      //
      public: ::std::unique_ptr< TStrategyBaseConfiguration > DataTypeConfiguration;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TStrategyFactoryConfiguration();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TStrategyFactoryConfiguration
         ( TStrategyFactoryConfiguration const & source
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TStrategyFactoryConfiguration & operator =
         ( TStrategyFactoryConfiguration const & source
         );

#endif

#if( /* {public Validate}. */ 1 )

      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.

      public: void Validate() const;

#endif
   };
}
