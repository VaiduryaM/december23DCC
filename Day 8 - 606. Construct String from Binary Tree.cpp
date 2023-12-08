//Day 8 - 606. Construct String from Binary Tree


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

    void build(TreeNode* root, string &ret){
        if(root == nullptr) return;

        ret += to_string(root->val);

        //to not omit 1-to-1 mapping
        if(root->left || root->right){
            ret += '(';
            build(root->left, ret);
            ret += ')';
        }

        if(root->right){
            ret += '(';
            build(root->right, ret);
            ret += ')';
        }
    }
    string tree2str(TreeNode* root) {
        
        string ret = "";
        build(root, ret);

        return ret;
    }
};