class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n1 = s.size();
        int n2 = t.size();

        if (n1 < n2)
            return "";
        unordered_map<char, int> mp, mps;

        for (char c : t)
        {
            mp[c]++;
        }

        int l = 0;
        int count = 0, start = 0;
        int mini = INT_MAX;

        for (int r = 0; r < n1; r++)
        {
            char c = s[r];
            mps[c]++;

            if (mp.find(c) != mp.end() && mps[c] == mp[c])
            {
                count++;
            }

            while (count == mp.size())
            { // mp.size return size for unique chars
                if (r - l + 1 < mini)
                {
                    mini = r - l + 1;
                    start = l;
                }

                char lc = s[l];
                mps[lc]--;

                if (mp.count(lc) && mps[lc] < mp[lc])
                {
                    count--;
                }
                l++;
            }
        }
        return (mini == INT_MAX) ? "" : s.substr(start, mini);
    }
};