#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        if(root == nullptr) return {};
        vector<int>res;
        queue<pair<Node*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            int size =q.size();
            auto it=q.front();
            q.pop();
            Node* node = it.first;
            int line =it.second;
            if(mpp.find(line)==mpp.end()) mpp[line] = node->data;
            if(node->left!=nullptr){
                q.push({node->left,line-1});
            }
            if(node->right!= nullptr){
                q.push({node->right,line+1});
            }
        }
        for(auto it:mpp){
            res.push_back(it.second);
        }
        return res;
        
    }
};