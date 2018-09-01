#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TErrorHandlingHelpers.hpp"

//#include "../Threading/TThreadingHelpers.cpp"
#include "../CodeOptimization/Macros.cpp"
#include "../Diagnostics/TDiagnosticsHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ErrorHandling
{
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

   inline void TErrorHandlingHelpers::AtomicLastChanceHandleException
      ( ::Poco::Exception const & exception1
      )
   {
      try
      {
         ::Poco::Util::Application::instance().logger().fatal( exception1.displayText() );

         // Sleeping to give the logger a chance to log the message on a thread pool thread.
         //// yg? We could sleep for 2 multimedia timer ticks but I don't want to allow the corrupt app to keep running that long.
         //Threading::TThreadingHelpers::SleepMillisecond();
         ::Poco::Thread::sleep( 1 );

         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }
      catch( ... )
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      ::std::abort();

      // yg? Consider using { __declspec( noreturn ) }.
      // yg? Why {::std::abort} is not declared that way? Maybe because in debug build it probably can return.
      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   }

#endif
#if( /* {public AtomicLastChanceHandleException}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TErrorHandlingHelpers::AtomicLastChanceHandleException
      ( ::std::exception const & exception1
      )
   {
      try
      {
         // The C++ standard requires {::std::exception::what()} to be a valid NTBS. If it's a {nullptr} we would crash.
         ::Poco::Util::Application::instance().logger().fatal( ::std::string( exception1.what() ) );

         // See a related comment in the 1st overload above.
         //Threading::TThreadingHelpers::SleepMillisecond();
         ::Poco::Thread::sleep( 1 );

         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }
      catch( ... )
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      ::std::abort();

      // yg? See a related comment in the 1st overload above.
      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   }

#endif
#if( /* {public AtomicLastChanceHandleException}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TErrorHandlingHelpers::AtomicLastChanceHandleException()
   {
      try
      {
         {
            static char const constantString1AsArray[]( "a non-exception was thrown" );
            ::Poco::Util::Application::instance().logger().fatal( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
         }

         // See a related comment in the 1st overload above.
         //Threading::TThreadingHelpers::SleepMillisecond();
         ::Poco::Thread::sleep( 1 );

         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }
      catch( ... )
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      }

      ::std::abort();

      // yg? See a related comment in the 1st overload above.
      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   }

#endif
}
}
