#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TNetworkingHelpers.hpp"

#include "../DataStructures/TUnionPair.cpp"
//#include "../ErrorHandling/TCriticalErrorException.cpp"
#include "../ErrorHandling/TRegularErrorException.cpp"
#include "../Diagnostics/Macros.cpp"
#include "../Diagnostics/TDiagnosticsHelpers.cpp"
#include "../Threading/TMemoryAtomicOperationsHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Networking
{
#if( /* {public WildcardIPAddress}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   ::Poco::Net::IPAddress const TNetworkingHelpers::WildcardIPAddress;

#endif
#if( /* {public WildcardIPSocketAddress}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   ::Poco::Net::SocketAddress const TNetworkingHelpers::WildcardIPSocketAddress
      ( WildcardIPAddress, static_cast< unsigned short >( 0U ) );

#endif

#if( /* {private SocketHandleToWaitOn_}. */ defined( _MSC_VER ) && 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   DataStructures::TUnionPair< ::SOCKET, void * > TNetworkingHelpers::SocketHandleToWaitOn_ = { INVALID_SOCKET };

#endif

#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public SleepMicrosecondsWithSelect}. */ defined( _MSC_VER ) && 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNetworkingHelpers::SleepMicrosecondsWithSelect
      ( long timeSpanMicroseconds
      )
   {
      if( timeSpanMicroseconds > 0 )
      {
         DoSleepMicrosecondsWithSelect( timeSpanMicroseconds );
      }
      else
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
   }

#endif
#if( /* {public DoSleepMicrosecondsWithSelect}. */ defined( _MSC_VER ) && 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TNetworkingHelpers::DoSleepMicrosecondsWithSelect
      ( long timeSpanMicroseconds
      )
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( timeSpanMicroseconds > 0 );
      ::timeval timeval1 = { 0, timeSpanMicroseconds };
      for( ; ; )
      {
         ::fd_set fdSet1;
         FD_ZERO( & fdSet1 );
         DataStructures::TUnionPair< ::SOCKET, void * > socketHandle1( SocketHandleToWaitOn_ );
         FD_SET( socketHandle1.Value1, ( & fdSet1 ) );

   // Commented out to make it possible to run debug build on Windows XP.
   //#if( ! defined( NDEBUG ) )
   //      ::ULONGLONG unbiasedInterruptTime1;
   //      assert( ::QueryUnbiasedInterruptTime( & unbiasedInterruptTime1 ) != FALSE );
   //#endif

         // Selecting for writing could be more correct or efficient but it doesn't work for a UDP socket.
         int outcomeCode1( ::select( 0, ( & fdSet1 ), nullptr, nullptr, ( & timeval1 ) ) );

         if( outcomeCode1 == 0 )
         {
   // Commented out to make it possible to run debug build on Windows XP.
   //#if( ! defined( NDEBUG ) )
   //         ::ULONGLONG unbiasedInterruptTime2;
   //         assert( ::QueryUnbiasedInterruptTime( & unbiasedInterruptTime2 ) != FALSE );
   //         assert( unbiasedInterruptTime1 < unbiasedInterruptTime2 );
   //#endif

            break;
         }
         if( socketHandle1.Value1 != INVALID_SOCKET )
         {
            Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

            {
               static char const constantString1AsArray[]( "Critical; {select} failed" );

               // yg? Considering this error critical. We might need to handle some errors here and either throw a non-critical exception or retry.
               // TODO 3 yg? Call {::WSAGetLastError} and addd the result to exception.
               throw ErrorHandling::TCriticalErrorException
                            ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                              outcomeCode1
                            );
            }
         }

         //socketHandle1.Value1 = ::socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
         socketHandle1.Value1 = ::socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );

         if( socketHandle1.Value1 == INVALID_SOCKET )
         {
            Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            
            {
               static char const constantString1AsArray[]( "Critical; {socket} failed" );

               // yg? Considering this error critical. We might need to handle some errors here and either throw a non-critical exception or retry.
               // TODO 3 yg? Call {::WSAGetLastError} and addd the result to exception.
               throw ErrorHandling::TCriticalErrorException
                            ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                              0
                            );
            }
         }

         // yg? If this throws an exception the socket will not be closed.
         if( Threading::TMemoryAtomicOperationsHelpers::GetAndSetValueIfEqualsWithoutMemoryBarrier( SocketHandleToWaitOn_.Value2, socketHandle1.Value2, reinterpret_cast< void * >( INVALID_SOCKET ) ) != reinterpret_cast< void * >( INVALID_SOCKET ) )

         {
            // Ignoring return value. This probably always succeeds.
            ::closesocket( socketHandle1.Value1 );
         }
      }
   }

