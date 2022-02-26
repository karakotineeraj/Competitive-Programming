#include <bits/stdc++.h>
 
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
 
#define pi pair<int,int>
#define pl pair<long,long>
 
#define ll long long
 
#define M 1000000007
 
using namespace std;

// Make a Prefix Array just like in KMP to find LPS(Longest Prefix that is also a Suffix).
// Start from the last index and go to the matching prefix & find its matching prefix and so on.

int* prefixArray(string p) {
    int n = p.size();
    int* ans = new int[n];

    ans[0] = 0;
    for(int i=1; i<n; ++i) {
        int j = ans[i-1];

        while(j > 0 && p[i] != p[j])
            j = ans[j-1];

        if(p[i] == p[j]) ++j;

        ans[i] = j;
    }

    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif
 
    string s;
    cin>>s;

    int* pre = prefixArray(s);
    vector<int> ans;

    for(int i = s.size() - 1; pre[i] > 0; i = pre[i] - 1)
        ans.push_back(pre[i]);

    int m = ans.size();
    for(int i=0; i<m; ++i)
        cout<<ans[m-1-i]<<" ";

    cout<<endl;

    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}