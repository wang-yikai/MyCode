/*
  CS2124
  Exceptions and Assertions
  Sec C
*/

//#define NDEBUG

#include <iostream>
#include <vector>
#include <cstdlib>

#include <exception>
#include <stdexcept>

using namespace std;

struct OurException : public exception {
    OurException(int n) : n(n) {}
    int n;
};

void bar(int n) {
    if (n > 200) {
        // What to do?
        throw 3;
        //        throw exception;
        // throw OurException(n);
        cout << "hello\n";
    }
}
void foo(int n) { bar(n); }

int main() {
    try {
        try {
            foo(300);
        }
        // catch (int x) { cerr << "caught an int: " << x << endl; }
        catch (exception& ex) {
            cerr << "caught an exception " << ex.what() << endl;
        }
    }
    catch (...) { cerr << "So long and thanks for all the fish\n"; }
}
