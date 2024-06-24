#include <iostream>
using namespace std;

int Part(int a[], int low, int high) {
	int i = low, j = high, data = a[low];
	while (i < j) {
		while (i<j && a[j]>data) j--;
		if (i < j) {
			swap(a[i++], a[j]);
		}
		while (i < j && a[i] <= data) i++;
		if (i < j) {
			swap(a[i], a[j--]);
		}
	}
	return i;
}

void sort(int a[], int low, int high) {
	if (low < high) {
		int mid = Part(a, low, high);
		sort(a, low, mid - 1);
		sort(a, mid + 1, high);
	}
}

int main() {
	int a[7] = { 1,3,2,2,4,7,5 };
	sort(a, 0, 6);
	for (int i = 0; i < 7; i++) {
		cout << a[i] << " ";
	}
	return 0;
}