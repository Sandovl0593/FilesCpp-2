#include <iostream>
#include <memory>
#include <vector>
#include <iterator>
#include "p9.h"
using namespace std;

int main() {
    fixed_stack<int, 5> fs0 = {1, 2, 3, 4, 5};
    while (!fs0.empty()){
        cout << fs0.top() << " ";
        fs0.pop();
    }

    fixed_stack<int, 100> fs1;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), fixed_stack_pusher(fs1));
    while (!fs1.empty()){
        cout << fs1.top() << " ";
        fs1.pop();
    }

    fixed_stack<float, 100> fs2;
    // vector<float> vc2{istream_iterator<float>(cin), istream_iterator<float>()};
    vector<float> vc2 = {1, 2, 3, 4, 5, 6, 7, 8};
    for(const auto& item: vc2)
        fs2.push(item);
    while (!fs2.empty()){
        cout << fs2.top() << " ";
        fs2.pop();
    }

    fixed_stack<float, 5> fs3;
    // vector<float> vc1{istream_iterator<float>(cin), istream_iterator<float>()};
    vector<float> vc1 = {1, 2, 3, 4, 5, 6, 7, 8};
    for(const auto& item: vc1)
        if (!fs3.push(item))
            break;
    while (!fs3.empty()) {
        cout << fs3.top() << " ";
        fs3.pop();
    }

    fixed_stack<unique_ptr<pair<int, int>>, 7> fs4;
    int n = 0;
    cin >> n;
    vector<pair<int, int>> vc3(n);
    for (auto& item: vc3)
        cin >> item.first >> item.second;

    for (auto& item: vc3)
       if (!fs4.push(make_unique<pair<int, int>>(item)))
            break;

    while (!fs4.empty()){
        cout << fs4.top()->first << " " << fs4.top()->second << endl;
        fs4.pop();
    }
}