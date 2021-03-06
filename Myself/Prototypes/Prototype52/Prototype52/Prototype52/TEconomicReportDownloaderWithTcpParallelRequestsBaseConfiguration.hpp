#pragma once

#include "../Common/Networking/TSocketNextDynamicPortNumberAdvancerConfiguration.hpp"
#include "./TEconomicReportReceiverBaseConfiguration.hpp"
#include "./TTcpRequestConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // See the config file for more info.

   class TEconomicReportDownloaderWithTcpParallelRequestsBaseConfiguration abstract :
      public TEconomicReportReceiverBaseConfiguration
   {
#if( /* {public RequestPreSendingTimeOffsetMilliseconds}. */ 1 )

      //
      public: int RequestPreSendingTimeOffsetMilliseconds;

#endif
#if( /* {public ForcedDelayTimeSpanMillisecondsInTestMode}. */ 1 )

      //
      public: int ForcedDelayTimeSpanMillisecondsInTestMode;

#endif
#if( /* {public SocketNextDynamicPortNumberAdvancerConfiguration}. */ 1 )

      //
      public: ::Common::Networking::TSocketNextDynamicPortNumberAdvancerConfiguration SocketNextDynamicPortNumberAdvancerConfiguration;

#endif
#if( /* {public TcpRequestsConfiguration}. */ 1 )

      //
      public: ::std::vector< TTcpRequestConfiguration > TcpRequestsConfiguration;

#endif

#if( /* {(protected)} Instance default constructor. */ 1 )

      // Could be autogenerated.

#endif
#if( /* //{(private)} Instance copy constructor. */ 1 )

      // Cannot be autogenerated.

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // {virtual}.

#endif
#if( /* //{(private) operator =}. */ 1 )

      // Cannot be autogenerated.

#endif

#if( /* {public Validate}. */ 1 )

      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.
      // TODO 3 yg? If I implement this method I will need to make it {virtual}.

      public: void Validate() const;

#endif
   };
}
