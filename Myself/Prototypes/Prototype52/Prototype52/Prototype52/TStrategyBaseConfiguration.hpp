#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // See the config file for more info.

   class TStrategyBaseConfiguration abstract
   {
#if( /* {protected} Instance default constructor. */ 1 )

      //

      protected: explicit TStrategyBaseConfiguration();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TStrategyBaseConfiguration
         ( TStrategyBaseConfiguration const & source
         );

#endif
#if( /* {public} Instance destructor. */ 1 )

      //

      public: virtual ~TStrategyBaseConfiguration();

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TStrategyBaseConfiguration & operator =
         ( TStrategyBaseConfiguration const & source
         );

#endif

#if( /* {public Validate}. */ 1 )

      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.
      // TODO 3 yg? If I implement this method I will need to make it {virtual}.

      public: void Validate() const;

#endif
   };
}
