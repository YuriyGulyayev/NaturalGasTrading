#pragma once

#if( defined( _MSC_VER ) )
   #if( _MSC_VER != 1600 )
      #error yg?? Revisit these warnings. Try using the compiler "/Wall" option.
   #endif

   #pragma warning( disable: 4480 )
   #pragma warning( disable: 4481 )
   #pragma warning( disable: 4482 )
#endif

#if( defined( NDEBUG ) == defined( _DEBUG ) )
   #error ...
#endif

#if( 1 )
   #define YURIYGULYAYEV_TESTMODECODE() 0
#else
   #pragma message( "yg?? Test mode." )
   //#define YURIYGULYAYEV_TESTMODE ***
   #define YURIYGULYAYEV_TESTMODECODE() 1
#endif

// yg?
//#if( 1 )
//   #define YURIYGULYAYEV_DIAGNOSTICSMODECODE() 0
//#else
//   #pragma message( "yg?? Diagnostics mode." )
//   #define YURIYGULYAYEV_DIAGNOSTICSMODECODE() 1
//#endif

//#define YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONBALANCE() 0
//
//// A 3rd party application shall define this as 1 and include our ".cpp" files. A number greater than 1 would actually be better to catch some bugs.
//// Then it shall redefine this as 0 to be used in its own code.
//#define YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() 1

#if( defined( _MSC_VER ) )
   #if( _MSC_VER != 1600 )
      #error yg?? Revisit these warnings. Try using the compiler "/Wall" option.
   #endif

   #pragma warning( push )
   #pragma warning( disable: 4100 )
   #pragma warning( disable: 4512 )
   #pragma warning( disable: 4702 )
#endif

#if( defined( _MSC_VER ) )
   #if( _MSC_VER != 1600 )
      #error yg?? Copy the latest version of these from <Windows.h> .
   #endif

   // These constants are listed in <Windows.h> .
   #define NOGDICAPMASKS     // CC_*, LC_*, PC_*, CP_*, TC_*, RC_
   #define NOVIRTUALKEYCODES // VK_*
   #define NOWINMESSAGES     // WM_*, EM_*, LB_*, CB_*
   #define NOWINSTYLES       // WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
   #define NOSYSMETRICS      // SM_*
   #define NOMENUS           // MF_*
   #define NOICONS           // IDI_*
   #define NOKEYSTATES       // MK_*
   #define NOSYSCOMMANDS     // SC_*
   #define NORASTEROPS       // Binary and Tertiary raster ops
   #define NOSHOWWINDOW      // SW_*
   //#define OEMRESOURCE       // OEM Resource values
   #define NOATOM            // Atom Manager routines
   #define NOCLIPBOARD       // Clipboard routines
   #define NOCOLOR           // Screen colors
   #define NOCTLMGR          // Control and Dialog routines
   #define NODRAWTEXT        // DrawText() and DT_*
   #define NOGDI             // All GDI defines and routines
   #define NOKERNEL          // All KERNEL defines and routines
   #define NOUSER            // All USER defines and routines
   #define NONLS             // All NLS defines and routines
   #define NOMB              // MB_* and MessageBox()
   #define NOMEMMGR          // GMEM_*, LMEM_*, GHND, LHND, associated routines
   #define NOMETAFILE        // typedef METAFILEPICT
   #define NOMINMAX          // Macros min(a,b) and max(a,b)
   #define NOMSG             // typedef MSG and associated routines
   #define NOOPENFILE        // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
   #define NOSCROLL          // SB_* and scrolling routines
   #define NOSERVICE         // All Service Controller routines, SERVICE_ equates, etc.
   #define NOSOUND           // Sound driver routines
   #define NOTEXTMETRIC      // typedef TEXTMETRIC and associated routines
   #define NOWH              // SetWindowsHook and WH_*
   #define NOWINOFFSETS      // GWL_*, GCL_*, associated routines
   #define NOCOMM            // COMM driver routines
   #define NOKANJI           // Kanji support stuff.
   #define NOHELP            // Help engine interface.
   #define NOPROFILER        // Profiler interface.
   #define NODEFERWINDOWPOS  // DeferWindowPos routines
   #define NOMCX             // Modem Configuration Extensions

   #define STRICT

   // yg? For some reason this has no effect if we define it after we include Windows headers and before we include CRT headers.
   #define _CRT_SECURE_NO_WARNINGS

   #include "./TargetVer.h"

   // This includes <Windows.h> .
   // This does not include <WinSock.h> .
   #include <WinSock2.h>

   #include <MSTcpIP.h>
