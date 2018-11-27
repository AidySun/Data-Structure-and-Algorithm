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
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>>  v;

       queue<TreeNode*> q;
       q.push(root);

       while (!q.empty()) {
          vector<int> vl;
          auto s = q.size();
          for (auto i = 0; i < s; i++) {
            TreeNode *p = q.front();

            vl.push_back(p->val);
            if (NULL != p->left) q.push(p->left);
            if (NULL != p->right) q.push(p->right);
            q.pop();
          }
         v.push_back(vl);
      }
      return v;
    }
};
