#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TNewsHubEconomicIndicatorReceiver.hpp"

#include "./TNewsHubHelpers.cpp"
#include "./TEconomicReportReceiverViaTcpBase.cpp"
#include "./TNewsHubEconomicIndicatorReceiverConfiguration.cpp"
#include "../Common/WarmUp/TWarmUpHelpers.cpp"
#include "../Common/Globalization/TGlobalizationHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {private ConstantString13AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TNewsHubEconomicIndicatorReceiver::ConstantString13AsArray_[]( "(an exception was thrown on sending)" );

   inline void TNewsHubEconomicIndicatorReceiver::ConstantString13StaticAssertion()
   {
      static_assert( static_cast< unsigned int >( ConstantString13Length_ ) == ( sizeof( ConstantString13AsArray_ ) / sizeof( ConstantString13AsArray_[ 0U ] ) - 1U ), "" );
   }

#endif
#if( /* {private ConstantStrings26AsArray_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const * const TNewsHubEconomicIndicatorReceiver::ConstantStrings26AsArray_[ 4U ] =
      { "NH|AV|%.4u|%sEI name|-01.234567890|0|",
         "NH|AV|%.4u|%sEI name|987654321||",
         "NH|AV|%.4u|%sEI name|0000.0000|0|",
         "NH|AV|%.4u|%sEI name|+012345678.90||",
      };

#endif

