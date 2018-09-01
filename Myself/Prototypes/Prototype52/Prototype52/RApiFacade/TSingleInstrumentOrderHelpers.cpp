#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TSingleInstrumentOrderHelpers.hpp"

#include "./TSingleInstrumentOrder.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

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

#if( /* {public OrdersStateBitMaskEqual}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TSingleInstrumentOrderHelpers::OrdersStateBitMaskEqual
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator,
        TOrderStateBitMask orderStateBitMask
      )
   {
      // TODO 3 yg? Would it be efficient to call the other overload here?

      // TODO 3 yg? Can we use a sort of "true for all" method from a standard library?
      // TODO 3 yg? But the collection would have to appear as containing order references.
      // TODO 3 yg? Would {::boost::make_transform_iterator} be helpful?
      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )
      {
         if( ( * orders1BeginIterator )->StateBitMask == orderStateBitMask )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            return false;
         }
      }

      return true;
   }

#endif
#if( /* {public OrdersStateBitMaskEqual}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TSingleInstrumentOrderHelpers::OrdersStateBitMaskEqual
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator,
        TOrderStateBitMask orderStateBitMaskBitMask,
        TOrderStateBitMask orderStateBitMask
      )
   {
      // yg? See comments in the other overload.

      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )
      {
         if( ( ( * orders1BeginIterator )->StateBitMask & orderStateBitMaskBitMask ) == orderStateBitMask )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            return false;
         }
      }

      return true;
   }

#endif
#if( /* {public OrderStateBitMaskExists}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TSingleInstrumentOrderHelpers::OrderStateBitMaskExists
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator,
        TOrderStateBitMask orderStateBitMask
      )
   {
      // TODO 3 yg? Would it be efficient to call the other overload here?

      // TODO 3 yg? Can we use a sort of "find" or "exists" method from a standard library?
      // TODO 3 yg? But the collection would have to appear as containing order references.
      // TODO 3 yg? Would {::boost::make_transform_iterator} be helpful?
      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )
      {
         if( ( * orders1BeginIterator )->StateBitMask == orderStateBitMask )
         {
            return true;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
      }

      return false;
   }

#endif
#if( /* {public OrderStateBitMaskExists}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TSingleInstrumentOrderHelpers::OrderStateBitMaskExists
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator,
        TOrderStateBitMask orderStateBitMaskBitMask,
        TOrderStateBitMask orderStateBitMask
      )
   {
      // yg? See comments in the other overload.

      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )
      {
         if( ( ( * orders1BeginIterator )->StateBitMask & orderStateBitMaskBitMask ) == orderStateBitMask )
         {
            return true;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
      }

      return false;
   }

#endif
#if( /* {public OrdersStateBitMaskExist}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TSingleInstrumentOrderHelpers::OrdersStateBitMaskExist
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator,
        TOrderStateBitMask orderStateBitMask,
        int numberOrdersMinLimit
      )
   {
      // TODO 3 yg? Would it be efficient to call the other overload here?
      // If at the beginning {numberOrdersMinLimit <= 0} we should just return {true}
      // but that would introduce an overhead in most cases.

      // One might want to move this validation to where we access {numberOrdersMinLimit},
      // but I don't feel too bad about leaving it here.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberOrdersMinLimit > ::std::numeric_limits< int >::lowest() );

      // TODO 3 yg? Can we use a standard library method?
      // TODO 3 yg? But the collection would have to appear as containing order references.
      // TODO 3 yg? Would {::boost::make_transform_iterator} be helpful?
      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )
      {
         if( ( * orders1BeginIterator )->StateBitMask == orderStateBitMask &&
             ( -- numberOrdersMinLimit ) <= 0
           )
         {
            return true;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
      }

      return ( numberOrdersMinLimit <= 0 );
   }

