#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrumentConfigurationHelpers.hpp"

#include "./TInstrumentConfiguration.cpp"

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

   void TInstrumentConfigurationHelpers::ExtractConfiguration
      ( TInstrumentConfiguration & instrumentConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      // TODO 3 yg? We also need to call a helper method to populate {::Finance::TInstrumentBaseConfiguration}
      // TODO 3 yg? but one doesn't exist yet.

      {
         static char const parameter1NameAsArray[]( "Symbol" );

         // Unnamed objects -- move semantics.
         instrumentConfiguration1.Symbol.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "ExchangeAbbreviation" );

         // Unnamed objects -- move semantics.
         instrumentConfiguration1.ExchangeAbbreviation.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "QuantityIncrementMinLimit" );

         // yg? Do we need to round this?
         instrumentConfiguration1.QuantityIncrementMinLimit =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      // yg? 
      //instrumentConfiguration1.PriceIncrementMinLimit = ::std::numeric_limits< double >::lowest();
      instrumentConfiguration1.PriceIncrementMinLimit = 0.0;

      {
         static char const parameter1NameAsArray[]( "TradeRouteName" );

         // Unnamed objects -- move semantics.
         instrumentConfiguration1.TradeRouteName.assign
            ( abstractConfiguration1.getString( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
   }

#endif
}
