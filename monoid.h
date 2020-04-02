#pragma once

#include "base.h"

/*
 * Monoid: a set with an associative binary operation and an identity
 */

template<typename T>
concept bool Monoid = requires(T a) {
    { mempty<T> } -> T;
    { mappend<T>(a, a) } -> T;
};

