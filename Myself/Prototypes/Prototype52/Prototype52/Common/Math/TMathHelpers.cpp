#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TMathHelpers.hpp"

#include "../Diagnostics/Macros.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Math
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

#if( /* {public AssignMinValue}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline void TMathHelpers::AssignMinValue
      ( TValue_ & value1,
        TValue_ value2
      )
   {
      if( value2 < value1 )
      {
         value1 = ::std::move( value2 );
      }
      else
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
   }

#endif
#if( /* {public AssignMaxValue}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline void TMathHelpers::AssignMaxValue
      ( TValue_ & value1,
        TValue_ value2
      )
   {
      if( value2 > value1 )
      {
         value1 = ::std::move( value2 );
      }
      else
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
   }

#endif

#if( /* //{public CircularBitwiseShiftValueRight}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TUnsignedInteger_
   //   >
   //inline TUnsignedInteger_ TMathHelpers::CircularBitwiseShiftValueRight
   //   ( TUnsignedInteger_ value,
   //     unsigned int offset
   //   )
   //{
   //   // {TUnsignedInteger_} shall be unsigned.
   //   // Integral promotion is not a problem.
   //   static_assert( static_cast< TUnsignedInteger_ >( - 1 ) > static_cast< TUnsignedInteger_ >( 0 ), "" );
   //
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( offset < sizeof( value ) * 8U );
   //
   //   // Integral promotion is not a problem.
   //   return static_cast< TUnsignedInteger_ >( ( value >> offset ) |
   //                                                                     ( value <<
   //                                                                       ( ( // This can theoretically not fit in an {unsigned int}, which won't break the logic.
   //                                                                            ( sizeof( value ) * 8U ) -
   //
   //                                                                            offset
   //                                                                         ) %
   //                                                                         ( sizeof( value ) * 8U )
   //                                                                       )
   //                                                                     )
   //                                                                   );
   //}

#endif

#if( /* {public RoundValueToIntegerMidpointAwayFromZero}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline TValue_ TMathHelpers::RoundValueToIntegerMidpointAwayFromZero
      ( TValue_ value
      )
   {
      return ( value >= static_cast< TValue_ >( 0.0 ) ) ?
                 RoundValueToIntegerMidpointUp( value ) :
                 RoundValueToIntegerMidpointDown( value );
   }

#endif
#if( /* {public RoundValueToIntegerMidpointAwayFromZero}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_,
         typename TInteger_
      >
   inline TInteger_ TMathHelpers::RoundValueToIntegerMidpointAwayFromZero
      ( TValue_ value
      )
   {
      //// This can overflow.
      //return static_cast< TInteger_ >( RoundValueToIntegerMidpointAwayFromZero( value ) );

      //// This can overflow.
      //return static_cast< TInteger_ >( ( value >= static_cast< TValue_ >( 0.0 ) ) ? ( value + static_cast< TValue_ >( 0.5 ) ) : ( value - static_cast< TValue_ >( 0.5 ) ) );

      // This can overflow.
      {
         TInteger_ valueAsInteger( static_cast< TInteger_ >( value ) );
         TValue_ valueFraction( value - static_cast< TValue_ >( valueAsInteger ) );
         //TInteger_ valueRoundedMidpointAwayFromZeroAsInteger
         //   ( static_cast< TInteger_ >( valueFraction * static_cast< TValue_ >( 2.0 ) ) + valueAsInteger );
         TInteger_ valueRoundedMidpointAwayFromZeroAsInteger( static_cast< TInteger_ >( valueFraction + value ) );
         return valueRoundedMidpointAwayFromZeroAsInteger;
      }
   }

#endif
#if( /* {public RoundValueToMultipleOfMidpointAwayFromZero}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline TValue_ TMathHelpers::RoundValueToMultipleOfMidpointAwayFromZero
      ( TValue_ value,
        TValue_ valueDivisor
      )
   {
      // This can overflow.
      return RoundValueToIntegerMidpointAwayFromZero( value / valueDivisor ) * valueDivisor;
   }

#endif
#if( /* {public RoundValueToIntegerMidpointTowardsZero}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline TValue_ TMathHelpers::RoundValueToIntegerMidpointTowardsZero
      ( TValue_ value
      )
   {
      return ( value >= static_cast< TValue_ >( 0.0 ) ) ?
                 RoundValueToIntegerMidpointDown( value ) :
                 RoundValueToIntegerMidpointUp( value );
   }

