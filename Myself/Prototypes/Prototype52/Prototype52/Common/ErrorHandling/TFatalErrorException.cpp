#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TFatalErrorException.hpp"

#include "./TExceptionBase.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ErrorHandling
{
#if( /* {TFatalErrorException}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   POCO_IMPLEMENT_EXCEPTION( TFatalErrorException, TExceptionBase, "Fatal Error" )

#endif
}
}
