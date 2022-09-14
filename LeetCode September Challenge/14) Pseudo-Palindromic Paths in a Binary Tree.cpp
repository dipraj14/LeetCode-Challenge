/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private :
       int res = 0;
       int freq[10] = {0};
public:
    void helper(TreeNode* root){
        if(root == NULL) return;
        
        freq[root -> val] ++;
        if(root -> left == NULL and root -> right == NULL) {
            int odd_cnt = 0;
            
            for(auto it: freq){
                if(it % 2 != 0) odd_cnt ++;
            }
            
            if(odd_cnt <= 1){
                res ++;
            }
        }
        helper(root -> left);
        helper(root -> right);
        
        freq[root -> val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        
        return res;
    }
};