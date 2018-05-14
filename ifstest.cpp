#include <iostream>
#include <fstream>
using namespace std;

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
//
// class Performer{
// public:
// 	Performer(const string& name) : theName(name) {}
// 	virtual void perform() = 0;
// protected:
// 	const string& getName() const { return theName; }
// private:
// 	string theName;
// };
//
//
// class Actor : public Performer{
// public:
// 	Actor(const string& name, const string& script) : Performer(name), theScript(script) {}
// 	void perform(){
// 		cout << "I am " << getName() << ". Script: " << theScript << endl;
// 	}
// private:
// 	string theScript;
// };
//
// class Mime : public Performer{
// public:
// 	Mime(const string& name) : Performer(name) {}
// 	void perform(){
// 		cout << "BLANK" << endl;
// 	}
// private:
// };
//
// class Theater{
// public:
// 	Theater() {}
// 	void showtime(){
// 		for (size_t i = 0; i < performers.size(); i++){
// 			performers[i]->perform();
// 		}
// 	}
// 	void hire(Performer& newPerformer){
// 	    //param can't be const, push_back error
// 		performers.push_back(&newPerformer);
// 	}
// private:
// 	vector<Performer*> performers;
// };
//
//
//
//
// template <typename I, typename V>
// int count(I start, I end, V val){
//         int sum = 0;
//         for(I i = start; i != end; i++){
//                 if(*i == val){
//                         sum += 1;
//                 }
//         }
//         return sum;
// }
//
//
//
// int main()
// {
// //     cout<<"Hello World\n";
//
// //     Book b(32);
// // 	Magazine m(42);
//
// // 	cout << "Calling displayNumPages():\n";
// // 	b.displayNumPages();//420 then 32
// // 	m.displayNumPages();//42
// // 	cout << endl;
//
//
// // 	int arr[6];
// // 	for(int i = 0; i < 6; ++i) arr[i] = i + 5;
//
// // 	cout << (find(arr + 6, arr, -5) == arr) << endl;
//
//     int arr[6];
//
//     for(int i = 0; i < 6; ++i) arr[i] = 5;
//
//     cout << count(arr, arr + 6, 4) << endl;
//
//     Actor boi("Dat Boi", "Waddup");
//     boi.perform();
//
//     return 0;
// }


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
