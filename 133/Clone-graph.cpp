/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(unordered_map<Node*, Node*>& idToNode, Node* n) {
        // construct graph first
        if (n == nullptr) {
            return;
        }
        auto newNode = new Node(n->val);
        idToNode.insert({n, newNode});

        for (auto const& neighbor : n->neighbors) {
            if (idToNode.contains(neighbor)) {
                continue;
            }
            dfs(idToNode, neighbor);
        }
        return;
    };

    void createGraph(unordered_map<Node*, Node*>& idToNode, Node* n, unordered_set<Node*>& visited) {
        if (n == nullptr) {
            return;
        }
        visited.insert(idToNode[n]);

        for (auto const& neighbor : n->neighbors) {
            idToNode[n]->neighbors.push_back(idToNode[neighbor]);
            if (visited.contains(idToNode[neighbor])) {
                continue;
            }
            createGraph(idToNode, neighbor, visited);
        };
    }

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*>idToNode;
        unordered_set<Node*>visited;

        dfs(idToNode, node);
        createGraph(idToNode, node, visited);
        return idToNode[node];
    }
};
