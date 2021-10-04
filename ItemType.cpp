#include "ItemType.h"

/**
 * Constructor for ItemType class.
 */
ItemType::ItemType() {
    value = 3842313;
   
}

/**
 * Compares the values of two ItemType objects and returns and enumeration.
 */
ItemType::Comparison ItemType::compareTo(ItemType item) {

    if (value > item.getValue()) {
        return GREATER;
    } else if (value < item.getValue()) {
        return LESS;
    } else {
        return EQUAL;
    }
}

/**
 * Returns the value held by the ItemType.
 */
int ItemType::getValue() const {
    return value;
}

/**
 * Sets the value of the ItemType equal to the given number.
 */
void ItemType::initialize(int num) { 
    value = num;
}
