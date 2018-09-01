#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TSingleInstrumentOrder.hpp"

#include "../Finance/Math/TQuantityAndPrice.cpp"
#include "../Finance/Trading/TPositionDirectionCode.cpp"
#include "../Finance/Trading/TSingleInstrumentOrderBase.cpp"
#include "./TInstrument.cpp"
#include "./TOrderTypeCode.cpp"
#include "./TOrderTimeInForceCode.cpp"
#include "./TOrderStateBitMask.cpp"
//TODO should we include this a few lines above?
#include "./TSingleInstrumentOrderModificationRequest.cpp"
#include "../Common/CodeOptimization/Macros.cpp"
#include "../Common/Diagnostics/TDiagnosticsHelpers.cpp"
#include "./TSingleInstrumentOrderHelpers.cpp"
#include "./TREngineAdapter.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* {public NewOrderRequestId_}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
//   char const TSingleInstrumentOrder::NewOrderRequestId_( static_cast< char >( NewOrderRequestIdFactor1_ ) );

#endif

#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //TSingleInstrumentOrder::TSingleInstrumentOrder() :
   //   StateBitMask( TOrderStateBitMask_None ),
   //   BrokerGeneratedId( TRApiHelpers::OrderNumberNone ),
   //   //NumberPendingCancellationRequests( 0 ),
   //   LastModificationRequestId_( static_cast< char >( ModificationRequestIdFactor2_ ) ),
   //   LastCancellationRequestId_( static_cast< char >( CancellationRequestIdFactor2_ ) )
   //{
   //   FilledQuantityAndPrice.Reset();
   //}

#endif
#if( /* //{(private)} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* //{(private) operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif

#if( /* {public Prepare}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline void TSingleInstrumentOrder::Prepare
   //   ( TInstrument const & //instrument1
   //   )
   //{
   //   // This method is inline because it's called from only 1 place.

   //   ::Finance::Trading::TSingleInstrumentOrderBase< TSingleInstrumentOrder, TInstrument >::Prepare( instrument1 );

   //   {
   //      // At this point this is not guaranteed to be populated.
   //      // yg? Doing {const_cast}.
   //      OrderParams_.pAccount = const_cast< ::RApi::AccountInfo * >( & instrument1.BrokerAdapter().AccountInfo() );

   //      TRApiHelpers::PopulateTSNCharcb( OrderParams_.sExchange, instrument1.ExchangeAbbreviation() );
   //      TRApiHelpers::PopulateTSNCharcb( OrderParams_.sTicker, instrument1.Symbol() );

   //      // yg? "Day", not "good-till-cancelled", because it's safer.
   //      // yg? "Good-till-cancelled" orders are not currently supported by the papertrading environment.
   //      // Is this needed for a market order? Probably so as the {::RApi::MarketOrderParams} class has this field too.
   //      // Maybe because it's really "market-with-protection".
   //      OrderParams_.sDuration = ::RApi::sORDER_DURATION_DAY;

   //      OrderParams_.sEntryType = ::RApi::sORDER_ENTRY_TYPE_AUTO;
   //      TRApiHelpers::PopulateTSNCharcb( OrderParams_.sTradeRoute, instrument1.TradeRouteName() );

   //      // yg? Doing {const_cast}.
   //      OrderParams_.sUserMsg.pData = const_cast< char * >( & NewOrderRequestId_ );

   //      OrderParams_.sUserMsg.iDataLen = 1;

   //      // TODO 3 yg? Hack. Instead we should generate an integer order ID.
   //      OrderParams_.pContext = reinterpret_cast< void * >( this );
   //   }

   //   {
   //      ModifyOrderParams_.pAccount = OrderParams_.pAccount;

   //      // yg? I would expect instrument to be optional but it isn't.
   //      // TODO 3 yg? Test if it's now optional. Last tested 09/24/2013.
   //      ModifyOrderParams_.sExchange = OrderParams_.sExchange;
   //      ModifyOrderParams_.sTicker = OrderParams_.sTicker;

   //      ModifyOrderParams_.sEntryType = ::RApi::sORDER_ENTRY_TYPE_AUTO;
   //      ModifyOrderParams_.sUserMsg.pData = ( & LastModificationRequestId_ );
   //      ModifyOrderParams_.sUserMsg.iDataLen = 1;

   //      // TODO 3 yg? Hack. Instead we should generate an integer order ID.
   //      ModifyOrderParams_.pContext = reinterpret_cast< void * >( this );
   //   }
   //}

