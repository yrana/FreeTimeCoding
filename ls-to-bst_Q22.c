/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct ListNode* midNode(struct ListNode* left, struct ListNode* right){
    struct ListNode* slow = left;
    struct ListNode* fast = left;
    
    if(slow==NULL || slow==right){
        return NULL;
    }
    
    if (slow->next == right || slow->next== NULL){
        return left;
    }
    
    else{
        while(fast!=right && fast!= NULL){
            if (fast->next!= NULL && fast->next!=right){
                fast = fast->next->next;
                slow= slow->next;
            }
            else{
                break;
            }
        }
        return slow;
            
    }
}


struct TreeNode* sorted(struct ListNode* left, struct ListNode* right){
    struct ListNode* mid = midNode(left, right);
    
    
        
    struct TreeNode* head_t = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    
    if(mid==NULL){
        head_t = NULL;
        return head_t;
    }
    
    if(mid == left){
        head_t->val = left->val;
        head_t->left = NULL;
        head_t->right = NULL;
        return head_t;
    }
    
    
    head_t->val = mid->val;

    
    head_t->left = sorted(left, mid);
    
    head_t->right = sorted(mid->next, right);
    
    return head_t;
    
   
    
}


struct TreeNode* sortedListToBST(struct ListNode* head){
    
    struct TreeNode* ret = sorted(head, NULL);
    
      
    return ret;

}

