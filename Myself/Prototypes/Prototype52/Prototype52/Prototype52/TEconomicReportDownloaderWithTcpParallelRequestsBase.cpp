#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportDownloaderWithTcpParallelRequestsBase.hpp"

#include "../Common/Networking/TStreamSocketWithDataBuffer.cpp"
#include "../Common/Networking/TSocketNextDynamicPortNumberAdvancer.cpp"
#include "./TEconomicReportReceiverBase.cpp"
#include "./TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration.cpp"
#include "../Common/Threading/TThreadingHelpers.cpp"
#include "../Common/Math/TMultiplyWithCarryRandomNumberCommonGeneratorHelpers.cpp"
#include "./TTcpRequestConfigurationHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {private TTcpRequestInternalConfiguration_}. */ 1 )
   #if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestInternalConfiguration_::TTcpRequestInternalConfiguration_() :
      LocalSocketAddress( ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress ),
      DestinationSocketAddress( ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress )
   {
   }

   #endif
   #if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
   #if( /* {public} Instance move constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestInternalConfiguration_::TTcpRequestInternalConfiguration_
      ( TTcpRequestInternalConfiguration_ && source
      ) :
      LocalIPHostName( ::std::move( source.LocalIPHostName ) ),
      //LocalSocketAddress( ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress ),
      
      // yg? This is actually copying rather than moving. I don't want to code proper moving.
      LocalSocketAddress( ::std::move( source.LocalSocketAddress ) ),

      ShallAdvanceSocketNextDynamicPortNumber( ::std::move( source.ShallAdvanceSocketNextDynamicPortNumber ) ),
      DestinationUrlAsString( ::std::move( source.DestinationUrlAsString ) ),

      // yg? See comment near {LocalSocketAddress} a few lines above.
      DestinationSocketAddress( ::std::move( source.DestinationSocketAddress ) ),

      RequestContent( ::std::move( source.RequestContent ) ),
      NumberRequestsToSend( ::std::move( source.NumberRequestsToSend ) ),
      RequestsPreSendingBitMask( ::std::move( source.RequestsPreSendingBitMask ) ),
      FirstRequestSendingTimeOffsetMilliseconds( ::std::move( source.FirstRequestSendingTimeOffsetMilliseconds ) ),
      RequestSendingIntervalMilliseconds( ::std::move( source.RequestSendingIntervalMilliseconds ) )
   {
   }

   #endif
   #if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

   #endif
   #if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
   #if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline typename TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestInternalConfiguration_ &
      TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestInternalConfiguration_::operator =
         ( TTcpRequestInternalConfiguration_ && source
         )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

   #endif

   #if( /* {public Prepare}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestInternalConfiguration_::Prepare
      ( TTcpRequestConfiguration && tcpRequestConfiguration
      )
   {
      LocalIPHostName.assign( ::std::move( tcpRequestConfiguration.LocalIPHostName ) );

      // We rely on this assumption elsewhere.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( LocalSocketAddress.addr() == ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr() );

      if( ! LocalIPHostName.empty() )
      {
         // IP address resolutin takes time and can throw an exception, which is why this code must run on application start.
         // We could try to repeat the resolution attempt but keeping it simple.
         // We will not resolve the IP addresses any more, no matter for how long the application runs.
         // yg? This doesn't have a move assignment operator.
         LocalSocketAddress.swap
            ( const_cast< ::Poco::Net::SocketAddress & >
                 ( static_cast< ::Poco::Net::SocketAddress const & >
                      ( ::Poco::Net::SocketAddress( LocalIPHostName, static_cast< unsigned short >( 0U ) ) )
                 )
            );

         // We rely on this assumption elsewhere.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( LocalSocketAddress.addr() != ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr() );
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      ShallAdvanceSocketNextDynamicPortNumber = ::std::move( tcpRequestConfiguration.ShallAdvanceSocketNextDynamicPortNumber );
      DestinationUrlAsString.assign( ::std::move( tcpRequestConfiguration.DestinationUrlAsString ) );
      
      {
         ::Poco::URI uri1( DestinationUrlAsString );

         // yg? See a comment above near a call to {LocalSocketAddress.swap}.
         DestinationSocketAddress.swap
            ( const_cast< ::Poco::Net::SocketAddress & >
                 ( static_cast< ::Poco::Net::SocketAddress const & >
                      ( ::Poco::Net::SocketAddress( uri1.getHost(), uri1.getPort() ) )
                 )
            );
      }
      
      RequestContent.assign( ::std::move( tcpRequestConfiguration.RequestContent ) );
      NumberRequestsToSend = ::std::move( tcpRequestConfiguration.NumberRequestsToSend );
      RequestsPreSendingBitMask = ::std::move( tcpRequestConfiguration.RequestsPreSendingBitMask );
      FirstRequestSendingTimeOffsetMilliseconds = ::std::move( tcpRequestConfiguration.FirstRequestSendingTimeOffsetMilliseconds );
      RequestSendingIntervalMilliseconds = ::std::move( tcpRequestConfiguration.RequestSendingIntervalMilliseconds );
   }

   #endif

   #if( /* {public Assign}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestInternalConfiguration_::Assign
      ( TTcpRequestInternalConfiguration_ && source
      )
   {
      // This implementation will survive a self-assignment.

      LocalIPHostName.assign( ::std::move( source.LocalIPHostName ) );

      // yg? I don't want to code proper moving.
      LocalSocketAddress.swap( source.LocalSocketAddress );
      
      ShallAdvanceSocketNextDynamicPortNumber = ::std::move( source.ShallAdvanceSocketNextDynamicPortNumber );
      DestinationUrlAsString.assign( ::std::move( source.DestinationUrlAsString ) );

      // yg? See a comment near a call to {LocalSocketAddress.swap} a few lines above.
      DestinationSocketAddress.swap( source.DestinationSocketAddress );

      RequestContent.assign( ::std::move( source.RequestContent ) );
      NumberRequestsToSend = ::std::move( source.NumberRequestsToSend );
      RequestsPreSendingBitMask = ::std::move( source.RequestsPreSendingBitMask );
      FirstRequestSendingTimeOffsetMilliseconds = ::std::move( source.FirstRequestSendingTimeOffsetMilliseconds );
      RequestSendingIntervalMilliseconds = ::std::move( source.RequestSendingIntervalMilliseconds );
   }

   #endif
#endif
#if( /* {private TTcpRequestState_}. */ 1 )
   #if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

   #endif
   #if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
   #if( /* {public} Instance move constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestState_::TTcpRequestState_
      ( TTcpRequestState_ && source
      ) :
      TcpRequestInternalConfiguration( ::std::move( source.TcpRequestInternalConfiguration ) ),
      StateCode1( ::std::move( source.StateCode1 ) ),
      
      // yg? This is actually copying rather than moving. I don't want to code proper moving.
      Socket( ::std::move( source.Socket ) )
   {
   }

   #endif
   #if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestState_::TTcpRequestState_
      ( TTcpRequestInternalConfiguration_ const & tcpRequestInternalConfiguration1
      ) :
      TcpRequestInternalConfiguration( & tcpRequestInternalConfiguration1 ),
      //StateCode1( ??? ),

      // This creates a socket handle, which is the right thing to do in this scenario.
      Socket( ::Poco::Net::IPAddress::Family::IPv4 )
   {
   }

   #endif
   #if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

   #endif
   #if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

   #endif
   #if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline typename TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestState_ &
      TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestState_::operator =
         ( TTcpRequestState_ && source
         )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

   #endif

   #if( /* {public Assign}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TTcpRequestState_::Assign
      ( TTcpRequestState_ && source
      )
   {
      // This implementation will survive a self-assignment.

      TcpRequestInternalConfiguration = ::std::move( source.TcpRequestInternalConfiguration );
      StateCode1 = ::std::move( source.StateCode1 );

      // yg? This is actually copying rather than moving. I don't want to code proper moving.
      Socket = ::std::move( source.Socket );
   }

   #endif
#endif

#if( /* {private ConstantString13AsArray_}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // This is effectively inline but should not be.
   template
      < typename TResult_
      >
   char const TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ConstantString13AsArray_[]
      ( "(an exception was thrown on sending)" );

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ConstantString13StaticAssertion()
   {
      // TODO 3 yg?? Bug: this actually does nothing in a templated class -- revisit.
      static_assert( static_cast< unsigned int >( ConstantString13Length_ ) == ( sizeof( ConstantString13AsArray_ ) / sizeof( ConstantString13AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString15AsArray_}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // This is effectively inline but should not be.
   template
      < typename TResult_
      >
   char const TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ConstantString15AsArray_[]
      ( "(an exception was thrown on reception)" );

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ConstantString15StaticAssertion()
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
   char const TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ConstantString16AsArray_[]
      ( "(zero bytes were read)" );

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ConstantString16StaticAssertion()
   {
      // TODO 3 yg?? Bug: this actually does nothing in a templated class -- revisit.
      static_assert( static_cast< unsigned int >( ConstantString16Length_ ) == ( sizeof( ConstantString16AsArray_ ) / sizeof( ConstantString16AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString18AsArray_}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // This is effectively inline but should not be.
   template
      < typename TResult_
      >
   char const TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ConstantString18AsArray_[]
      ( "(remaining text was read later)" );

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ConstantString18StaticAssertion()
   {
      // TODO 3 yg?? Bug: this actually does nothing in a templated class -- revisit.
      static_assert( static_cast< unsigned int >( ConstantString18Length_ ) == ( sizeof( ConstantString18AsArray_ ) / sizeof( ConstantString18AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif

#if( /* {protected} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TEconomicReportDownloaderWithTcpParallelRequestsBase()
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
   inline TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TEconomicReportDownloaderWithTcpParallelRequestsBase
      ( TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration && configuration1
      ) :
      TEconomicReportReceiverBase< TResult_ >( ::std::move( configuration1 ) ),
      TcpRequestsConfiguration_( ::std::move( configuration1.TcpRequestsConfiguration ) ),
      SocketNextDynamicPortNumberAdvancer_( ::std::move( configuration1.SocketNextDynamicPortNumberAdvancerConfiguration ) )
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
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::Initialize
      ( TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration && configuration1
      )
   {
      TEconomicReportReceiverBase< TResult_ >::Initialize( ::std::move( configuration1 ) );

      TcpRequestsConfiguration_ = ::std::move( configuration1.TcpRequestsConfiguration );
      SocketNextDynamicPortNumberAdvancer_.Initialize
         ( ::std::move( configuration1.SocketNextDynamicPortNumberAdvancerConfiguration ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::DoInitialize
      ( TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration && configuration1
      )
   {
// TODO 2 yg? Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
// TODO 2 yg? Refer to it from consrtructors, destructors, {Initialize}.

      RequestPreSendingTimeOffsetMilliseconds_ = ::std::move( configuration1.RequestPreSendingTimeOffsetMilliseconds );
      ForcedDelayTimeSpanMillisecondsInTestMode_ = ::std::move( configuration1.ForcedDelayTimeSpanMillisecondsInTestMode );
      ShallAdvanceSocketNextDynamicPortNumber_ = false;
      TryMakeWarmUpStepIsRunning_ = false;
      WarmUpCounter_ = 0;
   }

#endif
#if( /* {public Prepare}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::Prepare
      ( ::Common::Time::TDateTimeKeeper const & dateTimeKeeper
      )
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {Prepare} -- base.
      //       Override, call.
      //    {TcpRequestsConfiguration_}.
      //       Enumerate, release resources.
      //    {TcpRequestsConfiguration_[]}.
      //       Use.
      //    {TcpRequestsInternalConfiguration_}.
      //       Populate.
      //    {TcpRequestsInternalConfiguration_[].Prepare}.
      //       Call.

      TEconomicReportReceiverBase< TResult_ >::Prepare( dateTimeKeeper );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TcpRequestsConfiguration_.empty() );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TcpRequestsInternalConfiguration_.empty() );
      TcpRequestsInternalConfiguration_.resize( TcpRequestsConfiguration_.size() );

      {
         ::std::vector< TTcpRequestConfiguration >::iterator tcpRequestsConfigurationIterator( TcpRequestsConfiguration_.begin() );
         for( ::std::vector< TTcpRequestInternalConfiguration_ >::iterator tcpRequestsInternalConfigurationIterator
                   ( TcpRequestsInternalConfiguration_.begin() ) ;
                ;
                ++ tcpRequestsInternalConfigurationIterator
             )
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsConfigurationIterator != TcpRequestsConfiguration_.end() );
            tcpRequestsInternalConfigurationIterator->Prepare( ::std::move( * tcpRequestsConfigurationIterator ) );
             
            if( ( ++ tcpRequestsConfigurationIterator ) != TcpRequestsConfiguration_.end() )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               break;
            }
         }
      }

      {
         // Releasing the resources we don't need any more.
         ::std::vector< TTcpRequestConfiguration > dummy1( ::std::move( TcpRequestsConfiguration_ ) );
      }
   }

#endif
#if( /* {protected DoTryRun}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline /*bool*/ void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::DoTryRun()
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {DoTryRun} -- base.
      //       Implement.
      //    {PrepareRun}.
      //       Call.
      //    {TryDownloadEconomicReport}.
      //       Call.
      //    {CompleteRun}.
      //       Call.

      //base->DoTryRun

   #if( 1 )
   #else
      // This hack is not reflected in visible universe.
      #pragma message( "yg?? Forcing a trial period." )
      {
         ::SYSTEMTIME systemTime1;
         ::GetSystemTime( & systemTime1 );
         if( ( static_cast< unsigned int >( systemTime1.wYear ) << 4U ) + static_cast< unsigned int >( systemTime1.wMonth ) >= ( 2013U << 4U ) + 3U )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

            {
               static char const constantString1AsArray[]( "Critical; trial period expired" );
               throw ::Common::ErrorHandling::TCriticalErrorException
                            ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                              0
                            );
            }
         }
      }
   #endif

      PrepareRun();
      TryDownloadEconomicReport();
      CompleteRun();
   }

#endif

#if( /* {public TryMakeWarmUpStep}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline bool TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TryMakeWarmUpStep()
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
      //    {InvocationTimeOffsetMilliseconds()}.
      //       Use.
      //    {TcpRequestsInternalConfiguration_.size()}.
      //       Use.
      //    {TryMakeWarmUpStepIsRunning_}.
      //       Update.
      //    {WarmUpCounter_}.
      //       Use.
      //    {LogActivityReportIfPossible}.
      //       Call.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TryMakeWarmUpStepIsRunning_ );
      TryMakeWarmUpStepIsRunning_ = true;

      TEconomicReportReceiverBase< TResult_ >::TryMakeWarmUpStep();

      {
         int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
         int economicReportReleaseTimeMilliseconds( currentTimeMilliseconds - InvocationTimeOffsetMilliseconds() );
         ::Poco::Int64 economicReportReleaseDateTimeMillisecondsSince1970
            ( DateTimeKeeper_->GetDateTimeMillisecondsAsInteger< ::Poco::Int64 >( economicReportReleaseTimeMilliseconds ) );

         // Unconditionally using {TPeerStrategyBaseModeCode_Test}.
         TryRun( economicReportReleaseDateTimeMillisecondsSince1970, TPeerStrategyBaseModeCode_Test );
      }


      //// Testing {TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TryRun}.
      //// Comment out the preceeding {TryRun} call.
      //// {LogActivityReportIfPossible} ignores {TryMakeWarmUpStepIsRunning_}, so it's OK to call it after this.
      //{
      //   ForcedDelayTimeSpanMillisecondsInTestMode_ = 1;
      //   NumberRequestsToSend_ = 49;
      //   unsigned int randomNumber1( ::Common::Math::TMultiplyWithCarryRandomNumberCommonGeneratorHelpers::MultiplyWithCarryRandomNumberCommonGenerator.???() );
      //   TryMakeWarmUpStepIsRunning_ = false;
      //
      //   // After this {WarmUpCounter_} must become a nonzero -- to please {assert} below.
      //   TryRun
      //      ( ( WarmUpCounter_ == 0 || ( randomNumber1 & 1U ) != 0U ) ? tradingSystemWarmUpModeCode1 : TTradingSystemWarmUpModeCode_None,
      //        ( ( randomNumber1 & 2U ) != 0U ) ? TPeerStrategyBaseModeCode_Test : TPeerStrategyBaseModeCode_Normal,
      //        economicReportReleaseDateTimeMillisecondsSince1970
      //      );
      //
      //   TryMakeWarmUpStepIsRunning_ = true;
      //   ::Common::Threading::TThreadingHelpers::DoSleepMilliseconds( 10 );
      //}


      if( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success )
      {
         TryCreateNewsHubMessage();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      LogActivityReportIfPossible();

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TryMakeWarmUpStepIsRunning_ );
      TryMakeWarmUpStepIsRunning_ = false;

      // Not assuming this condition as {WarmUpCounter_} can potentially overflow.
      assert( WarmUpCounter_ > 0 );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TcpRequestsInternalConfiguration_.size() > 0U );

      // yg? This condition can become {true} even if the caller calls {TryRun} directly
      // yg? and become {false} when it calls {TryMakeWarmUpStep} after that, which is currently not a problem.
      // This condition doesn't guarantee that all hardcoded response contents have been parsed, which is OK.
      // {WarmUpCounter_} can potentially become 0 again; in that case this condition can become {true} prematurely, which is OK.
      // Assuming this will not overflow or divide by 0U.
      return
         ( static_cast< unsigned int >( WarmUpCounter_ ) % static_cast< unsigned int >( TcpRequestsInternalConfiguration_.size() ) ==
           0U
         );
   }

#endif

#if( /* {public LogActivityReportIfPossible}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::LogActivityReportIfPossible()
   {
      // This method is virtual and inline.

      // Visible universe.
      //    {LogActivityReportIfPossible} -- base.
      //       Implement.
      //    {TcpRequestsState_.clear}.
      //       Call.
      //    {TcpRequestsState_.empty()}.
      //       Use.
      //    {ActiveTcpRequestsState_.clear}.
      //       Call.
      //    {ReceiveAnyResponsesAndLogActivityReport}.
      //       Call.

      //base->LogActivityReportIfPossible

      // Checking if it's "possible" to log activity report.
      if( ! TcpRequestsState_.empty() )

      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         return;
      }

      ReceiveAnyResponsesAndLogActivityReport();
      ActiveTcpRequestsState_.clear();
      TcpRequestsState_.clear();
   }

#endif

#if( /* {private PrepareRun}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::PrepareRun()
   {
      // Visible universe.
      //    {DateTimeKeeper_->Get...}.
      //       Call.
      //    {EconomicReportReleaseDateTimeMillisecondsSince1970_}.
      //       Use.
      //    {EconomicReportReleaseTimeMilliseconds_}.
      //       Update.

      //// Test.
      //TimeStampMillisecondsOnConnectingSockets_ = ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds();

      // yg? The strategy also calculates this -- redundant.
      EconomicReportReleaseTimeMilliseconds_ =
         DateTimeKeeper_->GetTimerTickCounter( static_cast< double >( EconomicReportReleaseDateTimeMillisecondsSince1970_ ) );
   }

#endif
#if( /* {private TryDownloadEconomicReport}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TryDownloadEconomicReport()
   {
      // Visible universe.
      //    {CreateTcpRequestsState}.
      //       Call.
      //    {OnConnectingSockets}.
      //       Call.
      //    {TryAsyncTryConnectSockets}.
      //       Call.
      //    {TryPreSendRequests}.
      //       Call.
      //    {TrySendRequestsAndReceiveAndProcessResponses}.
      //       Call.

      CreateTcpRequestsState();

      // yg? Would it be more correct to call this from {TryAsyncTryConnectSockets}?
      // yg? I don't like the idea as this method is really independent from any other logic.
      OnConnectingSockets();

      TryAsyncTryConnectSockets();
      TryPreSendRequests();
      TrySendRequestsAndReceiveAndProcessResponses();
   }

#endif
#if( /* {private CreateTcpRequestsState}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::CreateTcpRequestsState()
   {
      #pragma region

      // Visible universe.
      //    {::std::multimap< double, TTcpRequestState_ >::value_type::second.StateCode1}.
      //       Update.
      //    {::std::multimap< double, TTcpRequestState_ >::value_type::second.Socket}.
      //       Pass its reference to a method.
      //    {::std::multimap< double, TTcpRequestState_ >::value_type::second.Socket.bind}.
      //       Call.
      //    {::std::multimap< double, TTcpRequestState_ >::value_type::second.Socket.impl()->sockfd()}.
      //       Use.
      //    {::Common::Math::TMultiplyWithCarryRandomNumberCommonGeneratorHelpers::MultiplyWithCarryRandomNumberCommonGenerator.Generate...()}.
      //       Call.
      //    {::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress}.
      //       Use.
      //    {EconomicReportReleaseDateTimeMillisecondsSince1970_}.
      //       Use.
      //    {PeerStrategyBaseModeCode_}.
      //       Use.
      //    {TcpRequestInternalConfiguration_}.
      //       Enumerate.
      //    {TcpRequestInternalConfiguration_[]}.
      //       Swap.
      //    {TcpRequestInternalConfiguration_[].LocalSocketAddress}.
      //       Use.
      //    {TcpRequestInternalConfiguration_[].LocalSocketAddress.addr()}.
      //       Use.
      //    {TcpRequestInternalConfiguration_[].ShallAdvanceSocketNextDynamicPortNumber}.
      //       Use.
      //    {TcpRequestInternalConfiguration_[].NumberRequestsToSend}.
      //       Use.
      //    {TcpRequestInternalConfiguration_[].RequestsPreSendingBitMask}.
      //       Use.
      //    {TcpRequestInternalConfiguration_[].FirstRequestSendingTimeOffsetMilliseconds}.
      //       Use.
      //    {TcpRequestInternalConfiguration_[].RequestSendingIntervalMilliseconds}.
      //       Use.
      //    {TcpRequestsState_}.
      //       Populate.
      //    {ActiveTcpRequestsState_}.
      //       Populate and clear.
      //    {SocketNextDynamicPortNumberAdvancer_.Run}.
      //       Call.
      //    {ShallAdvanceSocketNextDynamicPortNumber_}.
      //       Use, update.
      //    {TryMakeWarmUpStepIsRunning_}.
      //       Validate, use.
      //    {WarmUpCounter_}.
      //       Use, update.
      //    {ConfigureSocket}.
      //       Call.

      #pragma endregion
      #pragma region

      {
         #pragma region

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TcpRequestsInternalConfiguration_.empty() );

         // This can't be a {...::const_iterator} as we need to swap the item it points to.
         ::std::vector< TTcpRequestInternalConfiguration_ >::iterator tcpRequestsInternalConfigurationIterator
            ( TcpRequestsInternalConfiguration_.begin() );

         ::std::vector< TTcpRequestInternalConfiguration_ >::iterator tcpRequestsInternalConfigurationEndIterator
            ( TcpRequestsInternalConfiguration_.end() );

         if( PeerStrategyBaseModeCode_ == TPeerStrategyBaseModeCode_Test )
         {
            // Assuming this will not overflow or divide by 0U.
            int tcpRequestInternalConfigurationToWarmUpIndex
               ( static_cast< int >
                    ( static_cast< unsigned int >( TcpRequestsInternalConfiguration_.size() ) -
                      1U -

                      // {WarmUpCounter_} can potentially become 0 again; in that case this can jump back to 0 prematurely,
                      // which is not a problem.
                      static_cast< unsigned int >( WarmUpCounter_ ) % static_cast< unsigned int >( TcpRequestsInternalConfiguration_.size() )
                    )
               );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestInternalConfigurationToWarmUpIndex >= 0 );

            tcpRequestsInternalConfigurationIterator += tcpRequestInternalConfigurationToWarmUpIndex;
            tcpRequestsInternalConfigurationEndIterator = tcpRequestsInternalConfigurationIterator + 1;

            // The result of a modulo operation is not uniformly distributed -- no big deal.
            // Assuming this will not overflow. It probably can't.
            unsigned int tcpRequestInternalConfigurationToSwapIndex
               ( ::Common::Math::TMultiplyWithCarryRandomNumberCommonGeneratorHelpers::MultiplyWithCarryRandomNumberCommonGenerator.GenerateMediumQuality32Bits() %
                 ( static_cast< unsigned int >( tcpRequestInternalConfigurationToWarmUpIndex ) + 1U )
               );

            // This can swap the item with itself and is guaranteed to do so when we have only 1 item left.
            // This doesn't invalidate the iterators.
            ::std::swap( ( * tcpRequestsInternalConfigurationIterator ),
                               TcpRequestsInternalConfiguration_.at( tcpRequestInternalConfigurationToSwapIndex )
                             );

            // This can potentially overflow and then reach 0, which won't hurt us.
            ++ WarmUpCounter_;
         }
         else
         {
            // {TryMakeWarmUpStep} unconditionally uses {TPeerStrategyBaseModeCode_Test}.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TryMakeWarmUpStepIsRunning_ );
         }

         #pragma endregion
         #pragma region

         // These are valid if the caller called {LogActivityReportIfPossible} after {TryRun}.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TcpRequestsState_.empty() );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ActiveTcpRequestsState_.empty() );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! ShallAdvanceSocketNextDynamicPortNumber_ );

         do
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsInternalConfigurationIterator != tcpRequestsInternalConfigurationEndIterator );

            if( tcpRequestsInternalConfigurationIterator->ShallAdvanceSocketNextDynamicPortNumber )
            {
               if( tcpRequestsInternalConfigurationIterator->LocalSocketAddress.addr() != ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr() )
               {
                  if( ! ShallAdvanceSocketNextDynamicPortNumber_ )
                  {
                     ShallAdvanceSocketNextDynamicPortNumber_ = true;
                  }
                  else
                  {
                     SocketNextDynamicPortNumberAdvancer_.Run();
                  }
               }
               else

               // In case we are not going to bind we will not advance. But an implicit binding will anyway be performed
               // when initiating connections.
               {
                  // The configuration is kinda incorrect, so let's stop.
                  // Would it be a good idea to log this? I don't want to bother.
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               }
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }

            {
               int numberRequestsToSend;

               if( TryMakeWarmUpStepIsRunning_ )
               {
                  numberRequestsToSend = 1;
               }
               else
               {
                  // As mentioned in the config file, in test mode this should not exceed 2.
                  numberRequestsToSend = tcpRequestsInternalConfigurationIterator->NumberRequestsToSend;
               }

               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberRequestsToSend > 0 );

               int requestCounter( 0 );
               do
               {
                  // This expression maximizes precision.
                  double requestSendingDateTimeMillisecondsSince1970
                     ( // Precision would be lower if we added the interval to a variable multiple times.
                       tcpRequestsInternalConfigurationIterator->RequestSendingIntervalMilliseconds * static_cast< double >( requestCounter ) +

                       tcpRequestsInternalConfigurationIterator->FirstRequestSendingTimeOffsetMilliseconds +
                       static_cast< double >( EconomicReportReleaseDateTimeMillisecondsSince1970_ )
                     );
                  
                  // Unnamed objects -- move semantics.
                  ::std::multimap< double, TTcpRequestState_ >::value_type tcpRequestStateItem
                     ( ::std::move( requestSendingDateTimeMillisecondsSince1970 ),
                       TTcpRequestState_( * tcpRequestsInternalConfigurationIterator )
                     );

                  {
                     unsigned int requestCounterRemainder
                        ( static_cast< unsigned int >( requestCounter ) % ( static_cast< unsigned int >( sizeof( unsigned int ) ) * 8U ) );
                     unsigned int requestCounterBitMask( 1U << requestCounterRemainder );
//TODO 3 yg? Can we use {...::TMathHelpers::CircularBitwiseShiftValueRight} or {::_rotr}? Replace {requestCounterRemainder} with a circulare shofted copy of {tcpRequestsInternalConfigurationIterator->RequestsPreSendingBitMask}.
                     tcpRequestStateItem.second.StateCode1 =
                        static_cast< int >
                           ( ( tcpRequestsInternalConfigurationIterator->RequestsPreSendingBitMask & requestCounterBitMask ) >>
                             requestCounterRemainder
                           ) -
                        1;
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                        ( tcpRequestStateItem.second.StateCode1 == ( - 1 ) || tcpRequestStateItem.second.StateCode1 == 0 );
                  }

                  ConfigureSocket( tcpRequestStateItem.second.Socket );

                  if( tcpRequestsInternalConfigurationIterator->LocalSocketAddress.addr() != ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr() )
                  {
                     // yg? Assuming this will not throw an exception unless the IP address is invalid.
                     tcpRequestStateItem.second.Socket.bind( tcpRequestsInternalConfigurationIterator->LocalSocketAddress, false );
                  }
                  else
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                  }

                  // This reserves {ActiveTcpRequestsState_} capacity.
                  // Unnamed objects -- move semantics.
                  // I don't want to validate that this insertion succeeds.
                  ActiveTcpRequestsState_.insert
                     ( ::std::map< ::poco_socket_t, typename ::std::multimap< double, TTcpRequestState_ >::value_type & >::value_type
                          ( tcpRequestStateItem.second.Socket.impl()->sockfd(),
                            /*::std::move*/( * static_cast< ::std::multimap< double, TTcpRequestState_ >::value_type * >( nullptr ) )
                          )
                     );

                  // Not making the keys deterministically comparable.
                  // Not ensuring that items with equal keys are inserted in a deterministic order.
                  // One lame way to fix this is to multiply each key by something like {::std::pow( 1.0 + ...::epsilon, requestCounter )}
                  // or possibly a bigger multiplier, but that would result in a nonzero sending interval, which is not what the user wants.
                  // Another solution would be to insert with a position hint but that would require to round keys to a multiple of some magic number.
                  // So let's keep it simple.
                  TcpRequestsState_.insert( ::std::move( tcpRequestStateItem ) );
               }
               while( ( ++ requestCounter ) < numberRequestsToSend );
            }
         }
         while( ( ++ tcpRequestsInternalConfigurationIterator ) != tcpRequestsInternalConfigurationEndIterator );

         #pragma endregion
      }

      #pragma endregion
      #pragma region

      // This warms up some code.
      // yg? We used to warm-up this collection's single item removal but I eliminated that.
      ActiveTcpRequestsState_.clear();

      #pragma endregion
   }

