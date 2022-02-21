#include <iostream>
#include <locale.h>
#include <algorithm>
#include "BinaryHeap.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Heap heap; // �������� ������ ���� �������� 100
	int value;

	for (int i = 0; i < 7; i++) {
		cout << "������� ������� " << i + 1 << " : ";
		cin >> value;
		heap.AddElem(value);
	}
	heap.DisplayHeap();
	cout << "������������ ������� � ����: " << heap.GetMax() << endl;
	cout << "���� ����� �������� ������������� ��������:" << endl;
	heap.DisplayHeap();
	return 0;
}