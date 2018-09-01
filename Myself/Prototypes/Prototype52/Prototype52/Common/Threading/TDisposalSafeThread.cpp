#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TDisposalSafeThread.hpp"

//#include "./.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Threading
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TThread_
      >
   inline TDisposalSafeThread< TThread_ >::TDisposalSafeThread()
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TThread_
      >
   inline TDisposalSafeThread< TThread_ >::TDisposalSafeThread
      ( ::std::string const & name
      ) :
      TThread_( name )
   {
   }

#endif
#if( /* {public} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TThread_
      >
   inline TDisposalSafeThread< TThread_ >::~TDisposalSafeThread()
   {
      // The docs says: "if multiple threads try to join the same thread, the result is undefined".
      // But this destructor is not supposed to be called on multiple threads.
      join();
   }

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
}
}
