#ifndef _QUEUE_H
#define _QUEUE_H
#include <exception>
#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;


template <typename ELEMTYPE>
class Queue {
private:
	ELEMTYPE* data;
	uint count;
	bool checkCount() { return count > 0; }
public:
	Queue() : count(0) {}
	Queue(const Queue<ELEMTYPE>& second) {
		if (second.checkCount())
			count = second.count;
		try {
			data = new ELEMTYPE[count + 1];
			for (int i = 0; i < count; i++)
				data[i] = second.data[i];
		}
		catch (bad_alloc err) {
			cout << err.what() << endl;
			count = 0;
		}
	}

	~Queue() {
		if (checkCount())
			delete[] data;
	}

	void Push(ELEMTYPE elem) {
		ELEMTYPE* tmp;
		tmp = data;
		
		try {
			data = new ELEMTYPE[count + 1];
			for (int i = 0; i < count; i++)
				data[i] = tmp[i];
			data[count] = elem;
			count++;

			if (count > 1)
				delete[] tmp;
		}
		catch (bad_alloc err) {
			cout << err.what() << endl;
			data = tmp;
		}
	}

	ELEMTYPE Pop() {
		if (isEmpty())
			throw "Ќевозможно извлечь что-либо из пустой очереди!";
		ELEMTYPE elem;
		elem = data[0];

		try {
			ELEMTYPE* tmp;
			tmp = new ELEMTYPE[count - 1];
			count--;
			for (int i = 0; i < count; i++)
				tmp[i] = data[i + 1];
			if (count > 0)
				delete[] data;
			data = tmp;
			return elem;
		}
		catch (bad_alloc err) {
			cout << err.what() << endl;
			return 0;
		}
	}

	ELEMTYPE& front() {
		if (isEmpty()) 
			throw "Ќевозможно извлечь что-либо из пустой очереди!";
		return data[0];
	}

	ELEMTYPE& rear() {
		if (isEmpty())
			throw "Ќевозможно извлечь что-либо из пустой очереди!";
		return data[count - 1];
	}


	bool isEmpty() { return count == 0; }
	uint getCount() { return count; }

	void clear() {
		if (checkCount()) {
			delete[] data;
			count = 0;
		}
	}

	void display() {
		if (isEmpty())
			cout << "Queue is empty!" << endl;
		for (int i = 0; i < count; i++) {
			if (i == count - 1)
				cout << data[i];
			else
				cout << data[i] << " --- ";
		}
		cout << endl;
	}
};


#endif _QUEUE_H
