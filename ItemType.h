#ifndef ITEMTYPE
#define ITEMTYPE
class ItemType {
    
    private:
        int value;
    public:
        enum Comparison {GREATER, LESS, EQUAL};
        ItemType();
        Comparison compareTo(ItemType item);
        int getValue() const;
        void initialize(int num);
};
#endif
