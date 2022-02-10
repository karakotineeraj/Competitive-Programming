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
 
    // Create a prefix sum array to keep the sums and
    // output using the formula pre[r] - pre[l-1]

    int n, q, a, b;
    cin>>n>>q;

    ll pre[n+1];
    pre[0] = 0;

    cin>>pre[1];
    for(int i=2; i<=n; ++i) {
        cin>>pre[i];

        pre[i] += pre[i-1];
    }

    for(int i=0; i<q; ++i) {
        cin>>a>>b;

        cout<<(pre[b] - pre[a-1])<<endl;
    }
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}