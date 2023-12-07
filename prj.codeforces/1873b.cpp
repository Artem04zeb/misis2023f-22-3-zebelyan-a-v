#include <iostream>
using namespace std;

int main() {
	int test;
	cin >> test;

	for (int i = 0; i < test; i++) {
		int num;
		cin >> num;
		int * arr = new int[num];

		for (int j = 0; j < num; j++) {
			cin >> arr[j];
		}

		// get small number of array
		int small = arr[0], count = 0;
		for (int j = 1; j < num; j++) {
			if (small > arr[j]) {
				small = arr[j];
				count = j;
			}
		}

		// add 1 to small num in array
		arr[count] = arr[count] + 1;

		// produce
		int result = arr[0];
		for (int j = 1; j < num; j++) {
			result = result * arr[j];
		}
		cout << result << endl;

		delete[] arr;
	}
	return 0;
}