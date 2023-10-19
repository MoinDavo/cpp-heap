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
	h.addElement(HeapElement(1));
	h.addElement(HeapElement(3));
	h.addElement(HeapElement(4));
	h.addElement(HeapElement(2));
	std::cout << "heap filled \n";

	std::cout << "test pop()...\n";
	std::cout << "to expect: \n"
			  << "5, 4, 3, 2, 1\n"
			  << "is: \n";
	h.printHeap();
	/*
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << "\n";
	*/

	return 0;
}
