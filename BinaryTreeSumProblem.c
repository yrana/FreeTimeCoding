/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding //up all the values along the path equals the given sum.

bool haspath(struct TreeNode* root, int sum, int temp){  
    
    if(root==NULL){
        return false;
    }
    
    temp+=root->val;
    
    if(temp==sum){
        if(root!=NULL){
            if (root->left==NULL && root->right==NULL){
                return true;
            }
        }
    }
    
    
    if(haspath(root->left,sum,temp) || haspath(root->right,sum,temp)){
        return true;   
    }
  
    return false;
    
}

bool hasPathSum(struct TreeNode* root, int sum){
    
    int temp=0;
    if (root==NULL || (root->val==sum && (root->left!=NULL || root->right!=NULL))){
        return false;
    }

    if(haspath(root, sum, temp)){
        return true;
    }
    return false;
}

