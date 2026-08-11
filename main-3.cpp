#include <iostream>
#include <string>


struct Songs{
    std::string title;
    Songs* next;
    Songs* prev;

    Songs(const std::string& name) : title(name), next(nullptr),prev(nullptr) {}
};


class Playlist {
private:
    Songs* head;
    Songs* current;

public:
    Playlist() : head(nullptr),current(nullptr) {}
    ~Playlist() {
        if (!head) return;
        Songs* temp = head;
        do {
            Songs* nextNode=temp->next;
            delete temp;
            temp=nextNode;
        } while (temp !=head);
    }
    void insertSong(const std::string& title) {
        Songs* newNode = new Songs(title);

        if (!head) {
            head =newNode;
            head->next=head;
            head->prev=head;
            current =head;
            std::cout<<"Added: \"" << title << "\"\n";
            return;
        }

        Songs* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;

        std::cout << "Added: \"" << title << "\"\n";
    }

    void removeSong(const std::string& title) {
        if (!head) {
            std::cout<<"Playlist is empty!\n";
            return;
        }
        Songs* temp= head;
        bool found= false;

        do {
            if (temp->title == title) {
                found=true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found) {
            std::cout << "song \"" << title << "\" not found.\n";
            return;
        }

        if (temp->next == temp) {
            delete temp;
            head = nullptr;
            current = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp==head) head= temp->next;
            if (temp==current) current= temp->next;

            delete temp;
        }

        std::cout << "removed: \"" << title << "\"\n";
    }

    void playAll() {
        if (!head) {
            std::cout <<"playlist is empty!\n";
            return;
        }

        std::cout << "\n--Playlist--\n";
        Songs* temp = head;
        do {
            std::cout << "- " << temp->title;
            if (temp==current) std::cout << " [Currently Playing]";
            std::cout<< "\n";
            temp = temp->next;
        } while (temp != head);
        std::cout << "-------------\n";
    }


    void next() {
        if (!current) {
            std::cout <<"playlist is empty!\n";
            return;
        }
        current= current->next;
        std::cout<< "Now playing: " <<current->title << "\n";
    }

    void previous() {
        if (!current) {
            std::cout <<"Playlist is empty!\n";
            return;
        }
        current=current->prev;
        std::cout <<"Now playing: "<< current->title << "\n";
    }
    
};


int main() {
    Playlist myPlaylist;
    int choice= 0;
    std::string songTitle;


    do {
        std::cout << "\n== PLAYLIST ==\n";
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Play All Songs\n";
        std::cout << "4. Next Song\n";
        std::cout << "5. Previous Song\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout <<"Enter song title: ";
                std::getline(std::cin, songTitle);
                myPlaylist.insertSong(songTitle);
                break;
            case 2:
                std::cout << "Enter song title: ";
                std::getline(std::cin, songTitle);
                myPlaylist.removeSong(songTitle);
                break;
            case 3:
                myPlaylist.playAll();
                break;
            case 4:
                myPlaylist.next();
                break;
            case 5:
                myPlaylist.previous();
                break;
            case 6:
                std::cout<<"Exiting playlist application. bye!\n";
                break;
            default:
                std::cout<< "Invalid choice. Please choose from 1 to 6.\n";
        }
    } while (choice != 6);

    return 0;
}