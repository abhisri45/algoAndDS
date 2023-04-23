#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int rowSize = grid.size();
        int colSize = grid[0].size();

        int maxCherry=0;
        int td = this->cherryPickupRecTD(0, 0, rowSize-1, colSize-1, grid);
        //int du = cherryPickupRecDU(rowSize-1, colSize-1, rowSize-1, colSize-1, grid);

        cout << "td: " << td << endl;

        maxCherry = max(maxCherry, td);

        return maxCherry;

    }

    int cherryPickupRecTD(int row, int col, int rowSize, int colSize, vector<vector<int>>& grid)
    {
       cout << row <<  " : : " << rowSize << " : : " << col << " : : " << colSize << endl;

        if(row>rowSize || row<0 || col>colSize || col<0)
        {
            cout << " 1: " << endl;
            return -1000000;
        }
        if(row=rowSize && col==colSize)
        {
             cout << " 2: " << endl;
            if(grid[row][col] == -1)
            {
                return -1000000;
            }
            if(grid[row][col] == 1)
            {
                //grid[row][col] = 1;
                return 1;
            }
            return grid[row][col];
        }

        if(grid[row][col] == -1)
        {
             cout << " 3: " << endl;
            return -1000000;
        }
        else
        {

            cout << " 4: " << grid[row][col] << endl;
            int down = grid[row][col] + cherryPickupRecTD(row+2, col, rowSize, colSize, grid);
            int right = grid[row][col] + cherryPickupRecTD(row, col+1, rowSize, colSize, grid);

            cout << "down: " << down << endl;
            cout << "right: " << right << endl;

            return max(down, right);
        }

    }

    int cherryPickupRecDU(int row, int col, int rowSize, int colSize, vector<vector<int>>& grid)
    {
        if(row>rowSize || row<0 || col>colSize || col<0)
        {
            return -1000000;
        }
        if(row==0 && col==0)
        {
            if(grid[row][col] == -1)
            {
                return -1000000;
            }
            if(grid[row][col] == 1)
            {
                grid[row][col] = 1;
                return 1;
            }
            return grid[row][col];
        }

        int down = grid[row][col] + cherryPickupRecDU(row-1, col, rowSize, colSize, grid);
        int right = grid[row][col] + cherryPickupRecDU(row, col-1, rowSize, colSize, grid);

        return max(down, right);

    }
};


int main()
{
   vector<vector<int>> grid = {{0,1,-1},{1,0,-1},{1,1,1}};
   Solution sol;
   sol.cherryPickup();
}
