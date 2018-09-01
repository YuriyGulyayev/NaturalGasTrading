#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TDateTimeKeeper.hpp"

#include "../DataStructures/TPair.cpp"
#include "./TDateTimeKeeperConfiguration.cpp"
//#include "../Diagnostics/Macros.cpp"
#include "../Math/TMathHelpers.cpp"
#include "./TTimeHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Time
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDateTimeKeeper::TDateTimeKeeper()
      // TODO 3 yg? remove>>>DateTimeBaseTicks_(),
      // TODO 3 yg? remove>>>DateTimeLastTicks_()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDateTimeKeeper::TDateTimeKeeper
      ( TDateTimeKeeperConfiguration && configuration1
      )
      // TODO 3 yg? remove>>>DateTimeBaseTicks_(),
      // TODO 3 yg? remove>>>DateTimeLastTicks_()
   {
      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TDateTimeKeeper::Initialize
      ( TDateTimeKeeperConfiguration && configuration1
      )
   {
      // Some fields are not initialized.

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TDateTimeKeeper::DoInitialize
      ( TDateTimeKeeperConfiguration && configuration1
      )
   {
      TimerTickIntervalMillisecondsDeviation_ = ::std::move( configuration1.TimerTickIntervalMillisecondsDeviation );
      DateTimeTickLagMilliseconds_ = ::std::move( configuration1.DateTimeTickLagMilliseconds );
      Factor1_ = ::std::move( configuration1.Factor1 );
      Factor2_ = ::std::move( configuration1.Factor2 );
      Factor3_ = ::std::move( configuration1.Factor3 );
      Factor4_ = ::std::move( configuration1.Factor4 );
      Factor5_ = ::std::move( configuration1.Factor5 );
      Factor6_ = ::std::move( configuration1.Factor6 );
      Factor7_ = ::std::move( configuration1.Factor7 );
      Factor8_ = ::std::move( configuration1.Factor8 );
      Factor9_ = ::std::move( configuration1.Factor9 );
      Factor10_ = ::std::move( configuration1.Factor10 );

      // yg? There is no need to initialize the base date-time tick but we will do that to return a non-garbage date-time if we are called too soon.
      // yg? This value guarantees that the date-time returned will be non-negative.
      // yg? This also requires that the initial {TimerTickIntervalMillisecondsSafeDeviation_ == 0.0}.
      // TODO 2 yg? We need a separate method to initialize these. Let the strategy to either call that method or populate this with current system date-time
      // TODO 2 yg? so that it did not have to log "??:??...".
      DateTimeBaseTicks_[ 0U ].Value1 = ::std::numeric_limits< int >::lowest();
      DateTimeBaseTicks_[ 0U ].Value2 = ( - static_cast< double >( ::std::numeric_limits< int >::lowest() ) );

      // yg? As mentioned a few lines above, this ensures that at the beginning we will return a non-negative date-time.
      TimerTickIntervalMillisecondsSafeDeviation_ = 0.0;
      
      DateTimeLastTicks_[ 1U ].Value2 = ::std::numeric_limits< double >::lowest();
      DateTimeLastTickAvailable_ = false;
      MaxNumberDateTimeTicksInIteration_ = 0;
      DateTimeTickInIterationCounter_ = 0;
      TimerTickIntervalMillisecondsDeviationCorrectionDirectionCode_ = 0;
      TimerTickIntervalMillisecondsDeviationCorrectionDirectionChangeCode_ = 0;
      TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ = 0;
      TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ = 0;
      UpdateCounter_ = 0;
   //#if( defined( YURIYGULYAYEV_TESTMODE ) )
   #if( YURIYGULYAYEV_TESTMODECODE() != 0 )
      Factor2Matters_ = false;
      Factor5Matters_ = false;
      Factor5Overmatters_ = true;
      Factor6Matters_ = false;
      Factor6Overmatters_ = true;
   #endif
   }

#endif
#if( /* {public Prepare}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TDateTimeKeeper::Prepare
      ( bool isFastMode
      )
   {
      if( isFastMode )
      {
         // This is really unnecessary as we don't feed date-time ticks to the date-time keeper after the later becomes ready.
         // Err... we can feed multiple date-time ticks before we create activities schedule.
         Factor2_ = 0.0;//static_cast< double >( ::std::numeric_limits< float >::???min() );

         Factor7_ = 1;
      }
      NumberDateTimeTicksInIteration_ = Factor7_;

      // yg? We don't need to change any other fields, right?
   }

#endif

#if( /* {public ProcessCurrentDateTimeTick}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   bool TDateTimeKeeper::ProcessCurrentDateTimeTick
      ( double currentDateTimeMilliseconds
      )
   {
      int timerTickCurrentCounter( TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
      return ProcessDateTimeTick( timerTickCurrentCounter, currentDateTimeMilliseconds );
   }

#endif
#if( /* {public ProcessDateTimeTick}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   bool TDateTimeKeeper::ProcessDateTimeTick
      ( int timerTickCounter,
        double dateTimeMilliseconds
      )
   {
      bool updateOccurred( false );
      if( ! DateTimeLastTickAvailable_ )
      {
         // yg? We ignore the date-time if it's not greater than any one received in the past.
         // yg? An equal (or smaller) date-time cannot be "better", assuming {timerTickCounter} is greather or equal.
         // yg? This results in discarding duplicate (or smaller) date-time ticks, which distorts the result and that's not necessarily a bad thing.
         // yg? A good reason to introduce this distortion is to increase resistance to market data bursts
         // yg? when batches of equal date-time ticks arrive within a short period of time with a longer latency.
         // yg? Assuming that even if {! DateTimeLastTickAvailable_}, {DateTimeLastTicks_[ 1U ].Value2} contains a valid value
         // yg? or {::std::numeric_limits< double >::lowest()}.
         // yg? Assuming {dateTimeMilliseconds > ::std::numeric_limits< double >::lowest()};
         // yg? otherwise this date-time tick will be ignored even if this is the 1st date-time tick, which is probably not too bad.
         if( dateTimeMilliseconds > DateTimeLastTicks_[ 1U ].Value2 )
         {
            DateTimeLastTickAvailable_ = true;
            goto label1;
         }
      }
      else
      {
         // yg? For the same reasons outlined above, we process only the greatest date-time tick among those occured between adjacent timer ticks.
         if( timerTickCounter == DateTimeLastTicks_[ 1U ].Value1 )
         {
            Math::TMathHelpers::AssignMaxValue( DateTimeLastTicks_[ 1U ].Value2, dateTimeMilliseconds );
         }
         else
         {
            updateOccurred = ProcessDateTimeLastTick();

            // yg? The comment above applies here too.
            if( dateTimeMilliseconds <= DateTimeLastTicks_[ 1U ].Value2 )
            {
               DateTimeLastTickAvailable_ = false;
            }
            else
            {
               Diagnostics::TDiagnosticsHelpers::DummyMethod();
            label1:
               DateTimeLastTicks_[ 1U ].Value1 = timerTickCounter;
               DateTimeLastTicks_[ 1U ].Value2 = dateTimeMilliseconds;
            }
         }
      }
      return updateOccurred;
   }

#endif
#if( /* {private ProcessDateTimeLastTick}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TDateTimeKeeper::ProcessDateTimeLastTick()
   {
      // yg? We don't reset {DateTimeLastTickAvailable_}.

      if( DateTimeTickInIterationCounter_ <= 0 )
      {
         goto label2;
      }
      else
      {
         int timerTickCounterDifference( DateTimeLastTicks_[ 1U ].Value1 - DateTimeBaseTicks_[ 1U ].Value1 );

         // yg? { >= }, not { > }.
         // This expression maximizes precision. It's equivalent to:
         // { DateTimeLastTicks_[ 1U ].Value2 >= DateTimeBaseTicks_[ 1U ].Value2 + static_cast< double >( timerTickCounterDifference ) + static_cast< double >( timerTickCounterDifference ) * TimerTickIntervalMillisecondsDeviation_ }.
         if( DateTimeLastTicks_[ 1U ].Value2 - DateTimeBaseTicks_[ 1U ].Value2 - static_cast< double >( timerTickCounterDifference ) >= static_cast< double >( timerTickCounterDifference ) * TimerTickIntervalMillisecondsDeviation_ )
         {
            Diagnostics::TDiagnosticsHelpers::DummyMethod();
         label2:
            DateTimeBaseTicks_[ 1U ] = DateTimeLastTicks_[ 1U ];
         }
      }

      if( ( ++ DateTimeTickInIterationCounter_ ) < NumberDateTimeTicksInIteration_ )
      {
         return false;
      }
      CompleteIteration();
      return true;
   }

#endif
#if( /* {private CompleteIteration}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TDateTimeKeeper::CompleteIteration()
   {
      // yg? To increase precision, I could eliminate some intermediary variables and use the same expressions in-line.
      // yg? The compiler could actually be able to do this as a part of the optimization but it won't order expression operands correctly.

      int timerLastTickCounterDifference;

      // yg? For performance, we could maintain a method pointer member field and call the method pointer instead of checking this condition.
      // yg? But would it really work faster?
      if( UpdateCounter_ <= 0 )

      {
         timerLastTickCounterDifference = ::std::numeric_limits< int >::max();
      }
      else
      {
         // These are positive as we process only one highest date-time tick among those occurred between adjacent timer ticks.
         timerLastTickCounterDifference = DateTimeLastTicks_[ 1U ].Value1 - DateTimeLastTicks_[ 0U ].Value1;
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( timerLastTickCounterDifference > 0 );
         int timerTickBaseCounterDifference( DateTimeBaseTicks_[ 1U ].Value1 - DateTimeBaseTicks_[ 0U ].Value1 );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( timerTickBaseCounterDifference > 0 );

         // This expression maximizes precision.
         double nextBaseDateTimeStampMillisecondsDeviation
            ( DateTimeBaseTicks_[ 1U ].Value2
              - DateTimeBaseTicks_[ 0U ].Value2
              - static_cast< double >( timerTickBaseCounterDifference )
              - static_cast< double >( timerTickBaseCounterDifference ) * TimerTickIntervalMillisecondsDeviation_
            );

         int timerTickIntervalMillisecondsDeviationCorrectionDirectionCode1
            ( // yg? When this is 0.0 we will treat it as the opposite to the previous.
              ( nextBaseDateTimeStampMillisecondsDeviation == 0.0 ) ?

              // yg? This is 0 at the beginning and can stay 0 for a few iterations.
              ( - TimerTickIntervalMillisecondsDeviationCorrectionDirectionCode_ ) :

              ( ( nextBaseDateTimeStampMillisecondsDeviation < 0.0 ) ? ( - 1 ) : 1 )
            );

         // yg? This condition is {True} only when it's evaluated for the 1st one or more times.
         if( timerTickIntervalMillisecondsDeviationCorrectionDirectionCode1 != TimerTickIntervalMillisecondsDeviationCorrectionDirectionCode_ ||
             timerTickIntervalMillisecondsDeviationCorrectionDirectionCode1 == 0
           )

         {
            // yg? This is redundant when {timerTickIntervalMillisecondsDeviationCorrectionDirectionCode1 == 0}; the compiler might be able to optimize this.
            TimerTickIntervalMillisecondsDeviationCorrectionDirectionCode_ = timerTickIntervalMillisecondsDeviationCorrectionDirectionCode1;

            // yg? This condition is {False} only when it's evaluated for the 1st time.
            if( UpdateCounter_ > 1 )

            {
               // yg? This condition is {True} (not only) when it's evaluated for the 1st time.
               if( TimerTickIntervalMillisecondsDeviationCorrectionDirectionChangeCode_ >= 0 )

               {
                  TimerTickIntervalMillisecondsDeviationCorrectionDirectionChangeCode_ = ( - 1 );
                  TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ = 1;
               }
               else
               {
                  // yg? Assuming this will not overflow.
                  ++ TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_;
               }
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                  ( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ > 0 &&
                    TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ >= 0
                  );

               do
               {
                  // yg? We could instead use {timerTickBaseCounterDifference} here but I feel that the result would be less deterministic.
                  // yg? If I decide to do so I would probably need to refactor the optimization to use {factor2Matters} together with
                  // yg? {factor5Matters} and {factor6Matters}, similarly to how it was done in {...::Test11}.
                  double factor2MinLimit( Factor5_ / static_cast< double >( timerLastTickCounterDifference ) );

                  // yg? We don't strictly enforce minimum limit of {Factor2_} as {timerLastTickCounterDifference} can be very small.
                  if( Factor2_ <= factor2MinLimit )
                  {
   //#if( defined( YURIYGULYAYEV_TESTMODE ) )
   #if( YURIYGULYAYEV_TESTMODECODE() != 0 )
                     //if( ! Factor5Matters_ )
                     {
                        Factor5Matters_ = true;
                        //Factor5Overmatters_ = true;
                     }
   #endif
                     break;
                  }

                  // yg? This cannot actually be 0, as validated by an {...ASSUME} above.
                  if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ <= 1 )

                  {
                     if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 1 )
                     {
                        if( ( Factor1_ & ( 1U << 22U ) ) == 0U )
                        {
                           break;
                        }
                     }
                     else
                     {
                        if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 2 )
                        {
                           if( ( Factor1_ & ( 1U << 20U ) ) == 0U )
                           {
                              break;
                           }
                        }
                        else
                        {
                           if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 3 )
                           {
                              if( ( Factor1_ & ( 1U << 18U ) ) == 0U )
                              {
                                 break;
                              }
                           }
                           else
                           {
                              YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                                 ( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ >= 4 ||
                                   TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ <= 0
                                 );
                              if( ( Factor1_ & ( 1U << 16U ) ) == 0U )
                              {
                                 break;
                              }
                           }
                        }
                     }
                  }
                  else
                  {
                     if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ == 2 )
                     {
                        if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 1 )
                        {
                           if( ( Factor1_ & ( 1U << 14U ) ) == 0U )
                           {
                              break;
                           }
                        }
                        else
                        {
                           if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 2 )
                           {
                              if( ( Factor1_ & ( 1U << 12U ) ) == 0U )
                              {
                                 break;
                              }
                           }
                           else
                           {
                              YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                                 ( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ >= 3 ||
                                   TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ <= 0
                                 );
                              if( ( Factor1_ & ( 1U << 10U ) ) == 0U )
                              {
                                 break;
                              }
                           }
                        }
                     }
                     else
                     {
                        if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ == 3 )
                        {
                           if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 1 )
                           {
                              if( ( Factor1_ & ( 1U << 8U ) ) == 0U )
                              {
                                 break;
                              }
                           }
                           else
                           {
                              if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 2 )
                              {
                                 if( ( Factor1_ & ( 1U << 6U ) ) == 0U )
                                 {
                                    break;
                                 }
                              }
                              else
                              {
                                 YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                                    ( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ >= 3 ||
                                      TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ <= 0
                                    );
                                 if( ( Factor1_ & ( 1U << 4U ) ) == 0U )
                                 {
                                    break;
                                 }
                              }
                           }
                        }
                        else
                        {
                           if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ == 4 )
                           {
                              if( ( Factor1_ & ( 1U << 2U ) ) == 0U )
                              {
                                 break;
                              }
                           }
                           else
                           {
                              if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ == 5 )
                              {
                                 if( ( Factor1_ & ( 1U << 0U ) ) == 0U )
                                 {
                                    break;
                                 }
                              }
                              else
                              {
                                 YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                                    ( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ >= 6 );
   //#if( defined( YURIYGULYAYEV_TESTMODE ) )
   #if( YURIYGULYAYEV_TESTMODECODE() != 0 )
                                 Factor5Overmatters_ = false;
   #endif
                              }
                           }
                        }
                     }
                  }

                  // yg? This can underflow.
                  // yg? If {Factor2_} was initialized with 0.0 it will stay 0.0, otherwise it will not become 0.0.
                  double nextFactor2( Factor2_ * Factor3_ );

                  // Making sure that {nextFactor2} is not too small (and is not 0.0).
                  // yg? Forcing the rounding from a 10-byte register to a {double}, which is a hack.
                  // yg? Assuming, the compiler will not optimize this rounding out.
                  // TODO 3 yg?? Actually it probably will. See a comment in {Math::TMathHelpers::CalculateNextCheapMovingAverage}.
                  if( static_cast< double >( TimerTickIntervalMillisecondsDeviation_ + nextBaseDateTimeStampMillisecondsDeviation * nextFactor2 ) ==
                      TimerTickIntervalMillisecondsDeviation_
                    )
                  {
                     break;
                  }

                  // yg? It would be more efficient to check this before the previous check but we do this afterwards to correctly set {Factor5Matters_}.
                  // yg? In the non-testing mode the compiler might be able to optimize this.
                  if( nextFactor2 >= factor2MinLimit )
                  {
                     Factor2_ = nextFactor2;
                  }
                  else
                  {
                     Factor2_ = factor2MinLimit;
   //#if( defined( YURIYGULYAYEV_TESTMODE ) )
   #if( YURIYGULYAYEV_TESTMODECODE() != 0 )
                     Factor5Matters_ = true;
   #endif
                  }
               }
               while( static_cast< void >( false ) , false );
            }
         }
         else
         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( UpdateCounter_ > 1 );

            // yg? This condition is {True} (not only) when it's evaluated for the 1st time.
            if( TimerTickIntervalMillisecondsDeviationCorrectionDirectionChangeCode_ <= 0 )
            {
               TimerTickIntervalMillisecondsDeviationCorrectionDirectionChangeCode_ = 1;
               TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ = 1;
            }
            else
            {
               // yg? Assuming this will not overflow.
               ++ TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_;
            }
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
               ( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ > 0 &&
                 TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ >= 0
               );

            do
            {
               // yg? Assuming that the use of {factor2MaxLimit} will ensure that {Factor2_} will stay far away from the point of overflow.
               // yg? Actually as we enforce {Factor2_ <= 1.0 / timerTickBaseCounterDifference} no overflow will occur anyway.
               // yg? We could instead use {timerTickBaseCounterDifference} here but I feel that the result would be less deterministic.
               // yg? If I decide to do so I would probably need to refactor the optimization to use {factor2Matters} together with
               // yg? {factor5Matters} and {factor6Matters}, similarly to how it was done in {...::Test11}.
               double factor2MaxLimit( Factor6_ / static_cast< double >( timerLastTickCounterDifference ) );

               // yg? We don't strictly enforce maximum limit of {Factor2_} as {timerLastTickCounterDifference} can be very large.
               if( Factor2_ >= factor2MaxLimit )
               {
   //#if( defined( YURIYGULYAYEV_TESTMODE ) )
   #if( YURIYGULYAYEV_TESTMODECODE() != 0 )
                  Factor6Matters_ = true;
   #endif
                  break;
               }

               if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 1 )
               {
                  if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ <= 1 )
                  {
                     if( ( Factor1_ & ( 1U << 23U ) ) == 0U )
                     {
                        break;
                     }
                  }
                  else
                  {
                     if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ == 2 )
                     {
                        if( ( Factor1_ & ( 1U << 21U ) ) == 0U )
                        {
                           break;
                        }
                     }
                     else
                     {
                        if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ == 3 )
                        {
                           if( ( Factor1_ & ( 1U << 19U ) ) == 0U )
                           {
                              break;
                           }
                        }
                        else
                        {
                           YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                              ( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ >= 4 );
                           if( ( Factor1_ & ( 1U << 17U ) ) == 0U )
                           {
                              break;
                           }
                        }
                     }
                  }
               }
               else
               {
                  if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 2 )
                  {
                     if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ <= 1 )
                     {
                        if( ( Factor1_ & ( 1U << 15U ) ) == 0U )
                        {
                           break;
                        }
                     }
                     else
                     {
                        if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ == 2 )
                        {
                           if( ( Factor1_ & ( 1U << 13U ) ) == 0U )
                           {
                              break;
                           }
                        }
                        else
                        {
                           YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                              ( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ >= 3 );
                           if( ( Factor1_ & ( 1U << 11U ) ) == 0U )
                           {
                              break;
                           }
                        }
                     }
                  }
                  else
                  {
                     if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 3 )
                     {
                        if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ <= 1 )
                        {
                           if( ( Factor1_ & ( 1U << 9U ) ) == 0U )
                           {
                              break;
                           }
                        }
                        else
                        {
                           if( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ == 2 )
                           {
                              if( ( Factor1_ & ( 1U << 7U ) ) == 0U )
                              {
                                 break;
                              }
                     }
                           else
                           {
                           YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                                 ( TimerTickIntervalMillisecondsDeviationCorrectionInOppositeDirectionCounter_ >= 3 );
                              if( ( Factor1_ & ( 1U << 5U ) ) == 0U )
                              {
                                 break;
                              }
                           }
                        }
                     }
                     else
                     {
                        if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 4 )
                        {
                           if( ( Factor1_ & ( 1U << 3U ) ) == 0U )
                           {
                              break;
                           }
                        }
                        else
                        {
                           if( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ == 5 )
                           {
                              if( ( Factor1_ & ( 1U << 1U ) ) == 0U )
                              {
                                 break;
                              }
                           }
                           else
                           {
                              YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
                                 ( TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ >= 6 //||
                                   //TimerTickIntervalMillisecondsDeviationCorrectionInSameDirectionCounter_ <= 0
                                 );
   //#if( defined( YURIYGULYAYEV_TESTMODE ) )
   #if( YURIYGULYAYEV_TESTMODECODE() != 0 )
                              Factor6Overmatters_ = false;
   #endif
                           }
                        }
                     }
                  }
               }

               // yg? Assuming this will not overflow.
               double nextFactor2( Factor2_ * Factor4_ );

               if( nextFactor2 <= factor2MaxLimit )
               {
                  Factor2_ = nextFactor2;
               }
               else
               {
                  Factor2_ = factor2MaxLimit;
   //#if( defined( YURIYGULYAYEV_TESTMODE ) )
   #if( YURIYGULYAYEV_TESTMODECODE() != 0 )
                  Factor6Matters_ = true;
   #endif
               }
            }
            while( static_cast< void >( false ) , false );
         }

         // The {Factor2_ <= 1.0 / timerTickBaseCounterDifference} condition is required for the cheap moving average to be correct.
         // When {Factor2_ == 1.0 / timerTickBaseCounterDifference} previous value of {TimerTickIntervalMillisecondsDeviation_} will not matter.
         if( Factor2_ <= 1.0 / static_cast< double >( timerTickBaseCounterDifference ) )

         {
   //#if( defined( YURIYGULYAYEV_TESTMODE ) )
   #if( YURIYGULYAYEV_TESTMODECODE() != 0 )
            if( UpdateCounter_ == 1 )
            {
               // yg? There could be some mutual dependency between this and the other {...Matters} flags.
               Factor2Matters_ = true;
            }
   #endif
         }
         else
         {
            Factor2_ = 1.0 / static_cast< double >( timerTickBaseCounterDifference );
         }
         
         double timerTickIntervalMillisecondsDeviationCorrection( nextBaseDateTimeStampMillisecondsDeviation * Factor2_ );

         // yg? Can I improve precision of this and above expressions?
         TimerTickIntervalMillisecondsDeviation_ += timerTickIntervalMillisecondsDeviationCorrection;
      }

      Math::TMathHelpers::AssignMaxValue( MaxNumberDateTimeTicksInIteration_, NumberDateTimeTicksInIteration_ );

      do
      {
         // yg? This condition is {False} (not only) when it's evaluated for the 1st time.
         // yg? Although normally this condition is {True}.
         if( timerLastTickCounterDifference < Factor9_ )

         {
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( UpdateCounter_ > 0 );
            if( NumberDateTimeTicksInIteration_ < Factor8_ )
            {
               // yg? Adding 1.
               // yg? It might be beneficial to make the value to add configurable but that would require a significant redesign of the bias elimination logic.
               ++ NumberDateTimeTicksInIteration_;

               if( NumberDateTimeTicksInIteration_ > MaxNumberDateTimeTicksInIteration_ )
               {
                  // yg? {TimerTickIntervalMillisecondsDeviation_} upward bias elimination logic.
                  // yg? The bias occurs because {NumberDateTimeTicksInIteration_} increses.
                  {
                     int timerTickCounterDifference( DateTimeBaseTicks_[ 1U ].Value1 - DateTimeLastTicks_[ 0U ].Value1 );

                     // yg? Using the already updated {TimerTickIntervalMillisecondsDeviation_}, which, based on inconclusive testing results, could be better
                     // yg? than the unupdated value or the average of the unupdated and updated.
                     // yg? { <= }, not { < }.
                     // This expression maximizes precision.
                     if( DateTimeBaseTicks_[ 1U ].Value2 - DateTimeLastTicks_[ 0U ].Value2 - static_cast< double >( timerTickCounterDifference ) <= static_cast< double >( timerTickCounterDifference ) * TimerTickIntervalMillisecondsDeviation_ )
                     {
                        DateTimeBaseTicks_[ 0U ] = DateTimeLastTicks_[ 0U ];
                        break;
                     }
                  }
               }
            }
         }
         else
         {
            if( timerLastTickCounterDifference > Factor9_ )
            {
               if( NumberDateTimeTicksInIteration_ > Factor7_ )
               {
                  -- NumberDateTimeTicksInIteration_;
               }
            }
         }

         DateTimeBaseTicks_[ 0U ] = DateTimeBaseTicks_[ 1U ];
      }
      while( static_cast< void >( false ) , false );

      TimerTickIntervalMillisecondsSafeDeviation_ = ::std::min( ::std::max( TimerTickIntervalMillisecondsDeviation_, 1.0 / ( Factor10_ + 1.0 ) - 1.0 ), Factor10_ );
      DateTimeLastTicks_[ 0U ] = DateTimeLastTicks_[ 1U ];
      DateTimeTickInIterationCounter_ = 0;

      // Assuming this will not overflow.
      ++ UpdateCounter_;
   }

