#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TErrorHandlerScope.hpp"

#include "../Diagnostics/Macros.cpp"
#include "./TErrorHandler.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ErrorHandling
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TErrorHandlerScope::TErrorHandlerScope() :
      // It's unnecessary to initialize this field. But we validate it, so if I eliminate this initialization
      // I would also have to eliminate the validations.
      OldErrorHandler_( nullptr )
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

#if( /* {public SetErrorHandler}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TErrorHandlerScope::SetErrorHandler()
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OldErrorHandler_ == nullptr );

      // TODO 3 yg? Consider eliminating memory allocation and storing the whole {TErrorHandler} instance in a member field,
      // TODO 3 yg? like {::RApiFacade::TREngineAdapter::REnginePlace_}.
//TODO do this sooner; can we simpy declare a {TErrorHandler} field and not a "place"?
      OldErrorHandler_ = ::Poco::ErrorHandler::set( new TErrorHandler );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OldErrorHandler_ != nullptr );
   }

#endif
#if( /* {public RestoreErrorHandler}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TErrorHandlerScope::RestoreErrorHandler()
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( OldErrorHandler_ != nullptr );
      delete ::Poco::ErrorHandler::set( OldErrorHandler_ );

      // Just like in the constructor, it's unnecessary to reset this field.
      OldErrorHandler_ = nullptr;
   }

#endif
}
}
