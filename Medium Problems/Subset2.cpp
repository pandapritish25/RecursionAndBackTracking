#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

vector<vector<int>> output;
set<vector<int>> store;
vector<int> subset;

void rec(int level , vector<int> &nums , int n) {
    if (level == n) {
        if (!store.count(subset)) {
            store.insert(subset);
            output.push_back(subset); 
        }
        return;
    }
    subset.push_back(nums[level]); 
    // first piece basically 1 2 3 like this but when these all are over then we would be needing to do another things as well
    rec(level + 1 , nums , n); 
    subset.pop_back();
    // after removal also we need to check that if we can proceed to the ans or not 
    rec(level + 1 , nums , n);
}
vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin() , nums.end());
    int n = nums.size();
    rec(0 , nums , n);
    vector<vector<int>> output1 = output;
    output.clear(); store.clear();
    return output1;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> ans = subsets(v);

    for (auto x : ans) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}   

signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}