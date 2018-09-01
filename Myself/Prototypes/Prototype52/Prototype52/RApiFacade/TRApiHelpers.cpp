#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TRApiHelpers.hpp"

#include "./TREngineParamsConfiguration.cpp"
#include "./TLogInParamsConfiguration.cpp"
#include "./TAccountInfoConfiguration.cpp"
#include "./TSingleInstrumentOrder.cpp"
//#include "./TSingleInstrumentOrderHelpers.cpp"
//#include "./TREngineAdapter.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* {public OrderReportTextAtomicOrderOperationInProgressAsArray}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   char const TRApiHelpers::OrderReportTextAtomicOrderOperationInProgressAsArray[]( "Atomic order operation in progress" );

   inline void TRApiHelpers::OrderReportTextAtomicOrderOperationInProgressStaticAssertion()
   {
      static_assert( static_cast< unsigned int >( OrderReportTextAtomicOrderOperationInProgressLength ) == ( sizeof( OrderReportTextAtomicOrderOperationInProgressAsArray ) / sizeof( OrderReportTextAtomicOrderOperationInProgressAsArray[ 0U ] ) - 1U ), "" );
   }

#endif

#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public AtomicLastChanceHandleException}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TRApiHelpers::AtomicLastChanceHandleException
      ( ::OmneException const & exception1
      )
   {
      // yg? See additional comments in {::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException}.

      try
      {
         // yg? Not logging {omneException1.getErrorCode()}.
         // yg? Doing {const_cast}.
         ::Poco::Util::Application::instance().logger().fatal( ::std::string( const_cast< ::OmneException & >( exception1 ).getErrorString() ) );

         //::Common::Threading::TThreadingHelpers::SleepMillisecond();
         ::Poco::Thread::sleep( 1 );
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }
      catch( ... )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      ::std::abort();
      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   }

#endif

#if( /* {public TSNCharcbsEqual}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TRApiHelpers::TSNCharcbsEqual
      ( ::tsNCharcb const & tsNCharcb1,
        ::tsNCharcb const & tsNCharcb2
      )
   {
      // I don't want to assume these.
      assert( tsNCharcb1.iDataLen >= 0 );
      assert( tsNCharcb2.iDataLen >= 0 );

      return
         ( tsNCharcb1.iDataLen == tsNCharcb2.iDataLen &&

           // Case sensitive comparison.
           //::std::equal( tsNCharcb1.pData, tsNCharcb1.pData + tsNCharcb1.iDataLen, tsNCharcb2.pData );
           ( ::std::char_traits< char >::compare( tsNCharcb1.pData, tsNCharcb2.pData, static_cast< unsigned int >( tsNCharcb1.iDataLen ) ) ==
             0
           )
         );
   }

#endif
#if( /* {public TSNCharcbEqual}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TRApiHelpers::TSNCharcbEqual
      ( ::tsNCharcb const & tsNCharcb1,
        char const * chars2,
        int chars2Length
      )
   {
      // I don't want to assume this.
      assert( tsNCharcb1.iDataLen >= 0 );

      // But I want to assume this.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( chars2Length >= 0 );

      return
         ( tsNCharcb1.iDataLen == chars2Length &&

           // Case sensitive comparison.
           ::std::char_traits< char >::compare( tsNCharcb1.pData, chars2, static_cast< unsigned int >( chars2Length ) ) == 0
         );
   }

#endif
#if( /* {public PopulateNullableTSNCharcb}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TRApiHelpers::PopulateNullableTSNCharcb
      ( ::tsNCharcb & tsNCharcb1,
        ::std::string const & string1
      )
   {
      // Assuming this will not overflow.
      int stringLength( static_cast< int >( string1.length() ) );
      
      tsNCharcb1.iDataLen = stringLength;
      
      // yg? Would it make sense to compare {stringLength <= 0}? Keep in mind that {string1.length()} is unsigned.
      // yg? Doing {const_cast}.
      tsNCharcb1.pData = ( stringLength == 0 ) ? /*static_cast< char * >*/( nullptr ) : const_cast< char * >( string1.data() );
   }

#endif
#if( /* {public PopulateTSNCharcb}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TRApiHelpers::PopulateTSNCharcb
      ( ::tsNCharcb & tsNCharcb1,
        ::std::string const & string1
      )
   {
      // Assuming this will not overflow.
      int stringLength( static_cast< int >( string1.length() ) );
      
      // I don't want to assume this. {::RApi::REngine} will validate this and will probably throw an exception.
      assert( stringLength > 0 );

      tsNCharcb1.iDataLen = stringLength;

      // yg? Doing {const_cast}.
      tsNCharcb1.pData = const_cast< char * >( string1.data() );
   }

#endif

