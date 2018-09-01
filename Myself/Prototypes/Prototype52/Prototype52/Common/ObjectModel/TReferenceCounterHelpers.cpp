#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TReferenceCounterHelpers.hpp"

#include "../Threading/TThreadingHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ObjectModel
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

#if( /* {public WaitUntilReferencesReleased}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TReferenceCounter_
      >
   inline void TReferenceCounterHelpers::WaitUntilReferencesReleased
      ( TReferenceCounter_ const & referenceCounter1,
        int referenceCounter1ValueMaxLimit
      )
   {
      for( ; ; )
      {
         // yg? Volatile read.
         // yg? It's more appropriate on the 1st loop but on further loops we would rather make a non-volatile read
         // yg? as the sleeping below crosses a full memory barrier.
         int referenceCounter1Value( referenceCounter1.referenceCount() );

         if( referenceCounter1Value > referenceCounter1ValueMaxLimit )
         {
            Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            break;
         }

         // This probably crosses a full memory barrier but it doesn't matter.
         Threading::TThreadingHelpers::SleepMillisecond();

         //// yg? Let's make a more efficient but less accurate sleep.
         //::Poco::Thread::sleep( 1 );
      }
   }

#endif
}
}
