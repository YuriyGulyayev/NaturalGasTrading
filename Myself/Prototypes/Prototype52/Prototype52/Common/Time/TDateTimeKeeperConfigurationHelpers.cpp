#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TDateTimeKeeperConfigurationHelpers.hpp"

#include "./TDateTimeKeeperConfiguration.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Time
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

   void TDateTimeKeeperConfigurationHelpers::ExtractConfiguration
      ( TDateTimeKeeperConfiguration & dateTimeKeeperConfiguration1,
        ::Poco::Util::AbstractConfiguration const & abstractConfiguration1
      )
   {
      {
         static char const parameter1NameAsArray[]( "TimerTickIntervalMillisecondsDeviation" );
         dateTimeKeeperConfiguration1.TimerTickIntervalMillisecondsDeviation = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "DateTimeTickLagMilliseconds" );
         dateTimeKeeperConfiguration1.DateTimeTickLagMilliseconds = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor1" );

         // yg? There is no such thing as {getUInt}. A large value will overflow and an exception will be thrown.
         dateTimeKeeperConfiguration1.Factor1 = static_cast< unsigned int >( abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor2" );

         //// yg? There is no such thing as {getInt64}. A large value will overflow and an exception will be thrown.
         //// yg? Consider to workaround this with {getDouble}. In that case we would need to cast the {double} value to {::Poco::Int64} and back to {double}
         //// yg? and compare with the original {double} -- to be done by a helper method.
         //dateTimeKeeperConfiguration1.Factor2 = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );

         dateTimeKeeperConfiguration1.Factor2 = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor3" );
         dateTimeKeeperConfiguration1.Factor3 = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor4" );
         dateTimeKeeperConfiguration1.Factor4 = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor5" );
         dateTimeKeeperConfiguration1.Factor5 = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor6" );
         dateTimeKeeperConfiguration1.Factor6 = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor7" );
         dateTimeKeeperConfiguration1.Factor7 = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor8" );
         dateTimeKeeperConfiguration1.Factor8 = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor9" );
         dateTimeKeeperConfiguration1.Factor9 = abstractConfiguration1.getInt( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
      {
         static char const parameter1NameAsArray[]( "Factor10" );
         dateTimeKeeperConfiguration1.Factor10 = abstractConfiguration1.getDouble( ::std::string( parameter1NameAsArray, ( sizeof( parameter1NameAsArray ) / sizeof( parameter1NameAsArray[ 0U ] ) - 1U ) ) );
      }
   }

#endif
}
}
