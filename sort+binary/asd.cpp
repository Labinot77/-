/*
    Домашна работа
    Сортиране и двоично търсене

    Да се създаде файл с 100 случайни числа.
    Данните се записват в 4 масива.

    1. Merge Sort
    2. Quick Sort (Хоар)
    3. Selection Sort
    4. Binary Search

*/

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int n = 100;


void generateFile()
{
    ofstream file("numbers.txt");

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        file << rand() % 1000 << " ";
    }

    file.close();

    cout << "\nФайлът е създаден успешно!\n";
}


void readFile(int a[], int b[], int c[], int d[])
{
    ifstream file("numbers.txt");

    if (!file)
    {
        cout << "\nГрешка при отваряне!\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        file >> a[i];

        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    file.close();

    cout << "\nДанните са заредени!\n";
}

void printArray(int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

// 
void merge(int a[], int na, int b[], int nb, int c[]) {
    int ia = 0;
    int ib = 0;
    int ic = 0;

    while (ia < na && ib < nb) {
        c[ic++] = ((a[ia] < b[ib]) ? a[ia++] : b[ib++]);
    }

    while (ia < na) {
        c[ic++] = a[ia++];
    }

    while (ib < nb) {
        c[ic++] = b[ib++];
    }
}

//
void mergesort(int a[], int size) {
    if (size < 2)
        return;

    int nleft = size / 2;
    int nright = size - nleft;

    mergesort(a, nleft);
    mergesort(a + nleft, nright);

    int *p = new int[size];

    merge(a, nleft, a + nleft, nright, p);

    for (int i = 0; i < size; i++) {
        a[i] = p[i];
    }

    delete[] p;
}

//

int aQuick[n];

unsigned partition2(int L, int R) {
    int i, j, x, rab;

    i = L;
    j = R;
    x = aQuick[L];

    do {
        while (x > aQuick[i]) i++;

        while (x < aQuick[j]) j--;

        if (i <= j) {
            rab = aQuick[i];
            aQuick[i] = aQuick[j];
            aQuick[j] = rab;

            i++;
            j--;
        }

    } while (i <= j);

    return j;
}

void quicksort(int L, int R)
{
    int q;

    if (L < R)
    {
        q = partition2(L, R);

        quicksort(L, q);

        quicksort(q + 1, R);
    }
}

// ==================================================
// SELECTION SORT
// ==================================================

void straight_selection(int a[], unsigned size) {
    unsigned i, j;
    int rab;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (a[i] > a[j])
            {
                rab = a[i];
                a[i] = a[j];
                a[j] = rab;
            }
        }
    }
}

// ==================================================
// BINARY SEARCH
// ==================================================

int binarySearch(int a[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == key) {
            return mid;
        }

        if (a[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr1[n];
    int arr2[n];
    int arr3[n];
    int arr4[n];

    int choice;

    do
    {
        cout << "1. Генериране на файл\n";
        cout << "2. Прочитане на файл\n";
        cout << "3. Merge Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Selection Sort\n";
        cout << "6. Binary Search\n";
        cout << "0. Изход\n";

        cout << "\nИзбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            generateFile();
            break;

        case 2:
            readFile(arr1, arr2, arr3, arr4);
            break;

        case 3:

            mergesort(arr1, n);

            cout << "\nMerge Sort:\n";
            printArray(arr1);

            break;

        case 4:
            for (int i = 0; i < n; i++)
                aQuick[i] = arr2[i];

            quicksort(0, n - 1);

            cout << "\nQuick Sort:\n";

            for (int i = 0; i < n; i++)
                cout << aQuick[i] << " ";

            cout << endl;

            break;

        case 5:
            straight_selection(arr3, n);

            cout << "\nSelection Sort:\n";
            printArray(arr3);

            break;

        case 6:
        {
            mergesort(arr4, n);

            int key;

            cout << "\nВъведете число: ";
            cin >> key;

            int result = binarySearch(arr4, 0, n - 1, key);

            if (result != -1) {
                cout << "\nЧислото е намерено на позиция " << result << endl;
            }
            else {
                cout << "\nЧислото не е намерено!\n";
            }

            break;
        }

        case 0:
            cout << "\nКрай!\n";
            break;

        default:
            cout << "\nНевалиден избор!\n";
        }

    } while (choice != 0);

    return 0;
}