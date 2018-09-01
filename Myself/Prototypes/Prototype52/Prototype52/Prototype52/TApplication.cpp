#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TApplication.hpp"

#include "../Common/ErrorHandling/TErrorHandlerScope.cpp"
#include "../Common/Processes/TProcessHelpers.cpp"
#include "../Common/Time/TMultimediaTimerResolutionMillisecondsScope.cpp"
#include "../Common/DataFormatting/TDataFormattingHelpers.cpp"
#include "./TTradingSystemHelpers.cpp"
#include "./TApplicationConfigurationHelpers.cpp"
#if( YURIYGULYAYEV_TESTMODECODE() != 0 )
   //#include "../Common/Time/TDateTimeKeeperTestingHelpers.cpp"
   //#include "../RApiFacade/TTestingHelpers.cpp"
   //#include "./TNaturalGasStorageReportDownloaderTestingHelpers.cpp"
#endif

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TApplication::TApplication()
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(protected)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {protected initialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TApplication::initialize
      ( ::Poco::Util::Application & self
      )
   {
      // There is no need to handle exceptions.
      // Reinitialization will probably not work. It would be nice to throw an exception if someone tries to reinitialize us.

      ErrorHandlerScope_.SetErrorHandler();

      // This is needed for the sleeping with {::select}, which is in turn used by {::Common::ErrorHandling::TErrorHandler}.
      // Actually, {::Common::ErrorHandling::TErrorHandler} doesn't sleep with {::select} any more,
      // so we call {ErrorHandlerScope_.SetErrorHandler} above, but we still sleep all over the place.
      // This does nothing on Linux.
      // TODO 3 yg? We need a separate assembly initialization method for this and other initializations.
      ::Poco::Net::initializeNetwork();

      {
         static char const constantString1AsArray[]( "application.argv[1]" );
         ::std::string string1( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) );

         {
            static char const constantString2AsArray[]( "application.argv[2]" );

            if( config().hasProperty( string1 ) &&
                ( ! config().hasProperty( ::std::string( constantString2AsArray, ( sizeof( constantString2AsArray ) / sizeof( constantString2AsArray[ 0U ] ) - 1U ) ) ) )
              )
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
            }
            else
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

               {
                  // yg? Would be better if this said "Usage: ..."?
                  static char const constantString5AsArray[]( "Error; provide a single configuration file name in command line" );

                  // This is really a critical, if not fatal error but let's not scare the user.
                  throw ::Common::ErrorHandling::TRegularErrorException
                               ( ::std::string( constantString5AsArray, ( sizeof( constantString5AsArray ) / sizeof( constantString5AsArray[ 0U ] ) - 1U ) ),
                                 0
                               );
               }
            }
         }
         
         {
            // yg? Consider moving this out of the "logging" configuration.
            static char const constantString3AsArray[]( "logging.dateTimeStampForLogFileName" );

            // TODO 3 yg? Configure/implement log file rollover. But do I really need it?
            // yg? Using current thread locale.
            config().setString
               ( ::std::string( constantString3AsArray, ( sizeof( constantString3AsArray ) / sizeof( constantString3AsArray[ 0U ] ) - 1U ) ),
                 ::Poco::DateTimeFormatter::format
                    ( ::Poco::LocalDateTime( startTime() ),
                      ::Common::DataFormatting::TDataFormattingHelpers::DateTimeSecondResolutionFormatForFileNameString
                    )
               );
         }
         
         loadConfiguration( config().getString( string1 ) );
      }

      ::Poco::Util::Application::initialize( self );
   }

#endif
#if( /* {protected uninitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TApplication::uninitialize()
   {
      // It would be nice to handle exceptions here and make a best effort to execute each step.

      ::Poco::Util::Application::uninitialize();

      ::Poco::Net::uninitializeNetwork();
      ErrorHandlerScope_.RestoreErrorHandler();
   }

#endif
#if( /* {protected main}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   int TApplication::main
      ( ::std::vector< ::std::string > const & //arguments
      )
   {
      // There is no need to handle exceptions.

      //::Poco::Util::Application::main

      // yg? Magic number hardcoded.
      int const multimediaTimerResolutionMilliseconds( 1 );
      ::Common::Time::TMultimediaTimerResolutionMillisecondsScope multimediaTimerResolutionMillisecondsScope
         ( multimediaTimerResolutionMilliseconds );

      {
         static char const constantString1AsArray[]( "the application is starting; if it crashes examine the operating system event log; " __DATE__ " " __TIME__ );
         ::Poco::Logger & logger1( logger() );
         logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

   #if( YURIYGULYAYEV_TESTMODECODE() == 0 )

      {
         TApplicationConfiguration applicationConfiguration;
         TApplicationConfigurationHelpers::ExtractConfiguration( applicationConfiguration, config() );
         applicationConfiguration.Validate();

      #if( defined( _MSC_VER ) )
         // TODO 2 yg? Hack. These parameters probably need to be in the configuration.
         // Perhaps the app should refuse to run if this fails. But this can fail if the user has no administrative privileges.
         ::Common::Processes::TProcessHelpers::TrySetProcessWorkingSetSize
            ( ::GetCurrentProcess(), 128U * 1024U * 1024U, 128U * 1024U * 1024U );
      #elif( defined( __GNUC__ ) )
         #error yg?? ToDo
      #else
         #error ...
      #endif

//TODO remove (don't review this, just remove)
         //// It's OK if the collection is empty but it would make little sense.
         //for( ::std::vector< ::std::unique_ptr< TTradingSystemConfiguration > >::iterator tradingSystemsConfigurationIterator
         //         ( applicationConfiguration.TradingSystemsConfiguration.begin() ) ;
         //       tradingSystemsConfigurationIterator != applicationConfiguration.TradingSystemsConfiguration.end() ;
         //       ++ tradingSystemsConfigurationIterator
         //    )
         //{
         //   TTradingSystemHelpers::CreateAndRunTradingSystem( ::std::move( * tradingSystemsConfigurationIterator ) );
         //}

         // We can't use const iterators here.
         TTradingSystemHelpers::CreateAndRunTradingSystems
            ( applicationConfiguration.TradingSystemsConfiguration.begin(), applicationConfiguration.TradingSystemsConfiguration.end() );
      }

   #else

   #endif
      
      {
         static char const constantString1AsArray[]( "the application is terminating" );
         ::Poco::Logger & logger1( logger() );
         logger1.information( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
      }

      return ExitCode::EXIT_OK;
   }

#endif
}
