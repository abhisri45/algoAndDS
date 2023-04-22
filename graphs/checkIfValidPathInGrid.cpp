#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

/*

https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.


Example 1:


Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).


Example 2:


Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)

Example 3:

Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).


*/

class Solution {
public:
    
    bool findPath(int row, int col, std::vector<std::vector<int>>& grid, std::unordered_map<int, std::set<std::pair<int, int>>> route, std::vector<std::vector<bool>> visited, int rowSize, int colSize)
    {
        if((row == rowSize-1) && (col == colSize-1))
        {
            return true;
        }
        
        visited[row][col] = true;
        
        int mov = grid[row][col];
        
        std::set<std::pair<int, int>> pairSet = route[mov];
        
        std::set<std::pair<int, int>>::iterator it = pairSet.begin();
        
        
        for(;it!=pairSet.end(); it++)
        {
            
            int newRow = row + it->first;
            int newCol = col + it->second;
            
            int d1 = -(it->first);
            int d2 = -(it->second);
            
            
            
            
            if(newRow>=0 && newCol>=0 && newRow<=(rowSize-1) && newCol<=(colSize-1) && visited[newRow][newCol]==false)
            {
               
                int newMov = grid[newRow][newCol];
                std::set<std::pair<int, int>>::iterator setIt = route[newMov].find(std::pair<int, int>(d1, d2));
            
                bool sourceMatched = false;
            
                if(setIt != route[newMov].end())
                {
                    sourceMatched = true;
                }
            
            
                if(sourceMatched==true && findPath(newRow, newCol, grid, route, visited, rowSize, colSize))
                {
                    return true;
                }
            }
            
        }
        
        return false;
    }
    
    
    bool hasValidPath(std::vector<std::vector<int>>& grid) {
        
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        std::vector<std::vector<bool>> visited(rowSize, std::vector<bool>(colSize, false));    
        
        std::unordered_map<int, std::set<std::pair<int, int>>> route;
          
        // Possible states(of displacement) for connectors as per the pictures
        route.insert(std::pair<int, std::set<std::pair<int, int>>>(1, {{0,1}, {0,-1}}));
        route.insert(std::pair<int, std::set<std::pair<int, int>>>(2, {{1,0}, {-1,0}}));
        route.insert(std::pair<int, std::set<std::pair<int, int>>>(3, {{1,0}, {0,-1}}));
        route.insert(std::pair<int, std::set<std::pair<int, int>>>(4, {{1,0}, {0,1}}));
        route.insert(std::pair<int, std::set<std::pair<int, int>>>(5, {{-1,0}, {0,-1}}));
        route.insert(std::pair<int, std::set<std::pair<int, int>>>(6, {{0,1}, {-1,0}}));
         
            
        bool result = findPath(0,0, grid, route, visited, rowSize, colSize);
        
        
        
        return result;
        
    }
};

int main()
{
   Solution sol = Solution();
   std::vector<std::vector<int>> v1{{2,4,3},{6,5,2}};
   std::cout << sol.hasValidPath(v1) << std::endl;
   std::vector<std::vector<int>> v2{{1,2,1},{1,2,1}};
   std::cout << sol.hasValidPath(v2) << std::endl;
   std::vector<std::vector<int>> v3{{1,1,2}};
   std::cout << sol.hasValidPath(v3) << std::endl;


}
