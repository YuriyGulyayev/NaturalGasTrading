#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace DataStructures
{
   // Ensuring that the size of the {union} is not greater than the maximum size among its members.
   #pragma pack( push, 1 )

   // yg? An equivalent {union} might already exist in some library.

   template
      < typename TValue1_,
         typename TValue2_
      >
   union TUnionPair
   {
      //
      TValue1_ Value1;

      //
      TValue2_ Value2;
   };

   #pragma pack( pop )
}
}
