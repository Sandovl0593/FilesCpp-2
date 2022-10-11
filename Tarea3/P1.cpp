#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>
#include <deque>
#include "p1.h"
using namespace std;

/* int main() {
    deque<int> cnt {istream_iterator<int>(cin), istream_iterator<int>()};
    // deque<int> cnt = {3,4,5,6,7,8, 9, 10, 11, 12};
    auto res1 = split_range(cnt, 5);
    for (const auto& row : res1) {
        for (const auto& item : row)
            cout << item << " ";
        cout << endl;
    }

    list<int> cnt2{istream_iterator<int>(cin), istream_iterator<int>()};
    auto res2 = split_range(cnt2, 2);
    for (const auto& row : res2) {
        for (const auto& item : row)
            cout << item << " ";
    }

    vector<int> vec{istream_iterator<int>(cin), istream_iterator<int>()};
    forward_list<int> cnt3{begin(vec), end(vec)};
    auto res3 = split_range(cnt3, 3);
    for (const auto& row : res3) {
        for (const auto& item : row)
            cout << item << " ";
    }
} */