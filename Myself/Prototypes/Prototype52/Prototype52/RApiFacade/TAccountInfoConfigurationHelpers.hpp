#pragma once

#include "./TAccountInfoConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   //

   class TAccountInfoConfigurationHelpers abstract sealed
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

      // This method does not validate the configuration. (In fact this is not needed.)

      public: static void ExtractConfiguration
         ( TAccountInfoConfiguration & accountInfoConfiguration1,
           ::RApi::AccountInfo const & accountInfo1
         );

#endif
   };
}
