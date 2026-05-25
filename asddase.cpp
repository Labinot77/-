/*
 * ============================================================
 *  ДОМАШНА РАБОТА – Сортиране и двоично търсене
 * ============================================================
 *  Условие:
 *  Да се създаде текстов файл съдържащ 100 естествени числа,
 *  въведени на случаен принцип чрез рандом функция.
 *  Да се прочита файлът и данните да се запишат в 4 едномерни
 *  масива. Три от масивите да се сортират по 3 различни начина:
 *    1. Метод на сливане (Merge Sort)
 *    2. Бързо сортиране / метод на Хоар (Quick Sort)
 *    3. Сортиране чрез купчина (Heap Sort)
 *  За данните от четвъртия масив да се приложи алгоритъм за
 *  двоично търсене (Binary Search).
 *  Задачата е реализирана с меню.
 *
 *  Сложности:
 *    Merge Sort  – O(n log n) в най-лош/среден/най-добър случай
 *    Quick Sort  – O(n log n) средно, O(n²) в най-лош случай
 *    Heap Sort   – O(n log n) във всички случаи
 *    Binary Search – O(log n)
 * ============================================================
 *  Автор: студент
 *  Файл : sorting_homework.cpp
 * ============================================================
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>   // std::sort (само за проверка при двоично търсене)

using namespace std;

// ─── константи ───────────────────────────────────────────────
const int  N        = 100;
const char FILENAME[] = "numbers.txt";

// ─── прототипи ───────────────────────────────────────────────
void generateFile();
bool readFile(int arr[], int size);
void printArray(const int arr[], int size);

// Merge Sort
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

// Quick Sort (Hoare partition)
int  hoarePartition(int arr[], int l, int r);
void quickSort(int arr[], int l, int r);

// Heap Sort
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

// Binary Search
int  binarySearch(int arr[], int n, int key);

// помощни
void copyArray(const int src[], int dst[], int n);

// ═════════════════════════════════════════════════════════════
//  MAIN
// ═════════════════════════════════════════════════════════════
int main() {
    int original[N];   // оригинален – не се сортира, ползва се за двоично търсене
    int arr1[N];       // Merge Sort
    int arr2[N];       // Quick Sort
    int arr3[N];       // Heap Sort

    bool fileLoaded = false;

    int choice;
    do {
        cout << "\n╔══════════════════════════════════════╗\n";
        cout <<   "║        МЕНЮ – СОРТИРАНЕ              ║\n";
        cout <<   "╠══════════════════════════════════════╣\n";
        cout <<   "║ 1. Генерирай файл с 100 числа        ║\n";
        cout <<   "║ 2. Прочети файла в масивите          ║\n";
        cout <<   "║ 3. Покажи оригиналния масив          ║\n";
        cout <<   "║ 4. Merge Sort   (сортиране на слив.) ║\n";
        cout <<   "║ 5. Quick Sort   (бързо сортиране)   ║\n";
        cout <<   "║ 6. Heap Sort    (сорт. чрез купчина)║\n";
        cout <<   "║ 7. Двоично търсене (Binary Search)  ║\n";
        cout <<   "║ 0. Изход                             ║\n";
        cout <<   "╚══════════════════════════════════════╝\n";
        cout << "Избор: ";
        cin  >> choice;

        switch (choice) {

        // ── 1. Генерирай файл ──────────────────────────────
        case 1:
            generateFile();
            fileLoaded = false;   // при ново генериране масивите са остарели
            break;

        // ── 2. Прочети файла ───────────────────────────────
        case 2:
            if (readFile(original, N)) {
                copyArray(original, arr1, N);
                copyArray(original, arr2, N);
                copyArray(original, arr3, N);
                fileLoaded = true;
                cout << "Файлът е прочетен успешно.\n";
            } else {
                cout << "Грешка! Първо генерирай файла (опция 1).\n";
            }
            break;

        // ── 3. Покажи оригинала ────────────────────────────
        case 3:
            if (!fileLoaded) { cout << "Първо прочети файла (опция 2).\n"; break; }
            cout << "\nОригинален масив:\n";
            printArray(original, N);
            break;

        // ── 4. Merge Sort ──────────────────────────────────
        case 4:
            if (!fileLoaded) { cout << "Първо прочети файла (опция 2).\n"; break; }
            copyArray(original, arr1, N);   // нулиране
            mergeSort(arr1, 0, N - 1);
            cout << "\nMerge Sort – резултат:\n";
            printArray(arr1, N);
            cout << "\nАлгоритъм: разделяй и владей.\n"
                 << "Масивът се дели наполовина рекурсивно докато\n"
                 << "останат единични елементи, след което се СЛИВАТ\n"
                 << "по наредено.  Сложност: O(n log n) навсякъде.\n";
            break;

        // ── 5. Quick Sort ──────────────────────────────────
        case 5:
            if (!fileLoaded) { cout << "Първо прочети файла (опция 2).\n"; break; }
            copyArray(original, arr2, N);
            quickSort(arr2, 0, N - 1);
            cout << "\nQuick Sort – резултат:\n";
            printArray(arr2, N);
            cout << "\nАлгоритъм: избира се pivot (Hoare partition).\n"
                 << "Елементите се разделят: по-малки вляво, по-големи\n"
                 << "вдясно. Рекурсия върху двете части.\n"
                 << "Сложност: O(n log n) средно, O(n²) в най-лош случай.\n";
            break;

        // ── 6. Heap Sort ───────────────────────────────────
        case 6:
            if (!fileLoaded) { cout << "Първо прочети файла (опция 2).\n"; break; }
            copyArray(original, arr3, N);
            heapSort(arr3, N);
            cout << "\nHeap Sort – резултат:\n";
            printArray(arr3, N);
            cout << "\nАлгоритъм: изгражда се max-heap, след което\n"
                 << "коренът (максималният елемент) се разменя с\n"
                 << "последния и купчината се възстановява.\n"
                 << "Сложност: O(n log n) навсякъде.\n";
            break;

        // ── 7. Двоично търсене ─────────────────────────────
        case 7: {
            if (!fileLoaded) { cout << "Първо прочети файла (опция 2).\n"; break; }

            // Двоичното търсене изисква СОРТИРАН масив.
            // Ползваме arr1 (Merge Sort). Ако не е сортиран – сортираме.
            copyArray(original, arr1, N);
            mergeSort(arr1, 0, N - 1);

            int key;
            cout << "Въведи число за търсене: ";
            cin  >> key;

            int pos = binarySearch(arr1, N, key);
            if (pos != -1)
                cout << "Числото " << key << " е намерено на позиция [" << pos
                     << "] в сортирания масив.\n";
            else
                cout << "Числото " << key << " НЕ е намерено в масива.\n";

            cout << "\nАлгоритъм: сравнява се търсеният елемент с\n"
                 << "средния. Ако е по-малък – търси се в лявата\n"
                 << "половина, иначе – в дясната. Повтаря се.\n"
                 << "Сложност: O(log n).\n";
            break;
        }

        case 0:
            cout << "Довиждане!\n";
            break;

        default:
            cout << "Невалиден избор.\n";
        }

    } while (choice != 0);

    return 0;
}

// ═════════════════════════════════════════════════════════════
//  ПОМОЩНИ ФУНКЦИИ
// ═════════════════════════════════════════════════════════════

void generateFile() {
    srand((unsigned)time(nullptr));
    ofstream fout(FILENAME);
    if (!fout) { cout << "Грешка при създаване на файл!\n"; return; }
    for (int i = 0; i < N; i++) {
        fout << (rand() % 900 + 100);   // числа 100..999
        if (i < N - 1) fout << "\n";
    }
    fout.close();
    cout << "Файлът \"" << FILENAME << "\" е създаден с " << N << " числа.\n";
}

bool readFile(int arr[], int size) {
    ifstream fin(FILENAME);
    if (!fin) return false;
    for (int i = 0; i < size; i++) {
        if (!(fin >> arr[i])) return false;
    }
    fin.close();
    return true;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if ((i + 1) % 10 == 0) cout << "\n";
        else                    cout << "  ";
    }
    cout << "\n";
}

void copyArray(const int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

// ═════════════════════════════════════════════════════════════
//  MERGE SORT
//  Алгоритъм:
//    1. Раздели масива наполовина (l..m  и  m+1..r).
//    2. Рекурсивно сортирай двете половини.
//    3. Слей ги в наредена последователност.
//  Сложност: T(n) = 2T(n/2) + O(n)  →  O(n log n)
// ═════════════════════════════════════════════════════════════

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // временни масиви
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// ═════════════════════════════════════════════════════════════
//  QUICK SORT  (Hoare partition scheme)
//  Алгоритъм:
//    1. Избери pivot (първият елемент в Hoare схемата).
//    2. Раздели масива: ≤ pivot вляво, ≥ pivot вдясно.
//    3. Рекурсивно сортирай двете части.
//  Сложност: O(n log n) средно, O(n²) в най-лош случай
// ═════════════════════════════════════════════════════════════

int hoarePartition(int arr[], int l, int r) {
    int pivot = arr[l];
    int i = l - 1;
    int j = r + 1;
    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int l, int r) {
    if (l >= r) return;
    int p = hoarePartition(arr, l, r);
    quickSort(arr, l, p);
    quickSort(arr, p + 1, r);
}

// ═════════════════════════════════════════════════════════════
//  HEAP SORT
//  Алгоритъм:
//    1. Изгради max-heap от масива.
//    2. Последователно: разменяй корена (max) с последния
//       елемент, намали купчината с 1 и възстанови heap.
//  Сложност: O(n log n) навсякъде
// ═════════════════════════════════════════════════════════════

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Изграждане на max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // Извличане
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ═════════════════════════════════════════════════════════════
//  BINARY SEARCH
//  Предварително условие: масивът е СОРТИРАН.
//  Алгоритъм:
//    1. l = 0, r = n-1
//    2. mid = (l+r)/2
//    3. Ако arr[mid] == key → намерен (return mid)
//       Ако arr[mid] < key  → l = mid + 1
//       Ако arr[mid] > key  → r = mid - 1
//    4. Повтаряй докато l <= r, иначе return -1
//  Сложност: O(log n)
// ═════════════════════════════════════════════════════════════

int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if      (arr[mid] == key) return mid;
        else if (arr[mid] <  key) l = mid + 1;
        else                      r = mid - 1;
    }
    return -1;
}