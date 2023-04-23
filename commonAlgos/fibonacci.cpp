#include<vector>
#include<iostream>
/*


f[i] = f[i-1] +  f[i-2];

*/


int fibonacci(int n, std::vector<int> &vec)
{

   // Base Case: 1
   if (n < 1)
   {
      return 0;
   }
   // Base Case: 2
   if (n==1)
   {
      return 1;
   }
   
   // Relation
   if (vec[n - 1] != -1 && vec[n-2] != -1)
   {
      std::cout << n-1  <<  " " << vec[n - 1] << " and " << n-2 << " " << vec[n - 2] << std::endl;
      return vec[n - 1] + vec[n - 2];
   }
   else
   {
      std::cout << "Now calc fib for: " << n << std::endl;
      vec[n] = fibonacci(n-1, vec) + fibonacci(n-2, vec);
      std::cout << "calc fib num: " << vec[n] << " for n " << n << std::endl;
      return vec[n];
   }
   
}


int main()
{

int n = 13;
std::vector<int> vec(100, -1);

//std::vector<std::vector<int>> fibVec;
int finalNum = fibonacci(n, vec);
std::cout << "Finaly fibonacci of : " << n << " is "<< finalNum << std::endl;

}
