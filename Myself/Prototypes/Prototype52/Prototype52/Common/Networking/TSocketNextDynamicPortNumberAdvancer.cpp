#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TSocketNextDynamicPortNumberAdvancer.hpp"

#include "./TSocketNextDynamicPortNumberAdvancerConfiguration.cpp"
#include "./TNetworkingHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Networking
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSocket_
      >
   inline TSocketNextDynamicPortNumberAdvancer< TSocket_ >::TSocketNextDynamicPortNumberAdvancer()
   {
      // {TSocket_} default constructor assumes {::Poco::Net::IPAddress::Family::IPv4}.
      // Depending on which POCO socket class {TSocket_} is, it may or may not create a socket handle.
      // It would probably be more correct to not create a socket handle but keeping it simple.
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSocket_
      >
   inline TSocketNextDynamicPortNumberAdvancer< TSocket_ >::TSocketNextDynamicPortNumberAdvancer
      ( TSocketNextDynamicPortNumberAdvancerConfiguration && configuration1
      )
   {
      // See a comment in default constructor.

      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSocket_
      >
   inline void TSocketNextDynamicPortNumberAdvancer< TSocket_ >::Initialize
      ( TSocketNextDynamicPortNumberAdvancerConfiguration && configuration1
      )
   {
      DoInitialize( ::std::move( configuration1 ) );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSocket_
      >
   inline void TSocketNextDynamicPortNumberAdvancer< TSocket_ >::DoInitialize
      ( TSocketNextDynamicPortNumberAdvancerConfiguration && configuration1
      )
   {
      NumberSocketNextDynamicPortNumberIncrements_ =
         ::std::move( configuration1.NumberSocketNextDynamicPortNumberIncrements );
   }

#endif
#if( /* {public Run}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSocket_
      >
   inline void TSocketNextDynamicPortNumberAdvancer< TSocket_ >::Run
      ( //int numberLoops
      ) const
   {
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( NumberSocketNextDynamicPortNumberIncrements_ >= 0 );

      // The result of a modulo operation is not uniformly distributed -- no big deal.
      // Assuming this will not overflow.
      int numberLoops
         ( static_cast< int >
               ( ( static_cast< unsigned int >( NumberSocketNextDynamicPortNumberIncrements_ ) + 1U ) / 2U +
                 ( Math::TMultiplyWithCarryRandomNumberCommonGeneratorHelpers::MultiplyWithCarryRandomNumberCommonGenerator.GenerateMediumQuality32Bits() %
                   ( static_cast< unsigned int >( NumberSocketNextDynamicPortNumberIncrements_ ) + 1U )
                 )
               )
         );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( numberLoops >= 0 );

      while( ( -- numberLoops ) >= 0 )
      {
         // On each loop a socket is created and closed. It would be more efficient to pre-create a bunch of sockets
         // and close them later. But keeping it simple.
         // TODO 3 yg? This block should be moved to a separate method.
         {
            // A binding to a wildcard IP address appears to be a bit faster than binding to a specific local IP address.
            // yg? Assuming this will not throw an exception.
            Socket_.impl()->bind( TNetworkingHelpers::WildcardIPSocketAddress, false );

            // yg? Assuming this will not throw an exception.
            Socket_.close();
         }
      }
   }

#endif
#if( /* {public RunUntilNextMillisecond}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSocket_
      >
   inline void TSocketNextDynamicPortNumberAdvancer< TSocket_ >::RunUntilNextMillisecond() const
   {
      int currentTimeMilliseconds( Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() );

      do
      {
         // yg? See related comment in the {Run} method.
         {
            // yg? See related comment in the {Run} method.
            Socket_.impl()->bind( TNetworkingHelpers::WildcardIPSocketAddress, false );

            // yg? Assuming this will not throw an exception.
            Socket_.close();
         }
      }
      while( Time::TTimeHelpers::GetMultimediaCurrentTimeMilliseconds() == currentTimeMilliseconds );
   }

#endif

#if( /* {public NumberSocketNextDynamicPortNumberIncrements}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   template
      < typename TSocket_
      >
   inline int TSocketNextDynamicPortNumberAdvancer< TSocket_ >::NumberSocketNextDynamicPortNumberIncrements() const
   {
      return NumberSocketNextDynamicPortNumberIncrements_;
   }

#endif
}
}
