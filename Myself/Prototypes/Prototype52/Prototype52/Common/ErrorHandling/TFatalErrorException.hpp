#pragma once

#include "./TExceptionBase.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace ErrorHandling
{
   // yg? We don't use this class.
   // yg? Consider eliminating this class.

   POCO_DECLARE_EXCEPTION( , TFatalErrorException, TExceptionBase )
}
}
