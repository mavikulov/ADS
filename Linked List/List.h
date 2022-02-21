#ifndef LIST__H
#define LIST__H
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class List {
public:
	Node* Head = nullptr;

	void push_to_begin(int data) {
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

	Node* Prev(Node* node) {
		if (Head == nullptr || node == Head)
			return nullptr;
		Node* tmp = Head;
		while (tmp->next != node)
			tmp = tmp->next;
		return tmp;
	}

	Node* add(int val, Node* node) {
		Node* elem = new Node();
		elem->data = val;
		elem->next = node->next;
		node->next = elem;
		return elem;
	}

	Node* del(Node* node) {
		if (node == nullptr)
			return nullptr;
		if (node == Head) {
			Head = node->next;
			delete node;
			return Head;
		}

		Node* prev = Prev(node);
		prev->next = node->next;
		delete node;
		return prev;
	}
};



#endif LIST__H
