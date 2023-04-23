#include<iostream>

//LCS problem using DP.

// Logic remains same as recursion problem i.e. if character matches, length of both strings will be removed +1
// and if it does not matches then either take left or above one, which comes out the be bigger value.


int main()
{
   char const * p1 = "abcdefgh";
   char const * p2 = "lmnqpymn";

   int p1Len = strlen(p1);
   int p2Len = strlen(p2);
   int arr[p1Len+1][p2Len+1];
   std::fill(arr[0], arr[0] + ((p1Len + 1)*(p2Len + 1)), 0);
 

   for(int i=1; i<=p1Len; i ++)
   {
      for(int j=1; j<=p2Len; j++)
      {
         if(p1[i-1] == p2[j-1])
         {
            // if character matches 
            arr[i][j] = arr[i-1][j-1] + 1;
         }
         else
         {
            arr[i][j] = std::max(arr[i-1][j], arr[i][j-1]);
         }
      }
   }

   std::cout << "Length of string p1: " << p1Len << " and length of string p2: " << p2Len << std::endl;


   std::cout << "Largest substring sequence: " << arr[p1Len][p2Len] << std::endl;


}
