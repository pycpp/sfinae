//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Check if types support `<` comparison.
 *
 *  Detect if two types support a less than operator (`<`).
 *
 *  \synopsis
 *      template <typename T, typename U>
 *      using has_less = implementation-defined;
 *
 *      #if HAVE_CPP14
 *
 *      template <typename T, typename U>
 *      constexpr bool has_less_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/preprocessor/os.h>
#include <pycpp/sfinae/has_op.h>
#include <warnings/push.h>
#include <warnings/narrowing-conversions.h>

PYCPP_BEGIN_NAMESPACE

// SFINAE
// ------

PYCPP_HAS_OPERATION(less, <);

#ifdef HAVE_CPP14

// SFINAE
// ------

template <typename T, typename U>
constexpr bool has_less_v = has_less<T, U>::value;

#endif

PYCPP_END_NAMESPACE

#include <warnings/pop.h>
