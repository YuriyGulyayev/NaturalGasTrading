#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportReceiverFactory.hpp"

#include "./TEconomicReportReceiverBase.cpp"
#include "./TEconomicReportReceiverFactoryConfiguration.cpp"
#include "../Common/CodeOptimization/Macros.cpp"
#include "./TNaturalGasStorageReportDownloader.cpp"
#include "./TPetroleumStatusReportDownloader.cpp"
#include "./TNewsHubEconomicIndicatorReceiver.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* //{(private)} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TEconomicReportReceiverFactory::TEconomicReportReceiverFactory
      ( TEconomicReportReceiverFactoryConfiguration && configuration1
      ) :
      EconomicReportReceiver( CreateEconomicReportReceiver( ::std::move( configuration1 ) ) )
   {
      configuration1.DataTypeConfiguration.reset();
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {private CreateEconomicReportReceiver}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TEconomicReportReceiverBase< int > * TEconomicReportReceiverFactory::CreateEconomicReportReceiver
      ( TEconomicReportReceiverFactoryConfiguration && configuration1
      )
   {
      // This method is inline.
      // This method doesn't deallocate {configuration1.DataTypeConfiguration}.

      switch( configuration1.DataTypeCode )
      {
         case TEconomicReportReceiverTypeCode_TNaturalGasStorageReportDownloader :
         {
            // Not using {::std::move}.
            return new TNaturalGasStorageReportDownloader
                                 ( static_cast< TNaturalGasStorageReportDownloaderConfiguration && >( * configuration1.DataTypeConfiguration ) );
            
            break;
         }
         
         case TEconomicReportReceiverTypeCode_TPetroleumStatusReportDownloader :
         {
            // Not using {::std::move}.
            return new TPetroleumStatusReportDownloader
                                 ( static_cast< TPetroleumStatusReportDownloaderConfiguration && >( * configuration1.DataTypeConfiguration ) );
            
            break;
         }
         
         case TEconomicReportReceiverTypeCode_TNewsHubEconomicIndicatorReceiver :
         {
            // Not using {::std::move}.
            return new TNewsHubEconomicIndicatorReceiver
                                 ( static_cast< TNewsHubEconomicIndicatorReceiverConfiguration && >( * configuration1.DataTypeConfiguration ) );
            
            break;
         }

         default :
         {
            YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
            break;
         }
      }
   }

#endif
}
