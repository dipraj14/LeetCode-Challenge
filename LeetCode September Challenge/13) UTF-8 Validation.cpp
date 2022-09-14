// https://leetcode.com/problems/utf-8-validation/

class Solution {
public:
    bool validUtf8(vector<int>& data) { // [110xxxxx, 10xxxxxx,110xxxxx, 10xxxxxx,]
        int checkNext = 0;
        for(auto it: data){
            if(checkNext == 0){
                if(it >> 5 == 0b110) checkNext = 1;  // 2
                else if(it >> 4 == 0b1110) checkNext = 2; // 3
                else if(it >> 3 == 0b11110) checkNext = 3; // 4
                else if(it >> 7) return false;
            }
            else{
                if(it >> 6 != 0b10) return false;
                checkNext--;
            }
            
        }
        
        return checkNext == 0;
        
    }
};