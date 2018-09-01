#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrument.hpp"

#include "../Finance/TInstrumentBase.cpp"
#include "./TInstrumentConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TInstrument::TInstrument()
   {
   }

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TInstrument::TInstrument
      ( TInstrumentConfiguration && configuration1
      ) :
      ::Finance::TInstrumentBase< TREngineAdapter >( ::std::move( configuration1 ) ),
      Symbol_( ::std::move( configuration1.Symbol ) ),
      ExchangeAbbreviation_( ::std::move( configuration1.ExchangeAbbreviation ) ),
      TradeRouteName_( ::std::move( configuration1.TradeRouteName ) )
   {
      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public Initialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TInstrument::Initialize
      ( TInstrumentConfiguration && configuration1
      )
   {
      ::Finance::TInstrumentBase< TREngineAdapter >::Initialize( ::std::move( configuration1 ) );

      Symbol_.assign( ::std::move( configuration1.Symbol ) );
      ExchangeAbbreviation_.assign( ::std::move( configuration1.ExchangeAbbreviation ) );
      TradeRouteName_.assign( ::std::move( configuration1.TradeRouteName ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TInstrument::DoInitialize
      ( TInstrumentConfiguration && configuration1
      )
   {
      QuantityIncrementMinLimit = ::std::move( configuration1.QuantityIncrementMinLimit );
      PriceIncrementMinLimit = ::std::move( configuration1.PriceIncrementMinLimit );
   }

#endif

#if( /* {public Symbol}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::std::string const & TInstrument::Symbol() const
   {
      return Symbol_;
   }

#endif
#if( /* {public ExchangeAbbreviation}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::std::string const & TInstrument::ExchangeAbbreviation() const
   {
      return ExchangeAbbreviation_;
   }

#endif
#if( /* {public TradeRouteName}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::std::string const & TInstrument::TradeRouteName() const
   {
      return TradeRouteName_;
   }

#endif
}
