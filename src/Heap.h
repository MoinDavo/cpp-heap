#ifndef Heap_h
#define Heap_h

#include <vector>
#include "HeapElement.h"

class Heap // binary max-heap
{
private:
	std::vector<HeapElement> content;

	void heapify();							 // sort an already existing heap
	void heapify2();						 // sort an already existing heap (should be more efficient)
	void heapifyI(int);						 // sort an already existing heap
	void swap(HeapElement &, HeapElement &); // helper method for heapify()

public:
	Heap();
	~Heap();

	void addElement(HeapElement); // add an element to the heap and call heapify()
	HeapElement pop();			  // return and remove the top element
	HeapElement top();			  // return the top element
	bool isEmpty();				  // return if heap is empty (contains no elements)

	void printHeap();
};

#endif