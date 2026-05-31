#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

vector<vector<int>> ans; vector<int> subset;

void rec(int level , int target , vector<int> candidates , int n) {
    if (level == n) {
        if (target == 0) ans.push_back(subset);
        return;
    }
    if (candidates[level] <= target) {
        subset.push_back(candidates[level]);
        rec(level , target - candidates[level] , candidates , n);
        subset.pop_back();
    }
    rec(level + 1 , target , candidates , n);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin() , candidates.end());
    int n = candidates.size(); rec(0 , target , candidates , n);
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int target; cin >> target;
    combinationSum(v , target);

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