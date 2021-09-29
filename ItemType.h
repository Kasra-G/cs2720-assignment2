class ItemType {
    
    enum Comparison {GREATER, LESS, EQUAL};
    private:
        int value;
    public:
        ItemType();
        Comparison compareTo(ItemType item);
        int getValue() const;
        void initialize(int num);
};