#if( /* {public PopulateREngineParams}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::PopulateREngineParams
      ( ::RApi::REngineParams & rEngineParams1,
        TREngineParamsConfiguration const & rEngineParamsConfiguration1
      )
   {
      // yg? This can't be empty, can it?
      PopulateTSNCharcb( rEngineParams1.sAppName, rEngineParamsConfiguration1.sAppName );

      // yg? This can't be empty, can it?
      PopulateTSNCharcb( rEngineParams1.sAppVersion, rEngineParamsConfiguration1.sAppVersion );

      // yg? This can't be empty, can it?
      PopulateTSNCharcb( rEngineParams1.sAdmCnnctPt, rEngineParamsConfiguration1.sAdmCnnctPt );

      PopulateNullableTSNCharcb( rEngineParams1.sLogFilePath, rEngineParamsConfiguration1.sLogFilePath );

      // yg? Doing {const_cast}.
      rEngineParams1.envp = const_cast< char * * >( rEngineParamsConfiguration1.envp.data() );

      //rEngineParams1.pContext =
      //rEngineParams1.pAdmCallbacks =
   }

#endif
#if( /* //{public CreateREngine}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline ::RApi::REngine * TRApiHelpers::CreateREngine
   //   ( ::RApi::REngineParams const & rEngineParams1
   //   )
   //{
   //   ::RApi::REngine * rEngine1;
   //   //try
   //   //{
   //      // yg? Doing {const_cast}.
   //      rEngine1 = new ::RApi::REngine( const_cast< ::RApi::REngineParams * >( & rEngineParams1 ) );
   //   //}
   //   //catch( ::OmneException const & exception1 )
   //   //{
   //      //>>>Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //   //   throw TOmneException( exception1 );
   //   //}
   //   return rEngine1;
   //}

#endif

#if( /* {public LockREngine}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::LockREngine
      ( ::RApi::REngine & rEngine1
      )
   {
      int outcomeCode2;
      int outcomeCode1( rEngine1.lock( & outcomeCode2 ) );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
      if( outcomeCode1 != NOT_OK )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {RApi::REngine::lock} failed" );
            throw ::Common::ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           outcomeCode2
                         );
         }
      }
   }

#endif
#if( /* {public UnlockREngine}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::UnlockREngine
      ( ::RApi::REngine & rEngine1
      )
   {
      int outcomeCode2;
      int outcomeCode1( rEngine1.unlock( & outcomeCode2 ) );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
      if( outcomeCode1 != NOT_OK )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {RApi::REngine::unlock} failed" );
            throw ::Common::ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           outcomeCode2
                         );
         }
      }
   }

#endif

#if( /* {public PopulateLogInParams}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::PopulateLogInParams
      ( ::RApi::LoginParams & logInParams1,
        TLogInParamsConfiguration const & logInParamsConfiguration1
      )
   {
      PopulateTSNCharcb( logInParams1.sUser, logInParamsConfiguration1.sUser );
      PopulateTSNCharcb( logInParams1.sPassword, logInParamsConfiguration1.sPassword );

      // yg? It's not generally required to provide all connect points but current logic declares that we are fully logged in
      // yg? only after we log in to some specific connect points. Therefore assuming no connect point can be empty.
      // Not used. PopulateTSNCharcb( logInParams1.sIhCnnctPt, logInParamsConfiguration1.sIhCnnctPt );
      PopulateTSNCharcb( logInParams1.sMdCnnctPt, logInParamsConfiguration1.sMdCnnctPt );
      // Not used. PopulateTSNCharcb( logInParams1.sPnlCnnctPt, logInParamsConfiguration1.sPnlCnnctPt );
      PopulateTSNCharcb( logInParams1.sTsCnnctPt, logInParamsConfiguration1.sTsCnnctPt );

      //logInParams1.pCallbacks =
   }

#endif
#if( /* {public AsyncEnsureREngineLoggedIn}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::AsyncEnsureREngineLoggedIn
      ( ::RApi::REngine & rEngine1,
        ::RApi::LoginParams const & logInParams1
      )
   {
      int outcomeCode1;
      int outcomeCode2;

      //try
      //{
         // Assuming {rEngine1} is locked.
         // When we call this twice in a row, even if we sleep between the calls, it sets {outcomeCode2 = API_IN_PROGRESS}.
         // When we call this, unlock {rEngine1}, sleep, lock {rEngine1}, and call this again
         // it sets {outcomeCode2 = API_ALREADY_EXISTS}.
         // yg? I haven't tested what would happen if we call this while {rEngine1} is restoring a broken connection.
         // yg? Doing {const_cast}.
         outcomeCode1 = rEngine1.login( const_cast< ::RApi::LoginParams * >( & logInParams1 ), ( & outcomeCode2 ) );
      //}
      //catch( ::OmneException const & exception1 )
      //{
         //>>>Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      //   throw TOmneException( exception1 );
      //}

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
      if( outcomeCode1 != NOT_OK ||

          // yg? Consider logging a warning when {outcomeCode2} equals one of the ignored error codes.
          outcomeCode2 == API_IN_PROGRESS ||
          outcomeCode2 == API_ALREADY_EXISTS
        )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {RApi::REngine::login} failed" );
            throw ::Common::ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           outcomeCode2
                         );
         }
      }
   }