#endif

#if( /* {public PrepareSend}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TSingleInstrumentOrder::PrepareSend()
   {
      // yg? Consider making this method not inline.

//TODO remove this comment
      // yg? {TREngineAdapter::ModifyReport} and {TREngineAdapter::CancelReport} validate
      // yg? the {TOrderStateBitMask_TriggeredByBroker} and {TOrderStateBitMask_TriggeredByExchange} bits.
      // yg? If I implement support for "stop-limit" or "limit-if-touched" orders that validation would need to be revisited.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( StateBitMask == TOrderStateBitMask_None );
      StateBitMask = TOrderStateBitMask_NewOrderRequestPending;

      {
         switch( TypeCode )
         {
            case TOrderTypeCode_Market :
            {
               OrderParams_.sOrderType = ::RApi::sORDER_TYPE_MARKET;

               //#pragma message( "yg---?? Test." )
               //OrderParams_.sOrderType = ::RApi::sORDER_TYPE_LIMIT;
               //OrderParams_.dPrice = ( DirectionCode >= ::Finance::Trading::TPositionDirectionCode_None ) ?
               //                                     Instrument().BrokerAdapter().InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Ask.Price :
               //                                     Instrument().BrokerAdapter().InstrumentBestAggregatedBidAskQuoteSubscription_.InstrumentBestAggregatedBidAskQuote.Bid.Price;
               //StateBitMask = static_cast< TOrderStateBitMask >( StateBitMask | TOrderStateBitMask_ShallBeCancelled );

               break;
            }

            case TOrderTypeCode_StopMarket :
            {
               OrderParams_.sOrderType = ::RApi::sORDER_TYPE_STOP_MARKET;
               goto label1;
               break;
            }

            //case TOrderTypeCode_StopLimit :
            //{
            //   OrderParams_.sOrderType = ::RApi::sORDER_TYPE_STOP_LIMIT;
            //   OrderParams_.dPrice = LimitPrice;
            //   goto label1;
            //   break;
            //}

            case TOrderTypeCode_MarketIfTouched :
            {
               OrderParams_.sOrderType = ::RApi::sORDER_TYPE_MKT_IF_TOUCHED;

               // yg? This logic serves only our immediate needs.
               OrderParams_.sTriggerExchange = OrderParams_.sExchange;
               OrderParams_.sTriggerTicker = OrderParams_.sTicker;
               OrderParams_.iTriggerPriceId = ::RApi::TRADE_PRICE;
               OrderParams_.iTriggerCmpOperator = ( DirectionCode >= ::Finance::Trading::TPositionDirectionCode_None ) ?
                                                                           ::RApi::OP_LESS_THAN_OR_EQUAL_TO :
                                                                           ::RApi::OP_GREATER_THAN_OR_EQUAL_TO;

            label1:
               OrderParams_.dTriggerPrice = TriggerPrice;
               break;
            }

            default :
            {
               YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
               break;
            }
         }

         OrderParams_.sBuySellType = ( DirectionCode >= ::Finance::Trading::TPositionDirectionCode_None ) ?
                                                         ::RApi::sBUY_SELL_TYPE_BUY :
                                                         ::RApi::sBUY_SELL_TYPE_SELL;

         // As mentioned in a {Quantity} comment, the caller shall round this.
         // Assuming this will not overflow.
         OrderParams_.iQty = static_cast< int >( Quantity );
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Quantity == static_cast< double >( OrderParams_.iQty ) );
      }
   }