#endif
#if( /* {protected ConfigureSocket}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ConfigureSocket
      ( ::Common::Networking::TStreamSocketWithDataBuffer & socket1
      ) const
   {
      // This method is virtual and inline.
      // I don't want to write down visible universe here.
      // We probably don't need to set send timeout.
//TODO Actually speaking of which, set minimum possible send timeout, which is probably 1 ms on Windows and 1 us on Linux. This will actually be 501 ms on Windows. Maybe derived class should do this.

      socket1.setNoDelay( true );
      socket1.setLinger( true, 0 );
   }

#endif
#if( /* {private OnConnectingSockets}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::OnConnectingSockets()
   {
      // I don't want to write down visible universe here.

      // yg? Would it be better to log this when logging activity report? I don't like the idea as this info is really not important.
      // TODO 3 yg? It might be better to just not log this at all. So I might need to eliminate this method at some point.
      {
         int const tempString1BufferLength( 128 );
         ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
         static char const formatConstantString1AsArray[]
            ( "{Prototype52::TEconomicReportDownloaderWithTcpParallelRequestsBase<TResult_>} is connecting; %+i" );

         int tempString1Length
            ( ::_snprintf_l
                 ( ( & tempString1.front() ),
                   static_cast< unsigned int >( tempString1BufferLength ),
                   formatConstantString1AsArray,
                   ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,

                   // This indicates how much time passed since {InvocationTimeOffsetMilliseconds()}.
                   ( ( ( TimeStampMillisecondsOnConnectingSockets_ = ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() ) -
                        EconomicReportReleaseTimeMilliseconds_
                     ) -
                     InvocationTimeOffsetMilliseconds()
                   )
                 )
            );

         if( tempString1Length >= 0 )
         {
            tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
         }
         
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         logger1.information( tempString1 );
      }
   }

