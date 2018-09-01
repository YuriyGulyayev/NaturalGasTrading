#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TNaturalGasStorageReportDownloader.hpp"

#include "./TNewsHubHelpers.cpp"
#include "./TEconomicReportDownloaderWithTcpParallelRequestsBase.cpp"
#include "./TNaturalGasStorageReportDownloaderConfiguration.cpp"
#include "../Common/Globalization/TGlobalizationHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {private ConstantStrings26AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TNaturalGasStorageReportDownloader::ConstantStrings26AsArray_[ 3U ][ static_cast< unsigned int >( ConstantString26Length_ + 1 ) ] =
      { "HTTP/1.1 200 ************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\nNet Change: -999 ^",
         "HTTP/1.1 200 ************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\nNet Change: 0 ***^",
         "HTTP/1.1 200 ************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************\nNet Change: 999 *^",
      };

#endif
#if( /* {private ConstantString34AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TNaturalGasStorageReportDownloader::ConstantString34AsArray_[]( "HTTP/1.1 200 " );

   inline void TNaturalGasStorageReportDownloader::ConstantString34StaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ConstantString34Length_ ) == ( sizeof( ConstantString34AsArray_ ) / sizeof( ConstantString34AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString37AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TNaturalGasStorageReportDownloader::ConstantString37AsArray_[]( "\nNet Change: " );

   inline void TNaturalGasStorageReportDownloader::ConstantString37StaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ConstantString37Length_ ) == ( sizeof( ConstantString37AsArray_ ) / sizeof( ConstantString37AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantString44AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TNaturalGasStorageReportDownloader::ConstantString44AsArray_[]
      ( "DE|AV|0038|1418|US EIA Natural Gas Stocks|????|7|" );

   inline void TNaturalGasStorageReportDownloader::ConstantString44StaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ConstantString44Length_ ) == ( sizeof( ConstantString44AsArray_ ) / sizeof( ConstantString44AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif

#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TNaturalGasStorageReportDownloader::TNaturalGasStorageReportDownloader()
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TNaturalGasStorageReportDownloader::TNaturalGasStorageReportDownloader
      ( TNaturalGasStorageReportDownloaderConfiguration && configuration1
      ) :
      TEconomicReportDownloaderWithTcpParallelRequestsBase< int >( ::std::move( configuration1 ) )
   {
      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and not inline.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNaturalGasStorageReportDownloader::Initialize
      ( TNaturalGasStorageReportDownloaderConfiguration && configuration1
      )
   {
      TEconomicReportDownloaderWithTcpParallelRequestsBase< int >::Initialize( ::std::move( configuration1 ) );

      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNaturalGasStorageReportDownloader::DoInitialize
      ( //TNaturalGasStorageReportDownloaderConfiguration && configuration1
      )
   {
// TODO 2 yg? Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
// TODO 2 yg? Refer to it from consrtructors, destructors, {Initialize}.

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

   /*bool*/ void TNaturalGasStorageReportDownloader::DoTryRun()
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {Result}.
      //       Update.
      //    {DoTryRun} -- base.
      //       Override, call.
      //    {ResponseContentActualOffset37_}.
      //       Update.
      //    {NewsHubMessageText_.assign}.
      //       Call.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.

      Result = ::std::numeric_limits< int >::lowest();
      ResponseContentActualOffset37_ = ::std::numeric_limits< int >::lowest();
      NewsHubMessageText_.assign( ConstantString44AsArray_, static_cast< unsigned int >( ConstantString44Length_ ) );

      TEconomicReportDownloaderWithTcpParallelRequestsBase< int >::DoTryRun();
   }

#endif

#if( /* {public TryCreateNewsHubMessage}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   ::std::string const * TNaturalGasStorageReportDownloader::TryCreateNewsHubMessage()
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {Result}.
      //       Use.
      //    {OutcomeCode_}.
      //       Validate.
      //    {TryCreateNewsHubMessage} -- base.
      //       Override.
      //    {NewsHubMessageText_}.
      //       Update.
      //    {& NewsHubMessageText_}.
      //       Return.
      //    {ConstantString44Value1Offset_}.
      //       Use.
      //    {ConstantString44Value1Length_}.
      //       Use.

      //base->TryCreateNewsHubMessage

      // It's documented that {TryRun} shall succeed before {TryCreateNewsHubMessage} is called.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success );

      // We will insert 3 digits and a sign.
      static_assert( ConstantString44Value1Length_ == 4, "" );

      // It's documented that {TryCreateNewsHubMessage} may be called 0 or 1 time after a successful {TryRun} call
      // and before a {LogActivityReportIfPossible} call.
      // This validation can't actually detect if {LogActivityReportIfPossible} was called
      // as that method's "if possible" condition uses base class {private} fields, and that's OK.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( ConstantString44Value1Offset_ + 0 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( ConstantString44Value1Offset_ + 1 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( ConstantString44Value1Offset_ + 2 ) ) == '?' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( ConstantString44Value1Offset_ + 3 ) ) == '?' );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( ConstantString44Value1Offset_ - 1 ) ) == '|' );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( NewsHubMessageText_.at( static_cast< unsigned int >( ConstantString44Value1Offset_ + ConstantString44Value1Length_ ) ) == '|' );

      // Report value can be from -999 to 999. Otherwise report parsing would fail.
      // If report value could be bigger {ConstantString44Value1Length_} would need to be bigger.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Result >= ( - 999 ) );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Result <= 999 );

      {
         int value1( Result );
//TODO Do we need #if( defined( _M_IX86 ) || defined( _M_X64 ) ) . . . search for "unaligned".
         static_assert( POCO_ARCH_LITTLE_ENDIAN == 1, "" );
         unsigned int value1Chars;
         static_assert( sizeof( value1Chars ) == static_cast< unsigned int >( ConstantString44Value1Length_ ), "" );

         if( value1 < 0 )
         {
            //NewsHubMessageText_>>>at>>>[ static_cast< unsigned int >( ConstantString44Value1Offset_ + 0 ) ] = '-';
            value1 = ( - value1 );
            value1Chars = static_cast< unsigned int >( '000-' );
         }
         else
         {
            value1Chars = static_cast< unsigned int >( '000+' );
         }

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( value1 >= 0 );

         //NewsHubMessageText_>>>at>>>[ static_cast< unsigned int >( ConstantString44Value1Offset_ + 3 ) ] =
         //   static_cast< char >( int1 % 10 + static_cast< int >( static_cast< unsigned char >( '0' ) ) );
         //int1 /= 10;
         //NewsHubMessageText_>>>at>>>[ static_cast< unsigned int >( ConstantString44Value1Offset_ + 2 ) ] =
         //   static_cast< char >( int1 % 10 + static_cast< int >( static_cast< unsigned char >( '0' ) ) );
         //int1 /= 10;
         //NewsHubMessageText_>>>at>>>[ static_cast< unsigned int >( ConstantString44Value1Offset_ + 1 ) ] =
         //   static_cast< char >( int1 + static_cast< int >( static_cast< unsigned char >( '0' ) ) );

         value1Chars += ( static_cast< unsigned int >( value1 ) % 10U ) << ( 3U * 8U );
         value1 = static_cast< int >( static_cast< unsigned int >( value1 ) / 10U );
         value1Chars += ( static_cast< unsigned int >( value1 ) % 10U ) << ( 2U * 8U );
         value1 = static_cast< int >( static_cast< unsigned int >( value1 ) / 10U );
         value1Chars += static_cast< unsigned int >( value1 ) << ( 1U * 8U );

         reinterpret_cast< unsigned int & >( NewsHubMessageText_.at( static_cast< unsigned int >( ConstantString44Value1Offset_ ) ) ) =
            value1Chars;
      }

      return ( & NewsHubMessageText_ );
   }

#endif

#if( /* {protected ConfigureSocket}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TNaturalGasStorageReportDownloader::ConfigureSocket
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

   ::Common::DataStructures::TDataBuffer TNaturalGasStorageReportDownloader::GetResponseContentForWarmUp() const
   {
      // This method is virtual and not inline.
      //
      // TODO 3 yg? {TPetroleumStatusReportDownloader::GetResponseContentForWarmUp} implementation is better.
      // TODO 3 yg? Consider porting it to here but I would have to refactor some code, mostly validations,
      // TODO 3 yg? and I'd probably be able to make {TryMakeWarmUpStepIsRunning_} {private}.

      // Visible universe.
      //    {WarmUpCounter_}.
      //       Use.
      //    {GetResponseContentForWarmUp} -- base.
      //       Implement.
      //    {ConstantStrings26AsArray_}.
      //       Use.
      //    {ConstantString26Length_}.
      //       Use.

      //base->GetResponseContentForWarmUp

      // See a related comment in {TPetroleumStatusReportDownloader::GetResponseContentForWarmUp}.
      assert( WarmUpCounter_ > 0 );

      char const * constantString26AsArray
         ( ConstantStrings26AsArray_
              [ static_cast< unsigned int >( WarmUpCounter_ ) %
                static_cast< unsigned int >( sizeof( ConstantStrings26AsArray_ ) / sizeof( ConstantStrings26AsArray_[ 0U ] ) )
              ]
         );

      // Unnamed objects -- move semantics.
      return ::Common::DataStructures::TDataBuffer( constantString26AsArray, static_cast< unsigned int >( ConstantString26Length_ ) );
   }

#endif
#if( /* {protected TryParseResponse}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   unsigned int TNaturalGasStorageReportDownloader::TryParseResponse
      ( ::Common::DataStructures::TDataBuffer const & responseContent
      )
   {
      // This method is virtual and not inline.
      //
      // This implementation is simple.
      // Only the following number format can be parsed:
      // "\\-?\\d{1,3}[\x00- ]".
      // Thousand separator parsing is not supported.
      // So the result contains at most 3 digits, which {TryCreateNewsHubMessage} assumes.
      //
      // yg? Magic numbers hardcoded.

      // Visible universe.
      //    {Result}.
      //       Update.
      //    {EconomicReportReceptionTimeStampMilliseconds_}.
      //       Update.
      //    {OutcomeCode_}.
      //       Update.
      //    {TryMakeWarmUpStepIsRunning_}.
      //       Validate.
      //    {TryParseResponse} -- base.
      //       Implement.
      //    {SocketDataBufferInitialCapacity_}.
      //       Validate.
      //    {SocketDataBufferCapacityMaxLimit_}.
      //       Validate.
      //    {ResponseContentParsingFactor1_}.
      //       Use.
      //    {ResponseContentActualOffset37_}.
      //       Update.
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.

      //base->TryParseResponse

      // We have fewer validations here than in {TPetroleumStatusReportDownloader}.
      // yg? It might make sense to move some validations past the {ConstantString34AsArray_} comparison or repeat them there.

      // We can be called only after some text arrived.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContent.DataLength > 0U );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( ( TryMakeWarmUpStepIsRunning_ &&
              responseContent.length() == static_cast< unsigned int >( ConstantString26Length_ ) &&
              responseContent.DataLength == responseContent.length()
           ) ||
           ( ( ! TryMakeWarmUpStepIsRunning_ ) &&
              responseContent.length() >= static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) &&

              // We can exceed this limit by a little because we can append text to the data buffer
              // but we are not supposed to parse the text we appended.
              responseContent.length() <= static_cast< unsigned int >( SocketDataBufferCapacityMaxLimit_ ) &&

              responseContent.DataLength <= responseContent.length()
           )
         );

      // If this validation fails I would need to increase {SocketDataBufferInitialCapacity_}.
      assert( TryMakeWarmUpStepIsRunning_ ||
                  responseContent.length() == static_cast< unsigned int >( SocketDataBufferInitialCapacity_ )
               );

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

      // I want the length to be sufficient to fit "\nNet Change: " plus 5 chars.
      // The data to be parsed can be shorter but keeping it simple.
      if( static_cast< unsigned int >( responseContent.DataLength ) <
          static_cast< unsigned int >( ResponseContentParsingFactor1_ + ConstantString37Length_ + 5 )
        )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         return 2U;
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      {
         ::Common::DataStructures::TDataBuffer::const_iterator responseContentBeginIterator
            ( responseContent.cbegin() + ResponseContentParsingFactor1_ );
         ::Common::DataStructures::TDataBuffer::const_iterator responseContentEndIterator
            ( responseContent.cbegin() +
              static_cast< ::Common::DataStructures::TDataBuffer::difference_type >( responseContent.DataLength )
            );
      
         // These validations act as optimization hints for {::std::search}.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( ( responseContentEndIterator - 5 ) - responseContentBeginIterator >= ConstantString37Length_ );

         // As mentioned above, demanding at least 5 extra chars.
         ::Common::DataStructures::TDataBuffer::const_iterator responseContentIterator1
            ( ::std::search
                 ( responseContentBeginIterator,
                   responseContentEndIterator - 5,
                   ConstantString37AsArray_,
                   ConstantString37AsArray_ + static_cast< unsigned int >( ConstantString37Length_ )
                 )
            );

         if( responseContentIterator1 == responseContentEndIterator - 5 )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            return 2U;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }

         // We probably can assign to this field at most once, which I feel no need to validate.
         // Assuming this will not overflow. It probably can't.
         ResponseContentActualOffset37_ = static_cast< int >( responseContentIterator1 - responseContent.cbegin() );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ResponseContentActualOffset37_ >= ResponseContentParsingFactor1_ );

         responseContentIterator1 += ConstantString37Length_;
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( ( TryMakeWarmUpStepIsRunning_ &&
                 responseContentEndIterator - responseContentIterator1 == 5 + 1
              ) ||
              ( ( ! TryMakeWarmUpStepIsRunning_ ) &&
                 responseContentEndIterator - responseContentIterator1 >= 5
              )
            );

         // The last 2 chars of "\nNet Change: ".
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContentIterator1[ - 1 ] == ' ' );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( responseContentIterator1[ - 2 ] == ':' );

         {
            int value1( 0 );
            int value1SignCode;
            int value1DigitCounter( 3 );

            if( ( * responseContentIterator1 ) == '-' )
            {
               ++ responseContentIterator1;
               value1SignCode = ( - 1 );
            }
            else
            {
               value1SignCode = 1;
            }
            
            // This logic ensures that we won't fall through beyond the 5 chars.
            // But it's probably impossible to validate that without adding another variable.
            for( ; ; ++ responseContentIterator1 )
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( value1DigitCounter <= 3 );
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( value1DigitCounter >= 0 );

               // This works regardless if the {char} type is {signed} or {unsigned}.
               unsigned int responseContentChar1AsUInt( static_cast< unsigned char >( * responseContentIterator1 ) );

               // This works regardless if the {char} type is {signed} or {unsigned}.
               // This can overflow.
               unsigned int digitCode1( responseContentChar1AsUInt - static_cast< unsigned int >( static_cast< unsigned char >( '0' ) ) );

               if( digitCode1 <= 9U )
               {
                  if( ( -- value1DigitCounter ) >= 0 )
                  {
                     // This can't overflow.
                     value1 = static_cast< int >( static_cast< unsigned int >( value1 ) * 10U + digitCode1 );
                  }
                  else
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                     goto onResponseContentMalformed;
                  }
               }
               else
               {
                  // This works regardless if the {char} type is {signed} or {unsigned}.
                  if( responseContentChar1AsUInt <= static_cast< unsigned int >( static_cast< unsigned char >( ' ' ) ) )

                  {
                     if( value1DigitCounter < 3 )
                     {
                        // This can't overflow.
                        Result = value1SignCode * value1;

                        // The compiler views this as a memory barrier and therefore we cross it after potentially optimizable statements.
                        EconomicReportReceptionTimeStampMilliseconds_ = ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds();

                        YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
                        OutcomeCode_ = TEconomicReportReceiverOutcomeCode_Success;
                        return 1U;
                     }
                     else
                     {
                        ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                        goto onResponseContentMalformed;
                     }
                  }
                  else
                  {
                     ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                     goto onResponseContentMalformed;
                  }
               }
            }
         }
      }

      // This point is unreachable.

//TODO rename this label to not begin with "on"?
   onResponseContentMalformed:
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );
      OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError;
      return 8U;
   }

#endif

#if( /* {protected LogActivityReportHeader}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TNaturalGasStorageReportDownloader::LogActivityReportHeader() const
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
      //    {ResponseContentActualOffset37_}.
      //       Use.

      //base->LogActivityReportHeader

      int const tempString1BufferLength( 128 );
      ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
      static char const formatConstantString1AsArray[]( "natural gas storage report downloading activity report; %+i; %u; %+i; %i" );

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
                Result,

                // This can be a big negative number, so we can't log it as an unsigned. But we anyway don't prepend a '+'.
                ResponseContentActualOffset37_
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
