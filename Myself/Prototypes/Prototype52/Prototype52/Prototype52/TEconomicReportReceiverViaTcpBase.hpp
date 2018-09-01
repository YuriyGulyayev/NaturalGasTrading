#pragma once

#include "../Common/Networking/TStreamSocketWithDataBuffer.hpp"
#include "./TEconomicReportReceiverBase.hpp"
#include "./TEconomicReportReceiverViaTcpBaseConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // Visible universe.
   //    {::Poco::TimeoutException}.
   //    {::Common::Networking::TNetworkingHelpers}.
   //    {::Common::Networking::TStreamSocketWithDataBuffer}.
   //    {TEconomicReportReceiverBase< TResult_ >}.
   //       Subclass.
   //    {TEconomicReportReceiverViaTcpBaseConfiguration}.
   //    {EconomicReportReceptionTimeoutTimeSpanMilliseconds_}.
   //       Use.
   //    {DateTimeKeeper_}.
   //       Use.
   //    {EconomicReportReleaseDateTimeMillisecondsSince1970_}.
   //       Use.
   //    //{PeerStrategyBaseModeCode_}.
   //    //   Use.
   //    {OutcomeCode_}.
   //       Use, update.
   //    Instance constructors -- base.
   //       Hide, possibly implicitly. Call, possibly implicitly.
   //    Instance destructor -- base.
   //       Override, possibly implicitly. Call, possibly implicitly.
   //    {Initialize} -- base.
   //       Hide, call.
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

   template
      < typename TResult_
      >
   class TEconomicReportReceiverViaTcpBase abstract :
      public TEconomicReportReceiverBase< TResult_ >
   {
#if( /* {private EconomicReportSenderIPHostName_}. */ 1 )

      //
      private: ::std::string EconomicReportSenderIPHostName_;

#endif
#if( /* {private EconomicReportSenderIPPortNumber_}. */ 1 )

      // yg? Consider making this an {int} or {unsigned int}. In .NET it's an {int}.
      // yg? But all API and POCO functions accept an {unsigned short}.
      private: unsigned short EconomicReportSenderIPPortNumber_;

#endif
#if( /* {private LocalIPHostName_}. */ 1 )

      //
      private: ::std::string LocalIPHostName_;

#endif
#if( /* //{private SocketKeepAliveTimeoutTimeSpanMilliseconds_}. */ 1 )

      ////
      //private: int SocketKeepAliveTimeoutTimeSpanMilliseconds_;

#endif
#if( /* //{private SocketKeepAliveIntervalMilliseconds_}. */ 1 )

      ////
      //private: int SocketKeepAliveIntervalMilliseconds_;

#endif

#if( /* {private EconomicReportSenderSocketAddress_}. */ 1 )

      //
      private: ::Poco::Net::SocketAddress EconomicReportSenderSocketAddress_;

#endif
#if( /* {private LocalSocketAddress_}. */ 1 )

      //
      private: ::Poco::Net::SocketAddress LocalSocketAddress_;

#endif
#if( /* {protected Socket_}. */ 1 )

      // yg? Remember to reset {SocketStateIsValid_} when a socket handle state corrupting error occurs or when closing socket handle.
      protected: ::Common::Networking::TStreamSocketWithDataBuffer Socket_;

#endif
#if( /* {protected SocketStateIsValid_}. */ 1 )

      // When this is {false} we shall {close} and {init} {Socket_}.
      // We must clear this flag after the receive timeout expires because the socket handle state becomes indeterminate in that case.
      // Note that a receive operation can time-out only when {TryMakeWarmUpStep} is not running and in that case
      // {LogActivityReportIfPossible} anyway unconditionally clears this flag and closes the socket.
      // yg? See {Socket_} comment.
      protected: bool SocketStateIsValid_;

#endif
#if( /* {protected SocketDataBufferParsingOffset_}. */ 1 )

      //
      protected: int SocketDataBufferParsingOffset_;

#endif
#if( /* {private CanLogActivityReport_}. */ 1 )

      // Under some conditions we don't set this flag. In that case we log something and later don't log an activity report.
      private: bool CanLogActivityReport_;

#endif
#if( /* {private TryMakeWarmUpStepIsRunning_}. */ 1 )

      //
      private: bool TryMakeWarmUpStepIsRunning_;

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

      protected: explicit TEconomicReportReceiverViaTcpBase();

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {protected} Instance constructor. */ 1 )

      //

      protected: explicit TEconomicReportReceiverViaTcpBase
         ( TEconomicReportReceiverViaTcpBaseConfiguration && configuration1
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
         ( TEconomicReportReceiverViaTcpBaseConfiguration && configuration1
         );

#endif
#if( /* {private DoInitialize}. */ 1 )

      //

      private: void DoInitialize
         ( TEconomicReportReceiverViaTcpBaseConfiguration && configuration1
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

      // Before calling {TryRun} the caller must call {TryMakeWarmUpStep} at least once. This is needed to begin connecting
      // to economic report sender. However not doing so would not result in undefined behavior.

      public: virtual bool TryMakeWarmUpStep() override;

#endif

#if( /* {public LogActivityReportIfPossible}. */ 1 )

      //

      public: virtual void LogActivityReportIfPossible() override;

#endif
#if( /* {private RemoveParsedReceivedData}. */ 1 )

      //
      
      private: void RemoveParsedReceivedData();

#endif

#if( /* {private TryAsyncTryConnectToEconomicReportSender}. */ 1 )

      //
      
      private: void TryAsyncTryConnectToEconomicReportSender();

#endif
#if( /* {protected ConfigureSocket}. */ 1 )

      // {Socket_.close}, {Socket_.init}, and {ConfigureSocket} can be called multiple times.
      // An override shall assign a value to {Socket_.DataBufferCapacityMaxLimit()}.
      // An override should call {Socket_.DataBuffer().resize( size_type )}.
      // However it needs to do the 2 above only the 1st time it's called.

      protected: virtual void ConfigureSocket();

#endif
#if( /* {private TryReceiveAndProcessData}. */ 1 )

      //
      
      private: void TryReceiveAndProcessData();

#endif
#if( /* {protected TrySendHeartBeatMessage}. */ 1 )

      // On error this method clears the {SocketStateIsValid_} flag.
      // This method is called while the socket is in non-blocking mode and it shall leave the socket blocking mode unchanged.
      // It should not even temporarily change the blocking mode as that would imply a bloated and inefficient code.
      // Currently some/all implementations treat the "would block" error just like any other,
      // assuming that the socket state became invalid.
      // The base implementation does nothing and returns {true}.
      //
      // yg? Bug: the base class currently assumes that this method actually sends something. Otherwise, if the connection breaks
      // yg? we will never detect it. Note that, as mentioned above, the base implementation doesn't send anything,
      // yg? so a subclass must either override this method to send something or detect a broken connection by some other means.
      // yg? Furthermore, even if this method does send something a lot of sends might succeed until a "would block" error occurs.
      // yg? A solution might be to make send buffer smaller or use keep-alive.
      // yg? A more bloated solution would be to handle incoming heartbeats provided the server sends them.
      // TODO 3 yg? Revisit this. Test what will happen in case the connection breaks but the app keeps sending bytes periodically.
      
      protected: virtual bool TrySendHeartBeatMessage();

#endif
#if( /* {protected TryParseReceivedData}. */ 1 )

      // On success and possibly under some other conditions, this method updates a few fields, including
      // {Result}, {EconomicReportReceptionTimeStampMilliseconds_}, {OutcomeCode_}, {SocketDataBufferParsingOffset_},
      // and/or {SocketStateIsValid_}.
      // Returns:
      // @ 1U on success.
      //     In this case the method assigns {OutcomeCode_ = TEconomicReportReceiverOutcomeCode_Success} and possibly
      //     updates {EconomicReportReceptionTimeStampMilliseconds_}.
      // @ 2U on a non-severe error, for example, if not enough data arrived yet.
      // @ 4U is reserved.
      // @ 8U on a severe error, for example, if the data is malformed, possibly because its format has changed.
      //     In this case the method assigns {OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError} and possibly
      //     {SocketStateIsValid_ = false}.
      // TODO 3 yg? We need an {enum} for these magic numbers. Success should probably be denoted by 0U
      // TODO 3 yg? but that would complicate the return value processing.
      // TODO 3 yg? For efficiency, this method shoud be passed to base class as a template parameter. I would need to write a prototype
      // TODO 3 yg? and make sure it's efficient.
      
      protected: virtual unsigned int TryParseReceivedData() = 0;

#endif
#if( /* //{protected CompleteWarmUpStep}. */ 1 )

      //// yg? Consider renaming this to {CompleteMakeWarmUpStep}. But that would be ugly.
      //
      //protected: virtual void CompleteWarmUpStep();

#endif

#if( /* {protected LogActivityReport}. */ 1 )

      // This method is currently declared {const} as it's not expected to modify anything.
      // This method must not modify {Socket_.DataBuffer()} because the data can be preserved and used later.
      
      protected: virtual void LogActivityReport() const = 0;

#endif
   };
}