#endif
#if( /* {private TryAsyncTryConnectSockets}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TryAsyncTryConnectSockets()
   {
      // Visible universe.
      //    {TcpRequestsState_}.
      //       Enumerate.
      //    {TcpRequestsState_[].second.TcpRequestInternalConfiguration->DestinationSocketAddress}.
      //       Use.
      //    {TcpRequestsState_[].second.Socket.connectNB}.
      //       Call.
      //    {TcpRequestsState_[].second.Socket.setBlocking
      //       Call.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.
      //    {SleepMillisecond}.
      //       Call.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TcpRequestsState_.empty() );
      ::std::multimap< double, TTcpRequestState_ >::iterator tcpRequestsStateIterator( TcpRequestsState_.begin() );
      do
      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsStateIterator != TcpRequestsState_.end() );

         try
         {
            // If this throws an exception we will just do nothing at this time and later the socket will probably report itself as non-writable,
            // so we will create another socket and try to initiate another connection. But if somehow it reports itself as writable
            // we will not reconnect and we will use it just as if the connection initiation succeeded.
            // It might be a good idea to set a special {tcpRequestsStateIterator->second.StateCode1} and later handle it differently
            // but I don't want to bother.
            tcpRequestsStateIterator->second.Socket.connectNB
               ( tcpRequestsStateIterator->second.TcpRequestInternalConfiguration->DestinationSocketAddress );
         }

         // Catching only POCO exceptions. Assuming this exception is not critical.
         catch( ::Poco::Exception const & exception1 )

         {
            {
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
               logger1.log( exception1 );
            }

            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         }

         // We should not sleep on the last loop but it's OK.
         // Besides, now we need to call {SocketNextDynamicPortNumberAdvancerRunUntilNextMillisecondIfNeeded} here.
         SleepMillisecond();

         // yg? Assuming this will not throw an exception even if the connection initiation failed.
         tcpRequestsStateIterator->second.Socket.setBlocking( true );
      }

      // It's probably inefficient to call {TcpRequestsState_.end} on each loop but this code is not performance critical.
      while( ( ++ tcpRequestsStateIterator ) != TcpRequestsState_.end() );
   }

