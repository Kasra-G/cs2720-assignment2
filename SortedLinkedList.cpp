#include "SortedLinkedList.h"
#include <cstddef>

SortedLinkedList::SortedLinkedList() {
    head = NULL;
    len = 0;
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
