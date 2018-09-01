#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TConditionValidationHelpers.hpp"

//#include "./.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ConditionValidation
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

#if( /* //{public ValidateValueLessThan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TValue1, <<<this should end with a {_}.
   //      typename TException1 <<<this should end with a {_}.
   //      // yg? bool isErrorCritical
   //   >
   //inline void TConditionValidationHelpers::ValidateValueLessThan
   //   ( TValue1 value1,
   //     TValue1 value2,
   //     bool isErrorCritical
   //   )
   //{
   //   if( value1 < value2 )
   //   {
   //   }
   //   else
   //   {
//>>>Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //      if( isErrorCritical )
   //      {
   //         static char const constantString1AsArray[]( "Critical; {value1 >= value2}" );
   //         throw TException1( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ), 0 );
   //      }
   //      else
   //      {
   //         static char const constantString1AsArray[]( "Error; {value1 >= value2}" );
   //         throw TException1( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ), 0 );
   //      }
   //   }
   //}

#endif
}
}
