#include<iostream>

using namespace std;


struct TreeNode 
{
    TreeNode(char data):data(data), left(NULL), right(NULL)
    {
        
    }
    char data;
    TreeNode* left;
    TreeNode* right;
};


TreeNode * createTreeFromExpr(int & i, string expr)
{
   TreeNode * root = new TreeNode(expr[i]);
   cout << "data: " << root->data << endl;

   if(i==expr.size()-1)
   {
      return root;
   }

   i++;
   if(expr[i] == '?')
   {
      i++;
      root->left = createTreeFromExpr(i, expr);

      i++;
      root->right = createTreeFromExpr(i, expr);
      
      return root;
   }

   else
   {
      return root;
   }
   
}

void printTree(TreeNode * ptr)
{
   if(ptr == NULL)
   {
      return ;
   }
   cout << ptr->data << endl;
   printTree(ptr->left);
   printTree(ptr->right);
   
}

int main()
{
      string s1= "a?b:c";
      string s2= "a?b?c:d:e?f:g";
      int i=0;
      //TreeNode * ptr = createTreeFromExpr(i, s1);
      //printTree(ptr);
      cout << "New Tree" << endl;
      TreeNode * ptr2 = createTreeFromExpr(i, s2);
      printTree(ptr2);
}
