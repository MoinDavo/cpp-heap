#include <vector>
#include <cmath>
#include <iostream>
#include "Heap.h"
#include "HeapElement.h"

// ----------------------------------------------
// Constructors:
// ----------------------------------------------

Heap::Heap() {}
Heap::~Heap() {}

// ----------------------------------------------
// Private:
// ----------------------------------------------

/*
* restores the max-heap property
*/
void Heap::heapify() // should be more efficient
{
	if (this->content.size() < 1)
	{
		return;
	}
	for (int i = this->content.size(); i > 1; i--)
	{
		int parentIdx{(i - 1) / 2};
		if (this->content[i].getKey() > this->content[parentIdx].getKey())
		{
			this->swap(this->content[i], this->content[parentIdx]);
		}
		i = parentIdx;
	}
}


/*
* restores the max-heap property
*/
void Heap::heapify2()
{
	for (int i = 0; i < this->content.size(); i++) // work from top to bottom
	{
		int leftIdx{2 * i + 1}, rightIdx{2 * i + 2};
		bool ignoreLeft{false}, ignoreRight{false};

		// catch index out of bounds
		if (leftIdx > this->content.size() - 1)
		{
			ignoreLeft = true;
			leftIdx = this->content.size() - 1;
		}
		if (rightIdx > this->content.size() - 1)
		{
			ignoreRight = true;
			rightIdx = this->content.size() - 1;
		}

		HeapElement parent{this->content[i]};
		HeapElement left{this->content[leftIdx]};
		HeapElement right{this->content[rightIdx]};
		bool swapped{false};

		if (parent.getKey() < left.getKey() && !ignoreLeft)
		{
			swap(parent, left);
			swapped = true;
		}
		else if (parent.getKey() > right.getKey() && !ignoreRight)
		{
			swap(parent, right);
			swapped = true;
		}

		if (swapped) // do not proceed to next element if a swap was performed
		{
			i--;
		}
	}
}

/*
 * restores the max-heap property from i;
 * this only works if heap property is not fulfilled at one index
 * @param i index from which the heap shall be restored
 */
void Heap::heapifyRecursive(int i)
{
	
	int largest{i};
	int l{2 * i + 1}, r{2 * i + 2};

	if (l <= this->content.size()-1 && this->content[l].getKey() > this->content[i].getKey())
	{
		largest = l;
	}

	if (r <= this->content.size()-1 && this->content[r].getKey() > this->content[largest].getKey())
	{
		largest = r;
	}

	if (largest != i)
	{
		this->swap(this->content[i], this->content[largest]);
		this->heapifyRecursive(largest); // could this cause the segfault? no it does cause an endless loop XD
	}
}

/*
* swaps two elements within the heap
* @param e1 heap element to swap with other
* @param e2 heap element to swap with other
*/
void Heap::swap(HeapElement &e1, HeapElement &e2)
{
	HeapElement tmp{e1};
	e1 = e2;
	e2 = tmp;
}


// ----------------------------------------------
// Public:
// ----------------------------------------------

/*
* adds a supplied element to the heap and sorts it to the right position
*/
void Heap::addElement(const HeapElement &e)
{
	this->content.push_back(e);
	this->heapify();
	//this->heapifyI(this->content.back());
}


/*
* returns and deletes the root/top element of the heap
*/
HeapElement Heap::pop()
{
	HeapElement tmp{this->content[0]};
	swap(this->content[0], this->content.back());
	this->content.pop_back();
	if (!this->content.empty())
	{
		heapifyRecursive(this->content.size()-1); // on nativ linux -> segfault | on wsl -> stops here
	}
	return tmp;
}


/*
* returns the root/top element of the heap
*/
HeapElement Heap::top() { return this->content[0]; }

/*
* returns if the heap is empty
*/
bool Heap::isEmpty() { return this->content.empty(); }

/*
* output the heap contents to the cmdl
*/
void Heap::printHeap()
{
	for (size_t i = 0; i < this->content.size(); i++)
	{
		std::cout << std::to_string(this->content[i].getKey()) << ", ";
	}
	std::cout << "\n";
}