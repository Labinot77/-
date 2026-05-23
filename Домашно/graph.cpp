#include <iostream>
using namespace std;

// Съставете програма за работа с ориентиран граф, представен чрез списъци
//на съседство, която да предлага меню с основните операции със структурата граф. Да се
//напише функция, която визуализира и изтрива двойките свързани върхове (А -> B и B-
//>A ) за дадения граф и се добави към менюто.


const int n = 5;

struct link {
    char key;
    link *next;
} *gr[n];

int search_node(link *gr[n], char c) {
    int flag = 0;
    for (int i = 0; i < n; i++)
        if (gr[i])
            if (gr[i]->key == c) { 
                flag = 1; 
                break; 
            }
    return flag;
}

int search_arc(link *gr[n], char c1, char c2) {
    int flag = 0;
    if (search_node(gr, c1) && search_node(gr, c2)) {
        int i = 0; link *p;
        do {
            if ((gr[i] == NULL) || (gr[i] && gr[i]->key != c1))
                i++;
        } while (gr[i]->key != c1);
        p = gr[i];

        if (p) {
            while (p->key != c2 && p->next != NULL) p = p->next;

            if (p->key == c2) flag = 1;
        }
    }
    return flag;
}

void add_node(link *gr[n], char c) {
    if (search_node(gr, c))
        { cout << "\nVurhut veche susshtestva\n"; }
    else {
        int j = 0;
        while (gr[j] && (j < n)) j++;
        if (gr[j] == NULL) {
            gr[j] = new link;
            gr[j]->key = c;
            gr[j]->next = NULL;
        } else {
            cout << "\nGrafut e pulen!\n"; 
        }
    }
}

void add_arc(link *gr[n], char c1, char c2) {
    int i = 0;
    link *p;
    if (search_arc(gr, c1, c2))
        { cout << "\nDugata veche sushtestvuva!"; }
    else {
        if (!(search_node(gr, c1))) add_node(gr, c1);
        if (!(search_node(gr, c2))) add_node(gr, c2);
        while (gr[i]->key != c1) i++;
        p = new link;
        p->key = c2;
        p->next = gr[i]->next;
        gr[i]->next = p;
    }
}

void del_node(link *gr[n], char c) {
    if (search_node(gr, c)) {
        int i = 0;
        do {
            if ((gr[i] == NULL) || (gr[i] && gr[i]->key != c)) i++;
        } while (gr[i]->key != c);

        link *p = gr[i], *q;
        while (gr[i] != NULL) { 
            p = gr[i]; 
            gr[i] = p->next; 
            delete p; 
        }
        for (i = 0; i < n; i++)
            if (gr[i]) {
                p = gr[i];
                while ((p->key != c) && (p->next != NULL))
                    { q = p; 
                      p = p->next; 
                    }
                if (p->key == c) { 
                    q->next = p->next; 
                    delete p; 
                }
            }
    } else { cout << "Nqma takava duga v grafa"; }
}

void del_arc(link *gr[n], char c1, char c2) {
    if (search_arc(gr, c1, c2)) {
        int i = 0;
        while (gr[i]->key != c1) i++;
        link *p = gr[i], *q;
        while (p->key != c2)
            { q = p; p = p->next; }
        q->next = p->next;
        delete p;
    }
    else { cout << "\nNqma takava duga v grafa"; }
}


void removeMutualEdges() {
    cout << "\nDvoyki nasreshtni dugi:\n";
    for (int i = 0; i < n; i++) {
        if (!gr[i]) continue;
        char a = gr[i]->key;
        link *temp = gr[i]->next;
        while (temp) {
            char b = temp->key;
            temp = temp->next;
            if (search_arc(gr, b, a)) {
                cout << a << " <-> " << b << "\n";
                del_arc(gr, a, b);
                del_arc(gr, b, a);
            }
        }
    }
}

void printGraph() {
    cout << "\nGraf:\n";
    for (int i = 0; i < n; i++) {
        if (!gr[i]) continue;

        cout << gr[i]->key << " -> ";
        
        link *temp = gr[i]->next;
        while (temp) { 
            cout << temp->key << " "; 
            temp = temp->next; 
        }
        cout << "\n";
    }
}

void init(link *gr[n]) {
    for (int i = 0; i < n; i++) gr[i] = NULL;
}

int main() {
    init(gr);
    int choice;
    char a, b;

    do {
        cout << "\n 1. Dobavqne na vruh\n";
        cout << "2. Dobavqne na duga\n";
        cout << "3. Iztrivane na vruh\n";
        cout << "4. Iztrivane na duga\n";
        cout << "5. Print graf\n";
        cout << "6. Iztrivane na dve vruzki\n";
        cout << "Izbor: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Vuvedi vruh: ";
            cin >> a;
            add_node(gr, a);
            break;

        case 2:
            cout << "Nachalen vruh: ";
            cin >> a;
            cout << "Kraen vruh: ";
            cin >> b;
            add_arc(gr, a, b);
            break;

        case 3:
            cout << "Vuvedi vruh: ";
            cin >> a;
            del_node(gr, a);
            break;

        case 4:
            cout << "Nachalen vruh: ";
            cin >> a;
            cout << "Kraen vruh: ";
            cin >> b;
            del_arc(gr, a, b);
            break;

        case 5:
            printGraph();
            break;

        case 6:
            removeMutualEdges();
            break;

        default:
            cout << "Nevaliden izbor\n";
        }

    } while (choice != 0);

    return 0;
}
