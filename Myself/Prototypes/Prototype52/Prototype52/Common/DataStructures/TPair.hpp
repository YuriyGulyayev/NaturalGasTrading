#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace DataStructures
{
   // Simple pair with only autogenerated instance default constructor, instance copy constructor, instance destructor, {operator =}.
   // yg? Should this be a {struct}?

   template
      < typename TValue1_,
         typename TValue2_
      >
   class TPair
   {
      //
      public: TValue1_ Value1;

      //
      public: TValue2_ Value2;
   };

#if( /* {public operator ==}. */ 1 )

   //

   template
      < typename TValue1_,
         typename TValue2_
      >
   bool operator ==
      ( TPair< TValue1_, TValue2_ > const & instance1,
        TPair< TValue1_, TValue2_ > const & instance2
      );

#endif
#if( /* {public operator !=}. */ 1 )

   //

   template
      < typename TValue1_,
         typename TValue2_
      >
   bool operator !=
      ( TPair< TValue1_, TValue2_ > const & instance1,
        TPair< TValue1_, TValue2_ > const & instance2
      );

#endif
}
}