#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TNewsHubEconomicIndicatorReceiver::TNewsHubEconomicIndicatorReceiver()
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TNewsHubEconomicIndicatorReceiver::TNewsHubEconomicIndicatorReceiver
      ( TNewsHubEconomicIndicatorReceiverConfiguration && configuration1
      ) :
      TEconomicReportReceiverViaTcpBase< int >( ::std::move( configuration1 ) ),
      EconomicIndicatorIdAsString_( ::std::move( configuration1.EconomicIndicatorIdAsString ) )
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

   void TNewsHubEconomicIndicatorReceiver::Initialize
      ( TNewsHubEconomicIndicatorReceiverConfiguration && configuration1
      )
   {
      TEconomicReportReceiverViaTcpBase< int >::Initialize( ::std::move( configuration1 ) );

      EconomicIndicatorIdAsString_.assign( ::std::move( configuration1.EconomicIndicatorIdAsString ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNewsHubEconomicIndicatorReceiver::DoInitialize
      ( TNewsHubEconomicIndicatorReceiverConfiguration && configuration1
      )
   {
// TODO 2 yg? Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
// TODO 2 yg? Refer to it from consrtructors, destructors, {Initialize}.

      SocketDataBufferInitialCapacity_ = ::std::move( configuration1.SocketDataBufferInitialCapacity );
      EconomicIndicatorValueMultiplier_ = ::std::move( configuration1.EconomicIndicatorValueMultiplier );
      WarmUpCounter_ = 0;
   }

#endif
#if( /* {public Prepare}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TNewsHubEconomicIndicatorReceiver::Prepare
      ( ::Common::Time::TDateTimeKeeper const & dateTimeKeeper
      )
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {Prepare} -- base.
      //       Override, call.
      //    {EconomicIndicatorIdAsString_.push_back}.
      //       Call.

      TEconomicReportReceiverViaTcpBase< int >::Prepare( dateTimeKeeper );

      // {DoInitialize} should not do this as this can allocate memory and therefore throw an exception.
      EconomicIndicatorIdAsString_.push_back( '|' );
   }

#endif
#if( /* {protected DoTryRun}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   /*bool*/ void TNewsHubEconomicIndicatorReceiver::DoTryRun()
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {Result}.
      //       Update.
      //    {DoTryRun} -- base.
      //       Override, call.

      Result = ::std::numeric_limits< int >::lowest();

      TEconomicReportReceiverViaTcpBase< int >::DoTryRun();
   }

#endif

#if( /* {protected WarmUp}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TNewsHubEconomicIndicatorReceiver::WarmUp()
   {
      // This method is virtual and not inline.
      // As mentioned below, this method has some side effects, which is OK.

      // Visible universe.
      //    {::Common::WarmUp::TWarmUpHelpers::WarmUpState}.
      //       Update.
      //       This is a side effect, which is OK.
      //    {TNewsHubHelpers::MessageTextHeaderLength}.
      //       Validate, use.
      //    {Result}.
      //       Use, update.
      //       It's updated indirectly and is not restored, which is a side effect, which is OK.
      //    {EconomicReportReceptionTimeStampMilliseconds_}.
      //       Update.
      //       It's updated indirectly and is not restored, which is a side effect, which is OK.
      //    {OutcomeCode_}.
      //       Validate, update.
      //       It's updated indirectly and is not restored, which is a side effect, which is OK.
      //    {WarmUp} -- base.
      //       Override, call.
      //    {Socket_.DataBuffer()} content.
      //       Update.
      //       This is a side effect, which is OK.
      //    {Socket_.DataBuffer().length()}.
      //       Validate, use.
      //    {Socket_.DataBuffer().DataLength}.
      //       Validate, use, update (but restore).
      //    {SocketStateIsValid_}.
      //       Validate, use.
      //    {SocketDataBufferParsingOffset_}.
      //       Validate, update (but restore).
      //       It's updated indirectly.
      //    {EconomicIndicatorIdAsString_}.
      //       Validate, use.
      //    {WarmUpCounter_}.
      //       Use, update.
      //    {ConstantStrings26AsArray_}.
      //       Use.
      //    {ConstantString26LengthAdjustment_}.
      //       Use.
      //    {TryParseReceivedData}.
      //       Call.

      TEconomicReportReceiverViaTcpBase< int >::WarmUp();

      // To keep it simple, we will do nothing when this condition is {true}.
      // This condition is {true} on the 1st call.
      if( ! SocketStateIsValid_ )

      {
         return;
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( Socket_.DataBuffer().length() <
           static_cast< unsigned int >( ::std::numeric_limits< int >::max() ) / ( 2U * sizeof( ::Common::DataStructures::TDataBuffer::value_type ) )
         );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Socket_.DataBuffer().DataLength <= Socket_.DataBuffer().length() );

      // To keep it simple, we will do nothing when this condition is {false}.
      // This can't overflow, as validated.
      if( static_cast< unsigned int >( Socket_.DataBuffer().DataLength ) == 0U )

      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         return;
      }

      {
         char const * constantString26AsArray
            ( ConstantStrings26AsArray_
                 [ static_cast< unsigned int >( WarmUpCounter_ ) %
                   static_cast< unsigned int >( sizeof( ConstantStrings26AsArray_ ) / sizeof( ConstantStrings26AsArray_[ 0U ] ) )
                 ]
            );

         // I would normally want to increment this at the very end, ideally right before {TryMakeWarmUpStep} returns,
         // but we can abort the warm-up operation some 30 lines below
         // and I want to increment this even in case we abort the warm-up operation
         // so that the next time we could try another {ConstantStrings26AsArray_} item.
         ++ WarmUpCounter_;

         // Assuming this will not overflow.
         int constantString26Length
            ( static_cast< int >( ::Common::DataStructures::TDataBuffer::traits_type::length( constantString26AsArray ) ) );

         // If this condition is {false} fewer chars would be printed, which would result in malformed message,
         // which would break many other validations and probably result in incorrect/undefined behavior.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EconomicIndicatorIdAsString_.find( '\x00' ) == ::std::string::npos );

         // The number of chars expected to be printed, excluding the terminating '\x00'.
         // {EconomicIndicatorIdAsString_.length()} is at least 2U and is not too big and we probably don't need to validate that.
         // Assuming this will not overflow.
         int constantString26AdjustedLength
            ( constantString26Length + static_cast< int >( EconomicIndicatorIdAsString_.length() ) + ConstantString26LengthAdjustment_ );

         // This is really greater by a margin, probably close to 30, but it doesn't matter.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( constantString26AdjustedLength > TNewsHubHelpers::MessageTextHeaderLength );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( constantString26AdjustedLength - TNewsHubHelpers::MessageTextHeaderLength <= 9999 );

         // This condition will be {false} if the user configures a too small {SocketDataBufferInitialCapacity_}.
         // TODO 3 yg? Maybe don't check this, just assume.
         if( static_cast< unsigned int >( constantString26AdjustedLength ) <= static_cast< unsigned int >( Socket_.DataBuffer().length() ) )

         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            {
               static char const constantString1AsArray[]( "{Prototype52::TNewsHubEconomicIndicatorReceiver::WarmUp} failed" );
               ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
               logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
            }

            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            return;
         }

         int numberCharsPrinted
            ( ::_snprintf_l
                 ( ( & Socket_.DataBuffer().front() ),
                   static_cast< unsigned int >( constantString26AdjustedLength ),
                   constantString26AsArray,
                   ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                   static_cast< unsigned int >( constantString26AdjustedLength - TNewsHubHelpers::MessageTextHeaderLength ),

                   // We validated that this contains no '\x00'.
                   EconomicIndicatorIdAsString_.c_str()
                 )
            );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberCharsPrinted == constantString26AdjustedLength );
         Socket_.DataBuffer().DataLength = static_cast< unsigned int >( numberCharsPrinted );
      }

      // This is valid because {Socket_.DataBuffer().DataLength == 0U} (before we modified it).
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketDataBufferParsingOffset_ == 0 );

      unsigned int receivedDataParsingOutcomeCode( TryParseReceivedData() );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( receivedDataParsingOutcomeCode == 1U );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( static_cast< unsigned int >( SocketDataBufferParsingOffset_ ) == Socket_.DataBuffer().DataLength );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );
      ::Common::WarmUp::TWarmUpHelpers::WarmUpState ^= Result;
      
      SocketDataBufferParsingOffset_ = 0;
      Socket_.DataBuffer().DataLength = 0U;
   }

