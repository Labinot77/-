#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addElement(vector<int>& v);
void printVector(const vector<int>& v);
void sortVector(vector<int>& v);
void binarySearchElement(vector<int>& v);
void clearVector(vector<int>& v);
void isEmpty(const vector<int>& v);

int main() {
    vector<int> v;
    int choice;

    do {
        cout << "\n===== BINARY SEARCH MENU =====\n";
        cout << "1. Add element\n";
        cout << "2. Print elements\n";
        cout << "3. Sort vector\n";
        cout << "4. Binary search\n";
        cout << "5. Clear vector\n";
        cout << "6. Check if empty\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: addElement(v); break;
            case 2: printVector(v); break;
            case 3: sortVector(v); break;
            case 4: binarySearchElement(v); break;
            case 5: clearVector(v); break;
            case 6: isEmpty(v); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

// Add element
void addElement(vector<int>& v) {
    int x;
    cout << "Enter value: ";
    cin >> x;
    v.push_back(x);
    cout << "Added " << x << "\n";
}

// Print vector
void printVector(const vector<int>& v) {
    if (v.empty()) {
        cout << "Vector is empty!\n";
        return;
    }

    cout << "Elements: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

// Sort vector
void sortVector(vector<int>& v) {
    if (v.empty()) {
        cout << "Vector is empty!\n";
        return;
    }

    sort(v.begin(), v.end());
    cout << "Vector sorted\n";
}

// Binary search
void binarySearchElement(vector<int>& v) {
    if (v.empty()) {
        cout << "Vector is empty!\n";
        return;
    }

    int x;
    cout << "Enter value to search: ";
    cin >> x;

    // MUST be sorted first
    if (!is_sorted(v.begin(), v.end())) {
        cout << "Vector is not sorted! Sorting automatically...\n";
        sort(v.begin(), v.end());
    }

    bool found = binary_search(v.begin(), v.end(), x);

    if (found)
        cout << "Element found\n";
    else
        cout << "Element NOT found\n";
}

// Clear vector
void clearVector(vector<int>& v) {
    v.clear();
    cout << "Vector cleared\n";
}

// Check empty
void isEmpty(const vector<int>& v) {
    if (v.empty())
        cout << "Vector is empty\n";
    else
        cout << "Vector is NOT empty\n";
}