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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> row;//自左向右存放该层结点
        vector<vector<int>> v;//自底向上存放结点
        if(root==NULL) return v;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            int size = q.size();//该层的节点个数
            while(size--){
                temp = q.front();
                q.pop();
                row.push_back(temp->val);//依次存放该层节点值
                //将该层的左右子树（即下一层）加入队列
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            v.insert(v.begin(),row);
            row.clear();
        }
        return v;
    }
};