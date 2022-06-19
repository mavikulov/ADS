#include "Queue.h"
#include "QueueRing.h"

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "---��������� ��� ������ � ���������---" << endl;
	cout << "1 - �������" << endl;
	cout << "2 - ��������� �������" << endl;
	uint choice;
	cout << "������� ��� �����: ";
	cin >> choice;

	if (choice == 1) {
		cout << "�������� ������ ���� ������ � �������?" << endl;
		cout << "1 - int" << endl;
		cout << "2 - double" << endl;
		cout << "3 - string" << endl;
		uint type;
		cout << "������� ��� ������:";
		cin >> type;
		Queue<int> intQueue;
		Queue<double> doubleQueue;
		Queue<string> stringQueue;

		if (type == 1) {
			intQueue.Push(32);
			intQueue.Push(9);
			intQueue.Push(7);
			intQueue.Push(0);
			intQueue.Push(-999);
			cout << endl << "�������: ";
			intQueue.display();
		}
		else if (type == 2) {
			doubleQueue.Push(23.87);
			doubleQueue.Push(0.23);
			doubleQueue.Push(12.897);
			doubleQueue.Push(25.093);
			doubleQueue.Push(-193.502);
			cout << endl << "�������: ";
			doubleQueue.display();
		}
		else if (type == 3) {
			stringQueue.Push("First");
			stringQueue.Push("Second");
			stringQueue.Push("Third");
			stringQueue.Push("Fourth");
			stringQueue.Push("Fifth");
			cout << endl << "�������: ";
			stringQueue.display();
		}
		else
			cout << "������ ��� ������ ���� ������" << endl;

		cout << "������� front = ";
		if (type == 1)
			cout << intQueue.front() << endl;
		else if (type == 2)
			cout << doubleQueue.front() << endl;
		else
			cout << stringQueue.front();

		cout << "������� rear = ";
		if (type == 1)
			cout << intQueue.rear() << endl;
		else if (type == 2)
			cout << doubleQueue.rear() << endl;
		else
			cout << stringQueue.rear();

		cout << "�������� ����������������� ������ Pop" << endl;
		if (type == 1) {
			cout << "������� �� ����� = " << intQueue.Pop() << endl;
			cout << "������� ����� ������ Pop: ";
			intQueue.display();
		}
		else if (type == 2) {
			cout << "������� �� ����� = " << doubleQueue.Pop() << endl;
			cout << "������� ����� ������ Pop: ";
			doubleQueue.display();
		}
		else {
			cout << "������� �� ����� = " << stringQueue.Pop() << endl;
			cout << "������� ����� ������ Pop: ";
			stringQueue.display();
		}
	}
	else if (choice == 2) {
		QueueRing<int> QRint {1, 3, 7, -5, -10, 29, 38};
		QueueRing<double> QRdouble(6);
		QueueRing<string> QRstring {"Today", "we gonna", "play", "fortnite"};
		cout << "�������� ������ ���� ������ � ��������� �������?" << endl;
		cout << "1 - int" << endl;
		cout << "2 - double" << endl;
		cout << "3 - string" << endl;
		cout << "������� ��� ������:";
		uint type;
		cin >> type;
		if (type == 1) {
			cout << "��������� �������: ";
			QRint.display();
		}
		else if (type == 2) {
			QRdouble.Push(2.09);
			QRdouble.Push(-3.986);
			QRdouble.Push(290.720);
			QRdouble.Push(0.0);
			QRdouble.Push(0.352);
			QRdouble.Push(12.40);
			cout << "��������� �������: ";
			QRdouble.display();
		}
		else {
			cout << "��������� �������: ";
			QRstring.display();
		}

		cout << "����������� ����� ������� � ������ �������." << endl;
		QRint.Move();
		QRint.display();
	}
	return 0;
}