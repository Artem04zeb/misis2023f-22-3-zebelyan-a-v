#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int count = 0, i, n;
    cin >> n;
    cin >> s;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
    }
    cout << count;
    return 0;
}