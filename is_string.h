//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Type detection for strings.
 *
 *  Detect if type is one of many string types.
 *
 *  \synopsis
 *      template <typename T>
 *      using is_charp = implementation-defined;
 *
 *      template <typename T>
 *      using is_const_charp = implementation-defined;
 *
 *      template <typename T>
 *      using is_wcharp = implementation-defined;
 *
 *      template <typename T>
 *      using is_const_wcharp = implementation-defined;
 *
 *      template <typename T>
 *      using is_char16p = implementation-defined;
 *
 *      template <typename T>
 *      using is_const_char16p = implementation-defined;
 *
 *      template <typename T>
 *      using is_char32p = implementation-defined;
 *
 *      template <typename T>
 *      using is_const_char32p = implementation-defined;
 *
 *      template <typename T>
 *      using is_stl_string = implementation-defined;
 *
 *      template <typename T>
 *      using is_string = implementation-defined;
 *
 *      #if PYCPP_CPP14
 *
 *      template <typename T>
 *      constexpr bool is_charp_v = implementation-defined;
 *
 *      template <typename T>
 *      constexpr bool is_const_charp_v = implementation-defined;
 *
 *      template <typename T>
 *      constexpr bool is_wcharp_v = implementation-defined;
 *
 *      template <typename T>
 *      constexpr bool is_const_wcharp_v = implementation-defined;
 *
 *      template <typename T>
 *      constexpr bool is_char16p_v = implementation-defined;
 *
 *      template <typename T>
 *      constexpr bool is_const_char16p_v = implementation-defined;
 *
 *      template <typename T>
 *      constexpr bool is_char32p_v = implementation-defined;
 *
 *      template <typename T>
 *      constexpr bool is_const_char32p_v = implementation-defined;
 *
 *      template <typename T>
 *      constexpr bool is_stl_string_v = implementation-defined;
 *
 *      template <typename T>
 *      constexpr bool is_string_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/sfinae/is_specialization.h>
#include <pycpp/stl/string.h>
#include <pycpp/stl/type_traits.h>

PYCPP_BEGIN_NAMESPACE

namespace str_detail
{
// DETAIL
// ------

template <typename CharP, typename T>
using is_char_t = is_same<CharP, remove_cvref_t<decay_t<T>>>;

}   /* str_detail */

// SFINAE
// ------

// NARROW

template <typename T>
using is_charp = str_detail::is_char_t<char*, T>;

template <typename T>
using is_const_charp = str_detail::is_char_t<const char*, T>;

// WIDE

template <typename T>
using is_wcharp = str_detail::is_char_t<wchar_t*, T>;

template <typename T>
using is_const_wcharp = str_detail::is_char_t<const wchar_t*, T>;

// U16

template <typename T>
using is_char16p = str_detail::is_char_t<char16_t*, T>;

template <typename T>
using is_const_char16p = str_detail::is_char_t<const char16_t*, T>;

// U32

template <typename T>
using is_char32p = str_detail::is_char_t<char32_t*, T>;

template <typename T>
using is_const_char32p = str_detail::is_char_t<const char32_t*, T>;

// STL

template <typename T>
using is_stl_string = is_specialization<T, std::basic_string>;

// GENERAL

template <typename T>
using is_string = integral_constant<
    bool,
    is_charp<T>::value   || is_const_charp<T>::value   ||
    is_wcharp<T>::value  || is_const_wcharp<T>::value  ||
    is_char16p<T>::value || is_const_char16p<T>::value ||
    is_char32p<T>::value || is_const_char32p<T>::value ||
    is_stl_string<T>::value
>;

#ifdef PYCPP_CPP14

// SFINAE
// ------

template <typename T>
constexpr bool is_charp_v = is_charp<T>::value;

template <typename T>
constexpr bool is_const_charp_v = is_const_charp<T>::value;

template <typename T>
constexpr bool is_wcharp_v = is_wcharp<T>::value;

template <typename T>
constexpr bool is_const_wcharp_v = is_const_wcharp<T>::value;

template <typename T>
constexpr bool is_char16p_v = is_char16p<T>::value;

template <typename T>
constexpr bool is_const_char16p_v = is_const_char16p<T>::value;

template <typename T>
constexpr bool is_char32p_v = is_char32p<T>::value;

template <typename T>
constexpr bool is_const_char32p_v = is_const_char32p<T>::value;

template <typename T>
constexpr bool is_stl_string_v = is_stl_string<T>::value;

template <typename T>
constexpr bool is_string_v = is_string<T>::value;

#endif

PYCPP_END_NAMESPACE
