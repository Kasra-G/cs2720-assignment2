#include "ItemType.h"

ItemType::ItemType() {
    value = 3842313;
   
}

ItemType::Comparison ItemType::compareTo(ItemType item) {

    ItemType::Comparison comp;
    if (item.getValue() > value) {
        comp = GREATER;
    } else if (item.getValue() < value) {
        comp = LESS;
    } else {
        comp = EQUAL;
    }
    return comp;
}

int ItemType::getValue() const {
    return value;
}
void ItemType::initialize(int num) { 
    value = num;
}
