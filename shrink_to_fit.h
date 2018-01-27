//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief SFINAE detection for `shrink_to_fit` and fail-safe implementation.
 *
 *  Shrink container capacity to current size.
 *
 *  \synopsis
 *      template <typename T>
 *      struct has_shrink_to_fit: implementation_defined
 *      {};
 *
 *      struct shrink_to_fit
 *      {
 *          template <typename T>
 *          void operator()(T& t);
 *      };
 *
 *      #if HAVE_CPP14
 *
 *      template <typename T>
 *      constexpr bool has_shrink_to_fit_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/sfinae/has_member_function.h>
#include <pycpp/stl/type_traits.h>

PYCPP_BEGIN_NAMESPACE

// SFINAE
// ------

PYCPP_HAS_MEMBER_FUNCTION(shrink_to_fit, has_shrink_to_fit, void (C::*)());


/**
 *  \brief Call `shrink_to_fit` as a functor.
 */
struct shrink_to_fit
{
    template <typename T>
    enable_if_t<has_shrink_to_fit<T>::value, void>
    operator()
    (
        T &t
    )
    {
        t.shrink_to_fit();
    }

    template <typename T>
    enable_if_t<!has_shrink_to_fit<T>::value, void>
    operator()(
        T &t
    )
    {}
};

#ifdef HAVE_CPP14

// SFINAE
// ------

template <typename T>
constexpr bool has_shrink_to_fit_v = has_shrink_to_fit<T>::value;

#endif

PYCPP_END_NAMESPACE
