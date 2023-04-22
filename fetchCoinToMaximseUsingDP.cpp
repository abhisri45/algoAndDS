#include<vector>
#include<iostream>

/*

This is a 2 player game, in which one of them is myself and then there is another player.
As a rule we have to maximize the score by getting coins of higher valuations. Player can take out coin either from 
left most or right most. One of the player has to  take out first coin.

[5,40,10,8,100,15]

Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.
Note: The opponent is as clever as the user.

Let us understand the problem with few examples:  

5, 3, 7, 10 : The user collects maximum value as 15(10 + 5)
8, 15, 3, 7 : The user collects maximum value as 22(7 + 15)
Does choosing the best at each move gives an optimal solution? No. 
In the second example, this is how the game can be finished:

…….User chooses 8. 
…….Opponent chooses 15. 
…….User chooses 7. 
…….Opponent chooses 3. 
Total value collected by user is 15(8 + 7)
…….User chooses 7. 
…….Opponent chooses 8. 
…….User chooses 15. 
…….Opponent chooses 3. 
Total value collected by user is 22(7 + 15)
So if the user follows the second game state, the maximum value can be collected although the first move is not the best. 

*/

int count=0;

int fetchCoinToMaximize(std::vector<int> coinVec, int start, int end, std::vector<std::vector<int>> table)
{
   
   count++;
   std::cout << "Number of calls to this function: " << count << std::endl;

   //if(end - start = 1)
   /*
   if(start > end)
   {
      std::cout << "Condition 0" << std::endl;
      return 0;
   }
   */

   //Base case: Since coins are even and in case of last 2 coins, I am going to play and will make sure than I will get maximum out of 2.
   //Last coin will be taken by other player and will not be added in max score.
   if(end == start+1)
   {
      return std::max(coinVec[start], coinVec[end]);
   }
   
   if(table[start][end] != -1)
   {
      std::cout << "Condition 1" << std::endl;
      return table[start][end];
   }
   if(table[start+2][end] != -1 && table[start+1][end-1] != -1 && table[start+1][end-1] && table[start][end-2])
   {
      std::cout << "Condition 2" << std::endl;
      return std::max(coinVec[start] + std::min(table[start+2][end], table[start+1][end-1]), coinVec[end] + std::min(table[start+1][end-1], table[start][end-2]));
   }

   // exponential solution.
   table[start][end] = std::max(coinVec[start] + std::min(fetchCoinToMaximize(coinVec, start+2, end, table), fetchCoinToMaximize(coinVec, start+1, end-1, table)), coinVec[end] + std::min(fetchCoinToMaximize(coinVec, start+1, end-1, table), fetchCoinToMaximize(coinVec, start, end-2, table)));


   return table[start][end];
}

int main()
{

   //std::vector<int> coinVec = {5,40,10,8,100,15};
   //std::vector<int> coinVec = {5, 3, 7, 10};
   //std::vector<int> coinVec = {8, 15, 3, 7 };
   //std::vector<int> coinVec = {2, 2, 2, 2};
   std::vector<int> coinVec = { 20, 30, 2, 2, 2, 10 };

   std::vector<std::vector<int>> table(coinVec.size()+1, std::vector<int>(coinVec.size()+1, -1));

   for(int i=0; i < coinVec.size()+1; i++)
   {
      for(int j=0; j < coinVec.size()+1; j++)
      {
         std::cout << table[i][j] << std::endl ;
      }
   }

   int maxNum = fetchCoinToMaximize(coinVec, 0, coinVec.size()-1, table);
   std::cout << "Maxiumum value coins: " << maxNum << std::endl;
}
