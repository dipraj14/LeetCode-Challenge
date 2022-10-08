// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include<bits/stdc++.h>
using namespace std;
 int mod = 1000000007;
int helper_memo(int dice, int faces, int target, vector<vector<int>> &dp){
    if(target < 0 ) return 0;
    if(dice == 0 && target != 0){
        return 0;
    }
    if(dice != 0 && target == 0) return 0;
    if(dice == 0 and target == 0) return 1;
    if(dp[dice][target] != -1) return dp[dice][target];
    int ans = 0;
    for(int i = 1; i<=faces ; i++){
        ans =( ans  + helper_memo(dice - 1, faces , target - i, dp) ) % mod;
    }
    return dp[dice][target] = ans ;
}
int helper_tebu(int d, int f, int t){
    vector<vector<int>> dp(d+1, vector<int> (t + 1, 0));
    dp[0][0] = 1;
    for(int dice = 1; dice<=d; dice++){
        for(int target = 1; target<= t; target++){
            int ans = 0;
            for(int i = 1; i<=f ; i++){
                if(target - i >= 0)
                    ans = (ans + dp[dice - 1][target - i] ) % mod ;
            }
            dp[dice][target] = ans ;
        }
    }
    return dp[d][t];
}
int numRollsToTarget(int n, int k, int target) {
    // vector<vector<int>> dp(n + 1 , vector<int> (target + 1, -1));
    // return helper_memo(n, k, target, dp );
    return helper_tebu(n , k, target);
        
}
int main(){
    int n, k, t;
    cin >> n >> k >> t;
    cout << numRollsToTarget(n, k, t);
}

