class Solution {
private:
    struct Robot {
        int m_o_index;
        int m_pos;
        int m_health;
        char m_dir;
    };

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<Robot>curr;

        int n = positions.size();
        if (n == 1) {
            return {healths[0]};
        }

        vector<Robot>v;

        for (int i = 0; i < n; ++i) {
            Robot robot {i, positions[i], healths[i], directions[i]};
            v.push_back(robot);
        }

        sort(v.begin(), v.end(), [](Robot &a, Robot &b) {
            return a.m_pos < b.m_pos;
        });

        vector<Robot>survived;

        for (int i = 0; i < n; ++i) {
            if (v[i].m_dir == 'R') {
                curr.push(v[i]);
            }
            else if (v[i].m_dir == 'L') {
                Robot r2 = v[i];
                while (!curr.empty()) {
                    Robot r1 = curr.top();
                    curr.pop();

                    if (r1.m_health > r2.m_health) {
                        r1.m_health -= 1;
                        curr.push(r1);
                        r2.m_health = 0;
                        break;
                    }
                    else if (r2.m_health > r1.m_health) {
                        r2.m_health -= 1;
                    }
                    else {
                        r2.m_health = 0;
                        break;
                    }
                }
                if (r2.m_health > 0) {
                    survived.push_back(r2);
                }
            }
        }

        while (!curr.empty()) {
            Robot r = curr.top();
            curr.pop();
            survived.push_back(r);
        }

        sort(survived.begin(), survived.end(), [](Robot &a, Robot &b) {
            return a.m_o_index < b.m_o_index;
        });

        vector<int>res;
        for (auto& r : survived) res.push_back(r.m_health);
        return res;
    }
};
