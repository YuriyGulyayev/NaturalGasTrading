#pragma once

#include "../Finance/Trading/TOrderModificationRequestBase.hpp"
#include "./TOrderModificationRequestStateCode.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   // yg?
//TODO I can't avoid this, right?
   class TSingleInstrumentOrder;

   // It's undefined what {Order()} state items can be updated when its modification request state gets updated.
   // When the {OnReceivedData} event is raised the {Order().OnReceivedData} is not, so listeners shall examine {Order()} as well.

   class TSingleInstrumentOrderModificationRequest sealed :
      public ::Finance::Trading::TOrderModificationRequestBase< TSingleInstrumentOrderModificationRequest, TSingleInstrumentOrder >
   {
   // Request parameters.
#if( /* {public TriggerPrice}. */ 1 )

      // yg? See {TSingleInstrumentOrder::TriggerPrice} comment.
      public: double TriggerPrice;

#endif
#if( /* {public LimitPrice}. */ 1 )

      // yg? See {TriggerPrice} comment.
      public: double LimitPrice;

#endif
#if( /* {public Id}. */ 1 )

      // The caller shall assign a value to this field before calling {PrepareSend}.
      public: char Id[ 2U ];

#endif

   // Request execution state.
#if( /* {public StateCode}. */ 1 )

      //
      public: TOrderModificationRequestStateCode StateCode;

#endif

   // Other fields.
#if( /* {private ModifyOrderParams_}. */ 1 )

      //
      private: ::RApi::ModifyOrderParams ModifyOrderParams_;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TSingleInstrumentOrderModificationRequest();

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // This probably doesn't need to be {virtual}.
//TODO this comment came from order, remove it?
      // yg? If we derive a custom class from this one we would need a virtual destructor. But currently this class is {sealed},
      // yg? as should be any class that raises events and passes itself as an event sender.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif

#if( /* {public Prepare}. */ 1 )

      // This probably doesn't need to be {virtual}.
      // yg? See base method comment.
      
      public: void Prepare
         ( TSingleInstrumentOrder & order1
         );

#endif

#if( /* {public PrepareSend}. */ 1 )

      //

      public: void PrepareSend();

#endif

#if( /* {public ModifyOrderParams}. */ 1 )

      //

      public: ::RApi::ModifyOrderParams const & ModifyOrderParams() const;

#endif
   };
}
