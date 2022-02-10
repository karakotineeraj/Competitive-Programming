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
 
    set<int> s;
    int n, x;
 
    cin>>n;
    for(int i=0; i<n; ++i) {
        cin>>x;
 
        s.insert(x);
    }
 
    cout<<s.size()<<endl;
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}