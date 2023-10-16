#include <vector>
#include "Heap.h"
#include "HeapElement.h"

// ----------------------------------------------
// Constructors:
// ----------------------------------------------
Heap::Heap() {}

// ----------------------------------------------
// Private:
// ----------------------------------------------
void Heap::heapify()
{
	for (int i = 0; i < this->content.size(); i++) // work from top to bottom
	{
		int leftInd{2 * i + 1}, rightInd{2 * i + 2};
		bool ignoreLeft{false}, ignoreRight{false};

		// catch index out of bounds
		if (leftInd > this->content.size() - 1)
		{
			ignoreLeft = true;
			leftInd = this->content.size() - 1;
		}
		if (rightInd > this->content.size() - 1) 
		{
			ignoreRight = true;
			rightInd = this->content.size() - 1;
		}

		HeapElement parent{this->content[i]};
		HeapElement left{this->content[(2 * i + 1)]};
		HeapElement right{this->content[(2 * i + 2)]};
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

void Heap::swap(HeapElement e1, HeapElement e2)
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