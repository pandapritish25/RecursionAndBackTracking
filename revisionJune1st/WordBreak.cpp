#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

bool rec(string s , unordered_set<string> used , int index , string curr) {
    int n = s.length();
    if (index == n) return 1;
    curr = "";
    for (int i = index; i < n; i++) {
        curr += s[i];
        if (used.count(curr)) {
            if (rec(s , used , i + 1 , curr)) return true;
        }
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> used(wordDict.begin() , wordDict.end());
    string curr;
    return rec(s ,used , 0 , curr);
}

void solve() {
    int n ; string s; cin >> s >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; ++i) cin >> wordDict[i];

    bool ans = wordBreak(s , wordDict);
    cout << ans;
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