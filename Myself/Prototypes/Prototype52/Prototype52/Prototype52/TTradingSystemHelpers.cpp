#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TTradingSystemHelpers.hpp"

#include "./TTradingSystemConfiguration.cpp"
#include "./TTradingSystem.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
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

#if( /* {public CreateAndRunTradingSystem}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TTradingSystemHelpers::CreateAndRunTradingSystem
      ( ::std::unique_ptr< TTradingSystemConfiguration > && configuration1
      )
   {
      ::Common::ControlFlow::TThreadedActivityCancellationToken threadedActivityCancellationToken1;

      try
      {
         // This ensures that on an exception trading system destructor will not be called before we die.
         //TTradingSystem * tradingSystem1
         //   ( new TTradingSystem( threadedActivityCancellationToken1, ::std::move( * configuration1 ) ) );
         char tradingSystem1Place[ sizeof( TTradingSystem ) ];
         new( reinterpret_cast< void * >( tradingSystem1Place ) ) TTradingSystem
            ( threadedActivityCancellationToken1, ::std::move( * configuration1 ) );

         configuration1.reset();
         reinterpret_cast< TTradingSystem * >( tradingSystem1Place )->Prepare();
         reinterpret_cast< TTradingSystem * >( tradingSystem1Place )->Start();
         reinterpret_cast< TTradingSystem * >( tradingSystem1Place )->Run();

         // A typical strategy should wait until all its activities complete.
//TODO see prev line
//TODO Make sure the strategy never signals this.
         threadedActivityCancellationToken1.NonVolatileSignalOnceAndWaitUntilReleased( 1 );

         // At this point it might be a good idea to sleep a bit just in case a buggy 3rd party API is going to call us on another thread.

         //delete tradingSystem1;
         reinterpret_cast< TTradingSystem * >( tradingSystem1Place )->~TTradingSystem();
      }
      //catch( ::Common::ControlFlow::TOperationCancelledException const & exception1 )
      catch( ::OmneException const & exception1 )
      {
         ::RApiFacade::TRApiHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::Poco::Exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ::std::exception const & exception1 )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException( exception1 );
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
      catch( ... )
      {
         ::Common::ErrorHandling::TErrorHandlingHelpers::AtomicLastChanceHandleException();
         YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      }
   }

#endif
#if( /* {public CreateAndRunTradingSystems}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TTradingSystemsConfigurationUniquePtrIterator_
      >
   inline void TTradingSystemHelpers::CreateAndRunTradingSystems
      ( TTradingSystemsConfigurationUniquePtrIterator_ tradingSystemsConfigurationUniquePtrBeginIterator,
        TTradingSystemsConfigurationUniquePtrIterator_ tradingSystemsConfigurationUniquePtrEndIterator
      )
   {
      // It's OK if the collection is empty but it would make little sense.
      while( tradingSystemsConfigurationUniquePtrBeginIterator != tradingSystemsConfigurationUniquePtrEndIterator )
      {
         CreateAndRunTradingSystem( ::std::move( * tradingSystemsConfigurationUniquePtrBeginIterator ) );
         ++ tradingSystemsConfigurationUniquePtrBeginIterator;
      }
   }

#endif
}
