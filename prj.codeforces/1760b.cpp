#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s, a = "abcdefghijklmnopqrstuvwxyz";
		cin >> s;
		sort(s.begin(), s.end());
		for (int i = 0; i < a.size(); i++)
		{
			if (s[s.size() - 1] == a[i])
			{
				cout << i + 1 << endl;
				break;
			}
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}