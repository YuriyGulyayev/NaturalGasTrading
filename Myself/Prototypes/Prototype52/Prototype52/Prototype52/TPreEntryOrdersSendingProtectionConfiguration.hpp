#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // yg? I eliminated {TPostEntryOrdersSendingProtectionConfiguration}.
   // See the config file for more info.

   class TPreEntryOrdersSendingProtectionConfiguration
   {
#if( /* {public InstrumentBestAggregatedBidAskQuotePricesSpreadMaxLimit}. */ 1 )

      //
      public: double InstrumentBestAggregatedBidAskQuotePricesSpreadMaxLimit;

#endif
#if( /* //{public InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit}. */ 1 )

      //// TODO 3 yg? Rename this to specify exactly deviation from what to what we are talking about.
      //public: double InstrumentBestAggregatedQuotePriceCheapMovingAverageDeviationMaxLimit;

#endif
#if( /* {public InstrumentLastTradePriceDeviationMaxLimit}. */ 1 )

      // TODO 3 yg? Rename this to specify exactly deviation from what to what we are talking about.
      public: double InstrumentLastTradePriceDeviationMaxLimit;

#endif
#if( /* {public NumberInstrumentTradesCheapMovingAverageMinLimit}. */ 1 )

      //
      public: double NumberInstrumentTradesCheapMovingAverageMinLimit;

#endif
#if( /* {public NumberInstrumentTradesCheapMovingAverageMaxLimit}. */ 1 )

      //
      public: double NumberInstrumentTradesCheapMovingAverageMaxLimit;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TPreEntryOrdersSendingProtectionConfiguration();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TPreEntryOrdersSendingProtectionConfiguration
         ( TPreEntryOrdersSendingProtectionConfiguration const & source
         );

#endif
#if( /* {public} Instance move constructor. */ 1 )

      //

      public: TPreEntryOrdersSendingProtectionConfiguration
         ( TPreEntryOrdersSendingProtectionConfiguration && source
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TPreEntryOrdersSendingProtectionConfiguration & operator =
         ( TPreEntryOrdersSendingProtectionConfiguration const & source
         );

#endif
#if( /* {public operator =}. */ 1 )

      //

      public: TPreEntryOrdersSendingProtectionConfiguration & operator =
         ( TPreEntryOrdersSendingProtectionConfiguration && source
         );

#endif

#if( /* {public Assign}. */ 1 )

      // yg? Should this be named {Move}?

      public: void Assign
         ( TPreEntryOrdersSendingProtectionConfiguration && source
         );

#endif

#if( /* {public Validate}. */ 1 )

      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.

      public: void Validate() const;

#endif
   };
}
