#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEconomicReportReceiverFactoryConfigurationHelpers.hpp"

#include "./TEconomicReportReceiverFactoryConfiguration.cpp"
#include "../Common/ErrorHandling/TRegularErrorException.cpp"
#include "../Common/Diagnostics/TDiagnosticsHelpers.cpp"
#include "./TNaturalGasStorageReportDownloaderConfigurationHelpers.cpp"
#include "./TPetroleumStatusReportDownloaderConfigurationHelpers.cpp"
#include "./TNewsHubEconomicIndicatorReceiverConfigurationHelpers.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
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

#if( /* {public ExtractConfiguration}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TEconomicReportReceiverFactoryConfigurationHelpers::ExtractConfiguration
      ( TEconomicReportReceiverFactoryConfiguration & economicReportReceiverFactoryConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "DataTypeCode" );
         economicReportReceiverFactoryConfiguration1.DataTypeCode =
            static_cast< TEconomicReportReceiverTypeCode >
               ( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }

      {
         static char const parameter3NameAsArray[]( "DataTypeConfiguration" );

         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >
                 ( abstractConfiguration1.createView( ::std::string( parameter3NameAsArray, ( sizeof( parameter3NameAsArray ) / sizeof( parameter3NameAsArray[ 0U ] ) - 1U ) ) ) )
            );

         switch( economicReportReceiverFactoryConfiguration1.DataTypeCode )
         {
            case TEconomicReportReceiverTypeCode_TNaturalGasStorageReportDownloader :
            {
               TNaturalGasStorageReportDownloaderConfiguration * naturalGasStorageReportDownloaderConfiguration1( new TNaturalGasStorageReportDownloaderConfiguration );
               economicReportReceiverFactoryConfiguration1.DataTypeConfiguration.reset( naturalGasStorageReportDownloaderConfiguration1 );
               TNaturalGasStorageReportDownloaderConfigurationHelpers::ExtractConfiguration
                  ( ( * naturalGasStorageReportDownloaderConfiguration1 ), ( * abstractConfiguration1View1 ) );
               break;
            }

            case TEconomicReportReceiverTypeCode_TPetroleumStatusReportDownloader :
            {
               TPetroleumStatusReportDownloaderConfiguration * petroleumStatusReportDownloaderConfiguration1( new TPetroleumStatusReportDownloaderConfiguration );
               economicReportReceiverFactoryConfiguration1.DataTypeConfiguration.reset( petroleumStatusReportDownloaderConfiguration1 );
               TPetroleumStatusReportDownloaderConfigurationHelpers::ExtractConfiguration
                  ( ( * petroleumStatusReportDownloaderConfiguration1 ), ( * abstractConfiguration1View1 ) );
               break;
            }
         
            case TEconomicReportReceiverTypeCode_TNewsHubEconomicIndicatorReceiver :
            {
               TNewsHubEconomicIndicatorReceiverConfiguration * newsHubEconomicIndicatorReceiverConfiguration1( new TNewsHubEconomicIndicatorReceiverConfiguration );
               economicReportReceiverFactoryConfiguration1.DataTypeConfiguration.reset( newsHubEconomicIndicatorReceiverConfiguration1 );
               TNewsHubEconomicIndicatorReceiverConfigurationHelpers::ExtractConfiguration
                  ( ( * newsHubEconomicIndicatorReceiverConfiguration1 ), ( * abstractConfiguration1View1 ) );
               break;
            }
         
            default :
            {
               ::Common::Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

               {
                  static char const constantString1AsArray[]
                     ( "Error; {Prototype52::TEconomicReportReceiverFactoryConfigurationHelpers::ExtractConfiguration} failed" );

                  // yg? Would it make sense to throw a {::Common::ErrorHandling::TCriticalErrorException} here.
                  throw ::Common::ErrorHandling::TRegularErrorException
                               ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                                 0
                               );
               }
            }
         }
      }


      // Old version that uses {DataTypeName}.
      //
      //static char const parameter2NameAsArray[]( "DataTypeName" );
      //::std::string dataTypeName( abstractConfiguration1.getString( ::std::string( parameter2NameAsArray, ( sizeof( parameter2NameAsArray ) / sizeof( parameter2NameAsArray[ 0U ] ) - 1U ) ) ) );
      //
      //static char const parameter3NameAsArray[]( "DataTypeConfiguration" );
      //
      //// We have to do a {const_cast} here.
      //::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( ::std::string( parameter3NameAsArray, ( sizeof( parameter3NameAsArray ) / sizeof( parameter3NameAsArray[ 0U ] ) - 1U ) ) ) ) );
      //
      //{
      //   static char const dataType1NameAsArray[]( "TNaturalGasStorageReportDownloader" );
      //
      //   // This is inefficient and I am OK with that.
      //   if( dataTypeName.compare( 0U, dataTypeName.length(), dataType1NameAsArray, ( sizeof( dataType1NameAsArray ) / sizeof( dataType1NameAsArray[ 0U ] ) - 1U ) ) == 0 )
      //
      //   {
      //      economicReportReceiverFactoryConfiguration1.DataTypeCode = TEconomicReportReceiverTypeCode_TNaturalGasStorageReportDownloader;
      //      TNaturalGasStorageReportDownloaderConfiguration * naturalGasStorageReportDownloaderConfiguration1( new TNaturalGasStorageReportDownloaderConfiguration );
      //      economicReportReceiverFactoryConfiguration1.DataTypeConfiguration.reset( naturalGasStorageReportDownloaderConfiguration1 );
      //      TNaturalGasStorageReportDownloaderConfigurationHelpers::ExtractConfiguration
      //         ( ( * naturalGasStorageReportDownloaderConfiguration1 ), ( * abstractConfiguration1View1 ) );
      //      return;
      //   }
      //}
      //
      //{
      //   static char const dataType1NameAsArray[]( "TPetroleumStatusReportDownloader" );
      //
      //   // This is inefficient and I am OK with that.
      //   if( dataTypeName.compare( 0U, dataTypeName.length(), dataType1NameAsArray, ( sizeof( dataType1NameAsArray ) / sizeof( dataType1NameAsArray[ 0U ] ) - 1U ) ) == 0 )
      //
      //   {
      //      economicReportReceiverFactoryConfiguration1.DataTypeCode = TEconomicReportReceiverTypeCode_TPetroleumStatusReportDownloader;
      //      TPetroleumStatusReportDownloaderConfiguration * petroleumStatusReportDownloaderConfiguration1( new TPetroleumStatusReportDownloaderConfiguration );
      //      economicReportReceiverFactoryConfiguration1.DataTypeConfiguration.reset( petroleumStatusReportDownloaderConfiguration1 );
      //      TPetroleumStatusReportDownloaderConfigurationHelpers::ExtractConfiguration
      //         ( ( * petroleumStatusReportDownloaderConfiguration1 ), ( * abstractConfiguration1View1 ) );
      //      return;
      //   }
      //}
      //
      //{
      //   //YURIYGULYAYEV_COMMON_CODEOPTIMIZATION_UNREACHABLE();
      //   >>>Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
      //   static char const constantString1AsArray[]( "Critical; {Prototype52::TEconomicReportReceiverFactoryConfigurationHelpers::ExtractConfiguration} failed" );
      //   throw ::Common::ErrorHandling::TCriticalErrorException( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ), 0 );
      //}
   }

#endif
}
