#pragma once

#include "./TPeerMessageSenderConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   //

   class TPeerMessageSenderConfigurationHelpers abstract sealed
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
         ( TPeerMessageSenderConfiguration & peerMessageSenderConfiguration1,
           ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
         );

#endif
   };
}
