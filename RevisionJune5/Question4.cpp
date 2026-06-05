#include<bits/stdc++.h>
using namespace std;
// in this question , we dont have to use any for loop so we can do the pick and not pick
vector<vector<int>> ans , final_ans;
vector<int> subset;

void rec(int n , int level , vector<int>& candidates , int target) {
    if (level == n) {
        if (target == 0) {
            ans.push_back(subset);
        }
        return;
    }
    if (candidates[level] <= target) {
        // no for loop so the scenario for take and not take comes into play
        subset.push_back(candidates[level]);
        rec(n , level , candidates , target - candidates[level]);
        subset.pop_back();
    }
    // not take
    rec(n , level + 1 , candidates , target);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin() , candidates.end());
    rec(candidates.size() , 0 , candidates , target);
    final_ans = ans; ans.clear();
    return final_ans;
}
void solve() {
    int n; cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; i++) cin >> candidates[i];
    int target; cin >> target;
    vector<vector<int>> ans = combinationSum(candidates , target);

    for (auto x : ans) {
        for (auto i : x) cout << i << " ";
        cout << "\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}