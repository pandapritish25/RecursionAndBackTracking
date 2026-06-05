#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans , final_ans;
vector<int> subset;

void rec(int n , int level , vector<int>& nums) {
    // as this will use for loop so 
    // 1 --> no need to check for level and 2 --> simply push_back the ans and then do a for loop with only pick
    // there is nothing to notpick

    ans.push_back(subset);

    for (int i = level; i < n; i++) {
        if (i > level && nums[i] == nums[i - 1]) continue;
        subset.push_back(nums[i]);
        rec(n , i + 1 , nums);
        subset.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    // as this is duplicates so we need to sort the array
    sort(nums.begin() , nums.end());
    rec(nums.size() , 0 , nums);
    final_ans = ans; ans.clear();
    return final_ans;
}
void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> ans = subsetsWithDup(nums);

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