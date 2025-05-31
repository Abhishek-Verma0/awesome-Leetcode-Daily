class Solution {
public:
    int n;

    // helper DFS function to compute distances from  starting node
    void dfs(vector<int>& edges, int node, vector<int>& dist, vector<bool>& visited) {
        visited[node] = true;
        int v = edges[node];
        
        // continue DFS only if next node exists and hasn't been visited
        if (v != -1 && !visited[v]) {
            visited[v] = true;
            dist[v] = 1 + dist[node];  // increment distance
            dfs(edges, v, dist, visited);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();

        // distance arrays initialized to INT_MAX to represent unreachable nodes
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        // visited arrays for DFS traversal from both nodes
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        // set starting distances to 0
        dist1[node1] = 0;
        dist2[node2] = 0;

        //run DFS from both starting nodes
        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);

        int minNode = -1;
        int minDistNode = INT_MAX;

        // loop over all nodes to find the one with minimal max distance
        for (int i = 0; i < n; i++) {
            // skip if not reachable from either node
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue;

            int maxDist = max(dist1[i], dist2[i]);
            // update answer if smaller max distance found or smaller index
            if (maxDist < minDistNode) {
                minDistNode = maxDist;
                minNode = i;
            }
        }

        return minNode;
    }
};
