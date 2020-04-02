#pragma once

#include <algorithm>
#include <vector>
using std::vector;

#include "monoid.h"
#include "foldable.h"


template <typename T>
struct instances<vector<T>> {
  struct Monoid {
    static vector<T> mempty;
    static vector<T> mappend(vector<T> a, vector<T> b);
  };
};

template<typename T> vector<T> instances<vector<T>>::Monoid::mempty {};
template<typename T> vector<T> instances<vector<T>>::Monoid::mappend(vector<T> a, vector<T> b) {
    vector<T> result(a.size() + b.size());
    auto it = std::copy(a.begin(), a.end(), result.begin());
    std::copy(b.begin(), b.end(), it);
    return result;
}


template<typename T> T head(vector<T> vec) {
    return vec[0];
}

template<typename T> vector<T> tail(vector<T> vec) {
    vector<T> result(vec.size() - 1);
    std::copy(vec.begin() + 1, vec.end(), result.begin());
    return result;
}

template<typename Fn, typename A, typename B = std::invoke_result<Fn, A>>
B foldr(Fn f, B b, vector<A> as) {
    if (as.empty()) {
        return b;
    }
    return f(head(as), foldr(f, b, tail(as)));
}
