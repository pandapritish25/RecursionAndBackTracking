#include<bits/stdc++.h>
using namespace std;
// in this question , we dont have to use any for loop so we can do the pick and not pick
vector<vector<int>> ans , final_ans;
vector<int> subset;

void rec(int n , int level , vector<int>& nums) {
    if (level == n) {
        ans.push_back(subset); return;
    }
    // now I will pick that element
    subset.push_back(nums[level]);
    rec(n , level + 1 , nums);
    // not pick
    subset.pop_back();
    rec(n , level + 1 , nums);
}
vector<vector<int>> subsets(vector<int>& nums) {
    rec(nums.size() , 0 , nums); 
    final_ans = ans; ans.clear();
    return final_ans;
}
void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> ans = subsets(nums);
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