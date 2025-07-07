#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> res;
    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            level.push_back(node->val);
        }
        res.push_back(level);
    }
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    vector<int> res;
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->right);
        if (!node->left && !node->right)
            res.push_back(node->val);
        st.pop();
    }
    return res;
}

void postOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

vector<int> Iterative_postOrder(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    if (root == nullptr)
        return res;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st2.push(root);
        st1.pop();
        if (root->left != nullptr)
            st1.push(root->left);
        if (root->right != nullptr)
            st1.push(root->right);
    }
    while (!st2.empty())
    {
        res.push_back(st2.top()->val);
        st2.pop();
    }
    return res;
}
vector<int> Iterative_postOrder_single_stack(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty() || root != nullptr)
    {
        if (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                res.push_back(temp->val);
                while ((!st.empty()) && (temp = st.top()->right))
                {
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->val);
                }
            }
        }
    }
}
void ThreeInOnetraversal(TreeNode *root)
{
    stack<pair<TreeNode *, int>> st;
    vector<int> inorder, preorder, postorder;
    TreeNode *curr = root;
    if (curr == nullptr)
        return;
    st.push({curr, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        { // if the value is 1 I.E preorder
            // add to the preorder
            // increment the count
            // push again
            preorder.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left != nullptr)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        { // that is inorder
            // same as above
            inorder.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right != nullptr)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            postorder.push_back(it.first->val);
        }
    }
    cout << "The PreOrder Traversal: ";
    for (auto it : preorder)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "The Inoreder Traversal: ";
    for (auto it : inorder)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "The PostOrder Traversal: ";
    for (auto it : postorder)
    {
        cout << it << " ";
    }
}
vector<int> Iterative_Preorder(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    if (root == nullptr)
        return {};
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
        res.push_back(node->val);
    }
    return res;
}
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    bool rev = true;
    if (root == nullptr)
        return ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> mid;
        for (int i = 0; i < size; i++)
        {
            if (!rev)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                mid.push_back(node->val);
            }
            else
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
                mid.push_back(node->val);
            }
        }
        ans.push_back(mid);
        rev = !rev;
    }
    return ans;
}
int main()
{
    TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);
    levelOrder(node);
    // inorderTraversal(node);

    // postOrder(node);
    // vector<int>up = Iterative_postOrder_single_stack(node);
    // for(int i=0;i<up.size();i++){
    //     cout<<up[i]<<" ";
    // }
    // ThreeInOnetraversal(node);
    // vector<int>res = Iterative_Preorder(node);
    // for(auto it : res){
    //     cout<<it<<" ";
    // }
}