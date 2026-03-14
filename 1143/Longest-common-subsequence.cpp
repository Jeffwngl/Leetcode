class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

        for (size_t i = 1; i < n + 1; ++i) {
            for (size_t j = 1; j < m + 1; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // both characters equal so move both characters next 1 index
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};

// Editorial
// dp[i][j] = length of the LCS between text1[0..i-1] and text2[0..j-1]
// So dp[i][j] is the best subsequence we can build using the first i characters of text1 and the first j characters of text2.
// If they are equal, we have to append both of them to the current LCS, so we move on from [i - 1], [j - 1] to [i], [j] and add 1 to the next grid
//
// At some point when text1[i-1] != text2[j-1], They cannot both be in the subsequence so we discard one of them.
// We choose what one to keep based on if they maximise the value or not.
// If the first characters in the current iteration, i - 1, and j - 1 are not equal we cant go diagonally, we can only go right or down
// Those are guaranteed to be filled before we compute dp[i][j] because:
// i-1 row has already been processed
// j-1 column in current row has already been processed
//       "" a c
//    "" 0 0 0
// a     0 ? ?
// b     0 ? ?
// c     0 ? ?
// dp[1][1] → depends on dp[0][0], dp[0][1], dp[1][0] → all already 0
// dp[1][2] → depends on dp[0][1], dp[0][2], dp[1][1] → dp[1][1] was just computed
// dp[2][1] → depends on dp[1][0], dp[1][1], dp[2][0] → all ready
