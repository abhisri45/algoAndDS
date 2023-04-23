#include<iostream>

//LCS problem using recurssion.

int findCommonSubStrLen(char const* p1, char const* p2, int lenp1, int lenp2)
{
   if(lenp1 == 0 or lenp2 == 0)
   {
      return 0;
   }

   if (p1[lenp1 - 1] == p2[lenp2 - 1])
   {
      // if last character matches increase the length of the subsequence by 1 and simply remove that character.
      return 1 + findCommonSubStrLen(p1, p2, (lenp1 - 1), (lenp2 - 1));
   }

   else
   {
      // End characters don't match so we will try remove end character from one of the string, we will do this for both
      // strings and will then take the subsequence which will result in max length.
      return std::max(findCommonSubStrLen(p1, p2, (lenp1 - 1), lenp2), findCommonSubStrLen(p1, p2, lenp1, (lenp2 - 1)));
   }
}


int main()
{
   char const * p1 = "abcdefgh";
   char const * p2 = "adexyzglmnqhymn";

   int p1Len = strlen(p1);
   int p2Len = strlen(p2);

   std::cout << "Length of string p1: " << p1Len << " and length of string p2: " << p2Len << std::endl;

   int largestSubString = findCommonSubStrLen(p1, p2, p1Len, p2Len);

   std::cout << "Largest substring sequence: " << largestSubString << std::endl;


}
