#ifndef LIST__H
#define LIST__H
#include <iostream>

using namespace std;

/*
class List {
private:
	struct Node {
		int data;
		Node* next_ptr;
	};
	Node* HEAD;
	int count;
public:
	List() : HEAD(nullptr), count(0) {}
	~List() {
		while (HEAD != nullptr) {
			Node* tmp = HEAD->next_ptr;
			delete HEAD;
			HEAD = tmp;
		}
		count = 0;  // правильно ли?
	}
	int getCount() { return count; }
	bool isEmpty() { return HEAD == nullptr; }

	Node* Add(int val, Node* node = nullptr) {
		Node* tmp = new Node();
		tmp->data = val;
		count++;
		tmp->next_ptr = node->next_ptr;
		node->next_ptr = tmp;
		return tmp;
	}
	
	void Display() {
		if (isEmpty()) {
			cout << "Список пуст" << endl;
			return;
		}
		Node* tmp = HEAD;
		do {
			cout << tmp->data << " ";
			tmp = tmp->next_ptr;
		} while (tmp != nullptr);
		cout << endl;
	}
};


template <typename T>
Node* List<T>::Add(T val, Node* node) {

}
	Почему так не работает?
*/


struct Node {
	int data;
	Node* next;
};

class List {
public:
	Node* Head = nullptr;

	void push_back(int data) {
		Node* tmp = new Node();
		tmp->data = data;
		tmp->next = Head;
		Head = tmp;
	}

	void display() {
		Node* cur;
		cur = Head;
		while (cur != nullptr) {
			if (cur->next == nullptr)
				cout << cur->data;
			else 
				cout << cur->data << " --> ";
			cur = cur->next;
		}
		cout << endl;
	}

	Node* add(int val, Node* node) {
		Node* elem = new Node();
		elem->data = val;
		elem->next = node->next;
		node->next = elem;
		return elem;
	}
};

#endif LIST__H
