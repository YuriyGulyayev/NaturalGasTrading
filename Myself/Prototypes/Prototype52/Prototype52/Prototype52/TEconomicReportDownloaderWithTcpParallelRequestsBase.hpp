#pragma once

#include "../Common/Networking/TStreamSocketWithDataBuffer.hpp"
#include "../Common/Networking/TSocketNextDynamicPortNumberAdvancer.hpp"
#include "./TEconomicReportReceiverBase.hpp"
#include "./TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // yg? This class doesn't use keep-alive because the US Department of Energy web server breaks the connection
   // yg? as soon as a keep-alive packet arrives.
   // yg? Otherwise our options would be:
   // yg? 1. Set keep-alive when creating a socket and unset it after pre-sending each request. Or after pre-sending all requests,
   // yg?     in a separate loop. In this case timeout would be for example 100 and interval would be for example 50.
   // yg? 2. Set keep-alive after pre-sending each request with timeout being 1 and interval being a big number.
   // yg? As we now reconnect unconnected sockets the above options might need to be revisited. Keep-alive is probably less important
   // yg? now, although it would be nice to warm-up the route at the last moment.
   // yg? This might still be worth doing when sending requests via a TCP forwarder. Keep in mind that it has its own keep-alive.
   //
   // Visible universe.
   //    {::Common::Math::TMultiplyWithCarryRandomNumberCommonGeneratorHelpers}.
   //    {::Common::Networking::TNetworkingHelpers}.
   //    {::Common::Networking::TSocketNextDynamicPortNumberAdvancer<>}.
   //    {::Common::Networking::TStreamSocketWithDataBuffer}.
   //    {::Common::Threading::TThreadingHelpers}.
   //    {TEconomicReportReceiverBase< TResult_ >}.
   //       Subclass.
   //    {TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration}.
   //    {TTcpRequestConfiguration}.
   //    {EconomicReportReceptionTimeoutTimeSpanMilliseconds_}.
   //       Use.
   //    {DateTimeKeeper_}.
   //       Use.
   //    {EconomicReportReleaseDateTimeMillisecondsSince1970_}.
   //       Use.
   //    {PeerStrategyBaseModeCode_}.
   //       Use.
   //    {OutcomeCode_}.
   //       Use, update.
   //    Instance constructors -- base.
   //       Hide, possibly implicitly. Call, possibly implicitly.
   //    Instance destructor -- base.
   //       Override, possibly implicitly. Call, possibly implicitly.
   //    {Initialize} -- base.
   //       Hide, call.
