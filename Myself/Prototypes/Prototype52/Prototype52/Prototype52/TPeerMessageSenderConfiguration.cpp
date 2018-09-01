#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPeerMessageSenderConfiguration.hpp"

#include "./TPeerConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPeerMessageSenderConfiguration::TPeerMessageSenderConfiguration()
   {
      // This method is inline.
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* //{public} Instance move constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //TPeerMessageSenderConfiguration::TPeerMessageSenderConfiguration
   //   ( TPeerMessageSenderConfiguration && source
   //   ) :
   //   PeersConfiguration( ::std::move( source.PeersConfiguration ) )
   //{
   //   // yg? Consider making this method inline.
   //}

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* //{public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline TPeerMessageSenderConfiguration & TPeerMessageSenderConfiguration::operator =
   //   ( TPeerMessageSenderConfiguration && source
   //   )
   //{
   //   // yg? Consider making this method inline.
   //   // This implementation will survive a self-assignment.
   //   >>>remove this comment>>>// Some {::std::move} are commented out to ensure and/or make it clear that data will not be corrupt during a self-assignment.
//>>> If I uncomment this I'll need to add the {Assign} method and call it from here.
   //
   ////   PeersConfiguration = ::std::move( source.PeersConfiguration );
   //   return ( * this );
   //}

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerMessageSenderConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
