#ifndef HeapElement_h
#define HeapElement_h

class HeapElement
{
private:
	int key;
	// type payload //if needed for later implementations

public:
	HeapElement();
	HeapElement(int k);
	~HeapElement();

	int getKey();
};

#endif