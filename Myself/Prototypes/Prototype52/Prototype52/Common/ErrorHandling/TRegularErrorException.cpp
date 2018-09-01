#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TRegularErrorException.hpp"

#include "./TCriticalErrorException.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ErrorHandling
{
#if( /* {TRegularErrorException}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   POCO_IMPLEMENT_EXCEPTION( TRegularErrorException, TCriticalErrorException, "Regular Error" )

#endif
}
}
