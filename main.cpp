#include "src/Heap.h"
#include "src/HeapElement.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	Heap h;

	printf("test \n");

	// test if heap works (i/o)
	std::cout << "fill heap... \n";
	h.addElement(HeapElement(5));
	std::cout << "added 5 \n";
	h.printHeap();
	std::cout << "test \n";
	h.pop();
	/*
	h.addElement(HeapElement(1));
	std::cout << "added 1 \n";
	h.addElement(HeapElement(3));
	std::cout << "added 3 \n";
	h.addElement(HeapElement(4));
	std::cout << "added 4 \n";
	h.addElement(HeapElement(2));
	std::cout << "added 2 \n";
	std::cout << "heap filled \n";

	std::cout << "test pop()...\n";
	std::cout << "to expect: \n"
			  << "5, 4, 3, 2, 1\n"
			  << "is: \n";
	h.printHeap();
	*/
	
	/*
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << "\n";
	*/

	return 0;
}
