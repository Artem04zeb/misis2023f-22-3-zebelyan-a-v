#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, summa = 0;
	string comand;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> comand;
		if (comand == "++X" || comand == "X++") summa++;
		if (comand == "--X" || comand == "X--") summa--;
	}
	cout << summa;
	return 0;
}