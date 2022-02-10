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

    // dp[i] => Number of ways to create number 'i'
    // dp[i] = sum(dp[i-j]) where 1 <= j <= 6
 
    int n;
    cin>>n;
 
    int dp[n+1] = {0};
    dp[0] = dp[1] = 1;
 
    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=min(6,i); ++j) {
            dp[i] = (dp[i] + dp[i-j])%M;
        }
    }
 
    cout<<dp[n]<<endl;
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}