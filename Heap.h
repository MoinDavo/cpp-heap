#pragma once
#include <vector>
#include "HeapElement.h"

class Heap // binary max-heap
{
private:
	std::vector<HeapElement> content;

	void addElement(HeapElement);		 // add an element to the heap and call heapify()
	void heapify();						 // sort an already existing heap
	void swap(HeapElement, HeapElement); // helper method for heapify()

public:
	Heap();
	~Heap();

	HeapElement pop();	// return and remove the top element
	HeapElement pull(); // return the top element
};