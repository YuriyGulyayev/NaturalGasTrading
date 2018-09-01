#pragma once

#include "StdAfx.h"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TSingleInstrumentOrderBase.hpp"

#include "../../Common/ObjectModel/TDataSubscriptionBase.cpp"

#include "../../Common/SourceCodeModel/SourceFooter.hpp"

namespace Finance
{
namespace Trading
{
#if( /* {protected} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TDerivedDataType_,
         typename TInstrument_
      >
   inline TSingleInstrumentOrderBase< TDerivedDataType_, TInstrument_ >::TSingleInstrumentOrderBase()
      //Instrument_( ??? )
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
         typename TInstrument_
      >
   inline void TSingleInstrumentOrderBase< TDerivedDataType_, TInstrument_ >::Prepare
      ( TInstrument_ const & instrument1
      )
   {
      Instrument_ = ( & instrument1 );
   }

#endif

#if( /* {public Instrument}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TDerivedDataType_,
         typename TInstrument_
      >
   inline TInstrument_ const & TSingleInstrumentOrderBase< TDerivedDataType_, TInstrument_ >::Instrument() const
   {
      return ( * Instrument_ );
   }

#endif
}
}
