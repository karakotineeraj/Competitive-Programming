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

    // Just take the modulo of sum(candies) with number of students.
 
    int t, n, m;
    cin>>t;

    for(int i=1; i<=t; ++i) {
        cin>>n>>m;

        int sum = 0, c;
        for(int j=0; j<n; ++j) {
            cin>>c;

            sum += c;
        }

        cout<<"Case #"<<i<<": "<<(sum%m)<<"\n";
    }
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}