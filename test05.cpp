#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Treat {
  friend ostream& operator<<(ostream& os, const Treat& aTreat);
public:
  Treat(const string& name) : name(name) {}
private:
  string name;
};

class Baker {
  friend ostream& operator<<(ostream& os, const Baker& aBaker);
private:
  size_t theCapacity;
  size_t theSize;
  string name;
  Treat** treats;
public:
  Baker(const string& name) : name(name), theSize(0), theCapacity(0), treats(nullptr) {}

  Baker(const Baker& another) : name(another.name), theSize(another.theSize), theCapacity(another.theCapacity) {
    cout << "Copy Constructor!" << endl;
    treats = new Treat*[theCapacity];
    for(size_t i = 0; i < theSize; ++i) {
      if (another.treats[i]) {
        treats[i] = new Treat(*another.treats[i]);
      }
    }
  }

  Baker& operator=(const Baker& rhs) {
    if (this != &rhs) {
      if (treats) {
        for(size_t i = 0; i < theSize; ++i ) {
            delete treats[i];
        }

        delete[] treats;
      }

      name = rhs.name;
      theSize = rhs.theSize;
      theCapacity = rhs.theCapacity;
      treats = new Treat*[theCapacity];

      for(size_t i = 0; i < theSize; ++i) {
        if (rhs.treats[i]) {
          treats[i] = new Treat(*rhs.treats[i]);
        }
      }
    }

    return *this;
  }

  void bakes(const string& treatName) {
    if (!treats) {
      theCapacity = 2;
      treats = new Treat*[theCapacity];
    }
    else if (theSize == theCapacity) {
      theCapacity *= theCapacity;
      Treat** nextTreats = new Treat*[theCapacity];
      for(size_t i = 0; i < theSize; ++i) {
        nextTreats[i] = treats[i];
      }
      delete[] treats;
      treats = nextTreats;
    }
    treats[theSize] = new Treat(treatName);
    ++theSize;
  }

  Treat** delivers() {
    if (treats) {
      Treat** deliveredTreats = new Treat*[theCapacity];
      for(size_t i = 0; i < theSize; ++i) {
        if (treats[i]) {
          deliveredTreats[i] = new Treat(*treats[i]);
          delete treats[i];
        }
      }
      delete[] treats;
      theSize = 0;
      theCapacity = 0;
      treats = nullptr;
      return deliveredTreats;
    }
    return nullptr;
  }

  size_t getSize() const {
    return theSize;
  }

};

ostream& operator<<(ostream& os, const Treat& aTreat) {
  os << aTreat.name;
  return os;
}

ostream& operator<<(ostream& os, const Baker& aBaker) {
  os << "Baker: " << aBaker.name << ";";
  if (aBaker.treats) {
    for(size_t i = 0; i < aBaker.theSize; ++i) {
      os << " " << *(aBaker.treats[i]);
    }
    os << ".";
  }
  else {
    os << " No treats :-(";
  }
  return os;
}

bool operator==(const Baker& lhs, const Baker& rhs) {
  return lhs.getSize() == rhs.getSize();
}

int main() {
  Baker fred("fred");
  cout << fred << endl;
  fred.bakes("Twinkie");
  fred.bakes("Cupcake");
  fred.bakes("Twinkie");
  fred.bakes("Twinkie");
  fred.bakes("Cupcake");
  fred.bakes("Wonderbread");
  cout << fred << endl;

  Baker joe("joe");
  cout << joe << endl;
  joe = fred;
  cout << fred << endl;
  cout << joe << endl;
  Baker bob = fred;
  cout << bob << endl;
  cout << (bob == fred) << endl;

  fred.delivers();
  cout << fred << endl;
  cout << joe << endl;
  cout << (joe == fred) << endl;
}
