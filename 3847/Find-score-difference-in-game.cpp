class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int activePlayer = 1;

        int p1Points = 0;
        int p2Points = 0;
        
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 6 == 0 && i != 0) {
                if (activePlayer == 1) {
                    activePlayer = 2;
                } 
                else {
                    activePlayer = 1;
                }
            }
            if (nums[i] % 2 != 0) {
                // cout << i << " " << activePlayer << endl;
                if (activePlayer == 1) {
                    activePlayer = 2;
                } 
                else {
                    activePlayer = 1;
                }
            }
            if (activePlayer == 1) {
                p1Points += nums[i];
            }
            else {
                p2Points += nums[i];
            }
        }
        // cout << p1Points << " " << p2Points << endl;
        return (p1Points - p2Points);
    }
};
