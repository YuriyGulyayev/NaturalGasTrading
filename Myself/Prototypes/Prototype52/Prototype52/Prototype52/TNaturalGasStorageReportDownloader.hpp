#pragma once

#include "./TNewsHubHelpers.hpp"
#include "./TEconomicReportDownloaderWithTcpParallelRequestsBase.hpp"
#include "./TNaturalGasStorageReportDownloaderConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // yg? Name of this class and/or namespace should specify what jurisdiction and authority this economic report comes from.
   //
   // Visible universe.
   //    {TNewsHubHelpers}.
   //    {TEconomicReportDownloaderWithTcpParallelRequestsBase< int >}.
   //       Subclass.
   //    {TNaturalGasStorageReportDownloaderConfiguration}.
   //    //{PeerStrategyBaseModeCode_}.
   //    //   Use.
   //    {Result}.
   //       Use, update.
   //    {EconomicReportReceptionTimeStampMilliseconds_}.
   //       Update.
   //    {OutcomeCode_}.
   //       Use, update.
   //    {TryCreateNewsHubMessage} -- base.
   //       Override.
   //    {SafeGetEconomicReportReceptionDateTimeStampOffsetMilliseconds()}.
   //       Use.
   //    {TryMakeWarmUpStepIsRunning_}.
   //       Use.
   //    {WarmUpCounter_}.
   //       Use.
   //    Instance constructors -- base.
   //       Hide, possibly implicitly. Call, possibly implicitly.
   //    Instance destructor -- base.
   //       Override, possibly implicitly. Call, possibly implicitly.
   //    {Initialize} -- base.
   //       Hide, call.
   //    //{Prepare} -- base.
   //    //   Override, call.
   //    {DoTryRun} -- base.
   //       Override, call.
   //    {ConfigureSocket} -- base.
   //       Override, call.
   //    {GetResponseContentForWarmUp} -- base.
   //       Implement.
   //    {TryParseResponse} -- base.
   //       Implement.
   //    {LogActivityReportHeader} -- base.
   //       Implement.

   class TNaturalGasStorageReportDownloader :
      public TEconomicReportDownloaderWithTcpParallelRequestsBase< int >
   {
#if( /* {private SocketDataBufferInitialCapacity_}. */ 1 )

      // For maximum performance, this should be greather than or equal any response length, including the "New Release Pending".
      private: static int const SocketDataBufferInitialCapacity_ = 3 * 1024;

#endif
#if( /* {private SocketDataBufferCapacityMaxLimit_}. */ 1 )

      // We can exceed this by a little because we can append text to the data buffer.
      private: static int const SocketDataBufferCapacityMaxLimit_ = SocketDataBufferInitialCapacity_ * 2;

#endif

#if( /* {private ResponseContentParsingFactor1_}. */ 1 )

      // Offset from which to begin searching for "\nNet Change: ".
      // Actual offset of that substring is close to 373.
      // 373 - 16 == 357
      // TODO 3 yg? Revisit this magic number.
      private: static int const ResponseContentParsingFactor1_ = 357;

#endif

#if( /* {private ResponseContentActualOffset37_}. */ 1 )

      // Actual offset of "\nNet Change: " in response text. We will log it.
      // This value can but is not guaranteed to be valid when all response parsings failed.
      // yg? Some day I might want to name this better. In {TPetroleumStatusReportDownloader::TResponseContentLineParsingState_}
      // yg? this is called {ResponseContentLineTitleOffset}.

      private: int ResponseContentActualOffset37_;

#endif

#if( /* {private NewsHubMessageText_}. */ 1 )

      //
      private: ::std::string NewsHubMessageText_;

#endif

#if( /* {private ConstantString26Length_}. */ 1 )

      // Not validating this with a {static_assert}. But validating this in {DoInitialize}.
      // yg? Consider eliminating this and using
      // yg? {static_cast< int >( sizeof( ConstantStrings26AsArray_[ 0U ] ) / sizeof( ConstantStrings26AsArray_[ 0U ][ 0U ] ) - 1U )}
      // yg? instead.
      // The same applies to {TPetroleumStatusReportDownloader::ConstantString26Length_}.
      private: static int const ConstantString26Length_ = 392;

#endif
#if( /* {private ConstantStrings26AsArray_}. */ 1 )

      //
      private: static char const ConstantStrings26AsArray_[ 3U ][ static_cast< unsigned int >( ConstantString26Length_ + 1 ) ];

#endif
#if( /* {private ConstantString34AsArray_}. */ 1 )

      //
      private: static char const ConstantString34AsArray_[];

      //
      private: static void ConstantString34StaticAssertion();

#endif
#if( /* {private ConstantString34Length_}. */ 1 )

      //
      private: static int const ConstantString34Length_ = 13;

#endif
#if( /* {private ConstantString37AsArray_}. */ 1 )

      //
      private: static char const ConstantString37AsArray_[];

      //
      private: static void ConstantString37StaticAssertion();

#endif
#if( /* {private ConstantString37Length_}. */ 1 )

      //
      private: static int const ConstantString37Length_ = 13;

#endif
#if( /* {private ConstantString44AsArray_}. */ 1 )

      // TODO 2 yg? For both natural gas and petroleum, it might be faster to make this not fixed width
      // TODO 2 yg? as the transmission of 1 byte can be very slow relative to the CPU speed.
      private: static char const ConstantString44AsArray_[];

      //
      private: static void ConstantString44StaticAssertion();

#endif
#if( /* {private ConstantString44Length_}. */ 1 )

      //
      private: static int const ConstantString44Length_ = TNewsHubHelpers::MessageTextHeaderLength + 38;

#endif
#if( /* {private ConstantString44Value1Offset_}. */ 1 )

      //
      private: static int const ConstantString44Value1Offset_ = 42;

#endif
#if( /* {private ConstantString44Value1Length_}. */ 1 )

      //
      private: static int const ConstantString44Value1Length_ = 4;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TNaturalGasStorageReportDownloader();

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TNaturalGasStorageReportDownloader
         ( TNaturalGasStorageReportDownloaderConfiguration && configuration1
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
         ( TNaturalGasStorageReportDownloaderConfiguration && configuration1
         );

#endif
#if( /* {private DoInitialize}. */ 1 )

      //

      private: void DoInitialize
         ( //TNaturalGasStorageReportDownloaderConfiguration && configuration1
         );

#endif
#if( /* {protected DoTryRun}. */ 1 )

      //

      protected: virtual /*bool*/ void DoTryRun() override;

#endif

#if( /* {public TryCreateNewsHubMessage}. */ 1 )

      //

      public: virtual ::std::string const * TryCreateNewsHubMessage() override;

#endif

#if( /* {protected ConfigureSocket}. */ 1 )

      //

      protected: virtual void ConfigureSocket
         ( ::Common::Networking::TStreamSocketWithDataBuffer & socket1
         ) const override;

#endif
#if( /* {protected GetResponseContentForWarmUp}. */ 1 )

      //

      protected: virtual ::Common::DataStructures::TDataBuffer GetResponseContentForWarmUp() const override;

#endif
#if( /* {protected TryParseResponse}. */ 1 )

      //
      
      protected: virtual unsigned int TryParseResponse
         ( ::Common::DataStructures::TDataBuffer const & responseContent
         ) override;

#endif

#if( /* {protected LogActivityReportHeader}. */ 1 )

      //
      
      protected: virtual void LogActivityReportHeader() const override;

#endif
   };
}
