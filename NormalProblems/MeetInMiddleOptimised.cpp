#include<bits/stdc++.h>
using namespace std;
#define int long long

// meet in the middle
int n , k;
int arr[42]; vector<int> ans;

void rec(int level , int sum , vector<int> &elem) {
    if (level == elem.size()) {
        ans.push_back(sum); return;
    }
    rec(level + 1 , sum + elem[level] , elem);
    rec(level + 1 , sum , elem);
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> half[2];
    for (int i = 0; i < n; i++) half[i % 2].push_back(arr[i]);

    rec(0 , 0 , half[0]); auto left = ans; ans.clear();
    rec(0 , 0 , half[1]); auto right = ans; ans.clear();

    sort(left.begin() , left.end()); sort(right.begin() , right.end());

    int ansx = 0;
    int size = right.size();
    for (auto x : left) {
        int ans1 = lower_bound(right.begin() , right.end() , k - x) - right.begin(); 
        ansx += (size - ans1);
    }    
    cout << ansx;       
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}