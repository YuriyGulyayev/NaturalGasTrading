#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportReceiverBase.hpp"

#include "../Common/Time/TDateTimeKeeper.cpp"
#include "./TPeerStrategyBaseModeCode.cpp"
#include "./TEconomicReportReceiverOutcomeCode.cpp"
#include "./TEconomicReportReceiverBaseConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {protected} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportReceiverBase< TResult_ >::TEconomicReportReceiverBase()
      //DateTimeKeeper_( ??? ),
      //Result( ??? )
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {protected} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportReceiverBase< TResult_ >::TEconomicReportReceiverBase
      ( TEconomicReportReceiverBaseConfiguration && configuration1
      )
      //DateTimeKeeper_( ??? ),
      //Result( ??? )
   {
      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {public} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportReceiverBase< TResult_ >::~TEconomicReportReceiverBase()
   {
      // This method is virtual and inline.
   }

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverBase< TResult_ >::Initialize
      ( TEconomicReportReceiverBaseConfiguration && configuration1
      )
   {
      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverBase< TResult_ >::DoInitialize
      ( TEconomicReportReceiverBaseConfiguration && configuration1
      )
   {
      WarmUpStepInterval1Milliseconds_ = ::std::move( configuration1.WarmUpStepInterval1Milliseconds );
      WarmUpStepInterval2Milliseconds_ = ::std::move( configuration1.WarmUpStepInterval2Milliseconds );
      WarmUpStageEndTimeOffsetMilliseconds_ = ::std::move( configuration1.WarmUpStageEndTimeOffsetMilliseconds );
      InvocationTimeOffsetMilliseconds_ = ::std::move( configuration1.InvocationTimeOffsetMilliseconds );
      EconomicReportReceptionTimeoutTimeSpanMilliseconds_ = ::std::move( configuration1.EconomicReportReceptionTimeoutTimeSpanMilliseconds );

      OutcomeCode_ = TEconomicReportReceiverOutcomeCode_OtherError;
   }

#endif
#if( /* {public Prepare}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverBase< TResult_ >::Prepare
      ( ::Common::Time::TDateTimeKeeper const & dateTimeKeeper
      )
   {
      // This method is virtual and inline.

      DateTimeKeeper_ = ( & dateTimeKeeper );
   }

#endif
#if( /* {public TryRun}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline /*bool*/ void TEconomicReportReceiverBase< TResult_ >::TryRun
      ( ::Poco::Int64 economicReportReleaseDateTimeMillisecondsSince1970,
        TPeerStrategyBaseModeCode peerStrategyBaseModeCode
      )
   {
      // Not resetting {Result}, so a value from the previous run stays unchanged.
      // An override might want to reset {Result}.

      // I want to reset this sooner, just in case other threads want to check this.
      OutcomeCode_ = TEconomicReportReceiverOutcomeCode_Undefined;

      EconomicReportReleaseDateTimeMillisecondsSince1970_ = economicReportReleaseDateTimeMillisecondsSince1970;
      PeerStrategyBaseModeCode_ = peerStrategyBaseModeCode;

      DoTryRun();

//TODO do we need this validation here?
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME
         ( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success ||
           OutcomeCode_ == TEconomicReportReceiverOutcomeCode_OtherError
         );
   }

#endif
#if( /* {protected DoTryRun}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and inline.

#endif

#if( /* {public TryMakeWarmUpStep}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline bool TEconomicReportReceiverBase< TResult_ >::TryMakeWarmUpStep()
   {
      // This method is virtual and inline.

      WarmUp();
      return true;
   }

#endif
#if( /* {protected WarmUp}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline void TEconomicReportReceiverBase< TResult_ >::WarmUp()
   {
      // This method is virtual and inline.
   }

#endif

#if( /* {public TryCreateNewsHubMessage}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline ::std::string const * TEconomicReportReceiverBase< TResult_ >::TryCreateNewsHubMessage()
   {
      // This method is virtual and inline.

      return nullptr;
   }

#endif

#if( /* {public LogActivityReportIfPossible}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.
   // This method is virtual and inline.

#endif

#if( /* {public WarmUpStepInterval1Milliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline int TEconomicReportReceiverBase< TResult_ >::WarmUpStepInterval1Milliseconds() const
   {
      return WarmUpStepInterval1Milliseconds_;
   }

#endif
#if( /* {public WarmUpStepInterval2Milliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline int TEconomicReportReceiverBase< TResult_ >::WarmUpStepInterval2Milliseconds() const
   {
      return WarmUpStepInterval2Milliseconds_;
   }

#endif
#if( /* {public WarmUpStageEndTimeOffsetMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline int TEconomicReportReceiverBase< TResult_ >::WarmUpStageEndTimeOffsetMilliseconds() const
   {
      return WarmUpStageEndTimeOffsetMilliseconds_;
   }

#endif
#if( /* {public InvocationTimeOffsetMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline int TEconomicReportReceiverBase< TResult_ >::InvocationTimeOffsetMilliseconds() const
   {
      return InvocationTimeOffsetMilliseconds_;
   }

#endif
#if( /* //{public Result}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TResult_
   //   >
   //inline TResult_ * TEconomicReportReceiverBase< TResult_ >::Result()
   //{
   //   return ( & Result_ );
   //}

#endif
#if( /* {public EconomicReportReceptionTimeStampMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline int TEconomicReportReceiverBase< TResult_ >::EconomicReportReceptionTimeStampMilliseconds() const
   {
      return EconomicReportReceptionTimeStampMilliseconds_;
   }

#endif
#if( /* {public SafeGetEconomicReportReceptionDateTimeStampOffsetMilliseconds}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline int TEconomicReportReceiverBase< TResult_ >::SafeGetEconomicReportReceptionDateTimeStampOffsetMilliseconds() const
   {
      int economicReportReceptionDateTimeStampOffsetMilliseconds;

      // It's probably unnecessary to validate {OutcomeCode_} here.
      if( OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success )

      {
         // Because the date-time keeper is assumed to return the date-time that corresponds to the beginning of a timer based millisecond
         // and we likely received the report in the middle of a timer based millisecond, we add a half of a timer based millisecond.
         ::Poco::Int64 economicReportReceptionDateTimeStampMillisecondsSince1970
            ( DateTimeKeeper_->GetDateTimeMillisecondsAsInteger< ::Poco::Int64 >
                 ( static_cast< double >( EconomicReportReceptionTimeStampMilliseconds_ ) + 0.5 )
            );

         // Assuming this will not overflow. Although the type-cast will overflow.
         economicReportReceptionDateTimeStampOffsetMilliseconds =
            static_cast< int >( economicReportReceptionDateTimeStampMillisecondsSince1970 ) -
            static_cast< int >( EconomicReportReleaseDateTimeMillisecondsSince1970_ );
      }
      else
      {
         economicReportReceptionDateTimeStampOffsetMilliseconds = ::std::numeric_limits< int >::lowest();
      }

      return economicReportReceptionDateTimeStampOffsetMilliseconds;
   }

#endif
#if( /* {public OutcomeCode}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TResult_
      >
   inline TEconomicReportReceiverOutcomeCode TEconomicReportReceiverBase< TResult_ >::OutcomeCode() const
   {
      return OutcomeCode_;
   }

#endif
}
