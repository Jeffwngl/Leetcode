class Solution {
public:
    bool checkCycle(vector<int>::iterator begin, vector<int>::iterator end) {
        int n = end - begin;
        int inv = 0;
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            if (*(begin + i) > *(begin + next)) inv++;
        }
        return inv <= 1;
    }
    
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int>divisibles;
        int res = 0;
        
        for (int i = 1; i <= n; ++i) {
             if (n % i == 0) divisibles.push_back(i);   
        }

        for (int i = 0; i < divisibles.size(); ++i) {
            bool valid = true;
            int mn = 0;
            for (int j = 0; j < n; j += divisibles[i]) {
                if (checkCycle(nums.begin() + j, nums.begin() + j + divisibles[i])) {
                    int mx = *min_element(nums.begin() + j, nums.begin() + j + divisibles[i]);
                
                    if (mx < mn) {
                        valid = false;
                    }
                    mn = *max_element(nums.begin() + j, nums.begin() + j + divisibles[i]);
                } else {
                    valid = false;
                }
            }
            if (valid) {
                res += divisibles[i];
            }
        }
        return res;
    }
};
