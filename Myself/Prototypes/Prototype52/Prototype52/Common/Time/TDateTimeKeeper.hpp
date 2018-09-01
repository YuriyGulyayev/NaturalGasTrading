#pragma once

#include "../DataStructures/TPair.hpp"
#include "./TDateTimeKeeperConfiguration.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace Time
{
#pragma push_macro( "private" )
#pragma push_macro( "protected" )
//#if( defined( YURIYGULYAYEV_TESTMODE ) )
#if( YURIYGULYAYEV_TESTMODECODE() != 0 )
   #define private public
   #define protected public
#endif

   // This class essentially implements a search for and tracking of a moving target.
   // Date-time is expressed in milliseconds and can be an offset since for example the year of 1970 or 0000 -- up to the caller to interpret.
   // See the "15_DateTimeKeeperIdeas.doc" file, {...::TDateTimeKeeperPrototype2} class, {...::DateTimeKeeperPrototype1} class for more info.
   // yg? This code does not handle integer (including 32-bit milliseconds) or floating point overflows;
   // yg? system hibernation or leap seconds can cause incorrect behavior.
   // yg? In fact, in case incoming floating point date-times are the result of converting 64-bit integer microseconds or milliseconds to {double}
   // yg? no floating point overflow can occur.
   // yg? The date-time resolution can be insufficient if date-time is represented as milliseconds since a too distant year.
   // yg? A solution could be to use 10-byte floating point numbers, {decimal}, or represent a date-time with 2 variables.
   // yg? We don't currently use the {Math::TMathHelpers::CalculateNextCheapMovingAverage} logic. And we don't need it.
   // yg? In this class, we use the term "timer-tick-counter" but elsewhere we refer to the same thing "multimedia-time-milliseconds"
   // yg? or simply "time-milliseconds". Consider using the word "thread time slice".
   // yg? Consider using the word "date-time tracker".

   class TDateTimeKeeper
   {
#if( /* {private DateTimeBaseTicks_}. */ 1 )

      // "Best" date-time ticks.
      private: DataStructures::TPair< int, double > DateTimeBaseTicks_[ 2U ];

#endif
#if( /* {private TimerTickIntervalMillisecondsDeviation_}. */ 1 )

      // Difference of the timer tick interval from a millisecond.
      // The value is close to 0.0, positive or negative.
      // Obtained from the configuration and can change.
      // yg? Consider renaming this to {TimerTickIntervalDeviationMilliseconds_}. (Bad idea.)
      private: double TimerTickIntervalMillisecondsDeviation_;

#endif
#if( /* {private TimerTickIntervalMillisecondsSafeDeviation_}. */ 1 )

      // A "safe" version of {TimerTickIntervalMillisecondsDeviation_}.
      // yg? Consider renaming {TimerTickIntervalMillisecondsDeviation_} to {TimerTickIntervalMillisecondsRawDeviation_}.
      // yg? Consider renaming {TimerTickIntervalMillisecondsSafeDeviation_} to {TimerTickIntervalMillisecondsDeviation_}.
      private: double TimerTickIntervalMillisecondsSafeDeviation_;

#endif
#if( /* {private DateTimeLastTicks_}. */ 1 )

      // The item at 0 is the last date-time tick in previous iteration.
      // The item at 1 is the last up-to-date date-time tick in current iteration.
      private: DataStructures::TPair< int, double > DateTimeLastTicks_[ 2U ];

#endif
#if( /* {private DateTimeLastTickAvailable_}. */ 1 )

      // {True} when {DateTimeLastTicks_[ 1U ]} is valid.
      // yg? Even when this is {false} {DateTimeLastTicks_[ 1U ].Value2} contains a valid value or {::std::numeric_limits< double >::lowest()}.
      private: bool DateTimeLastTickAvailable_;

#endif
#if( /* {private NumberDateTimeTicksInIteration_}. */ 1 )

      //
      private: int NumberDateTimeTicksInIteration_;

#endif
#if( /* {private MaxNumberDateTimeTicksInIteration_}. */ 1 )

      // Highest watermark reached in the past.
      private: int MaxNumberDateTimeTicksInIteration_;

#endif
#if( /* {private DateTimeTickInIterationCounter_}. */ 1 )

      //
      private: int DateTimeTickInIterationCounter_;

#endif
#if( /* {private TimerTickIntervalMillisecondsDeviationCorrectionDirectionCode_}. */ 1 )

      // -1, 0, 1.
      private: int TimerTickIntervalMillisecondsDeviationCorrectionDirectionCode_;

#endif
#if( /* {private TimerTickIntervalMillisecondsDeviationCorrectionDirectionChangeCode_}. */ 1 )

      // -1, 0, 1.
      private: int TimerTickIntervalMillisecondsDeviationCorrectionDirectionChangeCode_;

#endif
#if( /* {private TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_}. */ 1 )

      //
      private: int TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_;

#endif
#if( /* {private TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_}. */ 1 )

      //
      private: int TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_;

#endif
#if( /* {private UpdateCounter_}. */ 1 )

      // Incremented at the end of each iteration.
      // The date-time returned by the date-time keeper is valid only when this is a nonzero.
      // Assumption: this will not overflow.
      private: ::Poco::Int64 UpdateCounter_;

#endif
#if( /* {private DateTimeTickLagMilliseconds_}. */ 1 )

      // Specifies how long it takes market data to reach us.
      // If we run close to the exchange this would be a small faction of a millisecond.
      // This value must be adjusted for both the date-time keeper implementation specifics and the way we use the date-time.
      // For example, when the implementation results in returning date-time that maps to the moment immediately before the next timer tick
      // and we want to get time that maps to the moment immediately after a timer tick or get timer tick to sleep until,
      // this value should be adjusted by something like -0.99 or, to avoid using numbers that appear to be magic, -1.0.
      // Shall be positive (unless an adjustment is needed).
      // Obtained from the configuration.
      private: double DateTimeTickLagMilliseconds_;

#endif
#if( /* {private Factor1_}. */ 1 )

      // This is a bitmask in which each bit controls some logic.
      // Obtained from the configuration.
      private: unsigned int Factor1_;

#endif
#if( /* {private Factor2_}. */ 1 )

      // Affects the correction of {TimerTickIntervalMillisecondsDeviation_}.
      // Shall be non-negative.
      // Obtained from the configuration and may change.
      // If it's initially 0.0 it will not change.
      // In the "fast" mode it's forced to be 0.0, which is really unnecessary as we don't feed date-time ticks to the date-time keeper after the later becomes ready.
      private: double Factor2_;

#endif
#if( /* {private Factor2Matters_}. */ /*defined( YURIYGULYAYEV_TESTMODE )*/ YURIYGULYAYEV_TESTMODECODE() != 0 )

      // This is used for the optimization.
      // yg? This should be a bit field.
      private: bool Factor2Matters_;

#endif
#if( /* {private Factor3_}. */ 1 )

      // Affects the reduction of {Factor2_}.
      // Shall be positive and { <= 1.0 }.
      // Obtained from the configuration.
      private: double Factor3_;

#endif
#if( /* {private Factor4_}. */ 1 )

      // Affects the increase of {Factor2_}.
      // Shall be { >= 1.0 }.
      // Obtained from the configuration.
      private: double Factor4_;

#endif
#if( /* {private Factor5_}. */ 1 )

      // Affects the minimum limit of {Factor2_}.
      // Shall be positive and {Factor5_ <= Factor6_}.
      // Obtained from the configuration.
      private: double Factor5_;

#endif
#if( /* {private Factor5Matters_}. */ /*defined( YURIYGULYAYEV_TESTMODE )*/ YURIYGULYAYEV_TESTMODECODE() != 0 )

      // This is used for the optimization.
      // yg? This should be a bit field.
      private: bool Factor5Matters_;

#endif
#if( /* {private Factor5Overmatters_}. */ /*defined( YURIYGULYAYEV_TESTMODE )*/ YURIYGULYAYEV_TESTMODECODE() != 0 )

      // This is used for the optimization.
      // yg? This is valid only when {Factor5Matters_ == true}.
      // yg? This should be a bit field.
      private: bool Factor5Overmatters_;

#endif
#if( /* {private Factor6_}. */ 1 )

      // Affects the maximum limit of {Factor2_}.
      // Shall be positive and {Factor5_ <= Factor6_}.
      // Obtained from the configuration.
      private: double Factor6_;

#endif
#if( /* {private Factor6Matters_}. */ /*defined( YURIYGULYAYEV_TESTMODE )*/ YURIYGULYAYEV_TESTMODECODE() != 0 )

      // This is used for the optimization.
      // yg? This should be a bit field.
      private: bool Factor6Matters_;

#endif
#if( /* {private Factor6Overmatters_}. */ /*defined( YURIYGULYAYEV_TESTMODE )*/ YURIYGULYAYEV_TESTMODECODE() != 0 )

      // This is used for the optimization.
      // yg? This is valid only when {Factor6Matters_ == true}.
      // yg? This should be a bit field.
      private: bool Factor6Overmatters_;

#endif
#if( /* {private Factor7_}. */ 1 )

      // Minimum value of {NumberDateTimeTicksInIteration_}.
      // Shall be positive and {Factor7_ <= Factor8_}.
      // Obtained from the configuration.
      // In the "fast" mode it's forced to be 1.
      private: int Factor7_;

#endif
#if( /* {private Factor8_}. */ 1 )

      // Maximum value of {NumberDateTimeTicksInIteration_}.
      // Shall be positive and {Factor7_ <= Factor8_}.
      // Obtained from the configuration.
      private: int Factor8_;

#endif
#if( /* {private Factor9_}. */ 1 )

      // Maximum number of timer ticks between the last date-time tick in previous iteration until the last date-time tick in current iteration.
      // If this limit is not reached {NumberDateTimeTicksInIteration_} will be incremented (up to {Factor8_}) for the next iteration.
      // If this limit is reached {NumberDateTimeTicksInIteration_} will be left unchanged for the next iteration.
      // If this limit is exceeded {NumberDateTimeTicksInIteration_} will be decremented (down to {Factor7_}) for the next iteration.
      // yg? It could be more correct to limit the timespan expressed in date-time rather than timer ticks. (Bad idea?)
      // Shall be positive.
      // Obtained from the configuration.
      private: int Factor9_;

#endif
#if( /* {private Factor10_}. */ 1 )

      // Affects the limits of {TimerTickIntervalMillisecondsSafeDeviation_}.
      // Shall be non-negative.
      // Obtained from the configuration.
      private: double Factor10_;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TDateTimeKeeper();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TDateTimeKeeper
         ( TDateTimeKeeper const & source
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TDateTimeKeeper
         ( TDateTimeKeeperConfiguration && configuration1
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TDateTimeKeeper & operator =
         ( TDateTimeKeeper const & source
         );

#endif

#if( /* {public Initialize}. */ 1 )

      //

      public: void Initialize
         ( TDateTimeKeeperConfiguration && configuration1
         );

#endif
#if( /* {private DoInitialize}. */ 1 )

      //

      private: void DoInitialize
         ( TDateTimeKeeperConfiguration && configuration1
         );

#endif
#if( /* {public Prepare}. */ 1 )

      // The "fast" mode is to be used in the strategy's test mode.

      public: void Prepare
         ( bool isFastMode
         );

#endif

#if( /* {public ProcessCurrentDateTimeTick}. */ 1 )

      // yg? Consider eliminating this method to decouple this class from the source of timer ticks.

      public: bool ProcessCurrentDateTimeTick
         ( double currentDateTimeMilliseconds
         );

#endif
#if( /* {public ProcessDateTimeTick}. */ 1 )

      // Returns {true} when {UpdateCounter_} changes.
      // yg? This method must be called often enough to prevent a timer tick counter difference overflow.
      // yg? Consider swapping the parameters as {dateTimeMilliseconds} is obtained before {timerTickCounter}.

      public: bool ProcessDateTimeTick
         ( int timerTickCounter,
           double dateTimeMilliseconds
         );

#endif
#if( /* {private ProcessDateTimeLastTick}. */ 1 )

      // yg? We might also need a method that would call {ProcessDateTimeLastTick} in case current timer tick counter { != DateTimeLastTicks_[ 1U ].Value1 }.

      private: bool ProcessDateTimeLastTick();

#endif
#if( /* {private CompleteIteration}. */ 1 )

      //

      private: void CompleteIteration();

#endif

#if( /* {public TimerTickIntervalMillisecondsDeviation}. */ 1 )

      //

      public: double TimerTickIntervalMillisecondsDeviation() const;

#endif
#if( /* {public TimerTickIntervalMillisecondsSafeDeviation}. */ 1 )

      //

      public: double TimerTickIntervalMillisecondsSafeDeviation() const;

#endif
#if( /* {public UpdateCounter}. */ 1 )

      //

      public: ::Poco::Int64 UpdateCounter() const;

#endif

#if( /* {public GetDateTimeMilliseconds}. */ 1 )

      //

      public: double GetDateTimeMilliseconds
         ( int timerTickCounter
         ) const;

#endif
#if( /* {public GetDateTimeMilliseconds}. */ 1 )

      // Provided {TDateTimeKeeper} is configured to return time immediately after a timer tick,
      // this method can be used to get date-time in the middle of a timer tick interval by adding 0.5 to {timerTickCounter}.

      public: double GetDateTimeMilliseconds
         ( double timerTickCounter
         ) const;

#endif
#if( /* {public GetCurrentDateTimeMilliseconds}. */ 1 )

      //

      public: double GetCurrentDateTimeMilliseconds() const;

#endif
#if( /* {public GetCurrentDateTimeMilliseconds}. */ 1 )

      // Provided {TDateTimeKeeper} is configured to return time immediately after a timer tick,
      // this method can be used to get date-time in the middle of a timer tick interval by passing {timerTickCurrentCounterOffset = 0.5}.

      public: double GetCurrentDateTimeMilliseconds
         ( double timerTickCurrentCounterOffset
         ) const;

#endif
#if( /* {public GetDateTimeMillisecondsAsInteger}. */ 1 )

      // This method rounds the result to the nearest integer.
      // yg? For certain scenarios it could be more appropriate to simply truncate the fractional part.

      public:
         template
            < typename TInteger_
            >
         TInteger_ GetDateTimeMillisecondsAsInteger
            ( int timerTickCounter
            ) const;

#endif
#if( /* {public GetDateTimeMillisecondsAsInteger}. */ 1 )

      // Provided {TDateTimeKeeper} is configured to return time immediately after a timer tick,
      // this method can be used to get date-time in the middle of a timer tick interval by adding 0.5 to {timerTickCounter}.

      public:
         template
            < typename TInteger_
            >
         TInteger_ GetDateTimeMillisecondsAsInteger
            ( double timerTickCounter
            ) const;

#endif
#if( /* {public GetCurrentDateTimeMillisecondsAsInteger}. */ 1 )

      //

      public:
         template
            < typename TInteger_
            >
         TInteger_ GetCurrentDateTimeMillisecondsAsInteger() const;

#endif
#if( /* {public GetCurrentDateTimeMillisecondsAsInteger}. */ 1 )

      // Provided {TDateTimeKeeper} is configured to return time immediately after a timer tick,
      // this method can be used to get date-time in the middle of a timer tick interval by passing {timerTickCurrentCounterOffset = 0.5}.

      public:
         template
            < typename TInteger_
            >
         TInteger_ GetCurrentDateTimeMillisecondsAsInteger
            ( double timerTickCurrentCounterOffset
            ) const;

#endif
#if( /* {public GetTimerTickCounter}. */ 1 )

      // Gets timer tick counter at the specified date-time.
      // yg? A timer tick counter overflow will occur if {dateTimeMilliseconds} is too far from {DateTimeBaseTicks_[ 0U ].Value2}.
      // yg? We might need a similar method that returns an unrounded {double}.

      public: int GetTimerTickCounter
         ( double dateTimeMilliseconds
         ) const;

#endif
   };

#pragma pop_macro( "protected" )
#pragma pop_macro( "private" )
}
}
