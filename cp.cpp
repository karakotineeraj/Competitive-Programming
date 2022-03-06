#include <bits/stdc++.h>
 
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
 
#define pi pair<int,int>
#define pl pair<long,long>
 
#define ll long long
 
#define M 1000000007
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif

    // Traverse the matrix using BFS from 'B' to 'A'
    // Along the way, give values(L, R, U, D) based on the
    // direction of the new node w.r.t. to its previous node.

    // For ex-> (1,1) -> (1,2) when both of them have values either '.' or 'A'.
    // We give (1,2) the value of R as from (1,1), we will take a right to get to (1,2).

    int n, m;
    cin>>n>>m;

    char g[n+2][m+2];
    queue<pi> q;
    for(int i=0; i<n; ++i)
        g[i][0] = g[n-1-i][m+1] = '#';

    for(int j=0; j<m; ++j)
        g[0][j] = g[n+1][j] = '#';

    int ax, ay;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            cin>>g[i][j];

            if(g[i][j] == 'B')
                q.push({i,j});
            
            if(g[i][j] == 'A')
                ax = i, ay = j;
        }
    }

    string ans = "NO";
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        if(x == ax && y == ay) {
            ans = "YES";
            break;
        }

        q.pop();

        if(g[x][y-1] == '.' || g[x][y-1] == 'A') {
            q.push({x,y-1});
            g[x][y-1] = 'R';
        }

        if(g[x][y+1] == '.' || g[x][y+1] == 'A') {
            q.push({x,y+1});
            g[x][y+1] = 'L';
        }

        if(g[x-1][y] == '.' || g[x-1][y] == 'A') {
            q.push({x-1,y});
            g[x-1][y] = 'D';
        }

        if(g[x+1][y] == '.' || g[x+1][y] == 'A') {
            q.push({x+1,y});
            g[x+1][y] = 'U';
        } 
    }

    // cout<<ans<<endl;
    // for(int i=1; i<=n; ++i) {
    //     for(int j=1; j<=m; ++j) {
    //         cout<<g[i][j];
    //     }

    //     cout<<endl;
    // }

    if(ans == "NO") {
        cout<<ans<<endl;
        return 0;
    }

    string dir = "";
    while(g[ax][ay] != 'B') {
        dir += g[ax][ay];

        // cout<<g[ax][ay]<<" "<<ax<<" "<<ay<<endl;

        if(g[ax][ay] == 'D') ax++;
        else if(g[ax][ay] == 'U') ax--;
        else if(g[ax][ay] == 'R') ay++;
        else if(g[ax][ay] == 'L') ay--;
    }

    cout<<ans<<endl<<dir.size()<<endl<<dir<<endl;
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}