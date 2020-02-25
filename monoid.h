#pragma once

/*
 * Monoid: a set with an associative binary operation and an identity
 */

template<typename T> T mempty;
template<typename T> T mappend(T, T);

template<typename T>
concept bool Monoid = requires(T a) {
    { mempty<T> } -> T;
    { mappend(a, a) } -> T;
};

