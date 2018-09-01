#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace ErrorHandling
{
   // Base of our exceptions.
   // yg? A POCO exception contains an {::std::string}, which means its creation will fail when there is not enough RAM available.
   // yg? This class should be abstract.

   POCO_DECLARE_EXCEPTION( , TExceptionBase, ::Poco::ApplicationException )
}
}
