#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H


template <typename T>
class doublelist{
    public:
        T data;
        doublelist<T>* next = nullptr;
        doublelist<T>* prev = nullptr;
};

// ---------------
// Creating a node
// ---------------

template <typename T>
doublelist<T>* new_Node(T newData){
	// Dynamic Allocation for a new node
	doublelist<T>* newNode = new doublelist<T>;
	
	//store the data in a new node
	newNode->data = newData;
	
	//since its a new node point it to null
	newNode->next = nullptr;
	newNode->prev = nullptr;
	
	return newNode;
};

//-----------
//TRAVERSAL
//-----------

template <typename T>
void dllTraverse(doublelist<T>* currentNode){
  doublelist<T>* tail = nullptr; 
	//TRAVERSAL TO THE END
	while (currentNode != NULL){
        //prints the data
		std::cout << currentNode->data << " ";
        //saves the current node as the last visited node
		tail = currentNode;
        //move to the next node
            currentNode = currentNode->next;
        }
	
	
	        //REVERSE TRAVERSAL
    std::cout << "\nReverse Traversal: " << std::endl;
    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
	
	
}


//---------------------
//INSERTION AT THE HEAD
//---------------------



template <typename T>
void dllInsertHead(T newData, doublelist<T>** currentHead){
    
    //creates a new node
    doublelist<T>* newNode = new_Node(newData);

    //point to the current head
    newNode->next = *currentHead;

    //current head will be pointed to a new node
    (*currentHead)->prev = newNode;

    //update head pointer
    *currentHead = newNode;

}

//-------------------
//GENERAL INSERTION
//-------------------

template <typename T>
void dllGenInsert(T newData, doublelist<T>* prevNode){

    if(prevNode == nullptr){
        return;
    }

    //create a new node
    doublelist<T>* newNode = new_Node(newData);

    //new node points to the node after the prevNode
    newNode->next = prevNode->next;

    //newNode previous must be pointed to the prevNode
    newNode->prev = prevNode;

    //if there is a node after the previous node
    //make it point back to the new node
    if(prevNode->next != nullptr){
        prevNode->next->prev = newNode;
    }

    //prevNode will be pointed to the newNode
    prevNode->next = newNode;
}

//------------------
//INSERT AT THE END
//------------------
template <typename T>
void dllInsertEnd(T newData, doublelist<T>* currenthead){

    //Create a new node
    doublelist<T>* newNode = new_Node(newData);

    //Traverse until the last nod
    while(currenthead->next != nullptr){
        currenthead = currenthead->next;
    }

    currenthead->next = newNode;
    newNode->prev = currenthead;

}

//------------------
//DELETION
//------------------
template <typename T>
void dllDelete(T findData, doublelist<T>** currenthead){
    if(*currenthead == nullptr){
        return;
    }

    doublelist<T>* currentnode= *currenthead;

    while(currentnode != nullptr && currentnode-> data !=findData){
        currentnode= currentnode->next;
    }

    if (currentnode==nullptr){
        return;
    }
    if (currentnode == *currenthead){
        *currenthead=currentnode->next;

    if (currenthead !=nullptr){
        (*currenthead)->prev= nullptr;
    }

    }else {
        currentnode->prev->next= currentnode->next;
        if(currentnode->next !=nullptr){
            currentnode->next->prev= currentnode->prev;
        }
    }
    delete currentnode;
}

#endif