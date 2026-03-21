class Solution {
private:
    bool backTrack(int i, int j, int k, string const& s1, string const& s2, string const& s3) {
        if (k == s3.size()) {
            return (i == s1.size() && j == s2.size());
        }

        if (i < s1.size() && s1[i] == s3[k]) {
            if (backTrack(i + 1, j, k + 1, s1, s2, s3)) {
                return true;
            }
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            if (backTrack(i, j + 1, k + 1, s1, s2, s3)) {
                return true;
            }
        }

        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        return backTrack(0, 0, 0, s1, s2, s3);   
    }
};
