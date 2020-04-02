#pragma once

#include <string>
using std::string;

#include "show.h"

template <>
struct instances<string> {
  struct Monoid {
    static string mempty;
    static string mappend(string a, string b);
  };
};

string instances<string>::Monoid::mempty = "";
string instances<string>::Monoid::mappend(string a, string b) { return a + b; }

template <>
std::string show<string>(string s) {
  return s;
}
