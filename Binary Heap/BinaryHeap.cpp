#include "BinaryHeap.h"
#include <algorithm>
#include <iostream>


Heap::Heap() {
	data = new int[MaxSize];
	HeapSize = 0;
}

void Heap::AddElem(int elem) {
	int i, parent;
	i = HeapSize;
	data[i] = elem;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (data[i] > data[parent])
			std::swap(data[i], data[parent]);
		i = parent;
		parent = (i - 1) / 2;
	}
	HeapSize++;
}

void Heap::DisplayHeap() {
	int i = 0;
	int k = 1;
	while (i < HeapSize) {
		while ((i < k) && (i < HeapSize)) {
			std::cout << data[i] << " ";
			i++;
		}
		std::cout << std::endl;
		k = k * 2 + 1;
	}
}

void Heap::DisplayArray() {
	for (int i = 0; i < this->HeapSize; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void Heap::Heapify(int vertex) {
	int left, right;
	left = 2 * vertex + 1;
	right = 2 * vertex + 2;

	if (left < HeapSize) {
		if (data[vertex] < data[left]) {
			std::swap(data[vertex], data[left]);
			Heapify(left);
		}
	}

	if (right < HeapSize) {
		if (data[vertex] < data[right]) {
			std::swap(data[vertex], data[right]);
			Heapify(right);
		}
	}
}

int Heap::GetMax() {
	int max;
	max = data[0];
	data[0] = data[HeapSize - 1];
	HeapSize--;
	Heapify(0);
	return max;
}