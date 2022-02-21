#include <iostream>
#include <algorithm>
#include <locale.h>
#include <vector>

using namespace std;
typedef unsigned int uint;


void BucketSort(double* arr) {

	// 1) Создаем ящики для дальнейшего разбиения
	vector <double> buckets[6];
	
	// 2) Кладем элементы массива в различные ящики
	for (int i = 0; i < 6; i++) {
		int bucket_index = 6 * arr[i];
		buckets[bucket_index].push_back(arr[i]);
	}

	// 3) Сортируем каждый ящик индивидуально
	for (int i = 0; i < 6; i++)
		sort(buckets[i].begin(), buckets[i].end());

	// 4) Конкатенация(слияние) всех ящиков в массив
	int index = 0;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < buckets[i].size(); j++)
			arr[index++] = buckets[i][j];
}




template <typename T>
void Heapify(T* arr, uint size, uint i) {
	uint largest = i;
	uint left = 2 * i + 1;
	uint right = 2 * i + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		Heapify(arr, size, largest);
	}
}

template <typename T>
void HeapSort(T* arr, uint size) {
	for (int i = size / 2 - 1; i >= 0; i--)
		Heapify(arr, size, i);
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

template <typename T>
void displayArray(T* arr, uint size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int* mas;
	uint dim;
	cout << "Введите размер массива: ";
	cin >> dim;
	mas = new int[dim];
	cout << "Заполнение псевдослучайными числами..." << endl;
	for (int i = 0; i < dim; i++)
		mas[i] = rand() % 10;
	cout << "Массив до сортировки кучей: " << endl;
	displayArray(mas, dim);
	HeapSort(mas, dim);
	displayArray(mas, dim);

	cout << "Массив до сортировки вычерпыванием:" << endl;
	double float_nums[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
	for (int i = 0; i < 6; i++)
		cout << float_nums[i] << ' ';
	cout << endl;
	BucketSort(float_nums);
	displayArray(float_nums, 6);
	return 0;
}