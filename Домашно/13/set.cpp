#include <iostream>
#include <set>

using namespace std;

using ReservedSeats = set<int>;

const int MAX_SEATS = 20;

void reserveSeat(ReservedSeats &seats, int seatNumber);
void cancelReservation(ReservedSeats &seats, int seatNumber);
void checkSeat(const ReservedSeats &seats, int seatNumber);
void showReservedSeats(const ReservedSeats &seats);
void showFreeSeats(const ReservedSeats &seats);

int main() {
    ReservedSeats seats;

    int choice;

    do {
        cout << "1. Резервирай място" << endl;
        cout << "2. Отмени резервация" << endl;
        cout << "3. Провери място" << endl;
        cout << "4. Покажи заетите места" << endl;
        cout << "5. Покажи свободните места" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int seat;

            cout << "Въведи номер на място: ";
            cin >> seat;

            reserveSeat(seats, seat);

            break;
        }
        case 2: {
            int seat;

            cout << "Въведи номер на място: ";
            cin >> seat;

            cancelReservation(seats, seat);

            break;
        }
        case 3: {
            int seat;

            cout << "Въведи номер на място: ";
            cin >> seat;

            checkSeat(seats, seat);

            break;
        }
        case 4: {
            showReservedSeats(seats);

            break;
        }
        case 5: {
            showFreeSeats(seats);

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

void reserveSeat(ReservedSeats &seats, int seatNumber) {
    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        cout << "Невалиден номер на място!" << endl;
        return;
    }

    if (seats.count(seatNumber)) {
        cout << "Мястото вече е резервирано!" << endl;
        return;
    }

    seats.insert(seatNumber);

    cout << "Мястото е резервирано успешно!" << endl;
}

void cancelReservation(ReservedSeats &seats, int seatNumber) {
    if (!seats.count(seatNumber)) {
        cout << "Това място не е резервирано!" << endl;
        return;
    }

    seats.erase(seatNumber);

    cout << "Резервацията е отменена успешно!" << endl;
}

void checkSeat(const ReservedSeats &seats, int seatNumber) {
    if (seats.count(seatNumber)) {
        cout << "Мястото е ЗАЕТО." << endl;
    }
    else {
        cout << "Мястото е СВОБОДНО." << endl;
    }
}

void showReservedSeats(const ReservedSeats &seats) {
    if (seats.empty()) {
        cout << "Няма резервирани места!" << endl;
        return;
    }

    cout << endl;
    cout << "Резервирани места: " << seats.size() << " | ";
    for (const auto &seat : seats) {
        cout << seat << " ";
    }

    cout << endl;
}

void showFreeSeats(const ReservedSeats &seats) {
    bool found = false;

    cout << endl;
    cout << "Свободните места са: ";

    for (int i = 1; i <= MAX_SEATS; i++) {
        if (!seats.count(i)) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "Няма свободни места!";
    }
    cout << endl;
}