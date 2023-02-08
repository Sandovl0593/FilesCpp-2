#include <iostream>
#include <string>
#include <stack>
#include "P5.h"
using namespace std;

bool is_equation_balanced(string source) {
    stack<char> operacion;
    for (const char& i: source)
        if (i != ' ')  operacion.push(i);

    string signs = "";
    string def_signs = "";
    int c = 0;
    while (!operacion.empty()) {
        char actu = operacion.top();
        string first = def_signs.substr(0, c);
        string last = def_signs.substr(c, c);
        switch (actu) {
            case ')': signs = ')' + signs;  def_signs = first + "()" +  last; c++;
                break;
            case ']': signs = ']' + signs;  def_signs = first + "[]" +  last; c++;
                break;
            case '}': signs = '}' + signs;  def_signs = first + "{}" +  last; c++;
                break;
            case '(': signs = '(' + signs;
                break;
            case '[': signs = '[' + signs;
                break;
            case '{': signs = '{' + signs;
                break;
            default:   break;
        }
        operacion.pop();
    }
    return signs == def_signs;
}

int main() {
    cout << std::boolalpha << is_equation_balanced("((10 + 20) + 30)") << endl; //true
    cout << std::boolalpha << is_equation_balanced("((10 +(30 * 1 + 2))") << endl; //false
    cout << std::boolalpha << is_equation_balanced("(10 + (15 + 4/2 - 5)))") << endl; //false
    cout << std::boolalpha << is_equation_balanced("{ (6 + 20} + 4)") << endl; //false
    cout << std::boolalpha << is_equation_balanced("{ [ (4 - 5) * 3] + 14}") << endl; //true
}