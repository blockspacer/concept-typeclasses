#pragma once

#include <string>
using std::string;

template<> string mempty<string> = "";
template<> string mappend<string>(string a, string b) { return a + b; }

