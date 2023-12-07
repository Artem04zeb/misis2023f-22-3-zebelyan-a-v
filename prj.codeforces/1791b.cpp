#include <iostream>
#include <string>
using namespace std;

int main() {
    bool flag = true;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') x--;
            else if (s[i] == 'R') x++;
            else if (s[i] == 'U') y++;
            else y--;

            if (x == 1 && y == 1) {
                cout << "YES" << endl;
                flag = false;
                break;
            }

        }

        if (flag == true)
            cout << "NO" << endl;
        else if (flag == false) {
            flag = true;

        }



    }
}

