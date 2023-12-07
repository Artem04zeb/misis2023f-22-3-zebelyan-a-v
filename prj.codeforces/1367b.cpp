#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    vector<int> veven, vodd;
    for (int i = 0; i < t; i++)
    {
        veven.clear();
        vodd.clear();
        cin >> n;
        int * a = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            if (j % 2 == 0 && a[j] % 2 != 0)
                vodd.emplace_back(a[j]);
            else if (j % 2 != 0 && a[j] % 2 == 0)
                veven.emplace_back(a[j]);
        }
        if (vodd.size() == veven.size())
            cout << vodd.size() << endl;
        else
            cout << -1 << endl;
        delete[] a;
    }
    return 0;
}
