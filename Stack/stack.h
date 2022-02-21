#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
const int MAX_SIZE = 10000;

template <typename T>
class Stack {
private:
	T* data;
	int size;
	T top;
public:
	Stack() : size(100), top(0) {
		data = new T[size];
	}
	~Stack() { delete[] data; }
	Stack(int number);
	bool Push(const T);
	bool Pop();
	void display();
};

template <typename T>
Stack<T>::Stack(int number) {
	size = number;
	data = new T[size];
	top = -1;
}

template <typename T>
bool Stack<T>::Push(const T value) {
	if (top == size - 1)
		return false;
	top++;
	data[top] = value;
	return true;
}

template <typename T>
bool Stack<T>::Pop() {
	if (top == -1)
		return false;
	data[top] = 0;
	top--;
	return true;
}

template <typename T>
void Stack<T>::display() {
	for (int i = size - 1; i >= 0; i--)
		cout << "|" << setw(5) << data[i] << setw(5) << "|" << endl;
}
#endif STACK_H