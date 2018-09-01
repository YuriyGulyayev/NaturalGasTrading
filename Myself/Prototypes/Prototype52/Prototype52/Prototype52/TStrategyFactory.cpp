#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TStrategyFactory.hpp"

#include "./TStrategyBase.cpp"
#include "./TStrategyFactoryConfiguration.cpp"
//#include "../Common/CodeOptimization/Macros.cpp"
#include "./TWarmUpStrategy.cpp"
#include "./TPrimaryPeerStrategy.cpp"
#include "./TSecondaryPeerStrategy.cpp"

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

   TStrategyFactory::TStrategyFactory
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
        TStrategyFactoryConfiguration && configuration1
      ) :
      Strategy( CreateStrategy( threadedActivityCancellationToken1, ::std::move( configuration1 ) ) )
   {
      configuration1.DataTypeConfiguration.reset();
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {private CreateStrategy}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TStrategyBase * TStrategyFactory::CreateStrategy
      ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
        TStrategyFactoryConfiguration && configuration1
      )
   {
      // This method is inline.
      // This method doesn't deallocate {configuration1.DataTypeConfiguration}.

      switch( configuration1.DataTypeCode )
      {
         case TStrategyTypeCode_TWarmUpStrategy :
         {
            // Not using {::std::move}.
            return new TWarmUpStrategy( threadedActivityCancellationToken1,
                                                             static_cast< TWarmUpStrategyConfiguration && >( * configuration1.DataTypeConfiguration )
                                                          );
            
            break;
         }
         
         case TStrategyTypeCode_TPrimaryPeerStrategy :
         {
            // Not using {::std::move}.
            return new TPrimaryPeerStrategy( threadedActivityCancellationToken1,
                                                                   static_cast< TPrimaryPeerStrategyConfiguration && >( * configuration1.DataTypeConfiguration )
                                                                );
            
            break;
         }
         
         case TStrategyTypeCode_TSecondaryPeerStrategy :
         {
            // Not using {::std::move}.
            return new TSecondaryPeerStrategy( threadedActivityCancellationToken1,
                                                                      static_cast< TSecondaryPeerStrategyConfiguration && >( * configuration1.DataTypeConfiguration )
                                                                    );
            
            break;
         }

         default :
         {
            YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
            break;
         }
      }
   }

#endif
}
