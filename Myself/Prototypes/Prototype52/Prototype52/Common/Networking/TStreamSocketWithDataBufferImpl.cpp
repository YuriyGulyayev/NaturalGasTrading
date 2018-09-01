#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TStreamSocketWithDataBufferImpl.hpp"

#include "../DataStructures/TDataBuffer.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Networking
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TStreamSocketWithDataBufferImpl::TStreamSocketWithDataBufferImpl()
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TStreamSocketWithDataBufferImpl::TStreamSocketWithDataBufferImpl
      ( ::Poco::Net::IPAddress::Family ipAddressFamilyCode
      ) :
      ::Poco::Net::StreamSocketImpl( ipAddressFamilyCode )
   {
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public ReceiveBytesIntoDataBuffer}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TStreamSocketWithDataBufferImpl::ReceiveBytesIntoDataBuffer
      ( int flags1
      )
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataBuffer.DataLength <= DataBuffer.length() );
      DataStructures::TDataBuffer::size_type dataBufferRemainingCapacity( DataBuffer.length() - DataBuffer.DataLength );
      int numberBytesToReceive;

      if( dataBufferRemainingCapacity > 0U )
      {
         // This prevents an overflow when the caller reserves a too large capacity.
         // yg? But this is an overhead that rarely if ever benefits my business.
         numberBytesToReceive =
            static_cast< int >
               ( ::std::min
                    ( dataBufferRemainingCapacity,
                      static_cast< DataStructures::TDataBuffer::size_type >( static_cast< unsigned int >( ::std::numeric_limits< int >::max() ) )
                    )
               );
      }
      else
// TODO 2 yg? Test code in this branch.
      {
         // We will increase buffer capacity by at least 1U, even if no data is {available}.
         // Another solution could be to wait until any data becomes {available} but that would imply a bloated and inefficient code.
         // Additionally, in case we are called after the {select} method, under some conditions the {select} method can report a socket
         // as readable while 0 bytes is actually available for reading.
         // Can the {available} method return a negative value? If it happens the {receiveBytes} method will probably throw an exception.
         // To avoid the exception, we could just log an error and return. Although the user might want to see the exception message.
         // Under some conditions, such as {DataBuffer.length() + 1U == DataBufferCapacityMaxLimit} (note that this expression
         // probably can overflow), it would be more efficient to not call {available} but that would introduce an unnecessary overhead
         // in almost all cases.
         // yg? Assuming this will not throw an exception.
         int numberBytesAvailable( ::std::max( available(), 1 ) );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesAvailable > 0 );

         // This can't overflow.
         DataBuffer.AllocateAdditionalCapacityIfNeeded
            ( static_cast< unsigned int >( numberBytesAvailable ), 1U, DataBufferCapacityMaxLimit );

         // This can't overflow, although the type-cast to {int} can and that's not a problem.
         numberBytesToReceive = static_cast< int >( DataBuffer.length() ) - static_cast< int >( DataBuffer.DataLength );
      }

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesToReceive > 0 );

      // This can throw an exception. Our state would not get corrupt.
      int numberBytesReceived( receiveBytes( ( & DataBuffer[ DataBuffer.DataLength ] ), numberBytesToReceive, flags1 ) );

      // If this value was negative an exception would have been thrown.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesReceived >= 0 );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesReceived <= numberBytesToReceive );

      // This can't overflow and can't exceed {DataBuffer.length()}.
      DataBuffer.DataLength += static_cast< unsigned int >( numberBytesReceived );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataBuffer.DataLength <= DataBuffer.length() );
      return numberBytesReceived;
   }


   // Old version.
   //
   //int TStreamSocketWithDataBufferImpl::ReceiveBytesIntoDataBuffer
   //   ( int flags1
   //   )
   //{
   //   DataStructures::TDataBuffer::size_type dataBufferLength( DataBuffer.length() );
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataBuffer.DataLength <= dataBufferLength );
   //   DataStructures::TDataBuffer::size_type dataBufferRemainingLength( dataBufferLength - DataBuffer.DataLength );
   //   int numberBytesToReceive;
   //
   //   if( dataBufferRemainingLength > 0U )
   //   {
   //      // This prevents an overflow when the caller reserves a too large capacity.
   //      numberBytesToReceive =
   //         static_cast< int >
   //            ( ::std::min
   //                 ( dataBufferRemainingLength,
   //                   static_cast< DataStructures::TDataBuffer::size_type >( static_cast< unsigned int >( ::std::numeric_limits< int >::max() ) )
   //                 )
   //            );
   //   }
   //   else
   //   {
   //      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataBuffer.DataLength == dataBufferLength );
   //
   //      dataBufferRemainingLength = DataBuffer.max_size() - dataBufferLength;
   //      if( dataBufferRemainingLength > 0U )
   //      {
   //         Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //      }
   //      else
   //      {
   //         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //
   //         {
   //            static char const constantString1AsArray[]( "Error; {Common::Networking::TStreamSocketWithDataBufferImpl::DataBuffer} is full" );
   //
   //            // yg? We might need to throw a more specialized exception.
   //            throw ErrorHandling::TRegularErrorException( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ), 0 );
   //         }
   //      }
   //
   //      // We will increase buffer length by at least 1, even if no data is {available}.
   //      // Another solution could be to wait until any data becomes {available} but that would imply a bloated and inefficient logic to code.
   //      // Additionally, in case we are called after the {select} method, under some conditions the {select} method can report a socket as readable
   //      // while 0 bytes is actually available for reading.
   //      // Can the {available} method return a negative value? If it happens the {receiveBytes} method will probably throw an exception.
   //      // To avoid the exception, we could just log an error and return. Although the user might want to see the exception message.
   //      // When at this point {dataBufferRemainingLength == 1U}, it would be more efficient to not call the {available} method
   //      // but that would introduce an unnecessary overhead in almost all cases.
   //      // yg? Assuming this will not throw an exception.
   //      int numberBytesAvailable( ::std::max( available(), 1 ) );
   //
   //      // This will not overflow.
   //      if( dataBufferRemainingLength > static_cast< unsigned int >( numberBytesAvailable ) )
   //
   //      {
   //         numberBytesToReceive = numberBytesAvailable;
   //      }
   //      else
   //      {
   //         // This will not overflow.
   //         numberBytesToReceive = static_cast< int >( dataBufferRemainingLength );
   //      }
   //
   //      // This will not overflow and will not exceed {DataBuffer.max_size()}.
   //      dataBufferLength += static_cast< unsigned int >( numberBytesToReceive );
   //
   //      // This initializes the extra chars with zeroes, which is an overhead. The caller should allocate sufficient memory in advance.
   //      DataBuffer.resize( dataBufferLength );
   //   }
   //
   //   // Would it be more correct to cast {DataBuffer.DataLength} to {DataStructures::TDataBuffer::difference_type}.
   //   // Maybe not as that can result in an overflow.
