#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> freq(101, 0);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    auto possible = [&](int days)
    {
        int people = 0;

        for (int f : freq)
            people += f / days;

        return people >= n;
    };

    int l = 1, r = m;
    int ans = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (possible(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}