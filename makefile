#pragma once

CC = g++
FLAGS = -Wall -pedantic-errors

main: main.o DoublyLinkedList.o
	$(CC) $(FLAGS) -o main main.o DoublyLinkedList.o

main.o: main.cpp DoublyLinkedList.h
	$(CC) $(FLAGS) -c main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	$(CC) $(FLAGS) -c DoublyLinkedList.cpp

run: compile
	./main

clean:
	rm -f *.o *.gch main