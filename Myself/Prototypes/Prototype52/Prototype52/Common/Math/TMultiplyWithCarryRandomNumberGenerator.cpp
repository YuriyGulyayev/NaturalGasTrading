#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TMultiplyWithCarryRandomNumberGenerator.hpp"

#include "../DataStructures/TUnionPair.cpp"
#include "../Time/TTimeHelpers.cpp"
#include "./TMathHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Math
{
#if( /* {(public)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public ValueZ}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::ValueZ() const
   {
      return ValueZ_;
   }

#endif
#if( /* {public ValueW}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::ValueW() const
   {
      return ValueW_;
   }

#endif
#if( /* {public SafeSeedValueZ}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TMultiplyWithCarryRandomNumberGenerator::SafeSeedValueZ
      ( unsigned int valueZSeed
      )
   {
      valueZSeed = TMathHelpers::ScaleNumber( valueZSeed, ValueZBadSeed1_ + 1U, ValueZBadSeed2_ - 1U );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( valueZSeed > ValueZBadSeed1_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( valueZSeed < ValueZBadSeed2_ );
      ValueZ_ = valueZSeed;
   }

#endif
#if( /* {public SafeSeedValueW}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TMultiplyWithCarryRandomNumberGenerator::SafeSeedValueW
      ( unsigned int valueWSeed
      )
   {
      valueWSeed = TMathHelpers::ScaleNumber( valueWSeed, ValueWBadSeed1_ + 1U, ValueWBadSeed2_ - 1U );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( valueWSeed > ValueWBadSeed1_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( valueWSeed < ValueWBadSeed2_ );
      ValueW_ = valueWSeed;
   }

#endif
#if( /* {public UnsafeSeedValueZ}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TMultiplyWithCarryRandomNumberGenerator::UnsafeSeedValueZ
      ( unsigned int valueZSeed
      )
   {
      // Not assuming these.
      // Some day I might need to eliminate these validations.
      assert( valueZSeed > ValueZBadSeed1_ );
      assert( valueZSeed < ValueZBadSeed2_ );

      ValueZ_ = valueZSeed;
   }

#endif
#if( /* {public UnsafeSeedValueW}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TMultiplyWithCarryRandomNumberGenerator::UnsafeSeedValueW
      ( unsigned int valueWSeed
      )
   {
      // Not assuming these.
      // Some day I might need to eliminate these validations.
      assert( valueWSeed > ValueWBadSeed1_ );
      assert( valueWSeed < ValueWBadSeed2_ );

      ValueW_ = valueWSeed;
   }

#endif
#if( /* {public Reseed}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TMultiplyWithCarryRandomNumberGenerator::Reseed()
   {
      // yg? Magic numbers hardcoded. Should some of them be moved to the class level?

      unsigned int const evenBitsBitMask
         ( ( 1U << 0U ) |
           ( 1U << 2U ) |
           ( 1U << 4U ) |
           ( 1U << 6U ) |
           ( 1U << 8U ) |
           ( 1U << 10U ) |
           ( 1U << 12U ) |
           ( 1U << 14U ) |
           ( 1U << 16U ) |
           ( 1U << 18U ) |
           ( 1U << 20U ) |
           ( 1U << 22U ) |
           ( 1U << 24U ) |
           ( 1U << 26U ) |
           ( 1U << 28U ) |
           ( 1U << 30U )
         );
      DataStructures::TUnionPair< ::Poco::UInt64, unsigned int[ 2U ] > seed;

      //unsigned int seedValue1( static_cast< unsigned int >( timeStamp1.epochMicroseconds() ) );
      //unsigned int seedValue2
      //   ( static_cast< unsigned int >( static_cast< ::Poco::UInt64 >( timeStamp1.epochMicroseconds() ) >> ( static_cast< unsigned int >( sizeof( /*::Poco::UInt64*/ unsigned int ) ) * 8U /*/ 2U*/ ) )
      //     //+ static_cast< unsigned int >( Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() )
      //     + static_cast< unsigned int >( reinterpret_cast< ::std::uintptr_t >( this ) )
      //   );
      
      //seed.Value1 =
      //   static_cast< ::Poco::UInt64 >( timeStamp1.epochMicroseconds() ) ^
      //   ( ( static_cast< ::Poco::UInt64 >( reinterpret_cast< ::std::uintptr_t >( this ) ) << 40U ) |
      //     ( static_cast< ::Poco::UInt64 >( reinterpret_cast< ::std::uintptr_t >( this ) ) >> 24U )
      //   );

      // yg? Consider generating the seeds with {::rand_s} (or is it {::std::rand_s}?) and scaling down the result.
      {
         ::Poco::Timestamp timeStamp1;
         ::Poco::Int64 cpuTimeStampCounter( Time::TTimeHelpers::GetCpuTimeStampCounter() );

         // I don't want to use {::_rotr64} here and in some places elsewhere in this class
         // as I want this logic to work regardless of how many bits are in these numbers.
         seed.Value1 =
            static_cast< ::Poco::UInt64 >( timeStamp1.epochMicroseconds() ) ^
            ( ( static_cast< ::Poco::UInt64 >( cpuTimeStampCounter ) << 32U ) /*|*/ ^
              ( static_cast< ::Poco::UInt64 >( cpuTimeStampCounter ) >> 32U )
            ) ^
            ( static_cast< ::Poco::UInt64 >( reinterpret_cast< ::std::uintptr_t >( this ) )
         
              // This probably ensures that if the address changes the power of 2 times while the timestamps stay unchanged
              // both Z and W seeds will change.
              // I don't want to scale the seeds down here because this little difference might get lost.
              * 3U
            );
      }

      //SafeSeedValueZ
      //   ( ( seed.Value2[ 0U ] & (    evenBitsBitMask ) ) |
      //     ( seed.Value2[ 1U ] & ( ~ evenBitsBitMask ) )
      //   );
      //SafeSeedValueW
      //   ( ( seed.Value2[ 1U ] & (    evenBitsBitMask ) ) |
      //     ( seed.Value2[ 0U ] & ( ~ evenBitsBitMask ) )
      //   );
      
      // This magic logic works for our hardcoded multipliers. It generates seeds within their respective correct ranges.
      // yg? But it creates a bias.
      // yg? An easier way to reduce bias might be to add a number to a seed
      // yg? that would statistically move the seed to the middle between the bad seeds. Currently we simply add 1.
      {
         {
            //unsigned int valueZSeed
            //   ( ( seed.Value2[ 0U ] & (    evenBitsBitMask ) ) |
            //     ( seed.Value2[ 1U ] & ( ~ evenBitsBitMask ) )
            //   );
            //
            //// This shift probably preserves a small {this} address change.
            //valueZSeed = ( ( valueZSeed << 1U ) & 0x7FFFFFFFU ) + ( ValueZBadSeed1_ + 1U );

            // yg? Actually, what that shift in the preceeding commented out code was for? Let's rewrite it.
            unsigned int valueZSeed
               ( ( seed.Value2[ 0U ] & ( (    evenBitsBitMask ) & 0x7FFFFFFFU ) ) |
                 ( seed.Value2[ 1U ] & ( ( ~ evenBitsBitMask ) & 0x7FFFFFFFU ) )
               );
            valueZSeed += ValueZBadSeed1_ + 1U;

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( valueZSeed > ValueZBadSeed1_ );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( valueZSeed < ValueZBadSeed2_ );
            ValueZ_ = valueZSeed;
         }

         {
            //unsigned int valueWSeed
            //   ( ( seed.Value2[ 1U ] & (    evenBitsBitMask ) ) |
            //     ( seed.Value2[ 0U ] & ( ~ evenBitsBitMask ) )
            //   );
            //
            //// This shift probably preserves a small {this} address change.
            //valueWSeed = ( ( valueWSeed << 1U ) & 0x7FFFFFFFU ) + ( ValueWBadSeed1_ + 1U );

            // yg? Actually, what that shift in the preceeding commented out code was for? Let's rewrite it.
            unsigned int valueWSeed
               ( ( seed.Value2[ 1U ] & ( (    evenBitsBitMask ) & 0x7FFFFFFFU ) ) |
                 ( seed.Value2[ 0U ] & ( ( ~ evenBitsBitMask ) & 0x7FFFFFFFU ) )
               );
            valueWSeed += ValueWBadSeed1_ + 1U;

            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( valueWSeed > ValueWBadSeed1_ );
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( valueWSeed < ValueWBadSeed2_ );
            ValueW_ = valueWSeed;
         }
      }

      //for( ; ; )
      //{
      //   ( * this )();
      //   unsigned int firstValueZ( ValueZ_ );
      //   unsigned int firstValueW( ValueW_ );
      //   ( * this )();
      //
      //   // I tested for our hardcoded multiplier that if these are unequal further generated numbers will not become equal.
      //   if( ValueZ_ != firstValueZ && ValueW_ != firstValueW )
      //
      //   {
      //      break;
      //   }
      //   else
      //   {
      //      // yg? Modifying both values even if only one is invalid.
      //      ValueZ_ += 0x01010101U;
      //      ValueW_ += 0x01010101U;
      //   }
      //}
   }

#endif
#if( /* {public AdvanceValueZ}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TMultiplyWithCarryRandomNumberGenerator::AdvanceValueZ()
   {
      unsigned int nextValueZ( ValueZ_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueZ > ValueZBadSeed1_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueZ < ValueZBadSeed2_ );
      nextValueZ = ValueZBadSeed2_ - nextValueZ + ValueZBadSeed1_;
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueZ > ValueZBadSeed1_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueZ < ValueZBadSeed2_ );
      nextValueZ = ValueZMultiplier_ * ( nextValueZ & 0xFFFFU ) + ( nextValueZ >> 16U );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueZ > ValueZBadSeed1_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueZ < ValueZBadSeed2_ );
      ValueZ_ = nextValueZ;
   }

#endif
#if( /* {public AdvanceValueW}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TMultiplyWithCarryRandomNumberGenerator::AdvanceValueW()
   {
      unsigned int nextValueW( ValueW_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueW > ValueWBadSeed1_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueW < ValueWBadSeed2_ );
      nextValueW = ValueWMultiplier_ * ( nextValueW & 0xFFFFU ) + ( nextValueW >> 16U );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueW > ValueWBadSeed1_ );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( nextValueW < ValueWBadSeed2_ );
      ValueW_ = nextValueW;
   }

#endif

