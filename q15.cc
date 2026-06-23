class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        int n = points.size();
        int ans = INT_MIN;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n && abs(points[i][0] - points[j][0]) <= k; j++)
            {
                int sum = points[i][1] + points[j][1] + abs(points[i][0] - points[j][0]);
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};