#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TUntradableConditionConfiguration.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TUntradableConditionConfiguration::TUntradableConditionConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance move constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TUntradableConditionConfiguration::TUntradableConditionConfiguration
      ( TUntradableConditionConfiguration && source
      ) :
      EconomicReportValueMinLimit1( ::std::move( source.EconomicReportValueMinLimit1 ) ),
      EconomicReportValueMaxLimit1( ::std::move( source.EconomicReportValueMaxLimit1 ) ),
      EconomicReportValueMinLimit2( ::std::move( source.EconomicReportValueMinLimit2 ) ),
      EconomicReportValueMaxLimit2( ::std::move( source.EconomicReportValueMaxLimit2 ) )
   {
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TUntradableConditionConfiguration & TUntradableConditionConfiguration::operator =
      ( TUntradableConditionConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TUntradableConditionConfiguration::Assign
      ( TUntradableConditionConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      EconomicReportValueMinLimit1 = ::std::move( source.EconomicReportValueMinLimit1 );
      EconomicReportValueMaxLimit1 = ::std::move( source.EconomicReportValueMaxLimit1 );
      EconomicReportValueMinLimit2 = ::std::move( source.EconomicReportValueMinLimit2 );
      EconomicReportValueMaxLimit2 = ::std::move( source.EconomicReportValueMaxLimit2 );
   }

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TUntradableConditionConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
