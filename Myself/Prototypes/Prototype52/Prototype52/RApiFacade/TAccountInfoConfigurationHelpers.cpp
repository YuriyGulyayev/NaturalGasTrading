#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TAccountInfoConfigurationHelpers.hpp"

#include "./TAccountInfoConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public ExtractConfiguration}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TAccountInfoConfigurationHelpers::ExtractConfiguration
      ( TAccountInfoConfiguration & accountInfoConfiguration1,
        ::RApi::AccountInfo const & accountInfo1
      )
   {
      accountInfoConfiguration1.sFcmId.assign
         ( accountInfo1.sFcmId.pData, static_cast< unsigned int >( accountInfo1.sFcmId.iDataLen ) );
      accountInfoConfiguration1.sIbId.assign
         ( accountInfo1.sIbId.pData, static_cast< unsigned int >( accountInfo1.sIbId.iDataLen ) );
      accountInfoConfiguration1.sAccountId.assign
         ( accountInfo1.sAccountId.pData, static_cast< unsigned int >( accountInfo1.sAccountId.iDataLen ) );
   }

#endif
}
