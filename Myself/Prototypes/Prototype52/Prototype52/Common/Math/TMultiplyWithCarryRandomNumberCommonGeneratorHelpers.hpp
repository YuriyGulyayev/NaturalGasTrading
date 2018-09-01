#pragma once

#include "./TMultiplyWithCarryRandomNumberCommonGenerator.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace Math
{
   //

   class TMultiplyWithCarryRandomNumberCommonGeneratorHelpers abstract sealed
   {
#if( /* //{public Random}. */ 1 )

      //// yg? We access this object on multiple threads, which is hopefully not too bad.
      //public: static ::Poco::Random Random;

#endif
#if( /* {public MultiplyWithCarryRandomNumberCommonGenerator}. */ 1 )

      // We access this object on multiple threads, which is hopefully not too bad.
      // See related comments for the {TMultiplyWithCarryRandomNumberGenerator} class for more info.
      public: static TMultiplyWithCarryRandomNumberCommonGenerator MultiplyWithCarryRandomNumberCommonGenerator;

#endif

#if( /* //{(private)} Instance default constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif
   };
}
}
