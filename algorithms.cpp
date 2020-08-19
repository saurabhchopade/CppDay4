#include <iostream>
using namespace std;

void  bubbleSort(int array[],int size) {
	int sortCheck = 0;

	for(int passNo = 1; passNo < size - 1; passNo++) {

		for(int index = 0; index< size - passNo; index++) {

			if(array[index] > array[index + 1]) {
				int temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				sortCheck = 1;
			}
		}
		if(sortCheck == 0) {
			break;
		}
	}
}

void insertionSort(int array[], int size) {
	int i, j, key;
	for(int i = 1; i < size; i++) {
		key = array[i];
		for(j = i-1; j >= 0 && array[j] > key; j = j - 1) {
			array[j + 1] = array[j];
		}
		array[j + 1] = key;
	}

	   for(int index = 0; index < size; index++) {
      cout << array[index];
   }
}

void merge(int left[],int right[], int array[],int l,int r) {

	int leftSize = l;
	int rightSize = r;
	int i =0;
	int j = 0;
	int k =0;

	while(i < leftSize && j < rightSize) {

		if(left[i] <= right[j]) {
			array[k] = left[i];
			cout<<"  \n"<<array[k];
			k = k + 1;
			i = i + 1;
		}
		else {
			array[k] = right[j];
			k = k + 1;
			j = j + 1;
		}
	}

	while(i < leftSize) {
		array[k] = left[i];
		i = i + 1;
		k = k + 1;
	}

	while(j < rightSize) {
		array[k] = right[j];
		j = j + 1;
		k = k + 1;
	}
}


int mergeSort(int array[], int size) {
   int length = size;

   if(length < 2)return 0;

   int mid = length / 2;
   int left[mid];
   int right[length - mid];

   for(int i = 0; i < mid - 1; i++) {
      left[i] =array[i];
   }

   for(int i = mid; i < length - 1; i++) {
      right[i - mid] = array[i];
   }

   mergeSort(left, mid-1);
   mergeSort(right, length-1);
   merge(left, right, array, mid-1, length-1);
	return 0;
}

int binarySearch(int array[], int size, int num) {
	int low = 0;
	int high = size - 1;

	while(low < high) {
	   int mid = low + (high - low)/2;

		if(num == array[mid]) {
			cout << "\n Element Found At = " <<array[mid];
	 		return mid;
		}
		else if(num < array[mid]) {
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return -1;

}

int main() {

	int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int size = sizeof(array) / sizeof(array[0]);

	while(true) {
		int option = 0;
		cout << "\n SELECT OPTION \n";
		cout << "\n 1) bubble sort \n 2) insertion sort \n 3) Mergesort \n 4 binarySearch" ;
		cout << "\n\n Enter option = ";
		cin >> option;

		switch(option){
			case 1:
				bubbleSort(array, size);
				break;
			case 2:
				insertionSort(array, size);
				break;
			case 3:
				mergeSort(array,size);
				break;
			case 4:
				binarySearch(array, size , 2);
				break;
			default :
				cout << "Enter correct choice";
				break;
		}
	}
}
