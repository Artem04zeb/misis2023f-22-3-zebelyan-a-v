#include <iostream>
using namespace std;
int main() {

	int a, b, t = 0;
	cin >> a >> b;

	while(a <= b) {
		t++;
		a = a * 3;
		b = b * 2;
	}
	cout << t;
	return 0;
}