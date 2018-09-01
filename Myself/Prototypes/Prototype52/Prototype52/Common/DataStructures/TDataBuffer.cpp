#pragma once

#include "StdAfx.h"

#include "../SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./TDataBuffer.hpp"

#include "../ErrorHandling/TRegularErrorException.cpp"
#include "../Diagnostics/Macros.cpp"
#include "../Diagnostics/TDiagnosticsHelpers.cpp"

#include "../SourceCodeModel/SourceFooter.hpp"

namespace Common
{
namespace DataStructures
{
#if( /* {public} Instance default constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer::TDataBuffer() :
      DataLength( 0U )
   {
   }

#endif
#if( /* {public} Instance copy constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer::TDataBuffer
      ( TDataBuffer const & source
      ) :
      // yg? This doesn't guarantee to reserve the capacity allocated for {source}.
      // yg? It's probably OK as the caller can use other constructors to accomplish that.
      ::std::string( source ),

      // yg? And this does. But this can populate the end of the buffer with garbage, although it will probably populate it with zeros.
      //::std::string( source.data(), source.capacity() ),

      //::std::string( source.data(), source.length() ),

      DataLength( source.DataLength )
   {
      // Validating that it actually allocated new memory. If this validation fails I would have to refactor the code,
      // possibly to use another base class constructor.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( data() != source.data() );
   }

#endif
#if( /* {public} Instance move constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer::TDataBuffer
      ( TDataBuffer && source
      ) :
      ::std::string( ::std::move( source ) ),
      DataLength( ::std::move( source.DataLength ) )
   {
      // We should set {source.DataLength = 0U} but {source} is now a zomby object whose state is undefined.
   }

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer::TDataBuffer
      ( size_type stringLength
      ) :
      ::std::string( stringLength, value_type() ),
      DataLength( 0U )
   {
   }

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer::TDataBuffer
      ( size_type data1Length,
        value_type char1
      ) :
      ::std::string( data1Length, char1 ),
      DataLength( data1Length )
   {
   }

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer::TDataBuffer
      ( const_pointer data1,
        size_type data1Length
      ) :
      ::std::string( data1, data1Length ),
      DataLength( data1Length )
   {
      // Validating that it actually allocated new memory. If this validation fails I would have to refactor the code,
      // possibly to use another base class constructor.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( data() != data1 );
   }

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer::TDataBuffer
      ( ::std::string const & data1
      ) :
      // yg? This doesn't guarantee to reserve the capacity allocated for {data1}.
      // yg? It's probably OK as the caller can use other constructors to accomplish that.
      ::std::string( data1 ),

      // yg? And this does. But this can populate the end of the buffer with garbage, although it will probably populate it with zeros.
      //::std::string( data1.data(), data1.capacity() ),

      //::std::string( data1.data(), data1.length() ),

      //DataLength( data1.length() )
      DataLength( length() )
   {
      // Validating that it actually allocated new memory. If this validation fails I would have to refactor the code,
      // possibly to use another base class constructor.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( data() != data1.data() );

      // Let's confirm that when we used {length()} in the initialization list it was already valid.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( length() == DataLength );
   }

#endif
#if( /* {public} Instance constructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer::TDataBuffer
      ( ::std::string && data1
      ) :
      ::std::string( ::std::move( data1 ) ),
      DataLength( length() )
   {
      // Let's confirm that when we used {length()} in the initialization list it was already valid.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( length() == DataLength );
   }

#endif
#if( /* {(public)} Instance destructor. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   // Placeholder.

#endif
#if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer & TDataBuffer::operator =
      ( TDataBuffer const & source
      )
   {
      Assign( source );
      return ( * this );
   }

#endif
#if( /* {public operator =}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline TDataBuffer & TDataBuffer::operator =
      ( TDataBuffer && source
      )
   {
      Assign( ::std::move( source ) );
      return ( * this );
   }

#endif

#if( /* {public AllocateAdditionalCapacityIfNeeded}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   void TDataBuffer::AllocateAdditionalCapacityIfNeeded
      ( size_type additionalCapacity,
        size_type additionalCapacityMinLimit,
        size_type capacityMaxLimit
      )
   {
      // These conditions are always {true}.
      //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( additionalCapacity >= 0U );
      //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( additionalCapacityMinLimit >= 0U );
      //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( capacityMaxLimit >= 0U );

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( additionalCapacity >= additionalCapacityMinLimit );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( capacityMaxLimit <= max_size() );

      {
         // It's probably not inherently necessary to demand this state validity but otherwise
         // the code would have to be more convoluted and less efficient.
         YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataLength <= length() );

         // This can't overflow because of the preceeding varidation.
         size_type additionalCapacityToAllocate( length() - DataLength );

         // This condition is guaranteed to be {true} if {additionalCapacity == 0U}.
         if( additionalCapacityToAllocate >= additionalCapacity )

         {
            //Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            return;
         }
         else
// TODO 2 yg? Test code below this point.
         {
            //Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

            // We can get to this point only if this is {true}.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( additionalCapacity > 0U );

            if( capacityMaxLimit > length() )
            {
               //Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

               // This condition is {true} since we validated that {length() >= DataLength}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( capacityMaxLimit > DataLength );

               // This is positive and can't overflow because of the preceeding varidation.
               additionalCapacityToAllocate = capacityMaxLimit - DataLength;

               // This would probably work even with the { > } operator but in case these values are equal more code would run before
               // {resize}. Also an {..._ASSUME} below would not be valid.
               if( additionalCapacityToAllocate >= additionalCapacity )

               {
                  //Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                  additionalCapacityToAllocate = additionalCapacity;

                  // We will allocate additional memory.
                  // We would not allocate additional memory if {additionalCapacity == 0U} but it's impossible, which we validated above.
                  // This might act as an optimization hint for {resize}.
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataLength + additionalCapacityToAllocate > length() );
                  
                  goto label1;
               }
               else
               {
                  Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

                  // We will allocate additional memory unless we throw an exception.
                  // This might act as an optimization hint for {resize}.
                  YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataLength + additionalCapacityToAllocate > length() );
               }
            }
            else
            {
               Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

               // The behavior will be the same as if {capacityMaxLimit == length()}.
               // We will not allocate additional memory.
               // This might act as an optimization hint for {resize}.
               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataLength + additionalCapacityToAllocate == length() );
            }

