//
//  DoublyLinkedListTemplate.cpp
//  DoublyLinkedListTemplate
//
//  Edited by Ahmet Ömer Kayabaşı on 11.01.2021.
//

#include "DoublyLinkedListTemplate.hpp"

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

//default constructor
template <class itemType>
DoublyLinkedList<itemType>::DoublyLinkedList ()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}


//Copy constructor for deep copy
template <class itemType>
DoublyLinkedList<itemType>::DoublyLinkedList (const DoublyLinkedList<itemType> & copy)
{
    tie(head,tail) = copy.createClone();
    
    size = copy.size;
}

//destructor function visits all nodes and returns to heap
template <class itemType>
DoublyLinkedList<itemType>::~DoublyLinkedList ()
{
    node<itemType> * ptr = head;
    while (ptr != NULL)
    {
        node<itemType> * temp = ptr->right;
        delete ptr;
        ptr = temp;
    }
}

template <class itemType>
void DoublyLinkedList<itemType>::addToBeginning (const itemType& n)
{
    
//    if list is empty
    if (size == 0) {
        node<itemType> * ptr = new node<itemType>(n,NULL,NULL);
        head = tail = ptr;
    }
    else{
        
    node<itemType> *ptr = new node<itemType>(n,NULL,head);
    
    head->left = ptr;
    
    head = ptr;
        
    }
    
    size++;
    
}

template <class itemType>
void DoublyLinkedList<itemType>::addToEnd (const itemType& n)
{
    
//    if list is empty
    if (size == 0) {
        node<itemType> * ptr = new node<itemType>(n,NULL,NULL);
        head = tail = ptr;
    }
    else{
        
    node<itemType> *ptr = new node<itemType>(n,tail,NULL);
    
    tail->right = ptr;
    
    tail = ptr;
        
    }
    
    size++;
    
}

template <class itemType>
void DoublyLinkedList<itemType>::printList () const
{
    node<itemType> * ptr = head;
    while (ptr != NULL)
    {
        cout << ptr ->info << endl;
        ptr = ptr->right;
    }
    cout << endl;
}

template <class itemType>
void DoublyLinkedList<itemType>::deleteList ()
{
    node<itemType> * ptr = head;
    while (ptr != NULL)
    {
        node<itemType> * temp = ptr->right;
        delete ptr;
        ptr = temp;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class itemType>
const DoublyLinkedList<itemType> & DoublyLinkedList<itemType>::operator = (const DoublyLinkedList<itemType> & rhs)
{
    if (this != &rhs)
    {
        deleteList(); // same as this->deleteList()
        size = rhs.size;
        tie(head,tail) = rhs.createClone();
    }
    return *this;
}


//generates a clone of the linked list object by generating new copies of
//each node and connecting them as in the original.
//Returns the head of the clone list.
template <class itemType>
pair<node<itemType> *,node<itemType> *> DoublyLinkedList<itemType>::createClone () const
{
    if (head == NULL)  //if list is empty
        return make_pair(nullptr, nullptr);   //clone is empty as well
    
    //first generate the first clone node and connect to head of clone
    node<itemType> * headClone = new node<itemType> (head->info, NULL,NULL);
    node<itemType> * ptr = head->right;  //second node in orig.
    node<itemType> * ptrClone = headClone; //to track the clone list
    
    while (ptr != NULL)
    {
        ptrClone->right = new node<itemType> (ptr->info, ptrClone, NULL);
        ptr = ptr->right;
        ptrClone = ptrClone->right;
    }
    
//    Making the doubly linked list
    node<itemType> * doubly = headClone;
    
    while(doubly->right != NULL){
        
        doubly->right->left = doubly;
        
        doubly = doubly->right;
    }
    

//    doubly represents the tail
    return make_pair(headClone, doubly);
//    return pair<headClone, doubly>;
}

template <class itemType>
void DoublyLinkedList<itemType>::printListReverse() const{
    node<itemType> * ptr = tail;
    
    while (ptr != NULL){
        
        cout << ptr->info << endl;
        ptr = ptr->left;
      
    }
    cout << endl;
    
}

template <class itemType>
DoublyLinkedList< node<itemType> * >  DoublyLinkedList<itemType>::searchElement(const itemType & elem)const{
    
    DoublyLinkedList< node<itemType> * > * list = new DoublyLinkedList< node<itemType> * >;
    
    node<itemType> * ptr = head;
    
    while(ptr != NULL){
        if(ptr->info == elem)
            list->addToBeginning(ptr);
        ptr = ptr->right;
    }
    
    return *list;
    
}

