class Solution {
private:
    const long long MOD = 1e9 + 7;
    
public:
    int smallestBalancedIndex(vector<int>& nums) {
        vector<unsigned long long>preSum;
        vector<unsigned long long>preProd;

        int n = nums.size();

        if (n == 1) {
            return -1;
        }

        // if (n == 2)

        preSum.resize(n);
        preProd.resize(n);

        preSum[0] = nums[0];
        preProd[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; ++i) {
            preSum[i] = (preSum[i - 1] + nums[i]) % MOD;
        }

        for (int i = n - 2; i >= 0; --i) {
            preProd[i] = (preProd[i + 1] * 1ULL * nums[i]) % MOD;
            // preProd[i] = preProd[i + 1] * nums[i];
            // cout << i << " " << preProd[i] << endl;
        }

        // cout << preProd[1] << endl;

        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                // cout << i << endl;
                // cout << preProd[i + 1] << endl;
                if (preProd[i + 1] == 0) {
                    return i;
                }
                continue;
            }
            if (i == n - 1) {
                if (preSum[i - 1] == 1) {
                    return i;
                }
                break;
            }
            if (preSum[i - 1] == preProd[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};
