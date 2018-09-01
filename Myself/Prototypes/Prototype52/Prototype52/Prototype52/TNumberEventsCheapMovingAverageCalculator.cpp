#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TNumberEventsCheapMovingAverageCalculator.hpp"

#include "../Common/Math/TCheapMovingAverageCalculator.cpp"
#include "./TNumberEventsCheapMovingAverageCalculatorConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TNumberEventsCheapMovingAverageCalculator::TNumberEventsCheapMovingAverageCalculator()
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TNumberEventsCheapMovingAverageCalculator::TNumberEventsCheapMovingAverageCalculator
      ( TNumberEventsCheapMovingAverageCalculatorConfiguration && configuration1
      ) :
      ::Common::Math::TCheapMovingAverageCalculator( ::std::move( configuration1 ) )
   {
      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public Initialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TNumberEventsCheapMovingAverageCalculator::Initialize
      ( TNumberEventsCheapMovingAverageCalculatorConfiguration && configuration1
      )
   {
      ::Common::Math::TCheapMovingAverageCalculator::Initialize( ::std::move( configuration1 ) );

      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNumberEventsCheapMovingAverageCalculator::DoInitialize
      ( //TNumberEventsCheapMovingAverageCalculatorConfiguration && configuration1
      )
   {
      DoReset();
   }

#endif
#if( /* {public Reset}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNumberEventsCheapMovingAverageCalculator::Reset()
   {
      ::Common::Math::TCheapMovingAverageCalculator::Reset();
      DoReset();
   }

#endif
#if( /* {private DoReset}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNumberEventsCheapMovingAverageCalculator::DoReset()
   {
      EventSinceLastUpdateCounter_ = 0;
   }

#endif

#if( /* {public RegisterEvent}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNumberEventsCheapMovingAverageCalculator::RegisterEvent()
   {
      // Assuming this will not overflow.
      ++ EventSinceLastUpdateCounter_;
   }

#endif
#if( /* {public EventSinceLastUpdateCounter}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TNumberEventsCheapMovingAverageCalculator::EventSinceLastUpdateCounter() const
   {
      return EventSinceLastUpdateCounter_;
   }

#endif
#if( /* {public Update}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TNumberEventsCheapMovingAverageCalculator::Update()
   {
      // yg? ::Common::Math::TCheapMovingAverageCalculator::Update( static_cast< double >( static_cast< unsigned int >( EventSinceLastUpdateCounter_ ) ) );
      ::Common::Math::TCheapMovingAverageCalculator::Update( static_cast< double >( EventSinceLastUpdateCounter_ ) );
      EventSinceLastUpdateCounter_ = 0;
   }

#endif
}
