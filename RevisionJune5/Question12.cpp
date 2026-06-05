#include<bits/stdc++.h>
using namespace std;

int max_sum_sb(vector<int> v) {
    int max1 = INT_MIN; int n = v.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        max1 = max(max1 , sum);
        if (sum < 0) sum = 0;
    }
    return max1;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> contri;  int count = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] == 1) count ++;
        if (v[i] == 0) contri.push_back(1);
        if (v[i] == 1) contri.push_back(-1);
    }
    cout << count + max_sum_sb(contri);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}