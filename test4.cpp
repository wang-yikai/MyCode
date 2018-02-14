#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// class Person {
//     public:
//         Person() : spouse(nullptr), dob(1,2,3) {}
//
//         bool marries(Person& bethrothed) {
//             if(bethrothed == nullptr && spouse == nullptr) {
//                 spouse = &bethrothed;
//                 bethrothed.spouse = this; //reference
//                 return true;
//             }
//             return false;
//         }
//     private:
//         class Date {
//         public:
//             Date(int m, int d, int y): month(m), day(d), year(y) {
//                 /* modifying, not initializing
//                 month = m;
//                 day = d;
//                 year = y;
//                 */
//             }
//
//         private:
//             const int year, day, month;
//         };
//     Person* spouse;
//     Date dob;
// };

int main() {
    // Call stack
    // Heap (dynamic memory - all used in python)
    // Globals
    // Code

    //new int(17) -> memory leak (garbage on the heap, only freed after process terminates)
    //C++ does not have a garbage collection
    int* a = new int(17);//a is the local variable
    delete a; //a is unaffected, but heap is

    cout << a << endl;
    cout << *a << endl;//value would be weird

    int w = 50;
    const int y = 20;
    int x = 40;
    // int* p = &y;
    const int* p = &y; //cannot change the contents of y, but can point to another variable
    p = &x;
    //*p = 30; //p is read only

    int* const z = &w; //can only refer to &w
    // int* const z = &y; //will fail
    *z = 30;

    const int* const u = nullptr; //can't change reference
    // u = &w;
}
