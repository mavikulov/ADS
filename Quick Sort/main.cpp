#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int partition(int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[h]);
	return (i + 1);
}

void qSort(int A[], int l, int h)
{
	if (l < h) {
		int p = partition(A, l, h);
		qSort(A, l, p - 1);
		qSort(A, p + 1, h);
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	vector <int> sort_numbers;
	int* arr;
	int size;
	cout << "������� ���-�� �����: ";
	cin >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "������� " << i + 1 << " �������: ";
		cin >> arr[i];
		sort_numbers.push_back(arr[i]);
	}

	cout << "��������� ������: ";
	for (auto elem: sort_numbers) 
		cout << elem << ' ';
	
	cout << endl;

	cout << "��������� ������: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';

	sort(sort_numbers.begin(), sort_numbers.end());
	cout << endl;

	qSort(arr, 0, size - 1);
	cout << "������ ����� ����������: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;

	cout << "��������������� ������: ";
	for (auto elem : sort_numbers)
		cout << elem << ' ';

	for (int i = 0; i < size; i++) {
		if (arr[i] != sort_numbers.at(i)) {
			cout << "���������� ������ �����������!" << endl;
			break;
		}
	}
	
	cout << endl;
	cout << "���������� ������ ���������!" << endl;
	return 0;
}