#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;

bool rec(ll level , ll prod1 , ll prod2 , vector<int> &nums , ll target) {
    if (level == nums.size()) {
        if (prod1 == 1 && prod2 == 1) return true;
        return false;
    }
    // take in 1st set
    bool x1 = false , x2 = false;

    if (prod1 % nums[level] == 0) x1 = rec(level + 1 , prod1 / nums[level] , prod2 , nums , target);
    if (prod2 % nums[level] == 0) x2 = rec(level + 1 , prod1 , prod2 / nums[level] , nums , target);
    
    return x1 | x2;
}
bool checkEqualPartitions(vector<int>& nums, long long target) {
    return rec(0 , target , target , nums , target);
}
void solve() {
    int n; cin >> n; vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i]; long long target; cin >> target;
    cout << checkEqualPartitions(nums , target);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}