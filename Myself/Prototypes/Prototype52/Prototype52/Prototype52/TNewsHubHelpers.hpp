#pragma once

//#include "./.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // It would probably be problematic to move this class to another namespace. It's really related to economic report receivers.

   class TNewsHubHelpers abstract sealed
   {
#if( /* {public MessageTextHeaderLength}. */ 1 )

      //
      public: static int const MessageTextHeaderLength = 11;

#endif
#if( /* {public ClientHeartBeatMessageTextAsArray}. */ 1 )

      // This is sent from a NewsHub client to NewsHub.
      public: static char const ClientHeartBeatMessageTextAsArray[];

      //
      private: static void ClientHeartBeatMessageTextStaticAssertion();

#endif
#if( /* {public ClientHeartBeatMessageTextLength}. */ 1 )

      //
      public: static int const ClientHeartBeatMessageTextLength = MessageTextHeaderLength + 12;

#endif
#if( /* {public NewsFeedAdapterHeartBeatMessageTextAsArray}. */ 1 )

      // This is sent from a news feed adapter to NewsHub.
      public: static char const NewsFeedAdapterHeartBeatMessageTextAsArray[];

      //
      private: static void NewsFeedAdapterHeartBeatMessageTextStaticAssertion();

#endif
#if( /* {public NewsFeedAdapterHeartBeatMessageTextLength}. */ 1 )

      //
      public: static int const NewsFeedAdapterHeartBeatMessageTextLength = MessageTextHeaderLength * 2 + 12 + 16;

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
