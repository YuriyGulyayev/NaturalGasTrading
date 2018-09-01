#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TDataSubscriptionBase.hpp"

//#include "./.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace ObjectModel
{
#if( /* {protected} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TDerivedDataType_
      >
   inline TDataSubscriptionBase< TDerivedDataType_ >::TDataSubscriptionBase()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public RaiseOnReceivedData}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TDerivedDataType_
      >
   inline void TDataSubscriptionBase< TDerivedDataType_ >::RaiseOnReceivedData()
   {
      //OnReceivedData.notify( this, ::Poco::EventArgs() );
      //OnReceivedData.notify( static_cast< void const * >( nullptr ), ( * static_cast< ::Poco::EventArgs * >( nullptr ) ) );
      
      TDerivedDataType_ * this1( static_cast< TDerivedDataType_ * >( this ) );
      OnReceivedData.notify( static_cast< void const * >( nullptr ), this1 );
   }

#endif
}
}
