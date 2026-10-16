
#include <iostream>
using namespace std;

int main() {
    int a[5] = {10, 20, 30, 40, 50};


    cout << *max_element(a,a+4) << endl;

    return 0;
}
