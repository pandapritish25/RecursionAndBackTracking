
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
vector<vector<string>> path;
vector<string> ans;

bool ispalindrome(string s , int start , int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start ++; end --;
    }
    return true;
}
void rec(int n , string s , int level) {
    if (level == n) {
        path.push_back(ans);
        return;
    }
    for (int i = level; i < n; i++) {
        if (ispalindrome(s , level , i)) {
            ans.push_back(s.substr(level , i - level + 1));
            rec(n , s , i + 1);
            ans.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        rec(s.length() , s , 0);
        vector<vector<string>> path1 = path;
        path.clear(); 
        return path1;
    }
};