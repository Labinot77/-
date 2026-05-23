#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Leaderboard = vector<pair<string, int>>;

void addPlayer(Leaderboard &players, const string &name, int score);
void sortLeaderboard(Leaderboard &players);
void showLeaderboard(const Leaderboard &players);

int main() {
    Leaderboard players;
    int choice;

    do {
        cout << "1. Добави играч\n";
        cout << "2. Сортирай leaderboard\n";
        cout << "3. Покажи leaderboard\n";
        cout << "0. Изход\n";

        cout << "Избор: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;
            int score;

            cout << "Име: ";
            cin >> name;

            cout << "Score: ";
            cin >> score;

            addPlayer(players, name, score);

            break;
        }

        case 2: {
            sortLeaderboard(players);
            break;
        }

        case 3: {
            showLeaderboard(players);
            break;
        }

        case 0: {
            cout << "Изход...\n";
            break;
        }

        default: {
            cout << "Невалиден избор!\n";
        }

        }

    } while (choice != 0);

    return 0;
}

void addPlayer(Leaderboard &players,
               const string &name,
               int score) {

    players.push_back({name, score});

    cout << "Играчът е добавен!\n";
}

void sortLeaderboard(Leaderboard &players) {
    sort(players.begin(),
         players.end(),
         [](const pair<string, int> &a,
            const pair<string, int> &b) {

        return a.second > b.second;
    });

    cout << "Leaderboard е сортиран!\n";
}

void showLeaderboard(const Leaderboard &players) {

    if (players.empty()) {

        cout << "Няма играчи!\n";

        return;
    }

    cout << "\n===== LEADERBOARD =====\n";

    int rank = 1;

    for (const auto &player : players) {

        cout << rank
             << ". "
             << player.first
             << " | Score: "
             << player.second
             << endl;

        rank++;
    }
}