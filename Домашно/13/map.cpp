#include <iostream>
#include <map>

using namespace std;

using Inventory = map<string, pair<int, double>>;

void addProduct(Inventory &shop, const string &name, int quantity, double price);
void restockProduct(Inventory &shop, const string &name, int quantity);
void sellProduct(Inventory &shop, const string &name, int quantity);
void changePrice(Inventory &shop, const string &name, double newPrice);
void searchProduct(const Inventory &shop, const string &name);
void showProducts(const Inventory &shop);
void totalStoreValue(const Inventory &shop);

int main() {
    Inventory shop;
    int choice;

    do {
        cout << endl;
        cout << "1. Добави продукт" << endl;
        cout << "2. Зареди количество" << endl;
        cout << "3. Продай продукт" << endl;
        cout << "4. Смени цена на продукт" << endl;
        cout << "5. Потърси продукт" << endl;
        cout << "6. Покажи всички продукти" << endl;
        cout << "7. Покажи общата стойност на магазина" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;
            int quantity;
            double price;

            cout << "Въведи име на продукт: ";
            cin >> name;

            cout << "Въведи количество: ";
            cin >> quantity;

            cout << "Въведи цена: ";
            cin >> price;

            addProduct(shop, name, quantity, price);

            break;
        }
        case 2: {
            string name;
            int quantity;

            cout << "Въведи име на продукт: ";
            cin >> name;

            cout << "Въведи количество: ";
            cin >> quantity;

            restockProduct(shop, name, quantity);

            break;
        }
        case 3: {
            string name;
            int quantity;

            cout << "Въведи име на продукт: ";
            cin >> name;

            cout << "Въведи количество за продажба: ";
            cin >> quantity;

            sellProduct(shop, name, quantity);

            break;
        }
        case 4: {
            string name;
            double price;

            cout << "Въведи име на продукт: ";
            cin >> name;

            cout << "Въведи нова цена: ";
            cin >> price;

            changePrice(shop, name, price);

            break;
        }
        case 5: {
            string name;

            cout << "Въведи име на продукт: ";
            cin >> name;

            searchProduct(shop, name);

            break;
        }
        case 6: {
            showProducts(shop);

            break;
        }
        case 7: {
            totalStoreValue(shop);

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

void addProduct(Inventory &shop, const string &name, int quantity, double price) {
    if (shop.count(name)) {
        cout << "Продуктът вече съществува!" << endl;
        return;
    }

    shop[name] = {quantity, price};
    cout << "Продуктът е добавен успешно!" << endl;
}

void restockProduct(Inventory &shop, const string &name, int quantity) {
    if (!shop.count(name)) {
        cout << "Продуктът не е намерен!" << endl;
        return;
    }

    shop[name].first += quantity;

    cout << "Количеството е обновено!" << endl;
}

void sellProduct(Inventory &shop, const string &name, int quantity) {
    if (!shop.count(name)) {
        cout << "Продуктът не е намерен!" << endl;
        return;
    }

    if (shop[name].first < quantity) {
        cout << "Няма достатъчно количество!" << endl;
        return;
    }

    shop[name].first -= quantity;

    double total = quantity * shop[name].second;

    cout << "Продадено за: " << total << " лв." << endl;
}

void changePrice(Inventory &shop, const string &name, double newPrice) {
    if (!shop.count(name)) {
        cout << "Продуктът не е намерен!" << endl;
        return;
    }

    shop[name].second = newPrice;
    cout << "Цената е обновена!" << endl;
}

void searchProduct(const Inventory &shop, const string &name) {
    if (!shop.count(name)) {
        cout << "Продуктът не е намерен!" << endl;
        return;
    }

    cout << "Име: " << name << " | Количество: " << shop.at(name).first << " | Цена: " << shop.at(name).second << endl;
}

void showProducts(const Inventory &shop) {
    if (shop.empty()) {
        cout << "Няма налични продукти!" << endl;
        return;
    }

    cout << endl;
    cout << "Продукти: " << endl;

    for (const auto &product : shop) {
        cout << "Име: " << product.first << " | Количество: " << product.second.first << " | Цена: " << product.second.second << endl;
    }
}

void totalStoreValue(const Inventory &shop) {
    double total = 0;
    for (const auto &product : shop) {
        total += product.second.first * product.second.second;
    }

    cout << "Обща стойност на магазина: " << total << " лв." << endl;
}
