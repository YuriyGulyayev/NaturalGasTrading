#pragma once

//TODO include TSingleInstrumentOrderModificationRequest.hpp and in the CPP file include the CPP ?
//TODO move any includes to TSingleInstrumentOrderModificationRequest?

#include "../Finance/Math/TQuantityAndPrice.hpp"
#include "../Finance/Trading/TPositionDirectionCode.hpp"
#include "../Finance/Trading/TSingleInstrumentOrderBase.hpp"
#include "./TInstrument.hpp"
#include "./TOrderTypeCode.hpp"
#include "./TOrderTimeInForceCode.hpp"
#include "./TOrderStateBitMask.hpp"
//TODO should we include this a few lines above?
#include "./TSingleInstrumentOrderModificationRequest.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   // Call {TREngineAdapter::CreateSingleInstrumentOrder} to create an instance of this class.
   // yg? This is currently not enforced by the compiler.
   //
   // I use the notion of the "new order request" that sends an order to the brokerage for the 1st time.
   // Depending on the order parameters, the brokerage can either immediately forward it to the exchange or hold it,
   // either until a release request or a trigger condition.
   // yg? The functionality and wordings don't clearly separate new order, modification, and cancellation requests
   // yg? and whether those are sent to the brokerage only or also to the exchange.
   // yg? We are not well designed to handle multiple pending new order, modification, and/or cancellation requests.
   // yg? Actually I made some limited improvements lately.
   // TODO 3 yg? We need a collection of modification and cancellation requests in this class,
   // TODO 3 yg? either a single one for both request types or separate.
   //
   // yg? Consider implementing the {::Poco::RefCountedObject} methods that would remove the order from {REngineAdapter}.
   // yg? The order would be required to be non-working, or better never filled, or even never sent
   // yg? to ensure that any execution restatements would be handled.
   // yg? But on the other hand I might want to "forget" an even still working order.

//TODO Support limit-if-touched and/or some others.
//TODO Maybe we don't need market-if-touched.
//TODO support DAY and IOC time-in-force
//TODO Add enum TTimeInForceCode, borrow codes from FIX, similar to TOrderTypeCode
//TODO Try to set any flags such as {bQty} in {Prepare}.
//TODO See test in "E:\MyFiles\Projects\Forteco\NaturalGasTrading\RApi.cpp\6.4.0.0\__samples\SampleOrder2.cpp".
//TODO I already verified all code outside of this class, so it will work with any order types -- reflect this in a comment.
//TODO Parts of this code might be crap, especially the population of new and modify order params -- retouch.

//TODO It appears to be impossible to modify a LIT order without modifying its limit price. But re-test this.
//TODO Otherwise the strategy would just clear the {ModifyOrderParams::bPrice} flag.

