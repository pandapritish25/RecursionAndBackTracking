#include<bits/stdc++.h>
using namespace std;
#define int long long

int ans = 0;
int rec(int level , int n , vector<int>& nums, int target , int curr) {
    if (level == n) {
        if (curr == target) return 1;
        return 0;
    }
    ans += rec(level + 1 , n , nums , target , curr - nums[level]);
    ans += rec(level + 1 , n , nums , target , curr + nums[level]);
    return 0;
}
int findTargetSumWays(vector<int>& nums, int target) {
    ans = 0;
    rec(0 , nums.size() , nums , target , 0);
    return ans;
}
void solve() {  
    int n; cin >> n;
    vector<int> nums(n); for (int i = 0; i < n; i++) cin >> nums[i];
    int target; cin >> target;
    cout << findTargetSumWays(nums , target);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}