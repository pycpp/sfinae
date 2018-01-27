//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Check if types support a specific operator.
 *
 *  Macro to detect if two types support a desired operation, expanding
 *  to a struct similar to `bool_constant`.
 *
 *  \synopsis
 *      #define PYCPP_HAS_OPERATION(name, op)   implementation-defined
 */

#pragma once

#include <pycpp/stl/type_traits.h>
#include <pycpp/stl/utility.h>

PYCPP_BEGIN_NAMESPACE

// FUNCTIONS
// ---------

/**
 *  We need an l-value for assignment operators, which also
 *  need an l-value for the first argument. This is strictly
 *  `declval` except providing an `lvalue` rather than `rvalue`
 *  reference.
 */
template <typename T>
add_lvalue_reference_t<T> decl_lvalue() noexcept;

// MACROS
// ------

/**
 *  \brief Macro to check if operation is supported between types.
 */
#define PYCPP_HAS_OPERATION(name, op)                                           \
    template <typename T, typename U = T>                                       \
    struct has_##name                                                           \
    {                                                                           \
    protected:                                                                  \
        template <typename T1 = T, typename U1 = U>                             \
        static                                                                  \
        char&                                                                   \
        test(decltype(decl_lvalue<T1>() op declval<U1>()));                     \
                                                                                \
        template <typename T1 = T, typename U1 = U>                             \
        static                                                                  \
        long&                                                                   \
        test(...);                                                              \
                                                                                \
    public:                                                                     \
        enum {                                                                  \
            value = sizeof(test<T, U>(decl_lvalue<int>())) == sizeof(char)      \
        };                                                                      \
    }

PYCPP_END_NAMESPACE