// todo Here and elsewhere, should we use the word "overload" instead of "hide"?
   //    {Prepare} -- base.
   //       Override, call.
   //    {TryRun}.
   //       Call.
   //    {DoTryRun} -- base.
   //       Implement.
   //    {TryMakeWarmUpStep} -- base.
   //       Override, call.
   //    //{WarmUp} -- base.
   //    //   Override, call.
   //    {TryCreateNewsHubMessage}.
   //       Call.
   //    {LogActivityReportIfPossible} -- base.
   //       Implement.
   //    {InvocationTimeOffsetMilliseconds()}.
   //       Use.

   template
      < typename TResult_
      >
   class TEconomicReportDownloaderWithTcpParallelRequestsBase abstract :
      public TEconomicReportReceiverBase< TResult_ >
   {
#if( /* {private TTcpRequestInternalConfiguration_}. */ 1 )

      // yg? I don't like the order of members in both {TTcpRequestConfiguration} and {TTcpRequestInternalConfiguration_} classes
      // yg? but I don't want to touch it for now. Compare the order to {TPeerConfiguration}. It might need revisiting there as well.

      private: class TTcpRequestInternalConfiguration_
      {
   #if( /* {public LocalIPHostName}. */ 1 )

         //
         public: ::std::string LocalIPHostName;

   #endif
   #if( /* {public LocalSocketAddress}. */ 1 )

         //
         public: ::Poco::Net::SocketAddress LocalSocketAddress;

   #endif
   #if( /* {public ShallAdvanceSocketNextDynamicPortNumber}. */ 1 )

         // yg? Consider placing this before {LocalSocketAddress} because the advancing happens before the binding.
         // yg? Is it really a good idea? Another option would be to place this after {DestinationSocketAddress}.
         public: bool ShallAdvanceSocketNextDynamicPortNumber;

   #endif
   #if( /* {public DestinationUrlAsString}. */ 1 )

         // yg? I don't like the word "destination" but neither I do something like "economic report sender".
         public: ::std::string DestinationUrlAsString;

   #endif
   #if( /* {public DestinationSocketAddress}. */ 1 )

         //
         public: ::Poco::Net::SocketAddress DestinationSocketAddress;

   #endif
   #if( /* {public RequestContent}. */ 1 )

         //
         public: ::std::string RequestContent;

   #endif
   #if( /* {public NumberRequestsToSend}. */ 1 )

         //
         public: int NumberRequestsToSend;

   #endif
   #if( /* {public RequestsPreSendingBitMask}. */ 1 )

         // We probably don't need this to be 64-bit.
         public: unsigned int RequestsPreSendingBitMask;

   #endif
   #if( /* {public FirstRequestSendingTimeOffsetMilliseconds}. */ 1 )

         // Keep in mind that this is a {double}.
         public: double FirstRequestSendingTimeOffsetMilliseconds;

   #endif
   #if( /* {public RequestSendingIntervalMilliseconds}. */ 1 )

         // Keep in mind that this is a {double}.
         public: double RequestSendingIntervalMilliseconds;

   #endif

   #if( /* {public} Instance default constructor. */ 1 )

         //

         public: explicit TTcpRequestInternalConfiguration_();

   #endif
   #if( /* {private} Instance copy constructor. */ 1 )

         //

         private: explicit TTcpRequestInternalConfiguration_
            ( TTcpRequestInternalConfiguration_ const & source
            );

   #endif
   #if( /* {public} Instance move constructor. */ 1 )

         //

         public: TTcpRequestInternalConfiguration_
            ( TTcpRequestInternalConfiguration_ && source
            );

   #endif
   #if( /* {(public)} Instance destructor. */ 1 )

         // Could be autogenerated.

   #endif
   #if( /* {private operator =}. */ 1 )

         //

         private: TTcpRequestInternalConfiguration_ & operator =
            ( TTcpRequestInternalConfiguration_ const & source
            );

   #endif
   #if( /* {public operator =}. */ 1 )

         //

         public: TTcpRequestInternalConfiguration_ & operator =
            ( TTcpRequestInternalConfiguration_ && source
            );

   #endif

   #if( /* {public Prepare}. */ 1 )

         // We don't currently need an instance constructor that does this.
         // But if I add one I'd probably need to rename this method to {Initialize}, but it's a heavy operation that can throw an exception.

         public: void Prepare
            ( TTcpRequestConfiguration && tcpRequestConfiguration
            );

   #endif

   #if( /* {public Assign}. */ 1 )

         // yg? Should this be named {Move}?

         public: void Assign
            ( TTcpRequestInternalConfiguration_ && source
            );

   #endif
      };

#endif
#if( /* {private TTcpRequestState_}. */ 1 )

      //

      private: class TTcpRequestState_
      {
   #if( /* {public TcpRequestInternalConfiguration}. */ 1 )

         //
         public: TTcpRequestInternalConfiguration_ const * TcpRequestInternalConfiguration;

   #endif
   #if( /* {public StateCode1}. */ 1 )

         // Initial value:
         //    -1 -- don't pre-send the request.
         //    0 -- pre-send the request.
         // Value after pre-sending requests:
         //    0 -- we didn't pre-send the request for any reason,
         //          possibly because the socket wasn't connected and we initiated a reconnection.
         //    1 -- we pre-sent the request.
         // Value after sending requests:
         //    0 or 1 -- previous value stays unchanged until we actually get a chance to try to send this request.
         //    2 -- we tried to send the whole request or the last byte of it, successfully or not.
         // yg? As we log these codes it would be nice to use more codes to denote the variety of states.
         // yg? Magic numbers hardcoded.
         public: int StateCode1;

   #endif
   #if( /* {public Socket}. */ 1 )

         //
         public: ::Common::Networking::TStreamSocketWithDataBuffer Socket;

   #endif

   #if( /* //{(private)} Instance default constructor. */ 1 )

         // Cannot be autogenerated.

   #endif
   #if( /* {private} Instance copy constructor. */ 1 )

         //

         private: explicit TTcpRequestState_
            ( TTcpRequestState_ const & source
            );

   #endif
   #if( /* {public} Instance move constructor. */ 1 )

         //

         public: TTcpRequestState_
            ( TTcpRequestState_ && source
            );

   #endif
   #if( /* {public} Instance constructor. */ 1 )

         //

         public: explicit TTcpRequestState_
            ( TTcpRequestInternalConfiguration_ const & tcpRequestInternalConfiguration1
            );

   #endif
   #if( /* {(public)} Instance destructor. */ 1 )

         // Could be autogenerated.

   #endif
   #if( /* {private operator =}. */ 1 )

         //

         private: TTcpRequestState_ & operator =
            ( TTcpRequestState_ const & source
            );

   #endif
   #if( /* {public operator =}. */ 1 )

         //

         public: TTcpRequestState_ & operator =
            ( TTcpRequestState_ && source
            );

   #endif

   #if( /* {public Assign}. */ 1 )

         // yg? Should this be named {Move}?

         public: void Assign
            ( TTcpRequestState_ && source
            );

   #endif
      };

#endif

#if( /* {private RequestPreSendingTimeOffsetMilliseconds_}. */ 1 )

      //
      private: int RequestPreSendingTimeOffsetMilliseconds_;

#endif
#if( /* {private ForcedDelayTimeSpanMillisecondsInTestMode_}. */ 1 )

      //
      private: int ForcedDelayTimeSpanMillisecondsInTestMode_;

#endif
#if( /* {private TcpRequestsConfiguration_}. */ 1 )

      // Storing the configuration object as is.
      private: ::std::vector< TTcpRequestConfiguration > TcpRequestsConfiguration_;

#endif

#if( /* {private TcpRequestsInternalConfiguration_}. */ 1 )

      //
      private: ::std::vector< TTcpRequestInternalConfiguration_ > TcpRequestsInternalConfiguration_;

#endif
#if( /* {private EconomicReportReleaseTimeMilliseconds_}. */ 1 )

      //
      private: int EconomicReportReleaseTimeMilliseconds_;

#endif
#if( /* {private TcpRequestsState_}. */ 1 )

      // The order of equal keys is probably undefined.
      // The floating point keys are not rounded to make them deterministically comparable.
      // Note that all {TcpRequestsState_} items must be created before copying their pointers
      // as otherwise the pointers' copies can become invalid.
      private: ::std::multimap< double, TTcpRequestState_ > TcpRequestsState_;

#endif
#if( /* {private ActiveTcpRequestsState_}. */ 1 )

      // This map contains references instead of pointers, which probably makes it more usable in STL algorithms.
      // TODO 3 yg? In addition we might need {private: ::fd_set ActiveSocketsFDSet_;}. See related comment near
      // TODO 3 yg? {::Common::Networking::TNetworkingHelpers::SelectAnySocketsReadyForReadingHandle}.
      private: ::std::map< ::poco_socket_t, typename ::std::multimap< double, TTcpRequestState_ >::value_type & > ActiveTcpRequestsState_;
   
#endif
#if( /* {private SocketNextDynamicPortNumberAdvancer_}. */ 1 )

      // yg? Consider renaming this to specify that this advances TCP port number, and not UDP or any other protocol.
      // yg? Then I would need to rename some other fields and methods as well.
      private: ::Common::Networking::TSocketNextDynamicPortNumberAdvancer< ::Poco::Net::StreamSocket > SocketNextDynamicPortNumberAdvancer_;

#endif
#if( /* {private ShallAdvanceSocketNextDynamicPortNumber_}. */ 1 )

      //
      private: bool ShallAdvanceSocketNextDynamicPortNumber_;

#endif
#if( /* {private TimeStampMillisecondsOnConnectingSockets_}. */ 1 )

      //
      private: int TimeStampMillisecondsOnConnectingSockets_;

#endif
#if( /* {protected TryMakeWarmUpStepIsRunning_}. */ 1 )

      //
      protected: bool TryMakeWarmUpStepIsRunning_;

#endif
#if( /* {protected WarmUpCounter_}. */ 1 )

      //
      protected: int WarmUpCounter_;

#endif

#if( /* {private ConstantString13AsArray_}. */ 1 )

      //
      private: static char const ConstantString13AsArray_[];

      //
      private: static void ConstantString13StaticAssertion();

#endif
#if( /* {private ConstantString13Length_}. */ 1 )

      //
      private: static int const ConstantString13Length_ = 36;

#endif
#if( /* {private ConstantString15AsArray_}. */ 1 )

      //
      private: static char const ConstantString15AsArray_[];

      //
      private: static void ConstantString15StaticAssertion();

#endif
#if( /* {private ConstantString15Length_}. */ 1 )

      //
      private: static int const ConstantString15Length_ = 38;

#endif
#if( /* {private ConstantString16AsArray_}. */ 1 )

      //
      private: static char const ConstantString16AsArray_[];

      //
      private: static void ConstantString16StaticAssertion();

#endif
#if( /* {private ConstantString16Length_}. */ 1 )

      //
      private: static int const ConstantString16Length_ = 22;

#endif
#if( /* {private ConstantString18AsArray_}. */ 1 )

      //
      private: static char const ConstantString18AsArray_[];

      //
      private: static void ConstantString18StaticAssertion();

#endif
#if( /* {private ConstantString18Length_}. */ 1 )

      //
      private: static int const ConstantString18Length_ = 31;

#endif

#if( /* {protected} Instance default constructor. */ 1 )

      //

      protected: explicit TEconomicReportDownloaderWithTcpParallelRequestsBase();

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {protected} Instance constructor. */ 1 )

      //

      protected: explicit TEconomicReportDownloaderWithTcpParallelRequestsBase
         ( TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration && configuration1
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // {virtual}.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif

#if( /* {public Initialize}. */ 1 )

      //

      public: void Initialize
         ( TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration && configuration1
         );

#endif
#if( /* {private DoInitialize}. */ 1 )

      //

      private: void DoInitialize
         ( TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration && configuration1
         );

#endif
#if( /* {public Prepare}. */ 1 )

      //

      public: virtual void Prepare
         ( ::Common::Time::TDateTimeKeeper const & dateTimeKeeper
         ) override;

#endif
#if( /* {protected DoTryRun}. */ 1 )

      //

      protected: virtual /*bool*/ void DoTryRun() override;

#endif

#if( /* {public TryMakeWarmUpStep}. */ 1 )

      //

      public: virtual bool TryMakeWarmUpStep() override;

#endif

#if( /* {public LogActivityReportIfPossible}. */ 1 )

      //

      public: virtual void LogActivityReportIfPossible() override;

#endif

#if( /* {private PrepareRun}. */ 1 )

      //
      
      private: void PrepareRun();

#endif
#if( /* {private TryDownloadEconomicReport}. */ 1 )

      //
      
      private: void TryDownloadEconomicReport();

#endif
#if( /* {private CreateTcpRequestsState}. */ 1 )

      //
      
      private: void CreateTcpRequestsState();

#endif
#if( /* {protected ConfigureSocket}. */ 1 )

      // It's possible that {socket1} has been {close}d and re{init}ed.
      // An override shall assign a value to {socket1.DataBufferCapacityMaxLimit()}.
      // An override should call {socket1.DataBuffer().resize( size_type )}.

      protected: virtual void ConfigureSocket
         ( ::Common::Networking::TStreamSocketWithDataBuffer & socket1
         ) const;

#endif
#if( /* {private OnConnectingSockets}. */ 1 )

      //
      
//TODO Rename this as this now looks like an event.
      private: void OnConnectingSockets();

#endif
#if( /* {private TryAsyncTryConnectSockets}. */ 1 )

      //
      
      private: void TryAsyncTryConnectSockets();

#endif
#if( /* {private TryPreSendRequests}. */ 1 )

      // yg? Should this method be renamed? We have 2 methods with this name and both do more than just presend.
      
      private: void TryPreSendRequests();

#endif
#if( /* {private TryPreSendRequests}. */ 1 )

      // yg? This should be named something like "try check sockets connected and async try reconnect or presend requests".
      // yg? See the other overload comment.
      
      private: void TryPreSendRequests
         ( bool shallPreSendRequests
         );

#endif
#if( /* {private TryAsyncTryReconnectSocket}. */ 1 )

      //
      
      private: void TryAsyncTryReconnectSocket
         ( TTcpRequestState_ & tcpRequestState
         );

#endif
#if( /* {private SleepMillisecond}. */ 1 )

      //
      
      private: void SleepMillisecond();

#endif
#if( /* {private SocketNextDynamicPortNumberAdvancerRunIfNeeded}. */ 1 )

      //
      
      private: void SocketNextDynamicPortNumberAdvancerRunIfNeeded();

#endif
#if( /* {private SocketNextDynamicPortNumberAdvancerRunUntilNextMillisecondIfNeeded}. */ 1 )

      //
      
      private: bool SocketNextDynamicPortNumberAdvancerRunUntilNextMillisecondIfNeeded();

#endif
#if( /* {private TrySendRequestsAndReceiveAndProcessResponses}. */ 1 )

      //
      
      private: void TrySendRequestsAndReceiveAndProcessResponses();

#endif
#if( /* {private ProcessSelectedSockets}. */ 1 )

      // Assumption: {socketsReadyForReadingHandle} is not empty.
      // Returns {true} if economic report reception completed, successfully or not.
      // Not using the word "ready for reading" in this method name to leave the door open to have for example ready for writing sockets.
      // Although we probably are not going to need anything like that.
      
      private: bool ProcessSelectedSockets
         ( ::fd_set const & socketsReadyForReadingHandle
         );

#endif
#if( /* {private ProcessSelectedSocketReadyForReading}. */ 1 )

      // Returns {true} if economic report reception completed, successfully or not.
      
      private: bool ProcessSelectedSocketReadyForReading
         ( typename ::std::map< ::poco_socket_t, typename ::std::multimap< double, TTcpRequestState_ >::value_type & >::iterator activeTcpRequestsStateIterator
         );

#endif
#if( /* {protected GetResponseContentForWarmUp}. */ 1 )

      //

      protected: virtual ::Common::DataStructures::TDataBuffer GetResponseContentForWarmUp() const = 0;

#endif
#if( /* {protected TryParseResponse}. */ 1 )

      // On success and possibly under some other conditions, this method updates a few fields, including
      // {Result}, {EconomicReportReceptionTimeStampMilliseconds_}, and/or {OutcomeCode_}.
      // Returns:
      // @ 1U on success.
      //     In this case the method assigns {OutcomeCode_ = TEconomicReportReceiverOutcomeCode_Success} and possibly
      //     updates {EconomicReportReceptionTimeStampMilliseconds_}.
      // @ 2U on a non-severe error, for example, if not enough text arrived yet.
      // @ 4U on a non-severe error if economic report is not going to arrive on this socket.
      //     This code is returned when the text indicates that the report is not available yet.
      // @ 8U on a severe error, for example, if the text is malformed, possibly because its format has changed.
      //     In this case the method assigns {OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError}.
      // TODO 3 yg? We need an {enum} for these magic numbers. Success should probably be denoted by 0U
      // TODO 3 yg? but that would complicate the return value processing.
      // TODO 3 yg? For efficiency, this method shoud be passed to base class as a template parameter. I would need to write a prototype
      // TODO 3 yg? and make sure it's efficient.
      
      protected: virtual unsigned int TryParseResponse
         ( ::Common::DataStructures::TDataBuffer const & responseContent
         ) = 0;

#endif
#if( /* {private CompleteRun}. */ 1 )

      //
      
      private: void CompleteRun();

#endif

#if( /* {private ReceiveAnyResponsesAndLogActivityReport}. */ 1 )

      //
      
      private: void ReceiveAnyResponsesAndLogActivityReport();

#endif
#if( /* {protected LogActivityReportHeader}. */ 1 )

      //
      
      protected: virtual void LogActivityReportHeader() const = 0;

#endif
   };
}
