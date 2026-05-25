#include <iostream>
#include <vector>

using namespace std;

using stock = vector<pair<string, int>>;

void addProduct(stock &inventory, const string &name, int quantity);
void sellProduct(stock &inventory, const string &name, int quantity);
void printInventory(const stock &inventory);
void searchProduct(const stock &inventory, const string &name);

int main() {
    stock inventory;
    int choice;

    do {
        cout << "1. Добави продукт" << endl;
        cout << "2. Продай продукт" << endl;
        cout << "3. Потърси продукт" << endl;
        cout << "4. Покажи инвентар" << endl;
        cout << "0. Изход" << endl;

        cout << "Избери: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;
            int quantity;

            cout << "Въведи име на продукт: ";
            cin >> name;

            cout << "Въведи количество: ";
            cin >> quantity;

            addProduct(inventory, name, quantity);

            break;
        }

        case 2: {
            string name;
            int quantity;

            cout << "Въведи име на продукт: ";
            cin >> name;

            cout << "Въведи количество за продажба: ";
            cin >> quantity;

            sellProduct(inventory, name, quantity);

            break;
        }

        case 3: {
            string name;

            cout << "Въведи име на продукт: ";
            cin >> name;

            searchProduct(inventory, name);

            break;
        }

        case 4: {
            printInventory(inventory);

            break;
        }

        case 0: {
            cout << "Програмата приключи." << endl;

            break;
        }

        default: {
            cout << "Невалиден избор!" << endl;
        }
        }

    } while (choice != 0);

    return 0;
}

void addProduct(stock &inventory, const string &name, int quantity) {
    for (auto &product : inventory) {
        if (product.first == name) {
            product.second += quantity;

            cout << "Обновено количество за " << name << endl;
            return;
        }
    }

    inventory.push_back({name, quantity});

    cout << "Добавен нов продукт: " << name << endl;
}

void sellProduct(stock &inventory, const string &name, int quantity) {
    for (auto &product : inventory) {
        if (product.first == name) {
            if (product.second >= quantity) {
                product.second -= quantity;

                cout << "Продадени " << quantity << " от " << name << endl;
            }
            else {
                cout << "Недостатъчно количество!" << endl;
            }
            return;
        }
    }

    cout << "Продуктът не е намерен!" << endl;
}

void printInventory(const stock &inventory) {
    if (inventory.empty()) {
        cout << "Инвентарът е празен." << endl;
        return;
    }

    for (const auto &product : inventory) {
        cout << "Продукт: " << product.first << " | Количество: " << product.second << endl;
    }
}

void searchProduct(const stock &inventory, const string &name) {
    for (const auto &product : inventory) {
        if (product.first == name) {
            cout << "Намерен: " << product.first << " | Количество: " << product.second << endl;
            return;
        }
    }

    cout << "Продуктът не е намерен!" << endl;
}