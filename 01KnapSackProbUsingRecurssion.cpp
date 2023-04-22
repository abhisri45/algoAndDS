#include<iostream>

int knapsack(int n, int wt, int *val, int *wts)
{
   if (n==0 || wt==0)
   {
      return 0;
   }
   
   if(wts[n-1] <= wt)
   {
      
      return std::max(val[n-1] + knapsack(n-1, wt - wts[n-1], val, wts), knapsack(n-1, wt, val, wts));
   }
   else
   {
      return knapsack(n-1, wt, val, wts);
   }
}

int main()
{
   int wtCapacity = 50;
   int values[] = {100, 212, 10, 150, 5, 30};
   int wts[] =  {10, 12, 30, 15, 51, 20};
   int n = sizeof(values)/sizeof(int);

   int maxValues = knapsack(n, wtCapacity, values, wts);
   std::cout << "maxValues: " << maxValues << std::endl;
}

