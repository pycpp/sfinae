//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief SFINAE detection for `front` and fail-safe implementation.
 *
 *  Return the first item in the container.
 *
 *  \synopsis
 *      template <typename T>
 *      struct has_front: implementation_defined
 *      {};
 *
 *      struct front
 *      {
 *          template <typename T>
 *          typename T::reference operator()(T& t);
 *
 *          template <typename T>
 *          typename T::const_reference operator()(const T& t);
 *      };
 *
 *      #if HAVE_CPP14
 *
 *      template <typename T>
 *      constexpr bool has_front_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/sfinae/back.h>

PYCPP_BEGIN_NAMESPACE

// SFINAE
// ------

PYCPP_HAS_MEMBER_FUNCTION(front, has_front, typename C::reference (C::*)());


/**
 *  \brief Call `front` as a functor.
 */
struct front
{
    template <typename T>
    enable_if_t<has_front<T>::value && !back_detail::is_const<T>::value, typename T::reference>
    operator()(
        T &t
    )
    {
        return t.front();
    }

    template <typename T>
    enable_if_t<!has_front<T>::value && !back_detail::is_const<T>::value, typename T::reference>
    operator()(
        T &t
    )
    {
        return *t.begin();
    }

    template <typename T>
    enable_if_t<has_front<T>::value, typename T::const_reference>
    operator()(
        const T &t
    )
    const
    {
        return t.front();
    }

    template <typename T>
    enable_if_t<!has_front<T>::value, typename T::const_reference>
    operator()(
        const T &t
    )
    const
    {
        return *t.begin();
    }
};

#ifdef HAVE_CPP14

// SFINAE
// ------

template <typename T>
constexpr bool has_front_v = has_front<T>::value;

#endif

PYCPP_END_NAMESPACE
