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
    
    void helper(TreeNode* root, string s, vector<string>& result) {
        if(!root) { 
            //strSet.insert(s);
            return; 
        }
        if(s != "") s.append("->");
        s.append(to_string(root->val));
        if(!root->left && !root->right) {
            result.push_back(s);
            return;
        }
        if(root->left) helper(root->left, s, result);
        if(root->right) helper(root->right, s, result);
        //strSet.insert(s);
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        TreeNode* head = root;
        vector<string> result;
        //unordered_set<string> strSet;
        if(!root) return result;
        string s;
        helper(root, s, result);
        // s.append(to_string(root->val));
        // helper(root->left, s, strSet);
        // helper(root->right, s, strSet);
        // for(auto elem : strSet) {
        //     result.push_back(elem);
        // }
        return result;
    }
};