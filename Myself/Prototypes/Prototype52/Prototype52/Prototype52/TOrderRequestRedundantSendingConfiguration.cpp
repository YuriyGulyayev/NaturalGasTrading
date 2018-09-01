#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TOrderRequestRedundantSendingConfiguration.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TOrderRequestRedundantSendingConfiguration::TOrderRequestRedundantSendingConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance move constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TOrderRequestRedundantSendingConfiguration::TOrderRequestRedundantSendingConfiguration
      ( TOrderRequestRedundantSendingConfiguration && source
      ) :
      PeersId( ::std::move( source.PeersId ) )
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

   inline TOrderRequestRedundantSendingConfiguration & TOrderRequestRedundantSendingConfiguration::operator =
      ( TOrderRequestRedundantSendingConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TOrderRequestRedundantSendingConfiguration::Assign
      ( TOrderRequestRedundantSendingConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      PeersId.assign( ::std::move( source.PeersId ) );
   }

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TOrderRequestRedundantSendingConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