//TODO Write somewhere a comment that when we request to cancel "any" orders one might want to maintain a number
//TODO of pending "any" order cancellation request receptions. This will probably get even uglier if we cancel "any" orders once or more
//TODO cancel a specific order, and then again cancel "any" orders once or more. So keeping it simlpe.

   class TSingleInstrumentOrder sealed :
      public ::Finance::Trading::TSingleInstrumentOrderBase< TSingleInstrumentOrder, TInstrument >
   {
   // New order request parameters.
#if( /* {public TypeCode}. */ 1 )

      //
      public: TOrderTypeCode TypeCode;

#endif
#if( /* {public DirectionCode}. */ 1 )

      // yg? "Sell-short" or "buy-to-cover" are not supported.
      public: ::Finance::Trading::TPositionDirectionCode DirectionCode;

#endif
#if( /* {public Quantity}. */ 1 )

      // The caller shall round this to the instrument's minimum quantity increment.
      // yg? Should this be an {int} or a template's type parameter?
      public: double Quantity;

#endif
#if( /* {public TriggerPrice}. */ 1 )

      // The caller is not generally required to round this but some brokerage APIs require order prices to be rounded,
      // and even otherwise midpoint rounding logic can be undefined.
      // TODO 3 yg? I have a related code pattern in UniversalFX.
      // yg? Gene Sato said that R|API rounded order prices to decimal places rather than price increments.
      public: double TriggerPrice;

#endif
#if( /* {public LimitPrice}. */ 1 )

      // yg? See {TriggerPrice} comment.
//TODO I recently uncommented this. Refactor related code.
      public: double LimitPrice;

#endif
#if( /* {public TimeInForceCode}. */ 1 )

      //
//TODO New field. Refactor related code.
//TODO Does it make sense to reorder this field? Maybe before or after {DirectionCode}.
      public: TOrderTimeInForceCode TimeInForceCode;

#endif
#if( /* //{public GoodForTimeSpanMilliseconds}. */ 1 )

      ////
      //public: int GoodForTimeSpanMilliseconds;

#endif
#if( /* //{public EntryExitCode}. */ 1 )

      //// yg? Rename this to something like "position effect", maybe "position disposition": open, close; or entry, exit.
      //public TOrderEntryExitCode EntryExitCode;

#endif
#if( /* {public NewOrderRequestId}. */ 1 )

      // The caller shall assign a value to the element at 0U before calling {PrepareSend}.
      // The caller shall not touch the other items.
//TODO write comments and refactor code
      public: char NewOrderRequestId[ 3U ];

#endif

   // Cancellation request parameters.
#if( /* {public CancellationRequestId}. */ 1 )

      // The caller shall assign a value to this field before calling ......??????
//TODO write comments and refactor code
//TODO init the item at 0U with 0x7 (see a factor below), which is probably the same as it is now
//TODO add a method to increment item at 0U
//TODO the caller shall assign a char which code is less that 0x80 to item at 0U or it call a method to increment it before calling ....
//TODO the caller is fully responsible for the item at 1U
//TODO item at 0U can be generated from '0' to '7' when re-requesting to cancel
      public: char CancellationRequestId[ 2U ];

#endif

   // Order execution state.
   // yg? Most/all fields are {public} but consider introducing some privacy to prevent the caller from accidentially modifying them.
   // yg? Consider moving these to a separate order execution state subscription class, similar to market data subscriptions. Bad idea?
//TODO the above applies to mod req too?
#if( /* {public StateBitMask}. */ 1 )

      //
      public: TOrderStateBitMask StateBitMask;

#endif
#if( /* {public BrokerGeneratedId}. */ 1 )

      // yg? It's impossible to cancel an order until its order number arrives.
      public: int BrokerGeneratedId;

#endif
//TODO remove?
#if( /* //{public NumberPendingCancellationRequests}. */ 1 )

      //// This value is incremented when the brokerage confirms that it received a cancellation request,
      //// regardless of which peer (or whoever) sent it, and decremented when the request completes.
      //// But we don't allow it to become negative, just in case.
      //// yg? Consider to rename this to {NumberWorkingCancellationRequests} or {NumberCancellationPendingRequests}.
      //// See also: {TOrderStateBitMask_CancellationRequestPending}.
      //public: int NumberPendingCancellationRequests;

#endif
#if( /* {public FilledQuantityAndPrice}. */ 1 )

      //
//TODO 1 yg? NumberBytesReceived vs FilledQuantityAndPrice. Rename one or another. Search for
//TODO 1 yg? NumberBytes~((Received>)|(Sent>)|(ToSend>)|(ToReceive>)|(Available>))
//TODO 1 yg? ~( |(<last))NumberBytes
      public: ::Finance::Math::TQuantityAndPrice FilledQuantityAndPrice;

#endif

//TODO New fields. Add regions and comments. Are they related to "Order execution state"?
//TODO comment that see also: TOrderStateBitMask_UnexpectedCancellationRequestPending
      public: char const * UnexpectedCancellationRequestId;
      public: int UnexpectedCancellationRequestIdLength;

   // Other fields.
//TODO remove
//#if( /* {private NewOrderRequestIdFactor1_}. */ 1 )
//
//      //
//      private: static unsigned int const NewOrderRequestIdFactor1_ = 0x67U;
//
//#endif
//TODO remove
//#if( /* {private NewOrderRequestId_}. */ 1 )
//
//      // Because we send only 1 new order request, this always equals {NewOrderRequestIdFactor1_}.
//      // This field is {static}.
//      private: static char const NewOrderRequestId_;
//
//#endif
#if( /* {private OrderParams_}. */ 1 )

      //
      private: ::RApi::OrderParams OrderParams_;

#endif
//TODO remove all/some commented out
//#if( /* {private ModificationRequestIdFactor1_}. */ 1 )
//
//      //
//      private: static unsigned int const ModificationRequestIdFactor1_ = 0x68U;
//
//#endif
//#if( /* {private ModificationRequestIdFactor2_}. */ 1 )
//
//      //
//      private: static unsigned int const ModificationRequestIdFactor2_ = 0x7U;
//
//#endif
//#if( /* {private LastModificationRequestId_}. */ 1 )
//
//      // yg? This can "overflow".
//      private: char LastModificationRequestId_;
//
//#endif
//#if( /* {private ModifyOrderParams_}. */ 1 )
//
//      //
//      private: ::RApi::ModifyOrderParams ModifyOrderParams_;
//
//#endif
#if( /* {private CancellationRequestIdFactor1_}. */ 1 )

      //
//TODO remove
      //private: static unsigned int const CancellationRequestIdFactor1_ = 0x70U;
      private: static unsigned int const CancellationRequestIdFactor1_ = 0x30U;

//TODO static_assert that this equals '0'; remember to correctly type-cast it

#endif
#if( /* {private CancellationRequestIdFactor2_}. */ 1 )

      //
      private: static unsigned int const CancellationRequestIdFactor2_ = 0x7U;

#endif
#if( /* {private CancellationRequestIdFactor3_}. */ 1 )

      //
      private: static unsigned int const CancellationRequestIdFactor3_ = 0x80U;

#endif
//#if( /* {private CancellationRequestIdFactor4_}. */ 1 )
//
//      //
//      private: static unsigned int const CancellationRequestIdFactor4_ = 0x10U;
//
//#endif
//#if( /* {private LastCancellationRequestId_}. */ 1 )
//
//      // yg? This can "overflow".
//      private: char LastCancellationRequestId_;
//
//#endif

//TODO add mod requests and their pool

#if( /* {public OnReceivedUnexpectedModificationRequest}. */ 1 )

      // yg? Some comments near {::Common::ObjectModel::TDataSubscriptionBase<>::OnReceivedData} might make sense here as well.
//TODO not passing sender, is it OK? at least write a comment
//TODO add a method to raise this event
      public: ::Poco::BasicEvent< TSingleInstrumentOrderModificationRequest *, ::Poco::NullMutex >
         OnReceivedUnexpectedModificationRequest;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TSingleInstrumentOrder();

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // This probably doesn't need to be {virtual}.
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
         ( TInstrument const & instrument1
         );

#endif

#if( /* {public PrepareSend}. */ 1 )

      // Prepares to send a new order request.
      // yg? Consider renaming this. See a renaming related comment near {TREngineAdapter::SendOrder}.

      public: void PrepareSend();

#endif
//#if( /* {public PrepareRequestModify}. */ 1 )
//
//      //
//
//      public: void PrepareRequestModify();
//
//#endif
#if( /* {public PrepareRequestCancel}. */ 1 )

      // This method is called before requesting to cancel an individual order, not "any" orders.

      public: void PrepareRequestCancel();

#endif
#if( /* {public RegisterRequestCancelAsAny}. */ 1 )

      // This method is called after a request to cancl "any" orders was sent,
      // only if {TSingleInstrumentOrderHelpers::CanCancelOrderAsAny} returns {true}.
      // Therefore using the word "register" rather than "prepare".
      // yg? We can have multiple pending "any" order cancellation requests (possibly intermixed with requests of other types).
      // yg? They all will have an empty {sUserMsg}.
      // yg? We will process a failure/success of the 1st such request as if it was related to the last one.
      // yg? Improvement of this logic might involve one or more the the following:
      // yg?     1. Maintain a counter of pending "any" order cancellation requests.
      // yg?     2. Handle a {::RApi::sLINE_STATUS_CANCEL_RECEIVED} {::RApi::LineInfo}s with an empty {sUserMsg}.
      // yg?         It would be more reliable to increment the counter then.
      // yg? But this logic would probably be unreliable.
      // yg? Actually we now have {TOrderStateBitMask_CancellationRequestPending}, which alleviated this problem a little.
      // yg? See the commented out {NumberPendingCancellationRequests} field.
//TODO revisit the above comment. we no longer check usermsg on cancel request completion

//TODO revisit, maybe we still need this
      public: void RegisterRequestCancelAsAny();

#endif

#if( /* {public RefillModificationRequestPoolIfNeeded}. */ 1 )

      //

//TODO implement
      public: void RefillModificationRequestPoolIfNeeded
         ( int numberPooledItemsMinLimit
         );

#endif
#if( /* {public GetPooledOrCreateModificationRequest}. */ 1 )

      //

//TODO implement
//TODO log a "pool miss" error but comment that it's wrong to do this at a performance critical moment
      public: TSingleInstrumentOrderModificationRequest & GetPooledOrCreateModificationRequest();

#endif
#if( /* {public CreateModificationRequest}. */ 1 )

      //

//TODO implement
      public: TSingleInstrumentOrderModificationRequest CreateModificationRequest();

#endif

//TODO add a method to find a mod req given a user msg. always fail if user msg len != 2
//TODO and I really need a method to find or create a mod req; it will need a bool param to be set to true if created, so a different event would be raised

#if( /* {public OrderParams}. */ 1 )

      //

      public: ::RApi::OrderParams const & OrderParams() const;

#endif
//#if( /* {private IncrementLastModificationRequestId}. */ 1 )
//
//      //
//
//      private: void IncrementLastModificationRequestId();
//
//#endif
//#if( /* {public LastModificationRequestId}. */ 1 )
//
//      //
//
//      public: char const & LastModificationRequestId() const;
//
//#endif
//#if( /* {public ModifyOrderParams}. */ 1 )
//
//      //
//
//      public: ::RApi::ModifyOrderParams const & ModifyOrderParams() const;
//
//#endif
//TODO do we need this method? at least remove the word "last".
//#if( /* {private IncrementLastCancellationRequestId}. */ 1 )
//
//      //
//
//      private: void IncrementLastCancellationRequestId();
//
//#endif
//TODO do we need this method? at least remove the word "last".
//#if( /* {private UpdateLastCancellationRequestIdToAsAny}. */ 1 )
//
//      //
//
//      private: void UpdateLastCancellationRequestIdToAsAny();
//
//#endif
//#if( /* {public LastCancellationRequestId}. */ 1 )
//
//      //
//
//      public: char const & LastCancellationRequestId() const;
//
//#endif
//TODO do we need this method? at least remove the word "last".
//#if( /* {public LastCancellationRequestIdMatches}. */ 1 )
//
//      // yg? Consider moving this method to {TSingleInstrumentOrderHelpers}. But it uses some {private} constants.
//
//      public: bool LastCancellationRequestIdMatches
//         ( ::tsNCharcb const & value1
//         ) const;
//
//#endif
//TODO we don't need this any more, right?
//#if( /* {public LastCancellationRequestIdMatchesLoosely}. */ 1 )
//
//      // yg? I don't like this loose logic.
//      // yg? See {LastCancellationRequestIdMatches} comment.
//
//      public: bool LastCancellationRequestIdMatchesLoosely
//         ( ::tsNCharcb const & value1
//         ) const;
//
//#endif
//#if( /* //Request ID prototype. */ 0 )
//
//      // Placeholder.
//
//#endif
   };
}
