#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
  Employee(const string& employeeName) : name(employeeName), boss(nullptr) {}

  void display() const {
    cout << "Name: " << name << "; ";
    cout << "Boss: ";
    if (boss == nullptr) {
      cout << "none; ";
    }
    else {
      cout << boss -> name << "; ";
    }
    cout << "Staff:";
    if (staff.size() == 0) {
      cout << " none.\n";
    }
    else {
      for (Employee* worker : staff) {
        cout << " " << worker -> name;
      }
      cout << ".\n";
    }
  }

  bool hire(Employee& worker) {
    if ((boss != &worker) && (this != &worker) && (worker.boss == nullptr)) {
      worker.boss = this;
      staff.push_back(&worker);
      return true;
    }
    return false;
  }

  bool quit() {
    if (boss != nullptr) {
      for(size_t i = 0; i < boss -> staff.size(); ++i) {
        if (boss -> staff[i] == this) {
          boss -> staff[i] = boss -> staff[boss -> staff.size() - 1];
          boss -> staff.pop_back();
          boss = nullptr;
          return true;
        }
      }
    }
    return false;
  }

private:
  string name;
  Employee* boss;
  vector<Employee*> staff;
};

int main() {
  Employee groucho("Groucho");
  Employee harpe( "Harpe");
  Employee chico("Chico");
  Employee zeppo("Zeppo");
  //Status
  groucho.display();
  harpe.display();
  chico.display();
  zeppo.display();
  cout << "=====\n";
  groucho.hire(harpe); // return true
  harpe.hire(groucho); // return false
  groucho.hire(zeppo); // return true
  groucho.hire(chico); // return true
  //Status
  groucho.display();
  harpe.display();
  chico.display();
  zeppo. display();
  cout << "=====\n";
  harpe.quit();
  harpe.hire(groucho);
  //Status
  groucho.display();
  harpe.display();
  chico.display();
  zeppo.display();
  cout << "=====\n";
}
