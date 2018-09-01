#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TCodeOptimizationHelpers.hpp"

//#include "./.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace CodeOptimization
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

#if( /* //{public MemoryReadBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TCodeOptimizationHelpers::MemoryReadBarrier()
   //{
   //#if( defined( _MSC_VER ) )
   //   ::_ReadBarrier();
   //#elif( defined( __GNUC__ ) )
   //   #error yg?? ToDo
   //#else
   //   #error ...
   //#endif
   //}

#endif
#if( /* //{public MemoryWriteBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TCodeOptimizationHelpers::MemoryWriteBarrier()
   //{
   //#if( defined( _MSC_VER ) )
   //   ::_WriteBarrier();
   //#elif( defined( __GNUC__ ) )
   //   #error yg?? ToDo
   //#else
   //   #error ...
   //#endif
   //}

#endif
#if( /* //{public MemoryReadWriteBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TCodeOptimizationHelpers::MemoryReadWriteBarrier()
   //{
   //#if( defined( _MSC_VER ) )
   //   ::_ReadWriteBarrier();
   //#elif( defined( __GNUC__ ) )
   //   #error yg?? ToDo
   //#else
   //   #error ...
   //#endif
   //}

#endif

#if( /* //{public GetVolatileValue}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TValue_
   //   >
   //inline TValue_ TCodeOptimizationHelpers::GetVolatileValue
   //   ( TValue_ const & value
   //   )
   //{
   //   // yg? New version.
   //   // yg? The docs is misleading but I believe this is correct.
   //   // yg? The idea is to prevent the elimination of this read in case a "normal" read was made right before this method was called.
   //   // yg? Now any previous reads will complete at the point of the {MemoryReadBarrier} call and the following read will not be eliminated.
   //   {
   //      MemoryReadBarrier();
   //      return value;
   //   }

   //   // yg? Old version.
   //   //{
   //   //   TValue_ value1( value );
   //   //   MemoryReadBarrier();
   //   //   return value1;
   //   //}
   //}

#endif
#if( /* //{public SetVolatileValue}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TValue_
   //   >
   //inline void TCodeOptimizationHelpers::SetVolatileValue
   //   ( TValue_ & destinationValue,
   //     TValue_ sourceValue
   //   )
   //{
   //   destinationValue = ::std::move( sourceValue );
   //   MemoryWriteBarrier();
   //}

#endif
}
}
