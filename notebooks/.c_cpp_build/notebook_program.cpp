
#include <iostream>
using namespace std;

void calculate(int a, int b, int& sum, int& product){
    sum = a + b;
    product = a * b;
}

int main() {

    int s,p;

    calculate(3,4,s,p);

    cout << s <<endl;
    cout << p <<endl;

    return 0;
}
