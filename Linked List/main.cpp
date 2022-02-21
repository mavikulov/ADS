#include <iostream>
#include <locale.h>
#include "List.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a[8] = { 10, 20, 30, 40, 50, 60, 70, 80 };
	List example;
	example.push_back(15);
	example.push_back(20);
	example.push_back(25);
	example.push_back(30);
	example.display();

	//Node* to_insert;
	//to_insert->data = -1;

	Node* begin = new Node();
	Node* end = begin;
	Node* j;
	for (int i = 0; i < 8; i++) {
		end->next = new Node();
		end = end->next;
		end->data = a[i];
	}

	j = example.add(23, begin);
	example.display();
	return 0;
}