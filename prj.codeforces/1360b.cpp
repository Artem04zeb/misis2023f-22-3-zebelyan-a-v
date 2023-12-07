#include <iostream>
using namespace std;
typedef long long ll;

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

void insertion_sort(ll* arr, ll l, ll r)
{
    for (ll i = l; i <= r; i++)
    {
        ll key = arr[i];
        ll j = i - 1;
        while (j >= l && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(ll* arr, ll l, ll mid, ll r)
{
    ll left_len = mid - l + 1;
    ll right_len = r - mid;
    auto left = new ll[left_len];
    auto right = new ll[right_len];
    for (ll i = l; i <= mid; i++)
        left[i - l] = arr[i];
    for (ll i = mid + 1; i <= r; i++)
        right[i - mid - 1] = arr[i];
    ll arr_idx = l, left_idx = 0, right_idx = 0;
    while (left_idx < (mid - l + 1) && right_idx < (r - mid))
    {
        if (left[left_idx] < right[right_idx])
        {
            arr[arr_idx] = left[left_idx];
            left_idx++;
        }
        else
        {
            arr[arr_idx] = right[right_idx];
            right_idx++;
        }
        arr_idx++;
    }
    while (left_idx < (mid - l + 1))
    {
        arr[arr_idx] = left[left_idx];
        left_idx++;
        arr_idx++;
    }
    while (right_idx < (r - mid))
    {
        arr[arr_idx] = right[right_idx];
        right_idx++;
        arr_idx++;
    }
    delete[] left;
    delete[] right;
}

void tim_sort(ll* arr, ll l, ll r)
{
    ll run = 32;
    ll len = r - l + 1;
    for (ll i = l; i <= r; i += run)
    {
        insertion_sort(arr, i, min(i + run - 1, r));
    }
    for (ll siz = run; siz < len; siz = 2 * siz)
    {
        for (ll left = l; left <= r; left += 2 * siz)
        {
            ll mid = left + siz - 1;
            ll right = min(left + 2 * siz - 1, r);
            if (mid < right)
            {
                merge(arr, left, mid, right);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll* arr = new ll[n + 5];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        tim_sort(arr, 0, n - 1);
        ll ans = 1000;
        for (ll i = 1; i < n; i++)
        {
            ans = min(ans, abs(arr[i - 1] - arr[i]));
        }
        cout << ans << endl;
        delete[] arr;
    }
    return 0;
}