#endif

#if( /* {protected ConfigureSocket}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TNewsHubEconomicIndicatorReceiver::ConfigureSocket()
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {Socket_.setLinger}.
      //       Call.
      //    {Socket_.setNoDelay}.
      //       Call.
      //    {Socket_.DataBuffer().length()}.
      //       Use.
      //    {Socket_.DataBuffer().resize}.
      //       Call.
      //    {Socket_.DataBufferCapacityMaxLimit()}.
      //       Update.
      //    {ConfigureSocket} -- base.
      //       Override, call.
      //    {SocketDataBufferInitialCapacity_}.
      //       Use.
      //    {SocketDataBufferInitialCapacityMultiplier_}.
      //       Use.

      // We probably don't need to set send timeout.

      // Changing these parameters before calling the base just in case the base needs to use them.
      {
         // We probably don't need to sanity-validate these at this point. But we will make some validations later.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketDataBufferInitialCapacity_ > 0 );
         unsigned int socketDataBufferCapacityMaxLimit
            ( static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) *
              static_cast< unsigned int >( SocketDataBufferInitialCapacityMultiplier_ )
            );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( socketDataBufferCapacityMaxLimit > static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );
      
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( Socket_.DataBuffer().length() <
              static_cast< unsigned int >( ::std::numeric_limits< int >::max() ) / ( 2U * sizeof( ::Common::DataStructures::TDataBuffer::value_type ) )
            );

         // This condition is {false} in case we closed previous socket handle and created another one.
         if( static_cast< unsigned int >( Socket_.DataBuffer().length() ) == 0U )

         {
            Socket_.DataBufferCapacityMaxLimit() = socketDataBufferCapacityMaxLimit;
            Socket_.DataBuffer().resize( static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );
         }
         else
         {
            // Assuming that the compiler is smart enough to optimize out the calculation of {socketDataBufferCapacityMaxLimit}.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( Socket_.DataBufferCapacityMaxLimit() == socketDataBufferCapacityMaxLimit );

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( Socket_.DataBuffer().length() >= static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );
         }
      }

      TEconomicReportReceiverViaTcpBase< int >::ConfigureSocket();

      // This is probably not important as we don't need to send anything in a timely manner but this probably eliminates some overhead.
      Socket_.setNoDelay( true );

      Socket_.setLinger( true, 0 );
   }

