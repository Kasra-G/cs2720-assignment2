#ifndef LINKEDLIST
#define LINKEDLIST

#include "ItemType.h"
#include "ListNode.h"

class SortedLinkedList {
    private:
        ListNode* head;
        ListNode* currentPos;
        ListNode* getNode(int i);
        int len;
    public:
        SortedLinkedList();
        ~SortedLinkedList();
        int length() const;
        void insertItem(ItemType item);
        void deleteItem(ItemType item);
        int searchItem(ItemType item);
        ItemType getNextItem();
        void resetList();
        void merge(SortedLinkedList* other);
        void deleteAlternates();
        void intersection(SortedLinkedList* other);
};
#endif
