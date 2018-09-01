#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // See the config file for more info.

   class TEconomicReportReceiverBaseConfiguration abstract
   {
#if( /* {public WarmUpStepInterval1Milliseconds}. */ 1 )

      //
      public: int WarmUpStepInterval1Milliseconds;

#endif
#if( /* {public WarmUpStepInterval2Milliseconds}. */ 1 )

      //
      public: int WarmUpStepInterval2Milliseconds;

#endif
#if( /* {public WarmUpStageEndTimeOffsetMilliseconds}. */ 1 )

      //
      public: int WarmUpStageEndTimeOffsetMilliseconds;

#endif
#if( /* {public InvocationTimeOffsetMilliseconds}. */ 1 )

      //
      public: int InvocationTimeOffsetMilliseconds;

#endif
#if( /* {public EconomicReportReceptionTimeoutTimeSpanMilliseconds}. */ 1 )

      //
      public: int EconomicReportReceptionTimeoutTimeSpanMilliseconds;

#endif

#if( /* {protected} Instance default constructor. */ 1 )

      //

      protected: explicit TEconomicReportReceiverBaseConfiguration();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TEconomicReportReceiverBaseConfiguration
         ( TEconomicReportReceiverBaseConfiguration const & source
         );

#endif
#if( /* {public} Instance destructor. */ 1 )

      //

      public: virtual ~TEconomicReportReceiverBaseConfiguration();

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TEconomicReportReceiverBaseConfiguration & operator =
         ( TEconomicReportReceiverBaseConfiguration const & source
         );

#endif

#if( /* {public Validate}. */ 1 )

      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.
      // TODO 3 yg? If I implement this method I will need to make it {virtual}.

      public: void Validate() const;

#endif
   };
}
