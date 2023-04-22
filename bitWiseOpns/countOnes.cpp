#include<iostream>
#include<stdint.h>

using namespace std;

class Solution {
public:
    int hammingWeight1(uint32_t n) {
        
        int loopCount = sizeof(n)*8;
        uint32_t countOfOnes = 0;
        uint32_t checkForOnes = 1;
        
        
        
            
        while(loopCount)
        {
            if(n&checkForOnes)
            {
                
                loopCount++;
                countOfOnes++;
                
            }
            if(!(n&UINT_MAX))
            {
                break;
            }
            
            checkForOnes = checkForOnes<<1;
            loopCount--;
        }
        
        
        return countOfOnes;
        
    }


   int hammingWeight(uint32_t n) {
        
        int loopCount = sizeof(n)*8;
        uint32_t countOfOnes = 0;
        uint32_t checkForOnes = 1;
        
        
        
            
        while(n)
        {
            if(n&checkForOnes)
            {
               
                countOfOnes++;
                
            }
                        
            n = n>>1;
        }
        
        
        return countOfOnes;
        
    }

};

int main()
{
   Solution sol = Solution();

   uint32_t output = sol.hammingWeight(9);
   cout << output << endl;

   return 0;

}
