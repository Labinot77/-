#include <iostream>
using namespace std;

const int MAX = 20;

struct Node {
    char v;
    Node* next;
};

Node* gr[MAX];
bool visited[MAX];
char vertices[MAX];
int vCount = 0;

// ========================
// РЕКУРСИВНО ДОБАВЯНЕ НА ВЪРХОВЕ
// ========================
void addVertexRec(int i, int n) {
    if (i == n) return;

    gr[i] = nullptr;
    cout << "Въведи връх: ";
    cin >> vertices[i];

    addVertexRec(i + 1, n);
}

// ========================
// ТЪРСЕНЕ НА ИНДЕКС НА ВЪРХА
// ========================
int getIndex(char v, int n, int i = 0) {
    if (i == n) return -1;
    if (vertices[i] == v) return i;
    return getIndex(v, n, i + 1);
}

// ========================
// РЕКУРСИВНО ДОБАВЯНЕ НА ДЪГА
// ========================
void addEdgeRec(char a, char b, int n) {
    int idx = getIndex(a, n);
    if (idx == -1) return;

    Node* newNode = new Node{b, gr[idx]};
    gr[idx] = newNode;
}

// ========================
// ВИЗУАЛИЗАЦИЯ НА ГРАФА
// ========================
void printGraphRec(int i, int n) {
    if (i == n) return;

    cout << vertices[i] << " -> ";
    Node* p = gr[i];

    while (p != nullptr) {
        cout << p->v << " ";
        p = p->next;
    }
    cout << endl;

    printGraphRec(i + 1, n);
}

// ========================
// ТЪРСЕНЕ И ИЗТРИВАНЕ НА ДЪГА
// ========================
void removeEdge(Node*& head, char target) {
    if (!head) return;

    if (head->v == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        removeEdge(head, target);
    } else {
        removeEdge(head->next, target);
    }
}

// ========================
// ИЗТРИВАНЕ НА ДВУСТРАННИ ВРЪЗКИ (A↔B)
// ========================
void deleteBidirectional(int i, int n) {
    if (i == n) return;

    Node* p = gr[i];

    while (p != nullptr) {
        char a = vertices[i];
        char b = p->v;

        int idxB = getIndex(b, n);

        if (idxB != -1) {
            Node* q = gr[idxB];

            bool hasBackEdge = false;
            while (q != nullptr) {
                if (q->v == a) {
                    hasBackEdge = true;
                    break;
                }
                q = q->next;
            }

            // ако има A->B и B->A
            if (hasBackEdge) {
                cout << "Премахвам двойка: " << a << " <-> " << b << endl;

                removeEdge(gr[i], b);
                removeEdge(gr[idxB], a);

                // рестартираме обхождането
                p = gr[i];
                continue;
            }
        }

        p = p->next;
    }

    deleteBidirectional(i + 1, n);
}

// ========================
// МЕНЮ
// ========================
void menu(int n) {
    int choice;

    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Печат на граф\n";
        cout << "2. Добавяне на дъга\n";
        cout << "3. Изтриване на двойни връзки (A<->B)\n";
        cout << "0. Изход\n";
        cout << "Избор: ";
        cin >> choice;

        if (choice == 1) {
            printGraphRec(0, n);
        }

        else if (choice == 2) {
            char a, b;
            cout << "От: "; cin >> a;
            cout << "До: "; cin >> b;
            addEdgeRec(a, b, n);
        }

        else if (choice == 3) {
            deleteBidirectional(0, n);
        }

    } while (choice != 0);
}

// ========================
// MAIN
// ========================
int main() {
    int n;

    cout << "Брой върхове: ";
    cin >> n;

    addVertexRec(0, n);

    menu(n);

    return 0;
}