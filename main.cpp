#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;


int main() {
	int num;
	int list1[20], list2[20];
	int length1 = 0, length2 = 0;
	while (cin>>num) {
		list1[length1++] = num;
		if (cin.get() == '\n') {
			break;
		}
	}
	while (cin >> num) {
		list2[length2++] = num;
		if (cin.get() == '\n') {
			break;
		}
	}
	int head1 = 0, head2 = 0;
	int maxlength = 0;
	int length = 0;
	int start = 0;
	while (head1 < length1 && head2 < length2) {
		if (list1[head1] == list2[head2]) {
			length = 1;
			head1++, head2++;
			while (list1[head1] == list2[head2] && head1 < length1 && head2 < length2) {
				length++;
				head1++, head2++;
			}
			maxlength = (maxlength > length) ? maxlength : length;
			start = (maxlength > length) ? start : (head1 - length);
		}
		head1++, head2++;
	}
	//cout << "Êä³ö£º";
	for (int i = 0; i < maxlength; i++) {
		if (i == maxlength - 1) {
			cout << list1[start + i];
		}
		else {
			cout << list1[start + i] << " ";
		}
	}

	if (maxlength == 0) cout << maxlength - 1 << endl;;
	return 0;
}
