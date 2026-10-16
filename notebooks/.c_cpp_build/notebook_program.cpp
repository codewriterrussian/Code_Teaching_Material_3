
#include <iostream>
using namespace std;

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;

    cout << sizeof(a) << endl;
    cout << sizeof(p) << endl;

    return 0;
}
