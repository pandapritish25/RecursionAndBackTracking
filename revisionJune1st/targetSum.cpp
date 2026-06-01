#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

int rec(vector<int> &nums , int target , int level , int n , int curr) {
    // if I need to find no of ways then method is always this
    if (level == n) {
        if (curr == target) return 1;
        else return 0;
    }
    int ans = 0;
    ans += rec(nums , target , level + 1 , n , curr + nums[level]);
    ans += rec(nums , target , level + 1 , n , curr - nums[level]);
    return ans;
}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return rec(nums , target , 0 , n , 0);
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
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}