#endif
#if( /* {public AsyncEnsureREngineLoggedOut}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TRApiHelpers::AsyncEnsureREngineLoggedOut
      ( ::RApi::REngine & rEngine1
      )
   {
      //int outcomeCode1;
      int outcomeCode2;

      //try
      //{
         // This method appears to not indicate an error when called redundantly.
         // I would expect it to set {outcomeCode2 = API_ALREADY_EXISTS}.
         // In .NET this method would throw an exception with that error code.
         // I've seen this method returning an error code under heavy debugging.
         // I believe it's safe to ignore any errors here.
         // TODO 3 yg? Should we log a warning when this returns an error code? Maybe only on some errors.
         /*outcomeCode1 =*/ rEngine1.logout( & outcomeCode2 );
      //}
      //catch( ::OmneException const & exception1 )
      //{
         //>>>Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      //   throw TOmneException( exception1 );
      //}

      //>>>YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 ...
      //if( outcomeCode1 >>>== NOT_OK )
      //{
         //>>>Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      //   static char const constantString1AsArray[]( "Critical; {RApi::REngine::logout} failed" );
      //   throw ::Common::ErrorHandling::TCriticalErrorException( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ), outcomeCode2 );
      //}
   }

#endif

#if( /* {public PopulateAccountInfo}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::PopulateAccountInfo
      ( ::RApi::AccountInfo & accountInfo1,
        TAccountInfoConfiguration const & accountInfoConfiguration1
      )
   {
      // yg? Maybe we should expect these to be empty.
      PopulateTSNCharcb( accountInfo1.sFcmId, accountInfoConfiguration1.sFcmId );
      PopulateTSNCharcb( accountInfo1.sIbId, accountInfoConfiguration1.sIbId );
      PopulateTSNCharcb( accountInfo1.sAccountId, accountInfoConfiguration1.sAccountId );

      //accountInfo1.pRmsInfo =
   }

#endif

#if( /* {public RequestInstrumentPriceIncrementMinLimit}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::RequestInstrumentPriceIncrementMinLimit
      ( TInstrument const & instrument1
      )
   {
      int outcomeCode1;
      int outcomeCode2;

      {
         ::tsNCharcb exchangeAbbreviation1;
         PopulateTSNCharcb( exchangeAbbreviation1, instrument1.ExchangeAbbreviation() );
         ::tsNCharcb symbol1;
         PopulateTSNCharcb( symbol1, instrument1.Symbol() );
         TREngineAdapter & rEngineAdapter1( instrument1.BrokerAdapter() );
         ::RApi::REngine & rEngine1( rEngineAdapter1.REngine() );

         // Assuming {rEngine1} is locked.
         // When we call this twice in a row it succeeds.
         // yg? See {TREngineAdapter::PriceIncrUpdate} comment.
         outcomeCode1 = rEngine1.getPriceIncrInfo( ( & exchangeAbbreviation1 ), ( & symbol1 ), ( & outcomeCode2 ) );
      }
      
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
      if( outcomeCode1 != NOT_OK )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {RApi::REngine::getPriceIncrInfo} failed" );
            throw ::Common::ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           outcomeCode2
                         );
         }
      }
   }

#endif

#if( /* {public RequestSubscribeInstrumentMarketDataIfNeeded}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::RequestSubscribeInstrumentMarketDataIfNeeded
      ( TInstrument const & instrument1,
        int instrumentMarketDataTypesBitMask
      )
   {
      int outcomeCode1;
      int outcomeCode2;

      {
         ::tsNCharcb exchangeAbbreviation1;
         PopulateTSNCharcb( exchangeAbbreviation1, instrument1.ExchangeAbbreviation() );
         ::tsNCharcb symbol1;
         PopulateTSNCharcb( symbol1, instrument1.Symbol() );
         TREngineAdapter & rEngineAdapter1( instrument1.BrokerAdapter() );
         ::RApi::REngine & rEngine1( rEngineAdapter1.REngine() );

         // {subscribeDC} would require us to maintain the order book. Actually it was eliminated.
         // Assuming {rEngine1} is locked.
         // When we call this twice in a row it sets {outcomeCode2 = API_ALREADY_EXISTS}.
         outcomeCode1 = rEngine1.subscribe
                                       ( ( & exchangeAbbreviation1 ),
                                         ( & symbol1 ),
                                         instrumentMarketDataTypesBitMask,
                                         ( & outcomeCode2 )
                                       );
      }

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
      if( outcomeCode1 != NOT_OK ||
         
          // yg? Not expecting the {API_IN_PROGRESS} error code.
          // yg? Consider logging a warning when {outcomeCode2} equals one of the ignored error codes.
          outcomeCode2 == API_ALREADY_EXISTS
        )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {RApi::REngine::subscribe} failed" );
            throw ::Common::ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           outcomeCode2
                         );
         }
      }
   }

