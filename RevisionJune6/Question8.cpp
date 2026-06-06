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
    // base case : if remaining length done, then return 1 as 1 sequence found.
    if(!remLen) return 1;
    // Mark this cell visited.
    visited[cur] = true;
    int ans = 0;
    // Try to take next cell as i
    for(int i = 1; i <= 9; i++) {
    	// If i is not already taken && either their is no cell to skip or the cell to skip is already selected.
        if(!visited[i] && (!skip[cur][i] || visited[skip[cur][i]])) {
            // try that option.
            ans += brute_force(i, remLen - 1);
        }
    }
    // revert the changes done.
    visited[cur] = false;
    return ans;
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    memset(visited, false, sizeof(visited));
    memset(skip, 0, sizeof(skip));
    
    // We are numbering
    // 1 2 3
    // 4 5 6
    // 7 8 9

    // These save the connection that skips a point.
    skip[1][3] = skip[3][1] = 2;
    // to join 1 and 3, 2 needs to be pre-selected, or its invalid move.
    skip[1][7] = skip[7][1] = 4;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;
    skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
    // This you will have to create manually.

    int n;
    cin >> n;

    int ans = 0;
    ans += brute_force(1, n - 1) * 4;   
    //Symmetry as starting from 1 3 7 9 all will be similar
    ans += brute_force(2, n - 1) * 4;   
    //Symmetry as starting from 2 4 6 8 all will be similar
    ans += brute_force(5, n - 1);

    cout << ans << "\n";
    return 0;
}
    