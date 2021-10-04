#ifndef LISTNODE
#define LISTNODE

#include "ItemType.h"
#include <cstddef>

struct ListNode {
    ItemType item;
    ListNode* next = NULL;
};
#endif
