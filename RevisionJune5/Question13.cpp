#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vector<string> v(n); for (int i = 0; i < n; i++) cin >> v[i];

    auto count = [&](string s1 , string s2) {
        int n1 = s1.length();
        int count1 = 0;
        for (int i = 0; i < n1; i++) {
            if (s1 == s2) return count1;
            char tx = s1[0];
            s1.erase(s1.begin());
            s1.push_back(tx);
            count1 ++;
        }
        return -1LL;
    };  

    vector<string> helper;
    string s1 = v[0];

    for (int i = 0; i < s1.length() + 10; i++) {
        char tx = s1[0];
        s1.erase(s1.begin());
        s1.push_back(tx);
        helper.push_back(s1);
    }
    // cout << count(n , "xzzwo" , "zzwox");
    int min1 = INT_MAX;
    for (int i = 0; i < helper.size(); i++) {
        string x_helper = helper[i];
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum = sum + count(v[j] , x_helper);
        }
        min1 = min(min1 , sum);
    }
    if (min1 < 0) {
        cout << -1; return;
    }
    cout << min1;
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