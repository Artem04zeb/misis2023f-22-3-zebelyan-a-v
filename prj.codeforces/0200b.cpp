#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	double p, itog = 0;
	for (int i = 0; i < n; ++i)
	{
		p += cin >> p;
		itog += p / 100;
	}
	cout << itog / n;

	return 0;
}