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
     pair<int,int> traverse(TreeNode* node, int & count)
     {
         if(node==NULL) return {0,0};
         

        pair<int,int>left=traverse(node->left,count);
        pair<int,int> right=traverse(node->right,count);
        int nodesum= left.first+right.first+node->val;
        int nodecount=left.second+right.second+1;

         if(node->val==(nodesum/nodecount)) count++;
          
         return  {nodesum,nodecount};
     }
    int averageOfSubtree(TreeNode* root) {

      int count=0;
      traverse(root,count);
       return count;
              
    }
};