// Topological sort + dp based solution
// note that this algo will work for negative edges as well (power of dp)
// time : O(V + E)
// auxilary space : O(V + E)
//https://www.naukri.com/code360/problems/shortest-path-in-dag_8381897

#define pb push_back
#define fi first
#define se second

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges){
    vector <int> dis(n, INT_MAX);
    dis[0] = 0;
    vector <vector <pair <int,int> >> in_edges(n);  // space O(V + E)
    vector <vector <int> > out_edges(n);                // space O(V + E)
    vector <int> in_degree(n, 0);                            // space O(V)
    for(auto ele: edges){
        in_degree[ele[1]]++;
        in_edges[ele[1]].pb({ele[0], ele[2]});
        out_edges[ele[0]].pb(ele[1]);
    }
    vector <int> topo;
    for(int u  = 0; u < n; u++) if(in_degree[u] == 0) topo.pb(u);
    int i = 0;
    while(i < n){
        int u = topo[i++];
        for(auto p: in_edges[u]){
            int v = p.fi;
            int w = p.se;
            // edge is v -> u
            if(dis[v] != INT_MAX) dis[u] = min(dis[u], dis[v] + w);
        }
        for(auto v: out_edges[u]){
            // edge is u -> v
            in_degree[v]--;
            if(in_degree[v] == 0) topo.pb(v);
        }
    }
    for(int u = 0; u < n; u++) if(dis[u] == INT_MAX) dis[u] = -1;
    return dis;
}
