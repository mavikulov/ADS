#include <iostream>
#include <locale.h>
#include <algorithm>
#include "BinaryHeap.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Heap heap; // Создание пустой кучи размером 100
	int value;

	for (int i = 0; i < 7; i++) {
		cout << "Введите элемент " << i + 1 << " : ";
		cin >> value;
		heap.AddElem(value);
	}
	heap.DisplayHeap();
	cout << "Максимальный элемент в куче: " << heap.GetMax() << endl;
	cout << "Куча после удаления максимального элемента:" << endl;
	heap.DisplayHeap();
	return 0;
}