CC = g++
CFLAGS = -I -g -Wall
DEPS = ItemType.h SortedLinkedList.h ListNode.h
OBJ = ItemType.o #SortedLinkedList.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)

main: $(OBJ) main.cpp
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) main