#endif
#if( /* {private TryPreSendRequests}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TryPreSendRequests()
   {
      // Visible universe.
      //    {::Common::Threading::TThreadingHelpers::...Sleep...}.
      //       Call.
      //    {EconomicReportReleaseDateTimeMillisecondsSince1970_}.
      //       Use.
      //    {RequestPreSendingTimeOffsetMilliseconds_}.
      //       Use.
      //    {EconomicReportReleaseTimeMilliseconds_}.
      //       Use.
      //    {TcpRequestsState_[].first}.
      //       Use.
      //    {ShallAdvanceSocketNextDynamicPortNumber_}.
      //       Update.
      //    {TimeStampMillisecondsOnConnectingSockets_}.
      //       Use.
      //    {TryPreSendRequests( bool )}.
      //       Call.
      //    {SocketNextDynamicPortNumberAdvancerRunIfNeeded}.
      //       Call.
      //    {SocketNextDynamicPortNumberAdvancerRunUntilNextMillisecondIfNeeded}.
      //       Call.

      // To improve timing accuracy, this is used instead of {InvocationTimeOffsetMilliseconds()}.
      // This is important because next dynamic port number advancing can take long.
      int timeStampMillisecondsOnConnectingSocketsOffset
         ( TimeStampMillisecondsOnConnectingSockets_ - EconomicReportReleaseTimeMilliseconds_ );
      
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TcpRequestsState_.empty() );

      // Timespan from invocation (actually {TimeStampMillisecondsOnConnectingSockets_}) to the 2nd pre-send.
      // We don't need high accuracy here.
      // This expression is overflow ridden but it works.
      int invocationToRequestPreSending2TimeSpanMilliseconds
         ( static_cast< int >( ::Common::Math::TMathHelpers::RoundValueToIntegerMidpointDown< double, ::Poco::Int64 >( TcpRequestsState_.cbegin()->first ) ) -
           static_cast< int >( EconomicReportReleaseDateTimeMillisecondsSince1970_ ) +
           RequestPreSendingTimeOffsetMilliseconds_ -
           timeStampMillisecondsOnConnectingSocketsOffset
         );

      // Timespan from invocation (actually {TimeStampMillisecondsOnConnectingSockets_}) to the 1st pre-send.
      // It's really not a pre-send but only a socket examination and possibly reconnect.
      // Truncating the remainder rather than rounding to give the 2nd connection initiation a bit more time.
      // --not any more-- The 1st connection initiation will actually have even a bit less time as it takes some time to create sockets.
      // If this request is to be forwarded the "ForwardTcpConnection.exe" connect timeout must be
      // this value minus ping time from us to "ForwardTcpConnection.exe" minus a margin.
      int invocationToRequestPreSendingTimeSpanMilliseconds( invocationToRequestPreSending2TimeSpanMilliseconds / 2 );

      for( bool shallPreSendRequests( false ) ; ; shallPreSendRequests = true )
      {
         SocketNextDynamicPortNumberAdvancerRunIfNeeded();

         // This validation can potentially fail due to a race outcome or if we stop in the debugger.
         // This value must actually be greather than 0 by a margin.
         // If the user misconfigures us we won't blow up but things won't happen as fast as the user might want and
         // the report downloading will probably fail but can also succeed.
         assert( invocationToRequestPreSendingTimeSpanMilliseconds > 0 );

         ::Common::Threading::TThreadingHelpers::SleepUntilMultimediaTimeMilliseconds
            //( EconomicReportReleaseTimeMilliseconds_ + /*InvocationTimeOffsetMilliseconds()*/ timeStampMillisecondsOnConnectingSocketsOffset + invocationToRequestPreSendingTimeSpanMilliseconds );
            ( TimeStampMillisecondsOnConnectingSockets_ + invocationToRequestPreSendingTimeSpanMilliseconds );
         TryPreSendRequests( shallPreSendRequests );
         
         if( ! shallPreSendRequests )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }
         
         invocationToRequestPreSendingTimeSpanMilliseconds = invocationToRequestPreSending2TimeSpanMilliseconds;
      }

      SocketNextDynamicPortNumberAdvancerRunUntilNextMillisecondIfNeeded();
      ShallAdvanceSocketNextDynamicPortNumber_ = false;
   }

