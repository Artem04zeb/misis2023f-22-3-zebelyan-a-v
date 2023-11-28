#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 0;
    string word;
    cin >> word;
    for (char c : word) {
        if (islower(c))
            n++;
        else n--;
    }
    for (char c : word) {
        if (n >= 0)
            cout << (char)tolower(c);
        else cout << (char)toupper(c);
    }
}