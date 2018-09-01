#pragma once

#include "StdAfx.h"

#include "./Common/SourceCodeModel/IncrementHeaderInclusionDepth.hpp"

#include __FILE__
#include "./Main.hpp"

#include "./Prototype52/TApplication.cpp"

#include "./Common/SourceCodeModel/SourceFooter.hpp"

#if( /* {main}. */ 0 == YURIYGULYAYEV_COMMON_SOURCECODEMODEL_HEADERINCLUSIONDEPTH() )

POCO_APP_MAIN( ::Prototype52::TApplication )

#endif
