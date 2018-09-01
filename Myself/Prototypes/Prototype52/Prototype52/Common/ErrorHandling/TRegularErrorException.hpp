#pragma once

#include "./TCriticalErrorException.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace ErrorHandling
{
   // Neither critical nor recoverable error.

   POCO_DECLARE_EXCEPTION( , TRegularErrorException, TCriticalErrorException )
}
}
