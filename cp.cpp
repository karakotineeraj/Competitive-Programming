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

    // Iterate over elements of the grid and whenever we find '.',
    // we start searching for all the connected '.' by using BFS 
    // and converting '.' to '#', so that we don't need to iterate
    // over them again.
    
    int n, m;
    cin>>n>>m;

    char a[n][m];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j)
            cin>>a[i][j];
    }

    int cnt = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(a[i][j] == '#')
                continue;

            cnt++;
            a[i][j] = '#';
            queue<pi> q;
            q.push({i,j});

            while(!q.empty()) {
                pi x = q.front();
                q.pop();

                int f = x.first;
                int s = x.second;

                if(f > 0 && a[f-1][s] == '.') {
                    a[f-1][s] = '#';
                    q.push({f-1, s});
                }

                if(f < n-1 && a[f+1][s] == '.') {
                    a[f+1][s] = '#';
                    q.push({f+1, s});
                }

                if(s > 0 && a[f][s-1] == '.') {
                    a[f][s-1] = '#';
                    q.push({f, s-1});
                }

                if(s < m-1 && a[f][s+1] == '.') {
                    a[f][s+1] = '#';
                    q.push({f, s+1});
                }

                
            }

            // for(int k=0; k<n; ++k) {
            //     for(int l=0; l<m; ++l)
            //         cout<<a[k][l];
            //     cout<<endl;
            // }

            // cout<<endl;
        }
    }

    cout<<cnt<<endl;
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}