#endif
#if( /* {private TryPreSendRequests}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TryPreSendRequests
      ( bool shallPreSendRequests
      )
   {
      // yg? As mentioned in the config file, request pre-sending probably adversely affects the reliability.

      // Visible universe.
      //    {TcpRequestsState_}.
      //       Enumerate.
      //    {TcpRequestsState_[].second}.
      //       Pass its reference to a method.
      //    {TcpRequestsState_[].second.TcpRequestInternalConfiguration->RequestContent}.
      //       Use.
      //    {TcpRequestsState_[].second.StateCode1}.
      //       Use, update.
      //    {TcpRequestsState_[].second.Socket.poll}.
      //       Call.
      //    {TcpRequestsState_[].second.Socket.sendBytes}.
      //       Call.
      //    {TryAsyncTryReconnectSocket}.
      //       Call.
      //    {SleepMillisecond}.
      //       Call.

      // We don't need to mention {::Poco::Timespan} in the visible universe.
      ::Poco::Timespan zeroTimeSpan( 0 );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TcpRequestsState_.empty() );
      for( ::std::multimap< double, TTcpRequestState_ >::iterator tcpRequestsStateIterator( TcpRequestsState_.begin() ) ; ; )
      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsStateIterator != TcpRequestsState_.end() );

         // This is inefficient and lame.
         // Instead of this we should continuously {::select} or {::WSAPoll} all sockets and reconnect one as soon as one becomes readable or with errors.
         // This could be done by another method named {monitorSockets}.
         // Then {TryPreSendRequests} should {::select} or {::WSAPoll} all sockets ready for writing and reconnect those that fail to select.
         // But this solution would result in different times from socket connection initiation to {::select} or {::WSAPoll}.
         // And if we try to sleep to preserve the timings before a reconnection we would need to revalidate that the socket still
         // is not writable, is readable, or has errors.
         // One other thing we would need to ensure is that {TryPreSendRequests} would not initiate a reconnection of a socket if
         // one's reconnection has just been initiated. The "just" would probably mean since the 1st connection initiation or previous call to
         // {TryPreSendRequests}, whichever occurred later.
         // Such a logic would be much more convoluted and ugly but any benefit would be negligible.
         if( tcpRequestsStateIterator->second.Socket.poll( zeroTimeSpan, ::Poco::Net::Socket::SelectMode::SELECT_WRITE ) &&
             ( ! tcpRequestsStateIterator->second.Socket.poll( zeroTimeSpan, ::Poco::Net::Socket::SelectMode::SELECT_READ | ::Poco::Net::Socket::SelectMode::SELECT_ERROR ) )
           )

         {
            int numberBytesToSend;

            if( ! shallPreSendRequests )
            {
               goto label4;
            }
            else
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                  ( tcpRequestsStateIterator->second.StateCode1 == ( - 1 ) || tcpRequestsStateIterator->second.StateCode1 == 0 );
               if( tcpRequestsStateIterator->second.StateCode1 >= 0 )
               {
                  // Assuming this will not overflow.
                  numberBytesToSend =
                     static_cast< int >( tcpRequestsStateIterator->second.TcpRequestInternalConfiguration->RequestContent.length() ) - 1;

                  // This validation succeeds for currently configured requests but some day I might need to eliminate it.
                  assert( numberBytesToSend > 0 );
               }
               else
               {
                  tcpRequestsStateIterator->second.StateCode1 = 0;

               label4:
                  numberBytesToSend = 0;
               }
            }

            if( numberBytesToSend > 0 )
            {
               try
               {
                  // We probably would be able to recover from a non-negative number bytes sent by sending remaining bytes later,
                  // but keeping it simple.
                  // Actually, this method guarantees to send all bytes in blocking mode but it can potentially take long if not forever.
                  // So it's safe to ignore return value.
                  tcpRequestsStateIterator->second.Socket.sendBytes
                     ( reinterpret_cast< void const * >
                          ( tcpRequestsStateIterator->second.TcpRequestInternalConfiguration->RequestContent.data() ),
                       numberBytesToSend,
                       0
                     );
               }

               // It's unlikely that an exception will be thrown given that we {poll}ed the socket.
               // Catching only POCO exceptions. Assuming this exception is not critical.
               catch( ::Poco::Exception const & exception1 )

               {
                  {
                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                     logger1.warning( exception1.displayText() );
                  }

                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsStateIterator->second.StateCode1 == 0 );
                  goto label5;
               }

               tcpRequestsStateIterator->second.StateCode1 = 1;
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }

            // We sleep either here or in {TryAsyncTryReconnectSocket}.
            // Sleeping even if we didn't send anything -- to preserve the same timing.
            // We should not sleep on the last loop but it's OK.
            // Besides, now we need to call {SocketNextDynamicPortNumberAdvancerRunUntilNextMillisecondIfNeeded} here.
            SleepMillisecond();
         }
         else
         {
            if( ! shallPreSendRequests )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                  ( tcpRequestsStateIterator->second.StateCode1 == ( - 1 ) || tcpRequestsStateIterator->second.StateCode1 == 0 );
               tcpRequestsStateIterator->second.StateCode1 = 0;
            }

         label5:
            TryAsyncTryReconnectSocket( tcpRequestsStateIterator->second );
         }

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( ( ( ! shallPreSendRequests ) &&
                 ( tcpRequestsStateIterator->second.StateCode1 == ( - 1 ) ||
                   tcpRequestsStateIterator->second.StateCode1 == 0
                 )
              ) ||
              ( shallPreSendRequests &&
                ( tcpRequestsStateIterator->second.StateCode1 == 0 ||
                  tcpRequestsStateIterator->second.StateCode1 == 1
                )
              )
            );

         // It's probably inefficient to call {TcpRequestsState_.end} on each loop but this code is not performance critical.
         if( ( ++ tcpRequestsStateIterator ) != TcpRequestsState_.end() )

         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }
      }
   }

