#include <iostream>
#include <set>

using namespace std;

using Tickets = multiset<string>;

void buyTicket(Tickets &tickets, const string &movie);
void returnTicket(Tickets &tickets, const string &movie);
void showTickets(const Tickets &tickets);
void mostPopularMovie(const Tickets &tickets);

int main() {
    Tickets tickets;
    int choice;

    do {
        cout << "1. Купи билет" << endl;
        cout << "2. Върни билет" << endl;
        cout << "3. Покажи всички билети" << endl;
        cout << "4. Най-популярен филм" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {

        case 1: {
            string movie;

            cout << "Въведи име на филм: ";
            getline(cin, movie);

            buyTicket(tickets, movie);

            break;
        }

        case 2: {
            string movie;

            cout << "Въведи име на филм: ";
            getline(cin, movie);

            returnTicket(tickets, movie);

            break;
        }

        case 3: {
            showTickets(tickets);

            break;
        }

        case 4: {
            mostPopularMovie(tickets);

            break;
        }

        case 0: {
            cout << "Изход..." << endl;

            break;
        }

        default: {
            cout << "Невалиден избор!" << endl;
        }

        }

    } while (choice != 0);

    return 0;
}

void buyTicket(Tickets &tickets, const string &movie) {
    tickets.insert(movie);

    cout << "Билетът е купен успешно!" << endl;
}

void returnTicket(Tickets &tickets, const string &movie) {
    auto it = tickets.find(movie);
    if (it == tickets.end()) {
        cout << "Няма такъв билет!" << endl;
        return;
    }

    tickets.erase(it);

    cout << "Билетът е върнат!" << endl;
}

void showTickets(const Tickets &tickets) {
    if (tickets.empty()) {
        cout << "Няма продадени билети!" << endl;
        return;
    }

    cout << "\n Продадени билети:" << endl;

    for (const auto &movie : tickets) {

        cout << movie << endl;
    }
}

void mostPopularMovie(const Tickets &tickets) {
    if (tickets.empty()) {
        cout << "Няма билети!" << endl;
        return;
    }

    string bestMovie;
    int maxTickets = 0;

    for (const auto &movie : tickets) {
        int current = tickets.count(movie);
        if (current > maxTickets) {
            maxTickets = current;
            bestMovie = movie;
        }
    }

    cout << "Най-популярен филм: " << bestMovie << endl;
}