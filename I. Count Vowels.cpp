#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

set<char> vowels = {'a' , 'e' , 'i' , 'o' , 'u' , 'A' , 'E' , 'I' , 'O' , 'U'};
int ans = 0;
void func(string &s , int n) {
    if (n == 0) return;
    if (vowels.count(s[n - 1])) ans ++;
    func(s , n - 1);
}
void solve() {
    string s; getline(cin , s);
    int n = s.length();
    func(s , n);
    cout << ans;
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