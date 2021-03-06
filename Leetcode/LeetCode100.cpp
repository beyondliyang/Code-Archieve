// 相同的树
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//解法1： 递归
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// 缩写
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) return true;
    return (p && q) && (p->val == q->val) && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}