#endif

#if( /* {public AddSocketAddressesFromUrls}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TUrlAsStringContainer_,
        ::std::string TUrlAsStringContainer_::*urlAsStringContainer1UrlAsStringPointerToMember,
        typename TUrlAsStringContainer1CollectionIterator_
      >
   inline void TNetworkingHelpers::AddSocketAddressesFromUrls
      ( ::std::vector< ::Poco::Net::SocketAddress > & socketAddresses1,
        TUrlAsStringContainer1CollectionIterator_ urlAsStringContainers1BeginIterator1,
        TUrlAsStringContainer1CollectionIterator_ urlAsStringContainers1EndIterator1
      )
   {
      // Assuming this will not overflow.
      TUrlAsStringContainer1CollectionIterator_::difference_type numberUrlAsStringContainers1( urlAsStringContainers1EndIterator1 - urlAsStringContainers1BeginIterator1 );

      // yg? Not assuming this.
      // yg? Actually why didn't I want to assume this?
      //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberUrlAsStringContainers1 >= 0 );
      assert( numberUrlAsStringContainers1 >= 0 );

      // Assuming this will not overflow.
      socketAddresses1.reserve( socketAddresses1.size() + static_cast< ::std::vector< ::Poco::Net::SocketAddress >::size_type >( numberUrlAsStringContainers1 ) );

      for( ; urlAsStringContainers1BeginIterator1 != urlAsStringContainers1EndIterator1 ; ++ urlAsStringContainers1BeginIterator1 )
      {
         // yg? {::Poco::URI} decodes/corrupts special chars and can have other issues. Consider parsing the URL with a regular expression.
         // yg? Actually, they fixed some related bugs.
         //::Poco::URI uri1( urlAsStringContainers1BeginIterator1->*urlAsStringContainer1UrlAsStringPointerToMember );
         ::Poco::URI uri1( ( * urlAsStringContainers1BeginIterator1 ).*urlAsStringContainer1UrlAsStringPointerToMember );

         //// This will throw an exception if host IP address resolutin fails.
         //::Poco::Net::SocketAddress uri1SocketAddress1( uri1.getHost(), uri1.getPort() );
         //
         //// Adding an item only after IP address resolution succeeds.
         //// But if an exception is thrown later any newly added items will stay in the collection.
         //{
         //   // Assuming this will not overflow.
         //   //socketAddresses1.resize( socketAddresses1.size() + 1U );
         //
         //   // yg? This doesn't have a move assignment operator.
         //   // yg? Do we really need {::std::move} here?
         //   //socketAddresses1.back().swap( ::std::move( uri1SocketAddress1 ) );
         //
         //   // This is more efficient than the above commented out {resize}+{swap}.
         //   // yg? This is actually copying rather than moving. I don't want to code proper moving.
         //   socketAddresses1.push_back( ::std::move( uri1SocketAddress1 ) );
         //}

         // This will throw an exception if host IP address resolutin fails.
         // Adding an item only after IP address resolution succeeds.
         // But if an exception is thrown later any newly added items will stay in the collection.
         // Unnamed objects -- move semantics.
         // yg? This is actually copying rather than moving. I don't want to code proper moving.
         socketAddresses1.push_back( ::Poco::Net::SocketAddress( uri1.getHost(), uri1.getPort() ) );
      }
   }


   // yg? Old version. To be revisited.
   //
   //template
   //   < //typename TUrlAsStringIterator1 <<<this should end with a {_}.
   //      typename TUrlAsStringContainerIterator1, <<<this should end with a {_}.
   //      typename TPointerToUrlAsStringContainerUrlAsStringMember1 <<<this should end with a {_}.
   //   >
   //inline void TNetworkingHelpers::AddSocketAddressesFromUrls
   //   ( ::std::vector< ::Poco::Net::SocketAddress > & socketAddresses1,
   //     //TUrlAsStringIterator1 urlAsStringIterator1,
   //     TUrlAsStringContainerIterator1 urlAsStringContainerIterator1,
   //     int numberUrlAsStringContainers1,
   //     TPointerToUrlAsStringContainerUrlAsStringMember1 pointerToUrlAsStringContainerUrlAsStringMember1
   //   )
   //{
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberUrlAsStringContainers1 >= 0 );
   //
   //   // Assuming this will not overflow.
   //   socketAddresses1.reserve( socketAddresses1.size() + static_cast< unsigned int >( numberUrlAsStringContainers1 ) );
   //
   //   while( ( -- numberUrlAsStringContainers1 ) >= 0 )
   //   {
   //      // yg? {::Poco::URI} decodes/corrupts special chars and can have other issues. Consider parsing the URL with a regular expression.
   //      // yg? Actually, they fixed some related bugs.
   //      //::Poco::URI uri1( urlAsStringContainerIterator1->*pointerToUrlAsStringContainerUrlAsStringMember1 );
   //      ::Poco::URI uri1( ( * urlAsStringContainerIterator1 ).*pointerToUrlAsStringContainerUrlAsStringMember1 );
   //
   //      // This will throw an exception if host IP address resolutin fails.
   //      ::Poco::Net::SocketAddress uri1SocketAddress1( uri1.getHost(), uri1.getPort() );
   //
   //      // Adding an item only after IP address resolution succeeds.
   //      // But if an exception is thrown later any newly added items will stay in the collection.
   //      // Assuming this will not overflow.
   //      socketAddresses1.resize( socketAddresses1.size() + 1U );
   //
   //      // yg? This doesn't have a move assignment operator.
   //      socketAddresses1.back().swap( uri1SocketAddress1 );
   //
   //      ++ urlAsStringContainerIterator1;
   //   }
   //}

