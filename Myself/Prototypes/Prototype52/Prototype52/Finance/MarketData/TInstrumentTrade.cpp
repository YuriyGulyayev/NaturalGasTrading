#pragma once

#include "StdAfx.h"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrumentTrade.hpp"

#include "../Math/TQuantityAndPrice.cpp"
#include "../../Common/Time/TTimeHelpers.cpp"

#include "../../Common/SourceCodeModel/SourceFooter.hpp"

namespace Finance
{
namespace MarketData
{
#if( /* {(public)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public Reset}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TInstrumentTrade::Reset()
   {
      QuantityAndPrice.Reset();
      //IsConditional = false;
      //GenerationDateTimeStampMillisecondsSince1970 = ::std::numeric_limits< double >::lowest();
      
      // This divides without a remainder.
      GenerationDateTimeStampMillisecondsSince1970 =
// TODO Validate this everywhere we use this and other similar constants. Replace division with multiplication.
         static_cast< double >( ::Common::Time::TTimeHelpers::MinTimeStamp.epochMicroseconds() / ::Poco::Timespan::MILLISECONDS );
      
      //SendingDateTimeStampMillisecondsSince1970 = ::std::numeric_limits< double >::lowest();
      SendingDateTimeStampMillisecondsSince1970 = GenerationDateTimeStampMillisecondsSince1970;
      IsValid = false;
   }

#endif
#if( /* {public Equals}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   bool TInstrumentTrade::Equals
      ( TInstrumentTrade const & instance1,
        TInstrumentTrade const & instance2
      )
   {
      return
         ( //instance1.IsConditional == instance2.IsConditional &&
           instance1.GenerationDateTimeStampMillisecondsSince1970 == instance2.GenerationDateTimeStampMillisecondsSince1970 &&
           instance1.SendingDateTimeStampMillisecondsSince1970 == instance2.SendingDateTimeStampMillisecondsSince1970 &&
           instance1.IsValid == instance2.IsValid &&
           Math::TQuantityAndPrice::Equals( instance1.QuantityAndPrice, instance2.QuantityAndPrice )
         );
   }

#endif
}
}
