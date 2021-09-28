class ItemType {
    
    enum Comparison {GREATER, LESS, EQUAL};
    private:
        extern int value;
    public:
        ItemType();
        Comparison compareTo(ItemType item);
        int getValue() const;
        void intialize(int num);
}
