#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TEntryOrderConfigurationHelpers.hpp"

#include "./TEntryOrderConfiguration.cpp"
#include "../Common/Diagnostics/Macros.cpp"

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

   void TEntryOrderConfigurationHelpers::ExtractConfiguration
      ( TEntryOrderConfiguration & entryOrderConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      //{
      //   static char const parameter1NameAsArray[]( "TypeCode" );
////>>> Call {....getChar}?
      //   entryOrderConfiguration1.TypeCode = static_cast< ::RApiFacade::TOrderTypeCode >( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      //}

      {
         static char const parameter1NameAsArray[]( "Quantity" );
         entryOrderConfiguration1.Quantity =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      
      {
         static char const parameter1NameAsArray[]( "TriggerPriceOffset1" );
         entryOrderConfiguration1.TriggerPriceOffset1 =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      {
         static char const parameter1NameAsArray[]( "TriggerPriceOffset2" );
         entryOrderConfiguration1.TriggerPriceOffset2 =
            abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }

      //{
      //   static char const parameter1NameAsArray[]( "LimitPriceOffset" );
      //   entryOrderConfiguration1.LimitPriceOffset =
      //      abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      //}

      //{
      //   static char const parameter1NameAsArray[]( "GoodForTimeSpanMilliseconds" );
      //   entryOrderConfiguration1.GoodForTimeSpanMilliseconds =
      //      abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      //}
   }

#endif
#if( /* {public ExtractConfigurations}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TEntryOrderConfigurationHelpers::ExtractConfigurations
      ( ::std::vector< TEntryOrderConfiguration > & entryOrdersConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      ::Poco::Util::AbstractConfiguration::Keys keys;
      abstractConfiguration1.keys( keys );

      // Assuming the collection is initially empty and all keys in the configuration are "add".
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( entryOrdersConfiguration1.empty() );
      entryOrdersConfiguration1.resize( keys.size() );

      ::std::vector< TEntryOrderConfiguration >::iterator entryOrdersConfiguration1Iterator( entryOrdersConfiguration1.begin() );
      for( ::Poco::Util::AbstractConfiguration::Keys::const_iterator keysIterator( keys.cbegin() ) ; keysIterator != keys.cend() ; ++ keysIterator )
      {
         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( * keysIterator ) ) );

         ExtractConfiguration( ( * entryOrdersConfiguration1Iterator ), ( * abstractConfiguration1View1 ) );
         ++ entryOrdersConfiguration1Iterator;
      }
   }

#endif
}
