#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TMemoryAtomicOperationsHelpers.hpp"

//#include "./.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace Threading
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

#if( /* //{public MemoryAcquireBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TMemoryAtomicOperationsHelpers::MemoryAcquireBarrier()
   //{
   //#if( defined( _MSC_VER ) )
   //   // yg? Acquire-only memory barrier is not supported.
   //   ::MemoryBarrier();
   //#elif( defined( __GNUC__ ) )
   //   #error yg?? ToDo
   //#else
   //   #error ...
   //#endif
   //}

#endif
#if( /* //{public MemoryReleaseBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TMemoryAtomicOperationsHelpers::MemoryReleaseBarrier()
   //{
   //#if( defined( _MSC_VER ) )
   //   // yg? Release-only memory barrier is not supported.
   //   ::MemoryBarrier();
   //#elif( defined( __GNUC__ ) )
   //   #error yg?? ToDo
   //#else
   //   #error ...
   //#endif
   //}

#endif
#if( /* //{public MemoryFullBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TMemoryAtomicOperationsHelpers::MemoryFullBarrier()
   //{
   //#if( defined( _MSC_VER ) )
   //   ::MemoryBarrier();
   //#elif( defined( __GNUC__ ) )
   //   #error yg?? ToDo
   //#else
   //   #error ...
   //#endif
   //}

#endif

#if( /* //{public GetValue}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline int TMemoryAtomicOperationsHelpers::GetValue
   //   ( int /*volatile*/ const & value
   //   )
   //{
   //   MemoryReleaseBarrier();
   //   return value;
   //}

#endif
#if( /* //{public SetValue}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   //inline void TMemoryAtomicOperationsHelpers::SetValue
   //   ( int /*volatile*/ & destinationValue,
   //     int sourceValue
   //   )
   //{
   //   destinationValue = sourceValue;
   //   MemoryReleaseBarrier();
   //}

#endif

