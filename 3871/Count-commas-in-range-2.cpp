class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) {
            return 0;
        }

        else if (n <= 100000) {
            return (n - 1000 + 1);
        }
        
        long long lowerLimit = 1000;
        int cnt = 1;
        long long res = 0;
        
        while (lowerLimit <= n) {
            long long upperLimit = lowerLimit * 1000 - 1; // e.g. 999,999
            upperLimit = min(n, upperLimit);

            res += (upperLimit - lowerLimit + 1) * cnt; // e.g. 999,999 - 1,000 + 1 (+1 to account for extra comma)

            lowerLimit *= 1000;
            cnt++;
        }

        return res;
    }
};