#endif
#if( /* {private TryAsyncTryReconnectSocket}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TryAsyncTryReconnectSocket
      ( TTcpRequestState_ & tcpRequestState
      )
   {
      // This code is similar to {CreateTcpRequestsState} and {TryAsyncTryConnectSockets}.
      // yg? See related comments in there.
      // yg? Should I move the creation/preparation of a socket to a separate method? I don't want to do it.

      // Visible universe.
      //    //{::Poco::Socket::setBlocking}.
      //    //   Call.
      //    //{::Poco::StreamSocket::connectNB}.
      //    //   Call.
      //    {::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress}.
      //       Use.
      //    //{::Common::Networking::TStreamSocketWithDataBuffer::bind}.
      //    //   Call.
      //    {ConfigureSocket}.
      //       Call.
      //    {SleepMillisecond}.
      //       Call.
      //    {tcpRequestState.TcpRequestInternalConfiguration->LocalSocketAddress}.
      //       Use.
      //    {tcpRequestState.TcpRequestInternalConfiguration->LocalSocketAddress.addr()}.
      //       Use.
      //    {tcpRequestState.TcpRequestInternalConfiguration->DestinationSocketAddress}.
      //       Use.
      //    {tcpRequestState.Socket.bind}.
      //       Call.
      //    {tcpRequestState.Socket.close}.
      //       Call.
      //    {tcpRequestState.Socket.connectNB}.
      //       Call.
      //    {tcpRequestState.Socket.init}.
      //       Call.
      //    {tcpRequestState.Socket.setBlocking}.
      //       Call.
      //    {tcpRequestState.Socket.DataBuffer().DataLength}.
      //       Validate.

      // We are going to reuse this socket object.
      // At this point we don't need to clear the buffer.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestState.Socket.DataBuffer().DataLength == 0U );

      // It might be possible to call {::DisconnectEx} on Windows and reuse the socket handle but based on the docs,
      // there can be marginal cases to take care of.
      // I would also need to ensure that all changes the virtual {ConfigureSocket} method made would be preserved, also the binding.
      // So keeping it simple for now.
      // If an unexpected exception is thrown before we have a chance to assign to {tcpRequestState.Socket} the socket will remain closed,
      // which is considered corrupt state that we are not designed to handle. In that case the caller shall call our destructor.
      // Actually we now {init} the same socket object.
      // yg? Assuming this will not throw an exception.
      tcpRequestState.Socket.close();

      // Sleeping after initiating a disconnect rather than after initiating a connect.
      // This increases the chance that the destination host will see fewer connections from us.
      SleepMillisecond();

      ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

      {
         //::Common::Networking::TStreamSocketWithDataBuffer socket2( ::Poco::Net::IPAddress::Family::IPv4 );
         tcpRequestState.Socket.init( AF_INET );
         //ConfigureSocket( socket2 );
         ConfigureSocket( tcpRequestState.Socket );
         
         if( tcpRequestState.TcpRequestInternalConfiguration->LocalSocketAddress.addr() != ::Common::Networking::TNetworkingHelpers::WildcardIPSocketAddress.addr() )
         {
            // yg? Assuming this will not throw an exception unless the IP address is invalid.
            //socket2.bind( tcpRequestState.TcpRequestInternalConfiguration->LocalSocketAddress, false );
            tcpRequestState.Socket.bind( tcpRequestState.TcpRequestInternalConfiguration->LocalSocketAddress, false );
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         try
         {
            // As mentioned above, we don't sleep after this.
            //socket2.connectNB( tcpRequestState.TcpRequestInternalConfiguration->DestinationSocketAddress );
            tcpRequestState.Socket.connectNB( tcpRequestState.TcpRequestInternalConfiguration->DestinationSocketAddress );
         }

         // Catching only POCO exceptions. Assuming this exception is not critical.
         catch( ::Poco::Exception const & exception1 )

         {
            {
               //::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
               logger1.log( exception1 );
            }

            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         }

         // yg? Assuming this will not throw an exception even if the connection initiation failed.
         //socket2.setBlocking( true );
         tcpRequestState.Socket.setBlocking( true );

         //// yg? This is actually copying rather than moving. I don't want to code proper moving.
         //tcpRequestState.Socket = ::std::move( socket2 );
      }

      {
         // {...::connectNB} can fail, so the operation can be unsuccessful.
         static char const constantString1AsArray[]( "initiated a socket reconnection, successfully or not" );

         //::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
#if( /* {private SleepMillisecond}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::SleepMillisecond()
   {
      // I don't want to write down visible universe here.

      if( SocketNextDynamicPortNumberAdvancerRunUntilNextMillisecondIfNeeded() )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Threading::TThreadingHelpers::SleepMillisecond();
      }
   }

#endif
#if( /* {private SocketNextDynamicPortNumberAdvancerRunIfNeeded}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::SocketNextDynamicPortNumberAdvancerRunIfNeeded()
   {
      // I don't want to write down visible universe here.

      if( ShallAdvanceSocketNextDynamicPortNumber_ )
      {
         SocketNextDynamicPortNumberAdvancer_.Run();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
   }

#endif
#if( /* {private SocketNextDynamicPortNumberAdvancerRunUntilNextMillisecondIfNeeded}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline bool TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::SocketNextDynamicPortNumberAdvancerRunUntilNextMillisecondIfNeeded()
   {
      // I don't want to write down visible universe here.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( SocketNextDynamicPortNumberAdvancer_.NumberSocketNextDynamicPortNumberIncrements() >= 0 );
      bool isNeeded
         ( ShallAdvanceSocketNextDynamicPortNumber_ &&

           // yg? I was thinking about never setting the {ShallAdvanceSocketNextDynamicPortNumber_} flag in {CreateTcpRequestsState}
           // yg? when this condition is {false} but this code is less performance critical than the one in {CreateTcpRequestsState}.
           // yg? Actually it's not really performance critical there...
           SocketNextDynamicPortNumberAdvancer_.NumberSocketNextDynamicPortNumberIncrements() > 0
         );

      if( isNeeded )
      {
         // yg? This logic doesn't guarantee a sufficient number of increments even if it's executed multiple times.
         // yg? See also: {...::RunUntilNextMillisecond} method comment.
         // Sometimes this sleeps longer than {::Common::Threading::TThreadingHelpers::SleepMillisecond} does because
         // the millisecond time isn't incremented on some multimedia timer interrupts. It's OK.
         SocketNextDynamicPortNumberAdvancer_.RunUntilNextMillisecond();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      
      return isNeeded;
   }

#endif
#if( /* {private TrySendRequestsAndReceiveAndProcessResponses}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::TrySendRequestsAndReceiveAndProcessResponses()
   {
      #pragma region

      // yg? It might be better to send requests on another thread.
      // yg? Then main thread would only {::select} or {::WSAPoll} without interruptions.
      // yg? But main thread would have to select all sockets, including those through which the request wasn't sent yet.

      // Visible universe.
      //    {::Common::Networking::TNetworkingHelpers::SelectAnySocketsReadyForReadingHandle}.
      //       Call.
      //    {::Common::Threading::TThreadingHelpers::...Sleep...}.
      //       Call.
      //    {EconomicReportReceptionTimeoutTimeSpanMilliseconds_}.
      //       Use.
      //    {DateTimeKeeper_->Get...}.
      //       Call.
      //    {OutcomeCode_}.
      //       Update.
      //    {EconomicReportReleaseTimeMilliseconds_}.
      //       Use.
      //    {TcpRequestsState_}.
      //       Enumerate.
      //    {TcpRequestsState_[].first}.
      //       Use.
      //    {TcpRequestsState_[].second.TcpRequestInternalConfiguration->RequestContent}.
      //       Use.
      //    {TcpRequestsState_[].second.StateCode1}.
      //       Use, update.
      //    {TcpRequestsState_[].second.Socket.impl()->sockfd()}.
      //       Use.
      //    {TcpRequestsState_[].second.Socket.sendBytes}.
      //       Call.
      //    {TcpRequestsState_[].second.Socket.DataBuffer().Assign}.
      //       Call.
      //    {ActiveTcpRequestsState_}.
      //       Populate, pass its reference to a method.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.
      //    {ProcessSelectedSockets}.
      //       Call.

      #pragma endregion
      #pragma region

      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ActiveTcpRequestsState_.empty() );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TcpRequestsState_.empty() );
         ::std::multimap< double, TTcpRequestState_ >::iterator tcpRequestsStateIterator( TcpRequestsState_.begin() );
         ::std::multimap< double, TTcpRequestState_ >::iterator tcpRequestsStateEndIterator( TcpRequestsState_.end() );
         
         // This is not valid inside the loop block.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsStateIterator != tcpRequestsStateEndIterator );
         
         for( ; ; ++ tcpRequestsStateIterator )
         {
            #pragma region

            {
               //double requestSendingDateTimeMillisecondsSince1970
               //   ( ( socketsIterator1 != socketsEndIterator1 ) ?
               //      socketsIterator1->first :
               //
               //      // For this timeout, the regular multimedia time accuracy would be good enough and, as the matter of practice, even preferable
               //      // but it's simply easier to use the {DateTimeKeeper_}'s time here. This is unlikely to cause incorrect behavior.
               //      static_cast< double >( EconomicReportReleaseDateTimeMillisecondsSince1970_ + EconomicReportReceptionTimeoutTimeSpanMilliseconds_ )
               //   );
               //int requestSendingTimeMilliseconds( DateTimeKeeper_->GetTimerTickCounter( requestSendingDateTimeMillisecondsSince1970 ) );

               int requestSendingTimeMilliseconds;
               if( tcpRequestsStateIterator != tcpRequestsStateEndIterator )
               {
                  requestSendingTimeMilliseconds = DateTimeKeeper_->GetTimerTickCounter( tcpRequestsStateIterator->first );
               }
               else
               {
                  requestSendingTimeMilliseconds =
                     EconomicReportReleaseTimeMilliseconds_ + EconomicReportReceptionTimeoutTimeSpanMilliseconds_;
               }

               for( bool responsesReceptionTried( false ) ; ; )
               {
                  if( ActiveTcpRequestsState_.empty() )
                  {
                     if( tcpRequestsStateIterator != tcpRequestsStateEndIterator )
                     {
                        ::Common::Threading::TThreadingHelpers::SleepUntilMultimediaTimeMilliseconds( requestSendingTimeMilliseconds );
                        goto label1;
                     }
                     else
                     {
                        goto label2;
                     }
                  }
                  else
                  {
                     int currentTimeMilliseconds( ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );

                     // Microseconds.
                     long timeSpanUntilRequestSendingTimeMicroseconds( requestSendingTimeMilliseconds - currentTimeMilliseconds );

                     if( timeSpanUntilRequestSendingTimeMicroseconds > 0 )
                     {
                        // TODO 3 yg? Revisit this. We should factor multimedia timer tick interval.
                        // Assuming this will not overflow, even if multiplied by 1000.
                        timeSpanUntilRequestSendingTimeMicroseconds =
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
                           ( timeSpanUntilRequestSendingTimeMicroseconds * static_cast< long >( ::Poco::Timespan::MILLISECONDS ) ) -
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
                           ( ( static_cast< long >( ::Poco::Timespan::MILLISECONDS ) - 1 ) / 2 );
                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( timeSpanUntilRequestSendingTimeMicroseconds > 0 );
                     }
                     else
                     {
                        // This ensures that we will select sockets at least once after sending a request,
                        // even if it's time to send another request or timeout has already expired when we sent the last request.
                        if( ! responsesReceptionTried )
                        {
                           timeSpanUntilRequestSendingTimeMicroseconds = 0;
                        }
                        else
                        {
                           break;
                        }
                     }
                     
                     ::fd_set socketsReadyForReadingHandle;
                     
                     // Optimization hint for {::Common::Networking::TNetworkingHelpers::SelectAnySocketsReadyForReadingHandle}.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ActiveTcpRequestsState_.cbegin() != ActiveTcpRequestsState_.cend() );

                     // Not selecting sockets with errors.
                     // yg? This needs to be rewritten on Linux.
                     // This can potentially throw a critical exception.
                     int numberSocketsReadyForReading
                        ( ::Common::Networking::TNetworkingHelpers::SelectAnySocketsReadyForReadingHandle
                             ( ActiveTcpRequestsState_, socketsReadyForReadingHandle, timeSpanUntilRequestSendingTimeMicroseconds )
                        );

                     // This value can't be negative as otherwise an exception would have been thrown.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberSocketsReadyForReading >= 0 );

                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                        ( static_cast< unsigned int >( numberSocketsReadyForReading ) == socketsReadyForReadingHandle.fd_count );

                     // Timeout expired?
                     if( numberSocketsReadyForReading <= 0 )

                     {
                        break;
                     }
                     else
                     {
                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                     }
                        
                     if( ! ProcessSelectedSockets( socketsReadyForReadingHandle ) )
                     {
                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                     }
                     else
                     {
                        return;
                     }

                     // This is not needed as this would introduce an unnecessary overhead in most cases.
                     //if( timeSpanUntilRequestSendingTimeMicroseconds > 0 )
                     //{
                     //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
                     //}
                     //else
                     //{
                     //   break;
                     //}

                     responsesReceptionTried = true;
                  }
               }
            }

            #pragma endregion
            #pragma region

            // This condition is {false} only after the socket selection times out after {EconomicReportReceptionTimeoutTimeSpanMilliseconds_}.
            // In a marginal case, it's possible that we selected 1 or more sockets, read 0 or more bytes but failed to parse the text,
            // and then based on {timeSpanUntilRequestSendingTimeMicroseconds} and {responsesReceptionTried} we broke the loop.
            if( tcpRequestsStateIterator != tcpRequestsStateEndIterator )

            {
               #pragma region

               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();

            label1:
               do
               {
                  // Assuming this will not overflow.
                  int numberBytesToSend
                     ( static_cast< int >( tcpRequestsStateIterator->second.TcpRequestInternalConfiguration->RequestContent.length() ) );
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesToSend >= 0 );
                  int byteOffset;
                  
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                     ( tcpRequestsStateIterator->second.StateCode1 == 0 || tcpRequestsStateIterator->second.StateCode1 == 1 );
                  if( tcpRequestsStateIterator->second.StateCode1 > 0 )
                  {
                     // If this wasn't the case we would not pre-send this request.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesToSend > 1 );

                     byteOffset = numberBytesToSend - 1;
                     numberBytesToSend = 1;
                  }
                  else
                  {
                     byteOffset = 0;
                  }
                  
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( byteOffset >= 0 );
                  tcpRequestsStateIterator->second.StateCode1 = 2;

                  try
                  {
                     // Some request sendings can fail because the connection wasn't established yet. In that case,
                     // after we try to send all requests, it would be nice to select sockets ready for writing and send requests. This implies that
                     // we would need to select both sockets ready for reading, as we do now, and in addition sockets ready for writing
                     // among those whose request sending failed. But keeping it simple.
                     // It might be easier to get this done if we send all requests on another thread.
                     // This method guarantees to send all bytes in blocking mode but it can potentially take long if not forever.
                     // So it's safe to ignore return value.
                     tcpRequestsStateIterator->second.Socket.sendBytes
                        ( reinterpret_cast< void const * >
                             ( & tcpRequestsStateIterator->second.TcpRequestInternalConfiguration->RequestContent.at
                                      ( static_cast< unsigned int >( byteOffset ) )
                             ),
                          numberBytesToSend,
                          0
                        );
                  }

                  // Catching only POCO exceptions. Assuming this exception is not critical.
                  catch( ::Poco::Exception const & exception1 )

                  {
                     {
                        ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
                        logger1.warning( exception1.displayText() );
                     }

                     //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

                     // Data buffer is empty, so we assign rather than append.
                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                        ( tcpRequestsStateIterator->second.Socket.DataBuffer().DataLength == 0U );
                     tcpRequestsStateIterator->second.Socket.DataBuffer().Assign
                        ( ConstantString13AsArray_, static_cast< unsigned int >( ConstantString13Length_ ) );

                     break;
                  }

                  {
                     //// Using {auto}. It's not too bad.
                     //// Both {auto}, {auto &}, {auto &&}, and even {auto const &} work but it probably makes no difference.
                     //auto const & activeTcpRequestsStateInsertResult

                     // This doesn't need to be a reference.
                     // Unnamed objects -- move semantics.
                     ::std::pair< ::std::map< ::poco_socket_t, typename ::std::multimap< double, TTcpRequestState_ >::value_type & >::iterator, bool > const
                        activeTcpRequestsStateInsertResult
                           ( ActiveTcpRequestsState_.insert
                                ( ::std::map< ::poco_socket_t, typename ::std::multimap< double, TTcpRequestState_ >::value_type & >::value_type
                                     ( tcpRequestsStateIterator->second.Socket.impl()->sockfd(),
                                       /*::std::move*/( * tcpRequestsStateIterator )
                                     )
                                )
                           );

                     YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( activeTcpRequestsStateInsertResult.second );
                  }
               }
               while( static_cast< void >( false ) , false );
            
               #pragma endregion
            }
            else
            {
               break;
            }

            #pragma endregion
         }
      }

      #pragma endregion
      #pragma region

   label2:
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
      OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError;

      #pragma endregion
   }

