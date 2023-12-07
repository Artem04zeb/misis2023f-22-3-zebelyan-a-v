#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    string n;
    cin >> n;
    int conscnt = 0;
    int removecnt = 0;
    for (int i = 0; i < t; i++) {
        if (n[i] == 'x') {
            conscnt++;
            if (conscnt >= 3) {
                removecnt++;
            }
        }
        else {
            conscnt = 0;
        }
    }
    cout << removecnt << endl;
    return 0;
}