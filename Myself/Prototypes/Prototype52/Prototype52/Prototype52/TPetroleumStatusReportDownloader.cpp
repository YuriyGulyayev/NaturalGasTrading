#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TPetroleumStatusReportDownloader.hpp"

#include "./TNewsHubHelpers.cpp"
#include "./TEconomicReportDownloaderWithTcpParallelRequestsBase.cpp"
#include "./TPetroleumStatusReportDownloaderConfiguration.cpp"
#include "../Common/Globalization/TGlobalizationHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {private ConstantStrings26AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TPetroleumStatusReportDownloader::ConstantStrings26AsArray_[ 3U ][ static_cast< unsigned int >( ConstantString26Length_ + 1 ) ] =
      { "HTTP/1.1 200 *******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\n\"Commercial (Excluding SPR)\",\"1.234\",\"1.234\",\"-999.999\"***********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\n\"Total Motor Gasoline\",\"1.234\",\"1.234\",\"-999.998\"**********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\n\"Distillate Fuel Oil\",\"1.234\",\"1.234\",\"-999.997\"*******^",
         "HTTP/1.1 200 *******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\n\"Commercial (Excluding SPR)\",\"567.456\",\"567.456\",\"0\"**************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\n\"Total Motor Gasoline\",\"567.456\",\"567.456\",\"0.001\"*********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\n\"Distillate Fuel Oil\",\"567.456\",\"567.456\",\"-0.001\"*****^",
         "HTTP/1.1 200 *******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\n\"Commercial (Excluding SPR)\",\"9,898.989\",\"9,898.989\",\"999.999\"****************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\n\"Total Motor Gasoline\",\"9,898.989\",\"9,898.989\",\"999.998\"***************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\n\"Distillate Fuel Oil\",\"9,898.989\",\"9,898.989\",\"999.997\"^",
      };

