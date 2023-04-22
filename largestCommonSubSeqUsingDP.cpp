#include<iostream>
#include<vector>
#include<string>

/*

Algo says we can start from left or right, although in the current case we moved from right to left.

Move both string pointers to left if character match else get maximum of either moving s1 or s2 to left.

Base case 

   if(len1 == 0 || len2 == 0)
   {
      return 0;
   }

 

*/
int largestCommonSubSeq(std::string s1, std::string s2, int len1, int len2, std::vector<std::vector<int>> &vec)
{
   
   //std::cout << len1 << " : " << len2 << std::endl;

   if(len1 == 0 || len2 == 0)
   {
      /*
      if (len1 == 0)
      {
         for(int j=0; j<=len2; j++)
         {
            vec[0][j] = 0;
            return vec[0][j];
         }
      }

      if (len2 == 0)
      {
         for(int i=0; i<=len1; i++)
         {
            vec[i][0] = 0;
            return vec[i][0];
         }
      }
      */
      return 0;
   }
  

 
   if(s1[len1 -1] == s2[len2 -1])
   {
      std::cout << "Character matched: " << len1 -1 << " and " << len2 -1 << std::endl;
      std::cout << s1[len1 -1] << " and " << s2[len2 -1] << std::endl;
      //Decrement both if characters match.
      len1--;
      len2--;

      // if required columns are already present then simply return them else calculate
      if (vec[len1][len2] != -1)
      {
         return 1 + vec[len1][len2];
      }
      else
      {
         vec[len1+1][len2+1] = 1 + largestCommonSubSeq(s1, s2, len1, len2, vec);
         return vec[len1+1][len2+1];
      }
   }
   else
   {

      int redL1 = len1 - 1;
      int redL2 = len2 - 1;
      
      if(vec[redL1][len2] != -1 && vec[len1][redL2] != -1)
      {
         return std::max(vec[redL1][len2], vec[len1][redL2]);
      }

      // Now we have 2 cases where either we keep the current character from s1 or s2 and then move the next one.
      // This is of exponential order. 
      vec[len1][len2] = std::max(largestCommonSubSeq(s1, s2, len1, redL2, vec), largestCommonSubSeq(s1, s2, redL1, len2, vec));
      return vec[len1][len2];
   }
}

int main()
{
   
   std::string str1("Srivastava");
   std::string str2("Srinivas");
   //std::string str2("Siypztamqva");
   //std::string str2("Jnoqlmevzubastawcdva");
   //std::string str2("abhishek");
  
   std::vector<std::vector<int>> vec(str1.size() +1, std::vector<int>(str2.size()+1, -1));

   /*
   for(int i=0; i<=str1.size(); i++)
   {
      for(int j=0; j<=str2.size(); j++)
      {
         vec[i][j] = -1;
      }
   } 
   */
   int maxCommonLen = largestCommonSubSeq(str1, str2, str1.size(), str2.size(), vec);
   std::cout << "Max common length: " << maxCommonLen << std::endl;

}
