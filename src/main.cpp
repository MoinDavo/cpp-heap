#include "../include/Heap.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	Heap h;

	//test if heap works (i/o)
	h.addElement(HeapElement(5));
	h.addElement(HeapElement(1));
	h.addElement(HeapElement(3));
	h.addElement(HeapElement(4));
	h.addElement(HeapElement(2));

	std::cout << h.pop().getKey();
	std::cout << h.pop().getKey();
	std::cout << h.pop().getKey();
	std::cout << h.pop().getKey();
	std::cout << h.pop().getKey();

	return 0;
}
