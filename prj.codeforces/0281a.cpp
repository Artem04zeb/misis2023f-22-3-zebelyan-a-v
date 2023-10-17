#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	if (int(str[0]) > 90) str[0] = char(int(str[0])-32);

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}

	return 0;
}