class Solution {
private:
    const long long MOD = 1e9 + 7;

    long long modInverse(long long a, long long mod) {
        // a^(mod-2) % mod
        long long result = 1;
        long long power = mod - 2;
        while (power > 0) {
            if (power & 1) result = result * a % mod;
            a = a * a % mod;
            power >>= 1;
        }
        return result;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // q1 is for the queries we cannot brute force
        // q2 is for the queries we can brute force
        vector<vector<int>>q1{};
        vector<vector<int>>q2{};
        for (auto& q : queries) {
            int k = q[2];
            if (k < sqrt(n)) {
                q1.push_back(q);
            }
            else q2.push_back(q);
        }

        // calculate brute force ones like normal
        for (auto& q : q2) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            int idx = l;
            while (idx <= r) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
                idx += k;
            }
        }

        // group by [k, l%k]
        // [k, l%k] -> {prefix products}
        map<pair<int, int>, vector<long long>>mp;

        for (auto& q : q1) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            int rem = l % k;
            int start = l / k; // start of l in curr group
            // int end = r / k; // end of l in curr group

            int groupSize = (n - rem + k - 1) / k; // from rem to n - 1, how many multiples of k fit

            if (mp.find({k, rem}) == mp.end()) {
                mp[{k, rem}] = vector<long long>(groupSize + 1, 1); // need r + 1 for when it finishes and sets to v^-1
            }

            //int end = min(r / k, groupSize - 1);
            int end = min((r - rem) / k, groupSize - 1);

            mp[{k, rem}][start] = mp[{k, rem}][start] * v % MOD; 
            mp[{k, rem}][end + 1] = mp[{k, rem}][end + 1] * modInverse(v, MOD) % MOD;// inverse of it so when * v % MOD is done, it gives 0
        }
        // done before calculating prefix product [a, 1, 1, a^-1 ...]

        vector<long long>preProd(n, 1);

        for (auto& [key, arr] : mp) {
            auto [k, rem] = key;
            long long curr = 1;
            for (int i = 0; i < arr.size() - 1; ++i) {
                curr = curr * arr[i] % MOD;
                // get index in original nums array
                int originalIndex = rem + i * k; // rem = offset, i * k = intervals for the current k
                preProd[originalIndex] = preProd[originalIndex] * curr % MOD;
            }
        }

        // multiplication is commutative so we can separate into q1 and q2
        for (int i = 0; i < n; ++i) {
            nums[i] = (1LL * nums[i] * preProd[i]) % MOD;
        }

        long long res = 0;

        for (auto& it : nums) {
            res ^= it;
        }

        return res;
    }
};
