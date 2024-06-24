#include <iostream>
using namespace std;
void merge(int A[],int low,int mid,int high) {
	int* B = new int[high - low + 1];
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high) {
		if (A[i] < A[j]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}
	while (i <= mid) B[k++] = A[i++];//将数组中剩下的元素放置B[]中
	while (j <= high) B[k++] = A[j++];
	for (i = low, k = 0; i <= high; i++)
		A[i] = B[k++];
	delete[]B;
}
void fen(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		fen(A, low, mid);
		fen(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}
int main() {
	int a[] = { 5,7,3,2,9,1,8};
	int low = 0, high = sizeof(a) / 4 - 1;
	fen(a, low, high);
	for (int i = 0; i < high+1; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}