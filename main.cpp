#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include <iterator>
#include <vector>
#include "DoublyLinkedList.h"

void printGreeting() {
    std::cout << "Enter list type (i - int, f - float, s - std::string): ";
}

void printOptions() {
    std::cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m)," << std::endl;
    std::cout << "printReverse (r), swapAtl(s), quit (q)" << std::endl;
}

DoublyLinkedList<int> createIntList(std::string fileName) {
    std::ifstream sFile(fileName.c_str());
	std::vector<int> vals;
	int num;
	DoublyLinkedList<int> created = DoublyLinkedList<int>();

	if (!sFile.is_open()) {
		std::cout << "File not found" << std::endl;
	}
	while (sFile >> num) {
		vals.push_back(num);
	}
    
    for (int j = 0; j < vals.size(); j++) {
        std::cout << vals.at(j) << " ";
    }

	for(int i = 0; i < vals.size(); i++) {
        std::cout << "Building" << std::endl;
        num = vals.at(i);
        std::cout << "num assigned" << std::endl;
		created.insertItem(num);
	}
	sFile.close();
	return created;
}

DoublyLinkedList<float> createFloatList(std::string fileName) {
    std::ifstream sFile(fileName.c_str());
	std::vector<float> vals;
	float num;
	DoublyLinkedList<float> created = DoublyLinkedList<float>();

	if (!sFile.is_open()) {
		std::cout << "File not found" << std::endl;
	}
	while (sFile >> num) {
		vals.push_back(num);
	}
	for(const auto &i: vals) {
        num = vals.at(i);
		created.insertItem(num);
	}
	sFile.close();
	return created;
}

DoublyLinkedList<std::string> createStringList(std::string fileName) {
    std::ifstream sFile(fileName.c_str());
	std::vector<std::string> vals;
	std::string num;
	DoublyLinkedList<std::string> created = DoublyLinkedList<std::string>();

	if (!sFile.is_open()) {
		std::cout << "File not found" << std::endl;
	}
	while (sFile >> num) {
		vals.push_back(num);
	}
	for(int i = 0; i < vals.size(); i++) {
        num = vals.at(i);
		created.insertItem(num);
	}
	sFile.close();
	return created;
}

void intList(DoublyLinkedList<int> list) {
    int item, len;
    char operation;

    while(1) {
        printOptions();
        std::cout << "Enter a command: ";
        std::cin >> operation;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(operation) {
        case 'i':
            std::cout << "Item to insert: ";
            std::cin >> item;
            list.DoublyLinkedList<int>::insertItem(item);
            break;
        case 'd':
            std::cout << "Enter item to delete: ";
            std::cin >> item;
            list.DoublyLinkedList<int>::deleteItem(item);
            break;
        case 'l':
            len = list.DoublyLinkedList<int>::lengthIs();
            std::cout << len << std::endl;
            break;
        case 'p':
            list.DoublyLinkedList<int>::print();
            break;
        case 'b': 
            list.DoublyLinkedList<int>::deleteSubsection();
            break;
        case 'm':
            list.DoublyLinkedList<int>::mode();
            break;
        case 'r':
            list.DoublyLinkedList<int>::printReverse();
            break;
        case 's':
            list.DoublyLinkedList<int>::swapAlternate();
            break;
        case 'q':
            std::cout << "Quitting program..." << std::endl;
            return;
        default:
            std::cout << "Invalid command, try again!" << std::endl;
            break;    
        }
    }

}

void floatList(DoublyLinkedList<float> list) {
    std::cout << "fList" << std::endl;

}

void stringList(DoublyLinkedList<std::string> list) {
    std::cout << "sList" << std::endl;

}

int main (int argc, char *argv[]) {

    DoublyLinkedList<int> iList = DoublyLinkedList<int>();
    DoublyLinkedList<float> fList = DoublyLinkedList<float>();
    DoublyLinkedList<std::string> sList = DoublyLinkedList<std::string>();

    if (argc != 2) {
        std::cout << "Usage: ./main [inputfile.txt]" << std::endl;
        return 1;
    }

    if (strcmp(argv[1], "int-input.txt") == 0) {
        iList = createIntList("int-input.txt");
    } else if (strcmp(argv[1], "int_input2.txt") == 0) {
        iList = createIntList("int-input2.txt");
    } else if (strcmp(argv[1], "float-input.txt") == 0) {
        fList = createFloatList("float-input.txt");
    } else if (strcmp(argv[1], "string-input.txt") == 0) {
        sList = createStringList("string-input.txt");
    }

    std::string type;
    while(1) {
        printGreeting();
        std::cin >> type;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (type == "i") {
            intList(iList);
            break;
        } else if (type == "f") {
            floatList(fList);
            break;
        } else if (type == "s") {
            stringList(sList);
            break;
        } else {
            std::cout << "Please enter a valid list type" << std::endl;
            continue;
        }
        break;
    }
    return 0;
} // main