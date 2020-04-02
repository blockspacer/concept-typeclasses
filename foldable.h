#pragma once

/*
 * Foldable: a structure over which one can fold
 */

#include <type_traits>


template<template<typename> typename T, typename Fn, typename A, typename B = std::invoke_result<Fn, A>>
B foldr(Fn, B, T<A>);

template<template<typename> typename T, typename Fn, typename A, typename B = std::invoke_result<Fn, A>>
concept bool Foldable = requires(T<A> t, Fn f, B b) {
    { foldr(f, b, t) } -> B;
};

