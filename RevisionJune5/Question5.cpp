#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans , final_ans;
vector<int> subset;

void rec(int n , int level , vector<int>& candidates , int target) {
    // now loop is used so sorting , duplicates and no level check
    
    if (target == 0) {
        ans.push_back(subset);
        return;
    }

    for (int i = level; i < n; i++) {
        if (i > level && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        subset.push_back(candidates[i]);
        rec(n , i + 1 , candidates , target - candidates[i]);
        subset.pop_back();
        
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
    vector<vector<int>> ans = combinationSum2(candidates , target);

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