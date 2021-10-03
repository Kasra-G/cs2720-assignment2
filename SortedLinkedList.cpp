#include "SortedLinkedList.h"
#include <cstddef>
#include <iostream>

using namespace std;

SortedLinkedList::SortedLinkedList() {
    head = NULL;
    currentPos = head;
    len = 0;
}

SortedLinkedList::~SortedLinkedList() {
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int SortedLinkedList::length() const{
    return len;
}

void SortedLinkedList::insertItem(ItemType item) {  
    ListNode* location = head;
    ListNode* temp = new ListNode;

    if (len == 0) {
        temp->item = item;
        head = temp;
        len += 1;
        return;
    }
    
    ListNode* prevloc;
    while (location != NULL) {
        if (item.compareTo(location->item) == ItemType::LESS) {
            break;
        } if (item.compareTo(location->item) == ItemType::EQUAL) {
            cout << "Sorry. You cannot insert the duplicate item" << endl;
            delete temp;
            return;
        }
        prevloc = location;
        location = location->next;
    }


    //NEEDS WORK HERE! 
    //If location is null, that means item must be inserted at the end of the list
    //If location is not null, then item must be inserted somewhere in the middle.

    temp->item = item;
    if (location == head) {
        temp->next = head;
        head = temp; 
    } else if (location == NULL) {
        temp = prevloc->next;
    } else {
        temp->next = location->next;
        prevloc->next = temp;
    }
    len += 1; 
}

void SortedLinkedList::deleteItem(ItemType item) {
    ListNode *location = head;  
    ListNode *prevloc;
    ListNode *temp;

    if (len == 0) {
        cout << "You cannot delete from an empty list" << endl;
        return;
    } else if (len == 1) {
        temp = head;
        delete temp;
    }
  
    while (location != NULL) {
        if (item.compareTo(location->item) == ItemType::EQUAL) {
            if (currentPos == location) {
                currentPos = currentPos->next;
            }
            break;
        }
        prevloc = location;
        location = location->next;
    }

    if (location == NULL) {
        cout << "You cannot delete from an empty list" << endl;
        return;
    } else if (location == head) {
        temp = head;
        delete temp;
        head = head->next;
    } else {
        temp = location->next;
        prevloc->next = temp;
        delete location;
    }
}

int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;
    int i = -1;
    ListNode *location = head;

    while (location != NULL) {
        if (item.compareTo(location->item) == ItemType::EQUAL) {
            return index;
        }
        location = location->next;
        index += 1;
    }

    cout << "Item not found" << endl;
    return i;
}

ItemType SortedLinkedList::getNextItem() {
    if (currentPos->next == NULL) {
        currentPos = head;
    } else {
        currentPos = currentPos->next;
    }

    return currentPos->item;
}

void SortedLinkedList::resetList() {
    while (head != NULL) {
        deleteItem(head->item);
    }
    
    currentPos = NULL;
}
