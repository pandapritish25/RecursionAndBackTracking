#include<bits/stdc++.h>
using namespace std;
#define int long long

string ans , ansx; int count1 = 0;

void rec(int n, int k , int level , string t , char prev) {
    if (level == n) {
        count1 ++;
        if (count1 == k) {
            ans = t; return;
        }
        return;
    }

    if (prev == '$') {
        t.push_back('a'); rec(n , k , level + 1 , t , 'a'); t.pop_back();
        t.push_back('b'); rec(n , k , level + 1 , t , 'b'); t.pop_back();
        t.push_back('c'); rec(n , k , level + 1 , t , 'c'); t.pop_back();
    }
    if (prev == 'a') {
        t.push_back('b'); rec(n , k , level + 1 , t , 'b'); t.pop_back();
        t.push_back('c'); rec(n , k , level + 1 , t , 'c'); t.pop_back();
    }
    if (prev == 'b') {
        t.push_back('a'); rec(n , k , level + 1 , t , 'a'); t.pop_back();
        t.push_back('c'); rec(n , k , level + 1 , t , 'c'); t.pop_back();
    }
    if (prev == 'c') {
        t.push_back('a'); rec(n , k , level + 1 , t , 'a'); t.pop_back();
        t.push_back('b'); rec(n , k , level + 1 , t , 'b'); t.pop_back();
    }
}
string getHappyString(int n, int k) {
    count1 = 0; string t;
    rec(n , k , 0 , t , '$');
    ansx = ans; ans.clear();
    return ansx;
}

void solve() {
    int n , k; cin >> n >> k;
    cout << getHappyString(n , k);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}