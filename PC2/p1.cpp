#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class printt {
    string ctr;
public:
    printt(string c=" "): ctr(c) {}
    void operator() (pair<int, int> s) { cout << s.first << ctr; }
};

vector<int> delete_duplicate(vector<int> cont) {
    vector<int> result(begin(cont), end(cont));
    auto ende = end(result);
    for (auto it = begin(result); it != ende; ++it) {
        ende = remove(it +1, ende, *it);
    }
    result.erase(ende, end(result));
    return result;
}

int main() {
    srand(time(NULL));
    vector<int> vec(1000);
    cout << "Vector generado.... ";
    generate(begin(vec), end(vec), [](){return 1+rand()%199;});
    cout << "Done" << endl;

    // no repetidos
    delete_duplicate(vec);

    map<int, int> count;
    cout << "Numero" << setw(10) << "Cifras" << endl;
    for (auto i=begin(vec); i!=end(vec); advance(i, 1)) {
        cout << setw(3) << *i << setw(10) << to_string(*i).size() << endl;
        count[*i] = to_string(*i).size();
    }

    cout << "Por cifras: " << endl;

    list<pair<int, int>> list3(begin(count), end(count));
    list3.remove_if([](pair<int, int> x) { return (x.second != 3); });
    cout << "3 cifras: ";
    for_each(list3.begin(), list3.end(), printt(", ")); cout << endl;
    
    list<pair<int, int>> list2(begin(count), end(count));
    list2.remove_if([](pair<int, int> x) { return (x.second != 2); });
    cout << "2 cifras: ";
    for_each(list2.begin(), list2.end(), printt(", ")); cout << endl;
    
    list<pair<int, int>> list1(begin(count), end(count));
    list1.remove_if([](pair<int, int> x) { return (x.second != 1); });
    cout << "1 cifras: ";
    for_each(list1.begin(), list1.end(), printt(", ")); cout << endl;
    
}