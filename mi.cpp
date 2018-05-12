#include <iostream>
#include <vector>
using namespace std;

// Mulitple inheritance

// Mixin
class Flier {
public:
  // virtual Flier() {}
    virtual void fly() { cout << "I can fly!!!\n"; }
};

class Animal {
public:
    virtual void display() { cout << "Animal\n"; }
};

class Bat : public Animal, public Flier { };

class Insect : public Animal, public Flier {
public:
    void fly() { cout << "Bzzzz. ";  Flier::fly();  }
};

class Plane : public Flier {};

// ==========================================

class Student {
public:
    virtual void display() const { cout << "Student\n"; }
};

class Instructor {
public:
    virtual void display() const { cout << "Instructor\n"; }
};

class TA : public Student, public Instructor {
public:
    //using Student::display;
    void display() const override {
        Student::display();
        Instructor::display();
    }
};

ostream& operator<<(ostream& os, const Student& rhs) {
  rhs.display();
  return os;
}

int main() {
    Bat battie;
    battie.display();
    battie.fly();
    Plane sopwithCamel;
    Insect lady;

    cout << "==========\n";
    vector<Flier*> vf;
    vf.push_back(&battie);
    vf.push_back(&sopwithCamel);
    vf.push_back(&lady);
    for (Flier* flier : vf) flier->fly();

    TA rohit;
    cout << rohit << endl;
    //line below will not compile!
     // rohit.display();  // ambiguous}
    // rohit.Student::display();  // ambiguous
}
