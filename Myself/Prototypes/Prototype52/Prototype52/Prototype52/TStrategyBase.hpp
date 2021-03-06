#pragma once

#include "../RApiFacade/TREngineAdapter.hpp"
#include "./TStrategyBaseConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // yg? 
   class TTradingSystem;

   // Visible universe.
   //    {::Common::ControlFlow::TThreadedActivityCancellationToken}.
   //    {::RApiFacade::TREngineAdapter}.
   //    {TTradingSystem}.
   //    {TStrategyBaseConfiguration}.

   class TStrategyBase abstract
   {
#if( /* {protected ThreadedActivityCancellationToken_}. */ 1 )

      //
      protected: ::Common::ControlFlow::TThreadedActivityCancellationToken * const ThreadedActivityCancellationToken_;

#endif
#if( /* //{protected TradingSystem_}. */ 1 )

      //// The constructor does not initialize this field.
      //// If I ever uncomment this I might want to require the caller to assign a value to this field directly.
      //protected: TTradingSystem * TradingSystem_;

#endif
#if( /* {protected REngineAdapter_}. */ 1 )

      // The constructor does not initialize this field.
      // If we owned this object this field would probably have to be the last.
      protected: ::RApiFacade::TREngineAdapter * REngineAdapter_;

#endif

#if( /* //{(private)} Instance default constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TStrategyBase
         ( TStrategyBase const & source
         );

#endif
#if( /* {protected} Instance constructor. */ 1 )

      //

      protected: explicit TStrategyBase
         ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
         );

#endif
#if( /* {protected} Instance constructor. */ 1 )

      //

      protected: explicit TStrategyBase
         ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
           TStrategyBaseConfiguration && configuration1
         );

#endif
#if( /* {public} Instance destructor. */ 1 )

      //

      public: virtual ~TStrategyBase();

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TStrategyBase & operator =
         ( TStrategyBase const & source
         );

#endif

#if( /* {public Initialize}. */ 1 )

      //

      public: void Initialize
         ( TStrategyBaseConfiguration && configuration1
         );

#endif
#if( /* {private DoInitialize}. */ 1 )

      //

      private: void DoInitialize
         ( //TStrategyBaseConfiguration && configuration1
         );

#endif
#if( /* {public Prepare}. */ 1 )

      // Assumption: the {tradingSystem1.REngineAdapter()) is a valid reference (but the object is not required to be ready to be used).

//TODO use {override}
      public: virtual void Prepare
         ( TTradingSystem & tradingSystem1
         );

#endif
#if( /* {public Start}. */ 1 )

      //

//TODO use {override}
      public: virtual void Start();

#endif
#if( /* {public Run}. */ 1 )

      //

//TODO use {override}
      public: virtual void Run() = 0;

#endif
   };
}
