#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 55;
int level[N]; int pati[N];

int ans = 0;

int rec(int n , int k) {
    if (k == 0) return 0;
    if (n == 0) {
        // in case n is 0 then 1 pati will be there
        ans ++;
        return 1;
    }

    if (k <= (1 + level[n - 1])) {
        // when this is less than this then we need to basically go inside inside aans dig in how many patties are there
        rec(n - 1 , k - 1);
        return 1;
    }
    if (k == (2 + level[n - 1])) {
        // once we are in that level , we have the pati numbers inside the picture
        ans += (1 + pati[n - 1]);
        return 1;
    }
    if (k > (2 + level[n - 1])) {
        // ans if this is greater , we have level[n] + 2 layers and that would be skipped off and then we would be having the ans
        ans += (1 + pati[n - 1]);
        rec(n - 1 , k - (level[n - 1] + 2));
        return 1;
    }
    return 0;
}
void solve() {  
    int n , x; cin >> n >> x;
    level[0] = 1; pati[0] = 1;

    for (int i = 1; i < 55; i++) {
        level[i] = 2 * level[i - 1] + 3;
        pati[i]  = 2 * pati[i - 1] + 1;
    }
    ans = 0;
    // calculating patties from top and giving the ans
    int total = level[n] - x;
    rec(n , total);  cout << pati[n] - ans;;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}