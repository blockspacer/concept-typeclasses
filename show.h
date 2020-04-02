#pragma once

#include <string>

template<typename T>
std::string show(T t);

template <typename T>
concept bool Show = requires (T a) {
    { show(a) } -> std::string;
};
