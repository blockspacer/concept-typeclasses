#pragma once

#include <algorithm>
#include <vector>
using std::vector;

#include "monoid.h"
#include "foldable.h"

template<typename T> vector<T> mempty<vector<T>>;

template<typename T> vector<T> mappend(vector<T> a, vector<T> b) {
    vector<T> result(a.size() + b.size());
    std::copy(b.begin(), b.end(), std::copy(a.begin(), a.end(), result.begin()));
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

template<typename A, typename B>
B foldr(function<B(A, B)> f, B b, vector<A> as) {
    if (as.empty()) {
        return b;
    }
    return f(head(as), foldr(f, b, tail(as)));
}
