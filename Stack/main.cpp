#include <iostream>
#include <iomanip>
#include <locale.h>
#include "stack.h"
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Stack <int> mystack(5);
	string s(20, '-');
	cout << "Заполнение стека:" << endl;
	for (int i = 0; i < 5; i++) {
		int elem;
		cin >> elem;
		mystack.Push(elem);
	}
	
	cout << s << endl;
	mystack.display();
	cout << s << endl;
	return 0;
}