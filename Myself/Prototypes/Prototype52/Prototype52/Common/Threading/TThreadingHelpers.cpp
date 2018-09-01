#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TThreadingHelpers.hpp"

#include "../Time/TTimeHelpers.cpp"
#include "../Networking/TNetworkingHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Threading
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

#if( /* {public SleepMillisecond}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TThreadingHelpers::SleepMillisecond()
   {
   #if( defined( _MSC_VER ) )
      // yg? Hack -- revisit.
//todo everywhere when sleeping for microseconds sleep by {::Poco::Timespan::MILLISECONDS + 0 / 2} less.
//todo everywhere when sleeping for milliseconds sleep by a half of a millisecond less.
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
      Networking::TNetworkingHelpers::DoSleepMicrosecondsWithSelect( static_cast< long >( ::Poco::Timespan::MILLISECONDS ) / 2 + 1 );

      return true;
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
      // yg? An interruption by a signal could inflict damage here.
      // yg? {::usleep} is deprecated, use {::nanosleep}.
      // yg? {::usleep} can return an error code -- handle it.
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
      ::usleep( static_cast< unsigned long >( ::Poco::Timespan::MILLISECONDS ) / 2U + 1U );
      return ???
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public SleepMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TThreadingHelpers::SleepMilliseconds
      ( int timeSpanMilliseconds
      )
   {
      if( timeSpanMilliseconds > 0 )
      {
         DoSleepMilliseconds( timeSpanMilliseconds );
      }
      else
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
   }

#endif
#if( /* {public DoSleepMilliseconds}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TThreadingHelpers::DoSleepMilliseconds
      ( int timeSpanMilliseconds
      )
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( timeSpanMilliseconds > 0 );
   #if( defined( _MSC_VER ) )
      int endTimeMilliseconds( Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() + timeSpanMilliseconds );
      if( timeSpanMilliseconds == 1 )
      {
         SleepMillisecond();
      }
      else
      {
         ::Poco::Thread::sleep( timeSpanMilliseconds - 1 );
      }
      timeSpanMilliseconds = endTimeMilliseconds - Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds();
      assert( timeSpanMilliseconds <= 1 );
      if( timeSpanMilliseconds > 0 )
      {
         SleepMillisecond();
      }
      
      // yg? This validation fails when the millisecond time is not incremented on a multimedia timer tick that in turn ticks 1024 times a second.
      // yg? In that case it would be more correct to call {SleepMillisecond} once more but keeping it simple.
      //assert( endTimeMilliseconds - Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() <= 0 );

   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
      // yg? Consider doing {::usleep(timeSpanMilliseconds*1000-499} and handle interruptions by a signal.
   //#if( defined( _MSC_VER ) )
      if( timeSpanMilliseconds == 1 )
      {
         // yg? On Windows this cannot be interrupted.
//>>>>>>incorrect because the time can stay unchanged
         SleepMillisecond();

         return;
      }
   //#elif( defined( __GNUC__ ) )
   //#else
   //   #error ...
   //#endif
      int endTimeMilliseconds( Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() + timeSpanMilliseconds );
      if( timeSpanMilliseconds > 1 )
      {
         // yg? The Windows {::Sleep} function often oversleeps by a millisecond.
         // yg? It's because the multimedia timer ticks 1024 times a second and {::Sleep} is guaranteed to sleep for at least the given milliseconds.
         // yg? To increase the chance of not oversleeping, consider sleeping by another millisecond less here.
         ::Poco::Thread::sleep( timeSpanMilliseconds - 1 );

         goto label1;
      }
      do
      {
         if( SleepMillisecond() && timeSpanMilliseconds == 1 )
         {
            break;
         }
      label1:
         timeSpanMilliseconds = endTimeMilliseconds - Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds();
      }
      while( timeSpanMilliseconds > 0 );
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public SleepUntilMultimediaTimeMilliseconds}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TThreadingHelpers::SleepUntilMultimediaTimeMilliseconds
      ( int endTimeMilliseconds
      )
   {
   #if( defined( _MSC_VER ) )
      int timeSpanMilliseconds( endTimeMilliseconds - Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
      if( timeSpanMilliseconds <= 0 )
      {
         return;
      }
      if( timeSpanMilliseconds == 1 )
      {
         SleepMillisecond();
      }
      else
      {
         ::Poco::Thread::sleep( timeSpanMilliseconds - 1 );
      }
      timeSpanMilliseconds = endTimeMilliseconds - Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds();
      assert( timeSpanMilliseconds <= 1 );
      if( timeSpanMilliseconds > 0 )
      {
         SleepMillisecond();
      }

      // yg? This validation fails when the millisecond time is not incremented on a multimedia timer tick that in turn ticks 1024 times a second.
      // yg? In that case it would be more correct to call {SleepMillisecond} once more but keeping it simple.
      //assert( endTimeMilliseconds - Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() <= 0 );

   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
      // yg? Consider doing {::usleep(timeSpanMilliseconds*1000-499} and handle interruptions by a signal.
      int timeSpanMilliseconds( endTimeMilliseconds - Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
      if( timeSpanMilliseconds <= 0 )
      {
         return;
      }
      if( timeSpanMilliseconds > 1 )
      {
         // yg? The Windows {::Sleep} function often oversleeps by a millisecond.
         // yg? It's because the multimedia timer ticks 1024 times a second and {::Sleep} is guaranteed to sleep for at least the given milliseconds.
         // yg? To increase the chance of not oversleeping, consider sleeping by another millisecond less here.
         ::Poco::Thread::sleep( timeSpanMilliseconds - 1 );

         goto label2;
      }
      do
      {
         if( SleepMillisecond() && timeSpanMilliseconds == 1 )
         {
            break;
         }
      label2:
         timeSpanMilliseconds = endTimeMilliseconds - Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds();
      }
      while( timeSpanMilliseconds > 0 );
   #else
      #error ...
   #endif
   }

#endif
}
}
