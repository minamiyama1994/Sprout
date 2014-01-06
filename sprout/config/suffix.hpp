/*=============================================================================
  Copyright (c) 2011-2013 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_CONFIG_SUFFIX_HPP
#define SPROUT_CONFIG_SUFFIX_HPP

//
// SPROUT_CONSTEXPR
// SPROUT_CONSTEXPR_OR_CONST
// SPROUT_STATIC_CONSTEXPR
// SPROUT_STATIC_CONSTEXPR_DATA_MEMBER_INNER
// SPROUT_STATIC_CONSTEXPR_DATA_MEMBER_OUTER
//
#ifndef SPROUT_CONFIG_DISABLE_CONSTEXPR
#	define SPROUT_CONSTEXPR constexpr
#	define SPROUT_CONSTEXPR_OR_CONST constexpr
#	define SPROUT_STATIC_CONSTEXPR static constexpr
#
#	define SPROUT_STATIC_CONSTEXPR_DATA_MEMBER_INNER(EXPR) = EXPR
#	define SPROUT_STATIC_CONSTEXPR_DATA_MEMBER_OUTER(EXPR)
#else	// #ifndef SPROUT_CONFIG_DISABLE_CONSTEXPR
#	define SPROUT_CONSTEXPR
#	define SPROUT_CONSTEXPR_OR_CONST const
#	define SPROUT_STATIC_CONSTEXPR static const
#
#	define SPROUT_STATIC_CONSTEXPR_DATA_MEMBER_INNER(EXPR)
#	define SPROUT_STATIC_CONSTEXPR_DATA_MEMBER_OUTER(EXPR) = EXPR
#endif	// #ifndef SPROUT_CONFIG_DISABLE_CONSTEXPR

//
// SPROUT_CXX14_CONSTEXPR
//
#ifndef SPROUT_CONFIG_DISABLE_CXX14_CONSTEXPR
#	define SPROUT_CXX14_CONSTEXPR constexpr
#else	// #ifndef SPROUT_CONFIG_DISABLE_CXX14_CONSTEXPR
#	define SPROUT_CXX14_CONSTEXPR
#endif	// #ifndef SPROUT_CONFIG_DISABLE_CXX14_CONSTEXPR

//
// SPROUT_INITIALIZER_LIST_CONSTEXPR
//
#ifndef SPROUT_NO_CXX14_INITIALIZER_LIST
#	define SPROUT_INITIALIZER_LIST_CONSTEXPR SPROUT_CXX14_CONSTEXPR
#else	// #ifndef SPROUT_NO_CXX14_INITIALIZER_LIST
#	define SPROUT_INITIALIZER_LIST_CONSTEXPR
#endif	// #ifndef SPROUT_NO_CXX14_INITIALIZER_LIST

//
// SPROUT_NON_CONSTEXPR
//
#define SPROUT_NON_CONSTEXPR

//
// SPROUT_DEFAULTED_DEFAULT_CONSTRUCTOR_DECL
// SPROUT_DEFAULTED_DESTRUCTOR_DECL
//
#ifndef SPROUT_CONFIG_DISABLE_DEFAULTED_FUNCTIONS
#	define SPROUT_DEFAULTED_DEFAULT_CONSTRUCTOR_DECL = default;
#	define SPROUT_DEFAULTED_DESTRUCTOR_DECL = default;
#else	// #ifndef SPROUT_CONFIG_DISABLE_DEFAULTED_FUNCTIONS
#	define SPROUT_DEFAULTED_DEFAULT_CONSTRUCTOR_DECL {}
#	define SPROUT_DEFAULTED_DESTRUCTOR_DECL {}
#endif	// #ifndef SPROUT_CONFIG_DISABLE_DEFAULTED_FUNCTIONS

//
// SPROUT_DELETED_FUNCTION_DECL
//
#ifndef SPROUT_CONFIG_DISABLE_DELETED_FUNCTIONS
#	define SPROUT_DELETED_FUNCTION_DECL = delete;
#else	// #ifndef SPROUT_CONFIG_DISABLE_DELETED_FUNCTIONS
#	define SPROUT_DELETED_FUNCTION_DECL ;
#endif	// #ifndef SPROUT_CONFIG_DISABLE_DELETED_FUNCTIONS

//
// SPROUT_USE_EXPLICIT_CONVERSION_OPERATORS
// SPROUT_EXPLICIT_CONVERSION
//
#ifndef SPROUT_CONFIG_DISABLE_EXPLICIT_CONVERSION_OPERATORS
#	define SPROUT_USE_EXPLICIT_CONVERSION_OPERATORS 1
#	define SPROUT_EXPLICIT_CONVERSION explicit
#else	// #ifndef SPROUT_CONFIG_DISABLE_EXPLICIT_CONVERSION_OPERATORS
#	define SPROUT_USE_EXPLICIT_CONVERSION_OPERATORS 0
#	define SPROUT_EXPLICIT_CONVERSION
#endif	// #ifndef SPROUT_CONFIG_DISABLE_EXPLICIT_CONVERSION_OPERATORS

//
// SPROUT_NOEXCEPT
// SPROUT_NOEXCEPT_EXPR
// SPROUT_NOEXCEPT_EXPR_OR_DEFAULT
//
#ifndef SPROUT_CONFIG_DISABLE_NOEXCEPT
#	define SPROUT_NOEXCEPT noexcept
#	define SPROUT_NOEXCEPT_EXPR(EXPR) noexcept(EXPR)
#	define SPROUT_NOEXCEPT_EXPR_OR_DEFAULT(EXPR, C) noexcept(EXPR)
#else	// #ifndef SPROUT_CONFIG_DISABLE_NOEXCEPT
#	define SPROUT_NOEXCEPT
#	define SPROUT_NOEXCEPT_EXPR(EXPR)
#	define SPROUT_NOEXCEPT_EXPR_OR_DEFAULT(EXPR, C) C
#endif	// #ifndef SPROUT_CONFIG_DISABLE_NOEXCEPT

//
// SPROUT_USE_TEMPLATE_ALIASES
//
#ifndef SPROUT_CONFIG_DISABLE_TEMPLATE_ALIASES
#	define SPROUT_USE_TEMPLATE_ALIASES 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_TEMPLATE_ALIASES
#	define SPROUT_USE_TEMPLATE_ALIASES 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_TEMPLATE_ALIASES

//
// SPROUT_USE_USER_DEFINED_LITERALS
//
#ifndef SPROUT_CONFIG_DISABLE_USER_DEFINED_LITERALS
#	define SPROUT_USE_USER_DEFINED_LITERALS 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_USER_DEFINED_LITERALS
#	define SPROUT_USE_USER_DEFINED_LITERALS 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_USER_DEFINED_LITERALS

//
// SPROUT_USE_DELEGATING_CONSTRUCTORS
//
#ifndef SPROUT_CONFIG_DISABLE_DELEGATING_CONSTRUCTORS
#	define SPROUT_USE_DELEGATING_CONSTRUCTORS 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_DELEGATING_CONSTRUCTORS
#	define SPROUT_USE_DELEGATING_CONSTRUCTORS 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_DELEGATING_CONSTRUCTORS

//
// SPROUT_USE_UNICODE_LITERALS
//
#ifndef SPROUT_CONFIG_DISABLE_UNICODE_LITERALS
#	define SPROUT_USE_UNICODE_LITERALS 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_UNICODE_LITERALS
#	define SPROUT_USE_UNICODE_LITERALS 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_UNICODE_LITERALS

//
// SPROUT_USE_VARIABLE_TEMPLATES
//
#ifndef SPROUT_CONFIG_DISABLE_VARIABLE_TEMPLATES
#	define SPROUT_USE_VARIABLE_TEMPLATES 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_VARIABLE_TEMPLATES
#	define SPROUT_USE_VARIABLE_TEMPLATES 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_VARIABLE_TEMPLATES

//
// SPROUT_USE_BUILTIN_CMATH_FUNCTION
//
#ifndef SPROUT_CONFIG_DISABLE_BUILTIN_CMATH_FUNCTION
#	define SPROUT_USE_BUILTIN_CMATH_FUNCTION 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_BUILTIN_CMATH_FUNCTION
#	define SPROUT_USE_BUILTIN_CMATH_FUNCTION 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_BUILTIN_CMATH_FUNCTION

//
// SPROUT_USE_BUILTIN_BIT_OPERATION
//
#ifndef SPROUT_CONFIG_DISABLE_BUILTIN_BIT_OPERATION
#	define SPROUT_USE_BUILTIN_BIT_OPERATION 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_BUILTIN_BIT_OPERATION
#	define SPROUT_USE_BUILTIN_BIT_OPERATION 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_BUILTIN_BIT_OPERATION

//
// SPROUT_NOERROR_LARGE_FLOAT_ROUNDING
//
#ifndef SPROUT_CONFIG_DISABLE_LARGE_FLOAT_ROUNDING
#	define SPROUT_NOERROR_LARGE_FLOAT_ROUNDING 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_LARGE_FLOAT_ROUNDING
#	define SPROUT_NOERROR_LARGE_FLOAT_ROUNDING 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_LARGE_FLOAT_ROUNDING

//
// SPROUT_USE_INDEX_ITERATOR_IMPLEMENTATION
//
#ifndef SPROUT_CONFIG_DISABLE_SUPPORT_TEMPORARY_CONTAINER_ITERATION
#	define SPROUT_USE_INDEX_ITERATOR_IMPLEMENTATION 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_SUPPORT_TEMPORARY_CONTAINER_ITERATION
#	ifdef SPROUT_CONFIG_SUPPORT_TEMPORARY_CONTAINER_ITERATION
#		error config conflict: SPROUT_CONFIG_DISABLE_SUPPORT_TEMPORARY_CONTAINER_ITERATION, SPROUT_CONFIG_DISABLE_SUPPORT_TEMPORARY_CONTAINER_ITERATION
#	endif	// #ifndef SPROUT_CONFIG_SUPPORT_TEMPORARY_CONTAINER_ITERATION
#	define SPROUT_USE_INDEX_ITERATOR_IMPLEMENTATION 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_SUPPORT_TEMPORARY_CONTAINER_ITERATION

//
// SPROUT_USE_PTR_INDEX_ITERATOR_IMPLEMENTATION
//
#ifndef SPROUT_CONFIG_DISABLE_SUPPORT_EFFICIENT_ARRAY_ITERATION
#	define SPROUT_USE_PTR_INDEX_ITERATOR_IMPLEMENTATION 1
#else	// #ifndef SPROUT_CONFIG_DISABLE_SUPPORT_EFFICIENT_ARRAY_ITERATION
#	define SPROUT_USE_PTR_INDEX_ITERATOR_IMPLEMENTATION 0
#endif	// #ifndef SPROUT_CONFIG_DISABLE_SUPPORT_EFFICIENT_ARRAY_ITERATION

//
// HDR_FUNCTIONAL_SSCRISK_CEL_OR_SPROUT
// HDR_ALGORITHM_MIN_MAX_SSCRISK_CEL_OR_SPROUT
// NS_SSCRISK_CEL_OR_SPROUT
//
#ifndef SPROUT_CONFIG_USE_SSCRISK_CEL
#	define HDR_FUNCTIONAL_SSCRISK_CEL_OR_SPROUT <sprout/functional/functor.hpp>
#	define HDR_ALGORITHM_MIN_MAX_SSCRISK_CEL_OR_SPROUT <sprout/detail/algorithm_min_max.hpp>
#	define NS_SSCRISK_CEL_OR_SPROUT sprout
#else	// #ifndef SPROUT_CONFIG_USE_SSCRISK_CEL
#	define HDR_FUNCTIONAL_SSCRISK_CEL_OR_SPROUT <sscrisk/cel/functional.hpp>
#	define HDR_ALGORITHM_MIN_MAX_SSCRISK_CEL_OR_SPROUT <sscrisk/cel/algorithm.hpp>
#	define NS_SSCRISK_CEL_OR_SPROUT sscrisk::cel
#endif	// #ifndef SPROUT_CONFIG_USE_SSCRISK_CEL

#endif	// #ifndef SPROUT_CONFIG_SUFFIX_HPP
