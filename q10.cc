class Solution
{
public:
    bool valid(vector<int> &position, int force, int m)
    {
        int n = position.size();
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        for (int i = 1; i < n && ballsPlaced < m; i++)
        {
            int currPos = position[i];

            if (currPos - prevBallPos >= force)
            {
                ballsPlaced += 1;
                prevBallPos = currPos;
            }
        }
        return ballsPlaced == m;
    }

    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 1, r = position[n - 1];
        int ans = r;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (valid(position, mid, m))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};