#endif
#if( /* {public PrepareRequestModify}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline void TSingleInstrumentOrder::PrepareRequestModify()
   //{
   //   // yg? Consider making this method not inline.

   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TSingleInstrumentOrderHelpers::CanModifyOrder( * this ) );
   //   IncrementLastModificationRequestId();
   //   StateBitMask =
   //      static_cast< TOrderStateBitMask >
   //         ( ( StateBitMask &
   //              ( ~ TOrderStateBitMask_LastModificationRequestRejected )
   //           ) |
   //           TOrderStateBitMask_LastModificationRequestPending
   //         );

   //   // yg? Not providing the following potentially important {ModifyOrderParams_} fields:
   //   // yg? {sOrderType}, {sDuration}, {bQty}, {iQty}.
   //   // yg? Assuming that {TypeCode} never changes. Otherwise for example
   //   // yg? when modifying order type to "market" we would need to explicitly set {ModifyOrderParams_.bTriggerPrice = false},
   //   // yg? unless, of course, it would be ignored anyway (to be tested).
   //   // yg? An alternative solution would be to maintain a separate {::RApi::ModifyOrderParams} for each order type.
   //   {
   //      switch( TypeCode )
   //      {
   //         case TOrderTypeCode_Market :
   //         {
   //            break;
   //         }

   //         case TOrderTypeCode_StopMarket :
   //         {
   //            goto label2;
   //            break;
   //         }

   //         //case TOrderTypeCode_StopLimit :
   //         //{
   //         //   ModifyOrderParams_.dPrice = LimitPrice;
   //         //   ModifyOrderParams_.bPrice = true;
   //         //   goto label2;
   //         //   break;
   //         //}

   //         case TOrderTypeCode_MarketIfTouched :
   //         {
   //            // yg? The modification request would be rejected without these.
   //            // TODO 3 yg? Re-test it without these parameters. Last tested 10/17/2013.
   //            {
   //               ModifyOrderParams_.bQty = true;
   //               ModifyOrderParams_.iQty = OrderParams_.iQty;
   //               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( Quantity == static_cast< double >( ModifyOrderParams_.iQty ) );
   //            }

   //         label2:
   //            ModifyOrderParams_.dTriggerPrice = TriggerPrice;
   //            ModifyOrderParams_.bTriggerPrice = true;
   //            break;
   //         }

   //         default :
   //         {
   //            YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
   //            break;
   //         }
   //      }

   //      // TODO 3 yg? Do this and possibly some other actions in advance, maybe when the 1st {::RApi::LineInfo} arrives
   //      // TODO 3 yg? (that's when we will also move the order pointer from one collection to another).
   //      // TODO 3 yg? Better eliminate the {BrokerGeneratedId} field and add an accessor method of that name to return
   //      // TODO 3 yg? {ModifyOrderParams_.iOrderNum} reference.
   //      ModifyOrderParams_.iOrderNum = BrokerGeneratedId;
   //   }
   //}

#endif
#if( /* {public PrepareRequestCancel}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline void TSingleInstrumentOrder::PrepareRequestCancel()
   //{
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TSingleInstrumentOrderHelpers::InternalCanCancelOrder( * this ) );
   //   IncrementLastCancellationRequestId();
   //   StateBitMask =
   //      static_cast< TOrderStateBitMask >
   //         //( ( StateBitMask &
   //         //     ( ~ TOrderStateBitMask_LastCancellationRequestRejected )
   //         //  ) |
   //         //  TOrderStateBitMask_LastCancellationRequestPending
   //         //);
   //         ( StateBitMask |
   //           TOrderStateBitMask_ShallBeCancelled |
   //           TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending
   //         );
   //}

#endif
#if( /* {public RegisterRequestCancelAsAny}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline void TSingleInstrumentOrder::RegisterRequestCancelAsAny()
   //{
   //   YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( TSingleInstrumentOrderHelpers::CanCancelOrderAsAny( * this ) );
   //   UpdateLastCancellationRequestIdToAsAny();
   //   StateBitMask =
   //      static_cast< TOrderStateBitMask >
   //         //( ( StateBitMask &
   //         //     ( ~ TOrderStateBitMask_LastCancellationRequestRejected )
   //         //  ) |
   //         //  TOrderStateBitMask_LastCancellationRequestPending
   //         //);
   //         ( StateBitMask |
   //           TOrderStateBitMask_ShallBeCancelled |
   //           TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending
   //         );
   //}

#endif

//TODO remove/refactor
#if( /* {public OrderParams}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline ::RApi::OrderParams const & TSingleInstrumentOrder::OrderParams() const
   {
      return OrderParams_;
   }

#endif
#if( /* {private IncrementLastModificationRequestId}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline void TSingleInstrumentOrder::IncrementLastModificationRequestId()
   //{
   //   unsigned int uint1( static_cast< unsigned char >( LastModificationRequestId_ ) );
   //   uint1 = ( ( uint1 + 1U ) & ModificationRequestIdFactor2_ ) | ModificationRequestIdFactor1_;
   //   LastModificationRequestId_ = static_cast< char >( uint1 );
   //}

