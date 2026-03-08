class Solution {
private:
    long long findMin(int l, int r, vector<int>&preSum, int flatCost, int encCost) {
        long long cost;
        int length = r - l + 1;
        if (preSum[r + 1] - preSum[l] == 0) {
            cost = flatCost;
        }
        else {cost = 1LL * encCost * length * (preSum[r + 1] - preSum[l]);}
        
        if (length % 2 == 0) {
            int mid = (l + r) / 2;
            cost = min(cost, findMin(l, mid, preSum, flatCost, encCost) + findMin(mid + 1, r, preSum, flatCost, encCost));
        }
        return cost;
    }

public:
    long long minCost(string s, int encCost, int flatCost) {

        int n = s.size();

        vector<int>preSum;
        preSum.resize(n + 1);
        preSum[0] = 0;

        for (int i = 1; i < n + 1; ++i) {
            preSum[i] = preSum[i - 1] + (s[i - 1] - '0');
        }
        // preSum[n] = preSum[n - 1] + preSum[0];

        return findMin(0, n - 1, preSum, flatCost, encCost);
    }
};
