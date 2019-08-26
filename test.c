#include <iostream>

using namespace std;


int gcd(int a, int b) {
  if (a==b) {
    return a;
  }
  if (a > b) {
    cout << "here" << endl;
    return gcd(a, b -a );
  }
  else {
    return gcd(a - b, a);
  }
}

template <typename T, int count>
void foo(T x) {
  T val[count];
  for (int i = 0; i < count; i++) {
    val[i] = x++;
    cout << val[i] << " ";
  }
}

int main()
{
    float y = 2.1;
    foo<float, 3>(y);

    char a = -6;
    char b = -128;
    char result = a + b;
    cout << "result " << +result << endl;

    // unsigned char ch = 0;
    // int count = 0;
    // while(++ch <= 255) {
    //   count++;
    // }
    // cout << count << endl;

    int i = 5, j = 2;
    printf("%d %d\n", i << j, i >> j);

    // char ptr1[] = "Hello World";
    // // char *ptr2 = malloc(5);
    // ptr2 = ptr1;
    // cout << ptr2 << endl;
    // ptr2[0] = 'J';
    // cout << ptr2 << endl;

    cout << gcd(15, 21) << endl;
    return 0;
}
