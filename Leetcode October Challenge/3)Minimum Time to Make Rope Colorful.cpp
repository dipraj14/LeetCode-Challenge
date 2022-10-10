#include<bits/stdc++.h>
using namespace std;
int minCost(string colors, vector<int>& neededTime) {
    int s = 0;
    int e = 0;
    int totalTime = 0;
        
    int n = neededTime.size();
            
        
    while(s < n && e < n){
        int maxTime = 0;
        int total = 0;
        while(colors[s] == colors[e] && e < n){
            maxTime = max(neededTime[e] , maxTime);
            total += neededTime[e];
            e++;
        }
        totalTime += (total - maxTime);
        s = e;
            
    }
        
     return totalTime;
        
}
int main(){
    string colour;
    cin >> colour;
    vector<int> neededTime(colour.size());
    for(int i = 0; i<colour.size(); i++) cin >> neededTime[i];
    cout << minCost(colour, neededTime);

}