#endif

#if( /* {public TimerTickIntervalMillisecondsDeviation}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline double TDateTimeKeeper::TimerTickIntervalMillisecondsDeviation() const
   {
      return TimerTickIntervalMillisecondsDeviation_;
   }

#endif
#if( /* {public TimerTickIntervalMillisecondsSafeDeviation}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline double TDateTimeKeeper::TimerTickIntervalMillisecondsSafeDeviation() const
   {
      return TimerTickIntervalMillisecondsSafeDeviation_;
   }

#endif
#if( /* {public UpdateCounter}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::Poco::Int64 TDateTimeKeeper::UpdateCounter() const
   {
      return UpdateCounter_;
   }

#endif

#if( /* {public GetDateTimeMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline double TDateTimeKeeper::GetDateTimeMilliseconds
      ( int timerTickCounter
      ) const
   {
      return GetDateTimeMilliseconds( static_cast< double >( timerTickCounter ) );
   }

#endif
#if( /* {public GetDateTimeMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline double TDateTimeKeeper::GetDateTimeMilliseconds
      ( double timerTickCounter
      ) const
   {
      // yg? Would precision be higher if we use parts of this expression separately?
      double timerTickCounterDifference( timerTickCounter - static_cast< double >( DateTimeBaseTicks_[ 0U ].Value1 ) );

      // This expression maximizes precision.
      // We avoid adding 1.0 to {TimerTickIntervalMillisecondsSafeDeviation_}.
      return
         timerTickCounterDifference * TimerTickIntervalMillisecondsSafeDeviation_
         + DateTimeTickLagMilliseconds_
         + timerTickCounterDifference
         + DateTimeBaseTicks_[ 0U ].Value2;
   }

