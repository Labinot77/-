#include <iostream>
#include <queue>

using namespace std;

using TaskQueue = priority_queue<pair<int, string>>;

void addTask(TaskQueue &tasks, const string &name, int priority);
void doTask(TaskQueue &tasks);
void showNextTask(const TaskQueue &tasks);
void showAllTasks(TaskQueue tasks);

int main() {
    TaskQueue tasks;
    int choice;

    do {
        cout << endl;
        cout << "1. Добави задача" << endl;
        cout << "2. Изпълни задача" << endl;
        cout << "3. Покажи следваща задача" << endl;
        cout << "4. Покажи всички задачи" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;
            int priority;

            cout << "Име на задача: ";
            cin >> name;

            cout << "Приоритет (1-3): ";
            cin >> priority;

            addTask(tasks, name, priority);

            break;
        }
        case 2: {
            doTask(tasks);
            break;
        }
        case 3: {
            showNextTask(tasks);
            break;
        }
        case 4: {
            showAllTasks(tasks);
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

void addTask(TaskQueue &tasks, const string &name, int priority) {
    tasks.push({priority, name});

    cout << "Задачата е добавена!" << endl;
}

void doTask(TaskQueue &tasks) {
    if (tasks.empty()) {
        cout << "Няма задачи!" << endl;
        return;
    }

    cout << "Изпълнена задача: " << tasks.top().second << " (приоритет " << tasks.top().first << ")" << endl;

    tasks.pop();
}

void showNextTask(const TaskQueue &tasks) {
    if (tasks.empty()) {
        cout << "Няма задачи!" << endl;
        return;
    }

    cout << "Следваща задача: " << tasks.top().second << " (приоритет " << tasks.top().first << ")" << endl;
}

void showAllTasks(TaskQueue tasks) {
    if (tasks.empty()) {
        cout << "Няма задачи!" << endl;
        return;
    }

    cout << endl;
    cout << "Общ брой задачи: " << tasks.size() << endl;

    while (!tasks.empty()) {
        cout << tasks.top().second << " | приоритет: " << tasks.top().first << endl;
        tasks.pop();
    }
}