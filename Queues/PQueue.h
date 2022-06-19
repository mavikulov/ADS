#ifndef _PQUEUE_H
#define _PQUEUE_H

#include <iostream>

using namespace std;
typedef unsigned int uint;

template <typename ELEMTYPE>
class PQueue {
private:
	ELEMTYPE* data;
	uint* P;
	uint count;
public:
	PQueue() : data(nullptr), count(0), P(nullptr) {}
	PQueue(const PQueue<ELEMTYPE> &second) : count(second.count) {
		data = new ELEMTYPE[count];
		P = new ELEMTYPE[count];
		for (int i = 0; i < count; i++) {
			data[i] = second.data[i];
			P[i] = second.P[i];
		}
	}

	~PQueue() {
		delete[] data;
		delete[] P;
	}

	uint getCount() { return count; }
	void Clear() {
		if (this->count > 0) {
			delete[] data;
			delete[] P;
			count = 0;
		}
	}

	void Push(ELEMTYPE elem, uint priority) {
		ELEMTYPE* second_data;
		uint* P2;
		second_data = new ELEMTYPE[count + 1];
		P2 = new uint[count + 1];

		uint pos;
		if (count == 0)
			pos = 0;
		else {
			while (pos < count) {
				if (P[pos] < priority)
					break;
				pos++;
			}
		}

		for (size_t i = 0; i < pos; i++) {
			second_data[i] = data[i];
			P2[i] = P[i];
		}
		second_data[pos] = elem;
		P2[pos] = priority;

		for (size_t i = pos + 1; i < count + 1; i++) {
			second_data[i] = data[i - 1];
			P2[i] = P[i - 1];
		}

		if (count > 0) {
			delete[] data;
			delete[] P;
		}
		data = second_data;
		P = P2;
		count++;
	}

	ELEMTYPE Pop() {
		if (count == 0)
			return 0;
		ELEMTYPE* second_data;
		uint* P2;
		ELEMTYPE elem = data[0];
		second_data = new ELEMTYPE[count - 1];
		P2 = new ELEMTYPE[count - 1];

		for (int i = 0; i < count - 1; i++) {
			second_data[i + 1] = data[i + 1];
			P2[i + 1] = P[i + 1];
		}

		if (count > 0) {
			delete[] data;
			delete[] P;
		}
		count--;
		data = second_data;
		P = P2;
		return elem;
	}

	void display() {
		cout << "Priority Queue: ";
		for (size_t i = 0; i < count; i++) {
			cout << data[i] << ":" << P[i] << endl;
		}
		cout << endl;
	}
};


#endif _PQUEUE_H