#endif
#if( /* {private ConstantString34AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TPetroleumStatusReportDownloader::ConstantString34AsArray_[]( "HTTP/1.1 200 " );

   inline void TPetroleumStatusReportDownloader::ConstantString34StaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ConstantString34Length_ ) == ( sizeof( ConstantString34AsArray_ ) / sizeof( ConstantString34AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString36AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TPetroleumStatusReportDownloader::ConstantString36AsArray_[]( "\n\"Commercial (Excluding SPR)\",\"" );

   inline void TPetroleumStatusReportDownloader::ConstantString36StaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ConstantString36Length_ ) == ( sizeof( ConstantString36AsArray_ ) / sizeof( ConstantString36AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString37AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TPetroleumStatusReportDownloader::ConstantString37AsArray_[]( "\n\"Total Motor Gasoline\",\"" );

   inline void TPetroleumStatusReportDownloader::ConstantString37StaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ConstantString37Length_ ) == ( sizeof( ConstantString37AsArray_ ) / sizeof( ConstantString37AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString38AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TPetroleumStatusReportDownloader::ConstantString38AsArray_[]( "\n\"Distillate Fuel Oil\",\"" );

   inline void TPetroleumStatusReportDownloader::ConstantString38StaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ConstantString38Length_ ) == ( sizeof( ConstantString38AsArray_ ) / sizeof( ConstantString38AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString44AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TPetroleumStatusReportDownloader::ConstantString44AsArray_[]
      ( "DE|AV|0117|"
        "1415|US EIA Crude Stocks|????????|7|"
        "1417|US EIA Gasoline Stocks|????????|7|"
        "1416|US EIA Distillates Stocks|????????|7|"
      );

   inline void TPetroleumStatusReportDownloader::ConstantString44StaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ConstantString44Length_ ) == ( sizeof( ConstantString44AsArray_ ) / sizeof( ConstantString44AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif

#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TPetroleumStatusReportDownloader::TPetroleumStatusReportDownloader()
      //ResponseContentCurrentLineParsingState_( ??? )
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TPetroleumStatusReportDownloader::TPetroleumStatusReportDownloader
      ( TPetroleumStatusReportDownloaderConfiguration && configuration1
      ) :
      TEconomicReportDownloaderWithTcpParallelRequestsBase< int >( ::std::move( configuration1 ) )
      //ResponseContentCurrentLineParsingState_( ??? )
   {
      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and not inline.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public Initialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPetroleumStatusReportDownloader::Initialize
      ( TPetroleumStatusReportDownloaderConfiguration && configuration1
      )
   {
      TEconomicReportDownloaderWithTcpParallelRequestsBase< int >::Initialize( ::std::move( configuration1 ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPetroleumStatusReportDownloader::DoInitialize
      ( TPetroleumStatusReportDownloaderConfiguration && configuration1
      )
   {
// TODO 2 yg? Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
// TODO 2 yg? Refer to it from consrtructors, destructors, {Initialize}.

      //CommercialCrudeOilStocksQuantityDifferenceMultiplier_ = ::std::move( configuration1.CommercialCrudeOilStocksQuantityDifferenceMultiplier );
      //MotorGasolineStocksQuantityDifferenceMultiplier_ = ::std::move( configuration1.MotorGasolineStocksQuantityDifferenceMultiplier );
      //DistillateFuelOilStocksQuantityDifferenceMultiplier_ = ::std::move( configuration1.DistillateFuelOilStocksQuantityDifferenceMultiplier );

      ResponseContentLinesParsingState_[ 0U ].ResponseContentLineTitle = ConstantString36AsArray_;
      ResponseContentLinesParsingState_[ 0U ].ResponseContentLineTitleEnd = ConstantString36AsArray_ + static_cast< unsigned int >( ConstantString36Length_ );
      ResponseContentLinesParsingState_[ 0U ].ResponseContentLineTitleLength = ConstantString36Length_;
      ResponseContentLinesParsingState_[ 0U ].Value1Multiplier = ::std::move( configuration1.CommercialCrudeOilStocksQuantityDifferenceMultiplier );
      ResponseContentLinesParsingState_[ 1U ].ResponseContentLineTitle = ConstantString37AsArray_;
      ResponseContentLinesParsingState_[ 1U ].ResponseContentLineTitleEnd = ConstantString37AsArray_ + static_cast< unsigned int >( ConstantString37Length_ );
      ResponseContentLinesParsingState_[ 1U ].ResponseContentLineTitleLength = ConstantString37Length_;
      ResponseContentLinesParsingState_[ 1U ].Value1Multiplier = ::std::move( configuration1.MotorGasolineStocksQuantityDifferenceMultiplier );
      ResponseContentLinesParsingState_[ 2U ].ResponseContentLineTitle = ConstantString38AsArray_;
      ResponseContentLinesParsingState_[ 2U ].ResponseContentLineTitleEnd = ConstantString38AsArray_ + static_cast< unsigned int >( ConstantString38Length_ );
      ResponseContentLinesParsingState_[ 2U ].ResponseContentLineTitleLength = ConstantString38Length_;
      ResponseContentLinesParsingState_[ 2U ].Value1Multiplier = ::std::move( configuration1.DistillateFuelOilStocksQuantityDifferenceMultiplier );

   #if( ! defined( NDEBUG ) )
      {
         char const * constantStrings26AsArrayPointer
            ( ConstantStrings26AsArray_[ 0U ] + sizeof( ConstantStrings26AsArray_ ) / sizeof( ConstantStrings26AsArray_[ 0U ][ 0U ] ) );
         do
         {
            constantStrings26AsArrayPointer -= ( ConstantString26Length_ + 1 );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( constantStrings26AsArrayPointer[ ConstantString26Length_ ] == '\x00' );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( constantStrings26AsArrayPointer[ ConstantString26Length_ - 1 ] == '^' );
         }
         while( constantStrings26AsArrayPointer != ConstantStrings26AsArray_[ 0U ] );
      }
   #endif
   }

#endif
#if( /* {protected DoTryRun}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   /*bool*/ void TPetroleumStatusReportDownloader::DoTryRun()
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {Result}.
      //       Update.
      //    {DoTryRun} -- base.
      //       Override, call.
      //    {ResponseContentParsingFactor1_}.
      //       Use.
      //    {ResponseContentParsingFactor2_}.
      //       Use.
      //    {ResponseContentParsingFactor3_}.
      //       Use.
      //    {ResponseContentLinesParsingState_[].ResponseContentLineTitleOffset}.
      //       Update.
      //    {ResponseContentLinesParsingState_[].ResponseContentCurrentOffset}.
      //       Update.
      //    {ResponseContentLinesParsingState_[].Value1}.
      //       Update.
      //    {ResponseContentCurrentLineParsingState_}.
      //       Update.
      //    {NewsHubMessageText_.assign}.
      //       Call.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.

      // We will add 3 values multiplied by their respective multipliers to this.
      // If an error occurs this value will be undefined and we will log a big negative numebr instead.
      Result = 0;

      ResponseContentLinesParsingState_[ 0U ].ResponseContentLineTitleOffset = ::std::numeric_limits< int >::lowest();
      ResponseContentLinesParsingState_[ 0U ].ResponseContentCurrentOffset = ResponseContentParsingFactor1_;
      //ResponseContentLinesParsingState_[ 0U ].Value1 = ::std::numeric_limits< double >::lowest();
      ResponseContentLinesParsingState_[ 0U ].Value1 = ::std::numeric_limits< int >::lowest();
      ResponseContentLinesParsingState_[ 1U ].ResponseContentLineTitleOffset = ::std::numeric_limits< int >::lowest();
      ResponseContentLinesParsingState_[ 1U ].ResponseContentCurrentOffset = ResponseContentParsingFactor2_;
      //ResponseContentLinesParsingState_[ 1U ].Value1 = ::std::numeric_limits< double >::lowest();
      ResponseContentLinesParsingState_[ 1U ].Value1 = ::std::numeric_limits< int >::lowest();
      ResponseContentLinesParsingState_[ 2U ].ResponseContentLineTitleOffset = ::std::numeric_limits< int >::lowest();
      ResponseContentLinesParsingState_[ 2U ].ResponseContentCurrentOffset = ResponseContentParsingFactor3_;
      //ResponseContentLinesParsingState_[ 2U ].Value1 = ::std::numeric_limits< double >::lowest();
      ResponseContentLinesParsingState_[ 2U ].Value1 = ::std::numeric_limits< int >::lowest();

      ResponseContentCurrentLineParsingState_ = ResponseContentLinesParsingState_;
      NewsHubMessageText_.assign( ConstantString44AsArray_, static_cast< unsigned int >( ConstantString44Length_ ) );

      TEconomicReportDownloaderWithTcpParallelRequestsBase< int >::DoTryRun();
   }

#endif

#if( /* {public TryCreateNewsHubMessage}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   ::std::string const * TPetroleumStatusReportDownloader::TryCreateNewsHubMessage()
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {OutcomeCode_}.
      //       Validate.
      //    {TryCreateNewsHubMessage} -- base.
      //       Override.
      //    {ResponseContentLinesParsingState_[].Value1}.
      //       Use.
      //    {& NewsHubMessageText_}.
      //       Return.
      //    {ConstantString44Value1Offset1_}.
      //       Use.
      //    {ConstantString44Value1Offset2_}.
      //       Use.
      //    {ConstantString44Value1Offset3_}.
      //       Use.
      //    {TryInsertValueIntoNewsHubMessageText}.
      //       Call.

      //base->TryCreateNewsHubMessage

      // It's documented that {TryRun} shall succeed before {TryCreateNewsHubMessage} is called.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success );

      if( TryInsertValueIntoNewsHubMessageText( ResponseContentLinesParsingState_[ 0U ].Value1, ConstantString44Value1Offset1_ ) &&
          TryInsertValueIntoNewsHubMessageText( ResponseContentLinesParsingState_[ 1U ].Value1, ConstantString44Value1Offset2_ ) &&
          TryInsertValueIntoNewsHubMessageText( ResponseContentLinesParsingState_[ 2U ].Value1, ConstantString44Value1Offset3_ )
        )
      {
         return ( & NewsHubMessageText_ );
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         return nullptr;
      }
   }

#endif
#if( /* {private TryInsertValueIntoNewsHubMessageText}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   bool TPetroleumStatusReportDownloader::TryInsertValueIntoNewsHubMessageText
      ( int value1,
        int value1Offset
      )
   {
      // This method is not inline as it's called from multiple places.

      // Visible universe.
      //    {NewsHubMessageText_}.
      //       Update.
      //    {ConstantString44Value1Length_}.
      //       Use.

      // We will insert 7 digits and a sign.
      static_assert( ConstantString44Value1Length_ == 8, "" );

      // It's documented that {TryCreateNewsHubMessage} may be called 0 or 1 time after a successful {TryRun} call
      // and before a {LogActivityReportIfPossible} call.
      // This validation can't actually detect if {LogActivityReportIfPossible} was called
      // as that method's "if possible" condition uses base class {private} fields, and that's OK.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset + 0 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset + 1 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset + 2 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset + 3 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset + 4 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset + 5 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset + 6 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset + 7 ) ) == '?' );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset - 1 ) ) == '|' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset + ConstantString44Value1Length_ ) ) == '|' );

      // If report value could be bigger {ConstantString44Value1Length_} would need to be bigger.
      // yg? {TryParseResponse} doesn't currently ensure that this condition is {true}.
      if( value1 >= ( - 9999999 ) && value1 <= 9999999 )

      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         {
            // This message is not quite informative and that's OK.
            static char const constantString1AsArray[]
               ( "{Prototype52::TPetroleumStatusReportDownloader::TryInsertValueIntoNewsHubMessageText} failed" );

            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         return false;
      }

      {
//TODO Do we need #if( defined( _M_IX86 ) || defined( _M_X64 ) ) . . . search for "unaligned".
         static_assert( POCO_ARCH_LITTLE_ENDIAN == 1, "" );
         ::Poco::UInt64 value1Chars;
         static_assert( sizeof( value1Chars ) == static_cast< unsigned int >( ConstantString44Value1Length_ ), "" );

         if( value1 < 0 )
         {
            value1 = ( - value1 );
            value1Chars =
               ( static_cast< ::Poco::UInt64 >( static_cast< unsigned int >( '0000' ) ) << ( 4U * 8U ) ) | static_cast< unsigned int >( '000-' );
         }
         else
         {
            value1Chars =
               ( static_cast< ::Poco::UInt64 >( static_cast< unsigned int >( '0000' ) ) << ( 4U * 8U ) ) | static_cast< unsigned int >( '000+' );
         }
         
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( value1 >= 0 );

         value1Chars += static_cast< ::Poco::UInt64 >( static_cast< unsigned int >( value1 ) % 10U ) << ( 7U * 8U );
         value1 = static_cast< int >( static_cast< unsigned int >( value1 ) / 10U );
         value1Chars += static_cast< ::Poco::UInt64 >( static_cast< unsigned int >( value1 ) % 10U ) << ( 6U * 8U );
         value1 = static_cast< int >( static_cast< unsigned int >( value1 ) / 10U );
         value1Chars += static_cast< ::Poco::UInt64 >( static_cast< unsigned int >( value1 ) % 10U ) << ( 5U * 8U );
         value1 = static_cast< int >( static_cast< unsigned int >( value1 ) / 10U );
         value1Chars += static_cast< ::Poco::UInt64 >( static_cast< unsigned int >( value1 ) % 10U ) << ( 4U * 8U );
         value1 = static_cast< int >( static_cast< unsigned int >( value1 ) / 10U );
         value1Chars += ( static_cast< unsigned int >( value1 ) % 10U ) << ( 3U * 8U );
         value1 = static_cast< int >( static_cast< unsigned int >( value1 ) / 10U );
         value1Chars += ( static_cast< unsigned int >( value1 ) % 10U ) << ( 2U * 8U );
         value1 = static_cast< int >( static_cast< unsigned int >( value1 ) / 10U );
         value1Chars += static_cast< unsigned int >( value1 ) << ( 1U * 8U );
         
         reinterpret_cast< ::Poco::UInt64 & >( NewsHubMessageText_.at( static_cast< unsigned int >( value1Offset ) ) ) = value1Chars;
      }

      return true;
   }

#endif

#if( /* {protected ConfigureSocket}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPetroleumStatusReportDownloader::ConfigureSocket
      ( ::Common::Networking::TStreamSocketWithDataBuffer & socket1
      ) const
   {
      // This method is virtual and not inline.
      // I don't want to write down visible universe here.

      // Changing these parameters before calling the base just in case the base needs to use them.
      socket1.DataBufferCapacityMaxLimit() = static_cast< unsigned int >( SocketDataBufferCapacityMaxLimit_ );
      socket1.DataBuffer().resize( static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );

      TEconomicReportDownloaderWithTcpParallelRequestsBase< int >::ConfigureSocket( socket1 );
   }

#endif
#if( /* {protected GetResponseContentForWarmUp}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   ::Common::DataStructures::TDataBuffer TPetroleumStatusReportDownloader::GetResponseContentForWarmUp() const
   {
      // This method is virtual and not inline.
      //
      // TODO 3 yg? Consider porting this implementation to {TNaturalGasStorageReportDownloader::GetResponseContentForWarmUp}.
      // TODO 3 yg? See a related comment there.

      // Visible universe.
      //    {WarmUpCounter_}.
      //       Use.
      //    {GetResponseContentForWarmUp} -- base.
      //       Implement.
      //    {SocketDataBufferInitialCapacity_}.
      //       Use.
      //    {ConstantStrings26AsArray_}.
      //       Use.
      //    {ConstantString26Length_}.
      //       Use.

      //base->GetResponseContentForWarmUp

      // To simplify the parsing code, first of all the validations, we make this data buffer look like a real response one.
      // TODO 3 yg? As mentioned in a {::Common::DataStructures::TDataBuffer} comment,
      // TODO 3 yg? we need another constructor in that class to do all of these.
      {
         //::Common::DataStructures::TDataBuffer responseContent( static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );
         ::Common::DataStructures::TDataBuffer responseContent;
         responseContent.reserve( static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );

         {
            // At this point, {WarmUpCounter_} has already been incremented.
            // So we warm-up {ConstantStrings26AsArray_} items in a different order.
            // {WarmUpCounter_} is also incremented in test mode when {TryMakeWarmUpStep} is not running,
            // so in that case we will not warm-up the respective {ConstantStrings26AsArray_} item,
            // although we will still have a chance to warm it up later provided someone keeps calling {TryMakeWarmUpStep}.
            // Not assuming this condition as {WarmUpCounter_} can potentially overflow.
            assert( WarmUpCounter_ > 0 );

            char const * constantString26AsArray
               ( ConstantStrings26AsArray_
                    [ static_cast< unsigned int >( WarmUpCounter_ ) %
                      static_cast< unsigned int >( sizeof( ConstantStrings26AsArray_ ) / sizeof( ConstantStrings26AsArray_[ 0U ] ) )
                    ]
               );

            // This validation ensures that {responseContent.capacity()} will not increase.
            // This probably must be { < } as otherwise checked iterators would probably complain
            // but I don't need to worry about it until it actually happens.
            // Regardless, in the release build the behavior will be correct even if these are equal.
            static_assert( ConstantString26Length_ <= SocketDataBufferInitialCapacity_, "" );

            responseContent.Assign( constantString26AsArray, static_cast< unsigned int >( ConstantString26Length_ ) );
         }

         responseContent.resize( static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );

         // It's probably better to not use {::std::move} here.
         return responseContent;
      }
   }

#endif
#if( /* {protected TryParseResponse}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   unsigned int TPetroleumStatusReportDownloader::TryParseResponse
      ( ::Common::DataStructures::TDataBuffer const & responseContent
      )
   {
      // This method is virtual and not inline.
      // If we already parsed a part of a response we will resume, even if this is a different response.
      // We will be OK if HTTP headers in different responses have slightly different lengths.

      // Visible universe.
      //    //{Result}.
      //    //   Update.
      //    {EconomicReportReceptionTimeStampMilliseconds_}.
      //       Update.
      //    {OutcomeCode_}.
      //       Update.
      //    {TryParseResponse} -- base.
      //       Implement.
      //    {SocketDataBufferInitialCapacity_}.
      //       Validate.
      //    {ResponseContentLinesParsingState_}.
      //       Use.
      //    {ResponseContentCurrentLineParsingState_}.
      //       Use, update.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.
      //    {TryParseResponseContentLine}.
      //       Call.

      //base->TryParseResponse

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( responseContent.length() >= static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );

      // We can be called only after some text arrived.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContent.DataLength > 0U );

      // We probably don't need to validate anything else at this point.
      // {TryParseResponseContentLine} will make some validations.

      // Data buffer capacity is much bigger than this, so it's safe to compare this without prior checking if we received enough data.
      // Assuming it's impossible that the bufer is populated with some data but due to a subsequent error data length isn't updated.
      // And even otherwise we would probably be OK.
      // yg? Assuming a string fills itself with zeros when resized. It would be nice to validate that it's really the case.
      // TODO 3 yg? Really, validate this.
      // yg? If it's not the case we would have to do it manually, maybe set only 1 char to '\x00'.
      // yg? Check if this is the case on Linux.
      if( ::Common::DataStructures::TDataBuffer::traits_type::compare
              ( responseContent.data(), ConstantString34AsArray_, static_cast< unsigned int >( ConstantString34Length_ ) ) !=
          0
        )

      {
         // This condition is probably always {false} but I want to keep this logic.
         // This can't overflow, as we validated.
         if( static_cast< unsigned int >( responseContent.DataLength ) < static_cast< unsigned int >( ConstantString34Length_ ) )

         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            return 2U;
         }
         else
         {
            // We are probably parsing a "New Release Pending" page.
            return 4U;
         }
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

   //#if( defined( _MSC_VER ) && ( ! defined( NDEBUG ) ) )
   //   // yg? This hack is to silence checked iterators.
   //   // yg? This invalidates some validations above but we probably execute them only once under normal conditions.
   //   // In any case in the release build everything is OK.
   //   // This hack is not reflected in the visible universe.
   //   {
   //      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContent.DataLength <= responseContent.length() );
   //      if( responseContent.DataLength >= responseContent.length() )
   //      {
   //         // yg? Doing {const_cast}.
   //         const_cast< ::Common::DataStructures::TDataBuffer & >( responseContent ).resize( responseContent.length() + 1U );
   //      }
   //      else
   //      {
   //         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //      }
   //   }
   //#endif

      do
      {
         // {TryParseResponseContentLine} will validate that {ResponseContentCurrentLineParsingState_} is within array bounds,
         // so we don't need to validate that here.
         // We don't need to validate {tryParseResponseContentLineOutcomeCode}.
         unsigned int tryParseResponseContentLineOutcomeCode( TryParseResponseContentLine( responseContent ) );

         if( tryParseResponseContentLineOutcomeCode != 1U )
         {
            return tryParseResponseContentLineOutcomeCode;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
      }
      while( ( ++ ResponseContentCurrentLineParsingState_ ) !=
                 ResponseContentLinesParsingState_ + sizeof( ResponseContentLinesParsingState_ ) / sizeof( ResponseContentLinesParsingState_[ 0U ] )
               );

      // The compiler views this as a memory barrier and therefore we cross it after potentially optimizable statements.
      EconomicReportReceptionTimeStampMilliseconds_ = ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds();

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
      OutcomeCode_ = TEconomicReportReceiverOutcomeCode_Success;
      return 1U;
   }

#endif
#if( /* {private TryParseResponseContentLine}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TPetroleumStatusReportDownloader::TryParseResponseContentLine
      ( ::Common::DataStructures::TDataBuffer const & responseContent
      )
   {
      // Visible universe.
      //    {::_atof_l}.
      //       Call.
      //    {Result}.
      //       Update.
      //    {OutcomeCode_}.
      //       Update.
      //    {SocketDataBufferInitialCapacity_}.
      //       Validate.
      //    {SocketDataBufferCapacityMaxLimit_}.
      //       Validate.
      //    {ResponseContentParsingFactor6_}.
      //       Use.
      //    {ResponseContentParsingFactor8_}.
      //       Use.
      //    {ResponseContentLinesParsingState_}.
      //       Validate.
      //    {ResponseContentCurrentLineParsingState_}.
      //       Validate.
      //    {ResponseContentCurrentLineParsingState_->ResponseContentLineTitle}.
      //       Use.
      //    {* ResponseContentCurrentLineParsingState_->ResponseContentLineTitle}.
      //       Use.
      //    {ResponseContentCurrentLineParsingState_->ResponseContentLineTitleEnd}.
      //       Use.
      //    {ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength}.
      //       Use.
      //    {ResponseContentCurrentLineParsingState_->ResponseContentLineTitleOffset}.
      //       Update.
      //    {ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset}.
      //       Use, update.
      //    {ResponseContentCurrentLineParsingState_->Value1Multiplier}.
      //       Use.
      //    {ResponseContentCurrentLineParsingState_->Value1}.
      //       Update.
      //    {ConstantString26Length_}.
      //       Validate.

      // {TryParseResponse} validated this but let's do it again.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( responseContent.length() >= static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );

      // We can exceed this limit by a little because we can append text to the data buffer
      // but we are not supposed to parse the text we appended.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( responseContent.length() <= static_cast< unsigned int >( SocketDataBufferCapacityMaxLimit_ ) );

      // If this validation fails I would need to increase {SocketDataBufferInitialCapacity_}.
      assert( responseContent.length() == static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );

      // {TryParseResponse} validated this but let's do it again.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContent.DataLength > 0U );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContent.DataLength <= responseContent.length() );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ResponseContentCurrentLineParsingState_ - ResponseContentLinesParsingState_ >= 0 );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ( ( ResponseContentLinesParsingState_ + sizeof( ResponseContentLinesParsingState_ ) / sizeof( ResponseContentLinesParsingState_[ 0U ] ) ) -
              ResponseContentCurrentLineParsingState_
           ) >
           0
         );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ResponseContentCurrentLineParsingState_->ResponseContentLineTitle + ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength ==
           ResponseContentCurrentLineParsingState_->ResponseContentLineTitleEnd
         );

      // Not sanity-validating this. It's probably OK. We do make some other validations involving this field.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength > 0 );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset >= 0 );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset + ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength >
           0
         );

      // This is probably less by a margin close to {ResponseContentParsingFactor6_} but keeping it simple.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset + ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength <
           SocketDataBufferCapacityMaxLimit_
         );

      // The { < } comparison would also make it possible to fit the line title. On the other hand, one might want to demand a bigger
      // margin. But keeping it simple. Any additional logic would probably hurt performance.
      // Another argument to keep it this way is because we have a higher chance to populate
      // {ResponseContentCurrentLineParsingState_->ResponseContentLineTitleOffset}.
      // An argument to not keep it this way would be a higher chance to advance
      // {ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset} but that's probably not the case.
      if( static_cast< unsigned int >( responseContent.DataLength ) <=
          static_cast< unsigned int >( ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset + ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength )
        )
      {
         return 2U;
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      ::Common::DataStructures::TDataBuffer::const_iterator responseContentBeginIterator
         ( responseContent.cbegin() + ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset );

      // yg? This should be calculated only once per {TryParseResponse} call but this will probably be calculated
      // yg? once per {TryParseResponseContentLine} call because the compiler views a call to {::_atof_l}
      // yg? and possibly some other library functions as a memory barrier.
      ::Common::DataStructures::TDataBuffer::const_iterator responseContentEndIterator
         ( responseContent.cbegin() +
           static_cast< ::Common::DataStructures::TDataBuffer::difference_type >( responseContent.DataLength )
         );

      // These validations act as optimization hints for {::std::search}.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength > 0 );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( responseContentEndIterator - responseContentBeginIterator >
           ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength
         );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ResponseContentCurrentLineParsingState_->ResponseContentLineTitleEnd - ResponseContentCurrentLineParsingState_->ResponseContentLineTitle ==
           ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength
         );

      ::Common::DataStructures::TDataBuffer::const_iterator responseContentIterator1
         ( ::std::search
              ( responseContentBeginIterator,
                responseContentEndIterator,
                ResponseContentCurrentLineParsingState_->ResponseContentLineTitle,
                ResponseContentCurrentLineParsingState_->ResponseContentLineTitleEnd
              )
         );

      if( responseContentIterator1 == responseContentEndIterator )
      {
         // This can reduce {ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset}
         // and even make it less than its initial value.
         // We could prevent that but keeping it simple.
         // yg? Bug: actually this logic probably can be cracked by a series of response texts tweaked to make
         // yg? {ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset} negative. I am OK with that.
         // Assuming this will not overflow. It probably can't.
         ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset =
            static_cast< int >( responseContent.DataLength ) -
            ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength +
            1 -
            ResponseContentParsingFactor6_;

         // yg? This is probably much greater but let's account for the bug mentioned above.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset >= 0 );

         return 2U;
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      // It's possible that we already assigned a value to this field, so we don't validate this field.
      // It's possible that we will assign a value to this field multiple times if we parse multiple responses
      // and due to potentially different HTTP header lengths the values can be a bit different -- no problem.
      // Assuming this will not overflow. It probably can't.
      ResponseContentCurrentLineParsingState_->ResponseContentLineTitleOffset =
         static_cast< int >( responseContentIterator1 - responseContent.cbegin() );

      // yg? This is probably much greater but let's account for the bug described near an assignmet to
      // yg? {ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset} above.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ResponseContentCurrentLineParsingState_->ResponseContentLineTitleOffset >= 0 );

      // This points to the beginning of data in a CSV field. That's after the opening '"'.
      char const * responseContentPointer3
         ( & responseContentIterator1[ ResponseContentCurrentLineParsingState_->ResponseContentLineTitleLength ] );

      // This points to the closing '"' in a CSV field.
      char const * responseContentPointer4;

      for( int counter1( 3 ) ; ; )
      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContentPointer3[ - 1 ] == '"' );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContentPointer3[ - 2 ] == ',' );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContentPointer3[ - 3 ] == '"' );

         // On a next loop this condition can be tighter. We validate it at the end of the loop block.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & ( * responseContentEndIterator ) ) - responseContentPointer3 >= 0 );

         // Searching for the closing '"' of a CSV field.
         responseContentPointer4 =
            ::Common::DataStructures::TDataBuffer::traits_type::find
               ( responseContentPointer3,
                 static_cast< ::Common::DataStructures::TDataBuffer::size_type >
                    ( ( & ( * responseContentEndIterator ) ) - responseContentPointer3 ),
                 '"'
               );

         if( responseContentPointer4 == nullptr )
         {
            goto label1;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( * responseContentPointer4 ) == '"' );

         // yg? The CSV field should not be empty but release build will tolerate an empty one unless we need to parse it.
         assert( responseContentPointer4[ - 1 ] != '"' );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( counter1 <= 3 );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( counter1 >= 1 );
         if( ( -- counter1 ) > 0 )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }


// TODO 3 yg? Remove this?
         //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & ( * responseContentEndIterator ) ) - responseContentPointer4 > 0 );
         //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & ( * responseContentEndIterator ) ) - ( responseContentPointer4 + 1 ) >= 0 );
         //
         //// yg? This should find the next char but we will tolerate any chars inbetween, including digits or '\n'.
         //// There is no appropriate {::Common::DataStructures::TDataBuffer} method for this.
         //responseContentPointer3 =
         //   ::Common::DataStructures::TDataBuffer::traits_type::find
         //      ( responseContentPointer4 + 1,
         //        static_cast< ::Common::DataStructures::TDataBuffer::size_type >( ( & ( * responseContentEndIterator ) ) - ( responseContentPointer4 + 1 ) ),
         //        ','
         //      );
         //
         //if( responseContentPointer3 != nullptr )
         //{
         //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         //}
         //else
         //{
         //   goto label1;
         //}
         //
         //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & ( * responseContentEndIterator ) ) - responseContentPointer3 > 0 );
         //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & ( * responseContentEndIterator ) ) - ( responseContentPointer3 + 1 ) >= 0 );
         //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( * responseContentPointer3 ) == ',' );
         //
         //// yg? As mentioned above, we hope that we found the next char.
         //assert( responseContentPointer3[ - 1 ] == '"' );
         //
         //// yg? This should find the next char but we will tolerate any chars inbetween, including digits or '\n'.
         //// There is no appropriate {::Common::DataStructures::TDataBuffer} method for this.
         //responseContentPointer3 =
         //   ::Common::DataStructures::TDataBuffer::traits_type::find
         //      ( responseContentPointer3 + 1,
         //        static_cast< ::Common::DataStructures::TDataBuffer::size_type >( ( & ( * responseContentEndIterator ) ) - ( responseContentPointer3 + 1 ) ),
         //        '"'
         //      );
         //
         //if( responseContentPointer3 != nullptr )
         //{
         //   ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         //}
         //else
         //{
         //label1:
         //   // We assigned to this above.
         //   // This really must be not just non-negative but at least {ResponseContentParsingFactor6_}.
         //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         //      ( ResponseContentCurrentLineParsingState_->ResponseContentLineTitleOffset >= 0 );
         //
         //   // yg? See related comment above where we assign to this field.
         //   ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset =
         //      ResponseContentCurrentLineParsingState_->ResponseContentLineTitleOffset - ResponseContentParsingFactor6_;
         //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         //      ( ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset >= 0 );
         //
         //   return 2U;
         //}
         //
         //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & ( * responseContentEndIterator ) ) - responseContentPointer3 > 0 );
         //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & ( * responseContentEndIterator ) ) - ( responseContentPointer3 + 1 ) >= 0 );
         //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( * responseContentPointer3 ) == '"' );
         //
         //// yg? As mentioned above, we hope that we found the next char.
         //assert( responseContentPointer3[ - 1 ] == ',' );
         //assert( responseContentPointer3[ - 2 ] == '"' );
         //
         //++ responseContentPointer3;


         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & ( * responseContentEndIterator ) ) - responseContentPointer4 > 0 );

         // We need at least 4 chars after {responseContentPointer4}. Those can be ",\"7\"".
         if( ( & ( * responseContentEndIterator ) ) - responseContentPointer4 <= 4 )

         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();

         label1:
            // We assigned to this above.
            // This really must be not just non-negative but at least {ResponseContentParsingFactor6_}.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( ResponseContentCurrentLineParsingState_->ResponseContentLineTitleOffset >= 0 );

            // yg? See a related comment above where we assign to this field.
            ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset =
               ResponseContentCurrentLineParsingState_->ResponseContentLineTitleOffset - ResponseContentParsingFactor6_;
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( ResponseContentCurrentLineParsingState_->ResponseContentCurrentOffset >= 0 );

            return 2U;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

