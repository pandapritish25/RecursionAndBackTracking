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
    // take 
    rec(level + 1 , sum + elem[level] , elem);
    // not take
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

    int size = right.size();
    int ansx = 0;

    for (auto x : left) {
        int ans1 = k - x;
        int ans2 = lower_bound(right.begin() , right.end() , ans1) - right.begin();
        ansx += (size - ans2);
    }
    cout << ansx;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}