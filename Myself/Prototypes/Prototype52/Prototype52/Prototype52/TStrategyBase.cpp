#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TStrategyBase.hpp"

#include "../RApiFacade/TREngineAdapter.cpp"
#include "./TStrategyBaseConfiguration.cpp"
#include "./TTradingSystem.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {protected} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TStrategyBase::TStrategyBase
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
      ) :
      ThreadedActivityCancellationToken_( & threadedActivityCancellationToken1 )
      ////TradingSystem_( ??? ),
      //REngineAdapter_( ??? ),
   {
      // See visible universe in {DoInitialize}.
   }

#endif
#if( /* {protected} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TStrategyBase::TStrategyBase
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
        TStrategyBaseConfiguration && //configuration1
      ) :
      ThreadedActivityCancellationToken_( & threadedActivityCancellationToken1 )
      ////TradingSystem_( ??? ),
      //REngineAdapter_( ??? ),
   {
      // See visible universe in {DoInitialize}.

      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {public} Instance destructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TStrategyBase::~TStrategyBase()
   {
      // This method is virtual and therefore it should not be inline.
      // See visible universe in {DoInitialize}.
   }

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategyBase::Initialize
      ( TStrategyBaseConfiguration && //configuration1
      )
   {
      // See visible universe in {DoInitialize}.

      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TStrategyBase::DoInitialize
      ( //TStrategyBaseConfiguration && configuration1
      )
   {
      // Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
      //    {ThreadedActivityCancellationToken_}.
      //       Update.
      //    {DoInitialize}.
      //       Call.
   }

#endif
#if( /* {public Prepare}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategyBase::Prepare
      ( TTradingSystem & tradingSystem1
      )
   {
      // Visible universe.
      //    {REngineAdapter_}.
      //       Update.
      //    {tradingSystem1->REngineAdapter()}.
      //       Use.

      //TradingSystem_ = ( & tradingSystem1 );
      REngineAdapter_ = ( & tradingSystem1.REngineAdapter() );
   }

#endif
#if( /* {public Start}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TStrategyBase::Start()
   {
      // Visible universe.
      //    (None.)
   }

#endif
#if( /* {public Run}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
}
