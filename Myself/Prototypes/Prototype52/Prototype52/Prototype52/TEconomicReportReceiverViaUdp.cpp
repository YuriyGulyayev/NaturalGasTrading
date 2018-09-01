#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportReceiverViaUdp.hpp"

#include "./TEconomicReportReceiverBase.cpp"
#include "./TEconomicReportReceiverViaUdpConfiguration.cpp"
#include "../Common/Networking/TNetworkingHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportReceiverViaUdp< TResult_ >::TEconomicReportReceiverViaUdp()
   {
      // {::Poco::Net::DatagramSocket} default constructor assumes {::Poco::Net::IPAddress::Family::IPv4} and creates a socket handle.
      // It would probably be more correct to not create a socket handle.
      // We are going to unconditionally close this socket handle and create another one, which is lame.
      // But keeping it simple.
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportReceiverViaUdp< TResult_ >::TEconomicReportReceiverViaUdp
      ( TEconomicReportReceiverViaUdpConfiguration && configuration1
      ) :
      TEconomicReportReceiverBase< TResult_ >( ::std::move( configuration1 ) )
   {
      // See a comment in default constructor.

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and inline.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaUdp< TResult_ >::Initialize
      ( TEconomicReportReceiverViaUdpConfiguration && configuration1
      )
   {
      TEconomicReportReceiverBase< TResult_ >::Initialize( ::std::move( configuration1 ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaUdp< TResult_ >::DoInitialize
      ( TEconomicReportReceiverViaUdpConfiguration && configuration1
      )
   {
// TODO 2 yg? Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
// TODO 2 yg? Refer to it from consrtructors, destructors, {Initialize}.

      LocalIPPortNumber_ = ::std::move( configuration1.LocalIPPortNumber );
      SocketStateIsValid_ = false;
   }

#endif
#if( /* //{public Prepare}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {protected DoTryRun}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline /*bool*/ void TEconomicReportReceiverViaUdp< TResult_ >::DoTryRun()
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {DoTryRun} -- base.
      //       Implement.
      //    {CreateSocketIfNeeded}.
      //       Call.
      //    {TryReceiveAndProcessData}.
      //       Call.

      //base->DoTryRun

      CreateSocketIfNeeded();
      TryReceiveAndProcessData();
   }

#endif

#if( /* //{public TryMakeWarmUpStep}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public LogActivityReportIfPossible}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaUdp< TResult_ >::LogActivityReportIfPossible()
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {LogActivityReportIfPossible} -- base.
      //       Implement.
      //    {Socket_.close}.
      //       Call.
      //    {SocketStateIsValid_}.
      //       Update.

      //base->LogActivityReportIfPossible

      SocketStateIsValid_ = false;

      // yg? Assuming this will not throw an exception.
      Socket_.close();
   }

#endif

#if( /* {private CreateSocketIfNeeded}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaUdp< TResult_ >::CreateSocketIfNeeded()
   {
      // Visible universe.
      //    {::Common::Networking::TNetworkingHelpers::WildcardIPAddress}.
      //       Use.
      //    {LocalIPPortNumber_}.
      //       Use.
      //    {Socket_.bind}.
      //       Call.
      //    {Socket_.close}.
      //       Call.
      //    {Socket_.init}.
      //       Call.
      //    {SocketStateIsValid_}.
      //       Use, update.
      //    {ConfigureSocket}.
      //       Call.

      if( ! SocketStateIsValid_ )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         return;
      }

      // See a comment in default constructor.
      // yg? Assuming this will not throw an exception.
      Socket_.close();

      {
         //::Poco::Net::DatagramSocket socket1( ::Poco::Net::IPAddress::Family::IPv4 );
         Socket_.init( AF_INET );
         //ConfigureSocket( socket1 );
         ConfigureSocket();

         {
            // yg? It might be inefficient to bind to all local IP addresses in case we are not going to receive data on all of them.
            // It would be more efficient to pre-create this object but this code is not performance critical.
            // To make it more efficient we probably can simply call the {::bind} function.
            ::Poco::Net::SocketAddress socketAddress1
               ( ::Common::Networking::TNetworkingHelpers::WildcardIPAddress, LocalIPPortNumber_ );

            // yg? Assuming this will not throw an exception.
            // yg? Will this fail if this computer has no network interfaces or IP addresses? I believe, it really shouldn't fail.
            // yg? But if this can fail we would rather handle exceptions.
            // yg? It would probably be unnecessary to handle exceptions when binding to a specific IP address that is assumed to exist.
            //socket1.bind( socketAddress1, false );
            Socket_.bind( socketAddress1, false );
         }

         //// yg? This is actually copying rather than moving. I don't want to code proper moving.
         //Socket_ = ::std::move( socket1 );
      }

//TODO remove validation? reflect in visible universe
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! SocketStateIsValid_ );
      SocketStateIsValid_ = true;
   }

#endif
#if( /* {protected ConfigureSocket}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaUdp< TResult_ >::ConfigureSocket()
   {
      // This method is virtual and inline.
      // I don't want to write down visible universe here.
   }

#endif
#if( /* {private TryReceiveAndProcessData}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaUdp< TResult_ >::TryReceiveAndProcessData()
   {
      #pragma region

      // Visible universe.
      //    {::Poco::TimeoutException}.
      //       Catch.
      //    {::Common::Networking::TNetworkingHelpers::SocketReceiveTimeoutTimeSpanMillisecondsAdjustment}.
      //       Use.
      //    {EconomicReportReceptionTimeoutTimeSpanMilliseconds_}.
      //       Use.
      //    {DateTimeKeeper_.Get...}.
      //       Call.
      //    {EconomicReportReleaseDateTimeMillisecondsSince1970_}.
      //       Use.
      //    {PeerStrategyBaseModeCode_}.
      //       Use.
      //    {Result.PrepareReceiveDatagram}.
      //       Call.
      //       yg? See a related comment in the whole class visible universe.
      //    {Result.DatagramBuffer()}.
      //       Use, update content.
      //       yg? See a related comment in the whole class visible universe.
      //    {Result.DatagramBufferCapacity()}.
      //       Use.
      //       yg? See a related comment in the whole class visible universe.
      //    {Result.TryParseDatagramBuffer}.
      //       Call.
      //       yg? See a related comment in the whole class visible universe.
      //    {OutcomeCode_}.
      //       Update.
      //    {Socket_.receiveBytes}.
      //       Call.
      //    {Socket_.setReceiveTimeout}.
      //       Call.
      //    {SocketStateIsValid_}.
      //       Update.

      #pragma endregion
      #pragma region

      // yg? Consider making this variable a class member, like in {TEconomicReportDownloaderWithTcpParallelRequestsBase<>}.
      // yg? The strategy also calculates this -- redundant.
      int economicReportReleaseTimeMilliseconds
         ( DateTimeKeeper_->GetTimerTickCounter( static_cast< double >( EconomicReportReleaseDateTimeMillisecondsSince1970_ ) ) );

      int economicReportReceptionTimeoutTimeMilliseconds
         ( economicReportReleaseTimeMilliseconds + EconomicReportReceptionTimeoutTimeSpanMilliseconds_ );

      #pragma endregion
      #pragma region

      for( ; ; )
      {
         #pragma region

//TODO is this validation needed? reflect in visible universe
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );

         #pragma endregion
         #pragma region

         {
            int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
            int economicReportReceptionTimeoutTimeSpanMilliseconds
               ( economicReportReceptionTimeoutTimeMilliseconds - currentTimeMilliseconds );
            
            if( economicReportReceptionTimeoutTimeSpanMilliseconds > 0 )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

            label1:
               {
                  static char const constantString1AsArray[]( "{Prototype52::TEconomicReportReceiverViaUdp<TResult_>} timed out" );
                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
               
                  if( PeerStrategyBaseModeCode_ == TPeerStrategyBaseModeCode_Test )
                  {
                     logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                  }
                  else
                  {
                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                  }
               }

               //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

               // It's potentially possible that we will break the loop without making a single receive attempt.
               // Another option would be to force at least 1 non-blocking receive attempt
               // or to check if any data is available for reading.
               // But keeping it simple.
               break;
            }
            
            economicReportReceptionTimeoutTimeSpanMilliseconds +=
               ::Common::Networking::TNetworkingHelpers::SocketReceiveTimeoutTimeSpanMillisecondsAdjustment;

            // A 0 timeout would be interpreted as infinity.
            // If {::Common::Networking::TNetworkingHelpers::SocketReceiveTimeoutTimeSpanMillisecondsAdjustment == 0},
            // the compiler should be able to eliminate both the preceeding addition and this condition check.
            if( economicReportReceptionTimeoutTimeSpanMilliseconds > 0 )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // Becuse of this we can exceed the timeout by many milliseconds.
               // Even if the configured timeout is at least 501 ms, if we receive a datagram short before the timeout exprires
               // and then begin another receive operation we can still exceed the timeout.
               economicReportReceptionTimeoutTimeSpanMilliseconds = 1;
            }

            // On Windows, POCO will divide this by 1000 and truncate the remainder.
            // yg? On Windows this probably tends to over-wait by a millisecond.
            // yg? On Linux, it might be more correct to subtract 499 from the result.
            // yg? We don't need high accuracy here, so keeping it simple.
            // yg? To be tested on Linux.
            // This can't overflow.
            ::Poco::Timespan economicReportReceptionTimeoutTimeSpan
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
               ( economicReportReceptionTimeoutTimeSpanMilliseconds * ::Poco::Timespan::MILLISECONDS );

            // yg? Assuming this will not throw an exception.
            Socket_.setReceiveTimeout( economicReportReceptionTimeoutTimeSpan );
         }

         #pragma endregion
         #pragma region

         // This will not be called if we break the loop above.
         Result.PrepareReceiveDatagram();

         #pragma endregion
         #pragma region

         {
            #pragma region

            int numberBytesReceived;

            #pragma endregion
            #pragma region

            try
            {
               // This will throw an exception if someone sends us a bigger datagram. I don't want to handle that case in any special way.
               numberBytesReceived =
                  Socket_.receiveBytes( reinterpret_cast< void * >( Result.DatagramBuffer() ), Result.DatagramBufferCapacity(), 0 );
            }
            catch( ::Poco::TimeoutException const & /*exception1*/ )

            // Socket state is now indeterminate.
            {
               //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//TODO remove validation? reflect in visible universe
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );
               SocketStateIsValid_ = false;
               //break;
               goto label1;
            }

            // Catching only POCO exceptions. Assuming this exception is not critical.
            catch( ::Poco::Exception const & exception1 )

            {
               {
                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                  logger1.log( exception1 );
               }

               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//TODO remove validation? reflect in visible universe
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );
               SocketStateIsValid_ = false;
               break;
            }

            #pragma endregion
            #pragma region

            // It's documented that this method shall log any errors.
//TODO verify this. this used to compare numberBytesReceived to sizeof( Result )
            if( Result.TryParseDatagramBuffer( numberBytesReceived ) )

            {
               // {EconomicReportReceptionTimeStampMilliseconds_} remains uninitialized.

//TODO not validating this and going to remove other validations
               OutcomeCode_ = TEconomicReportReceiverOutcomeCode_Success;
               return;
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               //continue;
            }

            #pragma endregion
         }

         #pragma endregion
//TODO remove
//         #pragma region
//
//         // It's documented that this is required to log any errors.
//         if( Result.TryValidate() )
//
//         {
//            // {EconomicReportReceptionTimeStampMilliseconds_} remains uninitialized.
//
////TODO remove validation? reflect in visible universe
//            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
//            OutcomeCode_ = TEconomicReportReceiverOutcomeCode_Success;
//            return;
//         }
//         else
//         {
//            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
//         }
//
//         #pragma endregion
      }

      #pragma endregion
      #pragma region

//TODO remove validation? reflect in visible universe
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
      OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError;

      #pragma endregion
   }

#endif
}
