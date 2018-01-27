//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief SFINAE detection for `pop_front` and fail-safe implementation.
 *
 *  Remove item from front of container.
 *
 *  \synopsis
 *      template <typename T>
 *      struct has_pop_front: implementation_defined
 *      {};
 *
 *      struct pop_front
 *      {
 *          template <typename T>
 *          void operator()(T& t);
 *      };
 *
 *      #if HAVE_CPP14
 *
 *      template <typename T>
 *      constexpr bool has_pop_front_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/sfinae/has_member_function.h>
#include <pycpp/stl/type_traits.h>

PYCPP_BEGIN_NAMESPACE

// SFINAE
// ------

PYCPP_HAS_MEMBER_FUNCTION(pop_front, has_pop_front, void (C::*)());


/**
 *  \brief Call `pop_front` as a functor.
 */
struct pop_front
{
    template <typename T>
    enable_if_t<has_pop_front<T>::value, void>
    operator()(
        T &t
    )
    {
        t.pop_front();
    }

    template <typename T>
    enable_if_t<!has_pop_front<T>::value, void>
    operator()(
        T &t
    )
    {
        t.erase(t.begin());
    }
};

#ifdef HAVE_CPP14

// SFINAE
// ------

template <typename T>
constexpr bool has_pop_front_v = has_pop_front<T>::value;

#endif

PYCPP_END_NAMESPACE
