#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Parts {
private:
  int * number;
public:
  Parts(int num) : number(new int(num)) {}

  ~Parts() { delete number; }

  Parts(const Parts& another) {
    delete number;
    number = another.number;
  }

  Parts& operator=(const Parts& rhs) {
    if (this != &rhs) {
      delete number;
      number = rhs.number;
    }

    return *this;
  }
};

class Engine : public Parts {
private:
  double* horsepwr;
public:
  Engine(int num, double power): Parts(num), horsepwr(new double(power)) {}
  Engine& operator=(const Engine& rhs) {
    if (this != &rhs) {
      delete horsepwr;
      Parts::operator=(rhs);
      horsepwr = rhs.horsepwr;
    }
    return *this;
  }
};

class Car {
private:
  Parts** theParts;
  size_t theSize;
public:
  Car(const Car& another): theSize(another.theSize) {
    if (another.theParts) {
      theParts = new Parts*[theSize];
      for(size_t i = 0; i < theSize; ++i) {
        theParts[i] = new Parts(*another.theParts[i]);
      }
    }
    else {
      theParts = nullptr;
    }
  }

  ~Car() {
    for(size_t i = 0; i < theSize; ++i) {
      delete theParts[i];
    }
    delete[] theParts;
  }

  Car& operator=(const Car& rhs) {
    if (this != &rhs) {
      if (theParts) {
        for(size_t i = 0; i < theSize; ++i) {
          delete theParts[i];
        }
        delete[] theParts;
      }

      theSize = rhs.theSize;

      if (rhs.theParts) {
        theParts = new Parts*[theSize];
        for(size_t i = 0; i < theSize; ++i) {
          theParts[i] = new Parts(*rhs.theParts[i]);
        }
      }
      else {
        theParts = nullptr;
      }
    }

    return *this;
  }
};

int main() {

}
