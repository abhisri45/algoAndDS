#include<vector>
#include<iostream>

struct Node {

   Node(int cost, int coinsReuqired):cost(cost), coinsReuqired(coinsReuqired), next(NULL)
   {
   }
   int cost;
int coinsReuqired;

   struct Node* next;
};

void addToList(struct Node* head, int cost, int coinsReuqired)
{
   while(head->next != NULL)
   {
      head = head->next;
   }
   head->next = new Node(cost, coinsReuqired);
   return;
}


int coinsToBeMelted(struct Node* node, int totalCoins)
{
   int totalAmount;
   if (totalCoins<=0)
   {
      return 0;
   }

   if(node == NULL)
   {
      return 0;
   }
   if(node->coinsReuqired>totalCoins)
   {
      return 0;
   }

   totalAmount =  std::max(node->cost + coinsToBeMelted(node->next, totalCoins - node->coinsReuqired), coinsToBeMelted(node->next, totalCoins));
   
   
   return totalAmount;
}

int main()
{
   //1: 2, 2, 2:5,3, 3: 7,4 , 4: 12, 12, 5:16,16 
   int numberOfCoins = 20;

   // 5 objects
   struct Node * head = new Node(2,2);
   addToList(head, 6,3);
   addToList(head, 8,4);
   addToList(head, 12,12);
   addToList(head, 30,16);
   
   struct Node * ptr = head;
   while(ptr != NULL)
   {
      std::cout << ptr->cost << " : " << ptr->coinsReuqired << std::endl;
      ptr=ptr->next;
   }
   
   int total = coinsToBeMelted(head, numberOfCoins);
   std::cout << "Total amount: " << total << std::endl;
}