#endif
#if( /* {public RoundValueToIntegerMidpointTowardsZero}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_,
         typename TInteger_
      >
   inline TInteger_ TMathHelpers::RoundValueToIntegerMidpointTowardsZero
      ( TValue_ value
      )
   {
      // This can overflow.
      return static_cast< TInteger_ >( RoundValueToIntegerMidpointTowardsZero( value ) );
   }

#endif
#if( /* {public RoundValueToMultipleOfMidpointTowardsZero}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline TValue_ TMathHelpers::RoundValueToMultipleOfMidpointTowardsZero
      ( TValue_ value,
        TValue_ valueDivisor
      )
   {
      // This can overflow.
      return RoundValueToIntegerMidpointTowardsZero( value / valueDivisor ) * valueDivisor;
   }

#endif
#if( /* {public RoundValueToIntegerMidpointDown}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline TValue_ TMathHelpers::RoundValueToIntegerMidpointDown
      ( TValue_ value
      )
   {
      // This can't overflow.
      return ::std::ceil( value - static_cast< TValue_ >( 0.5 ) );
   }

#endif
#if( /* {public RoundValueToIntegerMidpointDown}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_,
         typename TInteger_
      >
   inline TInteger_ TMathHelpers::RoundValueToIntegerMidpointDown
      ( TValue_ value
      )
   {
      // This can overflow.
      return static_cast< TInteger_ >( RoundValueToIntegerMidpointDown( value ) );
   }

#endif
#if( /* {public RoundValueToMultipleOfMidpointDown}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline TValue_ TMathHelpers::RoundValueToMultipleOfMidpointDown
      ( TValue_ value,
        TValue_ valueDivisor
      )
   {
      // This can overflow.
      return RoundValueToIntegerMidpointDown( value / valueDivisor ) * valueDivisor;
   }

#endif
#if( /* {public RoundNonPositiveValueToIntegerMidpointDown}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_,
         typename TInteger_
      >
   inline TInteger_ TMathHelpers::RoundNonPositiveValueToIntegerMidpointDown
      ( TValue_ value
      )
   {
      // I don't want to assume this.
      assert( value <= static_cast< TValue_ >( 0.5 ) );

      // This can overflow.
      return static_cast< TInteger_ >( value - static_cast< TValue_ >( 0.5 ) );
   }

#endif
#if( /* {public RoundValueToIntegerMidpointUp}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline TValue_ TMathHelpers::RoundValueToIntegerMidpointUp
      ( TValue_ value
      )
   {
      // This can't overflow.
      return ::std::floor( value + static_cast< TValue_ >( 0.5 ) );
   }

#endif
#if( /* {public RoundValueToIntegerMidpointUp}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_,
         typename TInteger_
      >
   inline TInteger_ TMathHelpers::RoundValueToIntegerMidpointUp
      ( TValue_ value
      )
   {
      // This can overflow.
      return static_cast< TInteger_ >( RoundValueToIntegerMidpointUp( value ) );
   }

#endif
#if( /* {public RoundValueToMultipleOfMidpointUp}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_
      >
   inline TValue_ TMathHelpers::RoundValueToMultipleOfMidpointUp
      ( TValue_ value,
        TValue_ valueDivisor
      )
   {
      // This can overflow.
      return RoundValueToIntegerMidpointUp( value / valueDivisor ) * valueDivisor;
   }

#endif
#if( /* {public RoundNonNegativeValueToIntegerMidpointUp}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TValue_,
         typename TInteger_
      >
   inline TInteger_ TMathHelpers::RoundNonNegativeValueToIntegerMidpointUp
      ( TValue_ value
      )
   {
      // I don't want to assume this.
      assert( value >= static_cast< TValue_ >( - 0.5 ) );

      // This can overflow.
      return static_cast< TInteger_ >( value + static_cast< TValue_ >( 0.5 ) );
   }

#endif
#if( /* //{RoundValuePrototype}. */ 0 )

