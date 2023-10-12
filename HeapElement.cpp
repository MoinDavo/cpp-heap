#include "HeapElement.h"

HeapElement::HeapElement() : key{0} {};
HeapElement::HeapElement(int k) : key{k} {};

int HeapElement::getKey() { return this->key; };
