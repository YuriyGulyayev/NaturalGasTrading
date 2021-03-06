#pragma once

#include "../Common/ErrorHandling/TErrorHandlerScope.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
#if( POCO_VERSION != 0x01040601 )
   #error yg?? Check if {Poco::LoggingFactory::registerBuiltins} now supports "SimpleFileChannel". I posted this as an issue.
#endif

   //

   class TApplication :
      public ::Poco::Util::Application
   {
#if( /* {private ErrorHandlerScope_}. */ 1 )

      //
      private: ::Common::ErrorHandling::TErrorHandlerScope ErrorHandlerScope_;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TApplication();

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {(protected)} Instance destructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif

#if( /* {protected initialize}. */ 1 )

      //

      protected: virtual void initialize
         ( ::Poco::Util::Application & self
         ) override;

#endif
#if( /* {protected uninitialize}. */ 1 )

      //

      protected: virtual void uninitialize() override;

#endif
#if( /* {protected main}. */ 1 )

      //

      protected: virtual int main
         ( ::std::vector< ::std::string > const & arguments
         ) override;

#endif
   };
}
