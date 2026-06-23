class Solution
{
public:
    void generateSum(vector<int> &arr, vector<int> &sum)
    {
        int n = arr.size();
        for (int mask = 0; mask < (1 << n); mask++)
        {
            int total = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                    total += arr[i];
            }
            sum.push_back(total);
        }
    }

    int minAbsDifference(vector<int> &nums, int goal)
    {
        int n = nums.size();
        vector<int> left;
        vector<int> right;

        for (int i = 0; i < n / 2; i++)
            left.push_back(nums[i]);
        for (int i = n / 2; i < n; i++)
            right.push_back(nums[i]);

        vector<int> leftSum, rightSum;
        generateSum(left, leftSum);
        generateSum(right, rightSum);

        sort(rightSum.begin(), rightSum.end());

        int ans = INT_MAX;
        for (int i = 0; i < leftSum.size(); i++)
        {
            int curr = leftSum[i];
            int need = goal - curr;

            auto it = lower_bound(rightSum.begin(), rightSum.end(), need);
            if (it != rightSum.end())
                ans = min(ans, abs(goal - (curr + *it)));
            if (it != rightSum.begin())
            {
                it--;
                ans = min(ans, abs(goal - (curr + *it)));
            }
        }

        return ans;
    }
};