#endif
#if( /* {public RequestUnsubscribeInstrumentMarketDataIfNeeded}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::RequestUnsubscribeInstrumentMarketDataIfNeeded
      ( TInstrument const & instrument1
      )
   {
      ::tsNCharcb exchangeAbbreviation1;
      PopulateTSNCharcb( exchangeAbbreviation1, instrument1.ExchangeAbbreviation() );
      ::tsNCharcb symbol1;
      PopulateTSNCharcb( symbol1, instrument1.Symbol() );
      TREngineAdapter & rEngineAdapter1( instrument1.BrokerAdapter() );
      ::RApi::REngine & rEngine1( rEngineAdapter1.REngine() );
      int outcomeCode2;

      // yg? Ignoring and not logging errors.
      // Let's hope that when the connection is broken and is being restored {::RApi::REngine} will be smart enough
      // to not restore this subscription upon a reconnection.
      // When we are not subscribed this sets {outcomeCode2 = API_ALREADY_EXISTS}.
      rEngine1.unsubscribe( ( & exchangeAbbreviation1 ), ( & symbol1 ), ( & outcomeCode2 ) );

      //::Sleep( 5000U );
      //int xxx( rEngine1.unsubscribe( ( & exchangeAbbreviation1 ), ( & symbol1 ), ( & outcomeCode2 ) ) );
   }

#endif

#if( /* {public RequestSubscribeOrdersStateUpdateIfNeeded}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::RequestSubscribeOrdersStateUpdateIfNeeded
      ( ::RApi::REngine & rEngine1,
        ::RApi::AccountInfo const & accountInfo1
      )
   {
      int outcomeCode1;
      int outcomeCode2;

      //try
      //{
         //outcomeCode1 = rEngine1.subscribeAccountDC( const_cast< ::RApi::AccountInfo * >( & accountInfo1 ), ( & outcomeCode2 ) );

         // Assuming {rEngine1} is locked.
         // When we call this twice in a row it sets {outcomeCode2 = API_ALREADY_EXISTS}.
         // yg? Doing {const_cast}.
         outcomeCode1 = rEngine1.subscribeOrder( const_cast< ::RApi::AccountInfo * >( & accountInfo1 ), ( & outcomeCode2 ) );
      //}
      //catch( ::OmneException const & exception1 )
      //{
         //>>>Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      //   throw TOmneException( exception1 );
      //}

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
      if( outcomeCode1 != NOT_OK ||
         
          // yg? Not expecting the {API_IN_PROGRESS} error code.
          // yg? Consider logging a warning when {outcomeCode2} equals one of the ignored error codes.
          outcomeCode2 == API_ALREADY_EXISTS
        )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {RApi::REngine::subscribeOrder} failed" );
            throw ::Common::ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           outcomeCode2
                         );
         }
      }
   }

#endif
#if( /* {public SendOrder}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::SendOrder
      ( TSingleInstrumentOrder & order1
      )
   {
      order1.PrepareSend();

      {
         int outcomeCode2;

         // yg? Doing {const_cast}.
         int outcomeCode1( order1.Instrument().BrokerAdapter().REngine().sendOrderList
                                           ( const_cast< ::RApi::OrderParams * >( & order1.OrderParams() ), 1, ( & outcomeCode2 ) )
                                     );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
         if( outcomeCode1 != NOT_OK )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

            {
               static char const constantString1AsArray[]( "Critical; {RApi::REngine::sendOrderList} failed" );
               throw ::Common::ErrorHandling::TCriticalErrorException
                            ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                              outcomeCode2
                            );
            }
         }
      }

      //// Assuming no callback will be called before this statement executes, which is guaranteed if this method is called from within a locked scope.
      //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( order1.StateCode == TOrderStateCode_None );
      //order1.StateCode = TOrderStateCode_Sent;
   }

