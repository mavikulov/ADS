#ifndef BINARYHEAP_H
#define BINARYHEAP_H

class Heap {
private:
	int* data;
	int HeapSize;
	static const int MaxSize = 100;
public:
	Heap();
	void AddElem(int);
	void DisplayHeap();
	void DisplayArray();
	int GetMax(); 
	void Heapify(int);
};

#endif