#endif
#if( /* {protected TrySendHeartBeatMessage}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   bool TNewsHubEconomicIndicatorReceiver::TrySendHeartBeatMessage()
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {::Common::Networking::TNetworkingHelpers::SendBytesIntoSocket}.
      //       Call.
      //    {TNewsHubHelpers::ClientHeartBeatMessageTextAsArray}.
      //       Use.
      //    {TNewsHubHelpers::ClientHeartBeatMessageTextLength}.
      //       Use.
      //    {Socket_.DataBuffer().Append}.
      //       Call.
      //    {SocketStateIsValid_}.
      //       Update.
      //    {TrySendHeartBeatMessage} -- base.
      //       Override (but don't call).
      //    {ConstantString...AsArray_}, {ConstantString...Length_}.
      //       Use.

      //base->TrySendHeartBeatMessage

      try
      {
         ::Common::Networking::TNetworkingHelpers::SendBytesIntoSocket
            ( Socket_, TNewsHubHelpers::ClientHeartBeatMessageTextAsArray, TNewsHubHelpers::ClientHeartBeatMessageTextLength, 0 );
      }

      // Catching only POCO exceptions. Assuming this exception is not critical.
      catch( ::Poco::Exception const & exception1 )

      {
         {
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.warning( exception1.displayText() );
         }

         //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         // We will not try to parse this.
         // Expecting that the buffer is not empty. Otherwise we would assign rather than append.
         Socket_.DataBuffer().Append( ConstantString13AsArray_, static_cast< unsigned int >( ConstantString13Length_ ) );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );
         SocketStateIsValid_ = false;
         return false;
      }

      return true;
   }

