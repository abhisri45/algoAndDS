#include<iostream>
#include<cstring>
#include<vector>


//https://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming

int binSearch(std::vector<int> & a, int num)
{
   int i = 0;
   //std::vector<int>::iterator itr = a.begin();
   while(num > a[i])
   {
      i++;
   }


   std::cout << "Value of num: " << num << std::endl;
   std::cout << "Value of a[i] to be replaced: " << a[i] << " and i: "<< i << std::endl;
   return i;
}

int main()
{

   std::vector<int> incV; 
   //int arr[] = {10, 9, 5, 11, 13, 1, 2, 3, 4};
   int arr[] = {13, 1, 2, 3, 5, 10, 4, 3, 6, 7, 1, 11};

   int numOfElements = sizeof(arr)/sizeof(int);
   std::cout << "numOfElements: " << numOfElements << std::endl;

   int *ptr = new int [numOfElements];
   std::fill(ptr, ptr + numOfElements, 1);

   for(int j=0; j < numOfElements; j++)
   {
      std::cout << "Value of arr[j]: " << arr[j] << " and arr[j -1]: " << arr[j -1] << std::endl;
      if( j==0 || (arr[j] > incV[incV.size() - 1]) )
      {
         incV.push_back(arr[j]);
         continue;
         
      }
      /*
      if((arr[j] > arr[j - 1]) )
      {
         incV.push_back(arr[j]);
         continue;
      }
      */
      else
      {
         int idxToBeReplaced = binSearch(incV, arr[j]);
         std::cout << "idxToBeReplaced " << idxToBeReplaced << std::endl;
         incV[idxToBeReplaced] = arr[j];
      }

   }
   std::cout << "Size of vector: " << incV.size() << std::endl;
   for(int p=0; p<incV.size(); p++)
   {
      std::cout << "vector element i: " << p << " corresponding value: " << incV[p] << std::endl;
   }

}