#endif
#if( /* {public SendOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline void TRApiHelpers::SendOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      )
   {
      // TODO 3 yg? Optimize this to send all orders in a single batch.

   #if( 1 )
      // TODO 2 yg? Remember to {..._ASSUME} this if possible before calling {SendOrders}.
//TODO see prev line
      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )

      {
         SendOrder( * * orders1BeginIterator );
      }
   #else
      // yg? Sending orders in the reverse order.
      {
         // TODO 2 yg? Remember to {..._ASSUME} this if possible before calling {SendOrders}.
         while( orders1BeginIterator != orders1EndIterator )
         {
            -- orders1EndIterator;
            SendOrder( * * orders1EndIterator );
         }
      }
   #endif
   }

#endif
#if( /* {public RequestModifyOrder}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //void TRApiHelpers::RequestModifyOrder
   //   ( TSingleInstrumentOrder & order1
   //   )
   //{
   //   order1.PrepareRequestModify();

   //   {
   //      int outcomeCode2;

   //      // yg? Doing {const_cast}.
   //      int outcomeCode1( order1.Instrument().BrokerAdapter().REngine().modifyOrder
   //                                        ( const_cast< ::RApi::ModifyOrderParams * >( & order1.ModifyOrderParams() ), ( & outcomeCode2 ) )
   //                                  );

   //      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
   //      if( outcomeCode1 != NOT_OK )
   //      {
   //         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //      }
   //      else
   //      {
   //         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

   //         {
   //            static char const constantString1AsArray[]( "Critical; {RApi::REngine::modifyOrder} failed" );
   //            throw ::Common::ErrorHandling::TCriticalErrorException
   //                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
   //                           outcomeCode2
   //                         );
   //         }
   //      }
   //   }
   //}

#endif
#if( /* {public RequestModifyOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline void TRApiHelpers::RequestModifyOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      )
   {
      // Declaring this here to make it clear that this memory will be freed only on return.
      char * buffer1;

      int outcomeCode1;
      int outcomeCode2;

      {
         // This is probably signed but this code would work even if this was unsigned.
         auto numberOrders( orders1EndIterator - orders1BeginIterator );

         static_assert( sizeof( numberOrders ) >= sizeof( int ), "" );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberOrders >= 0 );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( numberOrders < ::std::numeric_limits< int >::max() / ( 2 * static_cast< int >( sizeof( ::RApi::ModifyOrderParams ) ) ) );

         // This is needed to safely assume that we have at least 1 order,
         // which in turn is needed to get its {Instrument().BrokerAdapter()}.
         // TODO 2 yg? Remember to {..._ASSUME} this if possible before calling {RequestModifyOrders}.
//TODO see prev line
         if( static_cast< int >( numberOrders ) > 0 )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            return;
         }

         // Assuming this will not overflow, as validated.
         int buffer1Length
            ( static_cast< int >
                 ( static_cast< unsigned int >( sizeof( ::RApi::ModifyOrderParams ) ) * static_cast< unsigned int >( numberOrders ) )
            );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( buffer1Length > 0 );
         buffer1 = reinterpret_cast< char * >( ::_alloca( static_cast< unsigned int >( buffer1Length ) ) );

         // yg? We don't call {::RApi::ModifyOrderParams} constructor and destructor.
         // yg? A way to call them would be to use a placement {operator new[]} and {operator delete[]}.
         // yg? Assuming the constructor only zeroes out memory and the destructor does nothing.
         // yg? The destructor is virtual but the virtual table pointer remains uninitialized.
         ::RApi::ModifyOrderParams * modifyOrderParamsArray( reinterpret_cast< ::RApi::ModifyOrderParams * >( buffer1 ) );

         // We need this instrument sooner to make some validations.
         // We need to use {orders1BeginIterator} before advancing it.
         // Note that at this point we know that we have at least 1 order.
         TInstrument const & instrument( ( * orders1BeginIterator )->Instrument() );

         {
            ::RApi::ModifyOrderParams * modifyOrderParamsArrayItemPointer( modifyOrderParamsArray );
            do
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( orders1BeginIterator != orders1EndIterator );

               //RequestModifyOrder( * * orders1BeginIterator );

               // All orders shall belong to the same broker adapter.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                  ( ( & ( * orders1BeginIterator )->Instrument().BrokerAdapter() ) == ( & instrument.BrokerAdapter() ) );

               ( * orders1BeginIterator )->PrepareRequestModify();

               // yg? This calls the autogenerated {::RApi::ModifyOrderParams} assignment operator.
               // yg? It probably doesn't copy the virtual table pointer, and it doesn't matter.
               // yg? This copying is inefficient.
               // TODO 3 yg? We need to pre-allocate and pre-populate a collection of {::RApi::ModifyOrderParams}.
               ( * modifyOrderParamsArrayItemPointer ) = ( * orders1BeginIterator )->ModifyOrderParams();

               ++ modifyOrderParamsArrayItemPointer;
               ++ orders1BeginIterator;
            }
            while( orders1BeginIterator != orders1EndIterator );
         }

         outcomeCode1 =
            instrument.BrokerAdapter().REngine().modifyOrderList
               ( modifyOrderParamsArray, static_cast< int >( numberOrders ), ( & outcomeCode2 ) );
      }

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
      if( outcomeCode1 != NOT_OK )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {RApi::REngine::modifyOrderList} failed" );
            throw ::Common::ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           outcomeCode2
                         );
         }
      }
   }

