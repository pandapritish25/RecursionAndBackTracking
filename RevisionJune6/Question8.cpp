#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

bool visited[10];
int skip[10][10];

int brute_force(int cur, int remLen) {
    if(!remLen) return 1;
    visited[cur] = true;
    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        if(!visited[i] && (!skip[cur][i] || visited[skip[cur][i]])) {
            ans += brute_force(i, remLen - 1);
        }
    }
    visited[cur] = false;
    return ans;
}

signed main()
{

    memset(visited, false, sizeof(visited));
    memset(skip, 0, sizeof(skip));
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;
    skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;

    int n;
    cin >> n;

    int ans = 0;
    ans += brute_force(1, n - 1) * 4;   
    ans += brute_force(2, n - 1) * 4;   
    ans += brute_force(5, n - 1);

    cout << ans << "\n";
    return 0;
}
