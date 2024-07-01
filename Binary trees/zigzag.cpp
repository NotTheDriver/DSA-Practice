class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     vector<vector<int>> ans;
     if(root==NULL){
         return ans;
     }   
     queue<TreeNode*> q;
     q.push(root);
     bool LeftToRight=true;
     while(!q.empty()){
         int size=q.size();
         vector<int> level(size);
         for(int i=0;i<size;i++){
             TreeNode* temp=q.front();
             q.pop();
             //to decide the traversal
             int index=LeftToRight? i : size-i-1;
             level[index]=temp->val;
             if(temp->left){
                 q.push(temp->left);
             }
             if(temp->right){
                 q.push(temp->right);
             }
         }
         LeftToRight=!LeftToRight;
         ans.push_back(level);
     }
    return ans;
    }
};