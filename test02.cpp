#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
  Person(const string& theName): name(theName), parent(nullptr) {}

  void adopt(Person& child) {
    if((child.parent == nullptr) && (this != &child) && (parent != &child)) {
      child.parent = this;
      children.push_back(&child);
    }
  }

  void display() const {
    cout << "Person: " << name << "; ";
    cout << "Parent: ";
    if (parent == nullptr) {
      cout << "none; ";
    }
    else {
      cout << parent -> name << "; ";
    }
    cout << "Children:";
    if (children.size() == 0) {
      cout << " none." << endl;
    }
    else {
      for(Person* child : children) {
        cout << " " << child -> name;
      }
      cout << ".\n";
    }
  }

  void runaway() {
    if (parent != nullptr) {
      for(size_t i = 0; i < parent -> children.size(); ++i) {
        if (parent -> children[i] == this) {
          for(size_t replace = i; replace < parent -> children.size() - 1; ++replace) {
            Person* placeholder = parent -> children[replace];
            parent -> children[replace] = parent -> children[replace + 1];
            parent -> children[replace + 1] = placeholder;
          }
          parent -> children.pop_back();
          parent = nullptr;
          return;
        }
      }
    }
  }

private:
  string name;
  Person* parent;
  vector<Person*> children;
};

int main() {
  Person moe("Moe");
  Person larry("Larry");
  Person curly("Curly");
  Person curly2("Curly");

  moe.adopt(larry);
  larry.display();
  moe.adopt(curly);
  moe.adopt(curly2);
  moe.display();
  larry.adopt(moe);
  moe.adopt(larry);
  moe.display();

  larry.runaway();
  larry.adopt(moe);
  moe.display();
  larry.display();
}
