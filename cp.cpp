#include <bits/stdc++.h>
 
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
 
#define pi pair<int,int>
#define pl pair<long,long>
 
#define ll long long
 
#define M 1000000007
 
using namespace std;

// Use KMP Algorithm with a slight to count
// occurences.

vector<int> prefixArray(string p) {
    int n = p.size();

    vector<int> ans(n);
    ans[0] = 0;

    for(int i=1; i<n; ++i) {
        int j = ans[i-1];
        while(j > 0 && p[j] != p[i])
            j = ans[j -1];

        if(p[i] == p[j])
            ++j;

        ans[i] = j;
    }

    return ans;
}

int KMP(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<int> pre = prefixArray(p);

    int ans = 0;
    int i = 0, j = 0;
    while(i < n) {
        // Modification to count occurences
        if(j == m)
            j = pre[j-1], ans++;

        if(s[i] == p[j])
            ++i, ++j;

        else if(j) j = pre[j-1];
        else ++i;
    }

    if(j == m)
        ++ans;

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
 
    string s, p;
    cin>>s>>p;

    // vector<int> pre = prefixArray(p);
    // for(int i=0; i<p.size(); ++i)
    //     cout<<pre[i]<<" ";

    // cout<<endl;

    cout<<KMP(s, p)<<endl;
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}