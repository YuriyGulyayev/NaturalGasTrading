#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPeerStrategyBase.hpp"

#include "../Common/Threading/TDisposalSafeThread.cpp"
#include "./TFileSystemCacheFlusher.cpp"
#include "./TEconomicReportReceiverFactory.cpp"
#include "./TPeerMessageSender.cpp"
#include "./TEconomicReportReceiverViaUdp.cpp"
#include "./TEconomicReportReceiverViaUdpWithDatagramCircularQueue.cpp"
#include "./TStrategyBase.cpp"
#include "./TPeerStrategyBaseConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
// TODO Review and remove this. I already reviewed this but it's worth to repeat.
#if( /* {protected TPlannedActionPeerMessage_}. */ 0 )
//   #if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   inline TPeerStrategyBase::TPlannedActionPeerMessage_::TPlannedActionPeerMessage_()
//   {
////TODO this is shit
//      {
//         unsigned int counter1( 0U );
//         do
//         {
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//               ( counter1 < static_cast< unsigned int >( sizeof( Zero1 ) / sizeof( Zero1[ 0U ] ) ) );
//            Zero1[ counter1 ] = '\x00';
//            ++ counter1;
//         }
//         while( counter1 < static_cast< unsigned int >( sizeof( Zero1 ) / sizeof( Zero1[ 0U ] ) ) );
//      }
//   }
//
//   #endif
//   #if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   // Not implemented.
//
//   #endif
//   #if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   // Placeholder.
//
//   #endif
//   #if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   // Not implemented.
//
//   #endif
//
//   #if( /* {public CalculateCheckSum}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   unsigned int TPeerStrategyBase::TPlannedActionPeerMessage_::CalculateCheckSum() const
//   {
//      static_assert( offsetof( TPlannedActionPeerMessage_, Zero1 ) - offsetof( TPlannedActionPeerMessage_, CheckSum ) ==
//                            ( sizeof( CheckSum ) +
//                              sizeof( BitMask1 ) +
//                              sizeof( InstrumentBestBidPrice ) +
//                              sizeof( InstrumentBestAskPrice ) +
//                              sizeof( InstrumentLastTradePrice )
//                            ),
//                            ""
//                          );
//      static_assert( ( ( sizeof( * this ) - offsetof( TPlannedActionPeerMessage_, BitMask1 ) ) / sizeof( CheckSum ) * sizeof( CheckSum ) ==
//                               ( sizeof( * this ) - offsetof( TPlannedActionPeerMessage_, BitMask1 ) )
//                             ),
//                             ""
//                          );
//      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Zero1[ 0U ] == '\x00' );
//      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Zero1[ 1U ] == '\x00' );
//      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Zero1[ 2U ] == '\x00' );
//
//      // To facilitate checksum calculation, 3 bytes after {BitMask1} shall be 0, which {PrepareReceiveDatagram} ensures.
//      {
//         static_assert( sizeof( BitMask1 ) == 1U, "" );
//         static_assert( sizeof( CheckSum ) - sizeof( BitMask1 ) == 3U, "" );
//
//         // Integral ptomotion is not a problem.
//         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
//            ( ( ( BitMask1 & TPlannedActionPeerMessageBitMask1_MayModifyEntryOrdersTowardsMoney_ ) !=
//                 TPlannedActionPeerMessageBitMask1_None_
//              ) ||
//              ( reinterpret_cast< char const * >( & BitMask1 )[ 1U ] == '\x00' &&
//                reinterpret_cast< char const * >( & BitMask1 )[ 2U ] == '\x00' &&
//                reinterpret_cast< char const * >( & BitMask1 )[ 3U ] == '\x00'
//              )
//            );
//      }
//
//      // Integral ptomotion is not a problem.
//      int dataSize
//         ( ( ( BitMask1 & TPlannedActionPeerMessageBitMask1_MayModifyEntryOrdersTowardsMoney_ ) !=
//              TPlannedActionPeerMessageBitMask1_None_
//           ) ?
//           static_cast< int >( sizeof( * this ) - offsetof( TPlannedActionPeerMessage_, BitMask1 ) ) :
//
//           // {BitMask1} plus 3 bytes.
//           4
//         );
//
//      return ::Common::Math::TMathHelpers::CalculateCheckSum
//         ( reinterpret_cast< unsigned int const * >( & BitMask1 ),
//           //reinterpret_cast< unsigned int const * >( reinterpret_cast< char const * >( & BitMask1 ) + dataSize ),
//           dataSize,
//           CheckSumFactor1_
////TODO remove
//           //CheckSumFactor2_
//         );
//   }
//
//   #endif
//   #if( /* {public UpdateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   inline void TPeerStrategyBase::TPlannedActionPeerMessage_::UpdateCheckSum()
//   {
//      CheckSum = CalculateCheckSum();
//   }
//
//   #endif
//
//   #if( /* {public PrepareReceiveDatagram}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   inline void TPeerStrategyBase::TPlannedActionPeerMessage_::PrepareReceiveDatagram()
//   {
//      static_assert( sizeof( BitMask1 ) == 1U, "" );
//      static_assert( sizeof( CheckSum ) - sizeof( BitMask1 ) == 3U, "" );
//
//      // This will facilitate checksum calculation.
////TODO pattern this after Zero1 initialization
//      reinterpret_cast< char * >( & BitMask1 )[ 1U ] = '\x00';
//      reinterpret_cast< char * >( & BitMask1 )[ 2U ] = '\x00';
//      reinterpret_cast< char * >( & BitMask1 )[ 3U ] = '\x00';
//   }
//
//   #endif
//   #if( /* {public DatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   inline char * TPeerStrategyBase::TPlannedActionPeerMessage_::DatagramBuffer()
//   {
//      return reinterpret_cast< char * >( & CheckSum );
//   }
//
//   #endif
//   #if( /* {public DatagramBufferCapacity}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   inline int TPeerStrategyBase::TPlannedActionPeerMessage_::DatagramBufferCapacity() const
//   {
//      return static_cast< int >( offsetof( TPlannedActionPeerMessage_, Zero1 ) - offsetof( TPlannedActionPeerMessage_, CheckSum ) );
//   }
//
//   #endif
//   #if( /* {public DatagramBufferLength}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   inline int TPeerStrategyBase::TPlannedActionPeerMessage_::DatagramBufferLength() const
//   {
//      // Integral ptomotion is not a problem.
//      return ( ( BitMask1 & TPlannedActionPeerMessageBitMask1_MayModifyEntryOrdersTowardsMoney_ ) !=
//                   TPlannedActionPeerMessageBitMask1_None_
//                 ) ?
//                 DatagramBufferCapacity() :
//                 static_cast< int >( offsetof( TPlannedActionPeerMessage_, BitMask1 ) +
//                                               sizeof( BitMask1 ) -
//                                               offsetof( TPlannedActionPeerMessage_, CheckSum )
//                                             );
//   }
//
//   #endif
//   #if( /* {public TryParseDatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )
//
//   inline bool TPeerStrategyBase::TPlannedActionPeerMessage_::TryParseDatagramBuffer
//      ( int numberBytesReceived
//      )
//   {
//      bool validationSucceeded( numberBytesReceived == DatagramBufferLength() );
//
//      if( validationSucceeded )
//      {
//         validationSucceeded = ( CalculateCheckSum() == CheckSum );
//
//         if( validationSucceeded )
//         {
//            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//         }
//         else
//         {
//            goto label1;
//         }
//      }
//      else
//      {
//         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
//
//      label1:
//         {
//            static char const constantString1AsArray[]
//               ( "{Prototype52::TPeerStrategyBase::TPlannedActionPeerMessage_::TryParseDatagramBuffer} failed" );
//            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//            logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
//         }
//
//         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//      }
//
//      return validationSucceeded;
//   }
//
//   #endif
#endif


