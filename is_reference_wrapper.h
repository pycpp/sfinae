//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Type detection for `reference_wrapper`.
 *
 *  Detect if a type is a `std::reference_wrapper`.
 *
 *  \synopsis
 *      template <typename T>
 *      using is_reference_wrapper = implementation-defined;
 *
 *      #if PYCPP_CPP14
 *
 *      template <typename T>
 *      constexpr bool is_reference_wrapper_v = implementation-defined;
 *
 *      #endif
 */

#pragma once

#include <pycpp/stl/type_traits/is_reference_wrapper.h>