#if( /* {public GenerateMediumQuality32Bits}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::GenerateMediumQuality32Bits()
   {
      AdvanceValueW();
      AdvanceValueZ();

      // We compliment the Z and flip the W. This probably works faster on a superscalar processor.
      unsigned int adjustedValueW( ValueW_ + ValueWAdjustment_ );
      unsigned int adjustedValueZ( ValueZ_ + ValueZAdjustment_ );

      // As mentioned in a comment elsewhere in this class, I don't want to use {::_rotr} here and in some places elsewhere in this class.
      unsigned int flippedAdjustedValueW( ( adjustedValueW << 16U ) /*|*/ ^ ( adjustedValueW >> 16U ) );

      return adjustedValueZ ^ flippedAdjustedValueW;
   }

#endif
#if( /* {public GenerateHighQuality16Bits}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::GenerateHighQuality16Bits()
   {
      return GenerateHighQuality16BitsRaw() & 0xFFFFU;
   }

#endif
#if( /* {public GenerateHighQuality16BitsRaw}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::GenerateHighQuality16BitsRaw()
   {
      AdvanceValueZ();
      AdvanceValueW();
      return ValueZ_ ^ ValueW_;
   }

#endif
#if( /* {public GenerateLowQuality16Bits}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::GenerateLowQuality16Bits()
   {
      return GenerateLowQuality16BitsRaw() & 0xFFFFU;
   }

#endif
#if( /* {public GenerateLowQuality16BitsRaw}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::GenerateLowQuality16BitsRaw()
   {
      // It's better to use the Z here as it has a longer period and is complimented.
      AdvanceValueZ();

      return ValueZ_;
   }

#endif
#if( /* {public GenerateLowQuality1Bit}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::GenerateLowQuality1Bit()
   {
      return GenerateLowQuality16Bits();
   }

#endif
#if( /* {public GenerateLowQuality1BitRaw}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::GenerateLowQuality1BitRaw()
   {
      return GenerateLowQuality16BitsRaw();
   }

#endif

#if( /* {public operator ()}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline unsigned int TMultiplyWithCarryRandomNumberGenerator::operator () ()
   {
      return GenerateMediumQuality32Bits();

      //// yg? Magic numbers hardcoded. Some of them should be moved to the class level.
      //
      //unsigned int const factor1Z( 65184U );
      //unsigned int const factor1W( 64860U );
      //
      //unsigned int const valueZBadSeed( ( ( factor1Z - 1U ) << 16U ) | 0xFFFFU );
      //unsigned int const valueWBadSeed( ( ( factor1W - 1U ) << 16U ) | 0xFFFFU );
      //
      //// These adjustments are added to the generated numbers to ensure that the values have the correct average. This in turn ensures that
      //// each bit has an about equal chance to be 0 or 1. Otherwise the highest order bit would tend to be 0.
      //unsigned int const factor2Z( ( ( 0xFFFFFFFFU - ( valueZBadSeed - 1U ) ) - 1U ) / 2U );
      ////   ( ( ( ::std::numeric_limits< unsigned int >::max() -
      ////         ( ( factor1Z *
      ////            ( ::std::numeric_limits< unsigned int >::max() &
      ////              static_cast< unsigned int >( ::std::numeric_limits< unsigned short >::max() )
      ////            )
      ////           ) +
      ////           ( ::std::numeric_limits< unsigned int >::max() >>
      ////            ( static_cast< unsigned int >( sizeof( unsigned int ) ) *
      ////              8U /
      ////              2U
      ////            )
      ////           )
      ////         ) +
      ////         1U
      ////       ) /
      ////       2U
      ////     ) +
      ////     0U
      ////   );
      //unsigned int const factor2W( ( ( 0xFFFFFFFFU - ( valueWBadSeed - 1U ) ) - 1U ) / 2U );
      ////   ( ( ( ::std::numeric_limits< unsigned int >::max() -
      ////         ( ( factor1W *
      ////            ( ::std::numeric_limits< unsigned int >::max() &
      ////              static_cast< unsigned int >( ::std::numeric_limits< unsigned short >::max() )
      ////            )
      ////           ) +
      ////           ( ::std::numeric_limits< unsigned int >::max() >>
      ////            ( static_cast< unsigned int >( sizeof( unsigned int ) ) *
      ////              8U /
      ////              2U
      ////            )
      ////           )
      ////         ) +
      ////         1U
      ////       ) /
      ////       2U
      ////     ) +
      ////     0U
      ////   );
      //
      //unsigned int nextValueZ( ValueZ_ );
      //nextValueZ = factor1Z * ( nextValueZ & 0xFFFFU ) + ( nextValueZ >> 16U );
      //unsigned int nextValueW( ValueW_ );
      //nextValueW = factor1W * ( nextValueW & 0xFFFFU ) + ( nextValueW >> 16U );
      //
      //ValueZ_ = nextValueZ;
      //ValueW_ = nextValueW;
      //
      //nextValueZ += factor2Z;
      //nextValueZ = ( nextValueZ << 16U ) | ( nextValueZ >> 16U );
      //nextValueW += factor2W;
      //return nextValueZ ^ nextValueW;
   }

#endif

