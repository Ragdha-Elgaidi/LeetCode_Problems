class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        // Initialize an array to store the number of ways to climb to each step.
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        // Calculate the number of ways for each step using dynamic programming.
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
