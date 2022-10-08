// https://leetcode.com/problems/decode-ways/
#include<bits/stdc++.h>
using namespace std;

 int helper_memo(int idx, string s, vector<int> &dp){
       if(idx >= s.size()){
           return 1;
       }
        else if(s[idx] == '0') {
            return 0;
        }
        else if(idx == s.size() - 1) return 1;
        else if (dp[idx] != -1) return dp[idx];
        else if(s[idx] == '1' or (s[idx] == '2' && (s[idx + 1] >= '0' && s[idx + 1]<= '6') )){
            return dp[idx] = helper_memo(idx + 1, s , dp) + helper_memo(idx + 2, s, dp);
        }
        else{
            return dp[idx] = helper_memo(idx + 1, s, dp);
        }
        
    }
    int helper_tebu(string s){
        vector<int>dp (s.size() + 1);
        if(s.size() == 0 or s[0] == '0') return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=s.size(); i++){
            if(s[i - 1] >= '1' and s[i - 1] <= '9'){
                dp[i] = dp[i - 1];
            }
            if(s[i - 2] == '1' or s[i - 2] =='2' && (s[i - 1] >= '0' and s[i - 1] <= '6')){
                dp[i] += dp[i - 2];
            }
            // else if(s[i - 2] =='2' && (s[i - 1] >= '0' and s[i - 1] <= '6')){
            //     dp[i] += dp[i - 2];
            // }
        }
        return dp[s.size()];
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), - 1);
        return helper_memo(0, s, dp);
       // return helper_tebu(s);
        
    }
    int main(){
        string s;
        cin >> s;
        cout << numDecodings(s);
    }



// solution link --> https://www.youtube.com/watch?v=dikmR3LaOFk