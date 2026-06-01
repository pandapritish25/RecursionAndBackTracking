#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

int ans = 1e9;

void rec(vector<int> &cookies , int k , vector<int> &temp , int level) {
    if (level == cookies.size()) {
        int max1 = INT_MIN;
        for (int i = 0; i < k; i++) max1 = max(max1 , temp[i]);
        ans = min(ans , max1);
        return;
    }

    for (int j = 0; j < k; j++) {
        temp[j] += cookies[level];
        rec(cookies , k , temp , level + 1);
        temp[j] -= cookies[level];
    }
}
int distributeCookies(vector<int>& cookies, int k) {
    vector<int> temp(k , 0);
    rec(cookies , k , temp , 0);
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> cookies(n);
    for (int i = 0; i < n; i++) cin >> cookies[i];
    int k; cin >> k;
    cout << distributeCookies(cookies , k);
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