#endif
#if( /* {public TrySetSocketKeepAliveMode}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   bool TNetworkingHelpers::TrySetSocketKeepAliveMode
      ( ::Poco::Net::Socket & socket,
        bool keepAliveEnabled
      )
   {
      try
      {
         socket.setKeepAlive( keepAliveEnabled );
      }

      // Catching only POCO exceptions. Assuming this exception is not critical.
      catch( ::Poco::Exception const & exception1 )

      {
         {
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            //logger1.fatal( ">>>1" );
            logger1.warning( exception1.displayText() );
         }

         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         return false;
      }
      return true;
   }

#endif
#if( /* {public SetSocketKeepAliveMode}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TNetworkingHelpers::SetSocketKeepAliveMode
      ( ::poco_socket_t socketHandle,
        bool keepAliveEnabled,
        int keepAliveTimeoutTimeSpanMilliseconds,
        int keepAliveIntervalMilliseconds
      )
   {
   #if( ! defined( _MSC_VER ) )
      #error yg?? ToDo
   #endif

      int wsaIoctlResultCode;
      
      {
         ::tcp_keepalive tcpKeepAlive1;
         tcpKeepAlive1.onoff = static_cast< ::u_long >( keepAliveEnabled );

         // Assuming these will not overflow.
         tcpKeepAlive1.keepalivetime = static_cast< unsigned int >( keepAliveTimeoutTimeSpanMilliseconds );
         tcpKeepAlive1.keepaliveinterval = static_cast< unsigned int >( keepAliveIntervalMilliseconds );

         ::DWORD bytesReturned;
         wsaIoctlResultCode =
            ::WSAIoctl
               ( socketHandle,
                 SIO_KEEPALIVE_VALS,
                 ( & tcpKeepAlive1 ),
                 static_cast< ::DWORD >( sizeof( tcpKeepAlive1 ) ),
                 nullptr,
                 0U,
                 ( & bytesReturned ),
                 nullptr,
                 nullptr
               );
      }

      if( wsaIoctlResultCode == 0 )
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            int wsaLastErrorCode( ::WSAGetLastError() );
            static char const constantString1AsArray[]( "Error; {WSAIoctl(...,SIO_KEEPALIVE_VALS,...)} failed" );

            // yg? Depending on under what conditions this failed and/or {wsaLastErrorCode}, we might want to view this error as recoverable or critical.
            throw ErrorHandling::TRegularErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           wsaLastErrorCode
                         );
         }
      }
   }