void RoundValuePrototype()
{
   // The timings were obtained on the Vinax server.

   // TODO 3 yg? Test if it's faster to round a small real number to a multiple of another real number via rounding to {int} or {long}.

   //::timeBeginPeriod( 1U );
   //::Sleep( 1U );

   double sum1( 0.0 );
   int minTimeSpan1( ::std::numeric_limits< int >::max() );

   unsigned __int64 randomNumber1( ::__rdtsc() );
   randomNumber1 = ( randomNumber1 << 32U ) | ( randomNumber1 >> 32U );

   for( int counter2( 0 ) ; counter2 < 50000 ; ++ counter2 )
   {
      ::LARGE_INTEGER performanceCounter1;
      ::QueryPerformanceCounter( & performanceCounter1 );
      randomNumber1 ^= static_cast< unsigned __int64 >( performanceCounter1.QuadPart );

      for( int counter1( 0 ) ; counter1 < 10000 ; ++ counter1 )
      {
         randomNumber1 = randomNumber1 * 9U + 1U;
         double double1
            ( static_cast< double >( static_cast< __int64 >( randomNumber1 ) )
              * ( 1.0 / static_cast< double >( static_cast< unsigned __int64 >( 1U ) << ( 64U - 14U ) ) )
            //  / static_cast< double >( static_cast< unsigned __int64 >( 1U ) << ( 64U - 14U ) )
            );

// TODO 3 yg? Add this as another set of "quick" rounding methods, including rounding to a multiple of.
#if( 0 )
         // Midpoint away from 0.0.
         // The result is probably not guaranteed to be rounded.
         // 654
         {
            double double1Truncated;
            double double1Fraction( ::std::modf( double1, ( & double1Truncated ) ) );
            double double1RoundedMidpointAwayFromZero
               ( double1Truncated + static_cast< double >( static_cast< int >( double1Fraction * 2.0 ) ) );
            sum1 += double1RoundedMidpointAwayFromZero;
            continue;
         }
#endif

#if( 0 )
         // Midpoint away from 0.0.
         // 1279
         {
            double double1Truncated;
            double double1Fraction( ::std::modf( double1, ( & double1Truncated ) ) );
            double double1RoundedMidpointAwayFromZero;
            //::std::modf( double1Truncated + double1Fraction * 2.0, ( & double1RoundedMidpointAwayFromZero ) );
            ::std::modf( double1 + double1Fraction, ( & double1RoundedMidpointAwayFromZero ) );
            sum1 += double1RoundedMidpointAwayFromZero;
            continue;
         }
#endif

#if( 0 )
         // Midpoint away from 0.0.
         // 3203
         {
            double double1Fraction( ::std::fmod( double1, 1.0 ) );
            double double1RoundedMidpointAwayFromZero;
            ::std::modf( double1 + double1Fraction, ( & double1RoundedMidpointAwayFromZero ) );
            sum1 += double1RoundedMidpointAwayFromZero;
            continue;
         }
#endif

#if( 0 )
         // Midpoint away from 0.0.
         // 947
         {
            double double1RoundedMidpointAwayFromZero( ( double1 >= 0.0 ) ? ::std::floor( double1 + 0.5 ) : ::std::ceil( double1 - 0.5 ) );
            sum1 += double1RoundedMidpointAwayFromZero;
            continue;
         }
#endif

#if( 0 )
         // Midpoint away from 0.0.
         // 1338
         {
            double double2( ::std::floor( ::std::abs( double1 ) + 0.5 ) );
            double double8( ::_copysign( double2, double1 ) );
            sum1 += double8;
            continue;
         }
#endif

#if( 0 )
         // Midpoint up.
         // 952
         {
            double double2( ::std::floor( double1 + 0.5 ) );
            sum1 += double2;
            continue;
         }
#endif

#if( 0 )
         // Midpoint down.
         // 951
         {
            double double2( ::std::ceil( double1 - 0.5 ) );
            sum1 += double2;
            continue;
         }
#endif

#if( 0 )
         // To integer, midpoint away from 0.0.
         // 1054
         {
            double double2( ( double1 >= 0.0 ) ? ::std::floor( double1 + 0.5 ) : ::std::ceil( double1 - 0.5 ) );
            int int1( static_cast< int >( double2 ) );
            sum1 += static_cast< double >( int1 );
            continue;
         }
#endif

#if( 0 )
         // To integer, midpoint away from 0.0.
         // 705
         {
            double double2( double1 + ::_copysign( 0.5, double1 ) );
            int int1( static_cast< int >( double2 ) );
            sum1 += static_cast< double >( int1 );
            continue;
         }
#endif

#if( 0 )
         // To integer, midpoint away from 0.0.
         // 517
         {
            //double1 = counter1 * 0.125 - 2.5;
            
            int double1AsInt( static_cast< int >( double1 ) );
            double double1Fraction( double1 - static_cast< double >( double1AsInt ) );
            int double1RoundedMidpointAwayFromZeroAsInt( static_cast< int >( double1Fraction * 2.0 ) + double1AsInt );

            //::std::cout
            //   << double1
            //   << ' '
            //   << double1RoundedMidpointAwayFromZero
            //   << ::std::endl;

            sum1 += static_cast< double >( double1RoundedMidpointAwayFromZeroAsInt );
            continue;
         }
#endif

#if( 0 )
         // To integer, midpoint away from 0.0.
         // 490
         {
            int double1AsInt( static_cast< int >( double1 ) );
            double double1Fraction( double1 - static_cast< double >( double1AsInt ) );
            int double1RoundedMidpointAwayFromZeroAsInt( static_cast< int >( double1 + double1Fraction ) );
            sum1 += static_cast< double >( double1RoundedMidpointAwayFromZeroAsInt );
            continue;
         }
#endif

#if( 0 )
         // To integer, midpoint away from 0.0.
         // 2929
         {
            double double1Fraction( ::std::fmod( double1, 1.0 ) );
            int double1RoundedMidpointAwayFromZeroAsInt( static_cast< int >( double1 + double1Fraction ) );
            sum1 += static_cast< double >( double1RoundedMidpointAwayFromZeroAsInt );
            continue;
         }
#endif

#if( 0 )
         // To integer, midpoint away from 0.0.
         // 709
         {
            int double1RoundedMidpointAwayFromZeroAsInt( static_cast< int >( ( double1 >= 0.0 ) ? ( double1 + 0.5 ) : ( double1 - 0.5 ) ) );
            sum1 += static_cast< double >( double1RoundedMidpointAwayFromZeroAsInt );
            continue;
         }
#endif

#if( 0 )
         // A non-negative value to integer, midpoint up.
         // 321
         {
            int int1( static_cast< int >( double1 + 0.5 ) );
            sum1 += static_cast< double >( int1 );
            continue;
         }
#endif

#if( 0 )
         // To integer, midpoint towards 0.0.
         // 1019
         {
            //double1 = counter1 * 0.25 - 2.5;

            int double1AsInt( static_cast< int >( double1 ) );
            double double1Fraction( double1 - static_cast< double >( double1AsInt ) );
            int double1RoundedMidpointTowardsZeroAsInt;

            if( double1Fraction > 0.5 )
            {
               double1RoundedMidpointTowardsZeroAsInt = double1AsInt + 1;
            }
            else
            {
               if( double1Fraction < ( - 0.5 ) )
               {
                  double1RoundedMidpointTowardsZeroAsInt = double1AsInt - 1;
               }
               else
               {
                  double1RoundedMidpointTowardsZeroAsInt = double1AsInt;
               }
            }
            
            //::std::cout
            //   << double1
            //   << ' '
            //   << double1RoundedMidpointTowardsZeroAsInt
            //   << ::std::endl;
            
            sum1 += static_cast< double >( double1RoundedMidpointTowardsZeroAsInt );
            continue;
         }
#endif

#if( 0 )
         // To integer, midpoint towards 0.0.
         // 1106
         {
            //double1 = counter1 * 0.25 - 2.5;

            int double1AsInt( static_cast< int >( double1 ) );
            double double1Fraction( double1 - static_cast< double >( double1AsInt ) );
            int double1RoundedMidpointTowardsZeroAsInt;

            if( double1AsInt >= 0 )
            {
               if( double1Fraction > 0.5 )
               {
                  double1RoundedMidpointTowardsZeroAsInt = double1AsInt + 1;
               }
               else
               {
                  double1RoundedMidpointTowardsZeroAsInt = double1AsInt;
               }
            }
            else
            {
               if( double1Fraction < ( - 0.5 ) )
               {
                  double1RoundedMidpointTowardsZeroAsInt = double1AsInt - 1;
               }
               else
               {
                  double1RoundedMidpointTowardsZeroAsInt = double1AsInt;
               }
            }
            
            //::std::cout
            //   << double1
            //   << ' '
            //   << double1RoundedMidpointTowardsZeroAsInt
            //   << ::std::endl;
            
            sum1 += static_cast< double >( double1RoundedMidpointTowardsZeroAsInt );
            continue;
         }
#endif

#if( 0 )
         // To integer, midpoint towards 0.0.
         // This is probably incorrect. I haven't tested this.
         // 
         {
            int double1AsInt( static_cast< int >( double1 ) );
            double double1Fraction( double1 - static_cast< double >( double1AsInt ) );
            double double1DoubleFraction( double1Fraction * 2.0 );

            // Problrm is that this can potentially be 2 or -2.
            int double1DoubleFractionAsInt( static_cast< int >( double1DoubleFraction ) );

            int double1RoundedMidpointTowardsZeroAsInt;
            
            if( double1DoubleFractionAsInt != 0 )
            {
               if( double1DoubleFraction != static_cast< double >( double1DoubleFractionAsInt ) )
               {
                  double1RoundedMidpointTowardsZeroAsInt = double1AsInt + double1DoubleFractionAsInt;
               }
               else
               {
                  double1RoundedMidpointTowardsZeroAsInt = double1AsInt;
               }
            }
            else
            {
               double1RoundedMidpointTowardsZeroAsInt = double1AsInt;
            }
            
            sum1 += static_cast< double >( double1RoundedMidpointTowardsZeroAsInt );
            continue;
         }
#endif
      }

      ::LARGE_INTEGER performanceCounter2;
      ::QueryPerformanceCounter( & performanceCounter2 );
      int timeSpan1( static_cast< int >( performanceCounter2.LowPart ) - static_cast< int >( performanceCounter1.LowPart ) );
      if( timeSpan1 < minTimeSpan1 )
      {
         minTimeSpan1 = timeSpan1;
         ::std::cout
            << minTimeSpan1
            //<< ' '
            //<< timeSpan1
            << ' '
            << sum1
            << ::std::endl;
      }
      else
      {
      }
   }
}

