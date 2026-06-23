

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;

    vector<long long> machines(n);

    long long mn = LLONG_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> machines[i];
        mn = min(mn, machines[i]);
    }

    long long l = 1;
    long long r = mn * t;
    long long ans = r;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;

        long long products = 0;

        for (auto x : machines)
        {
            products += mid / x;

            if (products >= t)
                break;
        }

        if (products >= t)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
}