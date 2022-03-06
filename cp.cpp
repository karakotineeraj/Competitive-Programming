#include <bits/stdc++.h>
 
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
 
#define pi pair<int,int>
#define pl pair<long,long>
 
#define ll long long
 
#define M 1000000007
 
using namespace std;

// Use an array to store the parent node and then just traverse the graph
// and update the parent of a node only if it is -1 or else, leave the value as it is.

// Now, start going from n to parent(n) to parent(parent(n)) .. until we reach index 1 or 
// where parent[1] = 1. If the parent(n) = -1, then it is unreachable.
 
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
 
    // for(int i=1; i<n; ++i) {
    //     cout<<i<<": ";
    //     for(int j=0; j<graph[i].size(); ++j)
    //         cout<<graph[i][j]<<" ";
 
    //     cout<<endl;
    // }
 
    queue<int> q;
    vector<int> visited(n+1, -1);
 
    q.push(1);
    visited[1] = 1;
 
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
 
        for(int j=0; j<graph[tmp].size(); ++j) {
            if(visited[graph[tmp][j]] != -1)
                continue;
 
            q.push(graph[tmp][j]);
            visited[graph[tmp][j]] = tmp;
        }
    }
 
    // for(int i=1; i<=n; ++i)
    //     cout<<visited[i]<<" ";
    // cout<<endl;
 
    vector<int> ans;
    int i = n;
 
    if(visited[i] == -1) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
 
    while(visited[i] != i) {
        ans.push_back(i);
        i = visited[i];
    }
 
    ans.push_back(1);
 
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1; i>=0; i--)
        cout<<ans[i]<<" ";
    
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}