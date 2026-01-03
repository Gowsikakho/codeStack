#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// -------------------------------------------------------------
// BFS: Check if we can reach node n from node 1 using ≤ k steps,
//      but only using edges whose weight ≤ limit
// -------------------------------------------------------------
bool canReach(int n, vector<vector<pair<int,int>>> &adj, int k, int limit) {

    queue<int> q;
    vector<int> dist(n + 1, INT_MAX);

    dist[1] = 0;
    q.push(1);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(dist[u] > k) continue;

        for(auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            // Only use edges with weight ≤ limit
            if(w <= limit && dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[n] <= k;
}

// -------------------------------------------------------------
// Binary Search on weight limit
// -------------------------------------------------------------
int getMinRepairCost(int g_nodes, vi &g_from, vi &g_to, vi &g_weight, int k) {

    int m = g_from.size();
    vector<vector<pair<int,int>>> adj(g_nodes + 1);

    // Build undirected graph
    for (int i = 0; i < m; i++) {
        adj[g_from[i]].push_back({g_to[i], g_weight[i]});
        adj[g_to[i]].push_back({g_from[i], g_weight[i]});
    }

    int lo = 0;
    int hi = *max_element(g_weight.begin(), g_weight.end());
    int ans = -1;

    // Binary search on the maximum allowed weight limit
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (canReach(g_nodes, adj, k, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;

    vector<int> g_from(g_edges), g_to(g_edges), g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) cin >> g_from[i];
    for (int i = 0; i < g_edges; i++) cin >> g_to[i];
    for (int i = 0; i < g_edges; i++) cin >> g_weight[i];

    int k;
    cin >> k;

    cout << getMinRepairCost(g_nodes, g_from, g_to, g_weight, k) << "\n";

    return 0;
}
