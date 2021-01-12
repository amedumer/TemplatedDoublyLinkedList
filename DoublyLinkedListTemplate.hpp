//
//  DoublyLinkedListTemplate.hpp
//  DoublyLinkedListTemplate
//
//  Taken from CS204 Lab Material.
//  Edited by Ahmet Ömer Kayabaşı on 11.01.2021.
//

#ifndef DoublyLinkedListTemplate_hpp
#define DoublyLinkedListTemplate_hpp

#include <stdio.h>

template <class itemType>
struct node {
    itemType info;
    node * left;
    node * right;
    
    node ()
    {}
    
    node (const itemType & s, node * left, node* right)
    : info(s), left (left),right(right)
    { }
    
};


template <class itemType>
class DoublyLinkedList
{
private:
    node<itemType> * head,* tail;
    int size;
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList&);  //copy constructor
    ~DoublyLinkedList();   //destructor
    void printList() const;
    void printListReverse() const;
    void addToBeginning(const itemType& n);
    void addToEnd(const itemType& n);
    void deleteList ();
    const DoublyLinkedList& operator = (const DoublyLinkedList& rhs);
	std::pair<node<itemType> *,node<itemType> *>  createClone () const; //generates the clone of the list and return the clone's head
	DoublyLinkedList< node<itemType> * >  searchElement(const itemType & elem) const; // returns a linked list of pointers with the desired search value
};


#include "DoublyLinkedListTemplate.cpp"

#endif /* DoublyLinkedListTemplate_hpp */
