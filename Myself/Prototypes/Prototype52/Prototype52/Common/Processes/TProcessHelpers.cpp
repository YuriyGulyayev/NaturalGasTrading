#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TProcessHelpers.hpp"

#include "../Diagnostics/TDiagnosticsHelpers.cpp"
#include "../Globalization/TGlobalizationHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Processes
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

#if( /* {public TrySetProcessWorkingSetSize}. */ defined( _MSC_VER ) && 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   ::BOOL TProcessHelpers::TrySetProcessWorkingSetSize
      ( __in ::HANDLE hProcess,
        __in ::SIZE_T dwMinimumWorkingSetSize,
        __in ::SIZE_T dwMaximumWorkingSetSize
      )
   {
      ::BOOL isSuccess( ::SetProcessWorkingSetSize( hProcess, dwMinimumWorkingSetSize, dwMaximumWorkingSetSize ) );

      if( isSuccess != FALSE )
      {
         Diagnostics::TDiagnosticsHelpers::DummyMethod();
      }
      else
      {
         ::DWORD lastErrorCode( ::GetLastError() );

         {
            static_assert( sizeof( lastErrorCode ) == sizeof( unsigned long ), "" );
            static char const formatConstantString1AsArray[]( "{SetProcessWorkingSetSize} failed; 0x%lX" );
            int const tempString1BufferLength( 64 );
            ::std::string tempString1( static_cast< unsigned int >( tempString1BufferLength ), '\x00' );

            int tempString1Length
               ( ::_snprintf_l
                    ( ( & tempString1.front() ),
                      static_cast< unsigned int >( tempString1BufferLength ),
                      formatConstantString1AsArray,
                      Globalization::TGlobalizationHelpers::CInvariantLocale,
                      lastErrorCode
                    )
               );

            if( tempString1Length >= 0 )
            {
               tempString1.resize( static_cast< unsigned int >( tempString1Length ) );
            }
            else
            {
               Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               tempString1.assign( formatConstantString1AsArray, ( sizeof( formatConstantString1AsArray ) / sizeof( formatConstantString1AsArray[ 0U ] ) - 1U ) );
            }
      
            ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );
            logger1.error( tempString1 );
         }
      }

      return isSuccess;
   }

#endif
}
}
