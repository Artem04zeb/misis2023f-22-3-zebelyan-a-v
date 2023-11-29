#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	double p, itog = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> p;
		itog += p / 100;
	}
	printf("%.6f", itog / n * 100);
	return 0;
}