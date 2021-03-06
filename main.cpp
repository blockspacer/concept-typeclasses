#include <iostream>
using std::cout;
using std::endl;

#include "monoid.h"
#include "foldable.h"
#include "string.h"
#include "vector.h"
#include "maybe.h"


template<> int mempty<int> = 0;
template<> int mappend(int a, int b) { return a + b; }

function<int(int, int)> add = [](int a, int b) {
    return a + b;
};

int main() {
    string foo = "foo";
    string bar = "bar";

    cout << "String mappend (should be foobarfoo)" << endl;
    cout << mappend(foo, mappend(mappend(bar, mempty<string>), foo)) << endl;

    vector<int> v1 {3, 4, 5};
    vector<int> v2 {6, 7, 8};

    cout << "Vector mempty (should be blank)" << endl;
    for (auto i : mempty<vector<int>>) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "Vector mappend (should be 3 4 5 6 7 8)" << endl;
    for (auto i : mappend(v1, v2)) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "Vector foldr (should be 22)" << endl;
    cout << foldr(add, 1, v2) << endl;

    cout << "Maybe mappend (should be 13)" << endl;
    cout << *mappend(maybe<int>(4), maybe<int>(9)) << endl;

    cout << "Maybe foldr (should be 6 7)" << endl;
    cout << foldr(add, 6, maybe<int>()) << ' ' << foldr(add, 6, maybe<int>(1)) << endl;

    return 0;
}
