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
    bool moreToSearch;
    ListNode* location = head;

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
            return;
        }
        prevloc = location;
        location = location->next;
    }

    ListNode* temp = new ListNode;

    //NEEDS WORK HERE! 
    //If location is null, that means item must be inserted at the end of the list
    //If location is not null, then item must be inserted somewhere in the middle.

    /*
    temp->item = item;
    if (location == head) {
        temp->next = head;
        head = temp; 
    } else {
        temp->next = location->next;
        prevloc->next = temp;
    }
    len += 1; 
    */
}

int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;
    int i = -1;
    struct ListNode *location = head;

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

ItemType SortedLinkedList::GetNextItem() {
    if (currentPos->next == NULL) {
        currentPos = head;
    } else {
        currentPos = currentPos->next;
    }
}