            // If this condition was {false} we would have jumped to {label1}.
            YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( additionalCapacityToAllocate < additionalCapacity );

            // As we have just validated, we can't allocate as much memory as we want. So now we need to check
            // if we can make available capacity at least {additionalCapacityMinLimit}.
            // This condition is guaranteed to be {true} if {additionalCapacityMinLimit == 0U}.
            if( additionalCapacityToAllocate >= additionalCapacityMinLimit )

            {
               Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();

            label1:
               resize( DataLength + additionalCapacityToAllocate );

               YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( additionalCapacityToAllocate <= additionalCapacity );
               if( additionalCapacityToAllocate >= additionalCapacity )
               {
                  //Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
                  Diagnostics::TDiagnosticsHelpers::DummyMethod();
               }
               else
               {
                  {
                     static char const constantString1AsArray[]( "allocated less for a {Common::DataStructures::TDataBuffer} than needed" );
                     ::Poco::Logger & logger1( ::Poco::Util::Application::instance().logger() );

                     // One might argue that this should be marked "Error" as it should really never happen
                     // and would require developer/user attention but from the {AllocateAdditionalCapacityIfNeeded} method point of view
                     // this problem is not that bad.
                     logger1.warning( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ) );
                  }

                  Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
               }

               return;
            }
            else
            {
               Diagnostics::TDiagnosticsHelpers::DummyMethodWithBreakPoint();
            }
         }
      }

      {
         static char const constantString1AsArray[]( "Error; {Common::DataStructures::TDataBuffer} is full" );

         // yg? We might need to throw a more specialized exception.
         throw ErrorHandling::TRegularErrorException
                      ( ::std::string( constantString1AsArray, ( sizeof( constantString1AsArray ) / sizeof( constantString1AsArray[ 0U ] ) - 1U ) ),
                        0
                      );
      }
   }

#endif

#if( /* {public Assign}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TDataBuffer::Assign
      ( TDataBuffer const & source
      )
   {
      // This implementation will survive a self-assignment.

      // yg? This doesn't guarantee to reserve the capacity allocated for {source}.
      // yg? See related comments in constructors above.
      assign( source );

      DataLength = source.DataLength;

      // Validating that it actually allocated new memory. If this validation fails I would have to refactor the code,
      // possibly to use another base class constructor.
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( this == ( & source ) || data() != source.data() );
   }

#endif
#if( /* {public Assign}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TDataBuffer::Assign
      ( TDataBuffer && source
      )
   {
      // This implementation will survive a self-assignment.

      assign( ::std::move( source ) );
      DataLength = ::std::move( source.DataLength );

      // We should set {source.DataLength = 0U} unless we are being self-assigned
      // but {source} is now a zomby object whose state is undefined.
   }

#endif
#if( /* {public Assign}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TDataBuffer::Assign
      ( const_pointer data1,
        size_type data1Length
      )
   {
      // It's undefined if this implementation will survive a self-assignment.
      // It might actually survive it because there is no need to allocate new memory.
      // So we will not validate that it actually allocated new memory.

      //YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataLength <= length() );
      replace( 0U, data1Length, data1, data1Length );
      DataLength = data1Length;
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataLength <= length() );
   }

#endif
#if( /* {public Append}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline void TDataBuffer::Append
      ( const_pointer data1,
        size_type data1Length
      )
   {
      // It's undefined if this implementation will survive a self-append.
      // If {DataLength == 0U} the result would be the same as the above {Assign}
      // and the self-assignment related comments would stand.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataLength <= length() );
      replace( DataLength, data1Length, data1, data1Length );

      // This will not overflow and will not exceed {max_size()} provided the {replace} method succeeded.
      DataLength += data1Length;

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( DataLength <= length() );
   }

#endif

#if( /* {public LessThan}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool TDataBuffer::LessThan
      ( TDataBuffer const & instance1,
        TDataBuffer const & instance2
      )
   {
      // This implementation doesn't ensure sorting by string comparison.

      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( instance1.DataLength <= instance1.length() );
      YURIYGULYAYEV_COMMON_DIAGNOSTICS_ASSUME( instance2.DataLength <= instance2.length() );

      if( instance1.DataLength != instance2.DataLength )
      {
         return ( instance1.DataLength < instance2.DataLength );
      }
      else
      {
         return ( traits_type::compare( instance1.data(), instance2.data(), instance1.DataLength ) < 0 );
      }
   }

#endif

#if( /* {public operator <}. */ 0 < YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

   inline bool operator <
      ( TDataBuffer const & instance1,
        TDataBuffer const & instance2
      )
   {
      return TDataBuffer::LessThan( instance1, instance2 );
   }

#endif
}
}
