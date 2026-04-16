class Solution {
private:
    int find(int n, vector<int>& parents) {
        if (parents[n - 1] <= -1 && parents[n - 1] >= -parents.size()) return n;
        return find(parents[n - 1], parents);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // use DSU to check cycle
        int e = edges.size();
        vector<int>parents(e, -1);

        for (int i = 0; i < e; ++i) {
            int u = edges[i][0], v = edges[i][1];
            int parent1 = find(u, parents);
            int parent2 = find(v, parents);
            if (parent1 == parent2) { // cycle found, node indexes equal
                return {u, v};
            }

            if (parents[parent1 - 1] <= parents[parent2 - 1]) { // parent1 set is bigger than parent2 set (union)
                parents[parent1 - 1] += parents[parent2 - 1]; // increase size of parent (-)
                parents[parent2 - 1] = parent1;
            }
            else {
                parents[parent2 - 1] += parents[parent1 - 1];
                parents[parent1 - 1] = parent2;
            }
        }
        return {};
    }
};
