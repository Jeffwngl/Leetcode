class Solution {
private:
    vector<int>visited{};
    bool dfs(vector<vector<int>>& graph, int vertex) {
        if (visited[vertex] == 1) return true;
        if (visited[vertex] == 2) return false;

        visited[vertex] = 1; // visiting
        // visited[0] = 1 (were visiting 0)
        // Go to neighbor 1 → visited[1] = 1
        // Go to neighbor 2 → visited[2] = 1
        // Go to neighbor 0 → visited[0] == 1 cycle detected
        // Am I revisiting a node that is currently being explored in this path

        for (auto const& neighbour : graph[vertex]) {
            if (dfs(graph, neighbour)) return true;
        }

        visited[vertex] = 2; // visited
        // this doesn't matter in the current iteration, 
        // Later, if some other node’s DFS reaches this node again:
        // visited[node] == 2 → we skip it, because it’s already safe (no cycles along its paths).
        // nodes with 2 means that they are on a path that doesn't form a cycle.
        // at the end of a whole dfs() call, if no cycle is detected, all nodes in visited are 2
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        vector<vector<int>>g(numCourses);
        visited.resize(numCourses);

        for (int i = 0; i < n; ++i) {
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < g.size(); ++i) {
            if (dfs(g, i)) return false;
        }
        
        return true;
    }
};
