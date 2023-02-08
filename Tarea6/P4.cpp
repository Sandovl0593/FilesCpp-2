#include <iostream>
#include <string>
#include <queue>
#include "P4.h"
using namespace std;

string process_text_by_queue(const string& source) {
    queue<char> charrs;
    string delets = "";
    for (const char &chr: source) {
        if (chr != '*') {
            charrs.push(chr);
        } else {
            delets += charrs.front();  charrs.pop();
        }
    } return delets;
}