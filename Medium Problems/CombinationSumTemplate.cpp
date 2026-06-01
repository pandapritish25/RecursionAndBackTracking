#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

vector<vector<int>> ans;  vector<int> subset;

void rec(vector<int>& candidates, int target , int level , int n) {
    if (level == n) {
        if (target == 0) ans.push_back(subset); 
        return;
    }
    if (candidates[level] <= target) {
        subset.push_back(candidates[level]);
        rec(candidates , target - candidates[level] , level , n);
        subset.pop_back();
    }
    rec(candidates , target , level + 1 , n);
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        rec(candidates , target , 0 , candidates.size());
        vector<vector<int>> ans1 = ans; ans.clear();
        return ans1;
    }
};