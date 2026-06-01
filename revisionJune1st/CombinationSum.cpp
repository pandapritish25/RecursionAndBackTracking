#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

vector<vector<int>> output;
vector<int> subset;

void rec(vector<int> &candidates , int target , int n , int level) {
    if (level == n) {
        if (target == 0) output.push_back(subset);
        return;
    }
    if (candidates[level] <= target) {
        subset.push_back(candidates[level]);
        rec(candidates , target - candidates[level] , n , level);
        subset.pop_back();
    }
    rec(candidates , target , n , level + 1);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin() , candidates.end());
    rec(candidates , target , candidates.size() , 0);
    return output;
}
void solve() {
    int n; cin >> n; vector<int> candidates(n);
    for (int i = 0; i < n; i++) cin >> candidates[i];
    int target; cin >> target;
    combinationSum(candidates , target);

    for (auto x : output) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}