#endif
#if( /* {public OrdersStateBitMaskExist}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TSingleInstrumentOrderHelpers::OrdersStateBitMaskExist
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator,
        TOrderStateBitMask orderStateBitMaskBitMask,
        TOrderStateBitMask orderStateBitMask,
        int numberOrdersMinLimit
      )
   {
      // yg? See comments in the other overload.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberOrdersMinLimit > ::std::numeric_limits< int >::lowest() );

      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )
      {
         if( ( ( * orders1BeginIterator )->StateBitMask & orderStateBitMaskBitMask ) == orderStateBitMask &&
             ( -- numberOrdersMinLimit ) <= 0
           )
         {
            return true;
         }
         else
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
      }

      return ( numberOrdersMinLimit <= 0 );
   }

#endif

#if( /* {public CanModifyOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TSingleInstrumentOrderHelpers::CanModifyOrder
      ( TSingleInstrumentOrder const & order1
      )
   {
      // As soon as we know brokerage generated order ID we can send a modification request,
      // even if any other requests, including the new order one, are still pending.
      return ( ( order1.StateBitMask &
                     ( TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                       TOrderStateBitMask_ProbablyCompleted
                     )
                   ) ==
                   TOrderStateBitMask_NewOrderRequestReceivedByBroker
                 );
   }

#endif
#if( /* {public CanModifyOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TSingleInstrumentOrderHelpers::CanModifyOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      )
   {
      // TODO 3 yg? Can we use a sort of "true for all" method from a standard library?
      // TODO 3 yg? But the collection would have to appear as containing order references.
      // TODO 3 yg? Would {::boost::make_transform_iterator} be helpful?
      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )
      {
         if( CanModifyOrder( * * orders1BeginIterator ) )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            return false;
         }
      }

      return true;
   }

#endif
#if( /* {public CanCancelOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TSingleInstrumentOrderHelpers::CanCancelOrder
      ( TSingleInstrumentOrder const & order1
      )
   {
//TODO revisit all comments

      // As soon as we know brokerage generated order ID we can send a cancellation request,
      // even if any other requests, including the new order one, are still pending.
      // But I don't want to send a cancellation request if another one is still believed to be pending.
      // This also applies to {ShallAndInternalCanCancelOrder}.
//TODO revisit the above comments
      return ( ( order1.StateBitMask &
                     ( TOrderStateBitMask_NewOrderRequestReceivedByBroker |

//TODO Write a better comment that when this bit is 1 the cancellation is managed by {TREngineAdapter}.
//TODO Really the same is true if any of the 3 bits is 1.
//TODO actually we don't need to check the other bits as when any of them is 1 this one is 1 too.
//TODO when this bit is 1 the caller is not supposed to do any cancelling but this logic won't allow it anyway
                       TOrderStateBitMask_ShallBeCancelled |

//TODO validate that if any of these 2 bits is 1 the TOrderStateBitMask_ShallBeCancelled==1

////TODO Write a better comment that once 1 or more of the {TOrderStateBitMask_ShallBeCancelled},
////TODO {TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending},
////TODO {TOrderStateBitMask_CancellationRequestPending} bits are 1 they will probably not all become 0,
////TODO although it depends on {::RApi::REngine} sending correct notifications. It can potentially indicate that no cancellation request
////TODO is pending but soon after that it should send an order report indicating the completion of the cancel request
//                       TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
////TODO remove
//                       //TOrderStateBitMask_LastCancellationRequestPending |
//                       TOrderStateBitMask_CancellationRequestPending |

                       TOrderStateBitMask_ProbablyCompleted
                     )
                   ) ==
                   TOrderStateBitMask_NewOrderRequestReceivedByBroker
                 );
   }

#endif
#if( /* {public CanCancelOrders}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSingleInstrumentsOrdersPointerIterator_
      >
   inline bool TSingleInstrumentOrderHelpers::CanCancelOrders
      ( TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
      )
   {
      // yg? See a comment in {CanModifyOrders}.
      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )
      {
         if( CanCancelOrder( * * orders1BeginIterator ) )
         {
            ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
         }
         else
         {
            return false;
         }
      }

      return true;
   }

