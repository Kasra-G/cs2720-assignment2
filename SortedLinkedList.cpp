#include "SortedLinkedList.h"
#include <cstddef>
#include <iostream>

using namespace std;

/**
 * Constructor for SortedLinkedList.
 */
SortedLinkedList::SortedLinkedList() {
    head = NULL;
    currentPos = head;
    len = 0;
}

/**
 * Destructor for SortedLinkedList.
 */
SortedLinkedList::~SortedLinkedList() {
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * Returns the length of the list.
 */
int SortedLinkedList::length() const{
    return len;
}

/**
 * Inserts a given item into the list as long as the item is not already present in the list.
 */
void SortedLinkedList::insertItem(ItemType item) {  
    ListNode* location = head;
    ListNode* temp = new ListNode;

    if (len == 0) {
        temp->item = item;
        head = temp;
        currentPos = head;
        len += 1;
        return;
    }
    
    ListNode* prevloc;
    while (location != NULL) {
        if (item.compareTo(location->item) == ItemType::LESS) {
            break;
        } if (item.compareTo(location->item) == ItemType::EQUAL) {
            cout << "Sorry. You cannot insert the duplicate item." << endl;
            delete temp;
            return;
        }
        prevloc = location;
        location = location->next;
    }

    temp->item = item;
    temp->next = location;
    prevloc->next = temp;
    len += 1; 
}

/**
 * Deletes specified item from the list if it exists in the list.
 */
void SortedLinkedList::deleteItem(ItemType item) {
    ListNode *location = head;  
    ListNode *prevloc;
    ListNode *temp;

    if (len == 0) { //Length of 0
        cerr << "You cannot delete from an empty list" << endl;
        return;
    } else if (len == 1) {  //Length of 1
        if (item.compareTo(head->item) == ItemType::EQUAL) {
            temp = head;
            delete temp;
            head = NULL;
            currentPos = head;
        } else {
            cerr << "Item not found." << endl;
        }
        return;
    }
  
    //Length > 1
    while (location != NULL) {
        if (item.compareTo(location->item) == ItemType::EQUAL) {
            break;
        }
        prevloc = location;
        location = location->next;
    }

    if (location == NULL) { //Item not found
        cerr << "Item not found." << endl;
        return;
    } else if (location == head) {  //Item was head
        temp = head;
        head = head->next;
        currentPos = head;
        delete temp;
    } else {    //Item was somehwere in the middle
        temp = location->next;
        prevloc->next = temp;
        delete location;
    }
}

/**
 * Searches through the list for specified item.
 */
int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;
    int i = -1;
    ListNode *location = head;

    while (location != NULL) {
        if (item.compareTo(location->item) == ItemType::EQUAL) {
            return index;
        }
        location = location->next;
        index++;
    }
    return i;
}

ItemType SortedLinkedList::getNextItem() {
    ListNode* temp = currentPos;
    if (head == NULL) {
        cerr << "List is empty" << endl;
        ItemType i;
        return i;
    } else if (currentPos == NULL) {
        cerr << "The end of the list has been reached" << endl;
        ItemType i;
        currentPos = head;
        return i;
    } else {
        currentPos = currentPos->next;
    }

    return temp->item;
}

/**
 * Resets the list.
 */
void SortedLinkedList::resetList() {
    currentPos = head;
}

/**
 * Gets the ListNode at the given index.
 */
ListNode* SortedLinkedList::getNode(int i) {
    ListNode* temp = head;
    while (i != 0 || temp != NULL) {
        temp = temp->next;
        i--;
    }
    return temp;
}

/**
 * Merges one list with the other list.
 */
void SortedLinkedList::merge(SortedLinkedList* other) {
    for (int i = 0; i < other->length(); i++) {
        if (searchItem(other->getNode(i)->item) != -1) {
            cerr << "Sorry. You cannot insert the duplicate item" << endl;
            return;
        }
    }
    
    for (int i = 0; i < other->length(); i++) {
        insertItem(other->getNode(i)->item);
    }
}

/**
 * Deletes every second node in the list.
 */
void SortedLinkedList::deleteAlternates() {
    ListNode* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        if (temp != NULL) {
            deleteItem(temp->item);
        }
    }
} 

/**
 * Prints out a list containing the common elements between the two lists.
 */
void SortedLinkedList::intersection(SortedLinkedList* other) {
    for (int i = 0; i < other->length(); i++) {
        ListNode* temp = other->getNode(i);
        if (searchItem(temp->item) != -1) {
            deleteItem(temp->item);
        }
    }
}
