#include <iostream>
#include <queue>

using namespace std;

using PatientQueue = queue<pair<string, string>>;

void addPatient(PatientQueue &patients, const string &name, const string &problem);
void servePatient(PatientQueue &patients);
void showNextPatient(PatientQueue patients);
void showAllPatients(PatientQueue patients);

int main() {
    PatientQueue patients;
    int choice;

    do {
        cout << "\n1. Добави пациент" << endl;
        cout << "2. Обслужи пациент" << endl;
        cout << "3. Покажи следващ пациент" << endl;
        cout << "4. Покажи всички пациенти" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;
            string problem;

            cout << "Въведи име на пациент: ";
            cin >> name;

            cin.ignore();

            cout << "Въведи проблем на пациента: ";
            getline(cin, problem);

            addPatient(patients, name, problem);

            break;
        }
        case 2: {
            servePatient(patients);
            break;
        }
        case 3: {
            showNextPatient(patients);
            break;
        }
        case 4: {
            showAllPatients(patients);
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

void addPatient(PatientQueue &patients, const string &name, const string &problem) {
    patients.push({name, problem});

    cout << name << " е добавен в опашката." << endl;
}

void servePatient(PatientQueue &patients) {
    if (patients.empty()) {
        cout << "Няма чакащи пациенти." << endl;
        return;
    }

    cout << "\nОбслужване на пациент:" << endl;
    cout << "Име: " << patients.front().first << endl;
    cout << "Проблем: " << patients.front().second << endl;

    patients.pop();
}

void showNextPatient(PatientQueue patients) {
    if (patients.empty()) {
        cout << "Няма чакащи пациенти." << endl;
        return;
    }

    cout << "\n Следващ пациент:" << endl;
    cout << "Име: " << patients.front().first << endl;
    cout << "Проблем: " << patients.front().second << endl;
}

void showAllPatients(PatientQueue patients) {
    if (patients.empty()) {
        cout << "Няма чакащи пациенти." << endl;
        return;
    }

    cout << "\n ЧАКАЩИ ПАЦИЕНТИ " << endl;
    cout << "Общо пациенти: " << patients.size() << endl;
    
    while (!patients.empty()) {
        cout << "Име: " << patients.front().first << " | Проблем: " << patients.front().second << endl;
        patients.pop();
    }

}
