class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k = tasks.size();
        vector<int>freq(26);
        priority_queue<int>pq;
        queue<pair<int, int>>q;

        for (int i = 0; i < k; ++i) ++freq[tasks[i] - 'A'];

        for (auto it : freq) if (it != 0) pq.push(it);

        int currTime = 0;

        /**
        * pq stores the maxHeap of remaining tasks counts that are currently available
        * q stores tasks that are on cooldown
        */

        while (!pq.empty() || !q.empty()) {
            currTime++;
            // if no tasks are available, we go to the time of next one that is
            if (pq.empty()) currTime = q.front().second;
            else { // next task is available
                int c = pq.top();
                pq.pop();
                if (c > 1) q.push({c - 1, currTime + n}); // if not empty, keep it on the q for next refresh
            }

            if (!q.empty() && q.front().second == currTime) { // check if items from q comes down cooldown
                pq.push(q.front().first);
                q.pop();
            }
        }
        return currTime;
    }
};