#endif
#if( /* {public GetCurrentDateTimeMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline double TDateTimeKeeper::GetCurrentDateTimeMilliseconds() const
   {
      int timerTickCurrentCounter( TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );
      return GetDateTimeMilliseconds( timerTickCurrentCounter );
   }

#endif
#if( /* {public GetCurrentDateTimeMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline double TDateTimeKeeper::GetCurrentDateTimeMilliseconds
      ( double timerTickCurrentCounterOffset
      ) const
   {
      // yg? Would precision be higher if we use parts of this expression separately?
      double timerTickCurrentCounter( static_cast< double >( TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() ) + timerTickCurrentCounterOffset );

      return GetDateTimeMilliseconds( timerTickCurrentCounter );
   }

#endif
#if( /* {public GetDateTimeMillisecondsAsInteger}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TInteger_
      >
   inline TInteger_ TDateTimeKeeper::GetDateTimeMillisecondsAsInteger
      ( int timerTickCounter
      ) const
   {
      return Math::TMathHelpers::RoundValueToIntegerMidpointUp< double, TInteger_ >( GetDateTimeMilliseconds( timerTickCounter ) );
   }

#endif
#if( /* {public GetDateTimeMillisecondsAsInteger}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TInteger_
      >
   inline TInteger_ TDateTimeKeeper::GetDateTimeMillisecondsAsInteger
      ( double timerTickCounter
      ) const
   {
      return Math::TMathHelpers::RoundValueToIntegerMidpointUp< double, TInteger_ >( GetDateTimeMilliseconds( timerTickCounter ) );
   }

