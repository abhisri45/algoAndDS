#include<vector>
#include<iostream>

/*
https://www.geeksforgeeks.org/optimal-strategy-for-a-game-set-2/
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
int count = 0;

int fetchCoinToMaximize(std::vector<int> coinVec, int start, int end)
{
   count++;
   std::cout << "Number of calls to this function: " << count << std::endl;
   if(end == start+1)
   {
      return std::max(coinVec[start], coinVec[end]);
   }

   /*
   if(start > end)
   {
      return 0;
   }
   */

   // exponential solution.
   int max = std::max(coinVec[start] + std::min(fetchCoinToMaximize(coinVec, start+2, end), fetchCoinToMaximize(coinVec, start+1, end-1)), coinVec[end] + std::min(fetchCoinToMaximize(coinVec, start+1, end-1), fetchCoinToMaximize(coinVec, start, end-2)));


   return max;
}

int main()
{

   //std::vector<int> coinVec = {5,40,10,8,100,15};
   //std::vector<int> coinVec = {5, 3, 7, 10};
   //std::vector<int> coinVec = {8, 15, 3, 7 };
   //std::vector<int> coinVec = {2, 2, 2, 2};
   std::vector<int> coinVec = { 20, 30, 2, 2, 2, 10 };

   int maxNum = fetchCoinToMaximize(coinVec, 0, coinVec.size()-1);
   std::cout << "Maxiumum value coins: " << maxNum << std::endl;
}
