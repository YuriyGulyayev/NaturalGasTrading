#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TStreamSocketWithDataBuffer.hpp"

#include "../DataStructures/TDataBuffer.cpp"
#include "./TStreamSocketWithDataBufferImpl.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Networking
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TStreamSocketWithDataBuffer::TStreamSocketWithDataBuffer() :
      ::Poco::Net::StreamSocket( new TStreamSocketWithDataBufferImpl )
   {
   }

#endif
#if( /* {(public)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TStreamSocketWithDataBuffer::TStreamSocketWithDataBuffer
      ( ::Poco::Net::Socket const & socket1
      ) :
      ::Poco::Net::StreamSocket( socket1 )
   {
   }

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TStreamSocketWithDataBuffer::TStreamSocketWithDataBuffer
      ( ::Poco::Net::SocketImpl * socketImpl1
      ) :
      ::Poco::Net::StreamSocket( socketImpl1 )
   {
   }

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TStreamSocketWithDataBuffer::TStreamSocketWithDataBuffer
      ( ::Poco::Net::IPAddress::Family ipAddressFamilyCode
      ) :
      ::Poco::Net::StreamSocket( new TStreamSocketWithDataBufferImpl( ipAddressFamilyCode ) )
   {
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public bind}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStreamSocketWithDataBuffer::bind
      ( ::Poco::Net::SocketAddress const & address,
        bool reuseAddress
      )
   {
      impl()->bind( address, reuseAddress );
   }

#endif

#if( /* {public DataBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline DataStructures::TDataBuffer & TStreamSocketWithDataBuffer::DataBuffer()
   {
      return static_cast< TStreamSocketWithDataBufferImpl * >( impl() )->DataBuffer;
   }

#endif
#if( /* {public DataBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline DataStructures::TDataBuffer const & TStreamSocketWithDataBuffer::DataBuffer() const
   {
      return static_cast< TStreamSocketWithDataBufferImpl const * >( impl() )->DataBuffer;
   }

#endif
#if( /* {public DataBufferCapacityMaxLimit}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline DataStructures::TDataBuffer::size_type & TStreamSocketWithDataBuffer::DataBufferCapacityMaxLimit()
   {
      return static_cast< TStreamSocketWithDataBufferImpl * >( impl() )->DataBufferCapacityMaxLimit;
   }

#endif
#if( /* {public DataBufferCapacityMaxLimit}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline DataStructures::TDataBuffer::size_type const & TStreamSocketWithDataBuffer::DataBufferCapacityMaxLimit() const
   {
      return static_cast< TStreamSocketWithDataBufferImpl const * >( impl() )->DataBufferCapacityMaxLimit;
   }

#endif

#if( /* {public ReceiveBytesIntoDataBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TStreamSocketWithDataBuffer::ReceiveBytesIntoDataBuffer
      ( int flags1
      )
   {
      return static_cast< TStreamSocketWithDataBufferImpl * >( impl() )->ReceiveBytesIntoDataBuffer( flags1 );
   }

#endif
#if( /* //{public ReceiveAllBytesIntoDataBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TStreamSocketWithDataBuffer::ReceiveAllBytesIntoDataBuffer
   //   ( int flags1
   //   )
   //{
   //   static_cast< TStreamSocketWithDataBufferImpl * >( impl() )->ReceiveAllBytesIntoDataBuffer( flags1 );
   //}

#endif
#if( /* //{public ReceiveAnyBytesIntoDataBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TStreamSocketWithDataBuffer::ReceiveAnyBytesIntoDataBuffer
   //   ( int flags1
   //   )
   //{
   //   static_cast< TStreamSocketWithDataBufferImpl * >( impl() )->ReceiveAnyBytesIntoDataBuffer( flags1 );
   //}

#endif
#if( /* //{public ReceiveAnyBytesIntoDataBufferUntilWouldBlock}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TStreamSocketWithDataBuffer::ReceiveAnyBytesIntoDataBufferUntilWouldBlock
   //   ( int flags1
   //   )
   //{
   //   static_cast< TStreamSocketWithDataBufferImpl * >( impl() )->ReceiveAnyBytesIntoDataBufferUntilWouldBlock( flags1 );
   //}

#endif
}
}
