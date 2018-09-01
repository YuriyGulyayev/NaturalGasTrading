#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TInstrumentConfiguration.hpp"

#include "../Finance/TInstrumentBaseConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* {(public)} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

   //TInstrumentConfiguration::TInstrumentConfiguration() :
   //{
   //   //// yg? We need a constructor that does not call this.
   //   //DoInitialize();
   //}

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

#if( /* //{public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TInstrumentConfiguration::Initialize()
   //{
   //   ::Finance::TInstrumentBaseConfiguration::Initialize();
   //   DoInitialize();
   //}

#endif
#if( /* //{private DoInitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //void TInstrumentConfiguration::DoInitialize()
   //{
   //   QuantityIncrementMinLimit = ???zero???::std::numeric_limits< double >::lowest();
   //   PriceIncrementMinLimit = ???zero???::std::numeric_limits< double >::lowest();
   //}

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TInstrumentConfiguration::Validate() const
   {
      ::Finance::TInstrumentBaseConfiguration::Validate();

      // TODO 3 yg? 
      // yg? Check that symbol and exchange are trimmed and uppercased.
   }

#endif
}