#endif

#if( /* {public ScaleNumber}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMathHelpers::ScaleNumber
      ( unsigned int number,
        unsigned int scaledNumberMinLimit,
        unsigned int scaledNumberMaxLimit
      )
   {
      // See prototype below.
      // It's undocumented whether this logic rounds midpoint up or down.
      // In the reality we use the faster expression that rounds midpoint down.
      // In some scenarios it might be better to randomly choose one or the other scaling algorithm.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( scaledNumberMinLimit <= scaledNumberMaxLimit );
      unsigned int scaledNumber
         ( static_cast< unsigned int >( ( ( static_cast< ::Poco::UInt64 >( number ) + 0U ) *
                                                             ( static_cast< ::Poco::UInt64 >( scaledNumberMaxLimit - scaledNumberMinLimit ) + 1U ) +
                                                             0U
                                                          ) /
                                                          ( static_cast< ::Poco::UInt64 >( ::std::numeric_limits< unsigned int >::max() ) + 1U )
                                                        ) +
           scaledNumberMinLimit
         );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( scaledNumber >= scaledNumberMinLimit );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( scaledNumber <= scaledNumberMaxLimit );
      return scaledNumber;
   }

   #if( /* //Prototype. */ 0 )

      public static void ScaleNumberPrototype()
      {
         // Integer scailing prototype.

         const uint scaledNumberMinLimit = 10U;
         const uint scaledNumberMaxLimit = 14U;
         //const uint scaledNumberMaxLimit = 101U;
         //const uint scaledNumberMaxLimit = 256U;
         uint[] scaledNumbersCounter = new uint[ (int) ( scaledNumberMaxLimit - scaledNumberMinLimit + 1U ) ];

         long timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp();
         timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp();

         for( uint number = 0U ; ; )
         {
#if( false )
            // Method 1.
            {
               // On most processors this division is lossless, right? So there would be no precision improvement from a rearrangement of expressions.
               // But this might not be the case on some processors.
               double zeroInclusiveToOneNotInclusive = number * ( 1.0 / ( (double) uint.MaxValue + 1.0 ) );
               
               // From 0.0 inclusive to {(double) ( scaledNumberMaxLimit - scaledNumberMinLimit ) + 1.0} not inclusive.
               // yg? But this probably won't work for a huge 64-bit number due to insufficient {double} resolution.
               double double1 =
                  ( (double) ( scaledNumberMaxLimit - scaledNumberMinLimit ) + 1.0 ) *
                  zeroInclusiveToOneNotInclusive;

               uint scaledNumber = (uint) double1 + scaledNumberMinLimit;

               ++ scaledNumbersCounter[ (int) ( scaledNumber - scaledNumberMinLimit ) ];
            }
#endif

#if( true )
            // Method 2. It's faster.
            {
               // Test.
               //double testDouble1 = (double) ( (ulong) number * ( (ulong) ( scaledNumberMaxLimit - scaledNumberMinLimit ) + 1U ) + ( scaledNumberMaxLimit - scaledNumberMinLimit + 1U - 1U ) ) / (double) ( (ulong) uint.MaxValue + 1U );

               uint scaledNumber =
   #if( true )
                  // This rounds midpoint down.
                  // This is faster.
                  (uint) ( ( ( (ulong) number + 0U ) *
                                 ( (ulong) ( scaledNumberMaxLimit - scaledNumberMinLimit ) + 1U ) +
                                 0U
                               ) /
                               ( (ulong) uint.MaxValue + 1U )
                            ) +
   #else
                  // This rounds midpoint up.
                  // This is slower.
                  // One might argue that this logic is more correct as it results in the numerator being maximum possible.
                  (uint) ( ( // This multiplication can overflow but subsequent decrement will fix the problem.
                                 // We have to add 1 to both multipliers so that it was guaranteed that subsequent decrement won't overflow.
                                 ( (ulong) number + 1U ) *
                                 ( (ulong) ( scaledNumberMaxLimit - scaledNumberMinLimit ) + 1U ) -

                                 1U
                               ) /

                               // A division by this is equivalent to shifting right by 32. The compiler probably optimizes this.
                               ( (ulong) uint.MaxValue + 1U )
                            ) +
   #endif
                  scaledNumberMinLimit;

               ++ scaledNumbersCounter[ (int) ( scaledNumber - scaledNumberMinLimit ) ];
            }
#endif

            if( ( ++ number ) > 0U )
            //if( ( number += 256U ) > 0U )
            {
            }
            else
            {
               break;
            }
         }

         timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp() - timeSpan1;
         System.Media.SystemSounds.Beep.Play();

         double timeSpan1Milliseconds = (double) timeSpan1 * 1000.0 / (double) System.Diagnostics.Stopwatch.Frequency;
         System.Console.WriteLine( timeSpan1Milliseconds.ToString( @"F0" ) );

         System.Console.WriteLine();
         System.Console.WriteLine( scaledNumbersCounter.Min() );
         System.Console.WriteLine( scaledNumbersCounter.Max() );
         ulong scaledNumbersCounterSum = 0U;
         foreach( uint scaledNumberCounter in scaledNumbersCounter )
         {
            scaledNumbersCounterSum += scaledNumberCounter;
         }

         // This is expected to print @"0x100000000".
         System.Console.WriteLine( @"0x" + scaledNumbersCounterSum.ToString( @"X" ) );

         System.Console.WriteLine();
         for( int counter2 = 0 ; counter2 < scaledNumbersCounter.Length ; ++ counter2 )
         {
            System.Console.Write( (uint) counter2 + scaledNumberMinLimit );
            System.Console.Write( ' ' );
            System.Console.WriteLine( scaledNumbersCounter[ counter2 ] );
         }
      }

   #endif

