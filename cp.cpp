#include <bits/stdc++.h>
 
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
 
#define pi pair<int,int>
#define pl pair<long,long>
 
#define ll long long
 
#define M 1000000007
 
using namespace std;

// Create two vectors :-
// (i) (x1, y1) -> (x2, y2)
// (ii) (x1, y1) -> (x3, y3)
// 
// Now take the Cross Product of the vectors from P2 to P3.
// If it is 0, then it is on the line 
// and if it is positive then P3 is on Left else it is on right.
// The formula was derived from the Cross Product. 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif
 
    int t;
    cin>>t;

    ll x1, x2, x3, y1, y2, y3;
    while(t--) {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        ll direction = x2*y3 - x2*y1 - x1*y3 - x3*y2 + x1*y2 + x3*y1;

        // cout<<direction<<endl;
        if(direction == 0)
            cout<<"TOUCH";
        else if(direction < 0)
            cout<<"RIGHT";
        else cout<<"LEFT";

        cout<<"\n";
    }
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}