#include <galaxy-explorer/AsteroidList.hpp>
#include <iostream>
using namespace std;

AsteroidListItem::AsteroidListItem() {
                
    //creates a new Asteroid that has no data and points to nothing
    this->next = NULL;
    this->data = NULL;
}

AsteroidListItem::AsteroidListItem(Asteroid a) {
    
    //creates a new Asteroid using the data from the given Asteroid 'a'
    this->next = NULL;
    this->data = new Asteroid(a);
}

AsteroidListItem::~AsteroidListItem() {
    
    //deletes the content of the data in the Asteroid
    delete data;
}

AsteroidList::AsteroidList() {
    
    //creates an empty list by pointing to nullptr
    head.setNext(nullptr);
}

AsteroidList::AsteroidList(const AsteroidList& src)
{
	// The functions in this class are listed in a suggested order of implementation,
	// except for this one and the destructor (because you should put all your constructors together).
    
    //creates a pointer pointing to the first Asteroid in the copy source
    const AsteroidListItem* srcPtr = src.head.getNext();
    
    //creates a pointer pointing to the head of the duplicate AsteroidList
    AsteroidListItem* newListPtr = this->beforeBegin();
    
    //creates a pointer used for copying contents of the source to the duplicate
    AsteroidListItem* copyPtr;
    
    //while srcPtr is pointing to an Asteroid
    while (srcPtr != nullptr) {
        
        //make copyPtr point to a new Asteroid using the data from srcPtr
        copyPtr = new AsteroidListItem(srcPtr->getData());
        
        //set the next asteroid in the duplicate list to be the same as copyPtr
        newListPtr->setNext(copyPtr);
        
        //traverse to access the new duplicated asteroid in the duplicate list
        newListPtr = newListPtr->getNext();
        
        //point srcPtr to the next Asteroid to be duplicated
        srcPtr = srcPtr->getNext(); 
    }
    
}

AsteroidList::~AsteroidList() {
	// The functions in this class are listed in a suggested order of implementation,
	// except for this one and the copy constructor (because you should put all your constructors together).
    
    //clears the list
    clear();
}

void AsteroidList::pushFront(Asteroid e) {   
    
    //creates a temporary pointer pointing to a new asteroid e
    AsteroidListItem *tempPtr = new AsteroidListItem(e);
    
    //sets the Asteroid after 'e' to be what the first Asteroid used to be
    tempPtr->setNext(head.getNext());
    
    //sets the first Asteroid in the list to be e
    head.setNext(tempPtr);
    
}

Asteroid& AsteroidList::front() {
    
    //if head points to the first asteroid, then return that asteroid
    if (head.getNext() != nullptr) {
        return head.getNext()->getData();
    }
    
    //if head points to nullptr, then return nullptr
    else {
        return *(Asteroid*)nullptr;
    }
    
}

const Asteroid& AsteroidList::front() const {
	
    //if head points to the first asteroid, then return that asteroid
    if (head.getNext() != nullptr) {
        return head.getNext()->getData();
    }
    
    //if head points to nullptr, then return nullptr
    else {
        return *(const Asteroid*)nullptr;
    }
    
}

bool AsteroidList::isEmpty() const {
    
    //if there are no asteroids in the list, return true
    if (head.getNext() == nullptr) {
        return true;
    }
    
    //if the list is not empty, return false
    else {
        return false;
    }
    
}

int AsteroidList::size() const {
    
    //initializes and sets count to 0
    int count = 0;
    
    //creates a temporary pointer to what head is pointing to
    const AsteroidListItem *tempPtr = head.getNext();
    
    //while there are more objects, traverse the list and keep count of objects
    while (tempPtr != nullptr) {
        tempPtr = tempPtr->getNext();
        count = count+1;
    }
    
    //return size of list
    return count;
}

AsteroidListItem* AsteroidList::beforeBegin() {
    
    //return the Asteroid of head
    return &head;
    
}

const AsteroidListItem* AsteroidList::beforeBegin() const {
    
    //return the Asteroid of head
    return &head;
    
}

AsteroidListItem* AsteroidList::begin() {
	
    //Assign the what comes after head to tempPtr
    AsteroidListItem *tempPtr = head.getNext();
    
    //if tempPtr points to an Asteroid, return tempPtr
    if (tempPtr != nullptr) {
        return tempPtr;
    }
    
    //if tempPtr points to nullptr, then there are no asteroids, so return end()
    else {
        return end();
    }
    
}

const AsteroidListItem* AsteroidList::begin() const {

    //Assign the what comes after head to tempPtr
    const AsteroidListItem *tempPtr = head.getNext();
    
    //if tempPtr points to an Asteroid, return tempPtr
    if (tempPtr->getNext() != nullptr) {
        return tempPtr;
    }
    
    //if tempPtr points to nullptr, then there are no asteroids, so return end()
    else {
        return end();
    }
    
}