#endif
#if( /* {public RequestCancelOrder}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //void TRApiHelpers::RequestCancelOrder
   //   ( TSingleInstrumentOrder & order1
   //   )
   //{
   //   order1.PrepareRequestCancel();
   //
   //   {
   //      int outcomeCode1;
   //      int outcomeCode2;

   //      {
   //         // yg? Doing {const_cast}.
   //         ::tsNCharcb userMessage = { const_cast< char * >( & order1.LastCancellationRequestId() ), 1 };

   //         TInstrument const & instrument1( order1.Instrument() );
   //         TREngineAdapter & rEngineAdapter1( instrument1.BrokerAdapter() );
   //         ::RApi::REngine & rEngine1( rEngineAdapter1.REngine() );

   //         // yg? {cancelOrderDC} was eliminated.
   //         // yg? Doing {const_cast}.
   //         outcomeCode1 =
   //            rEngine1.cancelOrder
   //               ( const_cast< ::RApi::AccountInfo * >( & rEngineAdapter1.AccountInfo() ),
   //                 order1.BrokerGeneratedId,
   //                 const_cast< ::tsNCharcb * >( & ::RApi::sORDER_ENTRY_TYPE_AUTO ),
   //                 ( & userMessage ),

   //                 // TODO 3 yg? Hack. Instead we should generate an integer order ID.
   //                 reinterpret_cast< void * >( & order1 ),

   //                 ( & outcomeCode2 )
   //               );
   //      }

   //      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
   //      if( outcomeCode1 != NOT_OK )
   //      {
   //         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
   //      }
   //      else
   //      {
   //         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

   //         {
   //            static char const constantString1AsArray[]( "Critical; {RApi::REngine::cancelOrder} failed" );
   //            throw ::Common::ErrorHandling::TCriticalErrorException
   //                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
   //                           outcomeCode2
   //                         );
   //         }
   //      }
   //   }
   //}

