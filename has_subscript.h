//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Check if container supports `[]` with subscript.
 *
 *  Detect if the `C` supports subscripting with `I` (`C[I]`).
 *
 *  \synopsis
 *      template <typename C, typename I>
 *      using has_subscript = implementation-defined;
 *
 *      #if HAVE_CPP14
 *
 *      template <typename C, typename I>
 *      constexpr bool has_subscript_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/stl/type_traits.h>
#include <pycpp/stl/utility.h>

PYCPP_BEGIN_NAMESPACE

// SFINAE
// ------

template <typename C, typename I, typename = void>
struct has_subscript_impl: false_type
{};

template <typename C, typename I>
struct has_subscript_impl<C, I, void_t<decltype(declval<C>()[declval<I>()])>>: true_type
{};

template <typename C, typename I>
using has_subscript = has_subscript_impl<C, I>;

#ifdef HAVE_CPP14

// SFINAE
// ------

template <typename C, typename I>
constexpr bool has_subscript_v = has_subscript<C, I>::value;

#endif

PYCPP_END_NAMESPACE
