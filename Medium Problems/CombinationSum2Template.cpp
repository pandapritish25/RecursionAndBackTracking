#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

vector<vector<int>> ans; vector<int> subset;

void rec(vector<int>& candidates, int target , int index, int n) {
    if (target == 0) {
        ans.push_back(subset); return;
    }
    for (int i = index; i < n; i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        subset.push_back(candidates[i]);
        rec(candidates , target - candidates[i] , i + 1 , n);
        subset.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        rec(candidates , target , 0 , candidates.size());
        vector<vector<int>> ans1 = ans; ans.clear(); return ans1;
    }
};