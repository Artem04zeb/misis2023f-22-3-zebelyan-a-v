#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string check_str = "";
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (check_str.find(str[i]) == -1) check_str += str[i];
	}

	if (check_str.size() % 2 == 0) cout << "CHAT WITH HER!";
	else cout << "IGNORE HIM!";
	
}