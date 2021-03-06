#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace Time
{
   // yg? Consider using the word "thread time slice".

   class TMultimediaTimerResolutionMillisecondsScope
   {
#if( /* {private MultimediaTimerResolutionMilliseconds_}. */ 1 )

      // When this value is negative we will not restore the timer resolution.
      // yg? See a comment in the constructor.
      private: int MultimediaTimerResolutionMilliseconds_;

#endif

#if( /* //{(private)} Instance default constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TMultimediaTimerResolutionMillisecondsScope
         ( TMultimediaTimerResolutionMillisecondsScope const & source
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      // Assumption: {multimediaTimerResolutionMilliseconds1 >= 0}.
      // The value of 0 will probably not work but it's reserved to denote the maximum possible resolution.

      public: explicit TMultimediaTimerResolutionMillisecondsScope
         ( int multimediaTimerResolutionMilliseconds1
         );

#endif
#if( /* {public} Instance destructor. */ 1 )

      // yg? This destructor calls {TTimeHelpers::AtomicRestoreMultimediaTimerResolutionMilliseconds}, which in turn can throw an exception.
      // yg? And that's an appropriate behavior as in that case the application should better die.
      // yg? Would it actually be better to kill the process instead of throwing an exception?

      public: ~TMultimediaTimerResolutionMillisecondsScope() /* yg? throw( ... ) */;

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TMultimediaTimerResolutionMillisecondsScope & operator =
         ( TMultimediaTimerResolutionMillisecondsScope const & source
         );

#endif
   };
}
}
