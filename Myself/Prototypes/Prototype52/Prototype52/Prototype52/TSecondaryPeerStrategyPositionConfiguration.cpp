#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TSecondaryPeerStrategyPositionConfiguration.hpp"

#include "../Finance/Trading/TPositionDirectionCode.cpp"
#include "./TEntryOrderConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TSecondaryPeerStrategyPositionConfiguration::TSecondaryPeerStrategyPositionConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance move constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TSecondaryPeerStrategyPositionConfiguration::TSecondaryPeerStrategyPositionConfiguration
      ( TSecondaryPeerStrategyPositionConfiguration && source
      ) :
      RelativeDirectionCode( ::std::move( source.RelativeDirectionCode ) ),
      EntryOrdersConfiguration( ::std::move( source.EntryOrdersConfiguration ) )
   {
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TSecondaryPeerStrategyPositionConfiguration & TSecondaryPeerStrategyPositionConfiguration::operator =
      ( TSecondaryPeerStrategyPositionConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TSecondaryPeerStrategyPositionConfiguration::Assign
      ( TSecondaryPeerStrategyPositionConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      RelativeDirectionCode = ::std::move( source.RelativeDirectionCode );
      EntryOrdersConfiguration = ::std::move( source.EntryOrdersConfiguration );
   }

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TSecondaryPeerStrategyPositionConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
