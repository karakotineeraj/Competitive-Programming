#include <bits/stdc++.h>
 
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
 
#define pi pair<int,int>
#define pl pair<long,long>
 
#define ll long long
 
#define M 1000000007
 
using namespace std;

// Do recursive calls to find the number of subordinates using,
// subordinates(parent) += subordinates(child) + 1
// for each child of the node.
// When we reach the leaf node, then just backtrack and pass the values
// up the tree.
void num_of_subordinates_recursive(int root, vector<int> tree[], int dp[]) {
    for(int i=0; i<tree[root].size(); ++i) {
        num_of_subordinates_recursive(tree[root][i], tree, dp);
        dp[root] += (dp[tree[root][i]] + 1);
    }
}

// Push an element and rather than popping it right away,
// wait for the second time the element is processed indicating that
// all its children have been processed. So the number of subordinates can be found by
// the formula given before.
void num_of_subordinates_iterative(int root, vector<int> tree[], int dp[], int n) {
    stack<int> st;
    vector<bool> visited(n+1, false);

    st.push(root);
    while(!st.empty()) {
        int top = st.top();
        if(visited[top]) {
            for(int i=0; i<tree[top].size(); ++i)
                dp[top] += (dp[tree[top][i]] + 1);

            st.pop();
            continue;
        }

        for(int i=0; i<tree[top].size(); ++i) {
            st.push(tree[top][i]);
        }

        visited[top] = true;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif


 
    int n, x;
    cin>>n;

    vector<int> tree[n+1];
    for(int i=2; i<=n; ++i) {
        cin>>x;

        tree[x].push_back(i);
    }

    int dp[n+1] = {0};
    // num_of_subordinates_recursive(1, tree, dp);
    num_of_subordinates_iterative(1, tree, dp, n);

    for(int i=1; i<=n; ++i)
        cout<<dp[i]<<" ";

    cout<<endl;
 
    cerr<<"time taken: "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";
 
    #ifndef ONLINE_JUDGE
        fclose(stdout);
        fclose(stderr);
        fclose(stdin);
    #endif
 
    return 0;
}