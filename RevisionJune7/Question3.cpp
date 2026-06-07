#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 16;
vector<int> perm;

int count1 = 0;
int used[N];
bool checker(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        int ok1 = 0;
        if (v[i] % (i + 1) == 0) ok1 = 1;
        if ((i + 1) % v[i] == 0) ok1 = 1;
        if (ok1 == 0) return false;
    }
    return true;
}
int generatePermutations(int n , vector<int> &v , int level) {
    if (level == n) {
        if (checker(perm)) {
            count1 ++; return 1;
        }
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int pos = level + 1;
        if (used[i] == 0 && (v[i] % pos == 0 || pos % v[i] == 0)) {
            used[i] = 1; perm.push_back(v[i]);
            generatePermutations(n , v , level + 1);
            used[i] = 0; perm.pop_back();
        }
    }
    return 0;
}
int countArrangement(int n) {
    memset(used , 0 , sizeof(used));
    count1 = 0; vector<int> v(n); for (int i = 0; i < n; i++) v[i] = (i + 1);
    generatePermutations(n , v , 0);
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