//TODO Do we need #if( defined( _M_IX86 ) || defined( _M_X64 ) ) . . . search for "unaligned".
         static_assert( POCO_ARCH_LITTLE_ENDIAN == 1, "" );

         // If this condition is {false} we will declare the text malformed.
         if( reinterpret_cast< short const & >( responseContentPointer4[ 1 ] ) == static_cast< short >( '",' ) )

         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            goto label2;
         }

         responseContentPointer3 = responseContentPointer4 + 3;

         // This is valid based on the 4 chars check above.
         // This condition is tighter than a similar one at the beginning of the loop block.
         // It can act as an optimization hint.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( & ( * responseContentEndIterator ) ) - responseContentPointer3 > 1 );
      }

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContentPointer4 - responseContentPointer3 >= 0 );

      // Checking if the CSV field we are to parse is not empty. Otherwise we will declare the text malformed.
      // yg? This is not a perfect protection. We can still accept any garbage chars, including '\n'.
      if( responseContentPointer4 - responseContentPointer3 > 0 )

      {
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContentPointer4[ - 1 ] != '"' );
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContentPointer4[ - 1 ] == '"' );

      label2:
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
         OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError;
         return 8U;
      }

      {
         // yg? This will return 0.0 on error and we will do nothing about it.
         // yg? A thousand separator or in any way malformed text can cause incorrect behavior.
         // yg? Not ensuring that the number parsing will end at the found above '"'. Although it's OK if some blanks follow the number.
         // TODO 3 yg? Consider implementing this parsing more efficiently and/or reliably.
         // TODO 3 yg? POCO uses a floating point parsing library or something like that. Can we use it?
         // TODO 3 yg? Can we use {::_atoflt_l}? Then round it as {< float, int >}.
         double double1( ::_atof_l( responseContentPointer3, ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale ) );

         // This is a cheap rounding but not necessarily the most correct.
         // It might be safer to round midpoint towards 0.0, which might result in a higher chance
         // of the report being treated as untradable. Maybe this comment is bullshit.
         // {ResponseContentParsingFactor8_} actually ensures that there will be no precision loss.
         int value1( ::Common::Math::TMathHelpers::RoundValueToIntegerMidpointAwayFromZero< double, int >
                              ( double1 * static_cast< double >( ResponseContentParsingFactor8_ ) )
                         );
         
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( ResponseContentCurrentLineParsingState_->Value1 == ::std::numeric_limits< int >::lowest() );
         ResponseContentCurrentLineParsingState_->Value1 = value1;

         // As mentioned in the config file, these multipliers must be small enough to eliminate the possibility of integer overflow.
         Result += value1 * ResponseContentCurrentLineParsingState_->Value1Multiplier;
      }

      return 1U;
   }

