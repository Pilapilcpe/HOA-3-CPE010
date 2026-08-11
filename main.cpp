#include <iostream>
#include "singly_ll.h"
#include "double_ll.h"


int main(){
    
    //CREATION OF NODE
    doublelist<char>* head = new_Node('C');
    
    //CREATION OF OTHER NODES
    doublelist<char>* second = new_Node('P');
    doublelist<char>* third = new_Node('E');
    doublelist<char>* fourth = new_Node('1');
    doublelist<char>* fifth = new_Node('0');
    doublelist<char>* last = new_Node('1');
    
    //LINK THE NODES
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->next = last;
    last->prev = fifth;
    last->next = nullptr;

    
    std::cout <<"Initial Traversal: " << std::endl;
    dllTraverse(head);

    std::cout << "\n Insertion at the head \n";
    dllInsertHead('G', &head);
    dllTraverse(head);

    std::cout << "\nGeneral Insertion\n";
    dllGenInsert('E', second);
    dllTraverse(head);


    std::cout<<"\n Delete C \n";
    dllDelete('C',&head);
    dllTraverse(head);

    std::cout<<"\n Delete P \n";
    dllDelete('P',&head);
    dllTraverse(head);

    std::cout << "\nFinal\n";
    dllTraverse(head);

   return 0;
}