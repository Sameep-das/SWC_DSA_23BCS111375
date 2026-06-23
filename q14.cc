class Solution
{
public:
    vector<int> getNse(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n + 1, n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                nse[i] = st.top();
            }

            st.push(i);
        }
        return nse;
    }

    vector<int> getPse(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n + 1, -1);

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                pse[i] = st.top();
            }

            st.push(i);
        }
        return pse;
    }

    int longestHistogram(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> nse = getNse(arr);
        vector<int> pse = getPse(arr);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int width = nse[i] - pse[i] - 1;

            ans = max(ans, width * arr[i]);
        }

        return ans;
    }

    int maxArea(vector<vector<int>> &mat)
    {
        // code here

        int n = mat.size();
        int m = mat[0].size();

        // pref array that holds histogram length for each row
        vector<vector<int>> pref(n, vector<int>(m, 0));

        for (int col = 0; col < m; col++)
        { // column
            int sum = 0;
            for (int row = 0; row < n; row++)
            { // row :: since we want the size of largest histogram for everu row
                sum += mat[row][col];

                if (mat[row][col] == 0)
                    sum = 0;

                pref[row][col] = sum;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, longestHistogram(pref[i]));
        }
        return ans;
    }
};