#include <iostream>
#define ll long long int
using namespace std;

void code_kor_hala()
{
    int n;
    cin >> n;
    int mx = -1, res = 1;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > 10) continue;
        if (b > mx) mx = b, res = i;
    }
    cout << res << "\n";

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        code_kor_hala();
    }
    return 0;
}