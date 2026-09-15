
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {10, 20, 30};

    a.push_back(40);
    a.push_back(50);

    cout << a.size() << endl;

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}
