//O(m*n) function calls and o(m*n) space complexity

int findUniquePaths(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
        return 1;

    int down =
        (dp[i - 1][j] >= 0) ? dp[i - 1][j] : findUniquePaths(i - 1, j, dp);
    int right =
        (dp[i][j - 1] >= 0) ? dp[i][j - 1] : findUniquePaths(i, j - 1, dp);

    return (dp[i][j] = (right + down));
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return findUniquePaths(m - 1, n - 1, dp);
}