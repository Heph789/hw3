#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

Stack<int> readStack(const char* filename)
{
    ifstream ifile(filename);
    Stack<int> h;
    int v;
    while ( ifile >> v ) {
        h.push(v);
    }
    return h;
}

void popOut(Stack<int>& s)
{
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main(int argc, char* argv[]) {
    Stack<int> s = readStack(argv[1]);
    cout << s.size() << endl;
    popOut(s);
    cout << endl;
    try {
        s.top();
    }
    catch (std::underflow_error& err) {
        cout << err.what() << endl;
    }
    try {
        s.pop();
    }
    catch (std::underflow_error& err) {
        cout << err.what() << endl;
    }
}