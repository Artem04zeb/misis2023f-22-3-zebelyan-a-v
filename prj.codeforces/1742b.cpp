#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int * arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int p = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                cout << "NO" << endl;
                p = 1;
                break;
            }
        }
        delete[] arr;
        if (p == 0) {
            cout << "YES" << endl;
        }



    }

    return 0;
}