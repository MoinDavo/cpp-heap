#include "HeapElement.h"

// ----------------------------------------------
// Constructors:
// ----------------------------------------------
HeapElement::HeapElement() : key{0} {};
HeapElement::HeapElement(int k) : key{k} {};
HeapElement::~HeapElement() {};

// ----------------------------------------------
// Public:
// ----------------------------------------------

int HeapElement::getKey() { return this->key; };
