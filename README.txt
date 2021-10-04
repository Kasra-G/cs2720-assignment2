Group Members:

Aditya Vurukala: av72034@uga.edu
Kasra Ghaffari: kg87769@uga.edu

Contributions:
Aditya - README.txt, ItemType.h, ItemType.cpp, ListNode.h, SortedLinkedList.h,
SortedLinkedList.cpp
Kasra - SortedLinkedList.h, SortedLinkedList.cpp, main.cpp, Makefile

How to Compile: make
How to Run: ./main input.txt

Merge Function:

for int i = 0 to otherList.length {
    if (searchItem(other->getNode(i)->item) != -1) {
        return;
    }
}
    
for (int i = 0; i < other->length(); i++) {
    insertItem(other->getNode(i)->item);
}

The complexity of our merge method is O(n^2).

Find Common Elements (Intersection) Function:

for (int i = 0; i < other->length(); i++) {
    ListNode* temp = other->getNode(i);
    if (searchItem(temp->item) != -1) {
        deleteItem(temp->item);
    }
}

The complexity of our intersection method is O(n).
