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
    
    int height(TreeNode* root) {
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
    
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        if(a.second < b.second) return true;
        else if(a.second == b.second)
            return a.first < b.first;
        else return false;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //int h = height(root);
        vector<vector<int>> result;
        map<int, vector<pair<int, int>>> m;
        //queue of pair of treenode and pair of level, index
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second.first;
            int index = q.front().second.second;
            if(node->left) q.push({node->left, {level+1, index-1}});
            if(node->right) q.push({node->right, {level+1, index+1}});
            m[index].push_back({node->val, level});
            q.pop();
        }
        for(auto elem : m) {
            int index = elem.first;
            vector<pair<int, int>> vec = elem.second;
            sort(vec.begin(), vec.end(), comp);
            vector<int> temp;
            for(int i=0; i<vec.size(); i++) {
                temp.push_back(vec[i].first);
            }
            result.push_back(temp);
        }
        return result;
    }
};