#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; // number of vertices, number of edges
    cin >> n >> m;

    vector <vector<pair<int, int>>> adj(1+n);
    for(int i = 1; i <= m; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back(make_pair(v2, w));
        adj[v2].push_back(make_pair(v1, w));
    }
    int s;
    cin >> s; // source vertex

    vector <int> parent(1+n, -1);
    vector <int> dis(1+n, INT_MAX);
    priority_queue <int, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, s));
    dis[s] = 0;
    int c = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto p: adj[u]){
            int v = p.first;
            int w = p.second;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                parent[v] = u;
                pq.push(make_pair(dis[u]+w, v));
            }
        }
    }

    for(int i = 0; i <= n; i++){
        cout << "Vertex: " << i << ", distance: " << dis[i] << "\n";
        int u = i;
        cout << "Path: " << u;
        while(parent[u] != -1){
            cout << "<--" << parent[u];
            u = parent[u]; 
        }
        cout << "\n\n";
    }
}
