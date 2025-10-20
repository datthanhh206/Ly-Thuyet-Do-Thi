#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    if (!(cin >> m)) return 0;

    // We'll allow vertices numbered up to, say, 10000 (tăng nếu cần)
    const int MAXV = 10005;
    // We'll discover max vertex value from input to shrink loops
    vector<pair<int, int>> edges; edges.reserve(m + 1);
    int u, v;
    int maxv = 0;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        edges.push_back({ u, v });
        if (u > maxv) maxv = u;
        if (v > maxv) maxv = v;
    }

    int V = maxv + 1;
    vector<vector<pair<int, int>>> adj(V); // (neighbor, edge_id)
    vector<int> deg(V, 0);

    for (int i = 0; i < m; ++i) {
        u = edges[i].first;
        v = edges[i].second;
        adj[u].push_back({ v, i });
        adj[v].push_back({ u, i });
        deg[u]++; deg[v]++;
    }

    // Check all vertices with degree>0 are in one connected component
    int start = -1;
    for (int i = 0; i < V; ++i) if (deg[i] > 0) { start = i; break; }
    if (start == -1) {
        // no edges: depending đề, treat as Euler (empty). We'll print 1 and nothing else.
        cout << 1 << '\n';
        return 0;
    }

    // connectivity DFS (on underlying undirected graph)
    vector<char> seen(V, 0);
    stack<int> stc;
    stc.push(start);
    seen[start] = 1;
    while (!stc.empty()) {
        int x = stc.top(); stc.pop();
        for (auto& p : adj[x]) {
            int nb = p.first;
            if (!seen[nb]) { seen[nb] = 1; stc.push(nb); }
        }
    }
    for (int i = 0; i < V; ++i) {
        if (deg[i] > 0 && !seen[i]) {
            cout << 0 << '\n';
            return 0;
        }
    }

    // Check all degrees even
    for (int i = 0; i < V; ++i) if (deg[i] % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    // Hierholzer: iterative using stack, track used edges
    vector<char> usedEdge(m, 0);
    vector<int> edgePos(V, 0); // next edge index to try for each vertex
    vector<int> vertexStack;
    vector<int> circuitVertices; // will hold vertices in order (length = m+1)

    vertexStack.push_back(start);
    while (!vertexStack.empty()) {
        int vcur = vertexStack.back();
        // find next unused edge from vcur
        while (edgePos[vcur] < (int)adj[vcur].size() && usedEdge[adj[vcur][edgePos[vcur]].second]) {
            edgePos[vcur]++;
        }
        if (edgePos[vcur] == (int)adj[vcur].size()) {
            // no more edges -> add to circuit
            circuitVertices.push_back(vcur);
            vertexStack.pop_back();
        }
        else {
            auto pr = adj[vcur][edgePos[vcur]];
            int nxt = pr.first;
            int eid = pr.second;
            usedEdge[eid] = 1;
            vertexStack.push_back(nxt);
            // advance edgePos[vcur] (next time skip this edge)
            edgePos[vcur]++;
        }
    }

    // circuitVertices should have length m+1
    if ((int)circuitVertices.size() != m + 1) {
        cout << 0 << '\n';
        return 0;
    }

    // Print result: 1 then each consecutive pair as an edge in the traversal
    cout << 1 << '\n';
    for (int i = 0; i + 1 < (int)circuitVertices.size(); ++i) {
        cout << circuitVertices[i] << " " << circuitVertices[i + 1] << '\n';
    }

    return 0;
}
