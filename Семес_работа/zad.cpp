// Задача 3. Да се сьстави програма, която генерира символен низ с дьлжина N (N<=100), образуван от буквите 'А', 'В' и 'С" и несьдьржащ два идентични съседни подниза.
//(Например, за N=6 такьв низ е 'АВАСАВ'. Низовете "ААВАСА', 'АВСВСА' и
//'ABCABC' са грешни). Програмата да се реализира с рекурсия (задьлжително на

#include <iostream>
using namespace std;

int N;
char s[105];

bool isValid(int pos) {
    for (int len = 1; 2 * len <= pos + 1; len++) {
        // Сравнява два съседни подниза с дължина 'len'
        if (strncmp(&s[pos - 2*len + 1], &s[pos - len + 1], len) == 0)
            return false;
    }
    return true;
}

bool gen(int pos) {
    if (pos == N) {
        for (int i = 0; i < N; i++)
            cout << s[i];
        cout << endl;
        return true; 
    }

    for (char c : {'A', 'B', 'C'}) {
        s[pos] = c;

        if (isValid(pos)) {
            if (gen(pos + 1))
                return true;
        }
    }

    return false;
}

int main() {
    cout << "Въведи число: "; 
    cin >> N;
    gen(0);
}