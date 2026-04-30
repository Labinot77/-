#include <iostream>
#include <vector>

using namespace std;

int maxElement(const vector<int>& n);

int main() {
    vector<int> v;

    for (int i = 0; i <= 10; i++) {
        v.push_back(i * 2);
    };
    
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);

    cout << "Size of " << v.size() << endl;

    for (int i = 0; i < v.size(); i++) {
        cout << "v[" << v[i] << "]" << endl;
    };

    cout << "Max: " << maxElement(v) << endl;

    return 0;
}

int maxElement(const vector<int>& v) {
    int maxVal = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > maxVal) {
            maxVal = v[i];
        }
    }

    return maxVal;
}