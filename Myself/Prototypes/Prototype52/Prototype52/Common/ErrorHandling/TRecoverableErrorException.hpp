#pragma once

#include "./TRegularErrorException.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace ErrorHandling
{
   //

   POCO_DECLARE_EXCEPTION( , TRecoverableErrorException, TRegularErrorException )
}
}
