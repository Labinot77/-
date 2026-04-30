// Задача 3. Да се сьстави програма, която генерира символен низ с дьлжина N (N<=100), образуван от буквите 'А', 'В' и 'С" и несьдьржащ два идентични съседни подниза.
//(Например, за N=6 такьв низ е 'АВАСАВ'. Низовете "ААВАСА', 'АВСВСА' и
//'ABCABC' са грешни). Програмата да се реализира с рекурсия (задьлжително на

#include <iostream>
using namespace std;

int N;
char s[105];

bool isValid(int pos) {
    for (int len = 1; len * 2 <= pos + 1; len++) {
        bool ok = true;

        for (int i = 0; i < len; i++) {
            if (s[pos - i] != s[pos - i - len]) {
                ok = false;
                break;
            }
        }

        if (ok) return false; // found repeated adjacent substring
    }

    return true;
}

bool gen(int pos) {
    if (pos == N) {
        for (int i = 0; i < N; i++)
            cout << s[i];
        cout << endl;
        return true; // stop after first solution
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
    cin >> N;
    gen(0);
}