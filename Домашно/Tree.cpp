#include <iostream>
using namespace std;

// Задача 13 - Да се състави програма на С/С++, която използва функция за извеждане на
// възлите с по два наследника в дадено двоично дърво;

//        10
//       /  \
//      5    20
//     / \   / \
//    3   7 15  25

struct Node {
    int data;
    Node* left;
    Node* right;
} *root = NULL;

Node* createNode(int value);
Node* input(int value);
Node* buildHardcoded();
void printTwoChildren(Node* node);

int main() {
    int choice;
    cout << "1. Въведи дърво ръчно\n";
    cout << "2. Използвай hardcoded дърво\n";
    cout << "Избор: ";
    cin >> choice;

    if (choice == 1) {
        int val;
        cout << "Стойност на корена: ";
        cin >> val;
        root = input(val);
    } else {
        root = buildHardcoded();
    }

    cout << "\nВъзли с два наследника: ";
    printTwoChildren(root);
    cout << endl;

    return 0;
}

Node* input(int value) {
    Node* node = createNode(value);

    int choice;
    cout << "Възел " << value << " - има ли ляво дете? (1-да / 0-не): ";
    cin >> choice;
    if (choice) {
        int c;
        cout << "Стойност на лявото дете: ";
        cin >> c;
        node->left = input(c);
    }

    cout << "Възел " << value << " - има ли дясно дете? (1-да / 0-не): ";
    cin >> choice;
    if (choice) {
        int c;
        cout << "Стойност на дясното дете: ";
        cin >> c;
        node->right = input(c);
    }

    return node;
}

Node* createNode(int value) {
    Node* n = new Node();
    n->data  = value;
    n->left  = NULL;
    n->right = NULL;

    return n;
}

Node* buildHardcoded() {
    root = createNode(10);
    root->left  = createNode(5);
    root->right = createNode(20);
    root->left->left   = createNode(3);
    root->left->right  = createNode(7);
    root->right->left  = createNode(15);
    root->right->right = createNode(25);

    return root;
}

void printTwoChildren(Node* node) {
    if (node == NULL) return;

    if (node->left != NULL && node->right != NULL) {
        cout << node->data << " ";
    }

    printTwoChildren(node->left);
    printTwoChildren(node->right);
}
