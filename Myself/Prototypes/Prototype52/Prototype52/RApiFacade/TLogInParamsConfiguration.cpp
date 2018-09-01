#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TLogInParamsConfiguration.hpp"

//#include "./.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace RApiFacade
{
#if( /* {public} Instance default constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TLogInParamsConfiguration::TLogInParamsConfiguration()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance move constructor. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   TLogInParamsConfiguration::TLogInParamsConfiguration
      ( TLogInParamsConfiguration && source
      ) :
      sUser( ::std::move( source.sUser ) ),
      sPassword( ::std::move( source.sPassword ) ),
      // Not used. sIhCnnctPt( ::std::move( source.sIhCnnctPt ) ),
      sMdCnnctPt( ::std::move( source.sMdCnnctPt ) ),
      // Not used. sPnlCnnctPt( ::std::move( source.sPnlCnnctPt ) ),
      sTsCnnctPt( ::std::move( source.sTsCnnctPt ) )
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

   inline TLogInParamsConfiguration & TLogInParamsConfiguration::operator =
      ( TLogInParamsConfiguration && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public Assign}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TLogInParamsConfiguration::Assign
      ( TLogInParamsConfiguration && source
      )
   {
      // This implementation will survive a self-assignment.

      sUser.assign( ::std::move( source.sUser ) );
      sPassword.assign( ::std::move( source.sPassword ) );
      // Not used. sIhCnnctPt.assign( ::std::move( source.sIhCnnctPt ) );
      sMdCnnctPt.assign( ::std::move( source.sMdCnnctPt ) );
      // Not used. sPnlCnnctPt.assign( ::std::move( source.sPnlCnnctPt ) );
      sTsCnnctPt.assign( ::std::move( source.sTsCnnctPt ) );
   }

#endif

#if( /* {public Validate}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TLogInParamsConfiguration::Validate() const
   {
      // TODO 3 yg? 
   }

#endif
}
