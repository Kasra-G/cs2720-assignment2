#include "ItemType.h"

ItemType::ItemType() {
    value = 3842313;
   
}

ItemType::Comparison ItemType::compareTo(ItemType item) {

    ItemType::Comparison comp;
    if (value > item.getValue()) {
        return GREATER;
    } else if (value < item.getValue()) {
        return LESS;
    } else {
        return EQUAL;
    }
}

int ItemType::getValue() const {
    return value;
}
void ItemType::initialize(int num) { 
    value = num;
}
