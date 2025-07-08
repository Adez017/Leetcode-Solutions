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
bool isLeaf(TreeNode* root){
    return !root->left && !root->right;
}
void addLeftBoundry(TreeNode* root,vector<int>&res){
    TreeNode* node = root->left;
    while(node){
        if(!isLeaf(node)){ // that means its not a leaf and exist in left boundry
            res.push_back(node->val);

        }
        if(node->left){//traverse the left boundry
            node = node->left;
        }
        else{ // if there doesnt a left we go to the right side of the left 
            node = node->right;
        }
    }
}
void addRightBoundry(TreeNode* root,vector<int>&res){
    TreeNode* curr = root->right;
    vector<int>temp; // why ? because we need the eleements in reverse so will 
    // store here and then from here will traverse back wards and store in our res;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->val);
        }
        if(curr->right){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}
void addLeaves(TreeNode* root,vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;    
    }
    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);


    
}
vector<int>BoundryTraversal(TreeNode* root){
    //Algorithm
    //1. take out all left boundry except leafs
    //2. take out all right boundry but in reverse except leafs
    //3. add all the leafs
    vector<int>res;
    if(root== nullptr) return res;
    if(!isLeaf(root))  res.push_back(root->val);
    addLeftBoundry(root,res);
    addLeaves(root,res);
    addRightBoundry(root,res);

}

int main(){

    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->right->left = new TreeNode(6);
    node->right->right = new TreeNode(7);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);
    node->left->right->left = new TreeNode(8);
    node->left->right->right = new TreeNode(9);
    vector<int>res = BoundryTraversal(node);
    for(auto it : res){
        cout<<it<<" ";
    }

}