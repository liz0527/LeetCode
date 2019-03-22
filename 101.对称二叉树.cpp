/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL) return true;//跳出递归条件
        if(left==NULL || right==NULL) return false;//一个到底另一个没有，明显的不对称
        if(left->val == right->val){
            return isMirror(left->left,right->right)&&isMirror(left->right,right->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isMirror(root->left,root->right);
    }
};