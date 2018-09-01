#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TTimeHelpers.hpp"

#include "../ErrorHandling/TCriticalErrorException.cpp"
#include "../Diagnostics/Macros.cpp"
#include "../Diagnostics/TDiagnosticsHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Time
{
#if( /* {public MinDateTime}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   ::Poco::DateTime const TTimeHelpers::MinDateTime( 0, 1, 1 );

#endif
#if( /* {public MinTimeStamp}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   ::Poco::Timestamp const TTimeHelpers::MinTimeStamp( MinDateTime.timestamp() );

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

#if( /* {public GetCpuTimeStampCounter}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::Poco::Int64 TTimeHelpers::GetCpuTimeStampCounter()
   {
      auto cpuTimeStampCounter
   #if( defined( _MSC_VER ) )
         ( ::__rdtsc() );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
      static_assert( sizeof( cpuTimeStampCounter ) == sizeof( ::Poco::Int64 ), "" );
      return static_cast< ::Poco::Int64 >( cpuTimeStampCounter );
   }

#endif

#if( /* {public AtomicSetMultimediaTimerResolutionMilliseconds}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTimeHelpers::AtomicSetMultimediaTimerResolutionMilliseconds
      ( int multimediaTimerResolutionMilliseconds1
      )
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( multimediaTimerResolutionMilliseconds1 >= 0 );

   #if( defined( _MSC_VER ) )
      static_assert( sizeof( multimediaTimerResolutionMilliseconds1 ) <= sizeof( ::UINT ), "" );

      // This is not needed if we call {::timeSetEvent}.
      ::MMRESULT outcomeCode( ::timeBeginPeriod( static_cast< unsigned int >( multimediaTimerResolutionMilliseconds1 ) ) );

      if( outcomeCode != static_cast< ::MMRESULT >( TIMERR_NOERROR ) )
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {timeBeginPeriod} failed" );
            throw ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           static_cast< int >( outcomeCode )
                         );
         }
      }
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
      // yg? If this method becomes empty I would need to make it inline.
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public AtomicRestoreMultimediaTimerResolutionMilliseconds}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTimeHelpers::AtomicRestoreMultimediaTimerResolutionMilliseconds
      ( int multimediaTimerResolutionMilliseconds1
      )
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( multimediaTimerResolutionMilliseconds1 >= 0 );

   #if( defined( _MSC_VER ) )
      static_assert( sizeof( multimediaTimerResolutionMilliseconds1 ) <= sizeof( ::UINT ), "" );
      ::MMRESULT outcomeCode( ::timeEndPeriod( static_cast< unsigned int >( multimediaTimerResolutionMilliseconds1 ) ) );
      if( outcomeCode != static_cast< ::MMRESULT >( TIMERR_NOERROR ) )
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

         {
            static char const constantString1AsArray[]( "Critical; {timeEndPeriod} failed" );
            throw ErrorHandling::TCriticalErrorException
                         ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                           static_cast< int >( outcomeCode )
                         );
         }
      }
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
      // yg? If this method becomes empty I would need to make it inline.
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public GetMultimediaCurrentTimeMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TTimeHelpers::GetMultimediaCurrentTimeMilliseconds/*AsInt32*/()
   {
   #if( defined( _MSC_VER ) )
      // TODO 3 yg? Consider using {decltype( ::timeGetTime() )} here but double-check that it's not an rvalue reference.
      // TODO 3 yg? See {Test12} in "CPlusPlusTest1".
      // TODO 3 yg? Read help about {decltype}.
      // TODO 3 yg? See {GetCpuTimeStampCounter}.
      static_assert( sizeof( ::DWORD ) >= sizeof( int ), "" );

      return static_cast< int >( ::timeGetTime() );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
}
}
