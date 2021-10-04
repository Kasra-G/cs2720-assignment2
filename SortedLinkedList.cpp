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
        currentPos = head;
        len += 1;
        return;
    }
    
    ListNode* prevloc = NULL;
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


    //NEEDS WORK HERE! 
    //If location is null, that means item must be inserted at the end of the list
    //If location is not null, then item must be inserted somewhere in the middle.

    temp->item = item;
    temp->next = location;
    if (prevloc != NULL) {
        prevloc->next = temp;
    } else {
        head = temp;
    }
    len += 1; 
}

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
            len--;
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
    len--;
}

int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;
    ListNode *location = head;

    if (location == NULL) {
        return -1;
    }
    while (location != NULL) {
        if (item.compareTo(location->item) == ItemType::EQUAL) {
            return index;
        }
        location = location->next;
        index++;
    }
    return -1;
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

void SortedLinkedList::resetList() {
    currentPos = head;
}

ListNode* SortedLinkedList::getNode(int i) {
    ListNode* temp = head;
    while (i != 0 && temp != NULL) {
        temp = temp->next;
        i--;
    }
    return temp;
}

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

void SortedLinkedList::deleteAlternates() {
    ListNode* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (count % 2 == 1) {
            deleteItem(temp->item);
        }
        temp = temp->next;
        count++;
    }
} 

void SortedLinkedList::intersection(SortedLinkedList* other) {
    SortedLinkedList newList;
    for (int i = 0; i < other->length(); i++) {
        ListNode* temp = other->getNode(i);
        if (searchItem(temp->item) != -1) {
            newList.insertItem(temp->item);
        }
    }

    while (head != NULL) {
        deleteItem(head->item);
    }
    resetList();

    for (int i = 0; i < newList.length(); i++) {
        insertItem(newList.getNextItem());
    }
    
    
}
