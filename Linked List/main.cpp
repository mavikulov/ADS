#include <iostream>
#include <locale.h>
#include "List.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a[8] = { 10, 20, 30, 40, 50, 60, 70, 80 };
	List example;
	example.push_to_begin(15);
	example.push_to_begin(20);
	example.push_to_begin(25);
	example.push_to_begin(30);
	example.display();

	Node* begin = new Node();
	begin->data = -1;
	example.add(begin->data, begin);
	example.display();
	return 0;
}