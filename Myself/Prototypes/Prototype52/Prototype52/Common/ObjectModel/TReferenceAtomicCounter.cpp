#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TReferenceAtomicCounter.hpp"

#include "../Threading/TMemoryAtomicOperationsHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ObjectModel
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TReferenceAtomicCounter::TReferenceAtomicCounter() :
      Value_( 1 )
   {
      // yg? I commented this out as a constructor in general is not required to be atomic.
      // yg? Threading::TMemoryAtomicOperationsHelpers::SetValue( ReferenceCounter_, 1 );
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public ReferenceCounterValue}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TReferenceAtomicCounter::ReferenceCounterValue() const
   {
      // Non-volatile read.
      return Value_;
   }

#endif
#if( /* {public referenceCount}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TReferenceAtomicCounter::referenceCount() const
   {
      //// yg? <Quote>A read of a volatile object (volatile read) has Acquire semantics.</Quote>
      //// yg? We don't really need that here. At least this is hopefully not a hardware memory barrier.
      //return static_cast< int const volatile & >( ReferenceCounter_ );

      //// yg? Partially volatile read.
      //return CodeOptimization::TCodeOptimizationHelpers::GetVolatileValue( ReferenceCounter_ );

      // Volatile read.
      return static_cast< int const volatile & >( Value_ );
   }

#endif
#if( /* {public duplicate}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TReferenceAtomicCounter::duplicate() const
   {
      // yg? Consider {assert}ing that the result is positive.
      return Threading::TMemoryAtomicOperationsHelpers::IncrementAndGetValueWithoutMemoryBarrier( Value_ );
   }

#endif
#if( /* {public release}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TReferenceAtomicCounter::release() const
   {
      // yg? Consider {assert}ing that the result is not negative.
      return Threading::TMemoryAtomicOperationsHelpers::DecrementAndGetValueWithMemoryReleaseBarrier( Value_ );
   }

#endif
}
}