#endif
#if( /* {public RequestCancelOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline void TRApiHelpers::RequestCancelOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      )
   {
      // Declaring this here to make it clear that this memory will be freed only on return.
      char * buffer1;

      int outcomeCode1;
      int outcomeCode2;

      {
         // This is probably signed but this code would work even if this was unsigned.
         auto numberOrders( orders1EndIterator - orders1BeginIterator );

         static_assert( sizeof( numberOrders ) >= sizeof( int ), "" );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberOrders >= 0 );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
            ( numberOrders <
              ( ::std::numeric_limits< int >::max() /
                ( 2 * static_cast< int >( sizeof( ::RApi::AccountInfo ) + sizeof( int ) + sizeof( ::tsNCharcb ) * 2U + sizeof( void * ) ) )
              )
            );

         // This is needed to safely assume that we have at least 1 order,
         // which in turn is needed to get its {Instrument().BrokerAdapter()}.
         // TODO 2 yg? Remember to {..._ASSUME} this if possible before calling {RequestCancelOrders}.
//TODO see prev line
         if( static_cast< int >( numberOrders ) > 0 )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            return;
         }

         // Assuming this will not overflow, as validated.
         int buffer1Length
            ( static_cast< int >
                 ( static_cast< unsigned int >( sizeof( ::RApi::AccountInfo ) + sizeof( int ) + sizeof( ::tsNCharcb ) * 2U + sizeof( void * ) ) *
                   static_cast< unsigned int >( numberOrders )
                 )
            );

         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( buffer1Length > 0 );
         buffer1 = reinterpret_cast< char * >( ::_alloca( static_cast< unsigned int >( buffer1Length ) ) );

         // yg? See a comment in {TRApiHelpers::RequestModifyOrders} regarding {modifyOrderParamsArray}.
         ::RApi::AccountInfo * accountInfoArray( reinterpret_cast< ::RApi::AccountInfo * >( buffer1 ) );

         int * orderNumberArray
            ( reinterpret_cast< int * >
                 ( reinterpret_cast< char * >( accountInfoArray ) +
                   static_cast< int >( static_cast< unsigned int >( sizeof( * accountInfoArray ) ) * static_cast< unsigned int >( numberOrders ) )
                 )
            );
         ::tsNCharcb * entryTypeArray
            ( reinterpret_cast< ::tsNCharcb * >
                 ( reinterpret_cast< char * >( orderNumberArray ) +
                   static_cast< int >( static_cast< unsigned int >( sizeof( * orderNumberArray ) ) * static_cast< unsigned int >( numberOrders ) )
                 )
            );
         ::tsNCharcb * userMessageArray
            ( reinterpret_cast< ::tsNCharcb * >
                 ( reinterpret_cast< char * >( entryTypeArray ) +
                   static_cast< int >( static_cast< unsigned int >( sizeof( * entryTypeArray ) ) * static_cast< unsigned int >( numberOrders ) )
                 )
            );

         // yg? Initialization doesn't compile, using assignment.
         void * * contextArray =
            ( reinterpret_cast< void * * >
                 ( reinterpret_cast< char * >( userMessageArray ) +
                   static_cast< int >( static_cast< unsigned int >( sizeof( * userMessageArray ) ) * static_cast< unsigned int >( numberOrders ) )
                 )
            );

         // We need this instrument sooner to make some validations.
         // We need to use {orders1BeginIterator} before advancing it.
         // Note that at this point we know that we have at least 1 order.
         TInstrument const & instrument( ( * orders1BeginIterator )->Instrument() );

         {
            ::RApi::AccountInfo * accountInfoArrayItemPointer( accountInfoArray );
            int * orderNumberArrayItemPointer( orderNumberArray );
            ::tsNCharcb * entryTypeArrayItemPointer( entryTypeArray );
            ::tsNCharcb * userMessageArrayItemPointer( userMessageArray );

            // yg? Initialization doesn't compile, using assignment.
            void * * contextArrayItemPointer = ( contextArray );

            do
            {
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( orders1BeginIterator != orders1EndIterator );

               // All orders shall belong to the same broker adapter.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                  ( ( & ( * orders1BeginIterator )->Instrument().BrokerAdapter() ) == ( & instrument.BrokerAdapter() ) );

               ( * orders1BeginIterator )->PrepareRequestCancel();

               // We validated that all orders belong to the same broker adapter,
               // so it's safe (and probably more efficient) to use the 1st order's one for all orders.
               // yg? See a comment in {TRApiHelpers::RequestModifyOrders}
               // yg? regarding the autogenerated {::RApi::ModifyOrderParams} assignment operator.
               ( * accountInfoArrayItemPointer ) = instrument.BrokerAdapter().AccountInfo();

               ( * orderNumberArrayItemPointer ) = ( * orders1BeginIterator )->BrokerGeneratedId;
               ( * entryTypeArrayItemPointer ) = ::RApi::sORDER_ENTRY_TYPE_AUTO;

               // yg? Doing {const_cast}.
               userMessageArrayItemPointer->pData = const_cast< char * >( & ( * orders1BeginIterator )->LastCancellationRequestId() );

               userMessageArrayItemPointer->iDataLen = 1;

               // TODO 3 yg? Hack. Instead we should generate an integer order ID.
               ( * contextArrayItemPointer ) = reinterpret_cast< void * >( * orders1BeginIterator );

               ++ accountInfoArrayItemPointer;
               ++ orderNumberArrayItemPointer;
               ++ entryTypeArrayItemPointer;
               ++ userMessageArrayItemPointer;
               ++ contextArrayItemPointer;
               ++ orders1BeginIterator;
            }
            while( orders1BeginIterator != orders1EndIterator );
         }

         outcomeCode1 = instrument.BrokerAdapter().REngine().cancelOrderList( accountInfoArray,
                                                                                                                           orderNumberArray,
                                                                                                                           entryTypeArray,
                                                                                                                           userMessageArray,
                                                                                                                           contextArray,
                                                                                                                           static_cast< int >( numberOrders ),
                                                                                                                           ( & outcomeCode2 )
                                                                                                                         );
      }

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
      if( outcomeCode1 != NOT_OK )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {RApi::REngine::cancelOrderList} failed" );
            throw ::Common::ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           outcomeCode2
                         );
         }
      }
   }

