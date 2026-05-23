#include <iostream>
#include <deque>

using namespace std;

using Patients = deque<string>;

void addNormalPatient(Patients &patients, const string &name);
void addEmergencyPatient(Patients &patients, const string &name);
void treatPatient(Patients &patients);
void removeLastPatient(Patients &patients);
void showPatients(const Patients &patients);
void showFirstAndLast(const Patients &patients);

int main() {
    Patients patients;
    int choice;

    do {
        cout << "1. Добави нормален пациент" << endl;
        cout << "2. Добави спешен пациент" << endl;
        cout << "3. Приеми пациент" << endl;
        cout << "4. Премахни последния чакащ" << endl;
        cout << "5. Покажи всички чакащи" << endl;
        cout << "6. Покажи първи и последен пациент" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;

            cout << "Въведи име: ";
            cin >> name;

            addNormalPatient(patients, name);

            break;
        }
        case 2: {
            string name;

            cout << "Въведи име: ";
            cin >> name;

            addEmergencyPatient(patients, name);

            break;
        }
        case 3: {
            treatPatient(patients);

            break;
        }
        case 4: {
            removeLastPatient(patients);

            break;
        }
        case 5: {
            showPatients(patients);

            break;
        }
        case 6: {
            showFirstAndLast(patients);

            break;
        }
        case 0: {
            cout << "Изход от системата..." << endl;

            break;
        }

        default: {
            cout << "Невалиден избор!" << endl;
        }

        }

    } while (choice != 0);

    return 0;
}

void addNormalPatient(Patients &patients, const string &name) {
    patients.push_back(name);
    cout << "Нормален пациент е добавен успешно!" << endl;
}

void addEmergencyPatient(Patients &patients, const string &name) {
    patients.push_front(name);
    cout << "Спешен пациент е добавен успешно!" << endl;
}

void treatPatient(Patients &patients) {
    if (patients.empty()) {
        cout << "Няма чакащи пациенти!" << endl;
        return;
    }

    cout << "Приет пациент: " << patients.front() << endl;

    patients.pop_front();
}

void removeLastPatient(Patients &patients) {
    if (patients.empty()) {
        cout << "Няма пациенти!" << endl;
        return;
    }

    cout << "Последният пациент напусна: " << patients.back() << endl;
    patients.pop_back();
}

void showPatients(const Patients &patients) {
    if (patients.empty()) {
        cout << "Няма чакащи пациенти!" << endl;
        return;
    }

    cout << endl;
    cout << "Общо пациенти: " << patients.size() << endl;
    cout << "Чакащи пациенти: " << endl;

    for (const auto &patient : patients) {
        cout << patient << endl;
    }
}

void showFirstAndLast(const Patients &patients) {
    if (patients.empty()) {
        cout << "Няма пациенти!" << endl;
        return;
    }

    cout << "Първи пациент: " << patients.front() << endl;

    cout << "Последен пациент: " << patients.back() << endl;
}