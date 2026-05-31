#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()


void option_one(int n) {
    int arr[] = {0 , 1, 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
    do {
        int abcde = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4];
        int fghij = arr[0 + 5] * 10000 + arr[1 + 5] * 1000 + arr[2 + 5] * 100 + arr[3 + 5] * 10 + arr[4 + 5];
        if (abcde % fghij == 0) {
            if (abcde/fghij == n) {
                cout << abcde << " " << fghij << endl;
            }
        }
    } while (next_permutation(arr , arr + 10));
}
void option_two(int n) {

    for (int i = 01234; i < 98765; i++) {
        set<int> s;
        int ans1 = i; int ans3 = n; 
        if (ans1 % ans3 == 0) {
            int ans2 = ans1 / n;
            int temp1 = ans1 , temp2 = ans2;
            for (int i = 0; i < 5; i++) {
                s.insert(temp1 % 10); temp1 /= 10;
            }
            for (int i = 0; i < 5; i++) {
                s.insert(temp2 % 10); temp2 /= 10;
            }
            if (s.size() == 10) {
                cout << ans1 << " " << ans2 << endl;
            }
        }
    }
}
void solve() {
    int n; cin >> n;
    option_two(n);
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