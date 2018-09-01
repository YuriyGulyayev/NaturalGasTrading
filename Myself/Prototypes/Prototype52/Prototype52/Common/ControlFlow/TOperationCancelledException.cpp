#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TOperationCancelledException.hpp"

#include "../ErrorHandling/TCriticalErrorException.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ControlFlow
{
#if( /* {TOperationCancelledException}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   POCO_IMPLEMENT_EXCEPTION( TOperationCancelledException, ErrorHandling::TCriticalErrorException, "Operation Cancelled" )

#endif
}
}
