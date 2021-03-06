#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace WarmUp
{
   // yg? Consider renaming this class and its namespace to {TCodeWarmUpHelpers}, like the {CodeOptimization} namespace.
   // yg? But as I wrote in a comment there it's unclear which code we refer to, so maybe it should be "binary code".
   // yg? Consider renaming this class and its namespace to {TWarmingUp...}. I don't like this idea.

   class TWarmUpHelpers abstract sealed
   {
#if( /* {private TLifeTimeScope_}. */ 1 )

      // yg? I don't like this class name.

      private: class TLifeTimeScope_
      {
   #if( /* {public} Instance default constructor. */ 1 )

         //
      
         public: explicit TLifeTimeScope_();

   #endif
   #if( /* {private} Instance copy constructor. */ 1 )

         //

         private: explicit TLifeTimeScope_
            ( TLifeTimeScope_ const & source
            );

   #endif
   #if( /* {public} Instance destructor. */ 1 )

         //

         public: ~TLifeTimeScope_();

   #endif
   #if( /* {private operator =}. */ 1 )

         //

         private: TLifeTimeScope_ & operator =
            ( TLifeTimeScope_ const & source
            );

   #endif
      };

#endif

#if( /* {private LifeTimeScope_}. */ 1 )

      //
      private: static TLifeTimeScope_ LifeTimeScope_;

#endif

#if( /* {public WarmUpState}. */ 1 )

      // Any code that is designed for warm-up only and is not intended to have any side effects is welcome to change this field
      // to make it appear that it does have a side effect. This is needed to prevent over-optimization.
      // yg? Consider renaming this field to {WarmUpDummyState}.
      public: static int WarmUpState;

#endif

#if( /* //{(private)} Instance default constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif
   };
}
}
