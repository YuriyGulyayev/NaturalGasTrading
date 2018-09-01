// There is no ".cpp" counterpart for this file.
// yg? I don't like this file name.

#include "./DecrementHeaderInclusionDepth.hpp"

static_assert( YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() >= 0, "" );
#if( YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() > 0 )
   #include "./DecrementHeaderInclusionBalance.hpp"
#else
   // This often detects if we included an ".hpp" file but not its counterpart ".cpp" file. But it's not a perfect protection.
   static_assert( YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONBALANCE() == 0, "" );
#endif