#elif( defined( __GNUC__ ) )
   #error yg?? ToDo
#else
   #error ...
#endif

////#include <crtdbg.h>
////#include <sys/param.h>
////#include <tchar.h>
#include <cstdint>
//#include <cstddef>
//#include <cctype>
//#include <ctime>
//#include <cmath>
#include <clocale>
//#include <cstdlib>
//#include <cstdio>
#include <cassert>

//#include <type_traits>
//#include <limits>
//#include <iterator>
//#include <algorithm>
//#include <memory>
//#include <utility>
//#include <valarray>
//#include <map>
//#include <locale>
//#include <sstream>
//#include <iostream>
//#include <iomanip>

#include <Poco/Version.h>
#include <Poco/ErrorHandler.h>
#include <Poco/Process.h>
//#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/Delegate.h>
//#include <Poco/BasicEvent.h>
//#include <Poco/Timer.h>

// TODO 3 yg? This is poorly documented but should be revisited. Use this instead of {::Poco::Timespan::MILLISECONDS}, etc.
//#include <Poco/Util/Units.h>

#include <Poco/LineEndingConverter.h>
//#include <Poco/Format.h>

// yg? This class unconditionally uses current thread locale. Although in some cases it might use the classic C locale.
// yg? The configuration related code uses this class internally.
//#include <Poco/NumberFormatter.h>

// yg? This class unconditionally uses current thread locale. Although in some cases it might use the classic C locale.
// yg? The configuration related code uses this class internally.
//#include <Poco/NumberParser.h>

// yg? This class is inefficient. I should instead code some formattings more efficiently.
// yg? This class unconditionally uses current thread locale. Although in some cases it might use the classic C locale.
// yg? The configuration related code uses this class internally.
#include <Poco/DateTimeFormatter.h>

// yg? This class unconditionally uses current thread locale. Although in some cases it might use the classic C locale.
// yg? The configuration related code uses this class internally.
#include <Poco/DateTimeParser.h>

//// yg? The <regex> header could be a better option.
////#include <Poco/RegularExpression.h>

#include <Poco/URI.h>
#include <Poco/Net/NetException.h>
//#include <Poco/Net/DatagramSocketImpl.h>
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/StreamSocketImpl.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Util/Application.h>

#include <RApi.h>

#if( defined( _MSC_VER ) )
   #pragma warning( pop )
#endif

//static_assert( YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() == 1, "" );
//#undef YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH
//#define YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() 0

#if( defined( _MSC_VER ) )
   #if( _MSC_VER != 1600 )
      #error yg?? Revisit these warnings. Try using the compiler "/Wall" option.
   #endif

   // See a help page named "Compiler Warnings That Are Off by Default".
   //#pragma warning( default: 4061 )
   #pragma warning( default: 4062 )
   #pragma warning( default: 4191 )
   #pragma warning( default: 4242 )
   #pragma warning( default: 4254 )
   #pragma warning( default: 4255 )
   #pragma warning( default: 4263 )
   #pragma warning( default: 4264 )
   #pragma warning( default: 4265 )
   #pragma warning( default: 4266 )
   #pragma warning( default: 4287 )
   #pragma warning( default: 4289 )
   #pragma warning( default: 4296 )
   #pragma warning( default: 4302 )
   #pragma warning( default: 4350 )
   #pragma warning( default: 4365 )
   #pragma warning( default: 4412 )
   #pragma warning( default: 4431 )
   //#pragma warning( default: 4514 )
   #pragma warning( default: 4536 )
   #pragma warning( default: 4545 )
   #pragma warning( default: 4546 )
   #pragma warning( default: 4547 )
   #pragma warning( default: 4548 )
   #pragma warning( default: 4549 )
   #pragma warning( default: 4555 )
   #pragma warning( default: 4557 )
   //#pragma warning( default: 4571 )
   #pragma warning( default: 4619 )
   #pragma warning( default: 4623 )
   //#pragma warning( default: 4625 )
   //#pragma warning( default: 4626 )
   //#pragma warning( default: 4628 )
   #pragma warning( default: 4640 )
   #pragma warning( default: 4641 )
   #pragma warning( default: 4668 )
   #pragma warning( default: 4686 )
   #pragma warning( default: 4692 )
   //#pragma warning( default: 4710 )
   #pragma warning( default: 4711 )
   #pragma warning( default: 4738 )
   //#pragma warning( default: 4820 )
   #pragma warning( default: 4826 )
   #pragma warning( default: 4836 )
   #pragma warning( default: 4837 )
   #pragma warning( default: 4905 )
   #pragma warning( default: 4906 )
   #pragma warning( default: 4917 )
   #pragma warning( default: 4928 )
   #pragma warning( default: 4931 )
   #pragma warning( default: 4946 )
   #pragma warning( default: 4962 )

   // yg? We don't currently need {#pragma pointers_to_members}.
