#include "SortedLinkedList.h"
#include "ItemType.h"
#include <cstddef>
#include <iostream>

using namespace std;

SortedLinkedList::SortedLinkedList() {
    head = NULL;
    len = 0;
    currentPos = head;
}

SortedLinkedList::~SortedLinkedList() {
    struct ListNode* temp;
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
    struct ListNode *temp;
    struct ListNode *prevloc;
    struct ListNode *location = head;

    if (length == 0) {
        temp->item = item;
        head = item;
        length += 1;
        return;
    }

    while (location != NULL) {
        if (item.compareTo(location->item) == GREATER) {
            break;
        } if (item.compareTo(location->item) == EQUAL) {
            cout << "Sorry. You cannot insert the duplicate item" << endl;
            return;
        }
        prevloc = location;
        location = location->next;
    }

    temp->item = item;
    if (location == head) {
        temp->next = head;
        head = temp; 
    } else {
        temp->next = location->next;
        prevloc->next = temp;
    }
    length += 1; 
}

int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;
    int i = -1;
    struct ListNode *location = head;

    while (location != NULL) {
        if (item.compareTo(location->item) == EQUAL) {
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
