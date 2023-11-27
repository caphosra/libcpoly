#pragma once

//
// decltype in C++ can be used as an alternative for typeof.
//
#if defined(__cplusplus)
#   define TYPEOF(x) decltype(x)
//
// The keyword "typeof" has been standardized since C23.
//
#elif __STDC_VERSION__ >= 202311L
#   define TYPEOF(x) typeof(x)
//
// The keyword typeof is implemented as an original feature.
//
#elif defined(MODC_NATIVE_TYPEOF)
#   define TYPEOF(x) MODC_NATIVE_TYPEOF (x)
//
// A predefined __typeof__ is available on GNUC (and clang).
//
#elif defined(__GNUC__)
#   define TYPEOF(x) __typeof__(x)
//
// Throw an error unless MODC_DISABLE_TYPEOF_FEATURES is declared.
//
#elif !defined(MODC_DISABLE_TYPEOF_FEATURES)
#   error You should provide `typeof` by declaring MODC_NATIVE_TYPEOF. \
        If you cannot do that, you should declare MODC_DISABLE_TYPEOF_FEATURES instead.
#endif