#include<iostream>

int bionomialCoeff(int n, int k)
{
   if( k == n  || k == 0 )
   {
      return 1;
   }
   return bionomialCoeff(n - 1, k - 1) + bionomialCoeff(n - 1, k);

}

int main()
{
   int bioCoeff = 0;
   bioCoeff = bionomialCoeff(8,8);
   std::cout << bioCoeff << std::endl;
}

