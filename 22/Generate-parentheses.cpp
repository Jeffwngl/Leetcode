class Solution {
private:
    vector<string>res;
    void parGen(string& curr, int n, int l_cnt, int r_cnt) {
        if (curr.size() > 2 * n || r_cnt > l_cnt) {
            return;
        }
        if (curr.size() == 2 * n && l_cnt == r_cnt && l_cnt != 0) {
            // cout << "r: " << r_cnt << " " << "l: " << l_cnt << endl;
            res.push_back(curr);
            return;
        }

        if (l_cnt < n) {
            curr += '(';
            parGen(curr, n, l_cnt + 1, r_cnt);
            curr.pop_back();
        }

        cout << curr << endl;
        cout << "r: " << r_cnt << " " << "l: " << l_cnt << endl;

        if (r_cnt < n) {
            curr += ')';
            parGen(curr, n, l_cnt, r_cnt + 1);
        }

        curr.pop_back();
        //l_cnt+;
    } 

public:
    vector<string> generateParenthesis(int n) {
        string curr;

        parGen(curr, n, 0, 0);
        
        return res;
    }
};
