#ifndef LISTNODE
#define LISTNODE

#include "ItemType.h"

struct ListNode {
    ItemType item;
    ListNode* next;
};
#endif
