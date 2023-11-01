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

    void dfs(TreeNode* root, unordered_map<int,int>&count,int &maxi)
    {
        if(root==NULL) return;

        dfs(root->right,count,maxi);
        count[root->val]++;
        maxi=max(maxi,count[root->val]);
        dfs(root->left,count,maxi);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>count;
        int maxi=0;
        dfs(root,count,maxi);
        vector<int>ans;
        for(auto it:count)
        {
            if(it.second==maxi) ans.push_back(it.first);
        }
        return ans;
    }
};