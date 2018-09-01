#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TSingleInstrumentOrderModificationRequest.hpp"

#include "../Finance/Trading/TOrderModificationRequestBase.cpp"
#include "./TOrderModificationRequestStateCode.cpp"
//TODO include TSingleInstrumentOrder.cpp ?

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TSingleInstrumentOrderModificationRequest::TSingleInstrumentOrderModificationRequest() :
      StateCode( TOrderModificationRequestStateCode_None )
   {
   }

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

#if( /* {public Prepare}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TSingleInstrumentOrderModificationRequest::Prepare
      ( TSingleInstrumentOrder & order1
      )
   {
      // This method is inline because it's called from only 1 place.
//TODO make sure the above is the case

      ::Finance::Trading::TOrderModificationRequestBase< TSingleInstrumentOrderModificationRequest, TSingleInstrumentOrder >::Prepare
         ( order1 );

//TODO move some code from order to here
   }

#endif

#if( /* {public PrepareSend}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TSingleInstrumentOrderModificationRequest::PrepareSend()
   {
      // yg? Consider making this method not inline.

//TODO
   }

#endif

#if( /* {public ModifyOrderParams}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::RApi::ModifyOrderParams const & TSingleInstrumentOrderModificationRequest::ModifyOrderParams() const
   {
      return ModifyOrderParams_;
   }

#endif
}
