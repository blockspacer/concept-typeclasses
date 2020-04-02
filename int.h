#pragma once

#include "monoid.h"
#include "show.h"


template <>
struct instances<int> {
  struct Monoid {
    static int mempty;
    static int mappend(int a, int b);
  };
};

int instances<int>::Monoid::mempty = 0;
int instances<int>::Monoid::mappend(int a, int b) { return a + b; };

template <>
std::string show<int>(int n) {
  return std::to_string(n);
}
