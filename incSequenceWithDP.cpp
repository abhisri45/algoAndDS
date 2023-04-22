#include<iostream>
#include<vector>

/*

Lis: As per the current sequence value is 8.

Use suffix approach i.e.

Lis with 1 element will always be 1, then start increasing array by 1 every time. Calculate the LIS(may be an array, just like vector) of newly added member by comparing it will all the elements after that(as we took suffix approach).
If the newly added value is smaller than any of the rest element, take the lis of that element(already calculated) and compare that with LIS of new member(caluclated till now). Update the newly added member's LIS only if the LIS compared
with is atleast >= to lis of the other element compared to newly added member's LIS. 

*/

int main()
{
   int maxLis = -1;
   //std::vector<int> v1{9, 5, 10, 6, 11, 12, 14, 13, 87, 88};
   std::vector<int> v1{1, 5, 6, 7, 15, 2, 3, 11, 12, 13, 14};
   std::vector<int> lis(v1.size(), 0);
   int v1Size = v1.size();
   std::cout << "Size of vector: " << v1Size << std::endl;
      

   for(int i= (v1Size -1); i>=0; i--)
   {
      if(i== (v1Size -1))
      {
            std::cout << "first element" << std::endl;
            lis[v1Size -1] = 1;
            continue;
      }

      for (int j=i+1; j<=(v1Size -1); j++)
      {
         //std::cout << i << std::endl;
         {
            if(v1[i] < v1[j])
            {
               if(lis[j] >= lis[i])
               {
                  lis[i] = lis[j] + 1;
               }
            }
         }

      }
      
   }

   
   for(std::vector<int>::iterator it = lis.begin(); it!=lis.end(); it++)
   {
      std::cout << "Member in array: " << *it << std::endl;
      if(maxLis < *it)
      {
         maxLis = *it;
      }
   }


   std::cout << "Max linear sequence for the given list: " << maxLis << std::endl;

   return maxLis;
}
