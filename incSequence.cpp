#include<iostream>
#include<cstring>


int findLargestElement(int *p, int len)
{
   int largest = 0;
   if(p == NULL)
   {
      return 0;
   }
      
   for(int l=0; l<len; l++)
   {
      if(p[l] > largest)
      {
         largest = p[l];
      }
   }

   return largest;
}

int main()
{
   //int arr[] = {10, 9, 5, 11, 13, 1, 2, 3, 4};
   int arr[] = {13, 1, 2, 3, 5, 10, 4, 3, 6, 7, 1, 11};

   int numOfElements = sizeof(arr)/sizeof(int);
   std::cout << "numOfElements: " << numOfElements << std::endl;

   int *ptr = new int [numOfElements];
   std::cout << "sizeof ptr: " << sizeof(ptr) << std::endl;
   std::fill(ptr, ptr + numOfElements, 1);
   std::cout << "ptr[0]: " << ptr[0] << std::endl;

   for(int j=1; j < numOfElements; j++)
   {
      for(int i=0; i<j; i++) 
      {
         std::cout << "11111 i: " << i << " and j: " << j << std::endl;
         if(arr[j] > arr[i]) 
         {
            std::cout << "22222 " << std::endl;
            if((ptr[i] + 1) > ptr[j])
            {
               std::cout << "333333 " << std::endl;
               ptr[j] = ptr[i] + 1;
               std::cout << "444444 " << std::endl;
            }
         }   
      }
   }

   for(int k=0; k<numOfElements; k++)
   {
      std::cout << "ptr val: " << ptr[k] << std::endl;
   }

   std::cout << findLargestElement(ptr, numOfElements) << std::endl;
   return findLargestElement(ptr, numOfElements);
}