#endif
#if( /* {private ProcessSelectedSockets}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline bool TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ProcessSelectedSockets
      ( ::fd_set const & socketsReadyForReadingHandle
      )
   {
   #if( ! defined( _MSC_VER ) )
      #error yg?? ToDo
   #endif

      // Visible universe.
      //    {ActiveTcpRequestsState_.find}.
      //       Call.
      //    {ProcessSelectedSocketReadyForReading}.
      //       Call.

      bool returnValue;

      // Processing selected sockets in the reverse order as sockets at the beginning are more likely to yield the "New Release Pending"
      // page. Although sockets are ordered by socket handle, which can have nothing to do with the order of request sending.
      // Also, if we use proxy hosts, responses can arrive in an even less predictable order.
      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( socketsReadyForReadingHandle.fd_count > 0U );
         ::poco_socket_t const * socketHanlePointer( socketsReadyForReadingHandle.fd_array + socketsReadyForReadingHandle.fd_count );
         do
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( socketHanlePointer != socketsReadyForReadingHandle.fd_array );
            -- socketHanlePointer;
            ::std::map< ::poco_socket_t, typename ::std::multimap< double, TTcpRequestState_ >::value_type & >::iterator
               activeTcpRequestsStateIterator
                  ( ActiveTcpRequestsState_.find( * socketHanlePointer ) );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( activeTcpRequestsStateIterator != ActiveTcpRequestsState_.end() );
            returnValue = ProcessSelectedSocketReadyForReading( activeTcpRequestsStateIterator );
         }
         while( ( ! returnValue ) && socketHanlePointer != socketsReadyForReadingHandle.fd_array );
      }

      return returnValue;
   }

#endif
#if( /* {private ProcessSelectedSocketReadyForReading}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline bool TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ProcessSelectedSocketReadyForReading
      ( typename ::std::map< ::poco_socket_t, typename ::std::multimap< double, TTcpRequestState_ >::value_type & >::iterator activeTcpRequestsStateIterator
      )
   {
      // Visible universe.
      //    {OutcomeCode_}.
      //       Validate.
      //    {ActiveTcpRequestsState_.erase}.
      //       Call.
      //    {TryMakeWarmUpStepIsRunning_}.
      //       Use.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.
      //    {GetResponseContentForWarmUp}.
      //       Call.
      //    {TryParseResponse}.
      //       Call.
      //    {activeTcpRequestsStateIterator}.
      //       Remove the item it points to.
      //    {activeTcpRequestsStateIterator->second.second.Socket.DataBuffer()}.
      //       Pass it to a method.
      //    {activeTcpRequestsStateIterator->second.second.Socket.DataBuffer().Append}.
      //       Call.
      //    {activeTcpRequestsStateIterator->second.second.Socket.ReceiveBytesIntoDataBuffer}.
      //       Call.

      int numberBytesReceived;

      try
      {
         numberBytesReceived = activeTcpRequestsStateIterator->second.second.Socket.ReceiveBytesIntoDataBuffer( 0 );
      }

      // Catching only POCO exceptions. Assuming this exception is not critical.
      catch( ::Poco::Exception const & exception1 )

      {
         {
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.log( exception1 );
         }

         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         // Expecting that the buffer is not empty. Otherwise we would assign rather than append.
         activeTcpRequestsStateIterator->second.second.Socket.DataBuffer().Append
            ( ConstantString15AsArray_, static_cast< unsigned int >( ConstantString15Length_ ) );

         goto label3;
      }

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberBytesReceived >= 0 );
      if( numberBytesReceived > 0 )
      {
         // We will validate this after we call {TryParseResponse}, so let's valiate this before as well.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );

         unsigned int responseParsingOutcomeCode;

         if( TryMakeWarmUpStepIsRunning_ )
         {
            responseParsingOutcomeCode = TryParseResponse( GetResponseContentForWarmUp() );
         }
         else
         {
            responseParsingOutcomeCode = TryParseResponse( activeTcpRequestsStateIterator->second.second.Socket.DataBuffer() );
         }

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( ( responseParsingOutcomeCode == 1U && OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success ) ||
              ( responseParsingOutcomeCode == 2U && OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined ) ||
              ( responseParsingOutcomeCode == 4U && OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined ) ||
              ( responseParsingOutcomeCode == 8U && OutcomeCode_ == TEconomicReportReceiverOutcomeCode_OtherError )
            );

         if( ( responseParsingOutcomeCode & ( 1U | 8U ) ) == 0U )
         {
            if( responseParsingOutcomeCode == 2U )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else // 4U
            {
               goto label3;
            }
         }
         else
         {
            return true;
         }
      }
      else
      {
         // Expecting that the buffer is not empty. Otherwise we would assign rather than append.
         activeTcpRequestsStateIterator->second.second.Socket.DataBuffer().Append
            ( ConstantString16AsArray_, static_cast< unsigned int >( ConstantString16Length_ ) );

      label3:
         // I might want to optimize the removal of multiple items but this is probably rarely needed.
         // One way to optimize it is to remove any items only after all parsings and do nothing and return ASAP if a parsing succeeds.
         // yg? See a comment near where we call {ActiveTcpRequestsState_.clear}.
         ActiveTcpRequestsState_.erase( activeTcpRequestsStateIterator );
      }

      return false;
   }

#endif
#if( /* {protected GetResponseContentForWarmUp}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and inline.

#endif
#if( /* {protected TryParseResponse}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and inline.

#endif
#if( /* {private CompleteRun}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::CompleteRun()
   {
      // Visible universe.
      //    {::Common::Threading::TThreadingHelpers::...Sleep...}.
      //       Call.
      //    {PeerStrategyBaseModeCode_}.
      //       Use.
      //    {OutcomeCode_}.
      //       Use.
      //    {ForcedDelayTimeSpanMillisecondsInTestMode_}.
      //       Use.
      //    {ActiveTcpRequestsState_.empty()}.
      //       Use.
      //    {TryMakeWarmUpStepIsRunning_}.
      //       Use.

      do
      {
         if( PeerStrategyBaseModeCode_ == TPeerStrategyBaseModeCode_Test )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }
         
         if( TryMakeWarmUpStepIsRunning_ )
         {
            break;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         {
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success ||
                 OutcomeCode_ == TEconomicReportReceiverOutcomeCode_OtherError
               );
            if( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               // I don't want to sleep after a timeout expiration as in that case, depending on the configuration,
               // we can oversleep the strategy termination time. It probably won't be too bad but I want everything to be correct
               // and I don't want to adjust the configuration for this sleeping.
               // Of course if the report arrives right before the timeout expiration we can still oversleep, which is OK.
               // When we get to this point after the {::select} function times out the {ActiveTcpRequestsState_} collection cannot be empty.
               // So when it's empty we would rather sleep.
               // In test and not warm-up mode, when the web page says "New Release Pending" the report downloading will quickly fail and
               // the {ActiveTcpRequestsState_} collection will be cleared. In that case I want to sleep to have some orders filled.
               // Unfortunately, this condition probably can prevent sleeping under some other conditions when we would rather sleep,
               // which is OK.
               if( ActiveTcpRequestsState_.empty() )

               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
               else
               {
                  {
                     static char const constantString1AsArray[]
                        ( "{Prototype52::TEconomicReportDownloaderWithTcpParallelRequestsBase<TResult_>} cancelled forced sleeping" );

                     // It's probably correct to mark this "Warning".
                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                  }

                  break;
               }
            }

            {
               // It's probably OK to log this even if the sleeping time-span is non-positive.
               static char const constantString1AsArray[]
                  ( "{Prototype52::TEconomicReportDownloaderWithTcpParallelRequestsBase<TResult_>} is forcing sleeping" );

               logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }
         }

         // To keep it simple, sleeping even if the report was received not too fast.
         // This logic is also helpful when testing a purposely long forced delay.
         // This method correctly handles a non-positive sleeping time-span.
         ::Common::Threading::TThreadingHelpers::SleepMilliseconds( ForcedDelayTimeSpanMillisecondsInTestMode_ );
      }
      while( static_cast< void >( false ) , false );
   }