#if( /* {protected TOrdersPeerMessage_}. */ 1 )
   #if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPeerStrategyBase::TOrdersPeerMessage_::TOrdersPeerMessage_()
   {
   }

   #endif
   #if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
   #if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

   #endif
   #if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif

   #if( /* {public CalculateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TPeerStrategyBase::TOrdersPeerMessage_::CalculateCheckSum() const
   {
      static_assert( ( sizeof( TOrdersPeerMessagePseudoStructure_ ) ==
                               ( sizeof( static_cast< TOrdersPeerMessagePseudoStructure_ const * >( nullptr )->CheckSum ) +
                                 sizeof( static_cast< TOrdersPeerMessagePseudoStructure_ const * >( nullptr )->OrdersBrokerGeneratedId ) +
                                 sizeof( static_cast< TOrdersPeerMessagePseudoStructure_ const * >( nullptr )->BitMask1 ) +
                                 sizeof( static_cast< TOrdersPeerMessagePseudoStructure_ const * >( nullptr )->Zero1 )
                               )
                            ),
                            ""
                          );
      static_assert( sizeof( TOrdersPeerMessagePseudoStructure_ ) == 4U + 4U + 1U + 3U, "" );

      // To facilitate checksum calculation, 3 bytes at the end shall be 0.
      // Assuming {::std::string} fills itself with zeros on resizing.
      // See a related comment in {AllocateDatagramBufferIfNeeded}.
      static_assert( sizeof( static_cast< TOrdersPeerMessagePseudoStructure_ const * >( nullptr )->Zero1 ) == 3U, "" );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DatagramBuffer_.back() == '\x00' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DatagramBuffer_.end()[ - 2 ] == '\x00' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DatagramBuffer_.end()[ - 3 ] == '\x00' );

      // Assuming this will not overflow.
      return ::Common::Math::TMathHelpers::CalculateCheckSum
                    ( reinterpret_cast< unsigned int const * >
                         ( DatagramBuffer_.data() +
                           static_cast< int >( offsetof( TOrdersPeerMessagePseudoStructure_, OrdersBrokerGeneratedId ) )
                         ),
                      static_cast< int >
                         ( ( static_cast< unsigned int >( DatagramBuffer_.length() ) -
                              static_cast< unsigned int >( offsetof( TOrdersPeerMessagePseudoStructure_, OrdersBrokerGeneratedId ) )
                           ) /
                           static_cast< unsigned int >
                              ( sizeof( static_cast< TOrdersPeerMessagePseudoStructure_ const * >( nullptr )->CheckSum ) )
                         ),
                      CheckSumFactor1_
//TODO remove
                      //CheckSumFactor2_
                    );
   }

   #endif
   #if( /* {public UpdateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerStrategyBase::TOrdersPeerMessage_::UpdateCheckSum()
   {
      reinterpret_cast< TOrdersPeerMessagePseudoStructure_ * >( & DatagramBuffer_.front() )->CheckSum = CalculateCheckSum();
   }

   #endif

   #if( /* {public AllocateDatagramBufferIfNeeded}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerStrategyBase::TOrdersPeerMessage_::AllocateDatagramBufferIfNeeded
      ( int numberEntryOrdersInEachDirection
      )
   {
      // Assuming this will not overflow.
      // We probably don't need to sanity-validate this.
      // Keeping in mind that {TOrdersPeerMessagePseudoStructure_::OrdersBrokerGeneratedId} contains 1 item,
      // which I don't want to validate.
      unsigned int totalNumberOrders( ( static_cast< unsigned int >( numberEntryOrdersInEachDirection ) + 1U ) * 2U );
      unsigned int data1Length
         ( static_cast< unsigned int >( sizeof( TOrdersPeerMessagePseudoStructure_ ) ) -
           static_cast< unsigned int >( sizeof( static_cast< TOrdersPeerMessagePseudoStructure_ const * >( nullptr )->OrdersBrokerGeneratedId ) ) +
           ( totalNumberOrders *
             static_cast< unsigned int >( sizeof( static_cast< TOrdersPeerMessagePseudoStructure_ const * >( nullptr )->OrdersBrokerGeneratedId ) )
           )
         );

      // Assuming string length will not decrease as otherwise it would not be guaranteed that the last 3 bytes are 0.
      // See a related comment in {CalculateCheckSum}.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DatagramBuffer_.length() <= data1Length );

      DatagramBuffer_.resize( data1Length );
   }

   #endif
   #if( /* {public PrepareReceiveDatagram}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerStrategyBase::TOrdersPeerMessage_::PrepareReceiveDatagram()
   {
   }

   #endif
   #if( /* {public DatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline char * TPeerStrategyBase::TOrdersPeerMessage_::DatagramBuffer()
   {
      return ( & DatagramBuffer_.front() );
   }

   #endif
   #if( /* {public DatagramBufferCapacity}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TPeerStrategyBase::TOrdersPeerMessage_::DatagramBufferCapacity() const
   {
      // Assuming this will not overflow.
      // We probably don't need to sanity-validate this.
      return static_cast< int >( DatagramBuffer_.length() ) -
                 static_cast< int >( sizeof( static_cast< TOrdersPeerMessagePseudoStructure_ const * >( nullptr )->Zero1 ) );
   }

   #endif
   #if( /* {public DatagramBufferLength}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TPeerStrategyBase::TOrdersPeerMessage_::DatagramBufferLength() const
   {
      return DatagramBufferCapacity();
   }

   #endif
   #if( /* {public TryParseDatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TPeerStrategyBase::TOrdersPeerMessage_::TryParseDatagramBuffer
      ( int numberBytesReceived
      )
   {
      bool validationSucceeded( numberBytesReceived == DatagramBufferLength() );

      if( validationSucceeded )
      {
         validationSucceeded =
            ( CalculateCheckSum() ==
              reinterpret_cast< TOrdersPeerMessagePseudoStructure_ const * >( DatagramBuffer_.data() )->CheckSum
            );
      
         if( validationSucceeded )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            goto label2;
         }
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();

      label2:
         {
            static char const constantString1AsArray[]
               ( "{Prototype52::TPeerStrategyBase::TOrdersPeerMessage_::TryParseDatagramBuffer} failed" );
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      return validationSucceeded;
   }

   #endif
#endif
#if( /* {protected TPlannedAction1PeerMessage_}. */ 1 )
   #if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPeerStrategyBase::TPlannedAction1PeerMessage_::TPlannedAction1PeerMessage_()
   {
   }

   #endif
   #if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
   #if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

   #endif
   #if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif

   #if( /* {public CalculateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TPeerStrategyBase::TPlannedAction1PeerMessage_::CalculateCheckSum() const
   {
      static_assert( ( sizeof( * this ) ==
                               ( sizeof( InstrumentBestBidPrice ) +
                                 sizeof( InstrumentBestAskPrice ) +
                                 sizeof( InstrumentLastTradePrice ) +
                                 sizeof( CheckSum )
                               )
                            ),
                            ""
                          );
      static_assert( sizeof( * this ) == 8U + 8U + 8U + 4U, "" );

      return ::Common::Math::TMathHelpers::CalculateCheckSum
                    ( reinterpret_cast< unsigned int const * >( & InstrumentBestBidPrice ),
                      static_cast< int >( ( offsetof( TPlannedAction1PeerMessage_, CheckSum ) -
                                                      offsetof( TPlannedAction1PeerMessage_, InstrumentBestBidPrice )
                                                    ) /
                                                    sizeof( CheckSum )
                                                  ),
                      CheckSumFactor1_
//TODO remove
                      //CheckSumFactor2_
                    );
   }

   #endif
   #if( /* {public UpdateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerStrategyBase::TPlannedAction1PeerMessage_::UpdateCheckSum()
   {
      CheckSum = CalculateCheckSum();
   }

   #endif

   #if( /* {public PrepareReceiveDatagram}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerStrategyBase::TPlannedAction1PeerMessage_::PrepareReceiveDatagram()
   {
   }

   #endif
   #if( /* {public DatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline char * TPeerStrategyBase::TPlannedAction1PeerMessage_::DatagramBuffer()
   {
      return reinterpret_cast< char * >( & InstrumentBestBidPrice );
   }

   #endif
   #if( /* {public DatagramBufferCapacity}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TPeerStrategyBase::TPlannedAction1PeerMessage_::DatagramBufferCapacity() const
   {
      return static_cast< int >( sizeof( * this ) - offsetof( TPlannedAction1PeerMessage_, InstrumentBestBidPrice ) );
   }

   #endif
   #if( /* {public DatagramBufferLength}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TPeerStrategyBase::TPlannedAction1PeerMessage_::DatagramBufferLength() const
   {
      return DatagramBufferCapacity();
   }

   #endif
   #if( /* {public TryParseDatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TPeerStrategyBase::TPlannedAction1PeerMessage_::TryParseDatagramBuffer
      ( int numberBytesReceived
      )
   {
      bool validationSucceeded( numberBytesReceived == DatagramBufferLength() );

      if( validationSucceeded )
      {
         validationSucceeded = ( CalculateCheckSum() == CheckSum );
      
         if( validationSucceeded )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            goto label3;
         }
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();

      label3:
         {
            static char const constantString1AsArray[]
               ( "{Prototype52::TPeerStrategyBase::TPlannedAction1PeerMessage_::TryParseDatagramBuffer} failed" );
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      return validationSucceeded;
   }

   #endif
#endif
#if( /* {protected TPlannedAction2PeerMessage_}. */ 1 )
   #if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPeerStrategyBase::TPlannedAction2PeerMessage_::TPlannedAction2PeerMessage_()
   {
   }

   #endif
   #if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
   #if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

   #endif
   #if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif

   #if( /* {public CalculateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TPeerStrategyBase::TPlannedAction2PeerMessage_::CalculateCheckSum() const
   {
      static_assert( sizeof( * this ) == sizeof( CheckSum ), "" );
      static_assert( sizeof( * this ) == 4U, "" );

      // We would normally call {::Common::Math::TMathHelpers::CalculateCheckSum} here.
      return CheckSumFactor1_;
   }

   #endif
   #if( /* {public UpdateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerStrategyBase::TPlannedAction2PeerMessage_::UpdateCheckSum()
   {
      CheckSum = CalculateCheckSum();
   }

   #endif

   #if( /* {public PrepareReceiveDatagram}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerStrategyBase::TPlannedAction2PeerMessage_::PrepareReceiveDatagram()
   {
   }

   #endif
   #if( /* {public DatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline char * TPeerStrategyBase::TPlannedAction2PeerMessage_::DatagramBuffer()
   {
      return reinterpret_cast< char * >( & CheckSum );
   }

   #endif
   #if( /* {public DatagramBufferCapacity}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TPeerStrategyBase::TPlannedAction2PeerMessage_::DatagramBufferCapacity() const
   {
      return static_cast< int >( sizeof( * this ) - offsetof( TPlannedAction2PeerMessage_, CheckSum ) );
   }

   #endif
   #if( /* {public DatagramBufferLength}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TPeerStrategyBase::TPlannedAction2PeerMessage_::DatagramBufferLength() const
   {
      return DatagramBufferCapacity();
   }

   #endif
   #if( /* {public TryParseDatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TPeerStrategyBase::TPlannedAction2PeerMessage_::TryParseDatagramBuffer
      ( int numberBytesReceived
      )
   {
      bool validationSucceeded( numberBytesReceived == DatagramBufferLength() );

      if( validationSucceeded )
      {
         validationSucceeded = ( CalculateCheckSum() == CheckSum );
      
         if( validationSucceeded )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            goto label4;
         }
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();

      label4:
         {
            static char const constantString1AsArray[]
               ( "{Prototype52::TPeerStrategyBase::TPlannedAction2PeerMessage_::TryParseDatagramBuffer} failed" );
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      return validationSucceeded;
   }

   #endif
#endif
#if( /* {protected TPeerStatePeerMessage_}. */ 1 )
   #if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPeerStrategyBase::TPeerStatePeerMessage_::TPeerStatePeerMessage_()
   {
      Zero1[ 0U ] = '\x00';
   }

   #endif
   #if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
   #if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

   #endif
   #if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif

   #if( /* {public CalculateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TPeerStrategyBase::TPeerStatePeerMessage_::CalculateCheckSum() const
   {
      static_assert( sizeof( * this ) == sizeof( CheckSum ) + sizeof( BitMask1 ) + sizeof( PeerId ) + sizeof( Zero1 ), "" );
      static_assert( sizeof( * this ) == 4U + 2U + 1U + 1U, "" );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Zero1[ 0U ] == '\x00' );

      return ::Common::Math::TMathHelpers::CalculateCheckSum
                    ( reinterpret_cast< unsigned int const * >( & BitMask1 ),
                      static_cast< int >( ( sizeof( * this ) - offsetof( TPeerStatePeerMessage_, BitMask1 ) ) / sizeof( CheckSum ) ),
                      CheckSumFactor1_
//TODO remove
                      //CheckSumFactor2_
                    );
   }

   #endif
   #if( /* {public UpdateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerStrategyBase::TPeerStatePeerMessage_::UpdateCheckSum()
   {
      CheckSum = CalculateCheckSum();
   }

   #endif

   #if( /* {public PrepareReceiveDatagram}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TPeerStrategyBase::TPeerStatePeerMessage_::PrepareReceiveDatagram()
   {
   }

   #endif
   #if( /* {public DatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline char * TPeerStrategyBase::TPeerStatePeerMessage_::DatagramBuffer()
   {
      return reinterpret_cast< char * >( & CheckSum );
   }

   #endif
   #if( /* {public DatagramBufferCapacity}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TPeerStrategyBase::TPeerStatePeerMessage_::DatagramBufferCapacity() const
   {
      return static_cast< int >( offsetof( TPeerStatePeerMessage_, Zero1 ) - offsetof( TPeerStatePeerMessage_, CheckSum ) );
   }

   #endif
   #if( /* {public DatagramBufferLength}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TPeerStrategyBase::TPeerStatePeerMessage_::DatagramBufferLength() const
   {
      return DatagramBufferCapacity();
   }

   #endif
   #if( /* {public TryParseDatagramBuffer}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TPeerStrategyBase::TPeerStatePeerMessage_::TryParseDatagramBuffer
      ( int numberBytesReceived
      )
   {
      bool validationSucceeded( numberBytesReceived == DatagramBufferLength() );

      if( validationSucceeded )
      {
         validationSucceeded = ( CalculateCheckSum() == CheckSum );
      
         if( validationSucceeded )
         {
            // Integral ptomotion is not a problem.
            if( ( BitMask1 & TPeerStatePeerMessageBitMask1_IsWarmUp_ ) != TPeerStatePeerMessageBitMask1_None_ )

            {
               {
                  static char const constantString1AsArray[]
                     ( "received a warm-up {Prototype52::TPeerStrategyBase::TPeerStatePeerMessage_}" );
                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                  logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               validationSucceeded = false;
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
         }
         else
         {
            goto label5;
         }
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();

      label5:
         {
            static char const constantString1AsArray[]
               ( "{Prototype52::TPeerStrategyBase::TPeerStatePeerMessage_::TryParseDatagramBuffer} failed" );
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      return validationSucceeded;
   }

   #endif
#endif

#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {protected} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPeerStrategyBase::TPeerStrategyBase
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
      ) :
      TStrategyBase( threadedActivityCancellationToken1 ),
      //InstrumentBestAggregatedBidAskQuoteSubscription_( ??? ),
      //InstrumentTradeSubscription_( ??? ),

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      EconomicReportReceiverThreadRunnableAdapter_( ( * this ), ( & TPeerStrategyBase::EconomicReportReceiverThreadProc ) ),
      #pragma warning( pop )

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      PeerStatePeerMessageReceiverThreadRunnableAdapter_( ( * this ), ( & TPeerStrategyBase::PeerStatePeerMessageReceiverThreadProc ) )
      #pragma warning( pop )
   {
      // See visible universe in {DoInitialize}.
   }

#endif
#if( /* {protected} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPeerStrategyBase::TPeerStrategyBase
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
        TPeerStrategyBaseConfiguration && configuration1
      ) :
      TStrategyBase( threadedActivityCancellationToken1, ::std::move( configuration1 ) ),
      UntradableConditionConfiguration_( ::std::move( configuration1.UntradableConditionConfiguration ) ),
      //InstrumentBestAggregatedBidAskQuoteSubscription_( ??? ),
      //InstrumentTradeSubscription_( ??? ),
//TODO EconomicReportReceiver_( ... )

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      EconomicReportReceiverThreadRunnableAdapter_( ( * this ), ( & TPeerStrategyBase::EconomicReportReceiverThreadProc ) ),
      #pragma warning( pop )

      PeerStatePeerMessageSender_( ::std::move( configuration1.PeerStatePeerMessageSenderConfiguration ) ),
      PeerStatePeerMessageReceiver_( ::std::move( configuration1.PeerStatePeerMessageReceiverConfiguration ) ),

      #pragma warning( push )
   #if( defined( _MSC_VER ) )
      // warning C4355: 'this' : used in base member initializer list
      #pragma warning( disable: 4355 )
   #endif
      PeerStatePeerMessageReceiverThreadRunnableAdapter_( ( * this ), ( & TPeerStrategyBase::PeerStatePeerMessageReceiverThreadProc ) ),
      #pragma warning( pop )

      DateTimeKeeper_( ::std::move( configuration1.DateTimeKeeperConfiguration ) ),
      FileSystemCacheFlusher_( ::std::move( configuration1.FileSystemCacheFlusherConfiguration ) )
   {
      // See visible universe in {DoInitialize}.

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

      // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

      // Placeholder.

#endif

#if( /* {public Initialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerStrategyBase::Initialize
      ( TPeerStrategyBaseConfiguration && configuration1
      )
   {
      TStrategyBase::Initialize( ::std::move( configuration1 ) );

      UntradableConditionConfiguration_.Assign( ::std::move( configuration1.UntradableConditionConfiguration ) );
//TODO EconomicReportReceiver_.Initialize( ... )
      PeerStatePeerMessageSender_.Initialize( ::std::move( configuration1.PeerStatePeerMessageSenderConfiguration ) );
      PeerStatePeerMessageReceiver_.Initialize( ::std::move( configuration1.PeerStatePeerMessageReceiverConfiguration ) );
      DateTimeKeeper_.Initialize( ::std::move( configuration1.DateTimeKeeperConfiguration ) );
      FileSystemCacheFlusher_.Initialize( ::std::move( configuration1.FileSystemCacheFlusherConfiguration ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerStrategyBase::DoInitialize
      ( TPeerStrategyBaseConfiguration && configuration1
      )
   {
//TODO update this
      // Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
      //    Instance constructors -- base.
      //       Hide, possibly implicitly. Call, possibly implicitly.
      //    Instance destructor -- base.
      //       Override, possibly implicitly. Call, possibly implicitly.
      //    {Initialize} -- base.
      //       Hide, call.
      //    {DoInitialize}.
      //       Call.

      State1Code_ = TState1Code_None_;
      State2Code_ = TState2Code_None_;

      ModeCode_ = ::std::move( configuration1.ModeCode );
      PeerStatePeerMessage_.PeerId = ::std::move( configuration1.PeerId );
      EconomicReportReleaseTimeOfDayMilliseconds_ = ::std::move( configuration1.EconomicReportReleaseTimeOfDayMilliseconds );
      EconomicReportReleaseDateTimeTestOffsetMilliseconds_ =
         ::std::move( configuration1.EconomicReportReleaseDateTimeTestOffsetMilliseconds );

      // We need to assign a value to this sooner to be used below.
      EntryOrdersModificationTimeOffsetMilliseconds_ = ::std::move( configuration1.EntryOrdersModificationTimeOffsetMilliseconds );

//TODO I only copied this -- to be reviewed and fixed.
      {
         //// The rounding of this up results in the rounding of {FileSystemCacheFlushing1TimeOffsetTimer1Ticks_} and {FileSystemCacheFlushing2TimeOffsetTimer1Ticks_} down.
         //// Assuming this will not overflow.
         //int entryOrdersModificationTimeOffsetMillisecondsAsInt
         //   ( ::Common::Math::TMathHelpers::RoundValueToIntegerMidpointUp< double, int >( EntryOrdersModificationTimeOffsetMilliseconds_ ) );

         //// The rounding formula assumes that {configuration1.FileSystemCacheFlushing2TimeOffsetMilliseconds - entryOrdersModificationTimeOffsetMillisecondsAsInt}
         //// is negative.
         // It would be nice to log a warning if the resulting value is different from the configured one.
         // Assuming this will not overflow.
         FileSystemCacheFlushing2TimeOffsetTimer1Ticks_ =
            //::std::min( ( configuration1.FileSystemCacheFlushing2TimeOffsetMilliseconds - entryOrdersModificationTimeOffsetMillisecondsAsInt - Timer1TickIntervalMilliseconds_ / 2 ) / Timer1TickIntervalMilliseconds_, ( - 1 ) );
            ::std::min
               ( ::Common::Math::TMathHelpers::RoundValueToIntegerMidpointDown< double, int >
                     ( ( static_cast< double >( configuration1.FileSystemCacheFlushing2TimeOffsetMilliseconds ) - EntryOrdersModificationTimeOffsetMilliseconds_ ) / static_cast< double >( Timer1TickIntervalMilliseconds_ ) ),
                 ( - 1 )
               );

         //// The rounding formula assumes that {configuration1.FileSystemCacheFlushing1TimeOffsetMilliseconds - entryOrdersModificationTimeOffsetMillisecondsAsInt}
         //// is negative.
         // It would be nice to log a warning if the resulting value is different from the configured one.
         // Assuming this will not overflow.
         FileSystemCacheFlushing1TimeOffsetTimer1Ticks_ =
            //::std::min( ( configuration1.FileSystemCacheFlushing1TimeOffsetMilliseconds - entryOrdersModificationTimeOffsetMillisecondsAsInt - Timer1TickIntervalMilliseconds_ / 2 ) / Timer1TickIntervalMilliseconds_, FileSystemCacheFlushing2TimeOffsetTimer1Ticks_ - 1 );
            ::std::min
               ( ::Common::Math::TMathHelpers::RoundValueToIntegerMidpointDown< double, int >
                     ( ( static_cast< double >( configuration1.FileSystemCacheFlushing1TimeOffsetMilliseconds ) - EntryOrdersModificationTimeOffsetMilliseconds_ ) / static_cast< double >( Timer1TickIntervalMilliseconds_ ) ),
                 FileSystemCacheFlushing2TimeOffsetTimer1Ticks_ - 1
               );

         //// The rounding formula assumes that {configuration1.PeerMessageSendingWarmUp2TimeOffsetMilliseconds - entryOrdersModificationTimeOffsetMillisecondsAsInt}
         //// is negative.
         // It would be nice to log a warning if the resulting value is different from the configured one.
         // Assuming this will not overflow.
         PeerMessageSendingWarmUp2TimeOffsetTimer1Ticks_ =
            //::std::min( ( configuration1.PeerMessageSendingWarmUp2TimeOffsetMilliseconds - entryOrdersModificationTimeOffsetMillisecondsAsInt - Timer1TickIntervalMilliseconds_ / 2 ) / Timer1TickIntervalMilliseconds_, ( - 1 ) );
            ::std::min
               ( ::Common::Math::TMathHelpers::RoundValueToIntegerMidpointDown< double, int >
                     ( ( static_cast< double >( configuration1.PeerMessageSendingWarmUp2TimeOffsetMilliseconds ) - EntryOrdersModificationTimeOffsetMilliseconds_ ) / static_cast< double >( Timer1TickIntervalMilliseconds_ ) ),
                 ( - 1 )
               );

         //// The rounding formula assumes that {configuration1.PeerMessageSendingWarmUp1TimeOffsetMilliseconds - entryOrdersModificationTimeOffsetMillisecondsAsInt}
         //// is negative.
         // It would be nice to log a warning if the resulting value is different from the configured one.
         // Assuming this will not overflow.
         PeerMessageSendingWarmUp1TimeOffsetTimer1Ticks_ =
            //::std::min( ( configuration1.PeerMessageSendingWarmUp1TimeOffsetMilliseconds - entryOrdersModificationTimeOffsetMillisecondsAsInt - Timer1TickIntervalMilliseconds_ / 2 ) / Timer1TickIntervalMilliseconds_, PeerMessageSendingWarmUp2TimeOffsetTimer1Ticks_ - 1 );
            ::std::min
               ( ::Common::Math::TMathHelpers::RoundValueToIntegerMidpointDown< double, int >
                     ( ( static_cast< double >( configuration1.PeerMessageSendingWarmUp1TimeOffsetMilliseconds ) - EntryOrdersModificationTimeOffsetMilliseconds_ ) / static_cast< double >( Timer1TickIntervalMilliseconds_ ) ),
                 PeerMessageSendingWarmUp2TimeOffsetTimer1Ticks_ - 1
               );
      }

      TerminationTimeOffsetMilliseconds_ = ::std::move( configuration1.TerminationTimeOffsetMilliseconds );
      PositionExpectedDirectionCode_ = 0;

//TODO review this coment; keep it simple.
      // yg? This is probably unnecessary but we are not immediately going to create a pooled order, so I feel bad about a garbage pointer hanging around for some time.
      // yg? But the same is true of, for example, {InstrumentTradeSubscription_} but we don't null it. Although the code can check for {PooledOrder_ == nullptr},
      // yg? but it can run only after a pooled order was created and possibly nulled.
      PooledOrder_ = nullptr;
   }

#endif
#if( /* {public Prepare}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerStrategyBase::Prepare
      ( TTradingSystem & tradingSystem1
      )
   {
      // Visible universe.
//TODO

      TStrategyBase::Prepare( tradingSystem1 );

      EconomicReportReceiver_->Prepare( DateTimeKeeper_ );
      PeerStatePeerMessageSender_.Prepare();
      PeerStatePeerMessageReceiver_.Prepare( DateTimeKeeper_ );
      DateTimeKeeper_.Prepare( ModeCode_ != TPeerStrategyBaseModeCode_Normal );
   }

#endif
#if( /* {public Start}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerStrategyBase::Start()
   {
      // Visible universe.
//TODO

      TStrategyBase::Start();

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

         switch( ModeCode_ )
         {
            case TPeerStrategyBaseModeCode_Normal :
            {
               {
                  // One might argue, this message is misleading: we are not actually running yet, only starting.
                  static char const constantString1AsArray[]( "{Prototype52::TPeerStrategyBase} is running in normal mode" );

                  logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               break;
            }

            case TPeerStrategyBaseModeCode_Test :
            {
               {
                  // One might argue, this message is misleading: we are not actually running yet, only starting.
                  static char const constantString1AsArray[]( "{Prototype52::TPeerStrategyBase} is running in test mode" );

                  logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
               }

               break;
            }
            
            default :
            {
               YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
               break;
            }
         }
      }
   }

#endif
#if( /* {public Run}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerStrategyBase::Run()
   {
      // Visible universe.
      //    {Run} -- base.
      //       Implement.
//TODO add more

      //TStrategyBase::Run();

//TODO write code -- done?

      REngineAdapter_->LockREngine();
      REngineAdapter_->AsyncEnsureLoggedIn();
      //TODO move PrepareDoRun();
      DoRun();

      // yg? Assuming that callbacks will not be called after a log out.
      // yg? We should unhook events to make this assumption safer.
      REngineAdapter_->AsyncEnsureLoggedOut();

      REngineAdapter_->UnlockREngine();
   }

#endif
#if( /* {public DoRun}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif


#if( /* {private EconomicReportReceiverThreadProc}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerStrategyBase::EconomicReportReceiverThreadProc()
   {
//TODO
   }

#endif

#if( /* {private PeerStatePeerMessageReceiverThreadProc}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPeerStrategyBase::PeerStatePeerMessageReceiverThreadProc()
   {
//TODO
   }

#endif
}