#endif

#if( /* {public CalculateCheckSum}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMathHelpers::CalculateCheckSum
//TODO rename this to {data}?
      ( unsigned int const * dataBegin,
//TODO maybe this is also a good idea. maybe we can have an overload
        //unsigned int const * dataEnd,
        int dataLength,
        unsigned int initialCheckSum
        //unsigned int shiftInitialOffset
      )
   {
      dataBegin = 0;
      //dataEnd = 0;
      dataLength = 0;
      initialCheckSum = 0;
      //shiftInitialOffset = 0;


   //inline unsigned int TPeerData::CalculateCheckSum() const
   //{
   //   // This implementation is not designed to be secure.
   //
   //   unsigned int checkSum1( CheckSumFactor1 );
   //   unsigned int uint1;
   //   //uint1 = IsWarmUpOrTestModePlace;
   //
   //   // See {IsWarmUpOrTestMode} comment.
   //   uint1 = reinterpret_cast< unsigned int const & >( IsWarmUpOrTestMode );
   //
   //   checkSum1 ^= uint1;
   //   uint1 = static_cast< unsigned int >( StrategyState1Code );
   //   checkSum1 ^= ( uint1 << 5U ) | ( uint1 >> ( static_cast< unsigned int >( sizeof( uint1 ) * 8U - 5U ) ) );
   //   uint1 = static_cast< unsigned int >( PositionExpectedDirectionCode );
   //   checkSum1 ^= ( uint1 << 10U ) | ( uint1 >> ( static_cast< unsigned int >( sizeof( uint1 ) * 8U - 10U ) ) );
   //   return checkSum1;
   //}

      // Do we need a method like this?
      //public static int MergeHashCodes
      //   ( int hashCode1,
      //     int hashCode2
      //   )
      //{
      //   const int shiftOffsetIncrement = 7;
      //   return ( (int) ( (uint) hashCode1 >> shiftOffsetIncrement ) |
      //                ( hashCode1 << ( sizeof( int ) * 8 - shiftOffsetIncrement ) )
      //              ) ^
      //              hashCode2;
      //}


// TODO
//validate sizeof( * dataBegin ) == 4U
// n1 = initialShiftFactor & 0x1F
// n2 = ( ( 4U * 8U ) - n1 ) & 0x1F
//verify!!!
//validate that n1+n2==32U || (n1|n2)==0U
//check how I did this elsewhere, peer data?
//did i get it right in request pre-send bitmask?
//btw, sizeof(uint)-1U==0x1FU

//Acually see MergeHashCodes/MergeHashCodesPrototype in UniversalFX. we dont need shiftInitialOffset
//see CSharpTest1.Test34; move it here as a prototype
//cycle-shift right by 7, it will often split the number

//rename this method to use the word hash code, or hash sum?
//checksum is better
//the word code is incorrect

//      CircularBitwiseShiftValueRight

      return 0U;
   }

