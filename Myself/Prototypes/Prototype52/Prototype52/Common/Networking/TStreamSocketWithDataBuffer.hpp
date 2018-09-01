#pragma once

#include "../DataStructures/TDataBuffer.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace Networking
{
   // yg? The copy constructor and copy assignment operator in this and derived classes should be declared explicitly
   // yg? but I preserved the POCO code pattern.
   // yg? Consider making this a template with both base class and the {...::SocketImpl} class being template parameters.
   // yg? This class doesn't currently use rvalue references. It doesn't have a {Swap} method either.
#if( POCO_VERSION != 0x01040601 )
   #error yg?? Revisit the above comments. Check if they refactored their code.
#endif

   class TStreamSocketWithDataBuffer :
      public ::Poco::Net::StreamSocket
   {
#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TStreamSocketWithDataBuffer();

#endif
#if( /* {(public)} Instance copy constructor. */ 1 )

      // Could be autogenerated.
      // If {impl()} in the source object is not a {TStreamSocketWithDataBufferImpl} the behavior will be (very) incorrect.

#endif
#if( /* {public} Instance constructor. */ 1 )

      // If {socket1.impl()} is not a {TStreamSocketWithDataBufferImpl} the behavior will be (very) incorrect.

      public: explicit TStreamSocketWithDataBuffer
         ( ::Poco::Net::Socket const & socket1
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      // If {socketImpl1} is not a {TStreamSocketWithDataBufferImpl} the behavior will be (very) incorrect.

      public: explicit TStreamSocketWithDataBuffer
         ( ::Poco::Net::SocketImpl * socketImpl1
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TStreamSocketWithDataBuffer
         ( ::Poco::Net::IPAddress::Family ipAddressFamilyCode
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // {virtual}.

#endif
#if( /* {(public) operator =}. */ 1 )

      // Could be autogenerated.
      // The copy assignment operator accepting a {::Poco::Net::StreamSocket} is also inherited.
      // The copy assignment operator accepting a {::Poco::Net::Socket} is also inherited.
      // If {impl()} in the source object is not a {TStreamSocketWithDataBufferImpl} the behavior will be (very) incorrect.

#endif

#if( /* {public bind}. */ 1 )

      // yg? They forgot to add this method to the base class, probably intentionally.
   #if( POCO_VERSION != 0x01040601 )
      #error yg?? Check if they added this method.
   #endif
      // TODO 3 yg? This might be an alternative to binding but it doesn't appear to work:
      // TODO 3 yg? { datagramSocket1.setOption( IPPROTO_IP, IP_UNICAST_IF, sender3SocketAddress.host() ); }
   
      public: /*virtual*/ void bind
         ( ::Poco::Net::SocketAddress const & address,
           bool reuseAddress //= false
         );

#endif

#if( /* {public DataBuffer}. */ 1 )

      //
      
      public: DataStructures::TDataBuffer & DataBuffer();

#endif
#if( /* {public DataBuffer}. */ 1 )

      //
      
      public: DataStructures::TDataBuffer const & DataBuffer() const;

#endif
#if( /* {public DataBufferCapacityMaxLimit}. */ 1 )

      //
      
      public: DataStructures::TDataBuffer::size_type & DataBufferCapacityMaxLimit();

#endif
#if( /* {public DataBufferCapacityMaxLimit}. */ 1 )

      //
      
      public: DataStructures::TDataBuffer::size_type const & DataBufferCapacityMaxLimit() const;

#endif

#if( /* {public ReceiveBytesIntoDataBuffer}. */ 1 )

      //
      
      public: int ReceiveBytesIntoDataBuffer
         ( int flags1
         );

#endif
#if( /* //{public ReceiveAllBytesIntoDataBuffer}. */ 1 )

      ////
      //
      //public: void ReceiveAllBytesIntoDataBuffer
      //   ( int flags1
      //   );

#endif
#if( /* //{public ReceiveAnyBytesIntoDataBuffer}. */ 1 )

      ////
      //
      //public: void ReceiveAnyBytesIntoDataBuffer
      //   ( int flags1
      //   );

#endif
#if( /* //{public ReceiveAnyBytesIntoDataBufferUntilWouldBlock}. */ 1 )

      ////
      //
      //public: void ReceiveAnyBytesIntoDataBufferUntilWouldBlock
      //   ( int flags1
      //   );

#endif
   };
}
}