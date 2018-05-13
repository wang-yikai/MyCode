#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream ifs("test.txt");

	 //attempts to open text file and reads it
	if (!ifs) {
        cerr << "Can not open file!" << endl;
        exit(1);
    }

    int num;
    ifs >> num;

    cout << num << endl;

    //closes file
  	ifs.close();

  	return 0;
}
