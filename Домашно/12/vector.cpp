#include <iostream>
#include <vector>

using namespace std;

using TaskList = vector<pair<string, bool>>;

void addTask(TaskList &tasks, const string &name);
void completeTask(TaskList &tasks, int index);
void removeTask(TaskList &tasks, int index);
void showTasks(const TaskList &tasks);
void clearCompleted(TaskList &tasks);
void clearAllTasks(TaskList &tasks);

int main() {
    TaskList tasks;
    int choice;

    do {
        cout << "1. Добави задача" << endl;
        cout << "2. Отбележи задача като завършена" << endl;
        cout << "3. Изтрий задача" << endl;
        cout << "4. Покажи всички задачи" << endl;
        cout << "5. Изчисти завършените задачи" << endl;
        cout << "6. Изчисти всички задачи" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;

            cout << "Въведи задача: ";
            cin.ignore();
            getline(cin, name);

            addTask(tasks, name);
            break;
        }

        case 2: {
            int index;

            cout << "Въведи индекс на задача: ";
            cin >> index;

            completeTask(tasks, index);
            break;
        }

        case 3: {
            int index;

            cout << "Въведи индекс на задача: ";
            cin >> index;

            removeTask(tasks, index);
            break;
        }

        case 4: {
            showTasks(tasks);
            break;
        }

        case 5: {
            clearCompleted(tasks);
            break;
        }

        case 6: {
            clearAllTasks(tasks);
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

void addTask(TaskList &tasks, const string &name) {
    tasks.push_back({name, false});

    cout << "Задачата е добавена: " << name << endl;
}

void completeTask(TaskList &tasks, int index) {
    if (index < 0 || index >= tasks.size()) {
        cout << "Невалиден индекс!" << endl;
        return;
    }

    tasks[index].second = true;

    cout << "Задачата е отбелязана като завършена: " << tasks[index].first << endl;
}

void removeTask(TaskList &tasks, int index) {
    if (index < 0 || index >= tasks.size()) {
        cout << "Невалиден индекс!" << endl;
        return;
    }

    cout << "Изтрита задача: " << tasks[index].first << endl;

    tasks.erase(tasks.begin() + index);
}

void showTasks(const TaskList &tasks) {
    if (tasks.empty()) {
        cout << "Няма задачи!\n";
        return;
    }

    cout << "\n Списък със задачи" << endl;

    for (int i = 0; i < tasks.size(); i++) {
        cout << i << ". " << tasks[i].first << " | " << (tasks[i].second ? "Завършена" : "Незавършена") << endl;
    }
}

void clearCompleted(TaskList &tasks) {
    for (int i = tasks.size() - 1; i >= 0; i--) {
        if (tasks[i].second == true) {
            tasks.erase(tasks.begin() + i);
        }
    }

    cout << "Завършените задачи са изчистени!\n";
}

void clearAllTasks(TaskList &tasks) {
    tasks.clear();
    cout << "Всички задачи са изтрити!\n";
}