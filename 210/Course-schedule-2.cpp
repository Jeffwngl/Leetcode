class Solution {
private:
    vector<int>visited{};
    vector<int>res;
    bool dfs(vector<vector<int>>& graph, int vertex) {
        if (visited[vertex] == 1) return true;
        else if (visited[vertex] == 2) return false;

        visited[vertex] = 1;

        for (auto const& neighbour : graph[vertex]) {
            if (dfs(graph, neighbour)) return true;
        }
        res.push_back(vertex);
        visited[vertex] = 2;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        vector<vector<int>>graph(numCourses);
        // vector<int>res{};
        visited.resize(numCourses);

        for (int i = 0; i < n; ++i) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        // check cycles
        for (int i = 0; i < numCourses; ++i) {
            if (dfs(graph, i)) return {};
        }

        return res;

    }
};
