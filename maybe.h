#pragma once

#include <utility>
template<typename T> using maybe = std::optional<T>;

#include "monoid.h"


template<Monoid M> maybe<M> mempty<maybe<M>>;

template<Monoid M> maybe<M> mappend(maybe<M> a, maybe<M> b) {
    if (!a) {
        return b;
    }

    if (!b) {
        return a;
    }

    return maybe<M>(mappend(*a, *b));
}

template<typename A, typename B> B foldr(function<B(A, B)> f, B b, maybe<A> ma) {
    if (!ma) {
        return b;
    }
    return f(*ma, b);
}