#endif
#if( /* {public InternalCanCancelOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TSingleInstrumentOrderHelpers::InternalCanCancelOrder
      ( TSingleInstrumentOrder const & order1
      )
   {
//TODO write some comments?

      return ( ( order1.StateBitMask &
                     ( TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                       TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                       TOrderStateBitMask_CancellationRequestPending |
                       TOrderStateBitMask_ProbablyCompleted
                     )
                   ) ==
                   TOrderStateBitMask_NewOrderRequestReceivedByBroker
                 );
   }

#endif
#if( /* {public ShallAndInternalCanCancelOrder}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TSingleInstrumentOrderHelpers::ShallAndInternalCanCancelOrder
      ( TSingleInstrumentOrder const & order1
      )
   {
//TODO revisit comment
      // See a comment in {CanCancelOrder}.
      return ( ( order1.StateBitMask &
                     ( TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                       TOrderStateBitMask_ShallBeCancelled |
                       TOrderStateBitMask_LastCancellationRequestReceptionByBrokerPending |
                       //TOrderStateBitMask_LastCancellationRequestPending |
                       TOrderStateBitMask_CancellationRequestPending |
                       TOrderStateBitMask_ProbablyCompleted
                     )
                   ) ==
                   ( TOrderStateBitMask_NewOrderRequestReceivedByBroker |
                     TOrderStateBitMask_ShallBeCancelled
                   )
                 );
   }

#endif
#if( /* {public CanCancelOrderAsAny}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TSingleInstrumentOrderHelpers::CanCancelOrderAsAny
      ( TSingleInstrumentOrder const & order1
      )
   {
//TODO read this comment
      // The brokerage will likely try to cancel any not "probably" completed order.
      // yg? Although this might potentially be not the case if we send a new order request
      // yg? and immediately after that send an "any" order cancellation request.
      // yg? And if this happens we will not re-request to cancel this order.
      // A "probably" completed order will likely be fully completed by the time the request reaches the brokerage.
      return ( ( ( order1.StateBitMask &
                        TOrderStateBitMask_ProbablyCompleted
                     ) ==
                     TOrderStateBitMask_None
                   ) &&
                   ( ( order1.StateBitMask &
                        ( TOrderStateBitMask_NewOrderRequestPending |
                          TOrderStateBitMask_NewOrderRequestReceivedByBroker
                        )
                     ) !=
                     TOrderStateBitMask_None
                   )
                 );
   }

#endif
#if( /* {public RegisterRequestCancelOrderAsAnyIfCan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TSingleInstrumentOrderHelpers::RegisterRequestCancelOrderAsAnyIfCan
      ( TSingleInstrumentOrder & order1
      )
   {
      if( CanCancelOrderAsAny( order1 ) )
      {
         order1.RegisterRequestCancelAsAny();
      }
      else
      {
         ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
   }

#endif
#if( /* {public RegisterRequestCancelOrdersAsAnyIfCan}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TSingleInstrumentsOrdersPointerIterator_
   //   >
   void TSingleInstrumentOrderHelpers::RegisterRequestCancelOrdersAsAnyIfCan
      ( //TSingleInstrumentsOrdersPointerIterator_ orders1BeginIterator,
        //TSingleInstrumentsOrdersPointerIterator_ orders1EndIterator
        ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > > & orders1
      )
   {
      // TODO 3 yg? Can we generically call a method for all items in a collection?
      // TODO 3 yg? But the collection would have to appear as containing order references.
      // TODO 3 yg? Would {::boost::make_transform_iterator} be helpful?
      ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::const_iterator orders1BeginIterator( orders1.cbegin() );
      ::std::map< void const *, ::std::unique_ptr< TSingleInstrumentOrder > >::const_iterator orders1EndIterator( orders1.cend() );
      for( ; orders1BeginIterator != orders1EndIterator ; ++ orders1BeginIterator )
      {
         //RegisterRequestCancelOrderAsAnyIfCan( * * orders1BeginIterator );
         RegisterRequestCancelOrderAsAnyIfCan( * orders1BeginIterator->second );
      }
   }

#endif
}
