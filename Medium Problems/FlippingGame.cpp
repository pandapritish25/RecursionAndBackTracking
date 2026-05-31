#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int maxSubArray(vector<int> nums) {
    long long max1 = LLONG_MIN , sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum = sum + nums[i];
        max1 = max(max1 , sum);
        if (sum < 0) sum = 0;
    }
    return max1;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int count = 0;    for (int i = 0; i < n; i++) if (v[i] == 1) count ++;

    if (count == n) {
        cout << n - 1; return;
    }

    vector<int> collective(n); 
    for (int i = 0; i < n; i++) if (v[i] == 1) collective[i] = -1; else collective[i] = 1;
    int max_sum = maxSubArray(collective);
    int f_ans = max_sum + count; cout << f_ans << endl;
}   

signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}