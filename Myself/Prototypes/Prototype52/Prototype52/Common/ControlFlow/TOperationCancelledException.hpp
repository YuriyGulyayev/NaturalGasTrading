#pragma once

#include "../ErrorHandling/TCriticalErrorException.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace ControlFlow
{
   // Unless the exception handling code is designed to handle this particular exception, the exception will be treated as critical.
   //
   // yg? Consider adding {TControlFlowException}, derived from {ErrorHandling::TExceptionBase}.
   // yg? And write a comment that it relly has nothing to do with errors, so it's incorrect to derive it from an error related exception;
   // yg? it should itself be our the most base exception class or be derived from a sort of {TThrowable} class.
   // yg? Consider deriving {TOperationCancelledException} from {TControlFlowException}.
   // yg? Consider adding {TOperationCompletedException}, derived from {TControlFlowException}.

   POCO_DECLARE_EXCEPTION( , TOperationCancelledException, ErrorHandling::TCriticalErrorException )
}
}