#endif
#if( /* {protected TryParseReceivedData}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   unsigned int TNewsHubEconomicIndicatorReceiver::TryParseReceivedData()
   {
      #pragma region

      // This method is virtual and not inline.
      // yg? See {EconomicIndicatorIdAsString_} comment.
      // This implementation is not designed to parse a part of an incomplete message
      // and later when more data arrives resume from where is paused. We would probably rarely benefit from such a feature.
      // Data buffer can contain garbage beyond its {DataLength}.

      // Visible universe.
      //    {::_atof_l}.
      //       Call.
      //    {::Common::Math::TMathHelpers::Round...}.
      //       Call.
      //    {TNewsHubHelpers::MessageTextHeaderLength}.
      //       Use.
      //    {Result}.
      //       Update.
      //    {EconomicReportReceptionTimeStampMilliseconds_}.
      //       Update.
      //    {OutcomeCode_}.
      //       Update.
      //    {Socket_.DataBuffer()} content.
      //       Use.
      //    {Socket_.DataBuffer().length()}.
      //       Validate.
      //    {Socket_.DataBuffer().DataLength}.
      //       Validate, use.
      //    {SocketStateIsValid_}.
      //       Update.
      //    {SocketDataBufferParsingOffset_}.
      //       Validate, use, update.
      //    {TryParseReceivedData} -- base.
      //       Implement.
      //    {SocketDataBufferInitialCapacity_}.
      //       Validate.
      //    {EconomicIndicatorIdAsString_}.
      //       Validate, use.
      //    {EconomicIndicatorValueMultiplier_}.
      //       Use.

      //base->TryParseReceivedData

      #pragma endregion
      #pragma region

      // We can be called only after new data was appended to the buffer.
      // Note that we validate the { <= } comparison at the beginning of each loop and after we update {SocketDataBufferParsingOffset_}
      // in case we are going to break the loop.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( static_cast< unsigned int >( SocketDataBufferParsingOffset_ ) < Socket_.DataBuffer().DataLength );

      #pragma endregion
      #pragma region

      for( ; ; )
      {
         #pragma region

         // The buffer capacity limit is supposed to be much smaller than this.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( Socket_.DataBuffer().length() <
              static_cast< unsigned int >( ::std::numeric_limits< int >::max() ) / ( 2U * sizeof( ::Common::DataStructures::TDataBuffer::value_type ) )
            );

         // If this validation fails I would need to increase {SocketDataBufferInitialCapacity_}.
         assert( Socket_.DataBuffer().length() == static_cast< unsigned int >( SocketDataBufferInitialCapacity_ ) );

         // We can be called only after new data was appended to the buffer.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Socket_.DataBuffer().DataLength > 0U );

         // Since we validated that {Socket_.DataBuffer().DataLength > 0U}, this also indirectly validates that
         // {Socket_.DataBuffer().length() > 0U}.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Socket_.DataBuffer().DataLength <= Socket_.DataBuffer().length() );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketDataBufferParsingOffset_ >= 0 );

         // We can be called only after new data was appended to the buffer, so on the 1st loop the { < } comparison is valid,
         // which we validate before the loop.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( static_cast< unsigned int >( SocketDataBufferParsingOffset_ ) <= Socket_.DataBuffer().DataLength );

         #pragma endregion
         #pragma region

         int messageTextLength;

         #pragma endregion
         #pragma region

         {
            #pragma region

            // This can't overflow, as validated.
            int dataLength( static_cast< int >( Socket_.DataBuffer().DataLength ) - SocketDataBufferParsingOffset_ );

            // On the 1st loop this is actually positive, as validated before the loop.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( dataLength >= 0 );

            #pragma endregion
            #pragma region

            // Expecting that a message can contain only a header.
            if( dataLength < TNewsHubHelpers::MessageTextHeaderLength )
         
            {
               // We normally get to this point when {dataLength == 0}. Otherwise we would rather stop but keeping it simple.
               //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

               return 2U;
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }

            #pragma endregion
            #pragma region

            ::Common::DataStructures::TDataBuffer::const_iterator messageTextBeginIterator
               ( Socket_.DataBuffer().cbegin() + SocketDataBufferParsingOffset_ );

            #pragma endregion
            #pragma region

            // We don't check that these are all digits but we do check that the result is from 0 to 9999.
            // Overriding default integral promotion.
            // yg? It's worth testing if it would be faster to read a {uint} at the offset of 6
            // yg? and then bitwise-and and bitwise-shift it a few times.
            messageTextLength =
               static_cast< int >
                  ( static_cast< unsigned int >( static_cast< unsigned char >( messageTextBeginIterator[ 6 ] ) ) * 1000U +
                    static_cast< unsigned int >( static_cast< unsigned char >( messageTextBeginIterator[ 7 ] ) ) * 100U +
                    static_cast< unsigned int >( static_cast< unsigned char >( messageTextBeginIterator[ 8 ] ) ) * 10U +
                    static_cast< unsigned int >( static_cast< unsigned char >( messageTextBeginIterator[ 9 ] ) ) -
                    static_cast< unsigned int >( static_cast< unsigned char >( '0' ) ) * ( 1000U + 100U + 10U + 1U )
                  );
         
            //#pragma endregion
            //#pragma region

            if( messageTextLength >= 0 && messageTextLength <= 9999 )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               break;
            }

            messageTextLength += TNewsHubHelpers::MessageTextHeaderLength;

            #pragma endregion
            #pragma region

            if( messageTextLength > dataLength )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               return 2U;
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }

            #pragma endregion
            #pragma region

            // It would be nice to treat the message as malformed if any of these is {false} but keeping it efficient.
            {
               assert( messageTextBeginIterator[ 2 ] == '|' );
               assert( messageTextBeginIterator[ 5 ] == '|' );
               assert( messageTextBeginIterator[ TNewsHubHelpers::MessageTextHeaderLength - 1 ] == '|' );

               // Note that it's possible that {messageTextLength == TNewsHubHelpers::MessageTextHeaderLength}.
               // But it's probably not supposed to be the case in an "Actual Value" message.
               // But if it's the case we will skip the message.
               assert( messageTextBeginIterator[ messageTextLength - 1 ] == '|' );
            }

