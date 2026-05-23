#include <iostream>
#include <forward_list>

using namespace std;

using Feed = forward_list<string>;

void addPost(Feed &feed, const string &post);
void deletePost(Feed &feed, const string &post);
void searchPost(const Feed &feed, const string &post);
void showFeed(const Feed &feed);
void showLatestPost(const Feed &feed);

int main() {
    Feed feed;
    int choice;

    do {
        cout << "1. Добави пост" << endl;
        cout << "2. Изтрий пост" << endl;
        cout << "3. Търси пост" << endl;
        cout << "4. Покажи feed" << endl;
        cout << "5. Покажи последен пост" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {

        case 1: {
            string post;

            cout << "Въведи текст: ";
            getline(cin, post);

            addPost(feed, post);

            break;
        }

        case 2: {
            string post;

            cout << "Въведи пост за изтриване: ";
            getline(cin, post);

            deletePost(feed, post);

            break;
        }

        case 3: {
            string post;

            cout << "Въведи текст за търсене: ";
            getline(cin, post);

            searchPost(feed, post);

            break;
        }

        case 4: {
            showFeed(feed);

            break;
        }

        case 5: {
            showLatestPost(feed);

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

void addPost(Feed &feed, const string &post) {
    feed.push_front(post);

    cout << "Постът е добавен!" << endl;
}

void deletePost(Feed &feed, const string &post) {
    feed.remove(post);

    cout << "Постът е премахнат ако е съществувал." << endl;
}

void searchPost(const Feed &feed, const string &post) {
    for (const auto &current : feed) {
        if (current == post) {
            cout << "Постът е намерен!" << endl;
            return;
        }
    }

    cout << "Постът не е намерен." << endl;
}

void showFeed(const Feed &feed) {
    if (feed.empty()) {
        cout << "Feed е празен!" << endl;

        return;
    }

    for (const auto &post : feed) {
        cout << "- " << post << endl;
    }
}

void showLatestPost(const Feed &feed) {
    if (feed.empty()) {
        cout << "Няма постове!" << endl;
        return;
    }

    cout << "Последен пост: " << feed.front() << endl;
}