#if( /* //Prototype. */ 0 )

      public static void Test100()
      {
         // A simple test that generates the whole period of random numbers.

         const uint b1Length = 5U;
         const uint a1 = 27U;
         const uint b1 = 1U << (int) b1Length;
         const uint x1BadSeed = ( a1 - 1U ) * b1 + ( b1 - 1U );
         
         //uint seed1 = 1U;
         uint seed1 = (uint) System.Diagnostics.Stopwatch.GetTimestamp();
         //uint seed1 = x1BadSeed;

         // This must not be 0 or {x1BadSeed}, besides some other bigger values that would be transformed to a bad seed.
         // yg? Does the complementary version have bad seeds?
         seed1 %= ( b1 * b1 );

         uint x1 = seed1;

         //uint x1Disruptor = 1U;

         ulong x1ModB1Sum = 0U;

         long period = 0;

         do
         {
            //x1Disruptor = (uint) ( - (int) x1Disruptor );
            //x1Disruptor = ( x1Disruptor + 1U ) % b1;

            x1 = x1BadSeed - x1;
            //x1 = x1BadSeed - x1 + 1U;
            //x1 = x1BadSeed - x1 + x1Disruptor;
            //x1 += x1Disruptor;
            //x1 = ( x1 % b1 + x1Disruptor ) % b1 + x1 / b1 * b1;
            //x1 -= x1BadSeed;
            //x1 += x1BadSeed;
            //x1 = x1 ^ 1U;
            //x1 = ( ~ x1 );

            //x1 %= ( b1 * b1 );

            x1 = a1 * ( x1 % b1 ) + x1 / b1;

            x1ModB1Sum += x1 % ( b1 * 1U );
            //x1ModB1Sum += x1 % ( b1 * 2U );
            //x1ModB1Sum += x1 % ( b1 / 2U );

            ++ period;
         }
         while( x1 != seed1 );

         System.Console.WriteLine( period );
         System.Console.WriteLine( (double) x1ModB1Sum / (double) period - (double) ( b1 - 1U ) * 0.5 );
      }

      public static void Test101()
      {
         // Searches for an {a} that makes a safe prime.
         
         checked
         {
            for( uint bLength = 16U ; bLength >= 2U ; -- bLength )
            {
               uint b = 1U << (int) bLength;
               //uint b = ( 1U << (int) bLength ) - 1U;
               System.Console.Write( @"bLength = " );
               System.Console.Write( bLength );
               System.Console.Write( @"U; b = " );
               System.Console.Write( b );
               System.Console.Write( @"U; a = " );
               bool aFound = false;

               // It's OK when {a >= b}.
               //for( uint a = 2U ; a <= b * 1U ; ++ a )
               //for( uint a = 2U ; a <= b * 2U ; ++ a )
               //for( uint a = 2U ; a <= b * 4U ; ++ a )
               for( uint a = b * 4U ; a >= 2U ; -- a )

               {
                  // The generated number period will be equal {a * b / 2U - 1U}.
                  // Since it's a prime there is no possibility of the periods of different {a}'s having a common divisor greater than 1.
                  // Otherwise when we use multiple {a}'s the total period would be shorter.
                  if( ! ( Test101_IsNumberPrime( (ulong) a * (ulong) b / 2U - 1U ) && Test101_IsNumberPrime( (ulong) a * (ulong) b - 1U ) ) )

                  // This is for the complimentary algorithm.
                  //if( ! Test101_IsNumberPrime( (ulong) a * (ulong) b + 1U ) )

                  {
                  }
                  else
                  {
                     if( ! aFound )
                     {
                        aFound = true;
                     }
                     else
                     {
                        System.Console.Write( @", " );
                     }
                     System.Console.Write( a );
                     System.Console.Write( 'U' );
                  }
               }

               System.Console.WriteLine();
            }
         }
      }
      
      public static bool Test101_IsNumberPrime
         ( ulong value1
         )
      {
         // This implementation is inefficient and that's OK.
         // yg? This implementation will probably not behave correctly when {value1} is close to overflow, or maybe even many orders of magnitude away from it.

         System.Diagnostics.Debug.Assert( value1 > 0U );
         uint value1SquareRootAsUInt = (uint) System.Math.Sqrt( (double) value1 );

         // This protects us from a possible rounding error.
         // yg? Note that when {value1} if a huge 64-bit number there will be a big rounding error and this adjustment might not be sufficient.
         value1SquareRootAsUInt = (uint) System.Math.Min( (ulong) value1SquareRootAsUInt + 2U, value1 - 1U );

         for( uint counter1 = 2U ; counter1 <= /*( value1 + 0U ) / 2U*/ value1SquareRootAsUInt ; ++ counter1 )
         {
            if( value1 % counter1 > 0U )
            {
            }
            else
            {
               return false;
            }
         }
         return true;
      }

      public static void Test102()
      {
         checked
         {
            const uint b = 1U << 8/*U*/;
            //const uint b = 1U << 11/*U*/;
            //const uint b = 1U << 16/*U*/;

            // yg? Is it possible to implement efficient calculations with this base?
            // yg? Can something like a bitwise x-or with 0xFFFEU work? But it would still be an overhead.
            //const uint b = ( 1U << 12/*U*/ ) - 1U;
            //const uint b = ( 1U << 16/*U*/ ) - 1U;

            int minOutcomeCode = int.MaxValue;
            int maxOutcomeCode = int.MinValue;

            // It's OK when {a >= b}.
            //for( uint a = 2U ; a <= b * 4U ; ++ a )
            for( uint a = b * 4U ; a >= 2U ; -- a )

            {
               if( ! ( Test101_IsNumberPrime( (ulong) a * (ulong) b / 2U - 1U ) && Test101_IsNumberPrime( (ulong) a * (ulong) b - 1U ) ) )
               //if( ! Test101_IsNumberPrime( (ulong) a * (ulong) b + 1U ) )
               {
               }
               else
               {
                  int outcomeCode = Test102_1( a, b );
                  minOutcomeCode = System.Math.Min( minOutcomeCode, outcomeCode );
                  maxOutcomeCode = System.Math.Max( maxOutcomeCode, outcomeCode );

                  //if( outcomeCode < 13 )
                  //{
                  //}
                  //else
                  //{
                  //   break;
                  //}
               }
            }

            System.Console.WriteLine();
            System.Console.Write( minOutcomeCode );
            System.Console.Write( ' ' );
            System.Console.WriteLine( maxOutcomeCode );
         }
      }

      public static int Test102_1
         ( uint a,
           uint b
         )
      {
         // Generation of the next number.

         //const uint a = 65184U;
         //const uint a = 64860U;
         //const uint a = 64545U;
         //const uint a = 64455U;
         //const uint a = 36969U;
         //const uint a = 18000U;

         // Complimentary.
         //const uint a = 65193U;

         //for( ; ; )
         {
            // This seed will result in the period of 1.
            // Another {x} bad seed is 0U.
            // Bigger seeds will be OK, even though they are not generatable, but some will not be OK if {a} and/or {b} is small enough.
            // Generatable {x} can be from 1U to {xBadSeed - 1U}.
            uint xBadSeed = ( a - 1U ) * b + ( b - 1U );

            // At least one of these must be a nonzero and {cSeed != a - 1U || x0Seed != b - 1U}.
            // As mentioned in the {xBadSeed} comment, some other bad seeds are possible as well.
            uint cSeed;
            uint x0Seed;

            for( ; ; )
            {
               uint seed1 = ( ( (uint) System.DateTime.UtcNow.Ticks << 8/*U*/ ) + (uint) System.Diagnostics.Stopwatch.GetTimestamp() );
               cSeed = seed1 % a;
               seed1 /= a;
               x0Seed = seed1 % b;
               if( ! ( cSeed == 0U && x0Seed == 0U || cSeed == a - 1U && x0Seed == b - 1U ) )
               {
                  break;
               }
               else
               {
               }
            }

            //cSeed = 0xFFFFFFFFU;
            //cSeed = 0U;
            //cSeed = a - 1U;
            //x0Seed = 0U;
            //x0Seed = b - 1U;

            uint x0 = x0Seed;
            uint c = cSeed;
            uint minC = uint.MaxValue;
            uint maxC = 0U;
            uint minX0 = uint.MaxValue;
            uint maxX0 = 0U;
            uint minX = uint.MaxValue;
            uint maxX = 0U;

            // A period is by definition a positive number, even if the same number is always generated due to bad seed.
            uint period = 0U;

            for( ; ; )
            {
               ++ period;

               // This doubles the period and results in all numbers from 1U to {xBadSeed - 1U} being generated.
               // Otherwise only a half of them can be generated and their average is not exactly in the middle of the range.
               //c = ( a - 1U ) - c;
               //x0 = ( b - 1U ) - x0;

               // This is how to combine {x0} and {c} in a single number.
               uint x = c * b + x0;
               
               // This is another way to double the period.
               x = xBadSeed - x;

               //x += ( x & 1U );
               //if( x <= xBadSeed / 2U )
               //{
               //   ++ x;
               //}
               //else
               //{
               //   -- x;
               //}

               c = x / b;
               x0 = x % b;

               // Next number generation. Doing the same thing in 2 different ways.
               {
                  x = a * ( x % b ) + x / b;

                  {
                     uint x1 =
                        //(

                        // Complementary.
                        // A bitwise not or x-or might be a way to implement this efficiently.
                        // This doesn't appear to work when {b == 1U << N} but does when {b == ( 1U << N ) - 1U}.
                        //( b - 1U ) -

                        ( a * x0 + c )
                        //)
                        % b;
                     c = ( a * x0 + c ) / b;
                     x0 = x1;
                  }
               }

               //uint x = c * b + x0;

               // This validation can fail on the 1st and maybe a few further iterations if the seed values are out of range.
               System.Diagnostics.Debug.Assert( x == c * b + x0 );
               System.Diagnostics.Debug.Assert( x / b == c );
               System.Diagnostics.Debug.Assert( x % b == x0 );

               minC = System.Math.Min( minC, c );
               maxC = System.Math.Max( maxC, c );
               minX0 = System.Math.Min( minX0, x0 );
               maxX0 = System.Math.Max( maxX0, x0 );
               minX = System.Math.Min( minX, x );
               maxX = System.Math.Max( maxX, x );

               if( x0 != x0Seed || c != cSeed )
               {
               }
               else
               {
                  break;
               }

               // This logic protects us just in case the seeds and possibly a few first generated numbers are values that can't be generated again.
               // This can happen if the seeds are out of range or {a} is invalid.
               // This works when {(ulong) a * (ulong) b <= 0x100000000UL}.
               if( period != a * b )
               {
               }
               else
               {
                  System.Console.WriteLine();
                  System.Console.WriteLine( @"Error 1." );
                  System.Console.Write( cSeed );
                  System.Console.Write( ' ' );
                  System.Console.WriteLine( x0Seed );
                  System.Console.Write( c );
                  System.Console.Write( ' ' );
                  System.Console.WriteLine( x0 );
               
                  x0Seed = x0;
                  cSeed = c;
                  minC = uint.MaxValue;
                  maxC = 0U;
                  minX0 = uint.MaxValue;
                  maxX0 = 0U;
                  minX = uint.MaxValue;
                  maxX = 0U;
                  period = 0U;
               }
            }

            int outcomeCode;
            if( period >= ( a * b / 2U - 1U ) - 4U )
            {
               if( period == a * b / 2U - 1U )
               {
                  outcomeCode = 11;
               }
               else
               {
                  if( period == a * b / 2U )
                  {
                     outcomeCode = 12;
                  }
                  else
                  {
                     // When {b} is even, this is the same as {( a * b / 2U - 1U ) * 2U}.
                     // And therefore this is not a prime. But a half of it is.
                     if( period == a * b - 2U )

                     {
                        outcomeCode = 13;
                     }
                     else
                     {
                        if( period == a * b - 1U )
                        {
                           outcomeCode = 14;
                        }
                        else
                        {
                           if( period == a * b )
                           {
                              outcomeCode = 15;
                           }
                           else
                           {
                              if( period == a * b + 1U )
                              {
                                 outcomeCode = 16;
                              }
                              else
                              {
                                 outcomeCode = 19;
                              }
                           }
                        }
                     }
                  }
               }
            }
            else
            {
               outcomeCode = 10;
            }

            System.Console.WriteLine();
            System.Console.WriteLine( a );
            System.Console.Write( period );
            System.Console.Write( ' ' );
            System.Console.WriteLine( outcomeCode );
            System.Console.Write( minC );
            System.Console.Write( ' ' );
            System.Console.WriteLine( maxC );
            System.Console.Write( minX0 );
            System.Console.Write( ' ' );
            System.Console.WriteLine( maxX0 );
            System.Console.Write( minX );
            System.Console.Write( ' ' );
            System.Console.WriteLine( maxX );
            
            return outcomeCode;
         }
      }

      public static void Test103()
      {
         long minTimeSpan1 = long.MaxValue;
         for( int counter1 = 0 ; counter1 < 20 ; ++ counter1 )
         {
            minTimeSpan1 = System.Math.Min( minTimeSpan1, Test103_1() );
         }
         System.Console.WriteLine();
         double minTimeSpan1Milliseconds = (double) minTimeSpan1 * 1000.0 / (double) System.Diagnostics.Stopwatch.Frequency;
         System.Console.WriteLine( minTimeSpan1Milliseconds.ToString( @"F0" ) );
      }

      public static long Test103_1()
      {
         // Tests how many times each number and each bit is generated.

         const uint b1Length = 5U;
         const uint b2Length = 5U;
         const uint a1 = 27U;
         const uint a2 = 15U;

         //const uint b1Length = 5U;
         //const uint b2Length = 6U;
         //const uint a1 = 27U;
         //const uint a2 = 6U;

         //const uint b1Length = 5U;
         //const uint b2Length = 7U;
         //const uint a1 = 27U;
         //const uint a2 = 3U;

         //const uint a1 = 45U;
         //const uint a2 = 6U;
         //const uint bLength = 6U;

         //const uint b1Length = 6U;
         //const uint b2Length = 7U;
         //const uint a1 = 45U;
         //const uint a2 = 3U;

         //const uint a1 = 111U;
         //const uint a2 = 3U;
         //const uint bLength = 7U;

         //const uint a1 = 99U;
         //const uint a2 = 90U;
         //const uint bLength = 8U;

         //const uint a1 = 210U;
         //const uint a2 = 204U;
         //const uint bLength = 8U;

         //const uint a1 = 87U;
         //const uint a2 = 45U;
         //const uint bLength = 9U;

         const uint preferredBLength = b1Length;
         //const uint preferredBLength = b1Length - 1U;
         //const uint preferredBLength = b1Length + 1U;

         const uint b1 = 1U << (int) b1Length;
         const uint b2 = 1U << (int) b2Length;
         const uint preferredB = 1U << (int) preferredBLength;

         const uint x1BadSeed = ( a1 - 1U ) * b1 + ( b1 - 1U );
         System.Diagnostics.Debug.Assert( x1BadSeed <= ( preferredB * preferredB - 1U ) );
         System.Console.WriteLine( x1BadSeed - 1U );
         const uint x2BadSeed = ( a2 - 1U ) * b2 + ( b2 - 1U );
         System.Diagnostics.Debug.Assert( x2BadSeed <= ( preferredB * preferredB - 1U ) );
         System.Console.WriteLine( x2BadSeed - 1U );

         // Adjustment to center the generatable range.
         System.Diagnostics.Debug.Assert( ( preferredB * preferredB - x1BadSeed - 1U ) % 2U == 0U );
         const uint x1Adjustment =
            ( // How many big numbers are outside the generatable range.
              ( // Maximum possible number for this {preferredB}. When {preferredB == 0x10000U}, this equals 0xFFFFFFFFU.
                ( preferredB * preferredB - 1U ) -
         
                // Maximum generatable number.
                ( x1BadSeed - 1U )
              ) -
         
              // How many small numbers are outside the generatable range.
              // Only 0U is not generatable.
              1U
            ) /
         
            // As validated above, this divides without a remainder.
            2U;
         System.Diagnostics.Debug.Assert( ( preferredB * preferredB - x2BadSeed - 1U ) % 2U == 0U );
         const uint x2Adjustment =
            ( ( ( preferredB * preferredB - 1U ) -
                ( x2BadSeed - 1U )
              ) -
              1U
            ) /
            2U;

         // The multiply-with-carry formula can generate only a half of numbers from 1 inclusive to bad seed not inclusive.
         // Which half will be generated depends on the initial seed. Within the half the average is close to but doesn't equal the middle of the generatable range.
         // We will force the generation of the other half.
         // So we need 4 periods to combine every generated {x1} with every generated {x2}.
         // But some {x1} and {x2} combining formulas generate each number the same number of times even when both halfs of only {x1} or only {x2}
         // are generated.
         const bool shallGenerateX1BothNumberPaths = true;
         //const bool shallGenerateX1BothNumberPaths = false;
         //const bool shallGenerateX2BothNumberPaths = true;
         const bool shallGenerateX2BothNumberPaths = false;
         const uint numberCycles = 4U;
         //const uint numberCycles = 3U;
         //const uint numberCycles = 2U;
         //const uint numberCycles = 1U;

         uint x1Seed = (uint) System.Diagnostics.Stopwatch.GetTimestamp() % ( x1BadSeed - 1U ) + 1U;
         uint x2Seed = (uint) ( System.DateTime.UtcNow.Ticks / ( System.TimeSpan.TicksPerMillisecond * 16 ) ) % ( x2BadSeed - 1U ) + 1U;

         uint x1 = x1Seed;
         uint x2 = x2Seed;

         //uint bitwiseAnder1 = (uint) ( ( (int) System.Diagnostics.Stopwatch.GetTimestamp() & 1 ) * ( - 1 ) );
         uint bitwiseAnder1 = 0U;
         //uint bitwiseAnder1 = b - 1U;
         //uint bitwiseNotter2 = 0U;
         //uint bitwiseNotter3 = 0U;
         //uint bitwiseNotter4 = 0U;

// *** Begin Garbage.
//         uint period1 = 0U;
////#warning
//         //for( ; ; period1 = 0U )
//         {
//            for( ; ; )
//            {
//               ++ period1;
////#warning
//               // yg? When we do this only when {bitwiseNotter2 == 0U} the period doubles again.
//               // yg? When we apply some of these conditions the period increases further.
//               {
//                  //if( ( ( period1 - 1U ) & 1009U ) == 0U || ( period1 & 1009U ) == 0U )
//                  //if( ( ( period1 - 1U ) % ( 26879U + 1U ) ) == 0U || ( period1 % ( 26879U + 1U ) ) == 0U )
//                  //if( ( ( period1 - 1U ) & ( 26879U + 0U ) ) == 0U || ( period1 & ( 26879U + 0U ) ) == 0U )
//
//                  // yg? This condition increses the period another 1.5 times, which makes it an odd number.
////#warning
//                  //if( ( period1 % 2U ) == 0U )
//
//                  //if( ( period1 % 26879U ) == 0U )
//                  //if( ( period1 % 128U ) == 0U )
//                  //if( ( period1 % 256U ) == 0U )
//                  {
//#warning
////                     x1 = x1BadSeed - x1;
//                  }
//               }
//
////#warning
//               //x1 = ( ( a1 - 1U ) - x1 / b ) * b + x1 % b;
//
//               // This can result in {x1} becoming 0U or bad seed. But this will also get us off of bad seed.
//               // This is crap.
//               //x1 ^= bitwiseAnder1;
//
//               x1 = a1 * ( x1 % b ) + x1 / b;
//
////#warning
//               //bitwiseAnder1 ^= ( b - 1U );
//               //bitwiseNotter2 ^= bitwiseAnder1;
//               //bitwiseNotter3 ^= bitwiseNotter2;
//               //bitwiseNotter4 ^= bitwiseNotter3;
//
//               if( x1 != x1Seed )
//               {
//               }
//               else
//               {
////#warning
//                  //++ x1Seed;
//                  //x1Seed = x1Seed % ( x1BadSeed - 1U ) + 1U;
//                  //x1 = x1Seed;
//                  break;
//               }
//            }
//            System.Console.WriteLine( period1 );
//         }
// *** End Garbage.

// *** Begin Garbage.
//         uint period2 = 0U;
//         for( ; ; )
//         {
//            ++ period2;
//#warning
//            //if( bitwiseAnder1 != 0U )
//            //if( ( period2 % 2U ) == 0U )
//            {
//#warning
////               x2 = x2BadSeed - x2;
//            }
//            x2 = a2 * ( x2 % b ) + x2 / b;
//            if( x2 != x2Seed )
//            {
//            }
//            else
//            {
//               break;
//            }
//         }
//         System.Console.WriteLine( period2 );
//         System.Console.WriteLine( period1 * period2 );
// *** End Garbage.

         //uint x1PeriodCounter = 0U;
         //uint x2PeriodCounter = 0U;
         //ulong adjustedX1Sum = 0U;
         //ulong adjustedX2Sum = 0U;
         //ulong flippedAdjustedX1Sum = 0U;
         //ulong flippedAdjustedX2Sum = 0U;
         uint[] generatedNumbersCounter = new uint[ (int) ( preferredB * preferredB ) ];
         //bitwiseAnder1 = 0U;

         // We already warmed this up.
         long timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp();

         for( uint periodCounter = 0U ; periodCounter < numberCycles * ( x1BadSeed - 1U ) * ( x2BadSeed - 1U ) ; ++ periodCounter )
         //for( uint periodCounter = 0U ; periodCounter < numberCycles * ( x1BadSeed - 1U ) ; ++ periodCounter )
         //for( uint periodCounter = 0U ; periodCounter < numberCycles * ( x2BadSeed - 1U ) ; ++ periodCounter )
         {
            //bitwiseAnder1 = ( ~ bitwiseAnder1 );
            //bitwiseAnder1 ^= ( b - 1U );
            //for( ; ; )
            {
               if( shallGenerateX1BothNumberPaths )
               {
                  // This switches to the other generatable half.
                  // yg? Can this make the result less random?
                  x1 = x1BadSeed - x1;
               }
               else
               {
               }
               //x2 = x2BadSeed - x2;
               if( shallGenerateX2BothNumberPaths )
               {
                  // This switches to the other generatable half on every other loop.
                  //uint x21 = ( x2BadSeed - x2 ) & bitwiseAnder1;
                  bitwiseAnder1 = ( ~ bitwiseAnder1 );
                  //x21 |= x2 & bitwiseAnder1;
                  //x2 = x21;
                  if( bitwiseAnder1 != 0U )
                  {
                  }
                  else
                  {
                     x2 = x2BadSeed - x2;
                  }
               }
               else
               {
               }

               x1 = a1 * ( x1 % b1 ) + x1 / b1;
               x2 = a2 * ( x2 % b2 ) + x2 / b2;

               // The generated number.
               uint x = uint.MaxValue;

               {
                  #region Generation of {x}.
               
                  uint adjustedX1 = x1 + x1Adjustment;
                  uint adjustedX2 = x2 + x2Adjustment;
                  
                  // These formulas are probably essentially the same.
                  //uint twiceAdjustedX1 = adjustedX1 + x1Adjustment;
                  uint twiceAdjustedX1 = ( preferredB * preferredB - 1U ) - x1;
                  uint twiceAdjustedX2 = ( preferredB * preferredB - 1U ) - x2;

                  // Does it matter if we flip {x1} or {x2}? The one with a bigger or smaller multiplier?
                  // One possibly lame reasoning is that the one with a smaller multiplier has a narrower generatable range, so let's flip it.
                  // But tests show no real difference.
                  uint flippedX1 = ( x1 % preferredB ) * preferredB + x1 / preferredB;
                  uint flippedX2 = ( x2 % preferredB ) * preferredB + x2 / preferredB;
                  uint flippedAdjustedX1 = ( adjustedX1 % preferredB ) * preferredB + adjustedX1 / preferredB;
                  uint flippedAdjustedX2 = ( adjustedX2 % preferredB ) * preferredB + adjustedX2 / preferredB;
                  uint flippedTwiceAdjustedX1 = ( twiceAdjustedX1 % preferredB ) * preferredB + twiceAdjustedX1 / preferredB;
                  uint flippedTwiceAdjustedX2 = ( twiceAdjustedX2 % preferredB ) * preferredB + twiceAdjustedX2 / preferredB;

                  uint x1_2 = x1 - 1U;
                  //uint x1_2 = x1 + 1U;
                  uint x2_2 = x2 - 1U;
                  //uint x2_2 = x2 + 1U;

                  uint adjustedX1_2 = x1_2 + x1Adjustment;
                  uint adjustedX2_2 = x2_2 + x2Adjustment;
                  
                  uint twiceAdjustedX1_2 = ( preferredB * preferredB - 1U ) - x1_2;
                  uint twiceAdjustedX2_2 = ( preferredB * preferredB - 1U ) - x2_2;

                  uint flippedX1_2 = ( x1_2 % preferredB ) * preferredB + x1_2 / preferredB;
                  uint flippedX2_2 = ( x2_2 % preferredB ) * preferredB + x2_2 / preferredB;
                  uint flippedAdjustedX1_2 = ( adjustedX1_2 % preferredB ) * preferredB + adjustedX1_2 / preferredB;
                  uint flippedAdjustedX2_2 = ( adjustedX2_2 % preferredB ) * preferredB + adjustedX2_2 / preferredB;
                  uint flippedTwiceAdjustedX1_2 = ( twiceAdjustedX1_2 % preferredB ) * preferredB + twiceAdjustedX1_2 / preferredB;
                  uint flippedTwiceAdjustedX2_2 = ( twiceAdjustedX2_2 % preferredB ) * preferredB + twiceAdjustedX2_2 / preferredB;

                  {
                     // This is the formula George Marsaglia recommended in one of his posts.
                     // The carries are not factored.
                     // Its quality is lower comparing to the others.
                     //x = ( x1 % b ) * b + x2 % b;
                  }

                  {
                     // A "medium" quality {minBLength * 2U}-bit number.
                     // This works when only a half of {x1} or {x2} number path is generated.
                     //x = adjustedX1 ^ flippedAdjustedX2;
                     //x = adjustedX2 ^ flippedAdjustedX1;

                     // This is a bit better than the above but requires to generate both {x1} and {x2} number paths. It's probably not worth the overhead.
                     //x = x1 ^ flippedTwiceAdjustedX2;
                     //x = x2 ^ flippedTwiceAdjustedX1;
                     //x = flippedX1 ^ twiceAdjustedX2;
                     //x = flippedX2 ^ twiceAdjustedX1;

                     // This works but it's worse.
                     //x = adjustedX1 ^ flippedAdjustedX2_2;
                     //x = adjustedX1_2 ^ flippedAdjustedX2;
                     //x = x1 ^ flippedTwiceAdjustedX2_2;

                     // This is bad.
                     //x = x1 ^ x2;
                     //x = adjustedX1 ^ adjustedX2;
                     //x = x2 ^ twiceAdjustedX1;
                     //x = ( adjustedX1 + 1U ) ^ ( flippedAdjustedX2 - 1U );
                     //x = ( adjustedX1 + 1U ) ^ ( flippedAdjustedX2 - 0U );
                     //x = ( adjustedX1 + 1U ) ^ ( adjustedX2 - 1U );
                     //x = ( adjustedX1 + 1U ) ^ ( adjustedX2 - 0U );
                     //x = ( x1 - 0U ) ^ ( ( preferredB * preferredB - 1U ) - ( x2 - 0U ) );
                     //x = ( flippedAdjustedX1 - adjustedX2 ) % ( b * b );
                     //x = x1_2 ^ flippedTwiceAdjustedX2;
                  }

                  {
                     // A "high" quality {bLength}-bit number.
                     // This works when only a half of {x1} or {x2} number path is generated.
                     //x = ( x1 ^ x2 ) % preferredB;

                     // This is probably essentially the same.
                     //x = ( x1 ^ ( ~ x2 ) ) % b;
                     //x = ( twiceAdjustedX1 ^ x2 ) % b;

                     // This is a bit better than the above but requires to generate both {x1} and {x2} number paths. It's probably not worth the overhead.
                     //x = ( ( x1 - 1U ) ^ ( x2 - 0U ) ) % preferredB;

                     // This is bad.
                     //x = ( x1 + x2 ) % b;
                     //x = ( x1 - x2 ) % b;
                     //x = ( ( x1 - 1U ) ^ ( x2 + 1U ) ) % preferredB;
                  }

                  {
                     // A "low" quality {bLength}-bit number.
                     // But the period is much shorter.
                     // A bigger multiplier improves quality.
                     //x = x1 % minB;
                     //x = x2 % minB;
                     //x = x2 % b2;
                  
                     // This is bad.
                     //x = ( x1 - 1U ) % b;
                  }

                  {
                     // An apparently pretty good quality 1-bit number.
                     // Any bit with 0-based index from 0U to {bLength - 1U} is pretty good quality.
                     // But the period is much shorter.
                     //x = x1 % 2U;
                     //x = x1 & ( 1U << 2/*U*/ );
                     //x = x1 & ( 1U << (int) ( bLength - 1U ) );
               
                     // A combination of bits has a lower quality.
                     //x = x1 & 6U;
                     //x = x1 & ( ( 1U << (int) ( bLength - 1U ) ) | 1U );

                     // Further bits have poor quality.
                     //x = x1 & ( 1U << (int) ( b1Length - 0U ) );
                     //x = x1 & ( 1U << (int) ( b1Length * 2U - 1U ) );
                     //x = x1 & ( 1U << (int) ( b1Length * 2U - 2U ) );
                  }

                  {
                     // Some other bad options.
                     //x = x1;
                     //x = x2;
                     //x = x1 - 1U;
                     //x = adjustedX1;
                     //x = flippedAdjustedX1;
                     //x = ( x1 * x2 ) % preferredB;
                     //x = ( x1 % b1 ) * ( x2 % b2 );
                     //x = ( x1 % ( b1 / 2U ) ) * ( x2 % ( b2 / 2U ) );
                  }

                  {
                     // An attempt to factor the carries into a {bLength}-bit number.
                     // This is bad.
                     //x ^= x / b;
                     //x ^= ( ( b - 1U ) - x / b );
                     //x %= b;

                     // This selects some bits.
                     //x &= 6U;

                     // This calculates a remainder.
                     //x %= 131U;
                     //x %= 101U;
                  }
               
                  #endregion
               }

               //if( periodCounter % 8U == 0U )
               //{
               //   System.Console.WriteLine();
               //}
               //System.Console.Write( x );
               ++ generatedNumbersCounter[ (int) x ];

               //bitwiseAnder1 = ( ~ bitwiseAnder1 );
               //bitwiseAnder1 ^= ( b * b - 1U );
               //bitwiseAnder1 ^= ( b * b - 1U ) - ( b - 1U );
               //bitwiseAnder1 ^= ( b - 1U );
               //bitwiseNotter2 ^= bitwiseAnder1;
         
               //if( x1 != x1Seed )
               //{
               //}
               //else
               //{
               //   ++ x1PeriodCounter;
               //   //bitwiseAnder1 ^= ( b - 1U );
               //}
               //if( x2 != x2Seed )
               //{
               //}
               //else
               //{
               //   ++ x2PeriodCounter;
               //}
               //if( x1 != x1Seed || x2 != x2Seed )
               ////if( x1 != x1Seed || ( x2 ^ bitwiseAnder1 ) != x2Seed )
               //{
               //}
               //else
               //{
               //   break;
               //}
            }
         }

         timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp() - timeSpan1;
         System.Media.SystemSounds.Beep.Play();

         System.Diagnostics.Debug.Assert( x1 == x1Seed && x2 == x2Seed );

         //System.Console.WriteLine();
         //System.Console.WriteLine( x1PeriodCounter );
         //System.Console.WriteLine( x2PeriodCounter );
         //
         //// This probably has no meaning.
         //System.Console.WriteLine( x1PeriodCounter * x2PeriodCounter );

         bool generatedNumbersCounterContainsZeros = false;
         uint generatedNumbersCounterMinItem = uint.MaxValue;
         uint generatedNumbersCounterMaxItem = 0U;
         uint period = 0U;
         ulong xSum = 0U;
         int[] generatedNumberBitsCounter = new int[ (int) ( preferredBLength * 2U ) ];
         for( int counter1 = generatedNumbersCounter.Length ; ( -- counter1 ) >= 0 ; )
         {
            if( generatedNumbersCounter[ counter1 ] > 0U )
            {
               generatedNumbersCounterMinItem = System.Math.Min( generatedNumbersCounterMinItem, generatedNumbersCounter[ counter1 ] );
               generatedNumbersCounterMaxItem = System.Math.Max( generatedNumbersCounterMaxItem, generatedNumbersCounter[ counter1 ] );
               period += generatedNumbersCounter[ counter1 ];
               xSum += (ulong) (uint) counter1 * (ulong) generatedNumbersCounter[ counter1 ];
            }
            else
            {
               generatedNumbersCounterContainsZeros = true;
            }
            for( int counter2 = generatedNumberBitsCounter.Length ; ( -- counter2 ) >= 0 ; )
            {
               generatedNumberBitsCounter[ counter2 ] += ( (int) ( ( ( counter1 >> counter2 ) % 2U ) * 2U ) - 1 ) * (int) generatedNumbersCounter[ counter1 ];
            }
         }
         System.Diagnostics.Debug.Assert( period == numberCycles * ( x1BadSeed - 1U ) * ( x2BadSeed - 1U ) );
         
         System.Console.WriteLine();
         System.Console.WriteLine( ( (double) period / (double) numberCycles ).ToString( @"g10" ) );
         System.Console.WriteLine( period );

         //// How many times each individual period repeated.
         //System.Diagnostics.Debug.Assert( (float) ( (double) period / (double) period1 ) == (float) x1PeriodCounter );
         //System.Console.WriteLine( (double) period / (double) period1 );
         //System.Diagnostics.Debug.Assert( (float) ( (double) period / (double) period2 ) == (float) x2PeriodCounter );
         //System.Console.WriteLine( (double) period / (double) period2 );
         
         //// Individual periods.
         //System.Diagnostics.Debug.Assert( (float) ( (double) period / (double) x1PeriodCounter ) == (float) period1 );
         //System.Console.WriteLine( (double) period / (double) x1PeriodCounter );
         //System.Diagnostics.Debug.Assert( (float) ( (double) period / (double) x2PeriodCounter ) == (float) period2 );
         //System.Console.WriteLine( (double) period / (double) x2PeriodCounter );
         
         System.Console.WriteLine();
         double xAverage = (double) xSum / (double) period;
         //xAverageError -= (double) ( b * b - 1U ) * 0.5;
         //xAverageError -= (double) ( b - 1U ) * 0.5;
         //double xAverageError = (double) xSum / (double) period - (double) ( b / 2U * b - 1U ) * 0.5;
         //double xAverageError = (double) xSum / (double) period - (double) ( b * 4U - 1U ) * 0.5;
         System.Console.WriteLine( ( xAverage - (double) ( preferredB * preferredB - 1U ) * 0.5 ).ToString( @"g10" ) );
         System.Console.WriteLine( ( xAverage - (double) ( preferredB - 1U ) * 0.5 ).ToString( @"g10" ) );
         //double adjustedX1AverageError = (double) adjustedX1Sum / (double) period - (double) ( b * b - 1U ) * 0.5;
         //System.Console.WriteLine( adjustedX1AverageError.ToString( @"g10" ) );
         //double adjustedX2AverageError = (double) adjustedX2Sum / (double) period - (double) ( b * b - 1U ) * 0.5;
         //System.Console.WriteLine( adjustedX2AverageError.ToString( @"g10" ) );
         //double flippedAdjustedX1AverageError = (double) flippedAdjustedX1Sum / (double) period - (double) ( b * b - 1U ) * 0.5;
         //System.Console.WriteLine( flippedAdjustedX1AverageError.ToString( @"g10" ) );
         //double flippedAdjustedX2AverageError = (double) flippedAdjustedX2Sum / (double) period - (double) ( b * b - 1U ) * 0.5;
         //System.Console.WriteLine( flippedAdjustedX2AverageError.ToString( @"g10" ) );
         
         System.Console.WriteLine();
         for( int counter1 = 0 ; counter1 < generatedNumberBitsCounter.Length ; ++ counter1 )
         {
            if( counter1 <= 0 || generatedNumberBitsCounter[ counter1 ] != generatedNumberBitsCounter[ counter1 - 1 ] )
            {
               System.Console.Write( counter1 );
               System.Console.Write( ' ' );
               System.Console.WriteLine( ( (double) generatedNumberBitsCounter[ counter1 ] / (double) numberCycles ).ToString( @"g10" ) );
            }
            else
            {
               if( counter1 < generatedNumberBitsCounter.Length - 1 )
               {
               }
               else
               {
                  System.Console.Write( counter1 );
                  System.Console.WriteLine( @" ---" );
               }
            }
         }

         System.Console.WriteLine();
         System.Console.WriteLine( generatedNumbersCounterContainsZeros );
         System.Console.WriteLine( ( (double) generatedNumbersCounterMinItem / (double) numberCycles ).ToString( @"g10" ) );
         System.Console.WriteLine( ( (double) generatedNumbersCounterMaxItem / (double) numberCycles ).ToString( @"g10" ) );
         System.Console.WriteLine( ( (double) generatedNumbersCounterMaxItem / (double) generatedNumbersCounterMinItem ).ToString( @"g10" ) );

         System.Console.WriteLine();
         for( int counter1 = 0 ; counter1 < generatedNumbersCounter.Length ; ++ counter1 )
         {
            if( counter1 <= 0 || generatedNumbersCounter[ counter1 ] != generatedNumbersCounter[ counter1 - 1 ] )
            {
               System.Console.Write( counter1 );
               System.Console.Write( ' ' );
               System.Console.WriteLine( ( (double) generatedNumbersCounter[ counter1 ] / (double) numberCycles ).ToString( @"g10" ) );
            }
            else
            {
               if( counter1 < generatedNumbersCounter.Length - 1 )
               {
               }
               else
               {
                  System.Console.Write( counter1 );
                  System.Console.WriteLine( @" ---" );
               }
            }
         }

         return timeSpan1;
      }

      public static void Test104()
      {
         // *** This is old and is no longer maintained.

         // This test finds the best adjustment for any given {factor1}.
         // This is not totally precise science as the {double1} error is noisy and depends on the initial seed. The number generator
         // can take different paths in the number space, which affects the average.
         // yg? The complimentary algorithm might be less noisy but, as mentioned in another comment, I was unable to get it working.

         //const uint factor1 = 18000U; // period=589,823,999
         //const uint factor1 = 31083U; // period=1,018,527,743
         //const uint factor1 = 36969U; // period=1,211,400,191
         //const uint factor1 = 64455U;
         //const uint factor1 = 65184U; // period=2,135,949,311
         //const uint factor1 = 65514U; // This doesn't produce a safe prime. period=2,146,762,751

         // Complimentary.
         //const uint factor1 = 12108U;
         const uint factor1 = 65403U;

         // A 0U seed and this bad seed result in the period being 1.
         // A bigger seed will work but it will not be generated again.
         // Some bigger seeds can also result in the period being 1, but only when {factor1} is small enough.
         // The maximum number that can be generated repeatedly after a period is less than this value by 1.
         // Whether the maximum number will actually be generated depends on what path in the number space the number generator takes.
         // Minimum generatable number is 1 but it also is not guaranteed to be generated.
         const uint valueWBadSeed = ( ( factor1 - 1U ) << 16/*U*/ ) | 0xFFFFU;

         // We use this formula below. It equals the bad seed.
         System.Diagnostics.Debug.Assert( valueWBadSeed == ( ( factor1 * 65535U ) + ( ( factor1 * 65535U ) >> 16/*U*/ ) ) );

         int adjustment;

         adjustment = (int) ( // Adjustment to center the generatable range.
                                  // Note that some numbers within the generatable range will not actually be generated,
                                  // so the average will often be not exactly in the middle of the range.
                                  ( ( // How many big numbers are outside the generatable range.
                                       ( uint.MaxValue -

                                         // Maximum possible generatable number.
                                         // Whether it will actually be generated depends on what path the number generator takes.
                                         ( // This equals {valueWBadSeed}, as validated above.
                                           ( ( factor1 * 65535U ) + ( ( factor1 * 65535U ) >> 16/*U*/ ) ) -

                                           1U
                                         )
                                       ) -

                                       // How many small numbers are outside the generatable range.
                                       // Only 0U is not generatable.
                                       // Whether 1 will actually be generated depends on what path the number generator takes.
                                       1U +

                                       // I feel it might be more correct to not add 1 before dividing by 2.
                                       // I don't want to overshoot the center.
                                       // Although if we are to merge both Z and W values we might want to overshoot the center on one of them.
                                       // Problem is that this won't eliminate the bias as we would x-or the highest order W bit with another Z bit.
                                       // Luckuly, commented out test code a few lines below shows that this divides without a remainder.
                                       // And even if a {factor1} that fails this test existed we would simply not use it.
                                       0U
                                    ) /
                                    2U
                                  ) +

                                  // We probably don't need to add or subtract 1.
                                  0U
                                 );

         // As mentioned in a comment a few lines above, this divides without a remainder.
      //public static void Test000()
      //{
      //   //const uint factor1Z = 65184U;
      //   //const uint factor1Z = 64860U;
      //   //const uint factor1Z = 64545U;
      //   //const uint factor1Z = 64455U;
      //   //const uint factor1Z = 36969U;
      //   //const uint factor1Z = 31083U;
      //   //const uint factor1Z = 18000U;
      //   const uint factor1Z = 123U;
      //   //const uint factor1Z = 124U;
      //   const uint valueZBadSeed = ( ( factor1Z - 1U ) << 16/*U*/ ) | 0xFFFFU;
      //   const double factor2Z = (double) ( ( uint.MaxValue - ( valueZBadSeed - 1U ) ) - 1U ) / 2.0;
      //}

         // We used to use this formula but it's totally incorrect.
         //adjustment = (int) ( ( ( uint.MaxValue - ( ( factor1 * ( uint.MaxValue & 65535U ) ) + ( uint.MaxValue >> 16/*U*/ ) ) + 1U ) / 2U ) + 0U );

         //adjustment = (int) ( ( uint.MaxValue - ( ( ( factor1 - 1U ) << 16/*U*/ ) + ( factor1 - 1U ) ) ) / 2U );
         //adjustment = 0;
         //adjustment = 1557659648;
         //adjustment += 100000000;
         //adjustment += 1;
         //adjustment -= 1;

         int adjustmentStep = 1 << 8/*U*/;
         //int adjustmentStep = 1;

         uint valueWSeed;

         //valueWSeed = (uint) System.Diagnostics.Stopwatch.GetTimestamp() + ( (uint) System.DateTime.UtcNow.Ticks << 16/*U*/ );

         for( ; ; )
         {
            valueWSeed = (uint) System.Diagnostics.Stopwatch.GetTimestamp() + ( (uint) System.DateTime.UtcNow.Ticks << 16/*U*/ );
            //valueWSeed = 1221111U;

            uint minValueW = uint.MaxValue;
            uint maxValueW = 0U;
            ulong valueW16Sum = 0U;
            ulong adjustedValueWSum = 0U;
            //int[] adjustedValueWBitsCounter = new int[ 32 ];
            uint valueW = valueWSeed;

            // yg? This initial value requires tha the 1st generated number will be generated again.
            // yg? If it doesn't happen {actualPeriod} will be different from {counter1}.
            // yg? But I can't test all possible seeds.
            //uint period = unchecked( (uint) ( - 1 ) );

            uint period = unchecked( (uint) ( - 100 ) );
            //uint period = unchecked( (uint) ( - 2000 ) );
            //uint period = unchecked( (uint) ( - 589000000 ) );

            // yg? If this is seen to be different from {period} the later would need to be initialized with a bigger negative value.
            long actualPeriod = (int) period;

            for( ; ; )
            {
               if( period > 0U )
               {
               }
               else
               {
                  valueWSeed = valueW;
                  minValueW = uint.MaxValue;
                  maxValueW = 0U;
                  valueW16Sum = 0U;
                  adjustedValueWSum = 0U;
                  //adjustedValueWBitsCounter = new int[ 32 ];
                  ////adjustedValueWBitsCounter.Initialize();
               }
               ++ actualPeriod;
               ++ period;
               //valueW -= (uint) adjustment;

               // yg? This doubles the period (possibly by accident) but the numbers it generates are not right. It doesn't generate numbers close to 1.
               // yg? The minimum is some thousands, depending on {factor1}.
               //valueW = ( ~ valueW );

               // yg? This doubles the period and now generates all numbers from 1 to {valueWBadSeed - 1}.
               // yg? This probably forces the logic to jump from one number path to another.
               // yg? This might be the actual complimentary algorithm.
               // yg? Can we bitwise-not the result every other time?
               //valueW = ( valueWBadSeed /*- 1U*/ ) - valueW;

               // Complimentary.
               valueW ^= 0xFFFFU;

               valueW = factor1 * ( valueW & 65535U ) + ( valueW >> 16/*U*/ );

               //valueW = ( ~ valueW );

               minValueW = System.Math.Min( minValueW, valueW );
               maxValueW = System.Math.Max( maxValueW, valueW );
               valueW16Sum += ( valueW & 65535U );
               //valueW += (uint) adjustment;
               uint adjustedValueW = valueW + (uint) adjustment;
               adjustedValueWSum += adjustedValueW;
               //for( int bitIndex = 0 ; bitIndex < 32 ; ++ bitIndex )
               //{
               //   if( ( adjustedValueW & ( 1U << bitIndex ) ) != 0U )
               //   {
               //      ++ adjustedValueWBitsCounter[ bitIndex ];
               //   }
               //}
               if( valueW != valueWSeed )
               {
               }
               else
               {
                  break;
               }
               //if( period == 100000000U )
               //{
               //   break;
               //}
            }

            System.Diagnostics.Debug.Assert( minValueW > 0U );
            System.Diagnostics.Debug.Assert( maxValueW < valueWBadSeed );

            System.Console.Write( period );
            System.Console.Write( ' ' );
            System.Console.Write( actualPeriod );
            System.Console.Write( ' ' );
            System.Console.Write( minValueW );
            System.Console.Write( ' ' );
            System.Console.Write( maxValueW );
            double double2 = (double) valueW16Sum / (double) period - (double) ushort.MaxValue * 0.5;
            System.Console.Write( ' ' );
            System.Console.Write( double2.ToString( @"F3" ) );
            System.Console.Write( ' ' );
            System.Console.Write( adjustment );
            //double double1 = (double) adjustedValueWSum / (double) ( (ulong) uint.MaxValue * (ulong) period ) - 0.5;
            double double1 = (double) adjustedValueWSum / (double) period - (double) uint.MaxValue * 0.5;
            System.Console.Write( ' ' );
            System.Console.Write( double1.ToString( @"F3" ) );
            //double1 = (double) adjustedValueWSum / (double) ( period + 1U ) - (double) uint.MaxValue * 0.5;
            //System.Console.Write( ' ' );
            //System.Console.Write( double1.ToString( @"F3" ) );
            //double1 = (double) adjustedValueWSum / (double) ( period - 1U ) - (double) uint.MaxValue * 0.5;
            //System.Console.Write( ' ' );
            //System.Console.Write( double1.ToString( @"F3" ) );
            
            if( double1 > 0.0 )
            {
               if( adjustmentStep < 0 )
               {
                  adjustmentStep *= 2;
               }
               else
               {
                  adjustmentStep = ( - adjustmentStep );
                  adjustmentStep = System.Math.Min( adjustmentStep / 3, ( - 1 ) );
               }
               adjustment += adjustmentStep;
            }
            else
            {
               if( double1 < 0.0 )
               {
                  if( adjustmentStep > 0 )
                  {
                     adjustmentStep *= 2;
                  }
                  else
                  {
                     adjustmentStep = ( - adjustmentStep );
                     adjustmentStep = System.Math.Max( adjustmentStep / 3, 1 );
                  }
                  adjustment += adjustmentStep;
               }
               else
               {
                  if( adjustmentStep / 3 != 0 )
                  {
                     adjustmentStep /= 3;
                  }
               }
            }
            
            System.Console.Write( ' ' );
            System.Console.WriteLine( adjustmentStep );
         }
      }

      public static void Test105()
      {
         // *** This is old and is no longer maintained. Although it's relatively clean and garbage free.

         // Finds bad seeds.

         const uint factor1 = 65184U;
         //const uint factor1 = 64860U;
         //const uint factor1 = 36969U;
         //const uint factor1 = 18000U;

         const uint valueWBadSeed = ( ( factor1 - 1U ) << 16/*U*/ ) | 0xFFFFU;

         for( uint valueWSeed = 0U ; ; )
         {
            uint valueW = valueWSeed;
            uint prevValueW = 0U;
            bool firstAndSecondGeneratedValuesAreEqual = false;
            for( int counter1 = 0 ; counter1 < 100 ; ++ counter1 )
            {
               valueW = factor1 * ( valueW & 65535U ) + ( valueW >> 16/*U*/ );
               if( counter1 <= 0 )
               {
                  System.Diagnostics.Debug.Assert( counter1 == 0 );
               }
               else
               {
                  if( ( ( valueW ^ prevValueW ) & 0xF0000000U ) == 0U ||
                      ( ( valueW ^ prevValueW ) & 0x0F000000U ) == 0U ||
                      ( ( valueW ^ prevValueW ) & 0x00F00000U ) == 0U ||
                 ( ( valueW ^ prevValueW ) & 0x000F0000U ) == 0U ||
                      ( ( valueW ^ prevValueW ) & 0x0000F000U ) == 0U ||
                      ( ( valueW ^ prevValueW ) & 0x00000F00U ) == 0U ||
                      ( ( valueW ^ prevValueW ) & 0x000000F0U ) == 0U ||
                      ( ( valueW ^ prevValueW ) & 0x0000000FU ) == 0U ||
                      ( ( valueW ^ valueWSeed ) & 0xF0000000U ) == 0U ||
                      ( ( valueW ^ valueWSeed ) & 0x0F000000U ) == 0U ||
                      ( ( valueW ^ valueWSeed ) & 0x00F00000U ) == 0U ||
                      ( ( valueW ^ valueWSeed ) & 0x000F0000U ) == 0U ||
                      ( ( valueW ^ valueWSeed ) & 0x0000F000U ) == 0U ||
                      ( ( valueW ^ valueWSeed ) & 0x00000F00U ) == 0U ||
                      ( ( valueW ^ valueWSeed ) & 0x000000F0U ) == 0U ||
                      ( ( valueW ^ valueWSeed ) & 0x0000000FU ) == 0U
                    )
                  {
                  }
                  else
                  {
                     goto label1;
                  }
                  if( counter1 <= 1 )
                  {
                     System.Diagnostics.Debug.Assert( counter1 == 1 );

                     // It would be a problem if these were unequal but would eventually prove to be partially equal.
                     // So I want this condition to be {true}.
                     firstAndSecondGeneratedValuesAreEqual = ( valueW == prevValueW );
                  }
                  else
                  {
                  }
               }
               prevValueW = valueW;
            }

            {
               System.Console.WriteLine();
               System.Console.WriteLine( valueWSeed );
               System.Console.WriteLine( @"0x" + valueWSeed.ToString( @"X" ) );
               System.Console.WriteLine( valueWBadSeed );
               System.Console.WriteLine( @"0x" + valueWBadSeed.ToString( @"X" ) );
               System.Console.WriteLine( firstAndSecondGeneratedValuesAreEqual );
               System.Console.WriteLine( @"0x" + prevValueW.ToString( @"X" ) );
               System.Console.WriteLine( @"0x" + valueW.ToString( @"X" ) );
            }

         label1:
            if( ++ valueWSeed != 0U )
            {
            }
            else
            {
               break;
            }
         }
      }

      public static void Test106()
      {
         // *** This is old and is no longer maintained.

         // This tests the average of the generated random numbers.
         // We want both {valueZ}, {valueW}, and {randomNumber3} to have the correct average.
         // yg? It would be nice to also test the corellation. The next generated number must have
         // yg? the correct probability to be above or below current one. Maybe do this test for individual bytes within the 32-bit integer.

         const uint factorZ1 = 36969U;
         //unsigned int const factorW1( 18000U );
         const uint factorW1 = 65184U;

         const uint factorZ2 =
            ( ( ( uint.MaxValue -
                   ( ( factorZ1 *
                        ( uint.MaxValue &
                          ushort.MaxValue
                        )
                      ) +
                      ( uint.MaxValue >>
                        (int)
                        ( (uint) ( sizeof( ushort ) ) *
                          8U
                        )
                      )
                   ) +
                   1U
                 ) /
                 2U
              ) +
              0U
            );
         const uint factorW2 =
            ( ( ( uint.MaxValue -
                   ( ( factorW1 *
                        ( uint.MaxValue &
                          ushort.MaxValue
                        )
                      ) +
                      ( uint.MaxValue >>
                        (int)
                        ( (uint) ( sizeof( ushort ) ) *
                          8U
                        )
                      )
                   ) +
                   1U
                 ) /
                 2U
              ) +
              0U
            );

         for( ; ; )
         {
            uint valueZ = (uint) System.Diagnostics.Stopwatch.GetTimestamp();
            uint valueW = (uint) System.DateTime.UtcNow.Ticks;

            //const int numberLoops = 2000000000;
            const int numberLoops = 200000000;
            ulong randomNumber3Sum = 0U;
            for( int counter1 = 0 ; counter1 < numberLoops ; ++ counter1 )
            {
               valueZ = factorZ1 * ( valueZ & ushort.MaxValue ) + ( valueZ >> 16/*U*/ ) + factorZ2;
               valueW = factorW1 * ( valueW & ushort.MaxValue ) + ( valueW >> 16/*U*/ ) + factorW2;

               uint randomNumber3 = ( ( valueZ << 16/*U*/ ) | ( valueZ >> 16/*U*/ ) ) ^ valueW;
               //uint randomNumber3 = ( ( valueW << 16/*U*/ ) | ( valueW >> 16/*U*/ ) ) ^ valueZ;
               //uint randomNumber3 = valueZ;
               //uint randomNumber3 = valueW;

               randomNumber3Sum += randomNumber3;
            }
            double double1 = (double) randomNumber3Sum / (double) ( (ulong) uint.MaxValue * (ulong)(uint) numberLoops ) - 0.5;
            System.Console.WriteLine( double1.ToString( @"F9" ) );
         }
      }

      public static void Test107()
      {
         // *** This is old and is no longer maintained.

         // This test verifies that any number from 0U to 0xFFFFFFFFU is generated at least once.
         // But I can't test all combinations of seed values.

         const uint factorZ1 = 36969U;
         //unsigned int const factorW1( 18000U );
         const uint factorW1 = 65184U;

         const uint factorZ2 =
            ( ( ( uint.MaxValue -
                   ( ( factorZ1 *
                        ( uint.MaxValue &
                          ushort.MaxValue
                        )
                      ) +
                      ( uint.MaxValue >>
                        (int)
                        ( (uint) ( sizeof( ushort ) ) *
                          8U
                        )
                      )
                   ) +
                   1U
                 ) /
                 2U
              ) +
              0U
            );
         const uint factorW2 =
            ( ( ( uint.MaxValue -
                   ( ( factorW1 *
                        ( uint.MaxValue &
                          ushort.MaxValue
                        )
                      ) +
                      ( uint.MaxValue >>
                        (int)
                        ( (uint) ( sizeof( ushort ) ) *
                          8U
                        )
                      )
                   ) +
                   1U
                 ) /
                 2U
              ) +
              0U
            );

         uint valueZ = (uint) System.Diagnostics.Stopwatch.GetTimestamp();
         uint valueW = (uint) System.DateTime.UtcNow.Ticks;
         //uint valueZ = 0U;
         //uint valueW = 0U;

         // This is probably crap.
         //uint valueZ = unchecked ( (uint) ( - factorZ2 ) );
         //uint valueW = unchecked ( (uint) ( - factorW2 ) );

         double randomNumber3Sum = 0.0;
         uint unseenRandomNumber3 = 0U;
         //System.Collections.Generic.HashSet< uint > unseenRandomNumber3s = new System.Collections.Generic.HashSet< uint >();
         //unseenRandomNumber3s.Add( 0U );
         //System.Collections.Generic.SortedList< uint, byte > unseenRandomNumber3s = new System.Collections.Generic.SortedList< uint, byte >( 1024 * 1024 * 32 );
         System.Collections.Generic.Dictionary< uint, byte > unseenRandomNumber3s = new System.Collections.Generic.Dictionary< uint, byte >( 1024 * 1024 * 64 );
         //System.Collections.Generic.SortedDictionary< uint, byte > unseenRandomNumber3s = new System.Collections.Generic.SortedDictionary< uint, byte >();
         unseenRandomNumber3s.Add( 0U, (byte) 0U );
         int counter2 = 0;
         for( long counter1 = 1 ; ; ++ counter1 )
         {
            if( unseenRandomNumber3 < uint.MaxValue )
            {
               //if( unseenRandomNumber3s.Count < 1024 * 1024 * 32 )
               if( unseenRandomNumber3s.Count < 1024 * 1024 * 64 )
               {
                  ++ unseenRandomNumber3;
                  //unseenRandomNumber3s.Add( unseenRandomNumber3 );
                  unseenRandomNumber3s.Add( unseenRandomNumber3, (byte) 0U );
               }
               else
               {
               }
            }
            else
            {
               if( unseenRandomNumber3s.Count > 0 )
               {
               }
               else
               {
                  break;
               }
            }

            valueZ = factorZ1 * ( valueZ & ushort.MaxValue ) + ( valueZ >> 16/*U*/ ) + factorZ2;
            valueW = factorW1 * ( valueW & ushort.MaxValue ) + ( valueW >> 16/*U*/ ) + factorW2;

            uint randomNumber3 = ( ( valueZ << 16/*U*/ ) | ( valueZ >> 16/*U*/ ) ) ^ valueW;
            //uint randomNumber3 = ( ( valueW << 16/*U*/ ) | ( valueW >> 16/*U*/ ) ) ^ valueZ;
            //uint randomNumber3 = valueZ;
            //uint randomNumber3 = valueW;

            randomNumber3Sum += ( (double) randomNumber3 - (double) ( uint.MaxValue - 0U ) * 0.5 );

            if( unseenRandomNumber3s.Remove( randomNumber3 ) )
            {
               ++ counter2;
            }

            if( counter1 % 1000000 == 0 )
            {
               System.Console.Write( counter1 );
               System.Console.Write( ' ' );

               // This should always be about the same provided random numbers are uniformly distributed.
               System.Console.Write( counter2 );

               counter2 = 0;
               System.Console.Write( ' ' );
               System.Console.Write( unseenRandomNumber3 );
               System.Console.Write( ' ' );
               System.Console.Write( unseenRandomNumber3s.Count );
               System.Console.Write( ' ' );
               System.Console.WriteLine( randomNumber3Sum / (double) counter1 );
            }
         }
      }

      public static void LinearCongruentialGeneratorPrototype()
      {
         long timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp();

         //ulong seed64 = ( ~ 0U );
         //ulong seed64 = 0U;
         //ulong seed64 = 1U;
         ulong seed64 = ( ( (ulong) timeSpan1 << 32 ) | ( (ulong) timeSpan1 >> 32 ) ) ^ (ulong) System.DateTime.UtcNow.Ticks;

         uint x32 = (uint) seed64;
         uint x322;
         //ulong x64 = seed64;
         //ulong x642;

         ulong x32Sum = 0U;

         long period = 0;

         timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp();

         do
         {
            // Any number of lower order bits are not very random.
            // This should be labelled "low quality 64 bits".
            // This will be more random after xoring higher and lower 32 bits.
            // That should be labelled "medium quality 32 bits".
            //x64 = x64 * 6364136223846793005UL + 1442695040888963407UL;
            //x64 = x64 * 2862933555777941757UL + 3037000493UL;

            // This is more random but 2 lower order bits are just as unrandom.
            //x642 = x64 * 2862933555777941757UL + 3037000493UL;

            // This is even more random.
            // This should be labelled "medium quality 64 bits".
            // This will be more random after xoring higher and lower 32 bits.
            // That should be labelled "high quality 32 bits".
            // Instead of this, we can use the multiply-with-cappy algorithm to generate a 32-bit number but to make it unbiased
            // we will need to give it only numbers that are between the bad seeds.
            //x642 = ( ( x64 << 32 ) | ( x64 >> 32 ) ) * 2862933555777941757UL + 3037000493UL;

            //System.Console.WriteLine( x642 & 3U );
            
            // This is a way to distort {x64} periodically.
            //x64 -= ( x64 << 2 ) + 1UL;

            // The same for 32 bits.
            x32 = x32 * 1664525U + 1013904223U;
            x322 = ( ( x32 << 16 ) | ( x32 >> 16 ) ) * 2891336453U + 1640531513U;
            //x32 = x322;

            //x32Sum += x32;
            x32Sum += x322;



            // This can be used to spin a hash-sum and then bitwise-xor it with the next number.
            //x32 += ( x32 << 2 ) + 1013904223U;

            // The same but with subtraction.
            // Subtraction appears to produce the same period and the randomness is probably better,
            // at least the randomness of the 1st generated number when the seed is a small positive number.
            // This is probably the best formula to spin a 32-bit hash-sum.
            //x32 -= ( x32 << 2 ) + 1013904223U;

            // This works too.
            //x32 += ( x32 << 2 ) - 1013904223U;

            // This is probably the best formula to spin a 64-bit hash-sum.
            // yg? I can't test the period of this but the period of the lower order N bits is as expected, which is {pow(2,N)}.
            //x64 -= ( x64 << 2 ) + 1442695040888963407UL;



            // Some parameters copied from Wikipedia and other places.
            //x32 = x32 * 1664525U + 1013904223U;
            //x32 = x32 * 22695477U + 1U;
            //x32 = x32 * 1103515245U + 12345U;
            //x32 = x32 * 134775813U + 1U;
            //x32 = x32 * 214013U + 2531011U;
            //x32 = x32 * 1140671485U + 12820163U;
            //x32 = x32 * 2147483629U + 2147483587U;
            //x32 = x32 * 16807U + 0U;
            //x32 = x32 * 16807U + 1U;
            //x32 = x32 * 48271U + 0U;
            //x32 = x32 * 48271U + 1U;
            //x32 = x32 * 69069U + 1U;
            //x32 = x32 * 65539U + 0U;
            //x32 = x32 * 65539U + 1U;



            // Simple increment to compare to the other methods.
            //++ x32;

            ++ period;
         }
         //while( x32 != (uint) seed64 );
         while( x322 != ( ( (uint) seed64 << 16 ) | ( (uint) seed64 >> 16 ) ) * 2891336453U + 1640531513U );
         //while( ( x32 >> 2 ) != ( (uint) seed64 >> 2 ) );
         //while( ( x32 >> 1 ) != ( (uint) seed64 >> 1 ) );
         //while( ( x32 << 1 ) != ( (uint) seed64 << 1 ) );
         //while( (uint) x64 != (uint) seed64 );
         //while( (ushort) x64 != (ushort) seed64 );
         //while( (byte) x64 != (byte) seed64 );
         //while( (ushort) x642 != (ushort) seed64 );

         // This doesn't work the way one might hope.
         //while( (uint) x642 != (uint) ( ( ( seed64 << 32 ) | ( seed64 >> 32 ) ) * 2862933555777941757UL + 3037000493UL ) );

         //while( ( ( x64 ^ seed64 ) & 0x000000000000000FUL ) != 0U );
         //while( ( ( x64 ^ seed64 ) & 0x0000000FFFFFFFFFUL ) != 0U );
         //while( ( ( x64 ^ seed64 ) & 0xFFFFFFFF00000000UL ) != 0U );
         //while( ( (uint) ( x64 >> 32 ) ^ (uint) x64 ) != ( (uint) ( seed64 >> 32 ) ^ (uint) seed64 ) );
         
         timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp() - timeSpan1;
         System.Console.WriteLine( @"0x" + period.ToString( @"X" ) );
         System.Console.WriteLine( (double) x32Sum / (double) period - (double) 0xFFFFFFFFU * 0.5 );
         System.Console.WriteLine( timeSpan1 );
         double timeSpan1Milliseconds = (double) timeSpan1 * 1000.0 / (double) System.Diagnostics.Stopwatch.Frequency;
         System.Console.WriteLine( timeSpan1Milliseconds.ToString( @"F0" ) );
      }

      public static void LinearFeedbackShiftRegisterPrototype()
      {
         // https://en.wikipedia.org/wiki/Linear_feedback_shift_register
         // This is not quite random, right?

         long timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp();

         //ulong seed64 = ( ~ 0U );
         //ulong seed64 = 0U;
         //ulong seed64 = 1U;
         ulong seed64 = ( ( (ulong) timeSpan1 << 32 ) | ( (ulong) timeSpan1 >> 32 ) ) ^ (ulong) System.DateTime.UtcNow.Ticks;

         uint lfsr32 = (uint) seed64;
         //ulong lfsr64 = seed64;

         long period = 0;

         timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp();

         do
         {
            // taps: 32 31 29 1; feedback polynomial: x^32 + x^31 + x^29 + x + 1
            // It's probably possible to eliminate the negation by reversing the direction of shifts.
            // This will involve the sign bit propagation right by 31.
            lfsr32 = ( lfsr32 >> 1 ) ^ ( (uint) ( - (int) ( lfsr32 & 1u ) ) & 0xD0000001u );

            //lfsr32 = ( lfsr32 >> 1 ) ^ ( (uint) ( - (int) ( ( ~ lfsr32 ) & 1u ) ) & 0xD0000001u );
            //lfsr32 = ( lfsr32 >> 1 ) ^ ( ( ~ ( lfsr32 & 1u ) ) & 0xD0000001u );
            //lfsr32 = ( ~ lfsr32 );

            //lfsr32 =
            //   ( lfsr32 >> 1 ) ^
            //   ( ( ( lfsr32 & ( 1U << 31 ) ) << ( 31 - 31 ) ) ^
            //     ( ( lfsr32 & ( 1U << 21 ) ) << ( 31 - 21 ) ) ^
            //     ( ( lfsr32 & ( 1U << 1 ) ) << ( 31 - 1 ) ) ^
            //     ( ( lfsr32 & ( 1U << 0 ) ) << ( 31 - 0 ) ) ^
            //     ( 1U << 31 )
            //   );

            // Simple increment to compare to the other methods.
            //++ lfsr32;

            ++ period;
         }
         while( lfsr32 != (uint) seed64 );
         
         timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp() - timeSpan1;
         System.Console.WriteLine( @"0x" + period.ToString( @"X" ) );
         System.Console.WriteLine( timeSpan1 );
         double timeSpan1Milliseconds = (double) timeSpan1 * 1000.0 / (double) System.Diagnostics.Stopwatch.Frequency;
         System.Console.WriteLine( timeSpan1Milliseconds.ToString( @"F0" ) );
      }

      public static void XOrShiftGeneratorPrototype()
      {
         long timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp();

         //ulong seed64 = ( ~ 0U );
         //ulong seed64 = 0U;
         //ulong seed64 = 1U;
         ulong seed64 = ( ( (ulong) timeSpan1 << 32 ) | ( (ulong) timeSpan1 >> 32 ) ) ^ (ulong) System.DateTime.UtcNow.Ticks;

         uint x32 = (uint) seed64;
         //ulong x64 = seed64;

         ulong x32Sum = 0U;

         long period = 0;

         timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp();

         do
         {
            x32 ^= x32 << 13;
            x32 ^= x32 >> 17;
            x32 ^= x32 << 5;

            // 64 bits.
            //x^=(x<<13);
            //x^=(x>>7);
            //x^=(x<<17);
   
            x32Sum += x32;

            ++ period;
         }
         while( x32 != (uint) seed64 );

         timeSpan1 = System.Diagnostics.Stopwatch.GetTimestamp() - timeSpan1;
         System.Console.WriteLine( @"0x" + period.ToString( @"X" ) );
         System.Console.WriteLine( (double) x32Sum / (double) period - (double) 0xFFFFFFFFU * 0.5 );
         System.Console.WriteLine( timeSpan1 );
         double timeSpan1Milliseconds = (double) timeSpan1 * 1000.0 / (double) System.Diagnostics.Stopwatch.Frequency;
         System.Console.WriteLine( timeSpan1Milliseconds.ToString( @"F0" ) );
      }

#endif
}
}