#if( /* {public GetAndSetValueWithMemoryAcquireBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::GetAndSetValueWithMemoryAcquireBarrier
      ( int /*volatile*/ & destinationValue,
        int sourceValue
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( destinationValue ) == sizeof( ::LONG ), "" );
      return ::InterlockedExchangeAcquire( reinterpret_cast< ::LONG * >( & destinationValue ), sourceValue );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public GetAndSetValueIfEqualsWithMemoryAcquireBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::GetAndSetValueIfEqualsWithMemoryAcquireBarrier
      ( int /*volatile*/ & destinationValue,
        int sourceValue,
        int destinationValueComperand
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( destinationValue ) == sizeof( ::LONG ), "" );
      return ::InterlockedCompareExchangeAcquire
                    ( reinterpret_cast< ::LONG * >( & destinationValue ), sourceValue, destinationValueComperand );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public GetAndSetValueIfEqualsWithMemoryAcquireBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void * TMemoryAtomicOperationsHelpers::GetAndSetValueIfEqualsWithMemoryAcquireBarrier
      ( void * /*volatile*/ & destinationValue,
        void * sourceValue,
        void * destinationValueComperand
      )
   {
   #if( defined( _MSC_VER ) )
      // This would issue a compile error or warning if {::PVOID} is not the same as {void *}.
      return ::InterlockedCompareExchangePointerAcquire( ( & destinationValue ), sourceValue, destinationValueComperand );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public IncrementAndGetValueWithMemoryAcquireBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::IncrementAndGetValueWithMemoryAcquireBarrier
      ( int /*volatile*/ & value1
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( value1 ) == sizeof( ::LONG ), "" );
      return ::InterlockedIncrementAcquire( reinterpret_cast< ::LONG * >( & value1 ) );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public DecrementAndGetValueWithMemoryAcquireBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::DecrementAndGetValueWithMemoryAcquireBarrier
      ( int /*volatile*/ & value1
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( value1 ) == sizeof( ::LONG ), "" );
      return ::InterlockedDecrementAcquire( reinterpret_cast< ::LONG * >( & value1 ) );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public GetAndSetValueWithMemoryReleaseBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::GetAndSetValueWithMemoryReleaseBarrier
      ( int /*volatile*/ & destinationValue,
        int sourceValue
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( destinationValue ) == sizeof( ::LONG ), "" );
      return ::InterlockedExchangeRelease( reinterpret_cast< ::LONG * >( & destinationValue ), sourceValue );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public GetAndSetValueIfEqualsWithMemoryReleaseBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::GetAndSetValueIfEqualsWithMemoryReleaseBarrier
      ( int /*volatile*/ & destinationValue,
        int sourceValue,
        int destinationValueComperand
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( destinationValue ) == sizeof( ::LONG ), "" );
      return ::InterlockedCompareExchangeRelease
                    ( reinterpret_cast< ::LONG * >( & destinationValue ), sourceValue, destinationValueComperand );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public GetAndSetValueIfEqualsWithMemoryReleaseBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void * TMemoryAtomicOperationsHelpers::GetAndSetValueIfEqualsWithMemoryReleaseBarrier
      ( void * /*volatile*/ & destinationValue,
        void * sourceValue,
        void * destinationValueComperand
      )
   {
   #if( defined( _MSC_VER ) )
      // This would issue a compile error or warning if {::PVOID} is not the same as {void *}.
      return ::InterlockedCompareExchangePointerRelease( ( & destinationValue ), sourceValue, destinationValueComperand );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public IncrementAndGetValueWithMemoryReleaseBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::IncrementAndGetValueWithMemoryReleaseBarrier
      ( int /*volatile*/ & value1
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( value1 ) == sizeof( ::LONG ), "" );
      return ::InterlockedIncrementRelease( reinterpret_cast< ::LONG * >( & value1 ) );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public DecrementAndGetValueWithMemoryReleaseBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::DecrementAndGetValueWithMemoryReleaseBarrier
      ( int /*volatile*/ & value1
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( value1 ) == sizeof( ::LONG ), "" );
      return ::InterlockedDecrementRelease( reinterpret_cast< ::LONG * >( & value1 ) );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public GetAndSetValueWithoutMemoryBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::GetAndSetValueWithoutMemoryBarrier
      ( int /*volatile*/ & destinationValue,
        int sourceValue
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( destinationValue ) == sizeof( ::LONG ), "" );
      return ::InterlockedExchangeNoFence( reinterpret_cast< ::LONG * >( & destinationValue ), sourceValue );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public GetAndSetValueIfEqualsWithoutMemoryBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::GetAndSetValueIfEqualsWithoutMemoryBarrier
      ( int /*volatile*/ & destinationValue,
        int sourceValue,
        int destinationValueComperand
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( destinationValue ) == sizeof( ::LONG ), "" );
      return ::InterlockedCompareExchangeNoFence
                    ( reinterpret_cast< ::LONG * >( & destinationValue ), sourceValue, destinationValueComperand );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public GetAndSetValueIfEqualsWithoutMemoryBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void * TMemoryAtomicOperationsHelpers::GetAndSetValueIfEqualsWithoutMemoryBarrier
      ( void * /*volatile*/ & destinationValue,
        void * sourceValue,
        void * destinationValueComperand
      )
   {
   #if( defined( _MSC_VER ) )
      // This would issue a compile error or warning if {::PVOID} is not the same as {void *}.
      return ::InterlockedCompareExchangePointerNoFence( ( & destinationValue ), sourceValue, destinationValueComperand );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public IncrementAndGetValueWithoutMemoryBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::IncrementAndGetValueWithoutMemoryBarrier
      ( int /*volatile*/ & value1
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( value1 ) == sizeof( ::LONG ), "" );
      return ::InterlockedIncrementNoFence( reinterpret_cast< ::LONG * >( & value1 ) );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
#if( /* {public DecrementAndGetValueWithoutMemoryBarrier}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline int TMemoryAtomicOperationsHelpers::DecrementAndGetValueWithoutMemoryBarrier
      ( int /*volatile*/ & value1
      )
   {
   #if( defined( _MSC_VER ) )
      static_assert( sizeof( value1 ) == sizeof( ::LONG ), "" );
      return ::InterlockedDecrementNoFence( reinterpret_cast< ::LONG * >( & value1 ) );
   #elif( defined( __GNUC__ ) )
      #error yg?? ToDo
   #else
      #error ...
   #endif
   }

#endif
}
}
