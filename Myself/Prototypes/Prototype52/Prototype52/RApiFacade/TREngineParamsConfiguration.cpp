#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TREngineParamsConfiguration.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TREngineParamsConfiguration::TREngineParamsConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance move constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TREngineParamsConfiguration::TREngineParamsConfiguration
      ( TREngineParamsConfiguration && source
      ) :
      sAppName( ::std::move( source.sAppName ) ),
      sAppVersion( ::std::move( source.sAppVersion ) ),
      sAdmCnnctPt( ::std::move( source.sAdmCnnctPt ) ),
      sLogFilePath( ::std::move( source.sLogFilePath ) ),
      EnvironmentVariables( ::std::move( source.EnvironmentVariables ) ),
      envp( ::std::move( source.envp ) )
   {
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TREngineParamsConfiguration & TREngineParamsConfiguration::operator =
      ( TREngineParamsConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineParamsConfiguration::Assign
      ( TREngineParamsConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      sAppName.assign( ::std::move( source.sAppName ) );
      sAppVersion.assign( ::std::move( source.sAppVersion ) );
      sAdmCnnctPt.assign( ::std::move( source.sAdmCnnctPt ) );
      sLogFilePath.assign( ::std::move( source.sLogFilePath ) );
      EnvironmentVariables = ::std::move( source.EnvironmentVariables );
      envp = ::std::move( source.envp );
   }

#endif
#if( /* //{public Swap}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //void TREngineParamsConfiguration::Swap
   //   ( TREngineParamsConfiguration & anotherInstance
   //   )
   //{
   //   // This implementation will survive a self-swap.
   //
   //   sAppName.swap( anotherInstance.sAppName );
   //   sAppVersion.swap( anotherInstance.sAppVersion );
   //   sAdmCnnctPt.swap( anotherInstance.sAdmCnnctPt );
   //   sLogFilePath.swap( anotherInstance.sLogFilePath );
   //   EnvironmentVariables.swap( anotherInstance.EnvironmentVariables );
   //   envp.swap( anotherInstance.envp );
   //}

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TREngineParamsConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