#endif

#if( defined( _MSC_VER ) )
   #if( _MSC_VER != 1600 )
      #error yg?? Revisit what sections' params are to be changed in the linker configuration. See the linker's "/SECTION" option.
   #endif
#else
   #error yg?? Revisit the meaning of the {volatile} keyword.
   #error yg?? Check if the "I64" format works. Check out ".../Foundation/src/NumberFormatter.cpp".
#endif

#if( defined( _MSC_VER ) )
   #if( _MSC_VER != 1600 )
      #error yg?? Remove these hacks.
      #error yg?? Use the {Interlocked...NoFence} functions. See some related hacks below.
   #endif

   #if( ! defined( NDEBUG ) )
      #undef assert

      // yg? This eliminates a compile warning.
      #define assert(_Expression) (void)( (!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), (unsigned int) __LINE__), 0) )
   #endif

   #undef FD_SET

   // yg? This eliminates a compile warning.
   // TODO 3 yg? But really don't use this bloated code.
   #define FD_SET(fd, set) do { \
      u_int __i; \
      for (__i = 0; __i < ((fd_set FAR *)(set))->fd_count; __i++) { \
         if (((fd_set FAR *)(set))->fd_array[__i] == (fd)) { \
            break; \
         } \
      } \
      if (__i == ((fd_set FAR *)(set))->fd_count) { \
         if (((fd_set FAR *)(set))->fd_count < FD_SETSIZE) { \
            ((fd_set FAR *)(set))->fd_array[__i] = (fd); \
            ((fd_set FAR *)(set))->fd_count++; \
         } \
      } \
   } while((void)0,0)

   #if( defined( _M_IX86 ) || defined( _M_X64 ) )
      // yg? It looks like they forgot to add these.
      // yg? These should really be inline functions.
      #define InterlockedExchangeAcquire( a1, a2 ) InterlockedExchange( a1, a2 )
      #define InterlockedExchangeRelease( a1, a2 ) InterlockedExchange( a1, a2 )
   #else
      #error yg?? ToDo
   #endif

   // yg? These should really be inline functions.
   #define InterlockedIncrementNoFence( a1 ) InterlockedIncrementAcquire( a1 )
   #define InterlockedDecrementNoFence( a1 ) InterlockedDecrementAcquire( a1 )
   #define InterlockedExchangeNoFence( a1, a2 ) InterlockedExchangeAcquire( a1, a2 )
   #define InterlockedCompareExchangeNoFence( a1, a2, a3 ) InterlockedCompareExchangeAcquire( a1, a2, a3 )
   #define InterlockedCompareExchangePointerNoFence( a1, a2, a3 ) InterlockedCompareExchangePointerAcquire( a1, a2, a3 )
#endif

//#if( ! defined( YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH ) )
//   #define YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() 0
//#else
//   static_assert( YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() == 1, "" );
//#endif

// An application that uses our ".hpp" and ".cpp" files together with a binary library shall have a precompiled header file that
// defines this macro as 1, includes our ".cpp" files, and optionally redefines this macro as 0 in case the application itself needs it.
#define YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() 0

#define YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONBALANCE() 0
