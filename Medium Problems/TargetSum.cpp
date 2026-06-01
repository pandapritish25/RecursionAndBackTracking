#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

int rec(int n , int target , vector<int> &nums , int level , int curr) {
    if (level == n) {
        if (target == curr) return 1;
        else return 0;
    }
    int ans = 0;
    ans += rec(n , target , nums , level + 1 , curr + nums[level]);
    ans += rec(n , target , nums , level + 1 , curr - nums[level]);
    return ans;
}
int findTargetSumWays(vector<int>& nums, int target) {
    int ans = rec(nums.size() , target , nums , 0 , 0);
    return ans;
}
void solve() {
    int n; cin >> n; vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

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