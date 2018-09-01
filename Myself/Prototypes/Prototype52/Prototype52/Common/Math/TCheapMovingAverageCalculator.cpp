#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TCheapMovingAverageCalculator.hpp"

#include "./TCheapMovingAverageCalculatorConfiguration.cpp"
#include "./TMathHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Math
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TCheapMovingAverageCalculator::TCheapMovingAverageCalculator()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TCheapMovingAverageCalculator::TCheapMovingAverageCalculator
      ( TCheapMovingAverageCalculatorConfiguration && configuration1
      )
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

   inline void TCheapMovingAverageCalculator::Initialize
      ( TCheapMovingAverageCalculatorConfiguration && configuration1
      )
   {
      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TCheapMovingAverageCalculator::DoInitialize
      ( TCheapMovingAverageCalculatorConfiguration && configuration1
      )
   {
      Factor2_ = ::std::move( configuration1.Factor2 );
      DoReset();
   }

#endif
#if( /* {public Reset}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TCheapMovingAverageCalculator::Reset()
   {
      DoReset();
   }

#endif
#if( /* {private DoReset}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TCheapMovingAverageCalculator::DoReset()
   {
      // The logic would work even if we don't reset this field but we don't want the caller to see garbage.
      CheapMovingAverage_ = ::std::numeric_limits< double >::lowest();

      UpdateCounter_ = 0;
   }

#endif

#if( /* {public Update}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TCheapMovingAverageCalculator::Update
      ( double value1
      )
   {
      // yg? For performance, we could initialize {CheapMovingAverage_} with 0.0 and eliminate the following {if}.
      // yg? Another solution is to maintain a method pointer member field and call the method pointer directly.
      // yg? But would it really work faster?

      if( UpdateCounter_ <= 0 )
      {
         CheapMovingAverage_ = value1;
      }
      else
      {
         //CheapMovingAverage_ += ( value1 - CheapMovingAverage_ ) * Factor2_;
         CheapMovingAverage_ = TMathHelpers::CalculateNextCheapMovingAverage( CheapMovingAverage_, value1, Factor2_ );
      }

      // Assuming this will not overflow.
      ++ UpdateCounter_;
   }

#endif

#if( /* {public CheapMovingAverage}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline double TCheapMovingAverageCalculator::CheapMovingAverage() const
   {
      return CheapMovingAverage_;
   }

#endif
#if( /* {public UpdateCounter}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::Poco::Int64 TCheapMovingAverageCalculator::UpdateCounter() const
   {
      return UpdateCounter_;
   }

#endif
}
}
