#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int cnt = 0;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1]) cnt++;
    }

    cout << cnt << endl;
    delete[] a;
}