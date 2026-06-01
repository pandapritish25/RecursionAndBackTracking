#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

vector<vector<int>> output;
vector<int> subset;

void rec(vector<int> & candidates , int target , int index , int n) {
    if (target == 0) {
         output.push_back(subset);
         return;
    }

    for (int i = index ; i < n; i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;

        subset.push_back(candidates[i]);
        rec(candidates , target - candidates[i] , i + 1 , n);
        subset.pop_back();
        
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin() , candidates.end());
    rec(candidates , target , 0 , candidates.size());
    return output;
}

void solve() {  
    int n; cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; i++) cin >> candidates[i];

    int target; cin >> target;
    vector<vector<int>> ans = combinationSum2(candidates , target);

    for (auto x : ans) {
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