#endif

#if( /* {public CalculateNextCheapMovingAverage}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TCheapMovingAverage_
      >
   inline TCheapMovingAverage_ TMathHelpers::CalculateNextCheapMovingAverage
      ( TCheapMovingAverage_ cheapMovingAverage1,
        TCheapMovingAverage_ value1,
        TCheapMovingAverage_ factor2
      )
   {
      // See prototype below.
      // yg? There has got to be a cleaner way to accomplish this.
      // yg? Bug: when {factor2 == 0.0} or is very close to 0.0, the result will be incorrect.

      TCheapMovingAverage_ cheapMovingAverage2( cheapMovingAverage1 + ( value1 - cheapMovingAverage1 ) * factor2 );

// TODO Can I do something like {value1 + ( cheapMovingAverage1 - value1 ) * ( 1.0 - factor2 )}?
// TODO It might work without any additional logic.
// TODO Actually this formula exists in the prototype below...

      // Forcing the type-cast just in case otherwise an unrounded higher precision {cheapMovingAverage2} would be used for comparison.
      // yg?? Bug: in the Release Win32 build this logic gets over-optimized, which results in the exact behavior it's designed to prevent,
      // yg?? at least when {value1} is 0.0. This works correct in the Release x64 build though, possibly because it uses
      // yg?? 64-bit floating point registers. This results in the number of trades cheap moving average converging to about 1.98e-323.
      // yg?? This probably doesn't currently inflict damage.
      // TODO 3 yg?? Try using the strict floating point model for this comparison expression only.
      return
         ( static_cast< TCheapMovingAverage_ >( cheapMovingAverage2 ) != static_cast< TCheapMovingAverage_ >( cheapMovingAverage1 ) ) ?
         cheapMovingAverage2 :
         value1;
   }

   #if( /* //Prototype. */ 0 )

