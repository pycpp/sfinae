//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Check a type contains a specific member function.
 *
 *  Macro to detect if a class contains a member function of the given
 *  name (`member`), expanding to a struct similar to `bool_constant`.
 *  The macro takes an optional signature for the method, in case
 *  of ambiguous overloads leading to substitution failure.
 *
 *  \synopsis
 *      #define PYCPP_HAS_MEMBER_FUNCTION(...)      implementation-defined
 */

#pragma once

#include <pycpp/stl/type_traits/has_member_function.h>
