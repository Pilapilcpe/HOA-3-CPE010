#include <iostream>  // Provides input/output such as std::cout and std::cin
#include <string>    // Provides the std::string data type


// Struct declaration
// Songs represents one node in the playlist.
struct Songs {
    std::string title;  // Stores the song title
    Songs* next;        // Points to the next song
    Songs* prev;        // Points to the previous song

    // Constructor
    // Initializes the song title and sets both pointers to nullptr.
    Songs(const std::string& name)
        : title(name), next(nullptr), prev(nullptr) {}
};


// Class declaration
// Playlist manages the songs and controls playback.
class Playlist {

private:
    Songs* head;     // Points to the first song
    Songs* current;  // Points to the currently playing song

public:

    // Constructor
    // Starts the playlist with no songs.
    Playlist() : head(nullptr), current(nullptr) {}


    // Destructor
    // Automatically runs when the Playlist object is destroyed.
    ~Playlist() {

        // If the playlist is empty, there is nothing to delete.
        if (!head) return;

        // Starts deleting nodes from the head.
        Songs* temp = head;

        // do-while is used because this is a circular linked list.
        do {
            // Saves the next node before deleting the current node.
            Songs* nextNode = temp->next;

            // Deletes the current song from memory.
            delete temp;

            // Moves to the next song.
            temp = nextNode;

        // Stops when we return to the original head.
        } while (temp != head);
    }


    // Member function
    // Adds a new song to the playlist.
    void insertSong(const std::string& title) {

        // Creates a new song node dynamically.
        Songs* newNode = new Songs(title);

        // Checks if the playlist is empty.
        if (!head) {

            // The new node becomes the head.
            head = newNode;

            // Since this is the only node,
            // next points back to itself.
            head->next = head;

            // Previous also points back to itself.
            head->prev = head;

            // The new song becomes the current song.
            current = head;

            // Displays a confirmation message.
            std::cout << "Added: \"" << title << "\"\n";

            // Stops the function.
            return;
        }

        // Gets the last song.
        // In a circular doubly linked list,
        // the node before head is the tail.
        Songs* tail = head->prev;

        // The old tail now points to the new song.
        tail->next = newNode;

        // The new song points back to the old tail.
        newNode->prev = tail;

        // The new song points forward to head.
        newNode->next = head;

        // Head points back to the new song.
        head->prev = newNode;

        // Displays a confirmation message.
        std::cout << "Added: \"" << title << "\"\n";
    }


    // Member function
    // Searches for and removes a song.
    void removeSong(const std::string& title) {

        // Checks if the playlist is empty.
        if (!head) {
            std::cout << "Playlist is empty!\n";
            return;
        }

        // Starts searching from the head.
        Songs* temp = head;

        // Keeps track of whether the song was found.
        bool found = false;

        // Searches through the circular linked list.
        do {

            // Checks if the current song matches the title.
            if (temp->title == title) {
                found = true;
                break;
            }

            // Moves to the next song.
            temp = temp->next;

        // Stops after reaching the head again.
        } while (temp != head);


        // If the song was not found, display a message.
        if (!found) {
            std::cout << "song \"" << title << "\" not found.\n";
            return;
        }


        // Checks if there is only one song in the playlist.
        if (temp->next == temp) {

            // Deletes the only song.
            delete temp;

            // Playlist is now empty.
            head = nullptr;
            current = nullptr;

        } else {

            // Connects the previous song to the next song.
            temp->prev->next = temp->next;

            // Connects the next song back to the previous song.
            temp->next->prev = temp->prev;

            // If the removed song was the head,
            // move head to the next song.
            if (temp == head)
                head = temp->next;

            // If the removed song was currently playing,
            // move current to the next song.
            if (temp == current)
                current = temp->next;

            // Deletes the removed song.
            delete temp;
        }

        // Displays a confirmation message.
        std::cout << "removed: \"" << title << "\"\n";
    }


    // Member function
    // Displays all songs in the playlist.
    void playAll() {

        // Checks if the playlist is empty.
        if (!head) {
            std::cout << "playlist is empty!\n";
            return;
        }

        // Displays the playlist heading.
        std::cout << "\n--Playlist--\n";

        // Starts from the head.
        Songs* temp = head;

        // Traverses the circular linked list.
        do {

            // Displays the current song title.
            std::cout << "- " << temp->title;

            // Checks if this song is currently playing.
            if (temp == current)
                std::cout << " [Currently Playing]";

            std::cout << "\n";

            // Moves to the next song.
            temp = temp->next;

        // Stops when we return to the head.
        } while (temp != head);

        // Displays the bottom border.
        std::cout << "-------------\n";
    }


    // Member function
    // Moves to the next song.
    void next() {

        // Checks if there is no current song.
        if (!current) {
            std::cout << "playlist is empty!\n";
            return;
        }

        // Moves current to the next song.
        current = current->next;

        // Displays the new currently playing song.
        std::cout << "Now playing: " << current->title << "\n";
    }


    // Member function
    // Moves to the previous song.
    void previous() {

        // Checks if there is no current song.
        if (!current) {
            std::cout << "Playlist is empty!\n";
            return;
        }

        // Moves current to the previous song.
        current = current->prev;

        // Displays the new currently playing song.
        std::cout << "Now playing: " << current->title << "\n";
    }
};


// Main function
// Program execution starts here.
int main() {

    // Creates a Playlist object named myPlaylist.
    Playlist myPlaylist;

    // Stores the user's menu choice.
    int choice = 0;

    // Stores the song title entered by the user.
    std::string songTitle;


    // do-while loop keeps displaying the menu
    // until the user chooses option 6.
    do {

        // Displays the playlist menu.
        std::cout << "\n== PLAYLIST ==\n";
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Play All Songs\n";
        std::cout << "4. Next Song\n";
        std::cout << "5. Previous Song\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";

        // Gets the user's menu choice.
        std::cin >> choice;

        // Removes the leftover newline from the input buffer.
        std::cin.ignore();


        // Checks the user's choice.
        switch (choice) {

            // Add Song
            case 1:

                // Asks the user for the song title.
                std::cout << "Enter song title: ";

                // Reads an entire line, including spaces.
                std::getline(std::cin, songTitle);

                // Calls insertSong() to add the song.
                myPlaylist.insertSong(songTitle);

                // Stops this case.
                break;


            // Remove Song
            case 2:

                // Asks the user for the song title.
                std::cout << "Enter song title: ";

                // Reads the entire song title.
                std::getline(std::cin, songTitle);

                // Calls removeSong() to delete the song.
                myPlaylist.removeSong(songTitle);

                // Stops this case.
                break;


            // Play All Songs
            case 3:

                // Calls playAll() to display every song.
                myPlaylist.playAll();

                break;


            // Next Song
            case 4:

                // Calls next() to move forward.
                myPlaylist.next();

                break;


            // Previous Song
            case 5:

                // Calls previous() to move backward.
                myPlaylist.previous();

                break;


            // Exit
            case 6:

                // Displays the exit message.
                std::cout << "Exiting playlist application. bye!\n";

                break;


            // Runs when the user enters something other than 1-6.
            default:

                // Displays an error message.
                std::cout << "Invalid choice. Please choose from 1 to 6.\n";
        }

    // Repeats the menu while the choice is not 6.
    } while (choice != 6);


    // Ends the program successfully.
    return 0;
}