AsteroidListItem* AsteroidList::beforeEnd() {
    
    //assign the what comes after head to tempPtr
    AsteroidListItem *tempPtr = head.getNext();
    
    //if the list is empty, return beforeBegin()
    if (tempPtr == nullptr) {
        return beforeBegin();
    }
    
    //if the list is not empty, go through the list to find the last object
    else {
        
        //traverse the list until tempPtr points to the last Asteroid
        while (tempPtr->getNext() != nullptr) {
            tempPtr = tempPtr->getNext();
        }
    
        //While loop exists at last asteroid, return tempPtr
        return tempPtr;
    }

}

const AsteroidListItem* AsteroidList::beforeEnd() const {
    
    //Assign the what comes after head to tempPtr
    const AsteroidListItem *tempPtr = head.getNext();
    
    //if the list is empty, return beforeBegin()
    if (tempPtr == nullptr) {
        return beforeBegin();
    }
    
    //if the list is not empty, go through the list to find the last object
    else {
        
        //traverse the list until tempPtr points to the last Asteroid
        while (tempPtr->getNext() != nullptr) {
            tempPtr = tempPtr->getNext();
        }
    
        //While loop exists at last asteroid, return tempPtr
        return tempPtr;
    }
   
}

AsteroidListItem* AsteroidList::end() {

    return nullptr;
    
}

const AsteroidListItem* AsteroidList::end() const {

    return nullptr;
    
}

AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, Asteroid e) {
    
    //creates a pointer pointing to a new Asteroid with data from 'e'
    AsteroidListItem *newPtr = new AsteroidListItem(e);
    
    //assign prev to a temporary pointer tempPtr
    AsteroidListItem *tempPtr = prev; 
        
    //sets 'e' to point to what prev was pointing to before
    newPtr->setNext(tempPtr->getNext());
    
    //sets the prev to point to 'e'
    prev->setNext(newPtr);
    
    //traverse the list so prev points to the asteroid 'e'
    prev = prev->getNext();
    
    return prev;

}

AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, const AsteroidList& others) {
	
    //sets tempPtr equal to prev
    AsteroidListItem *tempPtr = prev;
    
    //sets afterPrev to point to object after prev initially
    AsteroidListItem *afterPrev = prev->getNext();
    
    //sets othersPtr to first object in others
    const AsteroidListItem *othersPtr = others.head.getNext();
    
    //if an empty list is given, return prev
    if (othersPtr == nullptr) {
        return prev;
    }
    
    //while othersPtr (pointer to others AsteroidList) is pointing to an object
    while (othersPtr != nullptr) {
        
        //creates newPtr pointing to a new Asteroid with the data from others
        AsteroidListItem *newPtr = new AsteroidListItem(othersPtr->getData());
        
        //sets the next object in the list to newPtr (the duplicated asteroid)
        tempPtr->setNext((newPtr));
        
        //advances the list to the new duplicated object
        tempPtr = tempPtr->getNext();
        
        //advances newPtr to the next object in others
        othersPtr = othersPtr->getNext(); 
    }
    
    //Assign the last object of others to endOfOthers
    AsteroidListItem *endOfOthers = tempPtr; 
    
    //sets the Asteroid after others to the Asteroid that used to be after prev
    tempPtr->setNext(afterPrev);
    
    return endOfOthers;
    
}

AsteroidListItem* AsteroidList::eraseAfter(AsteroidListItem* prev) {
    
    //sets tempPtr equal to prev
    AsteroidListItem *tempPtr = prev;
    
    //if there are no Asteroids after prev,then return end()
    if (tempPtr->getNext() == nullptr) {
        return end();
    }
    
    else {
        
        //sets afterPrev to point to the Asteroid after the Asteroid needed
        //to be erased (2 Asteroids ahead of prev)
        AsteroidListItem *afterPrev = prev->getNext()->getNext();
    
        //sets tempPtr equal to prev
        AsteroidListItem *tempPtr = prev;
    
        //empties the asteroid after prev
        free(tempPtr->getNext());
    
        //sets the asteroid after prev to be what is after the deleted asteroid
        tempPtr->setNext(afterPrev);
    
        //traverses to the asteroid after what was deleted
        tempPtr = tempPtr->getNext();
        
        return tempPtr;
    }
    
}

void AsteroidList::clear() {
    
    //Assign two pointers to the first Asteroid
    AsteroidListItem *nextPtr = head.getNext();
    AsteroidListItem *currPtr = head.getNext();
    
    //while there are more objects in the list
    while (nextPtr != nullptr) {
        
        //move nextPtr to the next object
        nextPtr = nextPtr->getNext();
        
        //delete the current object (behind nextPtr)
        delete currPtr;
        
        //sets currPtr to point to same object as nextPtr
        currPtr = nextPtr;
    }
    
    //sets head to point to nullptr
    head.setNext(nullptr);
    
}

AsteroidList& AsteroidList::operator=(const AsteroidList& src) {

    //if this AsteroidList is the same as src, then return (*this)
    if (this == &src) {
        return (*this);
    }
                       
    
    else {
        
        //clears this to have an empty AsteroidList
        this->clear();
   
        //insert src to after head of the newly
        //cleared list by using the insertAfter function
        this->insertAfter(&(this->head), src);
        
        return (*this);
    }
      
}
