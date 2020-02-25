#pragma once

/*
 * Foldable: a structure over which one can fold
 */

#include <functional>
using std::function;

template<template<typename> typename T, typename A, typename B>
B foldr(function<B(A, B)>, B, T<A>);

template<template<typename> typename T, typename A, typename B>
concept bool Foldable = requires(T<A> t, function<B(A, B)> f, B b) {
    { foldr(f, b, t) } -> B;
};

