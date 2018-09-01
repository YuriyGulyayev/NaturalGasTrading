#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TThreadedActivityCancellationToken.hpp"

#include "../ObjectModel/TReferenceAtomicCounter.cpp"
#include "../ObjectModel/TReferenceCounterHelpers.cpp"
#include "./TOperationCancelledException.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ControlFlow
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TThreadedActivityCancellationToken::TThreadedActivityCancellationToken() :
      // TODO 3 yg? remove>>>ObjectModel::TReferenceAtomicCounter(),
      Signaled_( false )
   {
   }

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

#if( /* {public NonVolatileSignalOnce}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TThreadedActivityCancellationToken::NonVolatileSignalOnce()
   {
      // Non-volaile write.
      Signaled_ = true;
   }

#endif
#if( /* {public VolatileGetSignaled}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TThreadedActivityCancellationToken::VolatileGetSignaled() const
   {
      // Volatile read.
      return static_cast< bool const volatile & >( Signaled_ );
   }

#endif
#if( /* {public Signaled}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TThreadedActivityCancellationToken::Signaled() const
   {
      // Non-volatile read.
      return Signaled_;
   }

#endif
#if( /* {public NonVolatileValidateNotSignaled}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TThreadedActivityCancellationToken::NonVolatileValidateNotSignaled() const
   {
      // Non-volatile read.
      if( ! Signaled_ )

      {
         Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         //Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
         throw TOperationCancelledException( 0 );
      }
   }

#endif
#if( /* {public NonVolatileSignalOnceAndWaitUntilReleased}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TThreadedActivityCancellationToken::NonVolatileSignalOnceAndWaitUntilReleased
      ( int referenceCounter1ValueMaxLimit
      )
   {
      NonVolatileSignalOnce();

      // yg? This is guaranteed to cross only an acquire memory barrier.
      ObjectModel::TReferenceCounterHelpers::WaitUntilReferencesReleased( ( * this ), referenceCounter1ValueMaxLimit );
   }

#endif
}
}
