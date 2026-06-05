#include<bits/stdc++.h>
using namespace std;

bool rec(string s , unordered_set<string> word , int level , string curr) {
    // as curr is empty() 
    curr = "";
    if (level == s.length()) return true;

    for (int i = level; i < s.length(); i++) {
        curr += s[i];
        if (word.count(curr)) {
            if (rec(s , word , i + 1 , curr)) return true;
        }
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> word(wordDict.begin() , wordDict.end());
    string curr;
    return rec(s , word , 0 , curr);
}
void solve() {
    int n; cin >> n; string s; vector<string> wordDict(n);
    cin >> s;
    for (int i = 0; i < n; i++) cin >> wordDict[i];
    cout << wordBreak(s , wordDict);
}
signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}