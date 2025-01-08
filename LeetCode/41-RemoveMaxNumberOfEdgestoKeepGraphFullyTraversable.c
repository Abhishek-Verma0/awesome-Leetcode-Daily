/*1579. Remove Max Number of Edges to Keep Graph Fully Traversable
Hard
Topics
Companies
Hint

Alice and Bob have an undirected graph of n nodes and three types of edges:

    Type 1: Can be traversed by Alice only.
    Type 2: Can be traversed by Bob only.
    Type 3: Can be traversed by both Alice and Bob.

Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

Example 1:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.

Example 2:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.

Example 3:

Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.

 

 

Constraints:

    1 <= n <= 105
    1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
    edges[i].length == 3
    1 <= typei <= 3
    1 <= ui < vi <= n
    All tuples (typei, ui, vi) are distinct.

*/







struct DSU {
    int *parent;
    int *rank;
    int root_cnt;
};
struct DSU *init_dsu(int n)
{
    struct DSU *dsu = malloc(sizeof(struct DSU));
    dsu->parent = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        dsu->parent[i] = i;
    dsu->rank = calloc(n, sizeof(int));
    dsu->root_cnt = n;
    return dsu;
}
void release_dsu(struct DSU *dsu)
{
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
    return;
}
int find_parent(struct DSU *dsu, int x)
{
    if (dsu->parent[x] != x)
        dsu->parent[x] = find_parent(dsu, dsu->parent[x]);
    return dsu->parent[x];
}
bool make_union(struct DSU *dsu, int x, int y)
{
    int px = find_parent(dsu, x);
    int py = find_parent(dsu, y);

    if (px == py)
        return false;
    
    if (dsu->rank[px] >= dsu->rank[py]) {
        dsu->rank[px] += dsu->rank[py];
        dsu->parent[py] = px;
    } else {
        dsu->rank[py] += dsu->rank[px];
        dsu->parent[px] = py;
    }
    dsu->root_cnt--;
    return true;
}
int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) 
{
    struct DSU *dsu_alice = init_dsu(n);
    struct DSU *dsu_bob = init_dsu(n);
    int edge_cnt = 0;
    int etype, u, v;

    for (int i = 0; i < edgesSize; i++) {
        etype = edges[i][0];
        u = edges[i][1];
        v = edges[i][2];
        if (etype == 3)
            edge_cnt += make_union(dsu_alice, u - 1, v - 1) | make_union(dsu_bob, u - 1, v - 1);
    }
    for (int i = 0; i < edgesSize; i++) {
        etype = edges[i][0];
        u = edges[i][1];
        v = edges[i][2];
        if (etype == 1)
            edge_cnt += make_union(dsu_alice, u - 1, v - 1);
        else if (etype == 2)
            edge_cnt += make_union(dsu_bob, u - 1, v - 1);
    }
    int res = (dsu_alice->root_cnt == 1 && dsu_bob->root_cnt == 1) ? edgesSize - edge_cnt : -1;
    release_dsu(dsu_alice);
    release_dsu(dsu_bob);
    return res;
}