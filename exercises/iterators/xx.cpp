class Solution
{
public:
    int maxCount = 0;
    std::vector<std::string> longest;
    short dp[1001][1001] = {};
    int longestCommonSubsequence(string &a, string &b)
    {
        for (auto i = 0; i < a.size(); ++i)
            for (auto j = 0; j < b.size(); ++j)
                dp[i + 1][j + 1] = a[i] == b[j] ? dp[i][j] + 1 : max(dp[i + 1][j], dp[i][j + 1]);
        return dp[a.size()][b.size()];
    }
    void solve(int i, int j, int n, std::vector<std::string> &words, std::vector<int> &groups, vector<string> &curr)
    {
        if (i == words.size())
        {
            if (maxCount < curr.size())
            {
                longest = curr;
                maxCount = curr.size();
            }
        }
        else
        {
            if (j == -1 || (i < n && groups[j] != groups[i] &&
                                        words[j].length() == words[i].length() &&
                                        longestCommonSubsequence(words[j], words[i]) == words[j].length() - 1))
            {
                curr.push_back(words[i]);
                solve(i + 1, i, n, words, groups, curr);
                curr.pop_back();
            }
            solve(i + 1, j, n, words, groups, curr);
        }
    }

    std::vector<std::string> getWordsInlongest(int n, std::vector<std::string> &words, std::vector<int> &groups)
    {
        std::vector<std::string> curr;
        solve(0, -1, n, words, groups, curr);
        return longest;
    }
};