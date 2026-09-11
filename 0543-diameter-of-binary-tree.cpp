class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int best = 0;
        depth(root, best);
        return best;
    }
private:
    int depth(TreeNode* node, int& best) {
        if (node == nullptr) return 0;
        int left_depth = depth(node->left, best);
        int right_depth = depth(node->right, best);
        best = max(best, left_depth + right_depth);
        return max(left_depth, right_depth) + 1;
    }
};
