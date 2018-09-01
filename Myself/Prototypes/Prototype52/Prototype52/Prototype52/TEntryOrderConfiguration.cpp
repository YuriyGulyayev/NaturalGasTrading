#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEntryOrderConfiguration.hpp"

//#include "../RApiFacade/TOrderTypeCode.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TEntryOrderConfiguration::TEntryOrderConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance move constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TEntryOrderConfiguration::TEntryOrderConfiguration
      ( TEntryOrderConfiguration && source
      ) :
      //TypeCode( ::std::move( source.TypeCode ) ),
      Quantity( ::std::move( source.Quantity ) ),
      TriggerPriceOffset1( ::std::move( source.TriggerPriceOffset1 ) ),
      TriggerPriceOffset2( ::std::move( source.TriggerPriceOffset2 ) )
      //LimitPriceOffset( ::std::move( source.LimitPriceOffset ) ),
      //GoodForTimeSpanMilliseconds( ::std::move( source.GoodForTimeSpanMilliseconds ) )
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

   inline TEntryOrderConfiguration & TEntryOrderConfiguration::operator =
      ( TEntryOrderConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TEntryOrderConfiguration::Assign
      ( TEntryOrderConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      //TypeCode = ::std::move( source.TypeCode );
      Quantity = ::std::move( source.Quantity );
      TriggerPriceOffset1 = ::std::move( source.TriggerPriceOffset1 );
      TriggerPriceOffset2 = ::std::move( source.TriggerPriceOffset2 );
      //LimitPriceOffset = ::std::move( source.LimitPriceOffset );
      //GoodForTimeSpanMilliseconds = ::std::move( source.GoodForTimeSpanMilliseconds );
   }

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TEntryOrderConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
