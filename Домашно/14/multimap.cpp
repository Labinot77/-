#include <iostream>
#include <map>

using namespace std;

using GradeBook = multimap<string, int>;

void addGrade(GradeBook &grades, const string &student, int grade);
void showAllGrades(const GradeBook &grades);
void showStudentGrades(const GradeBook &grades, const string &student);
void removeStudent(const GradeBook &grades, GradeBook &newGrades, const string &student);

int main() {
    GradeBook grades;
    int choice;

    do {
        cout << "1. Добави оценка" << endl;
        cout << "2. Покажи всички оценки" << endl;
        cout << "3. Покажи оценки на ученик" << endl;
        cout << "4. Изтрий ученик" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string student;
            int grade;

            cout << "Име на ученик: ";
            cin >> student;

            cout << "Оценка: ";
            cin >> grade;

            addGrade(grades, student, grade);

            break;
        }

        case 2: {
            showAllGrades(grades);

            break;
        }

        case 3: {
            string student;

            cout << "Име на ученик: ";
            cin >> student;

            showStudentGrades(grades, student);

            break;
        }

        case 4: {
            string student;

            cout << "Име на ученик: ";
            cin >> student;

            GradeBook newGrades;

            removeStudent(grades, newGrades, student);

            grades = newGrades;

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

void addGrade(GradeBook &grades, const string &student, int grade) {
    grades.insert({student, grade});

    cout << "Оценката е добавена!" << endl;
}

void showAllGrades(const GradeBook &grades) {
    if (grades.empty()) {
        cout << "Няма оценки!" << endl;
        return;
    }

    for (const auto &entry : grades) {
        cout << entry.first << " -> " << entry.second << endl;
    }
}

void showStudentGrades(const GradeBook &grades, const string &student) {
    auto range = grades.equal_range(student);
    if (range.first == range.second) {
        cout << "Няма такъв ученик!" << endl;
        return;
    }

    cout << endl << "Оценки на " << student << ":" << endl;
    for (auto it = range.first; it != range.second; it++) {
        cout << it->second << endl;
    }
}

void removeStudent(const GradeBook &grades, GradeBook &newGrades, const string &student) {
    for (const auto &entry : grades) {
        if (entry.first != student) {
            newGrades.insert(entry);
        }
    }

    cout << "Ученикът е премахнат!" << endl;
}