#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TExceptionBase.hpp"

//#include "./.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ErrorHandling
{
#if( /* {TExceptionBase}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   POCO_IMPLEMENT_EXCEPTION( TExceptionBase, ::Poco::ApplicationException, static_cast< char const * >( nullptr ) )

#endif
}
}
