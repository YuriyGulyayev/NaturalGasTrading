#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPeerMessageSender.hpp"

#include "../Common/DataStructures/TPair.cpp"
#include "./TPeerMessageSenderConfiguration.cpp"
#include "../Common/Diagnostics/Macros.cpp"
#include "../Common/Diagnostics/TDiagnosticsHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPeerMessageSender::TPeerMessageSender()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPeerMessageSender::TPeerMessageSender
      ( TPeerMessageSenderConfiguration && configuration1
      ) :
      PeersConfiguration_( ::std::move( configuration1.PeersConfiguration ) )
   {
      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerMessageSender::Initialize
      ( TPeerMessageSenderConfiguration && configuration1
      )
   {
      // This method is inline.

      PeersConfiguration_ = ::std::move( configuration1.PeersConfiguration );

      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerMessageSender::DoInitialize
      ( //TPeerMessageSenderConfiguration && configuration1
      )
   {
// TODO 2 yg? Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
// TODO 2 yg? Refer to it from consrtructors, destructors, {Initialize}.

      // This method is inline.
   }

#endif
#if( /* {public Prepare}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerMessageSender::Prepare()
   {
      // Visible universe.
      //    {UDP_NOCHECKSUM}.
      //       Use.
      //    {PeersConfiguration_}.
      //       Enumerate, release resources.
      //    {PeersConfiguration_[].Id}.
      //       Use.
      //    {PeersConfiguration_[].PeerIPHostName}.
      //       Use.
      //    {PeersConfiguration_[].PeerIPPortNumber}.
      //       Use.
      //    {PeersConfiguration_[].LocalIPHostName}.
      //       Use.
      //    {Sockets_}.
      //       Populate.
      //    {Sockets_[].Value1}.
      //       Update.
      //    {Sockets_[].Value2.bind}.
      //       Call.
      //    {Sockets_[].Value2.connect}.
      //       Call.
      //    {Sockets_[].Value2.setOption}.
      //       Call.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Sockets_.empty() );

      // {::Poco::Net::DatagramSocket} default constructor assumes {::Poco::Net::IPAddress::Family::IPv4}
      // and creates a socket handle.
      // This creates all socket objects at once but it might be more correct to create and configure each socket one-after-another.
      // It's not too bad.
      Sockets_.resize( PeersConfiguration_.size() );

      // I've seen some resizing replicating a default-constructed item by move-constructing the others.
      // {::std::string} might actually do that and not {::std::vector<>}.
      // Validating that it didn't happen this time.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( Sockets_.size() < 2U || Sockets_.at( 0U ).Value2.impl() != Sockets_.at( Sockets_.size() - 1U ).Value2.impl() );

      {
         ::std::vector< ::Common::DataStructures::TPair< char, ::Poco::Net::DatagramSocket > >::iterator socketsIterator
            ( Sockets_.begin() );
      
         // This iterator can't be const as we release some resources.
         for( ::std::vector< TPeerConfiguration >::iterator peersConfigurationIterator( PeersConfiguration_.begin() ) ;
                peersConfigurationIterator != PeersConfiguration_.end() ;
                ++ peersConfigurationIterator ,
                ++ socketsIterator
             )

         {
            // We probably don't need to set send timeout.
            {
               //::Poco::Net::DatagramSocket socket1( ::Poco::Net::IPAddress::Family::IPv4 );

               // We don't need a checksum as we have our own.
               // yg? But this is probably not a good thing for NewsHub.
               // This option is not supported for IPv6.
               // TODO 3 yg? There is another option named {UDP_CHECKSUM_COVERAGE} but it doesn't appear to work on Windows 7.
               // TODO 3 yg? Is it supported for either IPv4 or IPv6?
               // yg? Does one or another work on Linux?
               //socket1.setOption( IPPROTO_UDP, UDP_NOCHECKSUM, 1 );
               socketsIterator->Value2.setOption( IPPROTO_UDP, UDP_NOCHECKSUM, 1 );

               if( ! peersConfigurationIterator->LocalIPHostName.empty() )
               {
                  // IP address resolutin takes time and can throw an exception, which is why this code must run on application start.
                  // We could try to repeat the resolution attempt but keeping it simple.
                  // We will not resolve the IP addresses any more, no matter for how long the application runs.
                  //// Releasing the resources we don't need any more.
                  // Actually not releasing the resources any more as we will release them momentarily anyway
                  // and we don't need a lower performance and possible memory fragmentation.
                  ::Poco::Net::SocketAddress socketAddress1
                     //( ::std::string( ::std::move( peersConfigurationIterator->LocalIPHostName ) ),
                     ( peersConfigurationIterator->LocalIPHostName,
                       static_cast< unsigned short >( 0U )
                     );

                  //socket1.bind( socketAddress1, false );
                  socketsIterator->Value2.bind( socketAddress1, false );
               }
               else

               // --no longer relevant-- Here we don't move {peersConfigurationIterator->LocalIPHostName}. A moving would probably not release any memory anyway.
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }

               {
                  // Same comments as above apply.
                  ::Poco::Net::SocketAddress socketAddress1
                     //( ::std::string( ::std::move( peersConfigurationIterator->PeerIPHostName ) ),
                     ( peersConfigurationIterator->PeerIPHostName,
                       peersConfigurationIterator->PeerIPPortNumber
                     );

                  // This only establishes a default destination address. But this can still throw an exception
                  // if the network or host is unreachable, which implies that since this socket is blocking
                  // this operation is not necessarily instant.
                  // It could be possible that a temporary network outage or other change or a send error will break this connection.
                  // It would be nice to try to reconnect then, ideally after completing time sensitive actions, but keeping it simple.
                  // To reduce the time we stay "connected" we can connect right before economic report release
                  // but then we would have to handle exceptions.
                  // If this actually established a connection it would be incorrect to do it in the {Prepare} method.
                  //socket1.connect( socketAddress1 );
                  socketsIterator->Value2.connect( socketAddress1 );
               }

               //// yg? This is actually copying rather than moving. I don't want to code proper moving.
               //socketsIterator->Value1 = ::std::move( socket1 );
            }

            socketsIterator->Value1 = peersConfigurationIterator->Id;
         }
      }

      {
         // Releasing the resources we don't need any more.
         ::std::vector< TPeerConfiguration > dummy1( ::std::move( PeersConfiguration_ ) );
      }
   }

#endif

#if( /* {public TrySendPeerMessage}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerMessageSender::TrySendPeerMessage
      ( char const * peerMessage,
        int peerMessageLength
      )
   {
      // See comments in the other overload.

      // Visible universe.
      //    {Sockets_}.
      //       Enumerate.
      //    {Sockets_[].Value2.sendBytes}.
      //       Call.

      for( ::std::vector< ::Common::DataStructures::TPair< char, ::Poco::Net::DatagramSocket > >::iterator socketsIterator
                ( Sockets_.begin() ) ;
             ;
             ++ socketsIterator
          )
      {
         try
         {
            for( ; socketsIterator != Sockets_.end() ; ++ socketsIterator )
            {
               socketsIterator->Value2.sendBytes( reinterpret_cast< void const * >( peerMessage ), peerMessageLength, 0 );
            }
         }
         catch( ::Poco::Exception const & exception1 )
         {
            {
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
               logger1.log( exception1 );
            }

            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            continue;
         }

         break;
      }
   }

#endif
#if( /* {public TrySendPeerMessage}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerMessageSender::TrySendPeerMessage
      ( char const * peerMessage,
        int peerMessageLength,
        char peerIdToSkip
      )
   {
      // Visible universe.
      //    {Sockets_}.
      //       Enumerate.
      //    {Sockets_[].Value1}.
      //       Use.
      //    {Sockets_[].Value2.sendBytes}.
      //       Call.

      for( ::std::vector< ::Common::DataStructures::TPair< char, ::Poco::Net::DatagramSocket > >::iterator socketsIterator
                ( Sockets_.begin() ) ;
             ;
             ++ socketsIterator
          )
      {
         try
         {
            for( ; socketsIterator != Sockets_.end() ; ++ socketsIterator )
            {
               if( socketsIterator->Value1 != peerIdToSkip )
               {
                  // One might want to check if we sent a different number of bytes than we wanted to, but keeping it simple.
                  // The recipient will validate this anyway. Although NewsHub will not, but this probably won't send a shorter datagram.
                  // An alternative would be to call {::Common::Networking::TNetworkingHelpers::SendBytesIntoSocket}.
                  // But I really believe that since this socket is blocking all bytes will be sent.
                  // Although this behavior might vary from OS to OS.
                  socketsIterator->Value2.sendBytes( reinterpret_cast< void const * >( peerMessage ), peerMessageLength, 0 );
               }
               else
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
            }
         }

         // To recover from a send error we can next time send data to this peer even if it's "unimportant" but we were called to
         // send data to only "important" peers. But this logic would need to be skipped when sending warm-up data.
         // In case of an error it might be a good idea to create and configure a new socket and on success close the old socket but
         // this logic would be undesitable at a performance critical moment.
         // But keeping it simple.
         // Catching only POCO exceptions. Assuming this exception is not critical.
         catch( ::Poco::Exception const & exception1 )

         {
            {
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
               logger1.log( exception1 );
            }

            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            continue;
         }

         break;
      }
   }

#endif
}
