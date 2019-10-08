/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//Find the sum of all left leaves in a given binary tree.
//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

int sumval = 0;

int sum(struct TreeNode* root, int isleftchild){
  
    if(root==NULL){
        return;
    }
    
    if(isleftchild){
        if (root->left == NULL && root->right == NULL){
            sumval+=root->val;
        }
    }
    sum(root->left,1);
    sum(root->right,0);
    
    return sumval;
}

int sumOfLeftLeaves(struct TreeNode* root){
    int sumofleaves = sum(root,0);
    sumval = 0;
    return sumofleaves;
}

