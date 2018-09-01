#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace Time
{
   // See the config file for more info.

   class TDateTimeKeeperConfiguration
   {
#if( /* {public TimerTickIntervalMillisecondsDeviation}. */ 1 )

      //
      public: double TimerTickIntervalMillisecondsDeviation;

#endif
#if( /* {public DateTimeTickLagMilliseconds}. */ 1 )

      //
      public: double DateTimeTickLagMilliseconds;

#endif
#if( /* {public Factor1}. */ 1 )

      //
      public: unsigned int Factor1;

#endif
#if( /* {public Factor2}. */ 1 )

      //
      public: double Factor2;

#endif
#if( /* {public Factor3}. */ 1 )

      //
      public: double Factor3;

#endif
#if( /* {public Factor4}. */ 1 )

      //
      public: double Factor4;

#endif
#if( /* {public Factor5}. */ 1 )

      //
      public: double Factor5;

#endif
#if( /* {public Factor6}. */ 1 )

      //
      public: double Factor6;

#endif
#if( /* {public Factor7}. */ 1 )

      //
      public: int Factor7;

#endif
#if( /* {public Factor8}. */ 1 )

      //
      public: int Factor8;

#endif
#if( /* {public Factor9}. */ 1 )

      //
      public: int Factor9;

#endif
#if( /* {public Factor10}. */ 1 )

      //
      public: double Factor10;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TDateTimeKeeperConfiguration();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TDateTimeKeeperConfiguration
         ( TDateTimeKeeperConfiguration const & source
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TDateTimeKeeperConfiguration & operator =
         ( TDateTimeKeeperConfiguration const & source
         );

#endif

#if( /* {public Validate}. */ 1 )

      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.

      public: void Validate() const;

#endif
   };
}
}
