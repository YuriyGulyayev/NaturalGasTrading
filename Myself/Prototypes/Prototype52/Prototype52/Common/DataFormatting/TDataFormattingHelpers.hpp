#pragma once

//#include "./.hpp"

#include "../SourceCodeModel/IncrementHeaderInclusionBalance.hpp"

namespace Common
{
namespace DataFormatting
{
   //

   class TDataFormattingHelpers abstract sealed
   {
#if( /* {public DateTimeMicrosecondResolutionFormatStringAsArray}. */ 1 )

      // This can parse optional fractions of a second.
      public: static char const DateTimeMicrosecondResolutionFormatStringAsArray[];

#endif
#if( /* {public DateTimeMicrosecondResolutionFormatString}. */ 1 )

      //
      public: static ::std::string const DateTimeMicrosecondResolutionFormatString;

#endif
#if( /* {public DateTimeMillisecondResolutionFormatStringAsArray}. */ 1 )

      //
      public: static char const DateTimeMillisecondResolutionFormatStringAsArray[];

#endif
#if( /* {public DateTimeMillisecondResolutionFormatString}. */ 1 )

      //
      public: static ::std::string const DateTimeMillisecondResolutionFormatString;

#endif
#if( /* {public TimeOfDayMicrosecondResolutionFormatStringAsArray}. */ 1 )

      // This can parse optional fractions of a second.
      public: static char const TimeOfDayMicrosecondResolutionFormatStringAsArray[];

#endif
#if( /* {public TimeOfDayMicrosecondResolutionFormatString}. */ 1 )

      //
      public: static ::std::string const TimeOfDayMicrosecondResolutionFormatString;

#endif
#if( /* {public TimeOfDayMillisecondResolutionFormatStringAsArray}. */ 1 )

      //
      public: static char const TimeOfDayMillisecondResolutionFormatStringAsArray[];

#endif
#if( /* {public TimeOfDayMillisecondResolutionFormatString}. */ 1 )

      //
      public: static ::std::string const TimeOfDayMillisecondResolutionFormatString;

#endif
#if( /* {public TimeOfDaySecondResolutionFormatStringAsArray}. */ 1 )

      //
      public: static char const TimeOfDaySecondResolutionFormatStringAsArray[];

#endif
#if( /* {public TimeOfDaySecondResolutionFormatString}. */ 1 )

      //
      public: static ::std::string const TimeOfDaySecondResolutionFormatString;

#endif
#if( /* {public DateTimeSecondResolutionFormatForFileNameStringAsArray}. */ 1 )

      // yg? Does this belong here?
      public: static char const DateTimeSecondResolutionFormatForFileNameStringAsArray[];

#endif
#if( /* {public DateTimeSecondResolutionFormatForFileNameString}. */ 1 )

      // yg? See {DateTimeSecondResolutionFormatForFileNameStringAsArray} comment.
      public: static ::std::string const DateTimeSecondResolutionFormatForFileNameString;

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
