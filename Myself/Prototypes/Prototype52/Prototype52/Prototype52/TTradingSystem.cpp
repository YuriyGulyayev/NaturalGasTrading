#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TTradingSystem.hpp"

#include "./TStrategyBase.cpp"
#include "./TTradingSystemConfiguration.cpp"
#include "./TStrategyFactory.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TTradingSystem::TTradingSystem
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
      ) :
      ThreadedActivityCancellationToken_( & threadedActivityCancellationToken1 ),
      REngineAdapter_( threadedActivityCancellationToken1 )
   {
   }

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TTradingSystem::TTradingSystem
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
        TTradingSystemConfiguration && configuration1
      ) :
      ThreadedActivityCancellationToken_( & threadedActivityCancellationToken1 ),
      Strategy_
         ( ::std::move
              ( TStrategyFactory( threadedActivityCancellationToken1, ::std::move( configuration1.StrategyFactoryConfiguration ) ).Strategy )
         ),
      REngineAdapter_( threadedActivityCancellationToken1, ::std::move( configuration1.REngineAdapterConfiguration ) )
   {
      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Initialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTradingSystem::Initialize
      ( TTradingSystemConfiguration && configuration1
      )
   {
      Strategy_ =
         ::std::move
            ( TStrategyFactory( ( * ThreadedActivityCancellationToken_ ), ::std::move( configuration1.StrategyFactoryConfiguration ) ).Strategy );

      // No need to lock.
      REngineAdapter_.Initialize( ::std::move( configuration1.REngineAdapterConfiguration ) );
      
      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TTradingSystem::DoInitialize
      ( //TTradingSystemConfiguration && configuration1
      )
   {
   }

#endif
#if( /* {public Prepare}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTradingSystem::Prepare()
   {
      // No need to lock.
      REngineAdapter_.Prepare();

      Strategy_->Prepare( * this );
   }

#endif
#if( /* {public Start}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTradingSystem::Start()
   {
      // No need to lock.
      REngineAdapter_.Start();
      
      Strategy_->Start();
   }

#endif
#if( /* {public Run}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TTradingSystem::Run()
   {
      Strategy_->Run();
   }

#endif

#if( /* {public REngineAdapter}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::RApiFacade::TREngineAdapter & TTradingSystem::REngineAdapter() //const
   {
      return REngineAdapter_;
   }

#endif
}
