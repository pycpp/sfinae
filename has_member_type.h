//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Check a type contains a specific member type.
 *
 *  Macro to detect if a class contains a member type of the given
 *  name (`member`), expanding to a struct similar to `bool_constant`.
 *
 *  \synopsis
 *      #define PYCPP_HAS_MEMBER_TYPE(member, name)     implementation-defined
 */

#pragma once

#include <pycpp/stl/type_traits/has_member_type.h>
