#include <iostream>

using namespace std;
int a[105];
int b[105];
int main() {
	int m, s, x;
	cin >> m >> s;
	x = s;
	if (m == 1 && s == 0) {
		cout << 0 << " " << 0;
		return 0;
	}
	if (s == 0 || s > m * 9) {
		cout << -1 << " " << -1;
		return 0;
	}
	while (s != 0) {
		if (a[1] == 0) {
			a[1] = 1;
			s--;
			continue;
		}
		for (int i = m; i >= 1;) {
			if (a[i] != 9) {
				a[i]++;
				s--;
				break;
			}
			else {
				i--;
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << a[i];
	cout << " ";
	while (x != 0) {
		for (int i = 1; i <= m;) {
			if (b[i] != 9) {
				b[i]++;
				x--;
				break;
			}
			else {
				i++;
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << b[i];
}