#endif
#if( /* {public LastModificationRequestId}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline char const & TSingleInstrumentOrder::LastModificationRequestId() const
   //{
   //   return LastModificationRequestId_;
   //}

#endif
#if( /* {public ModifyOrderParams}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline ::RApi::ModifyOrderParams const & TSingleInstrumentOrder::ModifyOrderParams() const
   //{
   //   return ModifyOrderParams_;
   //}

#endif
#if( /* {private IncrementLastCancellationRequestId}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline void TSingleInstrumentOrder::IncrementLastCancellationRequestId()
   //{
   //   unsigned int uint1( static_cast< unsigned char >( LastCancellationRequestId_ ) );
   //   uint1 = ( ( uint1 + 1U ) & CancellationRequestIdFactor2_ ) | CancellationRequestIdFactor1_;
   //   LastCancellationRequestId_ = static_cast< char >( uint1 );
   //}

#endif
#if( /* {private UpdateLastCancellationRequestIdToAsAny}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline void TSingleInstrumentOrder::UpdateLastCancellationRequestIdToAsAny()
   //{
   //   // Integral promotion is not a problem.
   //   LastCancellationRequestId_ |= static_cast< char >( CancellationRequestIdFactor3_ );
   //}

#endif
#if( /* {public LastCancellationRequestId}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline char const & TSingleInstrumentOrder::LastCancellationRequestId() const
   //{
   //   return LastCancellationRequestId_;
   //}

#endif
#if( /* {public LastCancellationRequestIdMatches}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline bool TSingleInstrumentOrder::LastCancellationRequestIdMatches
   //   ( ::tsNCharcb const & value1
   //   ) const
   //{
   //   unsigned int uint1( static_cast< unsigned char >( LastCancellationRequestId_ ) );
   //   if( ( uint1 & CancellationRequestIdFactor3_ ) == 0U )
   //   {
   //      return ( value1.iDataLen == 1 && ( * value1.pData ) == LastCancellationRequestId_ );
   //   }
   //   else
   //   {
   //      return ( value1.iDataLen <= 0 );
   //   }
   //}

#endif
#if( /* {public LastCancellationRequestIdMatchesLoosely}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

//TODO I commented this out to suppress compile errors.
   //inline bool TSingleInstrumentOrder::LastCancellationRequestIdMatchesLoosely
   //   ( ::tsNCharcb const & value1
   //   ) const
   //{
   //   unsigned int uint1( static_cast< unsigned char >( LastCancellationRequestId_ ) );
   //   if( ( uint1 & CancellationRequestIdFactor3_ ) == 0U )
   //   {
   //      return ( value1.iDataLen == 1 && ( * value1.pData ) == LastCancellationRequestId_ );
   //   }
   //   else
   //   {
   //      if( value1.iDataLen <= 0 )
   //      {
   //         return true;
   //      }
   //      else
   //      {
   //         if( value1.iDataLen == 1 )
   //         {
   //            unsigned int uint2( static_cast< unsigned char >( * value1.pData ) );

   //            // This condition is {true} if {uint2} is not a valid cancellation request ID.
   //            // In that case it's most likely a valid new order or modification request ID.
   //            // Although a few numbers that are not a valid cancellation (or any other) request ID would also pass this test, and that's OK.
   //            return ( ( uint2 & CancellationRequestIdFactor4_ ) == 0U );
   //         }
   //         else
   //         {
   //            //::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
   //            return false;
   //         }
   //      }
   //   }
   //}

#endif
#if( /* //Request ID prototype. */ 0 )

      public static void RequestIdPrototype()
      {
         {
            uint n = 0x67U;
            System.Diagnostics.Debug.Assert( ( n & 0x10U ) == 0U );
            System.Console.WriteLine( (char) n );
         }

         System.Console.WriteLine();

         {
            uint m = 0x7U;
            uint c = 0x7U;

            for( int counter1 = 0 ; counter1 < 8 + 1 ; ++ counter1 )
            {
               m = ( ( m + 1U ) & 0x7U ) | 0x68;
               System.Diagnostics.Debug.Assert( ( m & 0x10U ) == 0U );
               System.Console.Write( (char) m );
               c = ( ( c + 1U ) & 0x7U ) | 0x70;
               System.Diagnostics.Debug.Assert( ( c & 0x10U ) != 0U );
               System.Console.WriteLine( (char) c );
            }
         }
      }

#endif
}
