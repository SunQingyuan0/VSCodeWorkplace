#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if(root==nullptr)return true;
        int count=0;
        if(root->left==nullptr||(root->val)>(root->left->val))
        {
            count++;
        }
        if(root->right==nullptr||(root->val)<(root->right->val))
        {
            count++;
        }
        if(isValidBST(root->left))
        {
            count++;
        }
        if(isValidBST(root->right))
        {
            count++;
        }
        if(count==4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};