#endif
#if( /* {public SelectAnySocketsReadyForReadingHandle}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSocketHandleMap_
      >
   inline int TNetworkingHelpers::SelectAnySocketsReadyForReadingHandle
      ( TSocketHandleMap_ const & socketsHandle,
        ::fd_set & socketsReadyForReadingHandle,
        long timeoutTimeSpanMicroseconds
      )
   {
   #if( ! defined( _MSC_VER ) )
      #error yg?? ToDo
      // yg? Do we need to handle an interruption by a signal?
      // yg? Do we need to use the {::epoll} function? POCO does.
   #endif

      // TODO 3 yg? We really must ensure we will stay within this array bounds. But I don't want any overhead at this point,
      // TODO 3 yg? so the caller must check this in advance.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( socketsHandle.size() <=
           sizeof( socketsReadyForReadingHandle.fd_array ) / sizeof( socketsReadyForReadingHandle.fd_array[ 0U ] )
         );

      // Assuming this will not overflow. It probably can't provided the above validation succeeded.
      socketsReadyForReadingHandle.fd_count = static_cast< ::u_int >( socketsHandle.size() );

      {
         ::poco_socket_t * socketHandlePointer( socketsReadyForReadingHandle.fd_array );
         TSocketHandleMap_::const_iterator socketsHandleEndIterator( socketsHandle.cend() );
         for( TSocketHandleMap_::const_iterator socketsHandleIterator( socketsHandle.cbegin() ) ;
                socketsHandleIterator != socketsHandleEndIterator ;
                ++ socketsHandleIterator,
                ++ socketHandlePointer
             )
         {
            //( * socketHandlePointer ) = sockets1Iterator1->second.impl()->sockfd();
            
            // yg? I don't like this code. Is it possibly to implement it more generically?
            static_assert( sizeof( * socketHandlePointer ) == sizeof( socketsHandleIterator->first ), "" );
            ( * socketHandlePointer ) = socketsHandleIterator->first;
         }
      }

      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( timeoutTimeSpanMicroseconds >= 0 );
         ::timeval timeval1 = { 0, timeoutTimeSpanMicroseconds };

         // TODO 3 yg? Can we use {::WSAPoll}? But its timeout is in ms.
         // yg? The 1st parameter probably matters on Linux. See POCO code.
         int selectResultCode( ::select( 0, ( & socketsReadyForReadingHandle ), nullptr, nullptr, ( & timeval1 ) ) );

         if( selectResultCode >= 0 )
         {
            Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

            {
               int wsaLastErrorCode( ::WSAGetLastError() );
               static char const constantString1AsArray[]( "Critical; {select} failed" );
               throw ErrorHandling::TCriticalErrorException
                            ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                              //selectResultCode
                              wsaLastErrorCode
                            );
            }
         }

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( static_cast< unsigned int >( selectResultCode ) == socketsReadyForReadingHandle.fd_count );
         return selectResultCode;
      }
   }

#endif
#if( /* {public SendBytesIntoSocket}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNetworkingHelpers::SendBytesIntoSocket
      ( ::Poco::Net::Socket & socket,
        char const * bytes,
        int bytesLength,
        int flags
      )
   {
      // The {::Poco::Net::Socket} class doesn't have the {sendBytes} method. Some of its subclasses do
      // and they simply call the same named method on the underlying implementation object.
      // yg? But can this potentially be incorrect?
      int numberBytesSent( socket.impl()->sendBytes( reinterpret_cast< void const * >( bytes ), bytesLength, flags ) );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesSent >= 0 );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesSent <= bytesLength );
      if( numberBytesSent >= bytesLength )
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            // Considering this outcome an unrecoverable error.
            // But labelling it a "Warning", as we normally do when a "normal" communication error occurs.
            static char const constantString1AsArray[]( "Warning; sent fewer bytes into a socket than intended" );

            // Another option would be to throw a {::Poco::TimeoutException} but I don't like it.
            throw ErrorHandling::TRegularErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           0
                         );
         }
      }
   }

#endif
}
}
