class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }

        int maxLeft = height[0];
        int maxRight = height[n - 1];

        int l = 1, r = n - 2;
        int res = 0;

        while (l <= r) {
            if (maxLeft < maxRight) {
                if (height[l] > maxLeft) {
                    maxLeft = height[l];
                }
                else {
                    res += maxLeft - height[l];
                }
                l++;
            }
            else {
                if (height[r] > maxRight) {
                    maxRight = height[r];
                }
                else {
                    res += maxRight - height[r];
                }
                r--;
            }
        }
        return res;
    }
};

// If maxLeft < maxRight, it means the water level is based on the left side (the left bar is smaller) then move left side, Else if maxLeft > maxRight, it means the water level is based on the right side (the right bar is smaller) then move right side.

// The condition guarantees the side we process is limited by its own max. If we don't we will overcount the water.