//TODO Do we need #if( defined( _M_IX86 ) || defined( _M_X64 ) ) . . . search for "unaligned".
            static_assert( POCO_ARCH_LITTLE_ENDIAN == 1, "" );

            // When this condition is {false} it would be nice to make an extra effort to check if the message is malformed
            // but keeping it efficient.
            if( reinterpret_cast< int const & >( * messageTextBeginIterator ) != 'A|HN' ||
                reinterpret_cast< short const & >( messageTextBeginIterator[ 4 ] ) != static_cast< short >( '|V' )
              )

            {
               //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               goto skipMessage;
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }

            #pragma endregion
            #pragma region

            // We appended '|' to this, so its length is supposed to be at least 2U.
            // Although there would probably be no undefined behavior even if this was configured to be empty
            // but in that case this validation/assumption will actually cause undefined behavior.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( EconomicIndicatorIdAsString_.length() >= 2U );

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( EconomicIndicatorIdAsString_.length() <
                 static_cast< unsigned int >( ::std::numeric_limits< int >::max() ) / ( 2U * sizeof( ::Common::DataStructures::TDataBuffer::value_type ) )
               );

            #pragma endregion
            #pragma region

            // This is an example of a minimum length "Actual Value" message:
            // NH|AV|0006|2||9||

            // This ensures that the message is long enough to fit {EconomicIndicatorIdAsString_}.
            // {false} usually indicates that the message is malformed but it's potentially possible that it's not
            // in case {EconomicIndicatorIdAsString_} is long enough, so we would just skip the message.
            // Note that we appended '|' to {EconomicIndicatorIdAsString_}.
            // I feel that this condition should not be flipped.
            // This can't overflow as we sanity-validated {EconomicIndicatorIdAsString_.length()}.
            if( static_cast< unsigned int >( messageTextLength ) >=
                ( static_cast< unsigned int >( TNewsHubHelpers::MessageTextHeaderLength ) +
                  static_cast< unsigned int >( EconomicIndicatorIdAsString_.length() ) +
                  4U
                )
              )

            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               goto skipMessage;
            }

            #pragma endregion
            #pragma region

            if( ::Common::DataStructures::TDataBuffer::traits_type::compare
                   ( ( & messageTextBeginIterator[ TNewsHubHelpers::MessageTextHeaderLength ] ),
                     EconomicIndicatorIdAsString_.data(),
                     EconomicIndicatorIdAsString_.length()
                   ) !=
                0
              )
            {
               //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               goto skipMessage;
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }

            #pragma endregion
            #pragma region

            // At this point we know that the desired message has arrived. We will now parse it and return.
            // yg? The number we are to parse can potentially be malformed but {::_atof_l} won't detect this.

            // Optimization hint.
            // We probably can safely assume that this is greater than 0U by some margin and less than {Socket_.DataBuffer().length()}
            // by some margin but keeping it simple.
            // As an unsigned, this is implicitly non-negative.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( static_cast< unsigned int >( SocketDataBufferParsingOffset_ + messageTextLength - 2 ) < Socket_.DataBuffer().length() );

            // Searching for the '|' before News Feed Source Integer, which in turn can be empty.
            // The starting search position is after the '|' after News Feed Source Integer as we checked that we have a few extra chars.
            // Both this and the next search are guaranteed to succeed as we checked that the message contains a few '|' chars.
            // yg? Here and below, it might be more efficient to avoid using {...::rfind} and instead simply write code
            // yg? to search for a char in a loop. And {::Common::DataStructures::TDataBuffer::traits_type::find} might be even faster.
            ::Common::DataStructures::TDataBuffer::size_type economicIndicatorValueOffset
               ( Socket_.DataBuffer().rfind( '|', static_cast< unsigned int >( SocketDataBufferParsingOffset_ + messageTextLength - 2 ) ) );

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( economicIndicatorValueOffset != ::Common::DataStructures::TDataBuffer::npos );

            // Last char of Actual Value.
            // We don't need to assume this in any logic.
            assert( static_cast< unsigned char >( Socket_.DataBuffer().at( economicIndicatorValueOffset - 1U ) ) >=
                        static_cast< unsigned char >( '0' )
                     );
            assert( static_cast< unsigned char >( Socket_.DataBuffer().at( economicIndicatorValueOffset - 1U ) ) <=
                        static_cast< unsigned char >( '9' )
                     );

            // Optimization hint.
            // The preceeding optimization hint comment applies.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( economicIndicatorValueOffset - 2U < Socket_.DataBuffer().length() );
            
            // Searching for the '|' before Actual Value.
            economicIndicatorValueOffset = Socket_.DataBuffer().rfind( '|', economicIndicatorValueOffset - 2U );
            
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( economicIndicatorValueOffset != ::Common::DataStructures::TDataBuffer::npos );

            ++ economicIndicatorValueOffset;

            #pragma endregion
            #pragma region

            // Let's advance this before crossing what the compiler views as memory barriers -- to make the code more optimizable.
            // It's correct to do this only when it's impossible that we will declare the message malformed.
            // yg? This is currently the case as {::_atof_l} won't detect a malformness.
            // This can't overflow.
            SocketDataBufferParsingOffset_ += messageTextLength;

            // Similar validations to those at the beginning of the loop.
            // See related comment near where we advance and validate this below.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketDataBufferParsingOffset_ > 0 );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( static_cast< unsigned int >( SocketDataBufferParsingOffset_ ) <= Socket_.DataBuffer().DataLength );

            #pragma endregion
            #pragma region

            // yg? This will return 0.0 on error and we will do nothing about it.
            // yg? If we didn't ignore number parsing errors it would be incorrect to advance {SocketDataBufferParsingOffset_} before this.
            // TODO 3 yg? Consider implementing this parsing more efficiently and/or reliably.
            // TODO 3 yg? POCO uses a floating point parsing library or something like that. Can we use it?
            // TODO 3 yg? Can we use {::_atoflt_l}? Then round it as {< float, int >}.
            // TODO 3 yg? But ideally I want NewsHub to always send an {int}.
            double economicIndicatorValue( ::_atof_l( ( & Socket_.DataBuffer().at( economicIndicatorValueOffset ) ),
                                                                               ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale
                                                                             )
                                                             );

            // This is a cheap rounding but not necessarily the most correct.
            // As mentioned in the config file, {EconomicIndicatorValueMultiplier_} must ensure that there will be no precision loss
            // or overflow.
            // It's probably unnecessary to validate {Result} before we update it.
            // And the validation would probably fail when we are called from {WarmUp}.
            Result = ::Common::Math::TMathHelpers::RoundValueToIntegerMidpointAwayFromZero< double, int >
                             ( economicIndicatorValue * EconomicIndicatorValueMultiplier_ );

            #pragma endregion
         }

         #pragma endregion
         #pragma region

         // The compiler views this as a memory barrier and therefore we cross it after potentially optimizable statements.
         EconomicReportReceptionTimeStampMilliseconds_ = ::Common::Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds();

         // This condition is {false} when we are called from {WarmUp}.
         //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );

         OutcomeCode_ = TEconomicReportReceiverOutcomeCode_Success;
         return 1U;

         #pragma endregion
         #pragma region

      skipMessage:
         // We will validate this on the next loop.
         // This can't overflow.
         SocketDataBufferParsingOffset_ += messageTextLength;

         // At the beginning of the loop we validate that this is not negative.
         // But let's validate that this is now positive, which really might be unnecessary.
         // We probably can safely assume that this is greater than 0 by a margin but keeping it simple.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketDataBufferParsingOffset_ > 0 );

         #pragma endregion
      }

      #pragma endregion
      #pragma region

      {
         static char const constantString1AsArray[]( "NewsHub message is malformed" );
         ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
         logger1.error( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketStateIsValid_ );
      SocketStateIsValid_ = false;

      // This condition is {false} when we are called from {WarmUp} but in that case we aren't supposed to get to this point.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Undefined );

      OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError;
      return 8U;

      #pragma endregion
   }

