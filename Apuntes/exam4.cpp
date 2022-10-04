#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    // map tiene un key y un value
    map<string, int> dict;
    string word;

    // contenedor ordenado y sin repeticion
    set<string> stop_words = {"in", "at"};

    // Imprime cada linea la cantidad
    while(getline(cin, word)) {
        // si la palabra no existe
        if (word.begin() == word.end())
            break;
        // si la palabra no es un stop_word se cuenta
        if (stop_words.find(word) == stop_words.end())
            dict[word]++;
    }
    for (const auto& i: dict) {
        cout << "(" << i.first << "," << i.second << ") ";
    } cout << endl;

    vector<int> numbers = {1,3,4,5,2,3,1,3};

    // cuando se incializa set (del mismo tipo nativo) con los iteradores del vector, omite los repetidos
    set<int> no_r_numbers(numbers.begin(), numbers.end());
    cout << numbers.size() << endl;  // out: 8
    cout << no_r_numbers.size() << endl;  // out: 5
}