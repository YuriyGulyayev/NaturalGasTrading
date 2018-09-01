#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TDataStructuresHelpers.hpp"

#include "../Math/TMultiplyWithCarryRandomNumberCommonGeneratorHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace DataStructures
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

#if( /* {public RandomShuffleCollectionItems}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TCollectionIterator_
      >
   inline void TDataStructuresHelpers::RandomShuffleCollectionItems
      ( TCollectionIterator_ collectionBeginIterator,
        TCollectionIterator_ collectionEndIterator
      )
   {
   #if( _MSC_VER != 1600 )
      #error yg?? Verify this.
   #endif

      // yg? The parameter and the return value are required to be of the iterator's difference type but Microsoft implementation works when both are {unsigned int}.
      // yg? The return value is required to be less than the argument but Microsoft implementation works when it's not.
      // yg? I am not sure if this works when a 32-bit collection contains over 0x80000000U items.
      // yg? The result will probably be less random when a 64-bit collection contains over 0x100000000U items.
      // yg? This should really be a template that returns a value of the same type as was passed to it but currently C++ doesn't support template lambdas.
      // yg? One way to workaround this could be to declare a template class and this lambda inside of it.
      // yg? Someone wrote on a forum that something like that was done in Boost.
      // yg? The result of a modulo operation is not uniformly distributed. This can be a problem if the collection is long. This can be fixed by scaling the random number.
      auto randomNumberGenerator1
         ( []
           ( unsigned int //collectionItemIndex
           )
           -> unsigned int
           {
               return Math::TMultiplyWithCarryRandomNumberCommonGeneratorHelpers::MultiplyWithCarryRandomNumberCommonGenerator.GenerateMediumQuality32Bits();
           }
         );

      ::std::random_shuffle( collectionBeginIterator, collectionEndIterator, randomNumberGenerator1 );
   }

#endif

#if( /* {public GetMapItemsKeyMaxLength}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TMapIterator_
      >
   inline auto TDataStructuresHelpers::GetMapItemsKeyMaxLength
      ( TMapIterator_ mapBeginIterator1,
        TMapIterator_ mapEndIterator1
      )
      -> decltype( mapBeginIterator1->first.length() )
   {
      decltype( mapBeginIterator1->first.length() ) mapItemsKeyMaxLength( static_cast< decltype( mapBeginIterator1->first.length() ) >( 0U ) );
      for( ; mapBeginIterator1 != mapEndIterator1 ; ++ mapBeginIterator1 )
      {
         Math::TMathHelpers::AssignMaxValue( mapItemsKeyMaxLength, mapBeginIterator1->first.length() );
      }
      return mapItemsKeyMaxLength;
   }

#endif
}
}
