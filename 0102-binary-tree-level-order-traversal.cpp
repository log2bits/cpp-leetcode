class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> result;
        stack<pair<int, TreeNode*>> st;

        st.push({0, root});
        while (!st.empty()) {
            auto [level, node] = st.top();
            st.pop();

            if (static_cast<int>(result.size()) == level) result.resize(level + 1);
            result[level].push_back(node->val);

            if (node->right != nullptr) st.push({level + 1, node->right});
            if (node->left != nullptr) st.push({level + 1, node->left});
        }
        return result;
    }
};
