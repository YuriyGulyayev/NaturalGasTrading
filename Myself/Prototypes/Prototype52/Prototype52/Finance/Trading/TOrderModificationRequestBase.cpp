#pragma once

#include "StdAfx.h"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TOrderModificationRequestBase.hpp"

#include "../../Common/ObjectModel/TDataSubscriptionBase.cpp"

#include "../../Common/SourceCodeModel/SourceFooter.hpp"

namespace Finance
{
namespace Trading
{
#if( /* {protected} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TDerivedDataType_,
         typename TOrder_
      >
   inline TOrderModificationRequestBase< TDerivedDataType_, TOrder_ >::TOrderModificationRequestBase()
      //Order_( ??? )
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

   template
      < typename TDerivedDataType_,
         typename TOrder_
      >
   inline void TOrderModificationRequestBase< TDerivedDataType_, TOrder_ >::Prepare
      ( TOrder_ & order1
      )
   {
      Order_ = ( & order1 );
   }

#endif

#if( /* {public Order}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TDerivedDataType_,
         typename TOrder_
      >
   inline TOrder_ & TOrderModificationRequestBase< TDerivedDataType_, TOrder_ >::Order() const
   {
      return ( * Order_ );
   }

#endif
}
}