#endif

#if( /* {protected LogActivityReportHeader}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TPetroleumStatusReportDownloader::LogActivityReportHeader() const
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {Result}.
      //       Use.
      //    {OutcomeCode_}.
      //       Use.
      //    {SafeGetEconomicReportReceptionDateTimeStampOffsetMilliseconds()}.
      //       Use.
      //    {LogActivityReportHeader} -- base.
      //       Implement.
      //    {ResponseContentParsingFactor8_}.
      //       Use.
      //    {ResponseContentLinesParsingState_[].ResponseContentLineTitleOffset}.
      //       Use.
      //    {ResponseContentLinesParsingState_[].Value1}.
      //       Use.

      //base->LogActivityReportHeader

      int const tempString1BufferLength( 256 );
      ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
      static char const formatConstantString1AsArray[]
         ( "petroleum status report downloading activity report; %+i; %u; %+i; %+.*g; %+.*g; %+.*g; %i; %i; %i" );

      // We will format this as an unsigned.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ >= 0 );

      int tempString1Length
         ( ::_snprintf_l
              ( ( & tempString1.front() ),
                static_cast< unsigned int >( tempString1BufferLength ),
                formatConstantString1AsArray,
                ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                SafeGetEconomicReportReceptionDateTimeStampOffsetMilliseconds(),
                static_cast< unsigned int >( OutcomeCode_ ),
                
                // We validate {OutcomeCode_} below.
                ( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success ) ? Result : ::std::numeric_limits< int >::lowest(),

                10,
                //ResponseContentLinesParsingState_[ 0U ].Value1,

                // Since we rounded this, this is not guaranteed to be equal the value in the report.
                static_cast< double >( ResponseContentLinesParsingState_[ 0U ].Value1 ) * ( 1.0 / static_cast< double >( ResponseContentParsingFactor8_ ) ),

                10,
                //ResponseContentLinesParsingState_[ 1U ].Value1,

                // Since we rounded this, this is not guaranteed to be equal the value in the report.
                static_cast< double >( ResponseContentLinesParsingState_[ 1U ].Value1 ) * ( 1.0 / static_cast< double >( ResponseContentParsingFactor8_ ) ),

                10,
                //ResponseContentLinesParsingState_[ 2U ].Value1,

                // Since we rounded this, this is not guaranteed to be equal the value in the report.
                static_cast< double >( ResponseContentLinesParsingState_[ 2U ].Value1 ) * ( 1.0 / static_cast< double >( ResponseContentParsingFactor8_ ) ),

                // These can be a big negative number, so we can't log them as an unsigned. But we anyway don't prepend a '+'.
                ResponseContentLinesParsingState_[ 0U ].ResponseContentLineTitleOffset,
                ResponseContentLinesParsingState_[ 1U ].ResponseContentLineTitleOffset,
                ResponseContentLinesParsingState_[ 2U ].ResponseContentLineTitleOffset
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
      
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success ||
           OutcomeCode_ == TEconomicReportReceiverOutcomeCode_OtherError
         );
      if( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success )
      {
         logger1.information( tempString1 );
      }
      else
      {
         logger1.warning( tempString1 );
      }
   }

#endif
}
