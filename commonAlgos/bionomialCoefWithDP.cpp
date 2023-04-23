#include<iostream>

int bionomialCoeff(int n, int k)
{
   int buff[n+1][k+1];
   /*
   for(int j=0; j <=k ; j++)
   {
      buff[0][j] = 0;
   }
   for(int i=0; i <=n ; i ++)
   {
      buff[i][0] = 1;
   }
   */
   
   for(int i=0; i<=n; i++)
   {
      for(int j=0; j<=std::min(i,k); j++)
      {
         if(j==0 || j==i)
         {
            buff[i][j] = 1;
         }
         else
         {
            buff[i][j] = buff[i-1][j-1] + buff[i-1][j];
         }
      }
   }

  return buff[n][k]; 
}

int main()
{
   int bioCoeff = 0;
   bioCoeff = bionomialCoeff(8,2);
   std::cout << bioCoeff << std::endl;
}

