#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrumentBase.hpp"

#include "./TInstrumentBaseConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Finance
{
#if( /* {protected} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TBrokerAdapter_
      >
   inline TInstrumentBase< TBrokerAdapter_ >::TInstrumentBase()
      //BrokerAdapter_( ??? )
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {protected} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TBrokerAdapter_
      >
   inline TInstrumentBase< TBrokerAdapter_ >::TInstrumentBase
      ( TInstrumentBaseConfiguration && //configuration1
      )
      //BrokerAdapter_( ??? )
   {
      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TBrokerAdapter_
      >
   inline void TInstrumentBase< TBrokerAdapter_ >::Initialize
      ( TInstrumentBaseConfiguration && //configuration1
      )
   {
      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TBrokerAdapter_
      >
   inline void TInstrumentBase< TBrokerAdapter_ >::DoInitialize
      ( //TInstrumentBaseConfiguration && configuration1
      )
   {
   }

#endif
#if( /* {public Prepare}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TBrokerAdapter_
      >
   inline void TInstrumentBase< TBrokerAdapter_ >::Prepare
      ( TBrokerAdapter_ & brokerAdapter1
      )
   {
      BrokerAdapter_ = ( & brokerAdapter1 );
   }

#endif

#if( /* {public BrokerAdapter}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TBrokerAdapter_
      >
   inline TBrokerAdapter_ & TInstrumentBase< TBrokerAdapter_ >::BrokerAdapter() const
   {
      return ( * BrokerAdapter_ );
   }

#endif
}
