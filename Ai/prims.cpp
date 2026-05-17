#include <bits/stdc++.h>
using namespace std;

void primsMST(int V, vector<vector<pair<int,int>>>& adj) {
    
    // {weight, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    // Start from node 0
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;

        // Traverse neighbors
        for (auto &it : adj[u]) {
            int v = it.first;
            int wt = it.second;

            // If v not in MST and weight is smaller
            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;

                pq.push({key[v], v});
            }
        }
    }

    int totalWeight = 0;

    cout << "Edges in MST:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << "  weight: " << key[i] << endl;

        totalWeight += key[i];
    }

    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {

    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    // u -- v , weight

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    primsMST(V, adj);

    return 0;
}