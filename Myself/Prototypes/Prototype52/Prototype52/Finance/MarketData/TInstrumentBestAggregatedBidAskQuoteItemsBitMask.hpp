#pragma once

//#include "./.hpp"

#include "../../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Finance
{
namespace MarketData
{
   // It's probably a bad idea to have a single bit for bid price/size and another bit for ask price/size as a brokerage API can
   // potentially update only the price or the size. And we now have an additional bit for the number of orders.
   // yg? Is it a good idea to add bits for the timestamps? If so the caller would need to expect those sometimes/always to be invalid.

   enum TInstrumentBestAggregatedBidAskQuoteItemsBitMask : unsigned int
   {
      //
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_None = 0U,

      //
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidPrice = 1U << 0U,

      //
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidQuantity = 1U << 1U,

      //
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidNumberOrders = 1U << 2U,

      //
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskPrice = 1U << 3U,

      //
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskQuantity = 1U << 4U,

      //
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskNumberOrders = 1U << 5U,

      //
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllBid =
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidPrice |
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidQuantity |
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidNumberOrders,

      //
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllAsk =
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskPrice |
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskQuantity |
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskNumberOrders,

      // We should consider market data valid when only these market data items are valid.
      // Not every brokerage API provides the others.
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllImportant =
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidPrice |
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_BidQuantity |
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskPrice |
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AskQuantity,

      // In certain scenarios prefer using {TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllImportant} instead of this.
      TInstrumentBestAggregatedBidAskQuoteItemsBitMask_All =
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllBid |
         TInstrumentBestAggregatedBidAskQuoteItemsBitMask_AllAsk,
   };
}
}
