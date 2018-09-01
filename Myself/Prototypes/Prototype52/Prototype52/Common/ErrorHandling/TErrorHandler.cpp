#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TErrorHandler.hpp"

#include "./TErrorHandlingHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ErrorHandling
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TErrorHandler::TErrorHandler()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public exception}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TErrorHandler::exception
      ( ::Poco::Exception const & exception1
      )
   {
      TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );

      // yg? Consider using { __declspec( noreturn ) }.
      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   }

#endif
#if( /* {public exception}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TErrorHandler::exception
      ( ::std::exception const & exception1
      )
   {
      TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );

      // yg? See a related comment in the 1st overload above.
      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   }

#endif
#if( /* {public exception}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TErrorHandler::exception()
   {
      TErrorHandlingHelpers::AtomicLastChanceHandleException();

      // yg? See a related comment in the 1st overload above.
      YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   }

#endif
}
}