#endif

#if( /* {private ReceiveAnyResponsesAndLogActivityReport}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportDownloaderWithTcpParallelRequestsBase< TResult_ >::ReceiveAnyResponsesAndLogActivityReport()
   {
      // Visible universe.
      //    {EconomicReportReleaseDateTimeMillisecondsSince1970_}.
      //       Use.
      //    {TcpRequestsState_}.
      //       Enumerate.
      //    {TcpRequestsState_[].first}.
      //       Use.
      //    {TcpRequestsState_[].second.TcpRequestInternalConfiguration->LocalIPHostName}.
      //       Use.
      //    {TcpRequestsState_[].second.TcpRequestInternalConfiguration->DestinationUrlAsString}.
      //       Use.
      //    {TcpRequestsState_[].second.StateCode1}.
      //       Use.
      //    {TcpRequestsState_[].second.Socket.available}.
      //       Call.
      //    {TcpRequestsState_[].second.Socket.DataBuffer()}.
      //       Use, update.
      //    {TcpRequestsState_[].second.Socket.DataBuffer().insert}.
      //       Call.
      //    {TcpRequestsState_[].second.Socket.DataBuffer().resize}.
      //       Call.
      //    {TcpRequestsState_[].second.Socket.DataBuffer().DataLength}.
      //       Use.
      //    {TcpRequestsState_[].second.Socket.DataBuffer().AllocateAdditionalCapacityIfNeeded}.
      //       Call.
      //    {TcpRequestsState_[].second.Socket.DataBuffer().Append}.
      //       Call.
      //    {TcpRequestsState_[].second.Socket.DataBufferCapacityMaxLimit()}.
      //       Use.
      //    {TcpRequestsState_[].second.Socket.ReceiveBytesIntoDataBuffer}.
      //       Call.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.
      //    {LogActivityReportHeader}.
      //       Call.

      // This creates another temporary string, which is OK.
      LogActivityReportHeader();

      {
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         //int const tempString1BufferLength( ??? );
         ::std::string tempString1/*( static_cast< unsigned int >( tempString1BufferLength ), '\x00' )*/;

         int tcpRequestStateCounter( 1 );
         
         // Perhaps we should sanity-validate {TcpRequestsState_.size()} but keeping it simple.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ! TcpRequestsState_.empty() );
         for( ::std::multimap< double, TTcpRequestState_ >::iterator tcpRequestsStateIterator1( TcpRequestsState_.begin() ) ; ; )
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsStateIterator1 != TcpRequestsState_.end() );

            {
               // This can't tell us if the counterparty closed the connection. Regardless, we probably don't need to append
               // {ConstantString16AsArray_} here.
               // yg? Assuming this will not throw an exception, even if the socket is still connecting.
               int numberBytesAvailable( tcpRequestsStateIterator1->second.Socket.available() );

               if( numberBytesAvailable > 0 )
               {
                  // Expecting that the buffer is not empty. Otherwise we would assign rather than append.
                  tcpRequestsStateIterator1->second.Socket.DataBuffer().Append
                     ( ConstantString18AsArray_, static_cast< unsigned int >( ConstantString18Length_ ) );

                  try
                  {
                     tcpRequestsStateIterator1->second.Socket.DataBuffer().AllocateAdditionalCapacityIfNeeded
                        ( static_cast< unsigned int >( numberBytesAvailable ),
                          1U,
                          tcpRequestsStateIterator1->second.Socket.DataBufferCapacityMaxLimit()
                        );

                     // Is it potentially possible that this will not read all available data? Even if so keeping it simple.
                     // It's probably impossible that this reads 0 bytes after {tcpRequestsStateIterator1->second.Socket.available}
                     // returned a positive number but in any case there will be no incorrect behavior and we probably don't need to append
                     // {ConstantString16AsArray_} here.
                     tcpRequestsStateIterator1->second.Socket.ReceiveBytesIntoDataBuffer( 0 );
                  }

                  // Catching only POCO exceptions. Assuming this exception is not critical.
                  catch( ::Poco::Exception const & exception1 )

                  {
                     logger1.log( exception1 );
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

                     // Expecting that the buffer is not empty. Otherwise we would assign rather than append.
                     tcpRequestsStateIterator1->second.Socket.DataBuffer().Append
                        ( ConstantString15AsArray_, static_cast< unsigned int >( ConstantString15Length_ ) );
                  }
               }
               else
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
            }

            tcpRequestsStateIterator1->second.Socket.DataBuffer().resize
               ( tcpRequestsStateIterator1->second.Socket.DataBuffer().DataLength );

            //auto predicate1
            //   ( [ & ]
            //     ( TTcpRequestConfiguration const & tcpRequestConfiguration1
            //     )
            //     -> bool
            //     {
            //        return ( ( & tcpRequestConfiguration1.RequestContent ) == tcpRequestsStateIterator1->second.RequestContent() );
            //     }
            //   );
            //::std::vector< TTcpRequestConfiguration >::const_iterator tcpRequestsConfigurationIterator1
            //   //( ::std::find_if( >>>TcpRequestsConfiguration_.cbegin(), >>>TcpRequestsConfiguration_.cend(), predicate1 ) );
            //   ( TTcpRequestConfigurationHelpers::TryFindTcpRequestConfigurationByRequestContentPointer
            //        ( >>>TcpRequestsConfiguration_.cbegin(),
            //          >>>TcpRequestsConfiguration_.cend(),
            //          tcpRequestsStateIterator1->second.RequestContent()
            //        )
            //   );
            //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsConfigurationIterator1 != >>>TcpRequestsConfiguration_.cend() );

            {
               // Assuming this will not overflow.
               int const tempString1BufferLength
                  ( 64 +
                    static_cast< int >( tcpRequestsStateIterator1->second.TcpRequestInternalConfiguration->LocalIPHostName.length() ) +
                    static_cast< int >( tcpRequestsStateIterator1->second.TcpRequestInternalConfiguration->DestinationUrlAsString.length() )
                  );

               //::std::string tempString1( ???, ??? );
               tempString1.resize( static_cast< unsigned int >( tempString1BufferLength ) );
               static char const formatConstantString1AsArray[]( "response; %u; %+.*g; %u; %s; %s%s" );

               // We will format these as an unsigned.
               {
                  // This is actually positive.
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestStateCounter > 0 );

                  // This can be negative only if an exception was thrown and in that case we are not supposed to get here.
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( tcpRequestsStateIterator1->second.StateCode1 >= 0 );
               }

               int tempString1Length
                  ( ::_snprintf_l
                       ( ( & tempString1.front() ),
                         static_cast< unsigned int >( tempString1BufferLength ),
                         formatConstantString1AsArray,
                         ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                         static_cast< unsigned int >( tcpRequestStateCounter ),
                         10,
                         tcpRequestsStateIterator1->first - static_cast< double >( EconomicReportReleaseDateTimeMillisecondsSince1970_ ),
                         static_cast< unsigned int >( tcpRequestsStateIterator1->second.StateCode1 ),
                         tcpRequestsStateIterator1->second.TcpRequestInternalConfiguration->LocalIPHostName.c_str(),
                         tcpRequestsStateIterator1->second.TcpRequestInternalConfiguration->DestinationUrlAsString.c_str(),
                         ::Poco::LineEnding::NEWLINE_DEFAULT.c_str()
                       )
                  );

               if( tempString1Length >= 0 )
               {
                  //tempString1.resize( ??? );

                  // Incorrectness: not changing {tcpRequestsStateIterator1->second.Socket.DataBuffer().DataLength} -- no big deal.
                  tcpRequestsStateIterator1->second.Socket.DataBuffer().insert
                     ( 0U, tempString1.data(), static_cast< unsigned int >( tempString1Length ) );
               }
               else
               {
                  ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                  //tempString1.assign( ???, ??? );

                  // Incorrectness: same as the above.
                  tcpRequestsStateIterator1->second.Socket.DataBuffer().insert
                     ( 0U, formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
               }
               
               //logger1.information( ??? );
            }

            // If an error occurred at any stage of this particular request one might want to mark this message accordingly.
            // But it's not necessarily a good idea in all scenarios.
            logger1.information( tcpRequestsStateIterator1->second.Socket.DataBuffer() );

            // It's probably inefficient to call {TcpRequestsState_.end} on each loop but this code is not performance critical.
            if( ( ++ tcpRequestsStateIterator1 ) != TcpRequestsState_.end() )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               break;
            }

            // Assuming this will not overflow.
            ++ tcpRequestStateCounter;
         }
      }
   }

#endif
#if( /* {protected LogActivityReportHeader}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and inline.

#endif
}
