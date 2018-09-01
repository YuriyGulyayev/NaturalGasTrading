#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TRecoverableErrorException.hpp"

#include "./TRegularErrorException.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ErrorHandling
{
#if( /* {TRecoverableErrorException}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   POCO_IMPLEMENT_EXCEPTION( TRecoverableErrorException, TRegularErrorException, "Recoverable Error" )

#endif
}
}
