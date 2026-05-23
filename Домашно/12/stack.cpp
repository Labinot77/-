#include <iostream>
#include <stack>

using namespace std;

using GameStack = stack<pair<int, int>>;

void reachLevel(GameStack &game, int level, int health);
void die(GameStack &game);
void showCurrent(const GameStack &game);
void showHistory(GameStack game);
void resetGame(GameStack &game);

int main() {
    GameStack game;
    game.push({1, 100});

    int choice;

    do {
        cout << "\n1. Достигни ново ниво" << endl;
        cout << "2. Умри (връщане към последния чекпойнт)" << endl;
        cout << "3. Показване на текущото състояние" << endl;
        cout << "4. Показване на историята на чекпойнтите" << endl;
        cout << "5. Рестартиране на играта" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int level, health;

            cout << "Въведи ниво: ";
            cin >> level;

            cout << "Въведи HP: ";
            cin >> health;

            reachLevel(game, level, health);
            break;
        }
        case 2: {
            die(game);
            break;
        }
        case 3: {
            showCurrent(game);
            break;
        }
        case 4: {
            showHistory(game);
            break;
        }
        case 5: {
            resetGame(game);
            break;
        }
        case 0: {
            cout << "Изход от играта..." << endl;
            break;
        }
        default: {
            cout << "Невалиден избор!" << endl;
        }
    }
    } while (choice != 0);

    return 0;
}

void reachLevel(GameStack &game, int level, int health) {
    if (level == 1) {
        cout << "Вече си на първо ниво." << endl;
        return;
    }

    game.push({level, health});

    cout << "Достигна ниво " << level << " с HP: " << health << endl;
}

void die(GameStack &game) {
    if (game.size() <= 1) {
        cout << "Няма чекпойнт!" << endl;
        return;
    }

    cout << "Играчът умря..." << endl;

    game.pop();
    auto checkpoint = game.top();

    cout << "Възстановен на ниво " << checkpoint.first << " с HP " << checkpoint.second << endl;
}

void showCurrent(const GameStack &game) {
    if (game.empty()) {
        cout << "Няма данни за играта!" << endl;
        return;
    }

    auto checkpoint = game.top();

    cout << "Текущо ниво: " << checkpoint.first << endl;
    cout << "Текущо HP: " << checkpoint.second << endl;
}

void showHistory(GameStack game) {
    cout << "\n История:" << endl;

    while (!game.empty()) {
        cout << "Ниво: " << game.top().first << " | HP: " << game.top().second << endl;

        game.pop();
    }
}

void resetGame(GameStack &game) {
    while (!game.empty()) {
        game.pop();
    }

    game.push({1, 100});

    cout << "Играта е рестартирана до ниво 1!" << endl;
}