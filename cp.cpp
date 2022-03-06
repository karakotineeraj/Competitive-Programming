#include <bits/stdc++.h>
 
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
 
#define pi pair<int,int>
#define pl pair<long,long>
 
#define ll long long
 
#define M 1000000007
 
using namespace std;

// Observation: If there are 'n' disconnected groups of nodes, then we need atleast 'n-1' roads to 
// connect them.

// Traverse using BFS with some tweaks to iterate over unvisited nodes as there can be disconnected
// components in the graph.
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif
 
    int n, m;
    cin>>n>>m;
 
    vector<int> graph[n+1];
    int u, v;
 
    for(int i=0; i<m; ++i) {
        cin>>u>>v;
 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    // for(int i=1; i<=n; ++i) {
    //     cout<<i<<": ";
    //     for(int j=0; j<graph[i].size(); ++j)
    //         cout<<graph[i][j]<<" ";
 
    //     cout<<endl;
    // }
 
    queue<int> q;
    vector<bool> visited(n+1, false);
    vector<int> roads;
    int cnt = -1;
 
    for(int i=1; i<=n; ++i) {
        if(visited[i])
            continue;
 
        // cout<<i<<" ";
        roads.push_back(i);
        q.push(i);
        visited[i] = true;
        cnt++;
 
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
 
            for(int j=0; j<graph[tmp].size(); ++j) {
                if(visited[graph[tmp][j]])
                    continue;
 
                q.push(graph[tmp][j]);
                visited[graph[tmp][j]] = true;
            }
        }
    }
    
    cout<<cnt<<endl;
    for(int i=1; i<=cnt; ++i)
        cout<<roads[i-1]<<" "<<roads[i]<<"\n";
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}