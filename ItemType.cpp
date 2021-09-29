#include "ItemType.h"

ItemType::ItemType() {

   
}

ItemType::Comparison ItemType::compareTo(ItemType item) {

    if (item.getValue() > value) {
        return GREATER;
    } else if (item.getValue() < value) {
        return LESS;
    } else {
        return EQUAL;
    }
}

int ItemType::getValue() const {
    return value;
}
void initialize(int num) { 
    value = num;
}
