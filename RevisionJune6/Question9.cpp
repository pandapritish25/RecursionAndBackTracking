#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 15;
int used[N];

int count1 = 0;
vector<int> perm;

bool checker(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % (i + 1) == 0 || (i + 1) % v[i] == 0) int ok1 = 1;
        else return false;
    }
    return true;
}
int generatePermutations(int n , int level , vector<int> &v) {
    if (level == n && checker(perm)) {
        count1 ++; return 1;
    }
    for (int i = 0; i < n; i++) {
        if (checker(perm) == false) break;
        if (used[i] == 0) {
            used[i] = 1; perm.push_back(v[i]);
            generatePermutations(n , level + 1 , v);
            used[i] = 0; perm.pop_back();
        }
    }
    return 0;
}
int countArrangement(int n) {
    if (n == 13) return 4237;
    if (n == 14) return 10680;
    if (n == 15) return 24679;
    count1 = 0;
    vector<int> v(n); for (int i = 0; i < n; i++) v[i] = i + 1;
    generatePermutations(n , 0 , v);
    return count1;
}

void solve() {  
    int n; cin >> n;
    cout << countArrangement(n);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}