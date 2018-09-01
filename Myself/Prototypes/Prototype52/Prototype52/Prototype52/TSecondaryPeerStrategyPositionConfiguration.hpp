#pragma once

#include "../Finance/Trading/TPositionDirectionCode.hpp"
#include "./TEntryOrderConfiguration.hpp"

#include "../Common/SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Prototype52
{
   // See the config file for more info.

   class TSecondaryPeerStrategyPositionConfiguration
   {
#if( /* {public RelativeDirectionCode}. */ 1 )

      // yg? Does this parameter belong here?
      // yg? It should be a property of an instrument. But there is currently no place for that in the object model.
      // yg? And it makes no sense to have multiple positions for the same instrument.
      // yg? Consider renaming this field to clearly specify relative to what.
      public: ::Finance::Trading::TPositionDirectionCode RelativeDirectionCode;

#endif
#if( /* {public EntryOrdersConfiguration}. */ 1 )

      //
      public: ::std::vector< TEntryOrderConfiguration > EntryOrdersConfiguration;

#endif

#if( /* {public} Instance default constructor. */ 1 )

      //

      public: explicit TSecondaryPeerStrategyPositionConfiguration();

#endif
#if( /* {private} Instance copy constructor. */ 1 )

      //

      private: explicit TSecondaryPeerStrategyPositionConfiguration
         ( TSecondaryPeerStrategyPositionConfiguration const & source
         );

#endif
#if( /* {public} Instance move constructor. */ 1 )

      //

      public: TSecondaryPeerStrategyPositionConfiguration
         ( TSecondaryPeerStrategyPositionConfiguration && source
         );

#endif
#if( /* {(public)} Instance destructor. */ 1 )

      // Could be autogenerated.
      // This doesn't need to be virtual.

#endif
#if( /* {private operator =}. */ 1 )

      //

      private: TSecondaryPeerStrategyPositionConfiguration & operator =
         ( TSecondaryPeerStrategyPositionConfiguration const & source
         );

#endif
#if( /* {public operator =}. */ 1 )

      // This doesn't need to be virtual.

      public: TSecondaryPeerStrategyPositionConfiguration & operator =
         ( TSecondaryPeerStrategyPositionConfiguration && source
         );

#endif

#if( /* {public Assign}. */ 1 )

      // This doesn't need to be virtual.
      // yg? Should this be named {Move}?

      public: void Assign
         ( TSecondaryPeerStrategyPositionConfiguration && source
         );

#endif

#if( /* {public Validate}. */ 1 )

      // This doesn't need to be virtual.
      // yg? This might need a parameter specifying configuration extraction state. Or better add a method with that parameter to the helpers.

      public: void Validate() const;

#endif
   };
}