#include<iostream>
#include<stack>
#include<queue>
/*

   Find the node with largest weight.

*/

struct TreeNode {

TreeNode(int key):key(key),left(NULL), right(NULL)
{
}


int key;

struct TreeNode* left;
struct TreeNode* right;
};

int findHightestNode(struct TreeNode* root)
{
   int max=0;
   struct TreeNode* node = root;

   std::stack<struct TreeNode*> stPtr;
   while(1)
   {
      while(node)
      {
         std::cout << node->key << std::endl; 
         stPtr.push(node);
         if(node->key > max)
         {
            max = node->key;
         }
         node = node->left;
      }
      if(stPtr.empty())
      {
         break;
      }
      struct TreeNode* temp = stPtr.top();
      stPtr.pop();
      node = temp->right;
   }
   
      
   return max;
}



int main()
{

   struct TreeNode * root = new TreeNode(5);
   root->left = new TreeNode(8);
   root->right = new TreeNode(2);
   root->right->left = new TreeNode(6);
   root->right->right = new TreeNode(21);
   root->left->left = new TreeNode(19);
   root->left->left->left = new TreeNode(20);
   root->left->right = new TreeNode(11);
   root->left->left->left->right = new TreeNode(13);

   

   int maxNode = findHightestNode(root);
   std::cout << "MAx Node: " << maxNode << std::endl;   
   
}
