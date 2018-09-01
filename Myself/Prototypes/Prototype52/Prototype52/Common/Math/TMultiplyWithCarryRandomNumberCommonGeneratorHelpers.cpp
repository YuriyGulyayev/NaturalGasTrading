#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TMultiplyWithCarryRandomNumberCommonGeneratorHelpers.hpp"

#include "./TMultiplyWithCarryRandomNumberCommonGenerator.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Math
{
#if( /* //{public Random}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //::Poco::Random ...::Random;

#endif
#if( /* {public MultiplyWithCarryRandomNumberCommonGenerator}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TMultiplyWithCarryRandomNumberCommonGenerator TMultiplyWithCarryRandomNumberCommonGeneratorHelpers::MultiplyWithCarryRandomNumberCommonGenerator;

#endif

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
}
}
