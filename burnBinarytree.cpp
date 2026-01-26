class Solution {
public:
    int minTime(TreeNode* root, TreeNode* target) {
        // Step 1: Build graph (tree -> undirected graph)
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (node->left) {
                graph[node].push_back(node->left);
                graph[node->left].push_back(node);
                q.push(node->left);
            }

            if (node->right) {
                graph[node].push_back(node->right);
                graph[node->right].push_back(node);
                q.push(node->right);
            }
        }

        // Step 2: BFS from target
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> bfs;
        bfs.push(target);
        visited.insert(target);

        int time = -1;

        while (!bfs.empty()) {
            int sz = bfs.size();
            time++;  // each level = 1 time unit

            for (int i = 0; i < sz; i++) {
                TreeNode* node = bfs.front(); bfs.pop();

                for (TreeNode* nei : graph[node]) {
                    if (!visited.count(nei)) {
                        visited.insert(nei);
                        bfs.push(nei);
                    }
                }
            }
        }

        return time;
    }
};
