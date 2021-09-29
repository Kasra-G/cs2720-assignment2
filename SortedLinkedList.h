#ifndef LINKEDLIST
#define LINKEDLIST

#include "ItemType.h"
#include "ListNode.h"

class SortedLinkedList {
    private:
        struct ListNode* head;
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
        void merge();
        void deleteAlternates();
        void intersect();
};
#endif
