    1 class Solution {
    2 private:
    3 ▎   int getOnes(int n) {
    4 ▎   ▎   int cnt = 0;
    5 ▎   ▎   while (n > 0) {
    6 ▎   ▎   ▎   cnt += (n & 1);
    7 ▎   ▎   ▎   n >>= 1;
    8 ▎   ▎   }
    9 ▎   ▎   return cnt;
   10 ▎   }
   11 ▎
   12 public:
E  13 ▎   vector<int> sortByBits(vector<int>& arr) {   ■■ No template named 'vector'
   14 ▎   ▎   int n = arr.size();
   15 ▎   ▎   sort(arr.begin(), arr.end());
E  16 ▎   ▎   vector<vector<int>>res;   ■ Use of undeclared identifier 'vector'
   17 ▎   ▎
   18 ▎   ▎   for (auto it : arr) {
   19 ▎   ▎   ▎   int index = getOnes(it);
   20 ▎   ▎   ▎   if (index + 1 > res.size()) {
   21 ▎   ▎   ▎   ▎   while (res.size() < index + 1) {
   22 ▎   ▎   ▎   ▎   ▎   res.push_back({});
   23 ▎   ▎   ▎   ▎   }
   24 ▎   ▎   ▎   }
   25 ▎   ▎   ▎   res[index].push_back(it);
   26 ▎   ▎   }
   27 ▎   ▎
E  28 ▎   ▎   vector<int>ans;   ■ No template named 'vector'
   29 ▎   ▎
   30 ▎   ▎   for (auto it : res) {
   31 ▎   ▎   ▎   if (it.size() == 0) {
   32 ▎   ▎   ▎   ▎   continue;
   33 ▎   ▎   ▎   }
   34 ▎   ▎   ▎   for (int i = 0; i < it.size(); i++) {
   35 ▎   ▎   ▎   ▎   ans.push_back(it[i]);
   36 ▎   ▎   ▎   }
   37 ▎   ▎   }
   38 ▎   ▎
   39 ▎   ▎   return ans;
   40 ▎   }
   41 };
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
 Normal  Git main Diff - Diag E4 LSP +  ~/dev/leetcode/1356/Sort-integers-by-number-of-1-bits.cpp                                                                                                                                                   cpp utf-8[unix] 885B   1:1

