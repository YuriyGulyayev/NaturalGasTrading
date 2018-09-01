#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace RApiFacade
{
   // yg? Consider something like this:
   // yg? "known to broker".
   // yg? "new order request pending".
   // yg? "new order request rejected by broker".
   // yg? "held by broker".
   // yg? "new order request rejected by exchange". Even after a holding by the brokerage and possible modification it will be a new order request from the exchange point of view.
   // yg? "last modification request pending". The order can still be held by the brokerage and will not be sent to the exchange.
   // yg? "last modification request rejected by broker".
   // yg? "last modification request rejected by exchange".
   // yg? "triggered by broker". This really can be named "sent to exchange". Maybe we don't need this.
   // yg? "triggered by exchange".
   // yg? "last cancellation ...".
   // yg? "probably completed".
   // yg? "completed".

   enum TOrderStateBitMask : unsigned int
   {
      //
      TOrderStateBitMask_None = 0U,

      // This bit is also set when the {TOrderStateBitMask_TriggeredByBroker} bit is set
      // and then cleared after the exchange accepts or rejects the new order request.
      TOrderStateBitMask_NewOrderRequestPending = 1U << 1U,

      // 1 indicates that the order is known to the brokerage and {TSingleInstrumentOrder::BrokerGeneratedId} is valid.
      // We set this bit every time we receive any notification from the brokerage regarding this order, which is usually redundant.
//TODO remove prev line; we now have a separate method that checks if the order is still in the collection keyed on new order req id and if so it sets this bit
      TOrderStateBitMask_NewOrderRequestReceivedByBroker = 1U << 3U,

      ////
      //TOrderStateBitMask_NewOrderRequestRejected = 1U << ???U,

      //// 1 indicates that the order has been accepted by the brokerage and now either is held or was sent to the exchange.
      //// The brokerage can hold the order either unconditionally or until a trigger condition is met.
      //// yg? Consider using the word "new order request". Bad idea?
      //TOrderStateBitMask_AcceptedByBroker = 1U << ???U,

      //// 1 indicates that the order has been accepted by the exchange.
      //// yg? Consider using the word "new order request". Bad idea?
      //TOrderStateBitMask_AcceptedByExchange = 1U << ???U,

//TODO remove these and refactor related code
      ////
      //TOrderStateBitMask_LastModificationRequestPending = 1U << ???U,
      //
      ////
      //TOrderStateBitMask_LastModificationRequestRejected = 1U << ???U,

      //// 1 indicates that a modification request is pending.
      //// This currently covers only the modification requests known to us, meaning those whose ID length is 2,
      //// which in turn causes an automatic creation of a modification request object if one doesn't exist yet.
      //// yg? If I implement the removal of modification requests I would need to check if this bit needs to be cleared.
//TODO we don't need this? it would be difficult to maintain this and there would be no benefit as we can have mod reqs of different purpoces
      //TOrderStateBitMask_ModificationRequestPending = 1U << ???U,

      // Cancel the order when possible.
      // It's undocumented under what exactly conditions this bit is set,
      // but it can be set only after we or any other app requests to cancel the order.
//TODO Write comments that we avoid setting this bit liberally.
//TODO It's possible that {::RApi::LineInfo} will show a pending cancel request, then show that no cancel request is pending and
//TODO if this bit is 1 another cancel request will be sent if this bit is 1. But after that a report can arrive saying that previous
//TODO cancel request completed.
//TODO One way to improve this logic is no not clear the {TOrderStateBitMask_CancellationRequestPending} bit in {LineUpdate}
//TODO but if a {::RApi::OrderFailureReport} arrives...
//TODO this is all shit... now setting this bit on any occasion.
//TODO the occasion includes seting of any of the other 2 cancel related bits
//TODO comment: we set this bit when we set the {TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending} or
//TODO {TOrderStateBitMask_CancellationRequestPending} bit.
      TOrderStateBitMask_ShallBeCancelled = 1U << 9U,

      // We set this bit when we send a cancellation request and unset it after the brokerage confirms its reception.
      // Note that an order cancellation request can be rejected with a single {FailureReport} callback call
      // and no other callback will be called.
//TODO maybe move the above comment to {FailureReport}.
//TODO better comment: when we set this bit we also set {TOrderStateBitMask_ShallBeCancelled}.
      TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending = 1U << 11U,

//TODO remove?
      //// See also: {TOrderStateBitMask_CancellationRequestPending}.
      //TOrderStateBitMask_LastCancellationRequestPending = 1U << ???U,

//TODO remove?
      ////
      //TOrderStateBitMask_LastCancellationRequestRejected = 1U << ???U,

      // When this bit is 1 the following are valid:
      // {TSingleInstrumentOrder::UnexpectedCancellationRequestId},
      // {TSingleInstrumentOrder::UnexpectedCancellationRequestIdLength}.
//TODO Write a better comment. See doc file.
      TOrderStateBitMask_UnexpectedCancellationRequestPending = 1U << 13U,

      // This bit is 1 when a cancellation request is pending, regardless of which peer (or whoever) sent it.
      // It's independent from {TOrderStateBitMask_LastCancellationRequestPending}
      // and is updated based on the brokerage notifications.
//TODO revisit the above comment
//TODO better comment: when we set this bit we also set {TOrderStateBitMask_ShallBeCancelled}.
      TOrderStateBitMask_CancellationRequestPending = 1U << 15U,

      // Trigger condition occurred on the brokerage and a new order request was sent to the exchange.
      // This bit can be set only for an "if-touched" order.
      // See also: {TOrderStateBitMask_NewOrderRequestPending}.
      TOrderStateBitMask_TriggeredByBroker = 1U << 17U,

      // Trigger condition occurred on the exchange and the order is working on the exchange.
      // This bit can be set only for a "stop-*" order.
      TOrderStateBitMask_TriggeredByExchange = 1U << 19U,

      // At some point a fill occurred.
      // This flag is not cleared after all fills get cancelled.
      // TODO 3 yg? Do we need this?
//TODO we need this to see if quick exit order fille occurred to execute the same logic as we do when its modification for release succeeds or it's triggered by broker
//TODO I uncommented this. Review comment and refactor code.
      TOrderStateBitMask_FillOccurred = 1U << 20U,

      // There is a high chance that the filled quantity will not change and the order will complete automatically.
      // This bit is always set when the {TOrderStateBitMask_Completed} one is set.
      // This logic can be risky. One risky assumption one might want to make
      // is that a "stop-market" order will be filled in full as soon as the exchange reports that the trigger condition occurred.
      // A brokerage API adapter should not make such an assumption but its caller might want to do so.
      TOrderStateBitMask_ProbablyCompleted = 1U << 21U,

      // The order is confirmed to be rejected, expired, cancelled, filled, etc.
      // Its fills can still be corrected/restated/cancelled/busted.
      // This bit can be set even if a new order, modification, or cancellation request is believed to still be pending. In that case
      // a request rejection notification will probably arrive soon.
      // See also: {TOrderStateBitMask_ProbablyCompleted}.
      TOrderStateBitMask_Completed = 1U << 23U,
   };
}
