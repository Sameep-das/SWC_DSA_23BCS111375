#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s)
{
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words(n);

    for (int i = 0; i < n; i++)
        cin >> words[i];

    string ans = words[0];

    for (int i = 1; i < n; i++)
    {
        string &cur = words[i];

        int len = min((int)ans.size(), (int)cur.size());

        string suffix = ans.substr(ans.size() - len);

        string temp = cur + "#" + suffix;

        vector<int> pi = prefix_function(temp);

        int overlap = pi.back();

        ans += cur.substr(overlap);
    }

    cout << ans << '\n';

    return 0;
}