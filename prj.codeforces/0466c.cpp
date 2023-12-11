#include <iostream>

using namespace std;
long long a[500005];
int main()
{
    int n, i, m;
    long long sum = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> m;
        a[i] = a[i - 1] + m;
        sum += m;
    }
    long long pj = sum / 3;
    long long pj1 = sum / 3 * 2;
    long long p1 = 0, p2 = 0;
    if (sum % 3 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        for (i = 1; i < n; i++)
        {
            if(a[i] == pj1) p2 += p1; 
            if(a[i] == pj) p1++; 
        }
        cout << p2 << endl;
    }
    return 0;
}