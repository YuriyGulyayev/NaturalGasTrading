#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TCriticalErrorException.hpp"

#include "./TFatalErrorException.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ErrorHandling
{
#if( /* {TCriticalErrorException}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   POCO_IMPLEMENT_EXCEPTION( TCriticalErrorException, TFatalErrorException, "Critical Error" )

#endif
}
}
