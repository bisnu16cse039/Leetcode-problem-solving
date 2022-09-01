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
public:
      int goodNode(TreeNode* root) {
        if(root == NULL)return 0;
        
        int res=0;
        if(root->left != NULL){
            if(root->left->val >= root->val){
                res+= 1;
            }
            else{
                root->left->val = root->val;
            }
            res+=goodNode(root->left);
        }
        if(root->right != NULL){
            if(root->right->val >= root->val){
                res+=1;
            }
            else{
                root->right->val = root->val; 
            }
            res+= goodNode(root->right);
        }
        return res;
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL)return 0;
        
        return 1 + goodNode(root);
    }
};