//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Check if types support `>=` comparison.
 *
 *  Detect if two types support a greater or equal operator ('>=').
 *
 *  \synopsis
 *      template <typename T, typename U>
 *      using has_greater_equal = implementation-defined;
 *
 *      #if PYCPP_CPP14
 *
 *      template <typename T, typename U>
 *      constexpr bool has_greater_equal_v = implementation-defined;
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

PYCPP_HAS_OPERATION(greater_equal, >=);

#ifdef PYCPP_CPP14

// SFINAE
// ------

template <typename T, typename U>
constexpr bool has_greater_equal_v = has_greater_equal<T, U>::value;

#endif

PYCPP_END_NAMESPACE

#include <warnings/pop.h>
