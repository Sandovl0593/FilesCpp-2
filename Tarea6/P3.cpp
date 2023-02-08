#include <iostream>
#include <string>
#include <stack>
#include "P3.h"
using namespace std;

string process_text_by_stack(string source) {
    stack<char> charrs;
    string delets = "";
    for (const char &chr: source) {
        if (chr != '*') {
            charrs.push(chr);
        } else {
            delets += charrs.top();  charrs.pop();
        }
    } return delets;
}