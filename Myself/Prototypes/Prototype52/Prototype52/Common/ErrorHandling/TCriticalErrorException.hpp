#pragma once

#include "./TFatalErrorException.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace ErrorHandling
{
   //

   POCO_DECLARE_EXCEPTION( , TCriticalErrorException, TFatalErrorException )
}
}
