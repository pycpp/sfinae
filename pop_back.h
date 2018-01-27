//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief SFINAE detection for `pop_back` and fail-safe implementation.
 *
 *  Remove item from back of container.
 *
 *  \synopsis
 *      template <typename T>
 *      struct has_pop_back: implementation_defined
 *      {};
 *
 *      struct pop_back
 *      {
 *          template <typename T>
 *          void operator()(T& t);
 *      };
 *
 *      #if HAVE_CPP14
 *
 *      template <typename T>
 *      constexpr bool has_pop_back_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/sfinae/has_member_function.h>
#include <pycpp/stl/type_traits.h>

PYCPP_BEGIN_NAMESPACE

// SFINAE
// ------

PYCPP_HAS_MEMBER_FUNCTION(pop_back, has_pop_back, void (C::*)());


/**
 *  \brief Call `pop_back` as a functor.
 *
 *  Must support bidirectional iteration.
 */
struct pop_back
{
    template <typename T>
    enable_if_t<has_pop_back<T>::value, void>
    operator()(T &t)
    {
        t.pop_back();
    }

    template <typename T>
    enable_if_t<!has_pop_back<T>::value, void>
    operator()(T &t)
    {
        t.erase(--t.end());
    }
};

#ifdef HAVE_CPP14

// SFINAE
// ------

template <typename T>
constexpr bool has_pop_back_v = has_pop_back<T>::value;

#endif

PYCPP_END_NAMESPACE
