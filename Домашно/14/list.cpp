#include <iostream>
#include <list>

using namespace std;

using Playlist = list<string>;

void addSong(Playlist &songs, const string &song);
void removeSong(Playlist &songs, const string &song);
void sortPlaylist(Playlist &songs);
void removeDuplicates(Playlist &songs);
void showPlaylist(const Playlist &songs);

int main() {
    Playlist songs;
    int choice;

    do {
        cout << "1. Добави песен" << endl;
        cout << "2. Изтрий песен" << endl;
        cout << "3. Сортирай playlist" << endl;
        cout << "4. Премахни duplicate песни" << endl;
        cout << "5. Покажи playlist" << endl;
        cout << "0. Изход" << endl;

        cout << "Избор: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {

        case 1: {
            string song;

            cout << "Въведи песен: ";
            getline(cin, song);

            addSong(songs, song);

            break;
        }

        case 2: {
            string song;

            cout << "Въведи песен за изтриване: ";
            getline(cin, song);

            removeSong(songs, song);

            break;
        }

        case 3: {
            sortPlaylist(songs);

            break;
        }

        case 4: {
            removeDuplicates(songs);

            break;
        }

        case 5: {
            showPlaylist(songs);

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

void addSong(Playlist &songs, const string &song) {
    songs.push_back(song);

    cout << "Песента е добавена!" << endl;
}

void removeSong(Playlist &songs, const string &song) {
    songs.remove(song);

    cout << "Песента е премахната ако е съществувала." << endl;
}

void sortPlaylist(Playlist &songs) {
    songs.sort();
    cout << "Playlist е сортиран!" << endl;
}

void removeDuplicates(Playlist &songs) {
    songs.unique();
    cout << "Duplicate песните са премахнати!" << endl;
}

void showPlaylist(const Playlist &songs) {
    if (songs.empty()) {
        cout << "Playlist е празен!" << endl;
        return;
    }

    int index = 1;

    for (const auto &song : songs) {
        cout << index << ". " << song << endl;
        index++;
    }
}