#pragma once

#include "../Common/Time/TDateTimeKeeper.hpp"
#include "./TPeerStrategyBaseModeCode.hpp"
#include "./TEconomicReportReceiverOutcomeCode.hpp"
#include "./TEconomicReportReceiverBaseConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // yg? Consider moving this and related classes to a more common namespace. But it uses some data types from its current namespace.
   // yg? NewsHub uses the word "economic indicator" instead of "economic report", so consider using it too.

   // Visible universe.
   //    {::Common::Time::TDateTimeKeeper}.
   //    {TPeerStrategyBaseModeCode}.
   //    {TEconomicReportReceiverBaseConfiguration}.
   //    {TEconomicReportReceiverOutcomeCode}.

   template
      < typename TResult_
      >
   class TEconomicReportReceiverBase abstract
   {
#if( /* {private WarmUpStepInterval1Milliseconds_}. */ 1 )

      // The strategy reads {WarmUpStepInterval1Milliseconds_} or {WarmUpStepInterval2Milliseconds_} on each loop,
      // which implies that an implementation is free to change these values as warming up progresses.
      // yg? But currently these fields are private.
      private: int WarmUpStepInterval1Milliseconds_;

#endif
#if( /* {private WarmUpStepInterval2Milliseconds_}. */ 1 )

      // yg? See {WarmUpStepInterval1Milliseconds_} comment.
      private: int WarmUpStepInterval2Milliseconds_;

#endif
#if( /* {private WarmUpStageEndTimeOffsetMilliseconds_}. */ 1 )

      // yg? Consider making this relative to {InvocationTimeOffsetMilliseconds_}. This might be a bad idea as
      // yg? absolute time when to stop sending HTTP requests is more important.
      private: int WarmUpStageEndTimeOffsetMilliseconds_;

#endif
#if( /* {private InvocationTimeOffsetMilliseconds_}. */ 1 )

      //
      private: int InvocationTimeOffsetMilliseconds_;

#endif
#if( /* {protected EconomicReportReceptionTimeoutTimeSpanMilliseconds_}. */ 1 )

      // This field doesn't have an accessor method. If I add one I might want to make this field {private}.
      protected: int EconomicReportReceptionTimeoutTimeSpanMilliseconds_;

#endif

#if( /* {protected DateTimeKeeper_}. */ 1 )

      // The constructor does not initialize this field.
      protected: ::Common::Time::TDateTimeKeeper const * DateTimeKeeper_;

#endif
#if( /* {protected EconomicReportReleaseDateTimeMillisecondsSince1970_}. */ 1 )

      // yg? Consider using the word "scheduled".
      protected: ::Poco::Int64 EconomicReportReleaseDateTimeMillisecondsSince1970_;

#endif
#if( /* {protected PeerStrategyBaseModeCode_}. */ 1 )

      // TODO 3 yg? Can I replace this with a boolean? Does it matter that we now have 2 strategies.
      protected: TPeerStrategyBaseModeCode PeerStrategyBaseModeCode_;

#endif

#if( /* {public Result}. */ 1 )

      // Info extracted from the report.
      // This value is guaranteed to be valid only when {OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success}.
      // This field is declared {public}. Another option would be to add an accessor method to return a {const} reference/pointer to it
      // but that can potentially create problems in case {TResult_} is a non-POD type.
      // yg? Consider using the word "economic report info" instead of "result". The strategy uses the word "economic report value"
      // yg? because it's a scalar. NewsHub uses the word "economic indicator actual value". But this result can be calculated based on
      // yg? arbitrary logic that can incorporate multiple economic indicators. But it might still be OK for us to use the word
      // yg? "economic indicator".
      public: TResult_ Result;

#endif
#if( /* {protected EconomicReportReceptionTimeStampMilliseconds_}. */ 1 )

      // This value should but is not required to be valid when {OutcomeCode_ == TEconomicReportReceiverOutcomeCode_Success}.
      // Depending on the implementation, this value can be valid even when
      // {OutcomeCode_ != TEconomicReportReceiverOutcomeCode_Success}. This can happen for example when malformed data arrives.
      // Although most implementations assign to this field only after report data was successfully parsed.
      protected: int EconomicReportReceptionTimeStampMilliseconds_;

#endif
#if( /* {protected OutcomeCode_}. */ 1 )

      // This field is initialized with {TEconomicReportReceiverOutcomeCode_OtherError}.
      protected: TEconomicReportReceiverOutcomeCode OutcomeCode_;

#endif

#if( /* {protected} Instance default constructor. */ 1 )

      //

      protected: explicit TEconomicReportReceiverBase();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TEconomicReportReceiverBase
         ( TEconomicReportReceiverBase const & source
         );

#endif
#if( /* {protected} Instance constructor. */ 1 )

      //

      protected: explicit TEconomicReportReceiverBase
         ( TEconomicReportReceiverBaseConfiguration && configuration1
         );

#endif
#if( /* {public} Instance destructor. */ 1 )

      //

      public: virtual ~TEconomicReportReceiverBase();

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TEconomicReportReceiverBase & operator =
         ( TEconomicReportReceiverBase const & source
         );

#endif

#if( /* {public Initialize}. */ 1 )

      //

      public: void Initialize
         ( TEconomicReportReceiverBaseConfiguration && configuration1
         );

#endif
#if( /* {private DoInitialize}. */ 1 )

      //

      private: void DoInitialize
         ( TEconomicReportReceiverBaseConfiguration && configuration1
         );

#endif
#if( /* {public Prepare}. */ 1 )

      // When this method is called, {dateTimeKeeper} is not required to be ready.
      // yg? It's probably possible to eliminate this method parameter and require the caller to assign a value to a respective field
      // yg? but that would probably not result in a significant benefit.

      public: virtual void Prepare
         ( ::Common::Time::TDateTimeKeeper const & dateTimeKeeper
         );

#endif
#if( /* {public TryRun}. */ 1 )

      // This method shall be called at {economicReportReleaseDateTimeMillisecondsSince1970 + InvocationTimeOffsetMilliseconds()}.
      // This method may be called multiple times but the {LogActivityReportIfPossible} method shall be called
      // before calling {TryRun} again.
      // yg? Consider eliminating this method parameters and requiring the caller to assign values to respective fields.
      // yg? Actually then {TryMakeWarmUpStep} would have to temporarily change and then restore the values and that would be ugly.

      public: /*bool*/ void TryRun
         ( ::Poco::Int64 economicReportReleaseDateTimeMillisecondsSince1970,
           TPeerStrategyBaseModeCode peerStrategyBaseModeCode
         );

#endif
#if( /* {protected DoTryRun}. */ 1 )

      // yg? Consider renaming this method to {TryRun}. This is probably a bad idea but the existing name is ugly.

      protected: virtual /*bool*/ void DoTryRun() = 0;

#endif

#if( /* {public TryMakeWarmUpStep}. */ 1 )

      // This method makes a warm-up step among possibly a series of such steps.
      // Returns {true} when it doesn't need to be called any more.
      // yg? Incorrectness: the return value of this "try" method indicates not whether the operation succeeded. One way to fix this
      // yg? incorrectness is to eliminate the word "try" but in any case this method should rarely throw exceptions.
      // This method may be called 0 or more times and at any time.
      // yg? But some implementations might require that this method was called at least once before {TryRun}.
      // yg? An alternative solution would be to add another virtual method to get notified that there will be no warm-up steps any more.
      // yg? See related comments in {TEconomicReportReceiverViaTcpBase< TResult_ >::CompleteWarmUpStep} (which I eliminated).
      // It's safe to call this method even after a past call returned {true}.
      // In that case it's recommended that the method returns {true} after another round of warming up has completed.
      // If {TryMakeWarmUpStep} calls {TryRun} it will have to ensure that {TryRun} is safe to call afterwards,
      // possibly by calling {LogActivityReportIfPossible}.
      // It must generate a {TPeerStrategyBaseModeCode} to be passed to {TryRun}.
      // {TPeerStrategyBaseModeCode_Test} might be a better option.
      // This method may use {DateTimeKeeper_} and therefore the caller must not update the later on another thread.
      // The base implementation calls {WarmUp} and returns {true}.

      public: virtual bool TryMakeWarmUpStep();

#endif
#if( /* {protected WarmUp}. */ 1 )

      // This method is intended to execute some quick warm-up code that should normally not involve waiting.
      // It should have no/few side effects.
      // To prevent over-optimization, it might have to change {::Common::WarmUp::TWarmUpHelpers::WarmUpState}.
      // An implementation might call any library/DLL functions/methods that take longer to execute when called for the 1st time.
      // The base implementation does nothing.

      protected: virtual void WarmUp();

#endif

#if( /* {public TryCreateNewsHubMessage}. */ 1 )

      // Creates/formats a message to be sent to NewsHub.
      // Returns a pointer to the message string.
      // On error returns {nullptr}.
      // The caller doesn't need to deallocate the memory a pointer to which is returned.
      // This method may be called 0 or 1 time after a successful {TryRun} call and before a {LogActivityReportIfPossible} call.
      // On error this method should log an error message; the caller doesn't need to log anything.
      // The base implementation does nothing and simply returns {nullptr}.
      // If this economic report is to be received from NewsHub it makes no sense to override this method.
      // yg? This method probably doesn't change any externally visible state, so it might be appropriate to declare it {const}
      // yg? and any member fields it modifies {mutable}, but I don't like this idea.

      public: virtual ::std::string const * TryCreateNewsHubMessage();

#endif

#if( /* {public LogActivityReportIfPossible}. */ 1 )

      // This method resets some internal state.
      // This method shall be called before calling {TryRun} again.
      // This method should do nothing when called redundantly.
      // yg? This method probably doesn't change any externally visible state, so it might be appropriate to declare it {const}
      // yg? and any member fields it modifies {mutable}, but I don't like this idea.
      // yg? Consider renaming this method to something like {CompleteRunIfNeeded}. Or add a method like that
      // yg? and have it to call this one.

      public: virtual void LogActivityReportIfPossible() = 0;

#endif

#if( /* {public WarmUpStepInterval1Milliseconds}. */ 1 )

      //
      
      public: int WarmUpStepInterval1Milliseconds() const;

#endif
#if( /* {public WarmUpStepInterval2Milliseconds}. */ 1 )

      //
      
      public: int WarmUpStepInterval2Milliseconds() const;

#endif
#if( /* {public WarmUpStageEndTimeOffsetMilliseconds}. */ 1 )

      //
      
      public: int WarmUpStageEndTimeOffsetMilliseconds() const;

#endif
#if( /* {public InvocationTimeOffsetMilliseconds}. */ 1 )

      //
      
      public: int InvocationTimeOffsetMilliseconds() const;

#endif
#if( /* //{public Result}. */ 1 )

      // I commented this method out, made the {Result_} field {public}, and removed "_" from the end of the field's name.

      //// This method is not {const} and returns a non-{const} pointer to a member field.
      //// I can add a {const} overload if needed.
      //
      //public: TResult_ * Result();

#endif
#if( /* {public EconomicReportReceptionTimeStampMilliseconds}. */ 1 )

      // The caller might not need this info but I want to keep it exposed.
      
      public: int EconomicReportReceptionTimeStampMilliseconds() const;

#endif
#if( /* {public SafeGetEconomicReportReceptionDateTimeStampOffsetMilliseconds}. */ 1 )

      // The result is calculated precisely and is rounded to an integer.
      // The result can differ from multimedia timer based milliseconds.
      // The caller might not need this info but I want to keep it exposed.
      // yg? Consider renaming this method to make it clear what is safe. Maybe use the word "if possible".
      // yg? Should we use the word "try"? Maybe not because it always returns some result rather than a {bool}.

      public: int SafeGetEconomicReportReceptionDateTimeStampOffsetMilliseconds() const;

#endif
#if( /* {public OutcomeCode}. */ 1 )

      //
      
      public: TEconomicReportReceiverOutcomeCode OutcomeCode() const;

#endif
   };
}
