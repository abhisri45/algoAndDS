#include<iostream>
using namespace std;


class AVLTree
{
   
   public:
   AVLTree(int key):key(key),height(1),left(NULL),right(NULL)
   {
   }

   int getHeight(AVLTree *node)
   {
      if (node == NULL)
      {
         return 0;
      }
      return node->height;
   }

   AVLTree* addNodeToBst(AVLTree* node, int key)
   {
      if(node == NULL)
      {
         return new AVLTree(key);
      }
      if(key<node->key)
      {
         node->left = this->addNodeToBst(node->left, key);
      }
      else if(key>node->key)
      {
         node->right = this->addNodeToBst(node->right, key);
      }
      else
      {
         return NULL;
      }
 

       
      //if(node->left && node->right) 
      node->height = 1 + std::max(this->getHeight(node->left), this->getHeight(node->right)); 
      
     
      //left - left
      int val = checkBalance(node);
      if (val > 1)
      {

         if(key < node->left->key)
         {
            return this->rightRotation(node);
         }
      }
      //right -right
      if(val < -1)
      {
         if(key > node->right->key)
         {
            return this->leftRotation(node);
         }
      }

      // left - right
      if(val > 1 && key > node->left->key )
      {
//         node->left = this->leftRotation(node);
         return this->rightRotation(node);
      }
      
/*      
      // right - left
      if(val < -1 && key < node->right->key)
      {
         node->right = this->rightRotation(node);
//         return this->leftRotation(node);
      } 
*/ 
      return node;
   }

   int checkBalance(AVLTree * node)
   {

      return this->getHeight(node->left) - this->getHeight(node->right);

   }

   
   AVLTree * rightRotation(AVLTree *node)
   {
      AVLTree *leftChild = node->left;
      AVLTree *temp = leftChild->right;
      leftChild->right = node;
      node->left = temp;

      node->height = 1 + std::max(this->getHeight(node->left), this->getHeight(node->right));
      leftChild->height = 1 + std::max(this->getHeight(leftChild->left), this->getHeight(leftChild->right));

      return leftChild;
      
   }

   AVLTree * leftRotation(AVLTree *node)
   {  
       AVLTree *rightChild = node->right;
       AVLTree *temp = rightChild->left;
       rightChild->left = node;
       node->right = temp;

     rightChild->height = 1 + std::max(this->getHeight(rightChild->left), this->getHeight(rightChild->right));
      node->height = 1 + std::max(this->getHeight(node->left), this->getHeight(node->right));

      return rightChild;
      
   }

   void inorderTraversal(AVLTree *node)
   {
      if(node == NULL)
      {
         return;
      }
      this->inorderTraversal(node->left);
      std::cout << node->key << std::endl;
      this->inorderTraversal(node->right);
   }


   
   int key;
   int height;
   AVLTree *left;
   AVLTree *right;


};



int main()
{
   
   int keyRoot = 20;
   int key1 = 10;
   int key2 = 18;
   int key3 = 22;
   int key4 = 15;
   int key5 = 25;
   int key6 = 11;
   int key7 = 16;
   int key8 = 23;
   int key9 = 29;
   int key10 = 32;
   int key11 = 12;
   int key12 = 2;

   AVLTree * rootNode = new AVLTree(keyRoot);
   rootNode->inorderTraversal(rootNode);
   std::cout << "======================"<< std::endl;
   rootNode->addNodeToBst(rootNode, key1);
   rootNode->addNodeToBst(rootNode, key2);
   rootNode->addNodeToBst(rootNode, key3);
   rootNode->addNodeToBst(rootNode, key4);
   rootNode->addNodeToBst(rootNode, key5);
   rootNode->addNodeToBst(rootNode, key6);
   rootNode->addNodeToBst(rootNode, key7);
   rootNode->inorderTraversal(rootNode);
   rootNode->addNodeToBst(rootNode, key8);
   rootNode->addNodeToBst(rootNode, key9);
   rootNode->addNodeToBst(rootNode, key10);
   rootNode->addNodeToBst(rootNode, key11);
   rootNode->addNodeToBst(rootNode, key12);

   std::cout << "======================"<< std::endl;
   rootNode->inorderTraversal(rootNode);
   
}
