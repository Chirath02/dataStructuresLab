#include <iostream>

using namespace std;

void swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void bubbleSort(int arr[],int size) {
	cout << "Bubble Sort " << endl;
	for(int i = 0; i < size; ++i) 
		for(int j = 0;j < size - i-1; ++j)
			if(arr[j] > arr[j+1]) 
				swap(arr, j, j+1);
	for(int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void insertionSort(int arr[], int size) {
	int index, key;
	cout << "Insertion sort" << endl;
	for(int i=0;i < size; ++i) {
		key = arr[i];
		for(int j = i; j <size;++j) {
			if(arr[j] < key) {
				index = j;
				key = arr[j];
				swap(arr,i,j);
			}
		}
	}
	for(int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int partition(int arr[], int initial, int final) {
	int temp = arr[final], i = initial - 1, j;
	for(j = initial; j <= final-1 ; j++) 
		if(arr[j] <= temp) {
			i++;
			swap(arr, i, j);
		}
	swap(arr, i+1, final);
	return i+1;
}

int quickSort(int arr[], int initial, int final) {
	int q;
	if(initial < final) {
		q = partition(arr, initial, final);
		quickSort(arr, initial, q-1);
		quickSort(arr, q+1, final);
	}	
}

int main() {
	int arr[100], size;
	cout << "Enter array size ";
	cin >> size;
	cout << "Enter array elemeants to be sorted ";
	for(int i=0; i < size; i++) 
		cin >> arr[i];
	//bubbleSort(arr, size);
	//insertionSort(arr, size);
	quickSort(arr, 0, size-1);
	for(int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}