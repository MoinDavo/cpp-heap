#include "src/Heap.h"
#include "src/HeapElement.h"
#include "src/colours.h"
#include <iostream>
#include <stdlib.h>

void testFillPop1()
{
	Heap h;
	std::cout << GRN
			  << "testFillPop1 \n"
			  << reset;
	// test if heap works (i/o)
	std::cout << "fill heap... \n";
	h.addElement(HeapElement(5));
	std::cout << "added 5 \n";
	h.addElement(HeapElement(2));
	std::cout << "added 2 \n";
	h.addElement(HeapElement(3));
	std::cout << "added 3 \n";
	h.addElement(HeapElement(4));
	std::cout << "added 4 \n";
	h.addElement(HeapElement(1));
	std::cout << "added 1 \n";
	std::cout << "heap filled \n";

	std::cout << "test pop()...\n";
	std::cout << "to expect: \n"
			  << "5, 4, 3, 2, 1\n"
			  << "is: \n";

	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << "\n";
}

void testFillPop2()
{
	Heap h;
	std::cout << BLU
			  << "testFillPop2\n"
			  << reset;
	// test if heap works (i/o)
	std::cout << "fill heap... \n";
	h.addElement(HeapElement(0));
	std::cout << "added 0 \n";
	h.addElement(HeapElement(50));
	std::cout << "added 50 \n";
	h.addElement(HeapElement(30));
	std::cout << "added 30 \n";
	h.addElement(HeapElement(10));
	std::cout << "added 10 \n";
	h.addElement(HeapElement(20));
	std::cout << "added 20 \n";
	std::cout << "heap filled \n";

	std::cout << "test pop()...\n";
	std::cout << "to expect: \n"
			  << "50, 30, 20, 10, 0\n"
			  << "is: \n";

	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << ", ";
	std::cout << std::to_string(h.pop().getKey()) << "\n";
}

void testFillPopFillPop1()
{
	Heap h;

	std::cout << BGRN
			  << "testFillPopFillPop1 \n"
			  << reset;
	std::cout << "add 12 \n";
	h.addElement(HeapElement(12));
	std::cout << "add 12 \n";
	h.addElement(HeapElement(12));
	std::cout << "add 50 \n";
	h.addElement(HeapElement(50));
	std::cout << "add 23 \n";
	h.addElement(HeapElement(23));
	std::cout << "add 44 \n";
	h.addElement(HeapElement(44));
	std::cout << "add 80 \n";
	h.addElement(HeapElement(80));

	std::cout << "Removing 3 Elements\n"
			  << "to expect:\n"
			  << "80, 50, 44\n"
			  << "is: \n";
	std::cout << std::to_string(h.pop().getKey()) << ", "
			  << std::to_string(h.pop().getKey()) << ", "
			  << std::to_string(h.pop().getKey()) << "\n";

	std::cout << "add 13 \n";
	h.addElement(HeapElement(13));
	std::cout << "add 40 \n";
	h.addElement(HeapElement(40));
	std::cout << "add 154 \n";
	h.addElement(HeapElement(154));
	std::cout << "add 80 \n";
	h.addElement(HeapElement(80));

	std::cout << "Removing 7 Elements\n"
			  << "to expect: \n"
			  << "154, 80, 40, 23, 13, 12, 12\n"
			  << "is: \n";

	std::cout << std::to_string(h.pop().getKey()) << ", "
			  << std::to_string(h.pop().getKey()) << ", "
			  << std::to_string(h.pop().getKey()) << ", "
			  << std::to_string(h.pop().getKey()) << ", "
			  << std::to_string(h.pop().getKey()) << ", "
			  << std::to_string(h.pop().getKey()) << ", "
			  << std::to_string(h.pop().getKey()) << "\n";
}

int main(int argc, char const *argv[])
{
	testFillPop1();
	std::cout << "\n";

	testFillPop2();
	std::cout << "\n";

	testFillPopFillPop1();

	return 0;
}