void CalculateNextCheapMovingAveragePrototype()
{
   __int64 timeStamp1( static_cast< __int64 >( ::__rdtsc() ) );
   __int64 timeStamp2( static_cast< __int64 >( ::__rdtsc() ) );
   __int64 timeStamp3( static_cast< __int64 >( ::__rdtsc() ) );
   __int64 timeSpan1( timeStamp2 - timeStamp1 );
   __int64 timeSpan2( timeStamp3 - timeStamp2 );
   ::std::cout << timeSpan1 << ::std::endl;
   ::std::cout << timeSpan2 << ::std::endl;

   //double epsilon( ::std::numeric_limits< double >::epsilon() );

   for( int counter2( 0 ) ; counter2 < 1000 ; ++ counter2 )
   {
      //double factor2( 0.125 );
      //double factor2( 1.0 - 0.125 );
      //double factor2( 0.4 );
      double factor2( ( ::__rdtsc() % 100000000 ) / 99000000.0 );
      //double factor2( 1.0 );
      double cheapMovingAverage( 0.6 );
      //double value1( -1.0 );
      double value1( static_cast< double >( ::__rdtsc() ) );
      //double value1( 0.0 );

      //if( factor2 == 0.0 )
      //{
      //   ++ factor2;
      //}

      for( int counter1( 0 ) ; counter1 < 10000 ; ++ counter1 )
      {
         //cheapMovingAverage += ( value1 - cheapMovingAverage ) * factor2;
         //cheapMovingAverage = cheapMovingAverage + ( value1 - cheapMovingAverage ) * factor2;
         //cheapMovingAverage = cheapMovingAverage + value1 * factor2 - cheapMovingAverage * factor2;
         //cheapMovingAverage = cheapMovingAverage * ( 1.0 - factor2 ) + value1 * factor2;
         //cheapMovingAverage = cheapMovingAverage * ( 1.0 - factor2 ) + value1 * factor2 + value1 - value1;
         //cheapMovingAverage = value1 * factor2 + cheapMovingAverage * ( 1.0 - factor2 ) - value1 + value1;
         //cheapMovingAverage = value1 + value1 * ( factor2 - 1.0 ) + cheapMovingAverage * ( 1.0 - factor2 );
         //cheapMovingAverage = value1 + ( cheapMovingAverage - value1 ) * ( 1.0 - factor2 );

         //cheapMovingAverage += ::std::numeric_limits< double >::epsilon() * cheapMovingAverage * 0.9;

         //double cheapMovingAverageDifference( ( value1 - cheapMovingAverage ) * factor2 );

         //double tempDouble1( ( cheapMovingAverage - value1 ) * ( 1.0 - factor2 ) );
         //cheapMovingAverage = value1 - tempDouble1 + tempDouble1 * 2.0;
         ////cheapMovingAverage = value1 + tempDouble1;
         ////cheapMovingAverage = value1 + tempDouble1 * 2.0 - tempDouble1;

         double tempDouble1( ( value1 - cheapMovingAverage ) * factor2 );
         if( ( counter1 & 1 ) == 0 )
         {
            //cheapMovingAverage = cheapMovingAverage + tempDouble1 * 2.0 - tempDouble1;
            cheapMovingAverage = cheapMovingAverage + tempDouble1 * 1.25 - tempDouble1 * 0.25;
         }
         else
         {
            //cheapMovingAverage = cheapMovingAverage - tempDouble1 + tempDouble1 * 2.0;
            cheapMovingAverage = cheapMovingAverage - tempDouble1 * 0.25 + tempDouble1 * 1.25;
         }

         //cheapMovingAverage = value1 * factor2 + cheapMovingAverage - cheapMovingAverage * factor2;

         ////double tempDouble1( value1 - cheapMovingAverage );
         //cheapMovingAverage += ( value1 - cheapMovingAverage ) * factor2;
         //double tempDouble2( value1 - cheapMovingAverage );
         ////double tempDouble3( tempDouble2 - tempDouble1 );
         //tempDouble2 -= value1;
         //tempDouble2 = ( - tempDouble2 );


         if( counter1 % 500 == 0 )
         {
            DummyFunction();
         }

         if( cheapMovingAverage == value1 )
         {
            break;
         }
      }

      cheapMovingAverage -= value1;
      if( cheapMovingAverage == 0.0 )
      {
      }
      else
      {
         DummyFunction();
      }
   }
}

   #endif

#endif
}
}
