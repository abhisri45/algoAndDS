#include<iostream>

/*
   Que: Reverse bits of a given unsigned integer.

   Input :   43261596
   Output: 964176192

   The binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 whose binary representation is 00111001011110000010100101000000

 
*/

int main()
{
   unsigned int inp = 43261596;
   unsigned int bit = 0;
   unsigned  out = 0;

   /*
   for(int i=0; i<31; i++)
   {
      bit = inp & (1 << i);
      out |= bit << (31 - i);  
   }
   */

   for(int i=0; i<31; i++)
   {
      if(inp & (1 << i))
      {
         out |= 1 << (31 - i);  
      }
            
   }


   std::cout << "Reversed output: " << out << std::endl;   

}


