#include<iostream>
#include<vector>

/*

Finding the length of connected cells of 1s (regions) in an matrix of Os and 1s
*/

using namespace std;


class CountOnes
{
   public:

   bool isValidPosition(int row, int col, int rowSize, int colSize)
   {
      cout << row  <<  " : " <<  col << endl;
      cout << rowSize  <<  " : " <<  colSize << endl;
      
      if(row>=rowSize || col>=colSize || row<0 || col<0)
      { 
         return false;
      }

      return true;
   }

   bool isValid(int row, int col, int rowSize, int colSize)
   {

      /*
      if(row>=rowSize || col>=colSize || row<0 || col<0)
      {
         return false;
      }
      */

      if(this->inp[row][col])
      {
         return true;
      }

      return false;
   }

   int countOnes()
   {
      int rowSize = this->inp.size();
      int colSize = this->inp[0].size();

      int globalMax=0;
      for(int i=0; i<rowSize; i++)
      {
         for(int j=0; j<colSize; j++)
         {
            int max = 0;
            if(this->inp[i][j])
            {
               cout << "BREAK" << endl;
               //cout << i  <<  " : " <<  j << endl;
               getMaxBlockSize(i, j, rowSize, colSize, max);
            }

            cout << "Local Max: " << max << ", for i, "<< i << " j " << j << endl;

            if(globalMax<max)
            {
               globalMax = max;
            }
         }
      }

      return globalMax;
   }

   void getMaxBlockSize(int row, int col, int rowSize, int colSize, int &max)
   {
      //if(!isValidPosition(row, col, rowSize, colSize))
      if(row>=rowSize || row<0)
      {
         cout << "Conditional Return 0" << endl;
         return;
      }

      if(col>=colSize || col<0)
      {
         cout << "Conditional Return 1" << endl;
         return;
      }

      

      if(this->inp[row][col] == 0)
      {
         cout << "Conditional Return 2" << endl;
         return;
      }

      this->inp[row][col] = 0;

      max++;

      //Downward 
      getMaxBlockSize(row+1, col, rowSize, colSize, max); 
      
      //1 in next col
      getMaxBlockSize(row, col+1, rowSize, colSize, max);
      
      //1 Diagnolly right downward
      //getMaxBlockSize(row+1, col+1, rowSize, colSize, max);    
      
      //1 Diagnolly left upwards
      // getMaxBlockSize(row-1, col-1, rowSize, colSize, max);    
      
      //1 upward
      getMaxBlockSize(row-1, col, rowSize, colSize, max);    
      
      //1 leftside
      getMaxBlockSize(row, col-1, rowSize, colSize, max);    
      
      //1 diagnolly right upward
      //getMaxBlockSize(row-1, col+1, rowSize, colSize, max);
      
      //1 diagnolly downward left
      //getMaxBlockSize(row+1, col-1, rowSize, colSize, max);       
      

   }

   CountOnes(std::vector<std::vector<int> > inp):inp(inp)
   {
      
   }

   std::vector<std::vector<int> > inp;

};


int main()
{
   std::vector<std::vector<int> > inp0 = {{1,1,0,0,0}, {0,1,1,0,0}, {0,0,1,0,1}, {1,0,0,0,1}, {0,1,0,1,1}};
   std::vector<std::vector<int> > inp1 = {{0,0,1,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,1,1,0,1,0,0,0,0,0,0,0,0}, {0,1,0,0,1,1,0,0,1,0,1,0,0}, {0,1,0,0,1,1,0,0,1,1,1,0,0}, {0,0,0,0,0,0,0,0,0,0,1,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,0,0,0,1,1,0,0,0,0}};
   //std::vector<std::vector<int> > inp1 = {{1,1,1,1,1}, {1,1,1,0,0}, {1,0,1,0,1}, {1,0,0,0,1}, {1,1,0,1,1}};

   int finalMax = CountOnes(inp1).countOnes();
   std::cout << "Group with max 1s: " << finalMax << std::endl;;
}

