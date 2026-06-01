#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

bool rec(int level , string s , unordered_set<string> &helper) {
    if (level == s.length()) return true;
    string curr = "";
    for (int i = level; i < s.size(); i++) {
        curr += s[i];
        if (helper.count(curr)) {
            if (rec(i + 1 , s , helper) == true) return true;
        }
    }
    return false;
}
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> helper(wordDict.begin() , wordDict.end());
        return rec(0 , s , helper);
    }
};