#endif

#if( /* {protected LogActivityReport}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TNewsHubEconomicIndicatorReceiver::LogActivityReport() const
   {
      // This method is virtual and not inline.

      // Visible universe.
      //    {PeerStrategyBaseModeCode_}.
      //       Use.
      //    {Result}.
      //       Use.
      //    {OutcomeCode_}.
      //       Use.
      //    {SafeGetEconomicReportReceptionDateTimeStampOffsetMilliseconds()}.
      //       Use.
      //    {Socket_.DataBuffer()} content.
      //       Use.
      //    {Socket_.DataBuffer().DataLength}.
      //       Validate, use.
      //    {SocketDataBufferParsingOffset_}.
      //       Validate, use.
      //    {LogActivityReport} -- base.
      //       Implement.

      //base->LogActivityReport

      // We don't need to sanity-validate {Socket_.DataBuffer().length()}.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( Socket_.DataBuffer().DataLength <
           static_cast< unsigned int >( ::std::numeric_limits< int >::max() ) / ( 2U * sizeof( ::Common::DataStructures::TDataBuffer::value_type ) )
         );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( SocketDataBufferParsingOffset_ >= 0 );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( static_cast< unsigned int >( SocketDataBufferParsingOffset_ ) <= Socket_.DataBuffer().DataLength );

      {
         // Based on the above validations, this can't overflow.
         int const tempString1BufferLength
            ( 128 +
              static_cast< int >( Socket_.DataBuffer().DataLength )
            );

         ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );
         static char const formatConstantString1AsArray[]
            //( "NewsHub economic indicator reception activity report; %+i; %u; %+i%s%.*s%s%s" );
            ( "NewsHub economic indicator reception activity report; %+i; %u; %+i%s%.*s%s%.*s" );

         // We will format this as an unsigned.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OutcomeCode_ >= 0 );

         // yg? Consider also logging {SocketStateIsValid_}. But it's probably unnecessary.
         int tempString1Length
            ( ::_snprintf_l
                 ( ( & tempString1.front() ),
                   static_cast< unsigned int >( tempString1BufferLength ),
                   formatConstantString1AsArray,
                   ::Common::Globalization::TGlobalizationHelpers::CInvariantLocale,
                   SafeGetEconomicReportReceptionDateTimeStampOffsetMilliseconds(),
                   static_cast< unsigned int >( OutcomeCode_ ),
                   Result,
                   ::Poco::LineEnding::NEWLINE_DEFAULT.c_str(),
                   SocketDataBufferParsingOffset_,

                   // yg? If this contains a '\x00' only whatever is before it will be printed.
                   Socket_.DataBuffer().data(),

                   ::Poco::LineEnding::NEWLINE_DEFAULT.c_str(),

                   //// yg? If this contains a '\x00' only whatever is before it will be printed.
                   //// Assuming this doesn't invalidate {Socket_.DataBuffer().data()} that we call a few lines above.
                   //Socket_.DataBuffer().c_str() + SocketDataBufferParsingOffset_

                   // Based on the above validations, this can't overflow.
                   static_cast< int >( Socket_.DataBuffer().DataLength ) - SocketDataBufferParsingOffset_,

                   // yg? If this contains a '\x00' only whatever is before it will be printed.
                   ( & Socket_.DataBuffer().at( static_cast< unsigned int >( SocketDataBufferParsingOffset_ ) ) )
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
         if( ( OutcomeCode_ != TEconomicReportReceiverOutcomeCode_Success ) ==
             ( PeerStrategyBaseModeCode_ == TPeerStrategyBaseModeCode_Test )
           )
         {
            logger1.information( tempString1 );
         }
         else
         {
            logger1.warning( tempString1 );
            //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         }
      }
   }

#endif
}
