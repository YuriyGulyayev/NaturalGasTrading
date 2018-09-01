#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPeerConfiguration.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPeerConfiguration::TPeerConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance move constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPeerConfiguration::TPeerConfiguration
      ( TPeerConfiguration && source
      ) :
      Id( ::std::move( source.Id ) ),
      PeerIPHostName( ::std::move( source.PeerIPHostName ) ),
      PeerIPPortNumber( ::std::move( source.PeerIPPortNumber ) ),
      LocalIPHostName( ::std::move( source.LocalIPHostName ) )
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

   inline TPeerConfiguration & TPeerConfiguration::operator =
      ( TPeerConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerConfiguration::Assign
      ( TPeerConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      Id = ::std::move( source.Id );
      PeerIPHostName.assign( ::std::move( source.PeerIPHostName ) );
      PeerIPPortNumber = ::std::move( source.PeerIPPortNumber );
      LocalIPHostName.assign( ::std::move( source.LocalIPHostName ) );
   }

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
