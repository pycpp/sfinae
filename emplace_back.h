//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief SFINAE detection for `emplace_back` and fail-safe implementation.
 *
 *  Construct item in-place at the end of the container.
 *
 *  \synopsis
 *      template <typename T>
 *      struct has_emplace_back: implementation_defined
 *      {};
 *
 *      struct emplace_back
 *      {
 *          template <typename T, typename... Ts>
 *          void operator()(T& t, Ts&&... ts);
 *      };
 *
 *      #if PYCPP_CPP14
 *
 *      template <typename T>
 *      constexpr bool has_emplace_back_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/preprocessor/compiler.h>
#include <pycpp/stl/type_traits.h>
#include <pycpp/stl/utility.h>

PYCPP_BEGIN_NAMESPACE

// SFINAE
// ------

// C++17 changed the return type from `void` to `reference`.
#if defined(PYCPP_CPP17)
#   define PYCPP_EMPLACE_BACK typename C::reference (C::*)(typename C::value_type&&)
#else
#   define PYCPP_EMPLACE_BACK void (C::*)(typename C::value_type&&)
#endif

PYCPP_HAS_MEMBER_FUNCTION(emplace_back, has_emplace_back, PYCPP_EMPLACE_BACK);
#undef PYCPP_EMPLACE_BACK


/**
 *  \brief Call `emplace_back` as a functor.
 */
struct emplace_back
{
    template <typename T, typename... Ts>
    enable_if_t<has_emplace_back<T>::value, void>
    operator()(
        T &t,
        Ts&&... ts
    )
    {
        t.emplace_back(forward<Ts>(ts)...);
    }

    template <typename T, typename... Ts>
    enable_if_t<!has_emplace_back<T>::value, void>
    operator()(
        T &t,
        Ts&&... ts
    )
    {
        t.insert(t.end(), forward<Ts>(ts)...);
    }
};

#ifdef PYCPP_CPP14

// SFINAE
// ------

template <typename T>
constexpr bool has_emplace_back_v = has_emplace_back<T>::value;

#endif

PYCPP_END_NAMESPACE
