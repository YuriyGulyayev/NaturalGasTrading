#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TWarmUpStrategy.hpp"

#include "./TStrategyBase.cpp"
#include "./TWarmUpStrategyConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TWarmUpStrategy::TWarmUpStrategy
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
      ) :
      TStrategyBase( threadedActivityCancellationToken1 )
   {
      // See visible universe in {DoInitialize}.

//TODO maybe I'll need to make this not inline
   }

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TWarmUpStrategy::TWarmUpStrategy
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
        TWarmUpStrategyConfiguration && configuration1
      ) :
      TStrategyBase( threadedActivityCancellationToken1, ::std::move( configuration1 ) )
   {
      // See visible universe in {DoInitialize}.

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

      // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

      // Placeholder.

#endif

#if( /* {public Initialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TWarmUpStrategy::Initialize
      ( TWarmUpStrategyConfiguration && configuration1
      )
   {
      // See visible universe in {DoInitialize}.

      TStrategyBase::Initialize( ::std::move( configuration1 ) );

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TWarmUpStrategy::DoInitialize
      ( TWarmUpStrategyConfiguration && //configuration1
      )
   {
      // Consrtructors, destructors, {Initialize}, {DoInitialize} visible universe.
      //    Instance constructors -- base.
      //       Hide, possibly implicitly. Call, possibly implicitly.
      //    Instance destructor -- base.
      //       Override, possibly implicitly. Call, possibly implicitly.
      //    {Initialize} -- base.
      //       Hide, call.
      //    {DoInitialize}.
      //       Call.
   }

#endif
#if( /* {public Run}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TWarmUpStrategy::Run()
   {
      // Visible universe.
      //    {Run} -- base.
      //       Implement.
//TODO add more

      //TStrategyBase::Run();

//TODO write code
   }

#endif
}
