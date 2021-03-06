#pragma once

#include "./TStrategyBase.hpp"
#include "./TTradingSystemConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   //

   class TTradingSystem
   {
#if( /* {private ThreadedActivityCancellationToken_}. */ 1 )

      //
      private: ::Common::ControlFlow::TThreadedActivityCancellationToken * const ThreadedActivityCancellationToken_;

#endif
#if( /* {private Strategy_}. */ 1 )

      //
      private: ::std::unique_ptr< TStrategyBase > Strategy_;

#endif
#if( /* {private REngineAdapter_}. yg? Must be the last. */ 1 )

      // yg? This field must be the last to be destructed the first as it can raise events.
      private: ::RApiFacade::TREngineAdapter REngineAdapter_;

#endif

#if( /* //{(private)} Instance default constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TTradingSystem
         ( TTradingSystem const & source
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TTradingSystem
         ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TTradingSystem
         ( ::Common::ControlFlow::TThreadedActivityCancellationToken & threadedActivityCancellationToken1,
           TTradingSystemConfiguration && configuration1
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TTradingSystem & operator =
         ( TTradingSystem const & source
         );

#endif

#if( /* {public Initialize}. */ 1 )

      //

      public: void Initialize
         ( TTradingSystemConfiguration && configuration1
         );

#endif
#if( /* {private DoInitialize}. */ 1 )

      //

      private: void DoInitialize
         ( //TTradingSystemConfiguration && configuration1
         );

#endif
#if( /* {public Prepare}. */ 1 )

      //

      public: void Prepare();

#endif
#if( /* {public Start}. */ 1 )

      //

      public: void Start();

#endif
#if( /* {public Run}. */ 1 )

      //

      public: void Run();

#endif

#if( /* {public REngineAdapter}. */ 1 )

      //

      public: ::RApiFacade::TREngineAdapter & REngineAdapter(); //const;

#endif
   };
}