#endif
#if( /* {public RequestCancelOrderIfCan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TRApiHelpers::RequestCancelOrderIfCan
      ( TSingleInstrumentOrder & order1
      )
   {
      //TODO Assumption: we sent this order. -- we don't actually need to assume this?
      //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( order1.StateBitMask &
      //                                                                                     ( TOrderStateBitMask_NewOrderRequestPending |
      //                                                                                       TOrderStateBitMask_NewOrderRequestReceivedByBroker
      //                                                                                     )
      //                                                                                   ) !=
      //                                                                                   TOrderStateBitMask_None
      //                                                                                );
      bool canCancelOrder( TSingleInstrumentOrderHelpers::CanCancelOrder( order1 ) );
      
      if( canCancelOrder )
      {
         RequestCancelOrder( order1 );
      }
      else
      {
//TODO Write a better comment that not setting the {TOrderStateBitMask_ShallBeCancelled} bit.
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      return canCancelOrder;
   }

#endif
#if( /* {public RequestCancelOrderIfInternalCan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TRApiHelpers::RequestCancelOrderIfInternalCan
      ( TSingleInstrumentOrder & order1
      )
   {
      bool internalCanCancelOrder( TSingleInstrumentOrderHelpers::InternalCanCancelOrder( order1 ) );
      
      if( internalCanCancelOrder )
      {
         RequestCancelOrder( order1 );
      }
      else
      {
//TODO Write a better comment that not setting the {TOrderStateBitMask_ShallBeCancelled} bit.
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      return internalCanCancelOrder;
   }

#endif
#if( /* {public RequestCancelOrderIfInternalShallAndCan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TRApiHelpers::RequestCancelOrderIfInternalShallAndCan
      ( TSingleInstrumentOrder & order1
      )
   {
//TODO better comment: and here we do need this assumption as we are not supposed to set any {order1.StateBitMask} bits before w send the order.
//TODO actually no!!! we dont need this assumption
//TODO move this validation to RequestCancelOrderWhenCan -- done
      //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( order1.StateBitMask &
      //                                                                                     ( TOrderStateBitMask_NewOrderRequestPending |
      //                                                                                       TOrderStateBitMask_NewOrderRequestReceivedByBroker
      //                                                                                     )
      //                                                                                   ) !=
      //                                                                                   TOrderStateBitMask_None
      //                                                                                );
      bool shallAndInternalCanCancelOrder( TSingleInstrumentOrderHelpers::ShallAndInternalCanCancelOrder( order1 ) );
      
      if( shallAndInternalCanCancelOrder )
      {
         RequestCancelOrder( order1 );
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }

      return shallAndInternalCanCancelOrder;
   }

#endif
#if( /* {public RequestCancelOrderWhenCan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TRApiHelpers::RequestCancelOrderWhenCan
      ( TSingleInstrumentOrder & order1
      )
   {
//TODO move the validation from RequestCancelOrderIfInternalShallAndCan to here -- done
//TODO review comments

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( ( order1.StateBitMask &
                                                                                           ( TOrderStateBitMask_NewOrderRequestPending |
                                                                                             TOrderStateBitMask_NewOrderRequestReceivedByBroker
                                                                                           )
                                                                                         ) !=
                                                                                         TOrderStateBitMask_None
                                                                                      );

      // Doing this unconditionally.
      // Another option would be to do this only if we can't send a cancellation request and the order is not complete yet.
      // yg? {RequestCancelOrderIfCan} is going to set some bits too, so it would be more efficient to combine these sets.
      // yg? Although the compiler can actually optimize this.
      // yg? Another option would be to unconditionally set this bit when requesting to cancel an order
      // yg? but we would still need to set it in case we can't immediatelly send a cancellation request,
      // yg? which can take more CPU cycles.
      order1.StateBitMask = static_cast< TOrderStateBitMask >( order1.StateBitMask | TOrderStateBitMask_ShallBeCancelled );

      // This validates {order1.StateBitMask} and the above modification of it doesn't break the validation.
//TODO not validatest any more?
      return RequestCancelOrderIfCan( order1 );
   }

#endif
#if( /* {public RequestCancelAnyOrders}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TRApiHelpers::RequestCancelAnyOrders
      ( ::RApi::REngine & rEngine1,
        ::RApi::AccountInfo const & accountInfo1
      )
   {
      int outcomeCode2;

      // yg? Doing {const_cast}.
      int outcomeCode1
         ( rEngine1.cancelAllOrders
              ( const_cast< ::RApi::AccountInfo * >( & accountInfo1 ),
                const_cast< ::tsNCharcb * >( & ::RApi::sORDER_ENTRY_TYPE_AUTO ),
                ( & outcomeCode2 )
              )
         );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( outcomeCode1 == OK || outcomeCode1 == NOT_OK );
      if( outcomeCode1 != NOT_OK )
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {RApi::REngine::cancelAllOrders} failed" );
            throw ::Common::ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           outcomeCode2
                         );
         }
      }
   }

#endif
#if( /* {public RequestCancelAnyOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TSingleInstrumentsOrdersPointerIterator_
   //   >
   inline void TRApiHelpers::RequestCancelAnyOrders
      ( ::RApi::REngine & rEngine1,
        ::RApi::AccountInfo const & accountInfo1,
        //TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        //TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
        ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > > & orders1
      )
   {
      RequestCancelAnyOrders( rEngine1, accountInfo1 );
      TSingleInstrumentOrderHelpers::RegisterRequestCancelOrdersAsAnyIfCan( /*orders1BeginIterator, orders1EndIterator*/ orders1 );
   }

#endif
}
