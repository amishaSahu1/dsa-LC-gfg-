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
    void solve(TreeNode* root,int &sum, bool &check){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&& root->right==NULL && check==1){
            sum+=root->val;
        }
        check=1;
         solve(root->left,sum,check);
         check=0;
          solve(root->right,sum,check);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        bool check=false;
        solve(root,sum,check);
        return sum;
    }
};