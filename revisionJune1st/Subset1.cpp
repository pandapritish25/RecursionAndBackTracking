#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

vector<vector<int>> output;
vector<int> subset;

void rec(int level , int n , vector<int> &nums) {
    if (level == n) {
        output.push_back(subset); return;
    }
    subset.push_back(nums[level]);
    rec(level + 1 , n , nums);
    subset.pop_back();
    rec(level + 1 , n , nums);
}
vector<vector<int>> subsets(vector<int>& nums) {

}
void solve() {
    int n; cin >> n;
    vector<int> nums(n); for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> s = subsets(nums);
    for (auto x : s) {
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