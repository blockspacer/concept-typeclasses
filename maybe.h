#pragma once

#include <optional>
#include "base.h"
#include "monoid.h"
#include "show.h"
#include "int.h"
#include "foldable.h"

template <typename T>
using maybe = std::optional<T>;


template <Monoid T>
struct instances<maybe<T>> {
  struct Monoid {
    static maybe<T> mempty;
    static maybe<T> mappend(maybe<T> a, maybe<T> b);
  };
};

template<Monoid T> maybe<T> instances<maybe<T>>::Monoid::mempty {};
template<Monoid T> maybe<T> instances<maybe<T>>::Monoid::mappend(maybe<T> a, maybe<T> b) {
    if (!a) { return b; }
    if (!b) { return a; }

    return maybe<T>(instances<T>::Monoid::mappend(*a, *b));
}

template <Show A>
std::string show(maybe<A> ma) {
    if (!ma) {
        return "Nothing";
    }
    return "Just " + show(*ma);
}

template <typename Fn, typename A, typename B = std::invoke_result<Fn, A>>
B foldr(Fn f, B b, maybe<A> ma) {
  if (!ma) {
    return b;
  }
  return f(*ma, b);
}
