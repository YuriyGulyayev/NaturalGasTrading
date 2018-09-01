#pragma once

#include "./TEconomicReportReceiverBase.hpp"
#include "./TEconomicReportReceiverFactoryConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // yg? Do we need base template classes for this and related classes.

   class TEconomicReportReceiverFactory
   {
#if( /* {public EconomicReportReceiver}. */ 1 )

      //
      public: ::std::unique_ptr< TEconomicReportReceiverBase< int > > EconomicReportReceiver;

#endif

#if( /* //{(private)} Instance default constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TEconomicReportReceiverFactory
         ( TEconomicReportReceiverFactory const & source
         );

#endif
#if( /* {public} Instance constructor. */ 1 )

      //

      public: explicit TEconomicReportReceiverFactory
         ( TEconomicReportReceiverFactoryConfiguration && configuration1
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // yg? It would probably be OK to not make this {virtual} even if I make this class a part of an inheritance hierarchy.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TEconomicReportReceiverFactory & operator =
         ( TEconomicReportReceiverFactory const & source
         );

#endif

#if( /* {private CreateEconomicReportReceiver}. */ 1 )

      // The caller shall {delete} the pointer returned.

      private: static TEconomicReportReceiverBase< int > * CreateEconomicReportReceiver
         ( TEconomicReportReceiverFactoryConfiguration && configuration1
         );

#endif
   };
}
