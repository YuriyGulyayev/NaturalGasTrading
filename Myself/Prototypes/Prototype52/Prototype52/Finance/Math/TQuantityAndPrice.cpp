#pragma once

#include "StdAfx.h"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TQuantityAndPrice.hpp"

//#include "./.cpp"

#include "../../Common/SourceCodeModel/SourceFooter.hpp"

namespace Finance
{
namespace Math
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

#if( /* {public Reset}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TQuantityAndPrice::Reset()
   {
      Quantity = 0.0;
      Price = ::std::numeric_limits< double >::lowest();
   }

#endif
#if( /* {public Equals}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TQuantityAndPrice::Equals
      ( TQuantityAndPrice const & instance1,
        TQuantityAndPrice const & instance2
      )
   {
      // No {float}-rounding. It probably won't even work in the precise floating point model in the Release Win32 build.
      return ( instance1.Quantity == instance2.Quantity && instance1.Price == instance2.Price );
   }

#endif
#if( /* {public GetPriceIfAvailable}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline double TQuantityAndPrice::GetPriceIfAvailable() const
   {
      // Test.
      //TQuantityAndPrice::Equals( static_cast< TQuantityAndPrice const & >( TQuantityAndPrice() ), ( * this ) );
      //TQuantityAndPrice::Equals( static_cast< TQuantityAndPrice const & >( TQuantityAndPrice() ), static_cast< TQuantityAndPrice const & >( TQuantityAndPrice() ) );
      //TQuantityAndPrice::Equals( static_cast< TQuantityAndPrice const && >( TQuantityAndPrice() ), static_cast< TQuantityAndPrice const && >( TQuantityAndPrice() ) );
      //TQuantityAndPrice::Equals( TQuantityAndPrice(), TQuantityAndPrice() );

      // No {float}-rounding. It probably won't even work in the precise floating point model in the Release Win32 build.
      return ( /*static_cast< float >*/( Quantity ) > 0.0/*F*/ ) ? Price : ::std::numeric_limits< double >::lowest();
   }

#endif
}
}
