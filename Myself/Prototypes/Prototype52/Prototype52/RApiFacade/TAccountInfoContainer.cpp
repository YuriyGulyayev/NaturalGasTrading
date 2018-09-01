#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TAccountInfoContainer.hpp"

#include "./TAccountInfoConfiguration.cpp"
#include "./TAccountInfoConfigurationHelpers.cpp"
#include "./TRApiHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TAccountInfoContainer::TAccountInfoContainer()
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

#if( /* {public Assign}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TAccountInfoContainer::Assign
      ( ::RApi::AccountInfo const & accountInfo1
      )
   {
      TAccountInfoConfigurationHelpers::ExtractConfiguration( AccountInfoConfiguration_, accountInfo1 );
      TRApiHelpers::PopulateAccountInfo( AccountInfo_, AccountInfoConfiguration_ );
   }

#endif
#if( /* {public AccountInfo}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::RApi::AccountInfo const & TAccountInfoContainer::AccountInfo() const
   {
      return AccountInfo_;
   }

#endif
}
