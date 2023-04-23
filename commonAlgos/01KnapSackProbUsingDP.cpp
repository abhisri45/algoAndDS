#include<iostream>

//using namespace std;

int main()
{
   
   int values[] = {100, 32, 45, 133, 121};
   int wts[] = {5, 7, 8, 2, 4};

   int wtLimit = 12;

   int num = sizeof(values)/sizeof(int);
   std::cout << "Value of num: " << num << std::endl;

   int mat[num+1][wtLimit+1];

   std::memset(mat,0, sizeof(int) * (num+1) * (wtLimit+1));
   for(int rows=0; rows<=num; rows++)
   {
      for(int wL=0; wL<=wtLimit; wL++)
      {
         std::cout << mat[rows][wL] << std::endl;
      }
   }

   for (int rows=0; rows <= num; rows++)
   {
      for(int wL=0; wL <= wtLimit; wL++)
      {
         if(rows == 0 ||  wL == 0)
         {
            mat[rows][wL] = 0;
         }
         else if (wts[rows-1] <= wL)
         {
            mat[rows][wL] = std::max(values[rows-1] + mat[rows-1][wL - wts[rows-1]], mat[rows - 1][wL]); 
         }
         else
         {
            mat[rows][wL] = mat[rows-1][wL];
         }

      } 
   }

  std::cout << mat[num][wtLimit] << std::endl ; 
  std::cout << mat << std::endl ; 

}
