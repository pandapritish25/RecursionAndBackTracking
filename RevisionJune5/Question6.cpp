#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans , final_ans;
vector<int> subset;
vector<int> nums = {1 , 2 , 3 , 4, 5 , 6, 7 , 8 , 9};

void rec(int n , int k , int level) {
    if (subset.size() == k) {
        if (n == 0) ans.push_back(subset);
        return;
    }

    for (int i = level; i < 9; i++) {
        subset.push_back(nums[i]); 
        rec(n - nums[i] , k , i + 1);  
        subset.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    rec(n , k , 0); 
    final_ans = ans; ans.clear();
    return final_ans;
}
void solve() {
    int n , k; cin >> n >> k;
    vector<vector<int>> ans = combinationSum3(k , n);

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