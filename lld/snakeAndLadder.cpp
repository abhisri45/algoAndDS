#include<iostream>

using namespace std;


class SnakeAndLadderGame
{
   public:
   SnakeAndLadderGame(std::vector<std::string> &playerNames, Dice  &dice, )
   {
   }

   std::pair<int, GameStateEnum> rollDice()
   {
      return board->rollDice();
   }

   void playGame()
   {
      while(1)
      {
         foreach(playerState: gameState->state)
         {
            while(1)
            {
               int playerScore = 0;
               cout << "Player " << playerState.first << " will now roll the dice " << endl;
               std::pair<int, GameStateEnum> diceResult = this->rollDice();
               cout << "Player " << playerState.first << " got  " << diceResult.first << endl;
               playerScore += diceResult.first;
               while(diceResult.second == GameStateEnum.CONT)
               {
                  cout << "Player " << playerState.first << " will now roll the dice again, as it got another chance" << endl;
                  std::pair<int, GameStateEnum> diceResult = this->rollDice();
                  cout << "Player " << playerState.first << " got  " << diceResult.first << endl;
                  playerScore += diceResult.first;
               }
               
               std::pair<int, GameStateEnum> updatedState = this->state->updateState(playerState.first, playerScore, board);
               if(updatedState.second != GameStateEnum.CONT)
               {
                  break;
               }

           }
         }
         
      }
   }
   

   private:
   
   GameState *gameState;
   Dice *dice;
   SnakeAndLadderBoard *board;
   
   
}

enum GameStateEnum
{
   START=1,
   NEXT=3,
   CONT=5,
   STAY=8;
   FINISH=10
};


class GameState
{
   GameState(std::vector<std::string> names)
   {
      foreach(name: names)
      {
         this->state.push_back(name, std::pair<int, GameStateEnum>(0, GameStateEnum.START));
      }
   }
   void updateState(std::string playerName, int score, SnakeAndLadderBoard *board)
   {
      std::pair<int, GameStateEnum> response;
      foreach(auto playerState: this->stat)
      {
         if(playerName == playerState.first)
         {
            response = board->update(playerState.second.first)
            
         }
      }
       
      return response;
   }

   std::vector<pair<std::string, std::pair<int, GameStateEnum>>> getGameState()
   {
      return this->state;
   }
   
   private:
   std::vector<pair<std::string, std::pair<int, GameStateEnum>>> state;
}

class Dice
{
   public:

   Dice(int numOfDice)
   {
   }

   int rollDice()
   {
      return std::random(1, numOfDice*6);
   }
   
   int getMax()
   {
      this->6*numOfDice;
   }

   private:

   int numOfDice;
   int max;
}


class Snake
{
   public:
   Snake(int startOffset, int endOffset):startOffset(startOffset), endOffset(endOffset)
   {
   }
   
   int startOffset;
   int endOffset;
};

class Ladder
{  
   public:
   Ladder(int startOffset, int endOffset):startOffset(startOffset), endOffset(endOffset)
   {
   }
   
   int startOffset;
   int endOffset;

}

class SnakeAndLadderBoard
{
   
   public:
   SnakeAndLadderBoard(int numOfDice, std::vector<Ladder> listOfLadders, std::vector<Snake> listOfSnakes, int boardMax=100):listOfLadders(listOfLadders), listOfSnakes(listOfSnakes), boardMax(boardMax)
   {
      this->dicePtr = new Dice(numOfDice);
      this->diceMax = dicePtr->getMax();
      
   }

   std::pair<int, GameStateEnum> rollDice()
   {
      
      int result = this->rollDice();
      if(result == this->diceMax)
      {
         return std::pair<int, GameStateEnum>(result, GameStateEnum.CONT);
      }
      return std::pair<int, GameStateEnum>(result, GameStateEnum.NEXT);
   }

   std::pair<int GameStateEnum> updateState(int currentOffset)
   {
      int endOffset = 1;
      if(this->offsetMap.find(currentOffset) != this->offsetMap.end())
      {
         endOffset = this->offsetMap[currentOffset]; 
      }

      if
      return endOffset+currentOffset;      

   }

   void prepareBoard()
   {
      foreach(snake: snakes)
      {
         std::map<int, int>::iterator sit = this->offsetMap.find(snake.startOffset);
         if(sit != this->offsetMap.end())
         {
            std::cout << "Incorrect Configurations for snakes " << std::endl;
         }
         this->offsetMap.insert(std::pair<int, int>(snake.startOffset, snake.endOffset));
      }

      foreach(ladder: ladders)
      {
         std::map<int, int>::iterator lit = this->offsetMap.find(ladder.startOffset);
         if(lit != this->offsetMap.end())
         {
            std::cout << "Incorrect Configurations for snakes " << std::endl;
         }
         
         this->offsetMap.insert(std::pair<int, int>(ladder.startOffset, ladder.endOffset));
      }


   }

   private:

   std::map<int, int> offsetMap;

   Dice *dicePtr;   
};




int main()
{

   
}
