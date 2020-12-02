TARGETS = AVL
CC = g++
CCFLAGS = -std=c++11 -g
AVL: main.cpp AVLInterface.h NodeInterface.h AVL.h AVL.cpp Node.h Node.cpp
	$(CC) $(CCFLAGS) -o avl main.cpp AVL.cpp Node.cpp
