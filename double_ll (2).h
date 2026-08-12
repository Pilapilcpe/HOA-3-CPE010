#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

// Header guard
// Prevents this header file from being included more than once.

template <typename T>
class doublelist {
public:
    T data;  // Stores the data inside the node

    // Pointer to the next node
    doublelist<T>* next = nullptr;

    // Pointer to the previous node
    doublelist<T>* prev = nullptr;
};


// Creating a node
template <typename T>
doublelist<T>* new_Node(T newData) {

    // Dynamically creates a new node in memory
    doublelist<T>* newNode = new doublelist<T>;

    // Stores the given data in the new node
    newNode->data = newData;

    // The new node has no next or previous node yet
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Returns the address of the new node
    return newNode;
}


// Traversal
template <typename T>
void dllTraverse(doublelist<T>* currentNode) {

    // Stores the last node visited during forward traversal
    doublelist<T>* tail = nullptr;

    // Traverses from the head toward the end of the list
    while (currentNode != nullptr) {

        // Prints the data stored in the current node
        std::cout << currentNode->data << " ";

        // Saves the current node as the last visited node
        tail = currentNode;

        // Moves to the next node
        currentNode = currentNode->next;
    }

    // Reverse traversal
    std::cout << "\nReverse Traversal: " << std::endl;

    // Traverses backward from the last node
    while (tail != nullptr) {

        // Prints the data stored in the current node
        std::cout << tail->data << " ";

        // Moves to the previous node
        tail = tail->prev;
    }
}


// Insertion at the head
template <typename T>
void dllInsertHead(T newData, doublelist<T>** currentHead) {

    // Creates a new node
    doublelist<T>* newNode = new_Node(newData);

    // Makes the new node point to the current head
    newNode->next = *currentHead;

    // Makes the current head point back to the new node
    (*currentHead)->prev = newNode;

    // Updates the head pointer
    // The new node becomes the first node
    *currentHead = newNode;
}


// General insertion
template <typename T>
void dllGenInsert(T newData, doublelist<T>* prevNode) {

    // Stops the function if prevNode does not exist
    if (prevNode == nullptr) {
        return;
    }

    // Creates a new node
    doublelist<T>* newNode = new_Node(newData);

    // Makes the new node point to the node after prevNode
    newNode->next = prevNode->next;

    // Makes the new node point back to prevNode
    newNode->prev = prevNode;

    // Checks if there is a node after prevNode
    if (prevNode->next != nullptr) {

        // Makes the next node point back to the new node
        prevNode->next->prev = newNode;
    }

    // Makes prevNode point forward to the new node
    prevNode->next = newNode;
}


// Insert at the end
template <typename T>
void dllInsertEnd(T newData, doublelist<T>* currenthead) {

    // Creates a new node
    doublelist<T>* newNode = new_Node(newData);

    // Moves through the list until the last node
    while (currenthead->next != nullptr) {
        currenthead = currenthead->next;
    }

    // Makes the last node point to the new node
    currenthead->next = newNode;

    // Makes the new node point back to the previous last node
    newNode->prev = currenthead;
}


// Deletion
template <typename T>
void dllDelete(T findData, doublelist<T>** currenthead) {

    // Checks if the list is empty
    if (*currenthead == nullptr) {
        return;
    }

    // Starts searching from the head
    doublelist<T>* currentnode = *currenthead;

    // Searches for the node containing findData
    while (currentnode != nullptr && currentnode->data != findData) {
        currentnode = currentnode->next;
    }

    // If the data was not found, stop the function
    if (currentnode == nullptr) {
        return;
    }

    // Checks if the node to delete is the head
    if (currentnode == *currenthead) {

        // Moves the head to the next node
        *currenthead = currentnode->next;

        // If a new head exists, remove its previous pointer
        if (*currenthead != nullptr) {
            (*currenthead)->prev = nullptr;
        }

    } else {

        // Makes the previous node point to the next node
        currentnode->prev->next = currentnode->next;

        // If a next node exists, make it point back
        // to the previous node
        if (currentnode->next != nullptr) {
            currentnode->next->prev = currentnode->prev;
        }
    }

    // Deletes the node from dynamic memory
    delete currentnode;
}

#endif
