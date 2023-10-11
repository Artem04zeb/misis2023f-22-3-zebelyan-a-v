#include <iostream>
using namespace std;
int main() {

	int n, k, ak, total = 0;
	cin >> n >> k;

	int* points = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> points[i];
		if (i == k - 1) ak = points[i];
	}
	for (int i = 0; i < n; ++i) {
		if (points[i] >= ak && points[i] > 0) total += 1;
	}
	cout << total;

	delete[] points;
	return 0;
}