#endif
#if( /* {public GetCurrentDateTimeMillisecondsAsInteger}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TInteger_
      >
   inline TInteger_ TDateTimeKeeper::GetCurrentDateTimeMillisecondsAsInteger() const
   {
      return Math::TMathHelpers::RoundValueToIntegerMidpointUp< double, TInteger_ >( GetCurrentDateTimeMilliseconds() );
   }

#endif
#if( /* {public GetCurrentDateTimeMillisecondsAsInteger}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TInteger_
      >
   inline TInteger_ TDateTimeKeeper::GetCurrentDateTimeMillisecondsAsInteger
      ( double timerTickCurrentCounterOffset
      ) const
   {
      return Math::TMathHelpers::RoundValueToIntegerMidpointUp< double, TInteger_ >( GetCurrentDateTimeMilliseconds( timerTickCurrentCounterOffset ) );
   }

#endif
#if( /* {public GetTimerTickCounter}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TDateTimeKeeper::GetTimerTickCounter
      ( double dateTimeMilliseconds
      ) const
   {
      // We avoid calculating the resulting timer tick counter as a {double} and rounding it to {int} as if the {double} value exceeded the
      // range of the {int} data type the rounding would not work correct.

      // yg? We could pre-calculate { 1.0 / ( TimerTickIntervalMillisecondsSafeDeviation_ + 1.0 ) } but that would reduce precision.
      // This expression maximizes precision.
      // yg? Can we avoid adding 1.0 to {TimerTickIntervalMillisecondsSafeDeviation_}?
      double timerTickCounterDifferenceAsDouble
         ( ( dateTimeMilliseconds - DateTimeBaseTicks_[ 0U ].Value2 - DateTimeTickLagMilliseconds_ ) / ( TimerTickIntervalMillisecondsSafeDeviation_ + 1.0 ) );

      // yg? Assuming this will not overflow.
      int timerTickCounterDifference( Math::TMathHelpers::RoundValueToIntegerMidpointDown< double, int >( timerTickCounterDifferenceAsDouble ) );

      int timerTickCounter( timerTickCounterDifference + DateTimeBaseTicks_[ 0U ].Value1 );
      return timerTickCounter;
   }

#endif
}
}
