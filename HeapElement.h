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