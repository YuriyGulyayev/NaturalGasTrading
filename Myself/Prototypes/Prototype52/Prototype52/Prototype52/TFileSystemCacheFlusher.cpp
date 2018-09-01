#pragma once

#include "StdAfx.h"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TFileSystemCacheFlusher.hpp"

#include "./TFileSystemCacheFlusherConfiguration.cpp"

#include "../Common/SourceCodeModel/SourceFooter.hpp"

namespace Prototype52
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TFileSystemCacheFlusher::TFileSystemCacheFlusher()
   {
   }

#endif
#if( /* {private} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TFileSystemCacheFlusher::TFileSystemCacheFlusher
      ( TFileSystemCacheFlusherConfiguration && configuration1
      ) :
      FileSystemCacheFlushingApplicationFilePathName_( ::std::move( configuration1.FileSystemCacheFlushingApplicationFilePathName ) )
   {
      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {private operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Not implemented.

#endif

#if( /* {public Initialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TFileSystemCacheFlusher::Initialize
      ( TFileSystemCacheFlusherConfiguration && configuration1
      )
   {
      FileSystemCacheFlushingApplicationFilePathName_.assign
         ( ::std::move( configuration1.FileSystemCacheFlushingApplicationFilePathName ) );

      DoInitialize( /*::std::move( configuration1 )*/ );
   }

#endif
#if( /* {private DoInitialize}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TFileSystemCacheFlusher::DoInitialize
      ( //TFileSystemCacheFlusherConfiguration && configuration1
      )
   {
   }

#endif
#if( /* {public AsyncRun}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TFileSystemCacheFlusher::AsyncRun()
   {
      //#pragma message( "yg---?? Test." )
      //::Poco::Util::Application::instance().logger().information( "dummy 1" );

      // "sync.exe" output appears in the same console window.
      // Otherwise it would probably be better to launch it minimized.
      // It would be more efficient to create a {::Poco::Process::Args} in advance but this code is not performance critical.
      ::Poco::Process::launch( FileSystemCacheFlushingApplicationFilePathName_, ::Poco::Process::Args() );

      //#pragma message( "yg---?? Test." )
      //::Poco::Util::Application::instance().logger().information( "dummy 2" );
   }

#endif
}
