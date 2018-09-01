#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TConfigurationHelpers.hpp"

//#include "./.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Configuration
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

#if( /* //{public ExtractConfiguration}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //template
   //   < typename TString_
   //   >
   //inline void TConfigurationHelpers::ExtractConfiguration
   //   ( ::std::pair< TString_, int > & , //configuration1,
   //     ::Poco::Util::AbstractConfiguration const & , //abstractConfiguration1,
   //     ::std::string const & , //value1Name,
   //     ::std::string const & //value2Name
   //   )
   //{
   //}

#endif
#if( /* {public ExtractConfigurations}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TString_
      >
   inline void TConfigurationHelpers::ExtractConfigurations
      ( ::std::map< TString_, int > & configurations1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      // yg? Parameter names are hardcoded.
      static char const parameter1NameAsArray[]( "Key" );
      ::std::string parameter1Name( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) );
      static char const parameter2NameAsArray[]( "Value" );
      ::std::string parameter2Name( parameter2NameAsArray, ( sizeof( parameter2NameAsArray ) / sizeof( parameter2NameAsArray[ 0U ] ) - 1U ) );

      ::Poco::Util::AbstractConfiguration::Keys keys;
      abstractConfiguration1.keys( keys );

      // Any items already in the collection will stay in there.
      // yg? Problem is that {::std::map<,>} doesn't support capacity reservatiuon.
      //
      //// Assuming this will not overflow.
      //configurations1.reserve( configurations1.size() + keys.size() );
      //configurations1.resize( configurations1.size() + keys.size() );

      for( ::Poco::Util::AbstractConfiguration::Keys::const_iterator keysIterator( keys.cbegin() ) ; keysIterator != keys.cend() ; ++ keysIterator )
      {
         // We have to do a {const_cast} here.
         ::Poco::AutoPtr< ::Poco::Util::AbstractConfiguration /*const*/ > const abstractConfiguration1View1
            ( const_cast< ::Poco::Util::AbstractConfiguration * >( abstractConfiguration1.createView( * keysIterator ) ) );

         // Unnamed objects -- move semantics.
         // It would be pain in the ass to achieve move semantics if we used a separate method that extracts an {::std::pair}.
         // TODO 3 yg? If an element with this key already exists in the map this insertion will do nothing. We should validate that.
         configurations1.insert
            ( ::std::map< TString_, int >::value_type
                 ( // Assuming that a {TString_} can be implicitly move- or at least copy-constructed from an {::std::string}.
                   // yg? I am surprised this compiles even though all {DataStructures::TDataBuffer} constructors are declared {explicit}.
                   abstractConfiguration1View1->getString( parameter1Name ),

                   abstractConfiguration1View1->getInt( parameter2Name )
                 )
            );
      }
   }

#endif
}
}
