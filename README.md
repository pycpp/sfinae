# SFINAE

**Table of Contents**

- [Introduction](#introduction)
- [Operation Detection](#operator-detection)
  - [Has Bit And](#has-bit-and)
  - [Has Bit And Assign](#has-bit-and-assign)
  - [Has Bit Or](#has-bit-or)
  - [Has Bit Or Assign](#has-bit-or-assign)
  - [Has Bit Xor](#has-bit-xor)
  - [Has Bit Xor Assign](#has-bit-xor-assign)
  - [Has Divides](#has-divides)
  - [Has Divides Assign](#has-divides-assign)
  - [Has Equal To](#has-equal-to)
  - [Has Greater](#has-greater)
  - [Has Greater Equal](#has-greater-equal)
  - [Has Left Shift](#has-left-shift)
  - [Has Left Shift Assign](#has-left-shift-assign)
  - [Has Less](#has-less)
  - [Has Less Equal](#has-less-equal)
  - [Has Logical And](#has-logical-and)
  - [Has Logical Or](#has-logical-or)
  - [Has Minus](#has-minus)
  - [Has Minus Assign](#has-minus-assign)
  - [Has Multiplies](#has-multiplies)
  - [Has Multiplies Assign](#has-multiplies-assign)
  - [Has Not Equal To](#has-not-equal-to)
  - [Has Plus](#has-plus)
  - [Has Plus Assign](#has-plus-assign)
  - [Has Right Shift](#has-right-shift)
  - [Has Right Shift Assign](#has-right-shift-assign)
  - [Has Subscript](#has-subscript)
- [Member Variable, Function, and Type Detection](#member-variable-function-and-type-detection)
  - [Has Member Function](#has-member-function)
  - [Has Member Type](#has-member-type)
  - [Has Member Variable](#has-member-variable)
- [Type Identification](#type-identification)
  - [Is Complex](#is-complex)
  - [Is Pair](#is-pair)
  - [Is Reference Wrapper](#is-reference-wrapper)
//  - [Is Specialization](#is-specialization)
//  - [Is String](#is-string)
//  - [Is Tuple](#is-tuple)

// TODO: here

- [Fail Safe Implementations](#fail-safe-implementations)
  - [Back](#back)
  - [Front](#front)
  - [Emplace Back](#emplace-back)
  - [Emplace Front](#emplace-front)

## Introduction

Substitution failure is not an error (SFINAE) enables the selection of proper function overloads by rejecting templates with substitution failures. PyCPP uses SFINAE extensively in its container design, and provides type traits for the detection of supported operators, member variable, function, and type detection, type identification, as well as fail-safe member function implementations.

## Operation Detection

### Has Bit And

Detect if two types support a bitwise and (`&`) operator.

```cpp
#include <pycpp/sfinae/has_bit_and.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_bit_and<int, int>::value, "");
    static_assert(!has_bit_and<x, int>::value, "");
    return 0;
}
```

### Has Bit And Assign

Detect if two types support a bitwise and assignment (`&=`) operator.

```cpp
#include <pycpp/sfinae/has_bit_and_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_bit_and_assign<int, int>::value, "");
    static_assert(!has_bit_and_assign<x, int>::value, "");
    return 0;
}
```

### Has Bit Or

Detect if two types support a bitwise or (`|`) operator.

```cpp
#include <pycpp/sfinae/has_bit_or.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_bit_or<int, int>::value, "");
    static_assert(!has_bit_or<x, int>::value, "");
    return 0;
}
```

### Has Bit Or Assign

Detect if two types support a bitwise or assignment (`|=`) operator.

```cpp
#include <pycpp/sfinae/has_bit_or_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_bit_or_assign<int, int>::value, "");
    static_assert(!has_bit_or_assign<x, int>::value, "");
    return 0;
}
```

### Has Bit Xor

Detect if two types support a bitwise xor (`^`) operator.

```cpp
#include <pycpp/sfinae/has_bit_xor.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_bit_xor<int, int>::value, "");
    static_assert(!has_bit_xor<x, int>::value, "");
    return 0;
}
```

### Has Bit Xor Assign

Detect if two types support a bitwise xor assignment (`^=`) operator.

```cpp
#include <pycpp/sfinae/has_bit_xor_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_bit_xor_assign<int, int>::value, "");
    static_assert(!has_bit_xor_assign<x, int>::value, "");
    return 0;
}
```

### Has Divides

Detect if two types support a divides (`/`) operator.

```cpp
#include <pycpp/sfinae/has_divides.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_divides<int, int>::value, "");
    static_assert(!has_divides<x, int>::value, "");
    return 0;
}
```

### Has Divides Assign

Detect if two types support a divides assignment (`/=`) operator.

```cpp
#include <pycpp/sfinae/has_divides_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_divides_assign<int, int>::value, "");
    static_assert(!has_divides_assign<x, int>::value, "");
    return 0;
}
```

### Has Equal To

Detect if two types support an equal to (`==`) operator.

```cpp
#include <pycpp/sfinae/has_equal_to.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_equal_to<int, int>::value, "");
    static_assert(!has_equal_to<x, int>::value, "");
    return 0;
}
```

### Has Greater

Detect if two types support a greater than (`>`) operator.

```cpp
#include <pycpp/sfinae/has_greater.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_greater<int, int>::value, "");
    static_assert(!has_greater<x, int>::value, "");
    return 0;
}
```

### Has Greater Equal

Detect if two types support a greater than or equal to (`>=`) operator.

```cpp
#include <pycpp/sfinae/has_greater_equal.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_greater_equal<int, int>::value, "");
    static_assert(!has_greater_equal<x, int>::value, "");
    return 0;
}
```

### Has Left Shift

Detect if two types support a left shift (`<<`) operator.

```cpp
#include <pycpp/sfinae/has_left_shift.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_left_shift<int, int>::value, "");
    static_assert(!has_left_shift<x, int>::value, "");
    return 0;
}
```

### Has Left Shift Assign

Detect if two types support a left shift assignment (`<<=`) operator.

```cpp
#include <pycpp/sfinae/has_left_shift_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_left_shift_assign<int, int>::value, "");
    static_assert(!has_left_shift_assign<x, int>::value, "");
    return 0;
}
```

### Has Less

Detect if two types support a less than (`<`) operator.

```cpp
#include <pycpp/sfinae/has_less.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_less<int, int>::value, "");
    static_assert(!has_less<x, int>::value, "");
    return 0;
}
```

### Has Less Equal

Detect if two types support a less than or equal to (`<=`) operator.

```cpp
#include <pycpp/sfinae/has_less_equal.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_less_equal<int, int>::value, "");
    static_assert(!has_less_equal<x, int>::value, "");
    return 0;
}
```

### Has Logical And

Detect if two types support a logical and (`&&`) operator.

```cpp
#include <pycpp/sfinae/has_logical_and.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_logical_and<int, int>::value, "");
    static_assert(!has_logical_and<x, int>::value, "");
    return 0;
}
```

### Has Logical Or

Detect if two types support a logical or (`||`) operator.

```cpp
#include <pycpp/sfinae/has_logical_or.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_logical_or<int, int>::value, "");
    static_assert(!has_logical_or<x, int>::value, "");
    return 0;
}
```

### Has Minus

Detect if two types support a minus (`-`) operator.

```cpp
#include <pycpp/sfinae/has_minus.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_minus<int, int>::value, "");
    static_assert(!has_minus<x, int>::value, "");
    return 0;
}
```

### Has Minus Assign

Detect if two types support a minus assignment (`-=`) operator.

```cpp
#include <pycpp/sfinae/has_minus_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_minus_assign<int, int>::value, "");
    static_assert(!has_minus_assign<x, int>::value, "");
    return 0;
}
```

### Has Modulus

Detect if two types support a modulus (`%`) operator.

```cpp
#include <pycpp/sfinae/has_modulus.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_modulus<int, int>::value, "");
    static_assert(!has_modulus<x, int>::value, "");
    return 0;
}
```

### Has Modulus Assign

Detect if two types support a modulus assignment (`%=`) operator.

```cpp
#include <pycpp/sfinae/has_modulus_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_modulus_assign<int, int>::value, "");
    static_assert(!has_modulus_assign<x, int>::value, "");
    return 0;
}
```

### Has Multiplies

Detect if two types support a multiplies (`*`) operator.

```cpp
#include <pycpp/sfinae/has_multiplies.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_multiplies<int, int>::value, "");
    static_assert(!has_multiplies<x, int>::value, "");
    return 0;
}
```

### Has Multiplies Assign

Detect if two types support a multiplies assignment (`*=`) operator.

```cpp
#include <pycpp/sfinae/has_multiplies_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_multiplies_assign<int, int>::value, "");
    static_assert(!has_multiplies_assign<x, int>::value, "");
    return 0;
}
```

### Has Not Equal To

Detect if two types support a not equal to (`!=`) operator.

```cpp
#include <pycpp/sfinae/has_not_equal_to.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_not_equal_to<int, int>::value, "");
    static_assert(!has_not_equal_to<x, int>::value, "");
    return 0;
}
```

### Has Plus

Detect if two types support a plus (`+`) operator.

```cpp
#include <pycpp/sfinae/has_plus.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_plus<int, int>::value, "");
    static_assert(!has_plus<x, int>::value, "");
    return 0;
}
```

### Has Plus Assign

Detect if two types support a plus assignment (`+=`) operator.

```cpp
#include <pycpp/sfinae/has_plus_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_plus_assign<int, int>::value, "");
    static_assert(!has_plus_assign<x, int>::value, "");
    return 0;
}
```

### Has Right Shift

Detect if two types support a right shift (`>>`) operator.

```cpp
#include <pycpp/sfinae/has_right_shift.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_right_shift<int, int>::value, "");
    static_assert(!has_right_shift<x, int>::value, "");
    return 0;
}
```

### Has Right Shift Assign

Detect if two types support a right shift assignment (`>>=`) operator.

```cpp
#include <pycpp/sfinae/has_right_shift_assign.h>

PYCPP_USING_NAMESPACE

struct x {};

int main()
{
    static_assert(has_right_shift_assign<int, int>::value, "");
    static_assert(!has_right_shift_assign<x, int>::value, "");
    return 0;
}
```

### Has Subscript

Check if type supports subscripting with another type (`C[I]`).

```cpp
#include <pycpp/sfinae/has_subscript.h>
#include <vector>

PYCPP_USING_NAMESPACE

int main()
{
    using vector_type = std::vector<int>;
    static_assert(has_subscript<vector_type, size_t>::value, "");
    static_assert(!has_subscript<int, size_t>::value, "");
    return 0;
}
```

## Member Variable, Function, and Type Detection

### Has Member Function

Macro to detect if a class contains a member function. There are two valid versions of the macro: one that takes the method name and the struct name, and another taking an additional method signature. The method signature is useful when resolving methods with multiple overloads, since the substitution will fail unless a particular overload is selected.

```cpp
#include <pycpp/sfinae/has_member_function.h>
#include <vector>

PYCPP_USING_NAMESPACE

PYCPP_HAS_MEMBER_FUNCTION(reserve, has_reserve);
PYCPP_HAS_MEMBER_FUNCTION(back, has_back, typename C::reference (C::*)());

int main()
{
    using vector_type = std::vector<int>;
    static_assert(has_reserve<vector_type>::value, "");
    static_assert(has_back<vector_type>::value, "");
    static_assert(!has_reserve<int>::value, "");
    static_assert(!has_back<int>::value, "");
    return 0;
}
```

### Has Member Type

Macro to detect if a class contains a member type. The macro takes the member type name and the name of the struct

```cpp
#include <pycpp/sfinae/has_member_type.h>
#include <string>

PYCPP_USING_NAMESPACE

PYCPP_HAS_MEMBER_TYPE(value_type, has_value_type);

int main()
{
    static_assert(has_value_type<std::string>::value, "");
    static_assert(!has_value_type<int>::value, "");
    return 0;
}
```

### Has Member Variable

Macro to detect if a class contains a member type. The macro takes the member variable name and the name of the struct. It will also detect static member variables.

```cpp
#include <pycpp/sfinae/has_member_variable.h>
#include <string>

PYCPP_USING_NAMESPACE

PYCPP_HAS_MEMBER_VARIABLE(npos, has_npos);

int main()
{
    static_assert(has_npos<std::string>::value, "");
    static_assert(!has_npos<int>::value, "");
    return 0;
}
```

## Type Identification

### Is Complex

Check if a type is a specialization of `std::complex`.

```cpp
#include <pycpp/sfinae/is_complex.h>

PYCPP_USING_NAMESPACE

int main()
{
    using complex_type = std::complex<float>;
    static_assert(is_complex<complex_type>::value, "");
    return 0;
}
```

### Is Pair

Check if a type is a specialization of `std::pair`.

```cpp
#include <pycpp/sfinae/is_pair.h>

PYCPP_USING_NAMESPACE

int main()
{
    using pair_type = std::pair<int, int>;
    static_assert(is_pair<pair_type>::value, "");
    return 0;
}
```

### Is Reference Wrapper

Check if a type is a specialization of `std::reference_wrapper`.

```cpp
#include <pycpp/sfinae/is_reference_wrapper.h>

PYCPP_USING_NAMESPACE

int main()
{
    using reference_wrapper_type = std::reference_wrapper<int>;
    static_assert(is_reference_wrapper<reference_wrapper_type>::value, "");
    return 0;
}
```

// TODO:

## Fail Safe Implementations

### Back

Access the last item in a container.

```cpp
#include <pycpp/sfinae/back.h>
#include <set>
#include <vector>

PYCPP_USING_NAMESPACE

int main()
{
    std::set<int> s = {1, 2, 3};
    std::vector<int> v = {1, 2, 3};
    back()(s);      // 3
    back()(v);      // 3
    return 0;
}
```

### Front

Access the first item in a container.

```cpp
#include <pycpp/sfinae/front.h>
#include <set>
#include <vector>

PYCPP_USING_NAMESPACE

int main()
{
    std::set<int> s = {1, 2, 3};
    std::vector<int> v = {1, 2, 3};
    front()(s);      // 1
    front()(v);      // 1
    return 0;
}
```

### Emplace Back

Construct item in-place at end of container.

```cpp
#include <pycpp/sfinae/emplace_back.h>
#include <set>
#include <vector>

PYCPP_USING_NAMESPACE

int main()
{
    std::set<int> s = {1, 2, 3};
    std::vector<int> v = {1, 2, 3};
    emplace_back()(s, 4);
    emplace_back()(v, 4);
    return 0;
}
```

### Emplace Front

Construct item in-place at start of container.

```cpp
#include <pycpp/sfinae/emplace_front.h>
#include <set>
#include <vector>

PYCPP_USING_NAMESPACE

int main()
{
    std::set<int> s = {1, 2, 3};
    std::vector<int> v = {1, 2, 3};
    emplace_front()(s, 0);
    emplace_front()(v, 0);
    return 0;
}
```

// TODO:
