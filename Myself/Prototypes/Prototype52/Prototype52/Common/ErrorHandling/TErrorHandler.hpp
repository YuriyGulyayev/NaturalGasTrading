#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace ErrorHandling
{
   // yg? Let's hope we will not be reentered and will not deadlock.
   // yg? I believe, this class can be called by the logger on a thread pool thread, which probably can result in a reentrancy
   // yg? and I can only hope that not much damage will be inflicted.
   // yg? Consider making this class aware of {ControlFlow::TOperationCancelledException}.
   // yg? Consider renaming this class to {TExceptionLastChanceHandler}.

   class TErrorHandler :
      public ::Poco::ErrorHandler
   {
#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TErrorHandler();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TErrorHandler
         ( TErrorHandler const & source
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // {virtual}.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TErrorHandler & operator =
         ( TErrorHandler const & source
         );

#endif

#if( /* {public exception}. */ 1 )

      //

      public: virtual void exception
         ( ::Poco::Exception const & exception1
         ) override;

#endif
#if( /* {public exception}. */ 1 )

      //

      public: virtual void exception
         ( ::std::exception const & exception1
         ) override;

#endif
#if( /* {public exception}. */ 1 )

      // yg? This method will be called on an {::OmneException}.

      public: virtual void exception() override;

#endif
   };
}
}
