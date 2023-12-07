#include <iostream>
#include <vector>

using namespace std;

int n, ind;

vector<int> a, vis;

void solve() {
    cin >> n; ind = 0;
    a.resize(2 * n);
    vis.resize(n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        vis[i % n] = 0;
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (!vis[a[i] - 1]) {
            cout << a[i] << ' ';
            ind++;
            vis[a[i] - 1] = 1;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}