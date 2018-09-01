#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPrimaryPeerStrategyPositionConfiguration.hpp"

#include "./TSecondaryPeerStrategyPositionConfiguration.cpp"
#include "./TPreEntryOrdersSendingProtectionConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPrimaryPeerStrategyPositionConfiguration::TPrimaryPeerStrategyPositionConfiguration()
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance move constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPrimaryPeerStrategyPositionConfiguration::TPrimaryPeerStrategyPositionConfiguration
      ( TPrimaryPeerStrategyPositionConfiguration && source
      ) :
      TSecondaryPeerStrategyPositionConfiguration( ::std::move( source ) ),
      PreEntryOrdersSendingProtectionConfiguration( ::std::move( source.PreEntryOrdersSendingProtectionConfiguration ) )
   {
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPrimaryPeerStrategyPositionConfiguration & TPrimaryPeerStrategyPositionConfiguration::operator =
      ( TPrimaryPeerStrategyPositionConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPrimaryPeerStrategyPositionConfiguration::Assign
      ( TPrimaryPeerStrategyPositionConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      TSecondaryPeerStrategyPositionConfiguration::Assign( ::std::move( source ) );

      PreEntryOrdersSendingProtectionConfiguration.Assign( ::std::move( source.PreEntryOrdersSendingProtectionConfiguration ) );
   }

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPrimaryPeerStrategyPositionConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
