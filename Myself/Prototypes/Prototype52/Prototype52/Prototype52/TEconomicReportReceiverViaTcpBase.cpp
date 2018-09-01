#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportReceiverViaTcpBase.hpp"

#include "../Common/Networking/TStreamSocketWithDataBuffer.cpp"
#include "./TEconomicReportReceiverBase.cpp"
#include "./TEconomicReportReceiverViaTcpBaseConfiguration.cpp"
#include "../Common/Networking/TNetworkingHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {private ConstantString15AsArray_}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // This is effectively inline but should not be.
   template
      < typename TResult_
      >
   char const TEconomicReportReceiverViaTcpBase< TResult_ >::ConstantString15AsArray_[]( "(an exception was thrown on reception)" );

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::ConstantString15StaticAssertion()
   {
      // TODO 3 yg?? Bug: this actually does nothing in a templated class -- revisit.
      static_assert( static_cast< unsigned int >( ConstantString15Length_ ) == ( sizeof( ConstantString15AsArray_ ) / sizeof( ConstantString15AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString16AsArray_}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // This is effectively inline but should not be.
   template
      < typename TResult_
      >
   char const TEconomicReportReceiverViaTcpBase< TResult_ >::ConstantString16AsArray_[]( "(zero bytes were read)" );

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::ConstantString16StaticAssertion()
   {
      // TODO 3 yg?? Bug: this actually does nothing in a templated class -- revisit.
      static_assert( static_cast< unsigned int >( ConstantString16Length_ ) == ( sizeof( ConstantString16AsArray_ ) / sizeof( ConstantString16AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString18AsArray_}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // This is effectively inline but should not be.
   // yg? In a common case this should use the word "data" instead of "text".
   template
      < typename TResult_
      >
   char const TEconomicReportReceiverViaTcpBase< TResult_ >::ConstantString18AsArray_[]( "(remaining text was read later)" );

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::ConstantString18StaticAssertion()
   {
      // TODO 3 yg?? Bug: this actually does nothing in a templated class -- revisit.
      static_assert( static_cast< unsigned int >( ConstantString18Length_ ) == ( sizeof( ConstantString18AsArray_ ) / sizeof( ConstantString18AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif

#if( /* {protected} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportReceiverViaTcpBase< TResult_ >::TEconomicReportReceiverViaTcpBase() :
      EconomicReportSenderSocketAddress_( ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress ),
      LocalSocketAddress_( ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress )
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {protected} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportReceiverViaTcpBase< TResult_ >::TEconomicReportReceiverViaTcpBase
      ( TEconomicReportReceiverViaTcpBaseConfiguration && configuration1
      ) :
      TEconomicReportReceiverBase< TResult_ >( ::std::move( configuration1 ) ),
      EconomicReportSenderIPHostName_( ::std::move( configuration1.EconomicReportSenderIPHostName ) ),
      LocalIPHostName_( ::std::move( configuration1.LocalIPHostName ) ),
      EconomicReportSenderSocketAddress_( ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress ),
      LocalSocketAddress_( ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress )
   {
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
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::Initialize
      ( TEconomicReportReceiverViaTcpBaseConfiguration && configuration1
      )
   {
      TEconomicReportReceiverBase< TResult_ >::Initialize( ::std::move( configuration1 ) );

      EconomicReportSenderIPHostName_.assign( ::std::move( configuration1.EconomicReportSenderIPHostName ) );
      LocalIPHostName_.assign( ::std::move( configuration1.LocalIPHostName ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::DoInitialize
      ( TEconomicReportReceiverViaTcpBaseConfiguration && configuration1
      )
   {
// TODO 2 yg? Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
// TODO 2 yg? Refer to it from consrtructors, destructors, {Initialize}.

      EconomicReportSenderIPPortNumber_ = ::std::move( configuration1.EconomicReportSenderIPPortNumber );
      //SocketKeepAliveTimeoutTimeSpanMilliseconds_ = ::std::move( configuration1.SocketKeepAliveTimeoutTimeSpanMilliseconds );
      //SocketKeepAliveIntervalMilliseconds_ = ::std::move( configuration1.SocketKeepAliveIntervalMilliseconds );
      SocketStateIsValid_ = false;
      //SocketDataBufferParsingOffset_ = ???
      CanLogActivityReport_ = false;
      TryMakeWarmUpStepIsRunning_ = false;
   }

#endif
#if( /* {public Prepare}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::Prepare
      ( ::Common::Time::TDateTimeKeeper const & dateTimeKeeper
      )
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr()}.
      //       Validate.
      //    {Prepare} -- base.
      //       Override, call.
      //    {EconomicReportSenderIPHostName_}.
      //       Use, release resources.
      //    {EconomicReportSenderIPPortNumber_}.
      //       Use.
      //    {LocalIPHostName_}.
      //       Use, release resources.
      //    {EconomicReportSenderSocketAddress_.swap}.
      //       Call.
      //    {LocalSocketAddress_.addr()}.
      //       Validate.
      //    {LocalSocketAddress_.swap}.
      //       Call.

      TEconomicReportReceiverBase< TResult_ >::Prepare( dateTimeKeeper );

      {
         // IP address resolutin takes time and can throw an exception, which is why this code must run on application start.
         // We could try to repeat the resolution attempt but keeping it simple.
         // We will not resolve the IP addresses any more, no matter for how long the application runs.
         ::Poco::Net::SocketAddress socketAddress1( EconomicReportSenderIPHostName_, EconomicReportSenderIPPortNumber_ );

         {
            // Releasing the resources we don't need any more.
            ::std::string dummy1( ::std::move( EconomicReportSenderIPHostName_ ) );
         }

         // yg? This doesn't have a move assignment operator.
         EconomicReportSenderSocketAddress_.swap( socketAddress1 );
      }

      // We rely on this assumption elsewhere.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( LocalSocketAddress_.addr() == ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr() );

      if( ! LocalIPHostName_.empty() )
      {
         {
            // yg? Same comments as above apply.
            ::Poco::Net::SocketAddress socketAddress1( LocalIPHostName_, static_cast< unsigned short >( 0U ) );
            LocalSocketAddress_.swap( socketAddress1 );
         }

         // We rely on this assumption elsewhere.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( LocalSocketAddress_.addr() != ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr() );
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      {
         // Releasing the resources we don't need any more.
         ::std::string dummy1( ::std::move( LocalIPHostName_ ) );
      }
   }

#endif
#if( /* {protected DoTryRun}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline /*bool*/ void TEconomicReportReceiverViaTcpBase< TResult_ >::DoTryRun()
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {OutcomeCode_}.
      //       Update.
      //    {DoTryRun} -- base.
      //       Implement.
      //    {SocketStateIsValid_}.
      //       Use.
      //    {CanLogActivityReport_}.
      //       Validate, update.
      //    {TryMakeWarmUpStepIsRunning_}.
      //       Use.
      //    {TryAsyncTryConnectToEconomicReportSender}.
      //       Call.
      //    {TryReceiveAndProcessData}.
      //       Call.

      //base->DoTryRun

      if( ! SocketStateIsValid_ )
      {
         if( TryMakeWarmUpStepIsRunning_ )
         {
            // This logs something on any outcome and doesn't set {CanLogActivityReport_}.
            // See related validations in {LogActivityReportIfPossible}.
            TryAsyncTryConnectToEconomicReportSender();
         }
         else

         // In this case we only log an error but don't begin to connect and don't set {CanLogActivityReport_}.
         // See related validations in {LogActivityReportIfPossible}.
         // Before calling {TryRun} the caller must call {TryMakeWarmUpStep} at least once.
         // Another option would be to make a best effort to connect and receive data but keeping it simple.
         {
            static char const constantString1AsArray[]
               ( "{Prototype52::TEconomicReportReceiverViaTcpBase<TResult_>::SocketStateIsValid_ == false}" );
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         // This is valid if the caller called {LogActivityReportIfPossible} after {TryRun}.
         // This remains unchanged.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! CanLogActivityReport_ );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
         OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError;
      }
      else
      {
         // This is valid if the caller called {LogActivityReportIfPossible} after {TryRun}.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! CanLogActivityReport_ );

         // Should this be done by {TryReceiveAndProcessData}? For now I am happy with the way it is.
         CanLogActivityReport_ = true;
      
         TryReceiveAndProcessData();
      }
   }

#endif

#if( /* {public TryMakeWarmUpStep}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline bool TEconomicReportReceiverViaTcpBase< TResult_ >::TryMakeWarmUpStep()
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {DateTimeKeeper_->Get...}.
      //       Call.
      //    {OutcomeCode_}.
      //       Use.
      //    {TryRun}.
      //       Call.
      //    {TryMakeWarmUpStep} -- base.
      //       Override, call.
      //    {TryCreateNewsHubMessage}.
      //       Call.
      //    {TryMakeWarmUpStepIsRunning_}.
      //       Update.
      //    {LogActivityReportIfPossible}.
      //       Call.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TryMakeWarmUpStepIsRunning_ );
      TryMakeWarmUpStepIsRunning_ = true;

      TEconomicReportReceiverBase< TResult_ >::TryMakeWarmUpStep();

      {
         int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );

         // It might be a good idea to decrement this to ensure that {economicReportReleaseDateTimeMillisecondsSince1970}
         // is not 1 ms in the future but when {TryMakeWarmUpStepIsRunning_} we don't block anyway.
         // Note that when {! TryMakeWarmUpStepIsRunning_} this time would be interpreted as
         // receive timeout already expired and therefore no receive attempt would be made.
         int economicReportReleaseTimeMilliseconds( currentTimeMilliseconds /* - InvocationTimeOffsetMilliseconds()*/ );

         ::Poco::Int64 economicReportReleaseDateTimeMillisecondsSince1970
            ( DateTimeKeeper_->GetDateTimeMillisecondsAsInteger< ::Poco::Int64 >( economicReportReleaseTimeMilliseconds ) );

         // Unconditionally using {TPeerStrategyBaseModeCode_Test}.
         TryRun( economicReportReleaseDateTimeMillisecondsSince1970, TPeerStrategyBaseModeCode_Test );
      }

      if( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success )
      {
         TryCreateNewsHubMessage();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      LogActivityReportIfPossible();
      //CompleteWarmUpStep();

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TryMakeWarmUpStepIsRunning_ );
      TryMakeWarmUpStepIsRunning_ = false;

      // Telling the strategy that we are now warm. It will keep calling {TryMakeWarmUpStep}.
      return true;
   }

#endif

#if( /* {public LogActivityReportIfPossible}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::LogActivityReportIfPossible()
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {LogActivityReportIfPossible} -- base.
      //       Implement.
      //    {Socket_.available}.
      //       Call.
      //    {Socket_.close}.
      //       Call.
      //    {Socket_.impl()->initialized()}.
      //       Validate.
      //    {Socket_.DataBuffer().AllocateAdditionalCapacityIfNeeded}.
      //       Call.
      //    {Socket_.DataBuffer().Append}.
      //       Call.
      //    {Socket_.DataBufferCapacityMaxLimit()}.
      //       Use.
      //    {Socket_.ReceiveBytesIntoDataBuffer}.
      //       Call.
      //    {SocketStateIsValid_}.
      //       Validate, use, update.
      //    {CanLogActivityReport_}.
      //       Use, update.
      //    {TryMakeWarmUpStepIsRunning_}.
      //       Validate, use.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.
      //    {RemoveParsedReceivedData}.
      //       Call.
      //    {LogActivityReport}.
      //       Call.

      //base->LogActivityReportIfPossible

      if( ! CanLogActivityReport_ )
      {
         //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         // {LogActivityReportIfPossible} shall ensure that these two are in sync -- by design.
         // We can ensure this by closing socket handle if one exists.
         // This validates that these two are in sync at this point, so we have nothing to do.
         // Note that it's never possible that socket handle doesn't exist but {SocketStateIsValid_}.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ == Socket_.impl()->initialized() );

         // When {! TryMakeWarmUpStepIsRunning_}, {LogActivityReportIfPossible} shall clear {SocketStateIsValid_} if it's {true}
         // and close socket handle if one exists -- by design.
         // This validates that it's impossible that {! TryMakeWarmUpStepIsRunning_} but socket handle exists, so we have nothing to do.
         // Note that when at this point {TryMakeWarmUpStepIsRunning_}, the existence of socked handle is undefined.
         // This validation, combined with the preceeding one ensures that when {! TryMakeWarmUpStepIsRunning_}:
         // {! SocketStateIsValid_}, which further confirms that we have nothing to do.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TryMakeWarmUpStepIsRunning_ || ( ! Socket_.impl()->initialized() ) );
      
         return;
      }
      else
      {
         // Socket handle is guaranteed to exist.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Socket_.impl()->initialized() );

         CanLogActivityReport_ = false;
      }

      if( TryMakeWarmUpStepIsRunning_ )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         // We always close socket handle when {TryMakeWarmUpStep} is not running as the strategy is about to terminate.
         // But some day I might need to revisit this logic.
         SocketStateIsValid_ = false;
      }

      if( SocketStateIsValid_ )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         // This can't tell us if the counterparty closed the connection. Regardless, we probably don't need to append
         // {ConstantString16AsArray_} here.
         // yg? Assuming this will not throw an exception, even if the socket is still connecting or its state is indeterminate.
         int numberBytesAvailable( Socket_.available() );

         if( numberBytesAvailable > 0 )
         {
            // We will not try to parse this.
            // Expecting that the buffer is not empty. Otherwise we would assign rather than append.
            Socket_.DataBuffer().Append( ConstantString18AsArray_, static_cast< unsigned int >( ConstantString18Length_ ) );

            try
            {
               Socket_.DataBuffer().AllocateAdditionalCapacityIfNeeded
                  ( static_cast< unsigned int >( numberBytesAvailable ), 1U, Socket_.DataBufferCapacityMaxLimit() );

               // We try to read any arrived data even if previous receive timed out and socket state is therefore indeterminate.
               // Is it potentially possible that this will not read all available data? Even if so keeping it simple.
               // It's probably impossible that this reads 0 bytes after {Socket_.available}
               // returned a positive number but in any case there will be no incorrect behavior and we probably don't need to append
               // {ConstantString16AsArray_} here.
               Socket_.ReceiveBytesIntoDataBuffer( 0 );
            }

            // Catching only POCO exceptions. Assuming this exception is not critical.
            catch( ::Poco::Exception const & exception1 )

            {
               {
                  ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                  logger1.log( exception1 );
               }

               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

               // We will not try to parse this.
               // Expecting that the buffer is not empty. Otherwise we would assign rather than append.
               Socket_.DataBuffer().Append( ConstantString15AsArray_, static_cast< unsigned int >( ConstantString15Length_ ) );

               // Socket handle state is now invalid but we don't need to clear {SocketStateIsValid_} at this point.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! SocketStateIsValid_ );
            }
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
      }

      LogActivityReport();

      // We validated above that this code doesn't need to run when {! CanLogActivityReport_}.
      // In that case we don't need to call {RemoveParsedReceivedData} as we need to log any data before we remove it,
      // and furthermore, when {! CanLogActivityReport_} we haven't received any data yet and {SocketDataBufferParsingOffset_}
      // is undefined.
      {
         if( SocketStateIsValid_ )
         {
            // It's possible that this won't remove some data, which implies that we can log the same data multiple times.
            RemoveParsedReceivedData();
         }
         else
         {
            // We have already cleared this flag.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! SocketStateIsValid_ );

            // Socket data buffer remains available for reuse.
            // We will reset its {DalaLengh} after we create another socket handle.
            // yg? Assuming this will not throw an exception.
            Socket_.close();

            // In case {TryMakeWarmUpStep} is running it might be a good idea to begin reconnecting immediately but keeping it simple.
            // Note that NewsHub manual says that we should reconnect in 60 seconds.
         }
      }
   }

#endif
#if( /* {private RemoveParsedReceivedData}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::RemoveParsedReceivedData()
   {
      // Visible universe.
      //    {Socket_.DataBuffer()}.
      //       Update.
      //    {Socket_.DataBuffer().length()}.
      //       Validate.
      //    {Socket_.DataBuffer().DataLength}.
      //       Validate, use, update.
      //    {SocketDataBufferParsingOffset_}.
      //       Validate, use, update.

      // We don't need to do anything when {SocketDataBufferParsingOffset_ == 0}.
      // We don't need to move data when
      // {static_cast< unsigned int >( SocketDataBufferParsingOffset_ ) == Socket_.DataBuffer().DataLength}.
      // But keeping it simple. Those extra condition checks would probably be an unwanted overhead.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Socket_.DataBuffer().DataLength <= Socket_.DataBuffer().length() );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketDataBufferParsingOffset_ >= 0 );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( static_cast< unsigned int >( SocketDataBufferParsingOffset_ ) <= Socket_.DataBuffer().DataLength );
      Socket_.DataBuffer().DataLength -= static_cast< unsigned int >( SocketDataBufferParsingOffset_ );

      // {...::copy} might work too and might be more efficient but this code is not performance critical.
      ::Common::DataStructures::TDataBuffer::traits_type::move
         ( ( & Socket_.DataBuffer().front() ),
           ( & Socket_.DataBuffer().at( static_cast< unsigned int >( SocketDataBufferParsingOffset_ ) ) ),
           Socket_.DataBuffer().DataLength
         );

      SocketDataBufferParsingOffset_ = 0;
   }

#endif

#if( /* {private TryAsyncTryConnectToEconomicReportSender}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::TryAsyncTryConnectToEconomicReportSender()
   {
      // Visible universe.
      //    {::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr()}.
      //       Use.
      //    //{::Common::Networking::TStreamSocketWithDataBuffer::bind}.
      //    //   Call.
      //    //{::Common::Networking::TStreamSocketWithDataBuffer::connectNB}.
      //    //   Call.
      //    {EconomicReportSenderSocketAddress_}.
      //       Use.
      //    {LocalSocketAddress_}.
      //       Use.
      //    {LocalSocketAddress_.addr()}.
      //       Use.
      //    //{Socket_}.
      //    //   Update.
      //    {Socket_.bind}.
      //       Call.
      //    {Socket_.close}.
      //       Call.
      //    {Socket_.connectNB}.
      //       Call.
      //    {Socket_.impl()->initialized()}.
      //       Validate.
      //    {Socket_.init}.
      //       Call.
      //    {Socket_.DataBuffer().DataLength}.
      //       Update.
      //    {SocketStateIsValid_}.
      //       Validate, update.
      //    {SocketDataBufferParsingOffset_}.
      //       Update.
      //    {ConfigureSocket}.
      //       Call.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! SocketStateIsValid_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! Socket_.impl()->initialized() );

      {
         // We will log something on any outcome.
         // We will not log an activity report.
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

         {
            //::Common::Networking::TStreamSocketWithDataBuffer socket1( ::Poco::Net::IPAddress::Family::IPv4 );
            Socket_.init( AF_INET );
            //ConfigureSocket( socket1 );
            ConfigureSocket();

            if( LocalSocketAddress_.addr() != ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr() )
            {
               // yg? Assuming this will not throw an exception unless the IP address is invalid.
               //socket1.bind( LocalSocketAddress_, false );
               Socket_.bind( LocalSocketAddress_, false );
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }

            try
            {
               // After this the socket will stay in non-blocking mode.
               // If this throws an exception we don't need to assign/append an error message to data buffer.
               //socket1.connectNB( EconomicReportSenderSocketAddress_ );
               Socket_.connectNB( EconomicReportSenderSocketAddress_ );
            }

            // Catching only POCO exceptions. Assuming this exception is not critical.
            catch( ::Poco::Exception const & exception1 )

            {
               {
                  //::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                  logger1.log( exception1 );
               }

               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

               // Resetting {Socket_.impl()->initialized()} back to what it was at the beginning.
               // yg? Assuming this will not throw an exception.
               Socket_.close();

               // This remains unchanged.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! SocketStateIsValid_ );

               return;
            }

            //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! Socket_.impl()->initialized() );

            //// yg? This is actually copying rather than moving. I don't want to code proper moving.
            //Socket_ = ::std::move( socket1 );
         }

         // This is needed in case we already received some data and then closed socket handle.
         Socket_.DataBuffer().DataLength = 0U;

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! SocketStateIsValid_ );
         SocketStateIsValid_ = true;
         SocketDataBufferParsingOffset_ = 0;

         {
            static char const constantString1AsArray[]( "{Prototype52::TEconomicReportReceiverViaTcpBase<TResult_>} began connecting" );
            //::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }
      }
   }

#endif
#if( /* {protected ConfigureSocket}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::ConfigureSocket()
   {
      // This method is virtual and inline.
      // I don't want to write down visible universe here.

      //::Common::Networking::TNetworkingHelpers::SetSocketKeepAliveMode
      //   ( Socket_.impl()->sockfd(), true, SocketKeepAliveTimeoutTimeSpanMilliseconds_, SocketKeepAliveIntervalMilliseconds_ );

      // I feel that a subclass should decide if it needs this.
      //Socket_.setNoDelay( true );

      // A subclass might need this.
      //Socket_.setLinger( true, 0 );

      // This will succeed (but also can fail) only after establishing the connection.
      // yg? Perhaps this should be done at some point to achieve maximum performance.
      // yg? But this must only be done by a subclass that knows that it will not send anything.
      //Socket_.shutdownSend();
   }

#endif
#if( /* {private TryReceiveAndProcessData}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverViaTcpBase< TResult_ >::TryReceiveAndProcessData()
   {
      #pragma region

      // In case data buffer is not empty we already tried to parse the data in it and determined that it's incomplete,
      // so we will attempt another parsing only if we receive more data.
      // The logic will be the same if this run is not a warm-up step, which can potentially result in some warm-up data parsing,
      // which currently is probably not a problem.

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
      //    {OutcomeCode_}.
      //       Validate, update.
      //    {Socket_.getBlocking()}.
      //       Validate.
      //    {Socket_.setBlocking}.
      //       Call.
      //    {Socket_.setReceiveTimeout}.
      //       Call.
      //    {Socket_.DataBuffer().Append}.
      //       Call.
      //    {Socket_.ReceiveBytesIntoDataBuffer}.
      //       Call.
      //    {SocketStateIsValid_}.
      //       Validate, update.
      //    {TryMakeWarmUpStepIsRunning_}.
      //       Use.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.
      //    {TrySendHeartBeatMessage}.
      //       Call.
      //    {TryParseReceivedData}.
      //       Call.

      #pragma endregion
      #pragma region

      {
         #pragma region

         // We validate this after we call {TrySendHeartBeatMessage}, so let's validate it before as well.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );

         // It's documented that {TrySendHeartBeatMessage} is called when the socket is in non-blocking mode.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! Socket_.getBlocking() );

         bool trySendHeartBeatMessageSucceeded( TrySendHeartBeatMessage() );

         // It's documented that {TrySendHeartBeatMessage} clears {SocketStateIsValid_} on error.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ == trySendHeartBeatMessageSucceeded );

         // It's documented that {TrySendHeartBeatMessage} doesn't change socket blocking mode.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! Socket_.getBlocking() );

         #pragma endregion
         #pragma region

         if( trySendHeartBeatMessageSucceeded )
         {
            #pragma region

            if( TryMakeWarmUpStepIsRunning_ )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // yg? Assuming this will not throw an exception.
               Socket_.setBlocking( true );

               //// This will fail if a non-blocking connect is still in progress. But {TrySendHeartBeatMessage} would have already failed
               //// provided it actually sends something.
               //::Common::Networking::TNetworkingHelpers::TrySetSocketKeepAliveMode( Socket_, false );
            }

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

               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );

               #pragma endregion
               #pragma region

               // When the socket is in blocking mode we will set its receive timeout.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Socket_.getBlocking() != TryMakeWarmUpStepIsRunning_ );
               if( TryMakeWarmUpStepIsRunning_ )
               {
                  #pragma region

                  // At this point, if this is not the 1st loop one might want to return but keeping it simple.
                  // However this makes it potentially possible to enter an infinite loop
                  // if the counterparty keeps sending us something often enough. Although in that case we would actually reach
                  // buffer length limit momentarily.

                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();

                  #pragma endregion
               }
               else
               {
                  #pragma region

                  // If we received (and parsed) incomplete data on previous loop it would be better to skip the timeout setting
                  // for performance reasons but that can result in exceeding the timeout.
                  // Another option would be to check if any data is available for reading and if so skip the timeout setting.
                  // However that would make it potentially possible to enter an infinite loop
                  // if the counterparty keeps sending us something often enough. Although in that case we would actually reach
                  // buffer length limit momentarily.
                  // But keeping it simple.
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
                        // Even if the configured timeout is at least 501 ms, if we receive a part of a message or an unrelated message
                        // short before the timeout expires and then begin another receive operation we can still exceed the timeout.
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
               }

               #pragma endregion
               #pragma region

               {
                  #pragma region

                  int numberBytesReceived;

                  #pragma endregion
                  #pragma region

                  try
                  {
                     #pragma region

                     numberBytesReceived = Socket_.ReceiveBytesIntoDataBuffer( 0 );

                     // This might act as an optimization hint.
                     // If this condition was {false} an exception would have been thrown.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesReceived >= 0 );
                  
                     #pragma endregion
                  }
                  catch( ::Poco::TimeoutException const & /*exception1*/ )
                  {
                     #pragma region

                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Socket_.getBlocking() != TryMakeWarmUpStepIsRunning_ );

                     // Checking if this is a "would block" error.
                     if( TryMakeWarmUpStepIsRunning_ )

                     {
                        break;
                     }

                     // So this is really a timeout error (not "would block").
                     else

                     // Socket state is now indeterminate.
                     {
                        // It's unnecessary to log this as what happened will anyway be clear based on activity report.
                        // If I uncomment this logging I'd need move it to where we break the loop
                        // when we have no time left until the timeout expires, like in {TEconomicReportReceiverViaUdp<>}.
                        //{
                        //   static char const constantString1AsArray[]( "{Prototype52::TEconomicReportReceiverViaTcpBase<TResult_>} timed out" );
                        //   ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                        //
                        //   if( IsWarmUpOrTestMode_ )
                        //   {
                        //      logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                        //   }
                        //   else
                        //   {
                        //      logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                        //   }
                        //}

                        //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

                        // We don't need to append {ConstantString15AsArray_} here.

                        numberBytesReceived = ::std::numeric_limits< int >::lowest();
                     }
                  
                     #pragma endregion
                  }

                  // Catching only POCO exceptions. Assuming this exception is not critical.
                  catch( ::Poco::Exception const & exception1 )

                  {
                     #pragma region

                     {
                        ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                        logger1.log( exception1 );
                     }

                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

                     // We will not try to parse this.
                     // Expecting that the buffer is not empty. Otherwise we would assign rather than append.
                     Socket_.DataBuffer().Append( ConstantString15AsArray_, static_cast< unsigned int >( ConstantString15Length_ ) );

                     numberBytesReceived = ::std::numeric_limits< int >::lowest();

                     #pragma endregion
                  }

                  #pragma endregion
                  #pragma region

                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                     ( numberBytesReceived >= 0 || numberBytesReceived == ::std::numeric_limits< int >::lowest() );
                  if( numberBytesReceived > 0 )
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     if( numberBytesReceived == 0 )
                     {
                        {
                           static char const constantString1AsArray[]( "economic report sender disconnected" );
                           ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
//TODO error?
                           logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                        }

                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

                        // yg? Consider either appending this string or logging this error, not both.
                        // We will not try to parse this.
                        // Expecting that the buffer is not empty. Otherwise we would assign rather than append.
                        Socket_.DataBuffer().Append( ConstantString16AsArray_, static_cast< unsigned int >( ConstantString16Length_ ) );
                     }
                     else
                     {
                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                     }

                     // Clearing this flag under the following conditions:
                     // - On any exception, including timeout, except a "would block" error.
                     // - If 0 bytes were read as that indicates a disconnection.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );
                     SocketStateIsValid_ = false;

                     break;
                  }

                  #pragma endregion
               }

               #pragma endregion
               #pragma region

               {
                  // We will validate these after we call {TryParseReceivedData}, so let's valiate these before as well.
                  {
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                        ( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
                  
                     // I commented this validation out below, so I commented it out here as well.
                     //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );
                  }

                  unsigned int receivedDataParsingOutcomeCode( TryParseReceivedData() );
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                     ( ( receivedDataParsingOutcomeCode == 1U && OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success ) ||
                       ( receivedDataParsingOutcomeCode == 2U && OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined ) ||
                       //( receivedDataParsingOutcomeCode == 4U && OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined ) ||
                       ( receivedDataParsingOutcomeCode == 8U &&
                         OutcomeCode_ == TEconomicReportReceiverOutcomeCode_OtherError //&&

                         // It's really not required to clear {SocketStateIsValid_} on a severe (or any other) error, so let's not validate this.
                         //( ! SocketStateIsValid_ )
                       )
                     );

                  if( receivedDataParsingOutcomeCode == 2U )
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }
                  else
                  {
                     return;
                  }
               }

               #pragma endregion
            }

            #pragma endregion
         }
         else
         {
            #pragma region

            //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();

            #pragma endregion
         }

         #pragma endregion
      }

      #pragma endregion
      #pragma region

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
      OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError;

      #pragma endregion
   }

#endif
#if( /* {protected TrySendHeartBeatMessage}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline bool TEconomicReportReceiverViaTcpBase< TResult_ >::TrySendHeartBeatMessage()
   {
      // This method is virtual and inline.
      // yg? See a bug related comment near this method declaration.
      // I don't want to write down visible universe here.

      // This {TrySendHeartBeatMessage} implementation should really not be used, so let's stop.
      // But it might be possible to implement a subclass that detects a broken connection by some other means,
      // so some day I might need to eliminate this stop.
      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

      return true;
   }

#endif
#if( /* {protected TryParseReceivedData}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and inline.

#endif
#if( /* //{protected CompleteWarmUpStep}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // yg? I eliminated this method but parts of the comment in it might still make sense.

   //template
   //   < typename TResult_
   //   >
   //inline void TEconomicReportReceiverViaTcpBase< TResult_ >::CompleteWarmUpStep()
   //{
   //   // This method is virtual and inline.
   //
////  Do we really need all the validations below?
   //
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TryMakeWarmUpStepIsRunning_ );
   //
   //   // These will be the case if the caller called {LogActivityReportIfPossible} after {TryRun}, which {TryMakeWarmUpStep} does.
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! CanLogActivityReport_ );
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ == Socket_.impl()->initialized() );
   //
   //   // This can result in a loss of a partianlly received message and subsequent attempt to parse the end of it.
   //   // If that's a problem an override of this method should remove any complete (and already parsed) messages
   //   // at the beginning of data buffer and/or ensure that data length is not too long.
   //   // But if no new data was received during a warm-up run and data buffer still contains some incomplete data it would need to assume
   //   // that the rest was lost and clear the buffer, or, yet better, clear the {SocketStateIsValid_} flag and close {Socket_}.
   //   // One way to implement this is to have a {TryMakeWarmUpStep} method override to save data length and
   //   // a {CompleteWarmUpStep} method override to compare current data length with the saved one.
   //   // It would also be nice to ensure that when a non-warm-up-step run begins the data buffer is empty
   //   // as otherwise some warm-up data would be processed as real data. But at this point it's unknown if the next run is going to be a warm-up step.
   //   // yg? We might need another virtual method to get notified that there will be no more warm-up steps.
   //   // yg? It also will have a chance to start connecting if needed.
   //   // Note that when {TryMakeWarmUpStepIsRunning_ && SocketStateIsValid_} the {LogActivityReportIfPossible} method
   //   // does not try to receive any pending data, so at this point any data in data buffer has been parsed, possibly unsuccessfully
   //   // because only a part of it was received. If we receive more data via this connection we will append it to data buffer and parse the whole data buffer.
   //   // It's unnecessary but OK to execute this code after we have just initiated a new connection, when {! SocketStateIsValid_},
   //   // and/or after we closed the socket.
   //   // Note that, as validated above, at this point {SocketStateIsValid_} is in sync with the socket's opennes.
   //   Socket_.DataBuffer().DataLength = 0U;
   //}

#endif

#if( /* {protected LogActivityReport}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and inline.

#endif
}
