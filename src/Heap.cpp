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
void Heap::heapify2() // this doesn't work ...
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

/*void Heap::heapify() // should be more efficient
{
	for (int i = this->content.size() + 1; i > 1; i--)
	{
		// int parentIdx{std::floor((i - 1) / 2)};
		int parentIdx{(i - 1) / 2};
		this->swap(this->content[i], this->content[parentIdx]);
		i = parentIdx;
	}
}*/

void Heap::heapify() {
	int 
}

void Heap::swap(HeapElement &e1, HeapElement &e2)
{
	HeapElement tmp{e1};
	e1 = e2;
	e2 = tmp;
}

// ----------------------------------------------
// Public:
// ----------------------------------------------
void Heap::addElement(HeapElement e)
{
	this->content.push_back(e);
	this->heapify();
}

HeapElement Heap::pop()
{
	HeapElement tmp{this->content[0]};
	swap(this->content[0], this->content.back());
	this->content.pop_back();
	heapify();
	return tmp;
}

HeapElement Heap::top() { return this->content[0]; }

bool Heap::isEmpty() { return this->content.empty(); }

void Heap::printHeap()
{
	for (size_t i = 0; i < this->content.size() - 1; i++)
	{
		std::cout << std::to_string(this->content[i].getKey()) << ", ";
	}
	std::cout << std::to_string(this->content[this->content.size() - 2].getKey()) << "\n";
}