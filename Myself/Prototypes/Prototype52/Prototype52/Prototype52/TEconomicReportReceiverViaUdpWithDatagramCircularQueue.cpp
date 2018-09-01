#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportReceiverViaUdpWithDatagramCircularQueue.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TEconomicReportReceiverViaUdp_
      >
   inline TEconomicReportReceiverViaUdpWithDatagramCircularQueue< TEconomicReportReceiverViaUdp_ >::TEconomicReportReceiverViaUdpWithDatagramCircularQueue()
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TEconomicReportReceiverViaUdp_
      >
   template
      < typename TEconomicReportReceiverViaUdpConfiguration_
      >
   inline TEconomicReportReceiverViaUdpWithDatagramCircularQueue< TEconomicReportReceiverViaUdp_ >::TEconomicReportReceiverViaUdpWithDatagramCircularQueue
      ( TEconomicReportReceiverViaUdpConfiguration_ && configuration1
      ) :
      TEconomicReportReceiverViaUdp_( ::std::move( configuration1 ) )
   {
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and inline.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {protected ConfigureSocket}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TEconomicReportReceiverViaUdp_
      >
   inline void TEconomicReportReceiverViaUdpWithDatagramCircularQueue< TEconomicReportReceiverViaUdp_ >::ConfigureSocket()
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {Socket_.impl()->ioctl}.
      //       Call.
      //    {ConfigureSocket} -- base.
      //       Override, call.

      TEconomicReportReceiverViaUdp_::ConfigureSocket();

      {
         int int1( 1 );

         // yg? MSDN library says that we shall call {::WSAIoctl} to set this opcode but {::ioctlsocket} appears to succeed.
         // yg? Revisit this on Linux.
         Socket_.impl()->ioctl( SIO_ENABLE_CIRCULAR_QUEUEING, int1 );
      }
   }

#endif
}
