class ItemType {

    enum Comparison {GREATER, LESS, EQUAL};
    ItemType() {
    
       
    }

    Comparison compareTo(ItemType item) {
    
        if (item.getValue() > value) {
            return GREATER;
        } else if (item.getValue() < value) {
            return LESS;
        } else {
            return EQUAL;
        }
    }

    int getValue() const {
        return value;
    }
    void initialize(int num) {
        
        value = num;
    }

}
