#ifndef _QUEUERING_H
#define _QUEUERING_H

#include <iostream>
#include <initializer_list>

using namespace std;

template <typename ELEMTYPE>
class QueueRing {
private:
	ELEMTYPE* data;
	uint count;
	uint maxCount;
	void Copy(const QueueRing<ELEMTYPE>& second) {
		if (maxCount > 0)
			delete[] data;
		try {
			count = second.count;
			maxCount = second.maxCount;
			data = new ELEMTYPE[maxCount];
			for (int i = 0; i < maxCount; i++)
				data[i] = second.data[i];
		}
		catch (bad_alloc err) {
			cout << err.what() << endl;
		}
	}

public:
	QueueRing() : data(nullptr), count(0), maxCount(1) {}
	QueueRing(initializer_list<ELEMTYPE> list) : maxCount(list.size()), count(list.size()) {
		data = new ELEMTYPE[maxCount];
		uint size = 0;
		for (auto elem : list) {
			data[size++] = elem;
		}
	}
	QueueRing(int maxSize) {
		try {
			maxCount = maxSize;
			data = new ELEMTYPE[maxCount];
			count = 0;
		}
		catch (bad_alloc err) {
			cout << err.what() << endl;
		}
	}
	
	QueueRing(const QueueRing<ELEMTYPE>& second) {
		Copy(second);
	}

	~QueueRing() {
		delete[] data;
		count = 0;
		maxCount = 0;
	}

	bool isEmpty() { return count == 0; }
	bool isFull() { return count == maxCount; }
	uint getCount() { return count; }
	QueueRing<ELEMTYPE> operator =(const QueueRing<ELEMTYPE>& second) {
		Copy(second);
		return *this;
	}

	void Move() {
		ELEMTYPE item = data[0];
		for (int i = 1; i < count; i++)
			data[i - 1] = data[i];
		data[count - 1] = item;
	}

	void Push(ELEMTYPE elem) {
		if (isFull())
			throw "Can not push into full queue";
		data[count++] = elem;
	}

	ELEMTYPE Pop() {
		if (isEmpty())
			throw "Can not take something from empty queue";
		ELEMTYPE* tmp;
		ELEMTYPE item = data[count];
		tmp = data;
		data = new ELEMTYPE[count - 1];
		count--;
		for (int i = 0; i < count - 1; i++)
			data[i] = tmp[i];
		delete[] tmp;
		return item;
	}

	void display() {
		if (isEmpty()) {
			cout << "Кольцевая очередь пуста!" << endl;
		}
		for (int i = 0; i < count; i++) {
			if (i == count - 1)
				cout << data[i];
			else
				cout << data[i] << " --- ";
		}
		cout << endl;
	}
};

#endif _QUEUERING_H