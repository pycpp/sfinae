//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Type detection for `tuple`.
 *
 *  Detect if a type is a `std::tuple`.
 *
 *  \synopsis
 *      template <typename T>
 *      using is_tuple = implementation-defined;
 *
 *      #if PYCPP_CPP14
 *
 *      template <typename T>
 *      constexpr bool is_tuple_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/sfinae/is_specialization.h>

PYCPP_BEGIN_NAMESPACE

// SFINAE
// ------

template <typename T>
using is_tuple = is_specialization<T, tuple>;

#ifdef PYCPP_CPP14

// SFINAE
// ------

template <typename T>
constexpr bool is_tuple_v = is_tuple<T>::value;

#endif

PYCPP_END_NAMESPACE
