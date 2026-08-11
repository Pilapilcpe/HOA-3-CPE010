#ifndef SINGLY_LL_H // header filename
#define SINGLY_LL_H //  file name

template <typename T> // This makes the class accept any data type
class SingleList{
    public:
    T data; //data of the node
    SingleList<T> *next = nullptr; //stores the address of the nextr node

};

template <typename T>
void ListTraversal(SingleList<T>* head){//Will check the data type stored in that address 
    while( head != nullptr){
        std::cout << head->data;
    
        // to check if the next head is null
        if (head->next != nullptr){
            std::cout << "->";
        }
        head = head->next;
   }
   std::cout << std::endl;
} 

//node insertion at the front
template <typename T>
void sllinserthead(T newData, SingleList<T>** currentHead){

    //allocate the memory for the new node
    SingleList<T>* newNode = new SingleList<T>;
    //Put data in a new node
    newNode->data = newData; 
    //set the new node to the point of the previous head
    newNode->next = *currentHead;
    //Reset head to point to the new node
    *currentHead = newNode;

}

//node insertion anywhere 
template <typename T>
void sllGeneralInsertion(T newData, SingleList<T>* prevNode){
    //check if the head node is null
    if(prevNode == nullptr){
        std::cout <<"A previous node cannot be null";
        return;
    }
    //allocate a new node
    SingleList<T>* newNode = new SingleList<T>;
    //store data inside a newnode
    newNode->data = newData;
    //point node to the previous node
    newNode->next = prevNode->next;
    //point previous node to the new node
    prevNode->next = newNode;

}

//node insertion at the end
template <typename T>
void sllInsertEnd(T newData, SingleList<T>** head){
    //allocate a new node
    SingleList<T>* newNode = new SingleList<T>;

    //Dereference to the head node
    SingleList<T>* currentNode = *head;

    //store data in the new node
    newNode->data = newData;

    //point data to null
    newNode->next = nullptr;

    //Check if list is empty, will insert new node in nullptr node
    if(currentNode == nullptr){
        currentNode == newNode;
        return;
    }
    
    //Traverse the list until the next node is null
    while(currentNode->next != nullptr){
        currentNode = currentNode->next; //iteration going to one node to another
    }

    currentNode->next = newNode;
}

//node deletion
template <typename T>
void sllDelete(T findData, SingleList<T>** head){

    //check if there is a list
    if(*head == nullptr){
        return;
    }

    SingleList<T>* cNode = *head;
    SingleList<T>* prevNode = nullptr;

    //Search fot the node
    while(cNode != nullptr && cNode->data != findData){
        prevNode = cNode;
        cNode = cNode->next;
    }


    //If data is not found
    if(cNode == nullptr) return;

    //delete the head node (the head node is findData)
    if (prevNode == nullptr){
        *head = cNode->next;
    }
    else {
        prevNode->next = cNode->next;
    }

    delete cNode;

}

template <typename T>
void sllDeleteList(SingleList<T>** head){
    SingleList<T>* cNode = *head;

    while(cNode != nullptr){
        SingleList<T>* temp = cNode;
        cNode = cNode->next;
        delete temp;
    }

    *head = nullptr;
}

#endif