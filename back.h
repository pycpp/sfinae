//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief SFINAE detection for `back` and fail-safe implementation.
 *
 *  Return the last item in the container.
 *
 *  \synopsis
 *      template <typename T>
 *      struct has_back: implementation_defined
 *      {};
 *
 *      struct back
 *      {
 *          template <typename T>
 *          typename T::reference operator()(T& t);
 *
 *          template <typename T>
 *          typename T::const_reference operator()(const T& t);
 *      };
 *
 *      #if PYCPP_CPP14
 *
 *      template <typename T>
 *      constexpr bool has_back_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/stl/type_traits.h>
#include <pycpp/stl/utility.h>

PYCPP_BEGIN_NAMESPACE

namespace back_detail
{
// SFINAE
// ------

template <typename T>
using dereference_iterator_type = decltype(*declval<typename T::iterator>());

template <typename T>
using is_const_iterator = is_same<dereference_iterator_type<T>, typename T::const_reference>;

template <typename T>
struct is_const: bool_constant<PYCPP_NAMESPACE::is_const<T>::value || is_const_iterator<T>::value>
{};

}   /* back_detail */

// SFINAE
// ------

PYCPP_HAS_MEMBER_FUNCTION(back, has_back, typename C::reference (C::*)());


/**
 *  \brief Call `back` as a functor.
 *
 *  Must support bidirectional iteration.
 */
struct back
{
    template <typename T>
    enable_if_t<has_back<T>::value && !back_detail::is_const<T>::value, typename T::reference>
    operator()(
        T &t
    )
    {
        return t.back();
    }

    template <typename T>
    enable_if_t<!has_back<T>::value && !back_detail::is_const<T>::value, typename T::reference>
    operator()(
        T &t
    )
    {
        return *t.rbegin();
    }

    template <typename T>
    enable_if_t<has_back<T>::value, typename T::const_reference>
    operator()(
        const T &t
    )
    const
    {
        return t.back();
    }

    template <typename T>
    enable_if_t<!has_back<T>::value, typename T::const_reference>
    operator()(
        const T &t
    )
    const
    {
        return *t.rbegin();
    }
};

#ifdef PYCPP_CPP14

// SFINAE
// ------

template <typename T>
constexpr bool has_back_v = has_back<T>::value;

#endif

PYCPP_END_NAMESPACE
