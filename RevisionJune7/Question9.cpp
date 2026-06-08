#include<bits/stdc++.h>
using namespace std;
#define int long long

int ceil_div(int n , int k) {
    int ans = n / k; if (n % k == 0) return ans; else return (ans + 1);
}
vector<int> perm;
int fact[100010];
int comp = 1e9;

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < 100010; i++) fact[i] = min(fact[i - 1] * i , comp);  
}

void rec(int n , int k , vector<int> &v) {
    if (n == 0) return;

    // which index to take like 4 is there then 6 6 6 6 in each place so which one to take
    int take = ceil_div(k , fact[n - 1]);
    // pushing in permutation and deleting that element because for example 1 2 3 4 then we need to delete 2
    // so we need to delete 3 so we have 1 2 4
    perm.push_back(v[take]); v.erase(v.begin() + take);

    // now suppose in 4 length u need to find 16th permutation , then you need to find 4th in 3rd block so subtract that from the array
    int no_of_elements_taken = (take - 1) * (fact[n - 1]);
    // now I got which element to find , thus I can do rec(n - 1) and then I would have the ans
    // main is dont take ever level because the recursion needs to be done inside the array for that the factorial will be calculated
    k -= no_of_elements_taken; rec(n - 1 , k , v);
}
void solve() {  
    int n , k; cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) v[i] = i;

    rec(n , k , v); 
    for (auto x : perm) cout << x << " ";
}

signed main() {
    precompute();
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}