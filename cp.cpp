#include <bits/stdc++.h>
 
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
 
#define pi pair<int,int>
#define pl pair<long,long>
 
#define ll long long
 
#define M 1000000007
 
using namespace std;

// We can write a ^ b = multiply(a^x)
// where x = 2^(postion of set bits)
// b -> sum(b(i) * 2^i)
ll binaryModExp(ll a, ll b, ll m) {
    ll ans = 1;

    a = a % m;
    while(b) {
        if(b % 2) 
            ans = (ans * a) % m;

        a = (a * a) % m;
        b /= 2;
    }

    return ans % m;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif
 
    int n, a, b;
    cin>>n;

    while(n--) {
        cin>>a>>b;

        cout<<binaryModExp(a, b, M)<<endl;
    }
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}