////  It would be better to call {DataBuffer.at}.
////  Otherwise {DataBuffer.DataLength} should be cast to {...::difference_type}.
   //   char * dataBufferPointer1( ( & DataBuffer.front() ) + DataBuffer.DataLength );
   //
   //   // This can throw an exception. Our state would not get corrupt.
   //   int numberBytesReceived( receiveBytes( dataBufferPointer1, numberBytesToReceive, flags1 ) );
   //
   //   // If this value was negative an exception would have been thrown.
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesReceived >= 0 );
   //
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesReceived <= numberBytesToReceive );
   //
   //   // This will not overflow.
   //   DataBuffer.DataLength += static_cast< unsigned int >( numberBytesReceived );
   //
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataBuffer.DataLength <= DataBuffer.length() );
   //   return numberBytesReceived;
   //}

#endif
#if( /* //{public ReceiveAllBytesIntoDataBuffer}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //void TStreamSocketWithDataBufferImpl::ReceiveAllBytesIntoDataBuffer
   //   ( int flags1
   //   )
   //{
   //   //DataStructures::TDataBuffer::size_type dataBufferDataLength1( DataBuffer.DataLength );
   //   int lastNumberBytesReceived;
   //
   //   // If the counterparty keeps continuesly sending us data it's potentially possible that this loop will never break and
   //   // we will run out of memory or data buffer will overflow.
   //   do
   //   {
   //      lastNumberBytesReceived = ReceiveBytesIntoDataBuffer( flags1 );
   //      if( lastNumberBytesReceived > 0 )
   //      {
   //         Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //      }
   //      else
   //      {
   //         break;
   //      }
   //   }
   //
   //   // Calling the {available} method here and the {ReceiveBytesIntoDataBuffer} method can also call it under some conditions -- inefficient.
   //   // But any logic designed to eliminate the redundant calls would introduce an unnecessary overhead in most cases.
   //   // Another solution would be to check if we received fewer bytes than the buffer capacity but that would be incorrect as
   //   // the {available} and {receiveBytes} methods can report/receive fewer bytes than actually available.
   //   // yg? Assuming this will not throw an exception.
   //   while( available() > 0 );
   //
   //   //// yg? Assuming this will not overflow. I really could design the whole class to limit data size to eliminate the possibility of this overflow.
   //   //int numberBytesReceived( static_cast< int >( DataBuffer.DataLength ) - static_cast< int >( dataBufferDataLength1 ) );
   //
   //   //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesReceived == static_cast< int >( DataBuffer.DataLength - dataBufferDataLength1 ) );
   //   //return ( numberBytesReceived > 0 ) ? numberBytesReceived : lastNumberBytesReceived;
   //}

#endif
#if( /* //{public ReceiveAnyBytesIntoDataBuffer}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //void TStreamSocketWithDataBufferImpl::ReceiveAnyBytesIntoDataBuffer
   //   ( int flags1
   //   )
   //{
   //   // Calling the {available} method here and the {ReceiveAllBytesIntoDataBuffer} method can also call it under some conditions -- inefficient.
   //   // But any logic designed to eliminate the redundant calls would introduce an unnecessary overhead in most cases.
   //   // yg? Assuming this will not throw an exception.
   //   int numberBytesReceived( available() );
   //
   //   if( numberBytesReceived > 0 )
   //   {
   //      /*numberBytesReceived =*/ ReceiveAllBytesIntoDataBuffer( flags1 );
   //   }
   //   else
   //   {
   //      Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //   }
   //   //return numberBytesReceived;
   //}

#endif
#if( /* //{public ReceiveAnyBytesIntoDataBufferUntilWouldBlock}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //void TStreamSocketWithDataBufferImpl::ReceiveAnyBytesIntoDataBufferUntilWouldBlock
   //   ( int flags1
   //   )
   //{
   //   try
   //   {
   //      // If the counterparty keeps continuesly sending us data it's potentially possible that this loop will never break and
   //      // we will run out of memory or data buffer will overflow.
   //      while( ReceiveBytesIntoDataBuffer( flags1 ) > 0 )
   //      {
   //      }
   //   }
   //   catch( ::Poco::TimeoutException const & /*exception1*/ )
   //   {
   //      //Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //      Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //   }
   //}

#endif
}
}
