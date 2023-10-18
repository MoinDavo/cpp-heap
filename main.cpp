#include "src/Heap.h"
#include "src/HeapElement.h"
#include <iostream>
 
int main(int argc, char const *argv[])
{
	Heap h;

	//test if heap works (i/o)
	std::cout << "fill heap...";
	h.addElement(HeapElement(5));
	h.addElement(HeapElement(1));
	h.addElement(HeapElement(3));
	h.addElement(HeapElement(4));
	h.addElement(HeapElement(2));

	std::cout << "test pop()...";
	std::cout << "to expect: \n" << "5, 4, 3, 2, 1"; 

	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey());

	return 0;
}
