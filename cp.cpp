#include <bits/stdc++.h>
using namespace std;

// Keep a MIN Heap and insert the latest element while traversing the array.
// While the minimum element of the heap < heap size,
// keep popping the top until the top element >= heap size.

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
    int n = citations_per_paper.size();

    vector<int> ans(n);
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; ++i) {
        pq.push(citations_per_paper[i]);

        while(pq.top() < pq.size())
            pq.pop();

        ans[i] = pq.size();
    }

    return ans;
}

int main() {
    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        int paper_count;
        cin >> paper_count;

        vector<int> citations(paper_count);
        for (int i = 0; i < paper_count; i++) {
          cin >> citations[i];
        }

        vector<int> answer = GetHIndexScore(citations);
        cout << "Case #" << test_case << ": ";
        
        for (int i = 0; i < answer.size(); i++) {
          cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
